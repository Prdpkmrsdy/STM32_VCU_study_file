#include <stdint.h>
#define SRAM_START 0x2000000U
#define SRAM_SIZE (128U *1024U) //128KB
#define SRAM_END ((SRAM_START) + (SRAM_END))

#define STACK_START SRAM_END

void Reset_handler(void) _attribute_((section(".random_section")));

uint32_t vector[] _attribute_((section(".isr_vector"))) ={
    STACK_START,
    (uint32_t) &Reset_handler,

};


void Reset_handler(void)
{

}