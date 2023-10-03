set -e
printf "\n.------------------------------------------------------.\n                compiling program...\n.------------------------------------------------------.\n\n"

g++ -std=c++20 *.cpp -o main.exe -ltag -l:libz.a
printf "\n.------------------------------------------------------.\n                program compiled!\n.------------------------------------------------------.\n\n"

printf "\n.------------------------------------------------------.\n                running program...\n.------------------------------------------------------.\n\n"

./main.exe