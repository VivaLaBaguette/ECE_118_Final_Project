#ifndef EVENTCHECKER_H
#define	EVENTCHECKER_H


#include "ES_Configure.h"   // defines ES_Event, INIT_EVENT, ENTRY_EVENT, and EXIT_EVENT
#include "BOARD.h"

//uint8_t CheckBattery(void);

uint8_t Beacon_2k(void);

uint8_t Beacon_2KCLOSE(void);

uint8_t Beacon_15k(void);

uint8_t Tape_Front_Right(void);

uint8_t Tape_Front_Center(void);

uint8_t Tape_Front_Left(void);

uint8_t Tape_Back_Right(void);

uint8_t Tape_Back_Left(void);

#endif