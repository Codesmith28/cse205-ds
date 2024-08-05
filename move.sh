#!/bin/bash

read -p "Enter dest(lc/cc/cf/cs/ot): " dir

case $dir in
    "lc")
        dest="leetcode"
        ;;
    "cc")
        dest="codechef"
        ;;
    "cf")
        dest="codeforces"
        ;;
    "cs")
        dest="cses"
        ;;
    "ot")
        dest="others"
        ;;
    *)
        echo "Invalid dest"
        exit 1
        ;;
esac

target_dir="cp/$dest"

# Create the target directory if it doesn't exist
mkdir -p "$target_dir"

for file in *.cpp
do
    if [ "$file" != "run.cpp" ] && [ -f "$file" ]
    then
        echo "Moving file: $file -> $target_dir"
        mv -f "$file" "$target_dir"
    fi
done

echo "Done! All files have been moved to $target_dir directory"