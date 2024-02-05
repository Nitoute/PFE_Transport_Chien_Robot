from setuptools import find_packages
from setuptools import setup

setup(
    name='unitree_nav_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('unitree_nav_interfaces', 'unitree_nav_interfaces.*')),
)
