Hello this program is made to count word in a text file.

flow of the program:
->fetch words from the file by strtok
->store it to 2d array
->assend the words in 2d array with the help of strlen 
->made a array of 2 rows in which 1st row has word lengths and seconf has its frequency.
->decend the second array according to frequency using double loop
->converted the main array all to lower case as to make it ready to check duplication.
->removed the duplication from the main array using multiple loops and temp array
->and printed as expected using loop which search the particular length word from the main array.



Input file:
Hi my; name is (shrey). I go to University,
university of Victoria
saanich
Victoria.
Victoria is good;


it checks ,.()space,nextline characters and suspend it.



output:
patelsr@ubuntu:~/Desktop/seng265/Assignment$ make word_count
make: `word_count' is up to date.
patelsr@ubuntu:~/Desktop/seng265/Assignment$ ./word_count --infile input_file.txt

Count[01]=01;
Count[02]=07;
Count[04]=02;
Count[05]=01;
Count[07]=01;
Count[08]=03;
Count[10]=02;


patelsr@ubuntu:~/Desktop/seng265/Assignment$ ./word_count --sort --infile input_file.txt

Count[02]=07;
Count[08]=03;
Count[04]=02;
Count[10]=02;
Count[07]=01;
Count[01]=01;
Count[05]=01;


patelsr@ubuntu:~/Desktop/seng265/Assignment$ ./word_count --sort --print-words --infile input_file.txt

Count[02]=07; (words: "my", "is", "hi", "go", "to" and "of")
Count[08]=03; (words: "victoria")
Count[04]=02; (words: "name" and "good")
Count[10]=02; (words: "university")
Count[07]=01; (words: "saanich")
Count[01]=01; (words: "i")
Count[05]=01; (words: "shrey")


patelsr@ubuntu:~/Desktop/seng265/Assignment$ ./word_count -infile input_file.txt

Please check the argument

patelsr@ubuntu:~/Desktop/seng265/Assignment$ ./word_count --file input_file.txt


Please check the argument

patelsr@ubuntu:~/Desktop/seng265/Assignment$ ./word_count -infile add input_file.txt


Please check the argument

patelsr@ubuntu:~/Desktop/seng265/Assignment$ ./word_count --file input_fe.txt


Please check the argument

patelsr@ubuntu:~/Desktop/seng265/Assignment$ ./word_count --infile input_fe.txtFile not found



THANK YOU.