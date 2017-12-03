/* 
 * File:   I2CdevModWriteByte.c
 * Author: Daniel Marquina
 *
 * Created on 30/09/2017
 * 
 * Copyright (c) 2013 Jeff Rowberg
 * Copyright (c) 2014 Marton Sebok
 * Copyright (c) 2017 Daniel Marquina
 */

#include "I2CdevMod.h"

/* Write a single byte to an 8-bit device register.
   @param devAddr: I2C slave device address
   @param regAddr: Register to write to
   @param data: Value to write
   @return statOp: Status of operation, true if every ACK was received
   */
bit I2CdevModWriteByte(uint8_t devAddr, uint8_t regAddr, uint8_t data) {

    return I2CdevModWriteBytes(devAddr, regAddr, 1, &data );
}

