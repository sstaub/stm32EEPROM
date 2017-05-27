#include "mbed.h"
#include "stm32EEPROM.h"

int main() {
  wait_ms(3000);
  printf("Erasing old data\n");
  for (uint32_t i = 0; i < 256; i++) {
    writeEEPROMByte(i, 0);
    }
  for (uint32_t i = 0; i < 256; i++) {
    uint8_t storedValue = readEEPROMByte(i);
    printf("Stored value in address %lu is %d \n\r", i, storedValue);
    }
  printf("Writing new data\n");
  for (uint32_t i = 0; i < 256; i++) {
    writeEEPROMByte(i, (uint8_t)i);
    }
  printf("Ready\n");
  for (uint32_t i = 0; i < 256; i++) {
    uint8_t storedValue = readEEPROMByte(i);
    printf("Stored value in address %lu is %d \n\r", i, storedValue);
    }
  }
