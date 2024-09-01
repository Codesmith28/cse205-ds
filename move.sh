#!/bin/bash
echo "Available files: "
ls *.cpp | grep -v "run.cpp"

echo

echo "Enter destionation:"
echo "1. Leetcode/GFG"
echo "2. Codechef"
echo "3. Codeforces"
echo "4. CSES"
echo "5. Others"

read -p "Enter your choice: " dir

case $dir in
1)
    dest="leetcode_gfg"
    ;;
2)
    dest="codechef"
    ;;
3)
    dest="codeforces"
    ;;
4)
    dest="cses"
    ;;
5)
    dest="others"
    ;;
*)
    echo "Invalid dest"
    exit 1
    ;;
esac

target_dir="cp/$dest"
mkdir -p "$target_dir"

for file in *.cpp; do
    if [ "$file" != "run.cpp" ] && [ -f "$file" ]; then
        echo "Moving file: $file -> $target_dir"
        mv -f "$file" "$target_dir"
    fi
done

echo

echo "Done! All files have been moved to $target_dir directory"
