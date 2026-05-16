#include <stdio.h>
#include <string.h>

int main() {
    char input_arr[100] = {}; // 1 bytes for each char
    unsigned int output_arr[100] = {};
    unsigned char hash = 0; // 1 byte for unsigned char, initialized to 0
    /* if we use unsigned int for hash, then we will have 4 bytes for hash and to make 
    this program memory efficient we can use unsigned char for hash,
    because we are only interested in the last byte of the hash value, and the upper 3 bytes will be wasted if we use unsigned int for hash */
    printf(".............. XOR ..............\n");
    printf("Enter value for Hashing...\n");

    fgets(input_arr, 99, stdin);

    // remove newline from fgets
    input_arr[strcspn(input_arr, "\n")] = '\0';

    int len = strlen(input_arr);

    for (int i = 0; i < len; i++) {
        hash = hash ^ input_arr[i];
        output_arr[i] = hash; // upper 24 bits are being wasted here so this is not memory efficient but it is just for demonstration purposes
    }


    printf("--> The Output Hash (step by step):\n");

    for (int i = 0; i < len; i++) {
        printf("%x", output_arr[i]); //putting each hash value in hex format, because %x is used for unsigned int in hex format
    }

    printf("\n");

    return 0;
}