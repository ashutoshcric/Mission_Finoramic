#! /usr/bin/python

import json
import os
import site
from pprint import pprint

try:
    import pip
except:
    print("installing pip")
    cmd = "sudo apt-get install python-pip"
    os.system(cmd)
    reload(site)
    import pip

#installs specified package
def install(package):
    status = True
    try:
        pip.main(['install', package])
    except:
        status = False
    return status

def installAll(filePath):
    with open(filePath) as inputFile:
        data = json.load(inputFile)

    toInstall = data["Dependencies"]
    pprint(toInstall)

    for package in toInstall.keys():
        val = str(package+"=="+toInstall[package])
        if not install(val):
            print("Could not install "+ package +" " + toInstall[package])
	else:
            print("Successfully installed "+ package + " "+ toInstall[package])

installAll('sample.json')

