/* stm32EEPROM library code is placed under the MIT license
 * Copyright (c) 2017 Stefan Staub
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef STM32EEPROM_H
#define STM32EEPROM_H

#include "mbed.h"

#define EEPROM_BASE_ADDRESS 0x08080000UL

/**
 * writeEEPROMByte allows to write a byte(uint8_t) to the internal eeprom
 * @param   address  starts at 0, the max size depends on the uc type
 * @param   data     byte (uint8_t)
 * @return  status   internal HAL_Status
 */
HAL_StatusTypeDef writeEEPROMByte(uint32_t address, uint8_t data) {
  HAL_StatusTypeDef  status;
  address = address + EEPROM_BASE_ADDRESS;
  HAL_FLASHEx_DATAEEPROM_Unlock();  //Unprotect the EEPROM to allow writing
  status = HAL_FLASHEx_DATAEEPROM_Program(TYPEPROGRAMDATA_BYTE, address, data);
  HAL_FLASHEx_DATAEEPROM_Lock();  // Reprotect the EEPROM
  return status;
  }

/**
 * readEEPROMByte reads a byte from an internal eeprom
 * @param   address  of the eeprom byte
 * @return  data     as a byte (uint8_t)
 */
uint8_t readEEPROMByte(uint32_t address) {
  uint8_t data = 0;
  address = address + EEPROM_BASE_ADDRESS;
  data = *(__IO uint32_t*)address;
  return data;
  }

#endif
