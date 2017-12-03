/* 
 * File:   I2CdevModReadByte.c
 * Author: Daniel Marquina
 *
 * Created on 29/09/2017
 * 
 * Copyright (c) 2013 Jeff Rowberg
 * Copyright (c) 2014 Marton Sebok
 * Copyright (c) 2017 Daniel Marquina 
 */

#include "I2CdevMod.h"

/* Read a single byte from an 8-bit device register.
   @param devAddr: I2C slave device address
   @param regAddr: Register to read from
   @param pVar: Pointer to variable where read data will be stored in
   @return: Status of operation, true if every ACK was received
   */
bit I2CdevModReadByte(uint8_t devAddr, uint8_t regAddr, uint8_t* pVar) {

    return I2CdevModReadBytes(devAddr, regAddr, 1, pVar);
}

