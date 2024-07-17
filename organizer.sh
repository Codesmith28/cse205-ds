#!/bin/bash

# Directory paths
CP_DIR="./cp"
CPH_DIR="./.cph"
CODEFORCES_DIR="$CP_DIR/codeforces"
CODECHEF_DIR="$CP_DIR/codechef"
CSES_DIR="$CP_DIR/cses"
LEETCODE_DIR="$CP_DIR/leetcode"
OTHERS_DIR="$CP_DIR/others"

# Create directories if they don't exist
mkdir -p "$CODEFORCES_DIR" "$CODECHEF_DIR" "$CSES_DIR" "$LEETCODE_DIR" "$OTHERS_DIR"

# Function to get the problem source from .cph file
get_problem_source() {
    local file="$1"
    local cph_file="$CPH_DIR/.${file}_*.prob"
    
    if [ -f $cph_file ]; then
        if grep -qi "Codeforces" "$cph_file"; then
            echo "codeforces"
        elif grep -qi "Codechef" "$cph_file"; then
            echo "codechef"
        elif grep -qi "CSES" "$cph_file"; then
            echo "cses"
        else
            echo "unknown"
        fi
    else
        echo "unknown"
    fi
}

# Organize files
for file in "$CP_DIR"/*.cpp "$CP_DIR"/*.h; do
    if [ -f "$file" ]; then
        filename=$(basename "$file")
        
        # Ignore debug.h file
        if [ "$filename" = "debug.h" ]; then
            continue
        fi
        
        # Check if filename starts with a capital letter followed by underscore (Codeforces)
        if [[ $filename =~ ^[A-Z]_ ]]; then
            mv "$file" "$CODEFORCES_DIR/"
        # Check if filename starts with a number (LeetCode)
        elif [[ $filename =~ ^[0-9] ]]; then
            mv "$file" "$LEETCODE_DIR/"
        else
            # Check .cph files for source
            source=$(get_problem_source "$filename")
            case $source in
                "codeforces")
                    mv "$file" "$CODEFORCES_DIR/"
                    ;;
                "codechef")
                    mv "$file" "$CODECHEF_DIR/"
                    ;;
                "cses")
                    mv "$file" "$CSES_DIR/"
                    ;;
                *)
                    mv "$file" "$OTHERS_DIR/"
                    ;;
            esac
        fi
    fi
done

echo "Files have been organized!"