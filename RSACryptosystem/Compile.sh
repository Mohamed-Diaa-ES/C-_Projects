#!/bin/bash

gcc RSA.c KeyGen/KeyGen.h KeyGen/KeyGen.c -o testKeyGen.exe


# g++ RSA_gpp.h RSA.cpp -o GppOutput.exe


# pyinstaller --onefile  RSA.py
