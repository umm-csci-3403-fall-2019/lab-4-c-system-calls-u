#!/usr/bin/env bash

dir=$1

numdir=$(find $dir -type d | wc -l)
echo "There were" $numdir "directories."

numfiles=$(find $dir -type f | wc -l)
echo "There were" $numfiles "regular files."

