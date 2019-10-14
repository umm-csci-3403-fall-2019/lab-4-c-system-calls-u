#!/env/bin/bash
$dir=$1;

find -f $dir | wc -l | printf("There were %d regular files.\n", $numfiles);

find -d $dir | wc -l | printf("There were %d directories.\n", num_dirs);

