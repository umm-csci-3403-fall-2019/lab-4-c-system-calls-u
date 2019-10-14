#!/usr/bin/env bash

#sets the argument to a directory variable
dir=$1

#This uses find to find all the subdirectories. wc -l counts the lines
#this is equal to the number of directories.
numdir=$(find $dir -type d | wc -l)
echo "There were" $numdir "directories."

#This does a similar thing, but searches for file type.
numfiles=$(find $dir -type f | wc -l)
echo "There were" $numfiles "regular files."

