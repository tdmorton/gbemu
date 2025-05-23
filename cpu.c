#include "cpu.h"

reg_t* reg_init()
{
    reg_t* reg = malloc(sizeof(reg_t));
    return reg;
}

void reg_free(reg_t* reg)
{
    free(reg);
}