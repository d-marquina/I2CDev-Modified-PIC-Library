/* 
 * File:   I2CdevModReadBits.c
 * Author: Daniel Marquina
 *
 * Created on 29/09/2017
 * 
 * Copyright (c) 2013 Jeff Rowberg
 * Copyright (c) 2014 Marton Sebok
 * Copyright (c) 2017 Daniel Marquina 
 */

#include "I2CdevMod.h"

/* Read multiple bits from an 8-bit device register.
   @param devAddr: I2C slave device address
   @param regAddr: Register to read from
   @param msbToRead: Position of MSB to read (from left to right, 76543210)
   @param nBits: number of bits to read
   @param pVar: Pointer to variable where to-read-bit will be stored in
   @return statOp: Status of operation, true if every ACK was received
   */   
    // 01101001 read byte
    // 76543210 bit positions
    //    xxx   args: msbToRead = 4, nBits = 3
    //    010   masked
    //   -> 010 shifted
bit I2CdevModReadBits(uint8_t devAddr, uint8_t regAddr, uint8_t msbToRead, uint8_t nBits, uint8_t* pVar){

    
    uint8_t bBit;
    bit statOp = I2CdevModReadByte(devAddr, regAddr, &bBit);
    if (statOp) {
        uint8_t mask = (uint8_t)(((0x01 << nBits) - 1) << (msbToRead - nBits + 1));
        bBit &= mask;
        bBit >>= (msbToRead - nBits + 1);
        *pVar = bBit;
    }
    return statOp;
}

