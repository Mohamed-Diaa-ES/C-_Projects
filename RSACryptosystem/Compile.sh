#!/bin/bash

# gcc RSA_gcc.h RSA.c -o GccOutput.exe

# g++ RSA_gpp.h RSA.cpp -o GppOutput.exe


pyinstaller --onefile  RSA.py
