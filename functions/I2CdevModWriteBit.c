/* 
 * File:   I2CdevModWriteBit.c
 * Author: Daniel Marquina
 *
 * Created on 30/09/2017, 01:02 AM
 * 
 * Copyright (c) 2013 Jeff Rowberg
 * Copyright (c) 2014 Marton Sebok
 * Copyright (c) 2017 Daniel Marquina
 */

#include "I2CdevMod.h"

/* Write a single bit to an 8-bit device register.
   @param devAddr: I2C slave device address
   @param regAddr: Register regAddr to write to
   @param bitPos: Position of bit to write (from left to right, 76543210)
   @param data: Right-aligned value to write (XX..Xdata)
   @return Status of operation, true if every ACK was received
   */
bit I2CdevModWriteBit(uint8_t devAddr, uint8_t regAddr, uint8_t bitPos, uint8_t data) {

    uint8_t bBit;
    I2CdevModReadByte(devAddr, regAddr, &bBit);
    bBit = (uint8_t)((data != 0) ? (bBit | (1 << bitPos)) : (bBit & ~(1 << bitPos)));
    return I2CdevModWriteByte(devAddr, regAddr, bBit);
}

