sudo apt update

sudo apt install openjdk-8-jdk -y
sudo update-alternatives --set javac /usr/lib/jvm/java-8-openjdk-amd64/bin/javac

cd ~
unzip PFE_Transport_Chien_Robot/lcm-1.4.0.zip
cd ../lcm-1.4.0
mkdir build
cd build
cmake ..
make -j24
sudo make install # this will install lcm
sudo ldconfig -v # updates the shared library cache
# after this, revert back to the previous version of openjdk: