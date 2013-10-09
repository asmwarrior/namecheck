#!/bin/bash

function checkInstalled
{
    if !(which $1 > /dev/null); then
        echo $1 is not installed. This script is for an ubuntu-based distribution.
        echo You will need to install the dependencies manually.
        exit 1
    fi
}

if !(which gcc > /dev/null); then
    echo gcc is not installed. Install it and re-run this script.
    exit 1
fi

checkInstalled dpkg
checkInstalled apt-cache
checkInstalled apt-get
checkInstalled gettext

if !(dpkg -l | grep libboost-regex-dev -c >>/dev/null); then 
    echo boost not installed. Installing it...
    sudo apt-get install libboost-regex-dev
else
    echo boost library already installed.
fi

if !(dpkg -l | grep gcc| grep plugin-dev >/dev/null); then
    echo gcc plugins library not installed.
    #determine the gcc version:
    if (gcc --version | head -n 1| grep 4.6 >/dev/null); then
        echo Installing it for gcc version 4.6
        sudo apt-get install gcc-4.6-plugin-dev
    elif (gcc --version | head -n 1| grep 4.7 >/dev/null); then
        echo Installing it for gcc version 4.7
        sudo apt-get install gcc-4.7-plugin-dev
    else
        echo gcc version not supported. Install the gcc-plugin-dev package manually.
        exit 1
    fi
else
    echo gcc plugins library already installed.
fi

if !(dpkg -l | grep gettext -c >>/dev/null); then 
    sudo apt-get install gettext
else
    echo gettext library already installed.
fi

echo All dependencies are installed. Build namecheck by running make.

