from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import (
    DeclareLaunchArgument,
    SetLaunchConfiguration,
    IncludeLaunchDescription,
    LogInfo,
    ExecuteProcess,
)
from launch_ros.parameter_descriptions import ParameterValue, ParameterFile
from launch.substitutions import (
    LaunchConfiguration,
    PythonExpression,
    PathJoinSubstitution,
    TextSubstitution,
    Command,
)
from launch_ros.substitutions import FindPackageShare
from launch.conditions import UnlessCondition, LaunchConfigurationNotEquals
from launch.launch_description_sources import PythonLaunchDescriptionSource


def generate_launch_description():
    rname = LaunchConfiguration("rname")
    gui = LaunchConfiguration("gui")
    use_sim_time = LaunchConfiguration("use_sim_time")
    headless = LaunchConfiguration("headless")
    debug = LaunchConfiguration("debug")
    user_debug = LaunchConfiguration("user_debug", default="false")
    wname = LaunchConfiguration("wname")
    ns = LaunchConfiguration("namespace")
    robot_path = FindPackageShare([rname, "_description"])
    robot_description = ParameterValue(
        Command(
            [
                "xacro ",
                LaunchConfiguration("model"),
                TextSubstitution(text=" DEBUG:="),
                user_debug,
            ]
        ),
        value_type=str,
    )
    gazebo_ros = FindPackageShare("gazebo_ros")
    unitree_gazebo = FindPackageShare("unitree_gazebo")
    world = LaunchConfiguration("world")
    config = ParameterFile(
        param_file=[
            PathJoinSubstitution([robot_path, "config"]),
            "robot_controller.yaml",
        ]
    )

    return LaunchDescription(
        [
            DeclareLaunchArgument(
                "wname", default_value="earth", choices=["earth", "space", "stairs"]
            ),
            DeclareLaunchArgument("rname", default_value="go1"),
            DeclareLaunchArgument("robot_path", default_value=robot_path),
            DeclareLaunchArgument(
                "paused", default_value="true", choices=["true", "false"]
            ),
            DeclareLaunchArgument(
                "use_sim_time", default_value="true", choices=["true", "false"]
            ),
            DeclareLaunchArgument("gui", default_value="true"),
            DeclareLaunchArgument(
                "headless", default_value="false", choices=["true", "false"]
            ),
            DeclareLaunchArgument("debug", default_value="false"),
            DeclareLaunchArgument(
                "user_debug", default_value="true", choices=["true", "false"]
            ),
            SetLaunchConfiguration("world_file", value=[wname, ".world"]),
            DeclareLaunchArgument(
                "world",
                default_value=PathJoinSubstitution(
                    [
                        unitree_gazebo,
                        "worlds",
                        LaunchConfiguration("world_file"),
                    ]
                ),
            ),
            DeclareLaunchArgument("namespace", default_value=[rname, "_gazebo"]),
            SetLaunchConfiguration(
                "model",
                value=PathJoinSubstitution([robot_path, "xacro", "robot.xacro"]),
            ),
            LogInfo(msg=["World file to be loaded: ", world]),
            IncludeLaunchDescription(
                PythonLaunchDescriptionSource(
                    PathJoinSubstitution([gazebo_ros, "launch", "gzserver.launch.py"])
                ),
                launch_arguments={
                    "world": world,
                    "pause": LaunchConfiguration("paused"),
                    "gui": gui,
                    "use_tim_time": use_sim_time,
                    "user_debug": user_debug,
                    "debug": debug,
                }.items(),
            ),
            # Start Gazebo client
            IncludeLaunchDescription(
                PythonLaunchDescriptionSource(
                    PathJoinSubstitution([gazebo_ros, "launch", "gzclient.launch.py"])
                ),
                condition=UnlessCondition(headless),
            ),
            Node(
                package="gazebo_ros",
                executable="spawn_entity.py",
                arguments=["-entity", rname, "-topic", "robot_description", "-z 0.6"],
                output="screen",
            ),
            # Joint State Broadcaster
            # ExecuteProcess(
            #     cmd=[
            #         "ros2",
            #         "control",
            #         "load_controller",
            #         "joint_state_broadcaster",
            #         "--set-state",
            #         "active",
            #     ],
            #     output="screen",
            # ),
            Node(
                package="controller_manager",
                executable="spawner",
                namespace=ns,
                arguments=[
                    "joint_state_broadcaster",
                    "FL_hip_controller",
                    "FL_thigh_controller",
                    "FL_calf_controller",
                    "FR_hip_controller",
                    "FR_thigh_controller",
                    "FR_calf_controller",
                    "RL_hip_controller",
                    "RL_thigh_controller",
                    "RL_calf_controller",
                    "RR_hip_controller",
                    "RR_thigh_controller",
                    "RR_calf_controller",
                ],
                parameters=[config],
                output="screen",
            ),
            Node(
                package="robot_state_publisher",
                executable="robot_state_publisher",
                parameters=[
                    {
                        "robot_description": robot_description,
                        "frame_prefix": [ns, "/"],
                        "use_tim_time": use_sim_time,
                    }
                ],
                output="screen",
            ),
        ]
    )
