mv opencv ..
cd ../opencv/build

sudo ln -s /usr/include/eigen3/Eigen /usr/include/Eigen
sudo make install # this will install opencv
sudo ldconfig -v # updates the shared library cache 

sudo apt-get install libgtk2.0-dev libgtk-3-dev
sudo apt install -y libgstreamer1.0-dev libgstreamer-plugins-base1.0-dev libgstreamer-plugins-bad1.0-dev libgstreamer-plugins-good1.0-dev
sudo apt install -y gstreamer1.0-plugins-base gstreamer1.0-plugins-good gstreamer1.0-plugins-bad gstreamer1.0-plugins-ugly
sudo apt install -y gstreamer1.0-tools gstreamer1.0-libav
sudo apt install -y gstreamer1.0-x gstreamer1.0-alsa gstreamer1.0-gl gstreamer1.0-gtk3 gstreamer1.0-qt5 gstreamer1.0-pulseaudio