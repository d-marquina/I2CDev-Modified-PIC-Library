/* 
 * File:   I2CdevModReadBytes.c
 * Author: Daniel Marquina
 *
 * Created on 28/09/2017
 * 
 * Copyright (c) 2013 Jeff Rowberg
 * Copyright (c) 2014 Marton Sebok
 * Copyright (c) 2017 Daniel Marquina 
 */

#include "I2CdevMod.h"

/* Read multiple bytes from an 8-bit device register.
   @param devAddr: I2C slave device address
   @param fRegAddr: First register to read from
   @param nBytes: Number of bytes to read
   @param pVar: Pointer to variable where read data will be stored in
   @return statOp: Status of operation, true if every ACK was received
   */
bit I2CdevModReadBytes(uint8_t devAddr, uint8_t fRegAddr, uint8_t nBytes, uint8_t* pVar) {
    
    bit statOp = true;
    IdleI2C();
    StartI2C();
    IdleI2C();
    statOp &= (bit)(WriteI2C((uint8_t)(devAddr << 1)) == 0);
    IdleI2C();
    statOp &= (bit)(WriteI2C(fRegAddr) == 0);
    IdleI2C();
    RestartI2C();
    IdleI2C();
    statOp &= (bit)(WriteI2C((uint8_t)((devAddr << 1) + 1)) == 0);
    for (uint8_t i = 0; i < nBytes - 1; i++) {
        IdleI2C();
        pVar[i] = ReadI2C();
        // ACK
        IdleI2C();
        AckI2C();
    }
    pVar[nBytes - 1] = ReadI2C();
    IdleI2C();
    NotAckI2C();
    IdleI2C();
    StopI2C();
    return statOp;
}
