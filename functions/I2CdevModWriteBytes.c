/* 
 * File:   I2CdevModWriteBytes.c
 * Author: Daniel Marquina
 *
 * Created on 29/09/2017
 * 
 * Copyright (c) 2013 Jeff Rowberg
 * Copyright (c) 2014 Marton Sebok
 * Copyright (c) 2017 Daniel Marquina
 */

#include "I2CdevMod.h"

/* Write multiple bytes to an 8-bit device register.
   @param devAddr: I2C slave device address
   @param fRegAddr: First register to write to
   @param nBytes: Number of bytes to write to
   @param pData: Pointer to variable where to-write-data is stored in
   @return statOp: Status of operation, true if every ACK was received
   */
bit I2CdevModWriteBytes(uint8_t devAddr, uint8_t fRegAddr, uint8_t nBytes, uint8_t* pData) {

    bit statOp = true;
    IdleI2C();
    StartI2C();
    IdleI2C();
    statOp &= (bit)(WriteI2C((uint8_t)(devAddr << 1)) == 0);
    IdleI2C();
    statOp &= (WriteI2C(fRegAddr) == 00);
    for (uint8_t i = 0; i < nBytes; i++) {
        IdleI2C();
        statOp &= (WriteI2C(pData[i]) == 0);
    }
    IdleI2C();
    StopI2C();
    return true;
}

