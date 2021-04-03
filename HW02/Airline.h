

#pragma once
#include "Flight.h"
#define max 15
typedef struct
{
	char* nameCompany;
	int countAirplane;
	int countFlight;
	Flight** allFilght;

}Airline;

void insertFlight(Airline* airline, Flight* flight, AirportManger* airportmanger);
void initAirline(Airline* airline);
int countFlightsLine(Airline* allFlights, char* codeSource, char* codeDest);
void printAirline(Airline* airline);
void  printCountFlightsLine(Airline* allFlights, AirportManger* airportManger);
void freeAirline(Airline* airline);
