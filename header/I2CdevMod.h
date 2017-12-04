/*  
 * I2C Device Modified Library for PIC18
 * File:   I2CdevMod.h
 * Author: Daniel Marquina
 *
 * This library is an adaptation of the I2C Device Library for PIC18 by Jeff 
 * Rowberg.
 * Currently compatible with 8-bit devices ONLY.
 *
 * Created on 28/09/2017
 * 
 * Copyright (c) 2013 Jeff Rowberg
 * Copyright (c) 2014 Marton Sebok
 * Copyright (c) 2017 Daniel Marquina 
 * 
 */

#ifndef I2CDEVMOD_H
#define	I2CDEVMOD_H

#ifdef	__cplusplus
extern "C" {
#endif

#ifndef __XC8
    #error Use XC8 for compiling
#endif

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include "i2c.h"

bit I2CdevModReadBytes(uint8_t devAddr, uint8_t fRegAddr, uint8_t nBytes, uint8_t* pVar);
bit I2CdevModReadByte(uint8_t devAddr, uint8_t regAddr, uint8_t* pVar);
bit I2CdevModReadBits(uint8_t devAddr, uint8_t regAddr, uint8_t msbToRead, uint8_t nBits, uint8_t* pVar);
bit I2CdevModReadBit(uint8_t devAddr, uint8_t regAddr, uint8_t bitPos, uint8_t* pVar);
bit I2CdevModWriteBytes(uint8_t devAddr, uint8_t fRegAddr, uint8_t nBytes, uint8_t* pData);
bit I2CdevModWriteByte(uint8_t devAddr, uint8_t regAddr, uint8_t data);
bit I2CdevModWriteBits(uint8_t devAddr, uint8_t regAddr, uint8_t msbToWrite, uint8_t nBits, uint8_t data);
bit I2CdevModWriteBit(uint8_t devAddr, uint8_t regAddr, uint8_t bitPos, uint8_t data);

#ifdef	__cplusplus
}
#endif

#endif	/* I2CDEVMOD_H */

