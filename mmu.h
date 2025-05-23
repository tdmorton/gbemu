#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct mmu
{
    uint8_t bios[0x0100];

    union
    {
        uint8_t addr[0x10000];

        struct
        {
            uint8_t rom[2][0x4000];
            uint8_t vram[0x2000];
            uint8_t eram[0x2000];
            uint8_t wram[0x2000];
            uint8_t wrams[0x1E00];
            uint8_t oam[0xA0];
            uint8_t empty[0x60];
            uint8_t io[0x40];
            uint8_t ppu[0x40];
            uint8_t zram[0x7F];
            uint8_t intenable;
        };
        
    };
    uint8_t* finished_bios;
} mmu_t;

mmu_t* mmu_init();

void mmu_free(mmu_t* mmu);

uint8_t mmu_read8(mmu_t* mmu, uint16_t addr);

void mmu_write8(mmu_t* mmu, uint16_t addr, uint8_t data);

uint16_t mmu_read16(mmu_t* mmu, uint16_t addr);

void mmu_write16(mmu_t* mmu, uint16_t addr, uint16_t data);

void mmu_load_bios(mmu_t* mmu);

