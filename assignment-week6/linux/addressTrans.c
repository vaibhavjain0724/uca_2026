#include <stdio.h>
#include <stdint.h>

int main(){
    uint32_t virtualAdress;
    scanf("%X",&virtualAdress);

    uint32_t pageNumber = 0;
    uint32_t offset = 0;

    uint32_t offsetMask = 0x0FFF;

    offset = virtualAdress & offsetMask;
    pageNumber = virtualAdress >> 12;

    printf("[1A] Addr: %X -> Page:%d (%X), Offset: %d (%X)\n", virtualAdress, pageNumber, pageNumber , offset, offset);
}