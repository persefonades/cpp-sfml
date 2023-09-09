# !/bin/bash

# Color Constants
RESTORE='\033[0m'

RED='\033[00;31m'
GREEN='\033[00;32m'
YELLOW='\033[00;33m'
BLUE='\033[00;34m'
PURPLE='\033[00;35m'
CYAN='\033[00;36m'
LIGHTGRAY='\033[00;37m'

LRED='\033[01;31m'
LGREEN='\033[01;32m'
LYELLOW='\033[01;33m'
LBLUE='\033[01;34m'
LPURPLE='\033[01;35m'
LCYAN='\033[01;36m'
WHITE='\033[01;37m'

APPNAME='tetris'
ROOT_DIR=$(pwd)
APP_DIR=$ROOT_DIR/$APPNAME
BUILD_DIR=$APP_DIR/build

if [[ -d $BUILD_DIR ]]; then
    rm -rf $BUILD_DIR
fi

echo "Compiling files for $APPNAME"

mkdir -p $BUILD_DIR
cd $BUILD_DIR
cmake $APP_DIR
cmake --build .

# make

EXECUTABLE_NAME=${APPNAME}_main

if [ -f $BUILD_DIR/$EXECUTABLE_NAME ]; then
    printf "\n${LBLUE}Running main...${RESTORE}\n"
    eval "./$EXECUTABLE_NAME"
else
    printf "\n${LRED}Error: ./$EXECUTABLE_NAME not found.${RESTORE}\n"
fi
