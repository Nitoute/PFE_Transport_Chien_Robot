sudo apt update

sudo apt install openjdk-8-jdk -y
sudo update-alternatives --set javac /usr/lib/jvm/java-8-openjdk-amd64/bin/javac

unzip lcm-1.4.0.zip
mv lcm-1.4.0 ..
cd ../lcm-1.4.0
mkdir build
cd build
cmake ..
make
sudo make install # this will install lcm
sudo ldconfig -v # updates the shared library cache
# after this, revert back to the previous version of openjdk: