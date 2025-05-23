#include <stdint.h>
#include <stdlib.h>

typedef struct reg
{
    union
    {
        uint16_t AF;
        struct
        {
            uint8_t F;
            uint8_t A;
        };
    };
    union
    {
        uint16_t BC;
        struct
        {
            uint8_t C;
            uint8_t B;
        };
    };
    union
    {
        uint16_t DE;
        struct
        {
            uint8_t E;
            uint8_t D;
        };
    };
    union
    {
        uint16_t HL;
        struct
        {
            uint8_t L;
            uint8_t H;
        };
    };


} reg_t;

reg_t* reg_init();

void reg_free(reg_t* reg);