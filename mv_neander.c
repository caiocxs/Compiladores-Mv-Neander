#include "mv_neander.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int ac = 0;
int pc = 0;
unsigned char *v;
size_t bytes_read;

enum NEANDER_COMMANDS
{
    NOP = 0x00,
    STA = 0x10,
    LDA = 0x20,
    ADD = 0x30,
    OR = 0x40,
    AND = 0x50,
    NOT = 0x60,
    JMP = 0x80,
    JN = 0x90,
    JZ = 0xA0,
    HLT = 0xF0
};

unsigned char SIGNATURE[] = {0x03, 0x4E, 0x44, 0x52};

int n_function()
{
    if (ac > 0)
        return 0;
    else
        return 1;
}

int z_function()
{
    if (ac == 0)
        return 1;
    else
        return 0;
}

int nop_command()
{
    return 0;
}

int sta_command(unsigned char addr)
{
    printf("\nSTA - HEXA: %x, DECI: %d, VALUE: %d", addr, addr, v[((int)addr + 2) * 2]);

    v[((int)addr + 2) * 2] = (unsigned char)ac;

    return 0;
}

int lda_command(unsigned char addr)
{
    printf("\nLDA - HEXA: %x, DECI: %d, VALUE: %d", addr, addr, v[((int)addr + 2) * 2]);
    ac = (int)v[((int)addr + 2) * 2];
    return 0;
}

int add_command(unsigned char addr)
{
    printf("\nADD - HEXA: %x, DECI: %d, VALUE: %d", addr, addr, v[((int)addr + 2) * 2]);
    ac += (int)v[((int)addr + 2) * 2];
    return 0;
}

int or_command(unsigned char addr)
{
    printf("\nOR - HEXA: %x, DECI: %d, VALUE: %d", addr, addr, v[((int)addr + 2) * 2]);
    ac = ac | v[((int)addr + 2) * 2];
    return 0;
}

int and_command(unsigned char addr)
{
    printf("\nAND - HEXA: %x, DECI: %d, VALUE: %d", addr, addr, v[((int)addr + 2) * 2]);
    ac = ac & v[((int)addr + 2) * 2];
    return 0;
}

int not_command()
{
    ac = !ac;
    return 0;
}

int jmp_command(unsigned char addr)
{
    printf("\nJMP - HEXA: %x, DECI: %d, VALUE: %d", addr, addr, v[((int)addr + 2) * 2]);

    pc = (int)v[((int)addr + 2) * 2];
    return 0;
}

int jn_command(unsigned char addr)
{
    printf("\nJN - HEXA: %x, DECI: %d, VALUE: %d", addr, addr, v[((int)addr + 2) * 2]);
    if (n_function())
    {
        pc = (int)v[((int)addr + 2) * 2];
    }
    return 0;
}

int jz_command(unsigned char addr)
{
    printf("\nJZ - HEXA: %x, DECI: %d, VALUE: %d", addr, addr, v[((int)addr + 2) * 2]);
    if (n_function())
    {
        pc = (int)v[((int)addr + 2) * 2];
    }
    return 0;
}

int hlt_command()
{
    pc = bytes_read;
    return 0;
}

int get_signature()
{
    char *v_sig = (char *)malloc(sizeof(SIGNATURE));
    if (v_sig == NULL)
        return -1;

    memcpy(v_sig, v, sizeof(SIGNATURE));

    printf("SIGNATURE: \n");
    for (size_t i = 0; i < sizeof(SIGNATURE); i++)
    {
        printf("%02X ", (unsigned char)v_sig[i]);
        if ((i + 1) % 16 == 0)
        {
            printf("\n");
        }
    }
    printf("\n");

    if (memcmp(v_sig, SIGNATURE, 4) == 0)
    {
        return 1;
    }

    return -1;
}

int print_neander(size_t bytes_read)
{
    printf("Read %zu bytes. Content:\n", bytes_read);
    for (size_t i = pc; i < bytes_read; i = i + 2)
    {
        printf("%02X ", v[i]);
        if (i % 16 == 0)
        {
            printf("\n");
        }
    }
    printf("\n\n");
}

int run_mv(char *filename)
{
    FILE *fp;
    long file_size;

    fp = fopen(filename, "rb");
    if (fp == NULL)
    {
        printf("Error opening file");
        return -1;
    }

    fseek(fp, 0, SEEK_END);
    file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    v = (unsigned char *)malloc(file_size);
    if (v == NULL)
    {
        printf("Memory allocation failed!\n");
        fclose(fp);
        return -1;
    }

    bytes_read = fread(v, 1, file_size, fp);
    if (bytes_read != file_size)
    {
        printf("Error reading file, expected %ld bytes, read %zu\n", file_size, bytes_read);
        fclose(fp);
        free(v);
        return -1;
    }

    if (get_signature() == -1)
    {
        printf("Error file.bin is not make for neander!");
        return -1;
    }
    printf("\n");

    pc = (pc % 256) + 4; // skip the signature

    print_neander(bytes_read);

    while (pc < bytes_read)
    {
        int result;

        switch (v[pc])
        {
        case NOP:
            result = nop_command();
            break;
        case STA:
            pc = pc + 2;
            result = sta_command(v[pc]);
            printf("\nAC: %d", ac);
            break;
        case LDA:
            pc = pc + 2;
            result = lda_command(v[pc]);
            printf("\nAC: %d", ac);
            break;
        case ADD:
            pc = pc + 2;
            result = add_command(v[pc]);
            printf("\nAC: %d", ac);
            break;
        case OR:
            pc = pc + 2;
            result = or_command(v[pc]);
            printf("\nAC: %d", ac);
            break;
        case NOT:
            pc = pc + 2;
            result = not_command();
            printf("\nAC: %d", ac);
            break;
        case JMP:
            pc = pc + 2;
            result = jmp_command(v[pc]);
            printf("\nAC: %d", ac);
            break;
        case JN:
            pc = pc + 2;
            result = jn_command(v[pc]);
            printf("\nAC: %d", ac);
            break;
        case JZ:
            pc = pc + 2;
            result = jz_command(v[pc]);
            printf("\nAC: %d", ac);
            break;
        default:
            break;
        }

        if ((pc - 4) % 16 == 0)
        {
            // printf("\n");
        }

        pc = pc + 2;
    }
    printf("\n");

    print_neander(bytes_read);

    fclose(fp);
    free(v);

    return 0;
}

int main(int argc, char **argv)
{
    for (int i = 0; i < argc; i++)
    {
        printf("Argument %d: %s\n", i, argv[i]);
    }
    printf("\n");

    if (argv[1] == NULL)
    {
        printf("Filename is null!\n");
        return -1;
    }

    if (argv[2] != NULL)
    {
        pc = atoi(argv[2]);
    }

    return run_mv(argv[1]);
}