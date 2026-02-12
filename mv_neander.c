#include "mv_neander.h"
#include <stdio.h>
#include <stdlib.h>

int ac = 0;
int pc = 0;
char *v;

int n_function() {
    if(ac > 0)
        return 0;
    else
        return 1;
}

int z_function() {
    if (ac == 0)
        return 1;
    else
        return 0;
}

int nop_command() {
    return 0;
}

int sta_command(char *addr) {
    return 0;
}

int lda_command(char *addr) {
    return 0;
}

int add_command(char *addr) {
    return 0;
}

int or_command(char *addr) {
    return 0;
}

int and_command(char *addr) {
    return 0;
}

int not_command() {
    return 0;
}

int jmp_command(char *addr) {
    return 0;
}

int jn_command(char *addr) {
    return 0;
}

int jz_command(char *addr) {
    return 0;
}

int hlt_command() {
    return 0;
}

int run_mv(char *filename) {
    FILE *fp;
    long file_size;
    char *buffer;
    size_t bytes_read;

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file");
        return -1;
    }

    fseek(fp, 0, SEEK_END);
    file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    
    buffer = (char *)malloc(file_size);
    if(buffer == NULL){
        printf("Memory allocation failed!\n");
        fclose(fp);
        return -1;
    }

    bytes_read = fread(buffer, 1, file_size, fp);
    if(bytes_read != file_size){
        printf("Error reading file, expected %ld bytes, read %zu\n", file_size, bytes_read);
        fclose(fp);
        free(buffer);
        return -1;
    }
    
    printf("Read %zu bytes. Content:\n", bytes_read);
    for (size_t i = 0; i < bytes_read; i++) {
        printf("%02X ", (unsigned char)buffer[i]);
        if((i + 1) % 16 == 0) {
            printf("\n");
        }
    }
    printf("\n");

    fclose(fp);
    free(buffer);

    return 0;
}

int main(int argc, char **argv) {
    for (int i = 0; i < argc; i++) {
        printf("Argument %d: %s\n", i, argv[i]);
    }
    printf("\n");

    if(argv[1] == NULL){
        printf("Filename is null!\n");
        return -1;
    }

    if(argv[2] != NULL){
        pc = argv[2];
    }

    return run_mv(argv[1]);
}