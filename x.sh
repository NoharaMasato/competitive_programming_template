#!/bin/bash

inputs="$1/inputs/*"
g++ $1.cpp

cnt=0
ls inputs >/dev/null 2>&1
if [ $? -ne 0 ]; then # sample test case does not exsist
  ./fetch_testcase $1
fi

for input in $inputs; do
  output=$1/outputs/$cnt.txt
  # cat $input
  diff <(./a.out < ./$input) <(cat $output) > /dev/null 2>&1
  if [ $? -eq 0 ]; then
    echo  $'\e[32mAC\e[0m'
  elif [ $? -eq 1 ]; then
    echo  $'\e[31mWA\e[0m'
  fi
  ((cnt=cnt+1))
done

