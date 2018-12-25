#!/bin/bash
if [ $1 == 'make' ]
then
  cd build/default
  ninja
fi

if [ $1 == 'run' ]
then
  cd build/default
  ninja
  ./cpp_demo
fi
