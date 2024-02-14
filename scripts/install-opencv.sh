mv opencv ..
cd ../opencv/build

sudo ln -s /usr/include/eigen3/Eigen /usr/include/Eigen
sudo make install # this will install opencv
sudo ldconfig -v # updates the shared library cache 