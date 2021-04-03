
#pragma once
#include "Airport.h"
#define maxAirport 100

typedef struct {
	Airport** allAirport;
	int countAirport;
}AirportManger;


int exsistAirpotInManger(AirportManger* Am, char* code);

void addAirportTo(AirportManger* Am, Airport* airport,int index);
void InsertAirport(AirportManger* Am, Airport* airport);

int addAirport(AirportManger* Am, Airport* airport,int index);
Airport* findByIndex(AirportManger* Am, char* code, int index);
Airport* find(AirportManger* Am, char* code);

void initAirportManger(AirportManger* Am, Airport* airport);
void printManager( AirportManger* Am);

void freeAirportManger(AirportManger* Am);