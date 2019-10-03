#include <stdio.h>
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
	int index
	int counter = 0;

	while(index<num_chars){
		if(!hasVowel(str[index])){
			counter++;
		}
		index++;
	}

	out_buf = (char*) calloc (counter, sizeof(char));

	for(int i=0,n=0;i<index;i++){
		if(!hasVowel(str[i])){
			newStr[n] = str[i];
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
}

int main(int argc, char *argv[]) {
    // You should set these to `stdin` and `stdout` by default
    // and then set them to user specified files when the user
    // provides files names as command line arguments.
    FILE *inputFile;
    FILE *outputFile;

    // Code that processes the command line arguments
    // and sets up inputFile and outputFile.

    disemvowel(inputFile, outputFile);

    return 0;
}
