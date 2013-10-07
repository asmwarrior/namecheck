#!/bin/bash

if !(dpkg -l | grep libboost-regex-dev -c >>/dev/null); then 
	sudo apt-get install libboost-regex-dev; 
fi

if !(dpkg -l | grep gcc-4.6-plugin-dev -c >>/dev/null); then
	sudo apt-get install gcc-4.6-plugin-dev; 
fi 
