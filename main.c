#include "mmu.h"
#include "cpu.h"

int memtest(mmu_t* mmu, reg_t* reg);
int main()
{

    mmu_t* mmu = mmu_init();
    reg_t* reg = reg_init();

    mmu_load_bios(mmu);
    printf("Bios[100]: %X\n", mmu->bios[100]);

    memtest(mmu, reg);
    return 1;

}

int memtest(mmu_t* mmu, reg_t* reg)
{
    mmu->addr[0x1000] = 0xEB;
    printf("%X\n", mmu->rom[0][0x1000]);
    reg->AF = 0x1452;
    printf("%X\t%X\n", reg->A, reg->F);
}