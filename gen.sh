#!/bin/bash

generator ()
{
  x=$1
  y=$2
  
  > "./map.fdf" # empty the file
  while [ $y -gt 0 ]; do
    arr=()
    arr=$(shuf -i 0-20 -n$x)
    echo ${arr[@]} >> "./map.fdf"
    let "y-= 1"
  done
}

if [ $# != 2 ]; then
  echo -e "\e[31mUsage: ./mapgen.sh <X> <Y>\e[0m" 2>&1
  exit 1
fi
if [ -e "./map.fdf" ]; then
  generator $1 $2
else
  touch "./map.fdf"
  generator $1 $2
fi
