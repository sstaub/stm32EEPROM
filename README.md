# mbed stm32EEPROM Library

The **mbed stm32EEPROM Library** allows you to write and read data (uint8_t) to the internal EEPROM of STM32L0xx and STM32L1xx microcontrollers, e.g. Nucleo-64 STM32L152RE.

## Installation

1. "Download": https://github.com/sstaub/stm32EEPROM/archive/master.zip the Master branch from GitHub.
2. Unzip and modify the folder name to "stm32EEPROM"
3. Move the modified folder in your Library folder (e.g. in your `lib` folder inside PlatformIO).


## How to use

First, include the stm32EEPROM.h to your project:

```
#include "stm32EEPROM.h"
```

Now, you can write and read data (uint8_t) to the internal EEPROM:

```
readEEPROMByte(5, 127); // write 127 to memory 5 of the EEPROM
uint8_t data = readEEPROMByte(5); // reads the data of memory 5
```

## IMPORTANT
The library is only tested with the Nucleo-64 STM32L152RE board. The maximum size of the EEPROM differs from type to type, e.g. Nucleo-64 STM32L152RE has 16kB EEPROM .

## Example

First we delete old data and show the values (only zeros). Then we write some data to the first 255 memories and show the new values.

```
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
```

## Documentation

### Functions

**HAL_StatusTypeDef writeEEPROMByte(uint32_t address, uint8_t data)**<br>
Write a byte (uint8_t) to a given address (uint32_t) of the EEPROM. Return the HAL Status.

**uint8_t readEEPROMByte(uint32_t address)**<br>
Read a byte (uint8_t) from a given address (uint32_t) of the EEPROM.
