#!/bin/bash

declare -a array=("a" "b" "c" "d" "e" "f")  

for e in ${array[@]}; do
  mkdir $e
  mkdir $e/inputs
  mkdir $e/outputs
done
