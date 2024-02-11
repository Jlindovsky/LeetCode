#!/bin/bash
help_function(){
    echo "Usage: $0 [-d <difficulty>] [-s <suffix>] [-t <topic>] [-h]"
    echo ""
    echo "  -d <difficulty>  Filter files by difficulty         Easy, Medium, Hard"
    echo "  -s <suffix>      Filter files by language           .cpp, .py"
    echo "  -t <topic>       Filter files by topic              Math, Dynamic Programing, Array"
    echo "  -h               Display this help message"
    echo ""
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

# Parsing command-line options
while getopts ":d:s:t:h" opt; do
  case $opt in
    d) difficulty="$OPTARG";; # Assigning the value of the -d flag
    s) suffix="$OPTARG";; # Assigning the value of the -s flag
    t) topic="$OPTARG";; # Assigning the value of the -t flag
    h) help="open";;
    \?) echo "Invalid option: -$OPTARG" >&2;;
  esac
done



# Determine which function to call based on the provided flags
if [ -n "$suffix" ] && [ -n "$difficulty" ] && [ -n "$topic" ]; then
    echo "Only $suffix files with $difficulty difficulty and $topic topic."
    filter_files_by_suffix_and_difficulty_and_topic "$suffix" "$difficulty" "$topic"

elif [ -n "$suffix" ] && [ -n "$difficulty" ]; then
    echo "Only $suffix files with $difficulty difficulty."
    filter_files_by_suffix_and_difficulty "$suffix" "$difficulty"
elif [ -n "$difficulty" ] && [ -n "$topic" ]; then
    echo "Only files with $difficulty difficulty and $topic topic."
    filter_files_by_difficulty_and_topic "$difficulty" "$topic"
elif [ -n "$suffix" ] && [ -n "$topic" ]; then
    echo "Only $suffix files with $topic topic."
    filter_files_by_suffix_and_topic "$suffix" "$topic"

elif [ -n "$topic" ]; then
    echo "Only files with $topic topic".
    filter_files_by_topic "$topic"
elif [ -n "$suffix" ]; then
    echo "Only $suffix files."
    filter_files_by_suffix "$suffix" 
elif [ -n "$difficulty" ]; then
    echo "Only files with $difficulty difficulty."
    filter_files_by_difficulty "$difficulty"

elif [ -n "$help" ]; then
    help_function
else
    echo "No flags provided."
fi
