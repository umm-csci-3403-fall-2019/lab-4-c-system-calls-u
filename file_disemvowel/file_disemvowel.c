#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BUF_SIZE 1024

bool is_vowel(char vowel) {
    return (vowel == 'a' || vowel == 'e' || vowel == 'i' || vowel == 'o' || vowel == 'u' ||
	        vowel == 'A' || vowel == 'E' || vowel == 'I' || vowel == 'O' || vowel == 'U');
}

int copy_non_vowels(int num_chars, char* in_buf, char* out_buf) {
    /*
     * Copy all the non-vowels from in_buf to out_buf.
     * num_chars indicates how many characters are in in_buf,
     * and this function should return the number of non-vowels that
     * that were copied over.
     */
	int index = 0;
	int counter = 0;

	while(index<num_chars){
		if(!is_vowel(in_buf[index])){
			counter++;
		}
		index++;
	}


	for(int i=0,n=0;i<index;i++){
		if(!is_vowel(in_buf[i])){
			out_buf[n] = in_buf[i];
			n++;
		}
	}
	return counter;
}

void disemvowel(FILE* inputFile, FILE* outputFile) {
    /*
     * Copy all the non-vowels from inputFile to outputFile.
     * Create input and output buffers, and use fread() to repeatedly read
     * in a buffer of data, copy the non-vowels to the output buffer, and
     * use fwrite to write that out.
     */

	char in_buffer[BUF_SIZE];
	char out_buffer[BUF_SIZE];

	int num_chars =fread(in_buffer,1,BUF_SIZE,inputFile);
       	while(num_chars !=0){
		int nonvowels = copy_non_vowels(num_chars,in_buffer,out_buffer);	
		fwrite(out_buffer,1,nonvowels,outputFile);
		num_chars= fread(in_buffer, 1, BUF_SIZE, inputFile);
	}
	
}


int main(int argc, char *argv[]) {
    // You should set these to `stdin` and `stdout` by default
    // and then set them to user specified files when the user
    // provides files names as command line arguments.
    FILE *inputFile;
    FILE *outputFile;


    if(argc > 1){
    	inputFile = fopen( argv[1], "r" );
    }else{
    	inputFile = stdin;
    }
    if(argc > 2){
	    outputFile = fopen( argv[2], "w" );
    }else{
    	outputFile = stdout;
    }
    // Code that processes the command line arguments
    // and sets up inputFile and outputFile.

    disemvowel(inputFile, outputFile);
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
