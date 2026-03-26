#!/bin/bash

set -e

DEST_DIR="/usr/local/bin"
SOURCE="./"
P_NAME="simclo"


echo "Compiling program":
make || { echo "[ERROR] There was an error during compilation. Installation aborted!"; exit 1;}
echo "Done!"
echo
echo "Installing program:"
sudo install -m 0755 $SOURCE/$P_NAME $DEST_DIR/$P_NAME || { echo "[ERROR] There was an error during installation. Installation aborted!"; exit 1;}
rm $SOURCE/$P_NAME
echo "Done!"
echo
echo "INSTALLATION COMPLETED!" 