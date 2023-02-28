rm*.o
rm*exe
gcc -c master.c
gcc -c count_consonants.c
gcc -o count_consonants_exe count_consonants.o master.o
./count_consonants_exe