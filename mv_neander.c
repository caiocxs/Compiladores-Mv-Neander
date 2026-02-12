#include "mv_neander.h"
#include <stdio.h>
#include <stdlib.h>

int ac = 0;
int pc = 0;

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

int run_mv(char *filename) {
    FILE *fp;

    if ((fp = fopen(filename, "rb")) == NULL) {
        printf("Error opening file");
        return -1;
    }

    return 0;
}

int main(int argc, char **argv) {
    for (int i = 0; i < argc; i++) {
        printf("Argument %d: %s\n", i, argv[i]);
    }

    return 0;
}