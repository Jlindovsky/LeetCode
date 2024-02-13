#!/bin/bash
help_function(){
    echo "Usage: $0 [-d <difficulty>] [-s <suffix>] [-t <topic>] [-h]"
    echo ""
    echo "  -d <difficulty>  Filter files by difficulty:     Easy, Medium, Hard"
    echo ""  
    echo "  -s <suffix>      Filter files by language:       .cpp, .py"
    echo ""  
    echo "  -t <topic>       Filter files by topic:              
                             Array, String, Hash Table, Dynamic Programming, Math, Sorting, Greedy,
                             Depth-First Search, Binary Search, Tree, Matrix, Two Pointers, Bit Manipulation,
                             Binary Tree, Heap, Stack, ..."
    echo ""                        
    echo "  --help           Display this help message"
    echo ""
}

show_descriptions() {
    local found_files="$@"
    if [ -z "$found_files" ]; then
        echo "No files filtered."
    else
        for file in $found_files; do
            echo "Description for file: $file"
            sed -n '/^Description:/,/^$/p' "$file" | sed '1d;$d' | sed '/^\*\/$/d; /^"""$/d'
            echo ""
        done
    fi
}



filter_files_by_difficulty() {
    local found_files=$(find . -type f -exec grep -qw "Difficulty: $difficulty" {} \; -print)
    if [ -z "$found_files" ]; then
        echo "No files found matching $difficulty difficulty."
    else
        echo "$found_files"
    fi
}

filter_files_by_suffix() {
    # List files in current directory and subdirectories, filter based on the suffix
    local found_files=$(find . -type f -name "*$suffix")
    if [ -z "$found_files" ]; then
        echo "No files found matching $suffix suffix."
    else
        echo "$found_files"
    fi
}

filter_files_by_topic() {
    local found_files=$(find . -type f -exec grep -qw "Topics:.*$topic" {} \; -print)
    if [ -z "$found_files" ]; then
        echo "No files found matching $topic topic."
    else
        echo "$found_files"
    fi
}

filter_files_by_suffix_and_difficulty() {
    local found_files=$(find . -type f -name "*$suffix" -exec grep -qw "Difficulty: $difficulty" {} \; -print)
    if [ -z "$found_files" ]; then
        echo "No files found matching $suffix suffix with $difficulty difficulty."
    else
        echo "$found_files"
    fi
}

filter_files_by_difficulty_and_topic() {
    local found_files=$(find . -type f -exec grep -qw "Difficulty: $difficulty" {} \; -exec grep -qw "Topics:.*$topic" {} \; -print)
    if [ -z "$found_files" ]; then
        echo "No files found matching $difficulty difficulty with $topic topic."
    else
        echo "$found_files"
    fi
}

filter_files_by_suffix_and_topic() {
    local found_files=$(find . -type f -name "*$suffix" -exec grep -qw "Topics:.*$topic" {} \; -print)
    if [ -z "$found_files" ]; then
        echo "No files found matching $suffix suffix with $topic topic."
    else
        echo "$found_files"
    fi
}


filter_files_by_suffix_and_difficulty_and_topic(){
    local found_files=$(find . -type f -name "*$suffix" -exec grep -qw "Difficulty: $difficulty" {} \; -exec grep -qw "Topics:.*$topic" {} \; -print)
    if [ -z "$found_files" ]; then
        echo "No files found matching $suffix suffix with $difficulty difficulty and $topic topic."
    else
        echo "$found_files"
    fi
}

found_files=""

# Parsing command-line options
while getopts ":d:s:t:ah" opt; do
  case $opt in
    d) difficulty="$OPTARG";; # Assigning the value of the -d flag
    s) suffix="$OPTARG";; # Assigning the value of the -s flag
    t) topic="$OPTARG";; # Assigning the value of the -t flag
    a) show="true";;
    h) help_function;;
    :) echo "Option -$OPTARG requires an argument." >&2;;
    \?) echo "Invalid option: -$OPTARG" >&2;;

  esac
done

# Determine which function to call based on the provided flags
# Your filtering logic...



# Determine which function to call based on the provided flags
if [ -n "$suffix" ] && [ -n "$difficulty" ] && [ -n "$topic" ]; then
    echo "Only $suffix files with $difficulty difficulty and $topic topic."
    echo ""
    found_files=$(filter_files_by_suffix_and_difficulty_and_topic "$suffix" "$difficulty" "$topic")

elif [ -n "$suffix" ] && [ -n "$difficulty" ]; then
    echo "Only $suffix files with $difficulty difficulty."
    echo ""
    found_files=$(filter_files_by_suffix_and_difficulty "$suffix" "$difficulty")
elif [ -n "$difficulty" ] && [ -n "$topic" ]; then
    echo "Only files with $difficulty difficulty and $topic topic."
    echo ""
    found_files=$(filter_files_by_difficulty_and_topic "$difficulty" "$topic")
elif [ -n "$suffix" ] && [ -n "$topic" ]; then
    echo "Only $suffix files with $topic topic."
    echo ""
    found_files=$(filter_files_by_suffix_and_topic "$suffix" "$topic")

elif [ -n "$topic" ]; then
    echo "Only files with $topic topic".
    echo ""
    found_files=$(filter_files_by_topic "$topic")
elif [ -n "$suffix" ]; then
    echo "Only $suffix files."
    echo ""
    found_files=$(filter_files_by_suffix "$suffix")
elif [ -n "$difficulty" ]; then
    echo "Only files with $difficulty difficulty."
    echo ""
    found_files=$(filter_files_by_difficulty "$difficulty")
fi

if [ -n "$show" ]; then
    show_descriptions "$found_files"
else
    echo "$found_files"
    echo ""
fi
