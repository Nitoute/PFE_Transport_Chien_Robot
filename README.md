# Go1 navigation and transport

## Dependencies
The jetson nanos on the dog use ARM64 processors so we need to install Qemu to compile the ros packages.
<code>
sudo apt-get install qemu binfmt-support qemu-user-static # Install Qemu dependencies
docker run --rm --privileged multiarch/qemu-user-static --reset -p yes # Setup Qemu for docker
</code>

trello link : https://trello.com/b/TMi6WSX4/pfe-transport-go1
overleaf link : https://www.overleaf.com/2373497429rbycvrqmqqsm#0de2a5
