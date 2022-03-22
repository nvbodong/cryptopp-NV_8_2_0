#!/usr/bin/env bash

# Use this script to switch back to the previous Crypto++ version before
# building the docs. Before running the script, copy it to the root
# directory. After running this script, you can 'make docs'

sed 's|Library 8.2 API|Library 8.1 API|g' cryptlib.h > cryptlib.h.new
mv cryptlib.h.new cryptlib.h

sed 's|= 8.2|= 8.1|g' Doxyfile > Doxyfile.new
mv Doxyfile.new Doxyfile

sed 's|CryptoPP_NV_2_MINOR 2|CryptoPP_NV_2_MINOR 1|g' config.h > config.h.new
mv config.h.new config.h

sed 's|CryptoPP_NV_2_VERSION 820|CryptoPP_NV_2_VERSION 810|g' config.h > config.h.new
mv config.h.new config.h
