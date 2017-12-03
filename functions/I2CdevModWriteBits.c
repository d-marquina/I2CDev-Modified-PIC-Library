/* 
 * File:   I2CdevModWriteBits.c
 * Author: Daniel Marquina
 *
 * Created on 30/09/2017, 12:55 AM
 * 
 * Copyright (c) 2013 Jeff Rowberg
 * Copyright (c) 2014 Marton Sebok
 * Copyright (c) 2017 Daniel Marquina
 */

#include "I2CdevMod.h"

/* Write multiple bits to an 8-bit device register.
   @param devAddr: I2C slave device address
   @param regAddr: Register regAddr to write to
   @param msbToWrite: Position of MSB to write (from left to right, 76543210)
   @param nBits: number of bits to write (not more than 8)
   @param data: Right-aligned value to write (XX..Xdata)
   @return Status of operation, true if every ACK was received
   */   
   //      010 data, value to write
   // 76543210 bit positions
   //    xxx   args: msbToWrite=4, nBits=3
   // 00011100 mask byte
   // 10101111 original register value (sample)
   // 10100011 original & ~mask
   // 10101011 masked | value
bit I2CdevModWriteBits(uint8_t devAddr, uint8_t regAddr, uint8_t msbToWrite, uint8_t nBits, uint8_t data) {
    
    uint8_t bBit;
    if (I2CdevModReadByte(devAddr, regAddr, &bBit) != 0) {
        uint8_t mask = (uint8_t)(((1 << nBits) - 1) << (msbToWrite - nBits + 1));
        data <<= (msbToWrite - nBits + 1); // shift data into correct position
        data &= mask; // zero all non-important bits in data
        bBit &= (uint8_t)(~(mask)); // zero all important bits in existing byte
        bBit |= data; // combine data with existing byte
        return I2CdevModWriteByte(devAddr, regAddr, bBit);
    } else {
        return false;
    }
}

