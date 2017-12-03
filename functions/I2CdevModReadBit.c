/* 
 * File:   I2CdevModReadBit.c
 * Author: Daniel Marquina
 *
 * Created on 29/09/2017
 * 
 * Copyright (c) 2013 Jeff Rowberg
 * Copyright (c) 2014 Marton Sebok
 * Copyright (c) 2017 Daniel Marquina
 */

#include "I2CdevMod.h"

/* Read a single bit from an 8-bit device register.
   @param devAddr: I2C slave device address
   @param regAddr: Register to read from
   @param bitPos: Position of bit to read (76543210)
   @param pVar: Pointer to variable where to-read-bit will be stored in
   @return statOp: Status of operation, true if every ACK was received
   */
   // Positions   76543210
   // To-read bit   x     
   // Register    10101010
   // Result      00100000
bit I2CdevModReadBit(uint8_t devAddr, uint8_t regAddr, uint8_t bitPos, uint8_t* pVar) {

    uint8_t bBit; // Byte where the to-read bit is stored
    bit statOP = I2CdevModReadByte(devAddr, regAddr, &bBit);
    *pVar = (uint8_t)(bBit & (0x01 << bitPos));
    return statOP;
}

