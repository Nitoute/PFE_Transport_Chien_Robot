import launch
from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument, LogInfo, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from ament_index_python.packages import get_package_share_directory
from launch.substitutions import LaunchConfiguration

def generate_launch_description():
    wname = LaunchConfiguration('wname', default="earth")
    rname = LaunchConfiguration('rname', default="laikago")
    robot_path = LaunchConfiguration('robot_path', default="(find {})".format(str(rname) + "_description"))
    dollar = LaunchConfiguration('dollar', default="$")
    paused = LaunchConfiguration('paused', default="true")
    use_sim_time = LaunchConfiguration('use_sim_time', default="true")
    gui = LaunchConfiguration('gui', default="true")
    headless = LaunchConfiguration('headless', default="false")
    debug = LaunchConfiguration('debug', default="false")
    user_debug = LaunchConfiguration('user_debug', default="false")

    return LaunchDescription([
        DeclareLaunchArgument(name='wname', default_value=wname, description='Gazebo world name'),
        DeclareLaunchArgument(name='rname', default_value=rname, description='Robot name'),
        DeclareLaunchArgument(name='robot_path', default_value=robot_path, description='Robot description path'),
        DeclareLaunchArgument(name='dollar', default_value=dollar, description='Dollar sign for parameter substitution'),
        DeclareLaunchArgument(name='paused', default_value=paused, description='Start Gazebo in paused state'),
        DeclareLaunchArgument(name='use_sim_time', default_value=use_sim_time, description='Use simulation time'),
        DeclareLaunchArgument(name='gui', default_value=gui, description='Show Gazebo GUI'),
        DeclareLaunchArgument(name='headless', default_value=headless, description='Run Gazebo in headless mode'),
        DeclareLaunchArgument(name='debug', default_value=debug, description='Debug mode for Gazebo'),
        DeclareLaunchArgument(name='user_debug', default_value=user_debug, description='User-defined debug mode'),

        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                get_package_share_directory('gazebo_ros') + '/launch/empty_world.py'
            ),
            launch_arguments={
                'world_name': get_package_share_directory('unitree_gazebo') + '/worlds/{}.world'.format(wname),
                'debug': debug,
                'gui': gui,
                'paused': paused,
                'use_sim_time': use_sim_time,
                'headless': headless
            }.items()
        ),

        Node(
            package='xacro',
            executable='xacro',
            name='xacro',
            output='screen',
            arguments=[str(robot_path) + '/xacro/robot.xacro', '--inorder', '{}{}'.format(dollar, 'robot_description'), 'DEBUG:={}'.format(user_debug)]
        ),

        Node(
            package='gazebo_ros',
            executable='spawn_model',
            name='urdf_spawner',
            output='screen',
            arguments=['-urdf', '-z', '0.6', '-model', '{}_gazebo'.format(rname), '-param', 'robot_description', '-unpause']
        ),

        Node(
            package='controller_manager',
            executable='spawner',
            name='controller_spawner',
            output='screen',
            namespace='/{}/_gazebo'.format(rname),
            arguments=['joint_state_controller',
                       'FL_hip_controller', 'FL_thigh_controller', 'FL_calf_controller',
                       'FR_hip_controller', 'FR_thigh_controller', 'FR_calf_controller',
                       'RL_hip_controller', 'RL_thigh_controller', 'RL_calf_controller',
                       'RR_hip_controller', 'RR_thigh_controller', 'RR_calf_controller']
        ),

        Node(
            package='robot_state_publisher',
            executable='robot_state_publisher',
            name='robot_state_publisher',
            output='screen',
            remappings=[('/joint_states', '/{}/_gazebo/joint_states'.format(rname))]
        ),

        # IncludeLaunchDescription(
        #     PythonLaunchDescriptionSource(
        #         get_package_share_directory('unitree_controller') + '/launch/set_ctrl.launch.py'
        #     ),
        #     launch_arguments={'rname': rname}.items()
        # )
    ])
