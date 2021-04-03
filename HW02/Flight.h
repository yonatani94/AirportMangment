#pragma once
#include "Airport.h"
#include "AirportManger.h"

#define size 11 // dd/mm/yyyy = 2+2+4+2+1=11
typedef struct
{
	Airport* source;
	Airport* dest;
	int hour;
	Date* date;
	float speed;

}Flight;

typedef struct
{
	int day;
	int month;
	int year;
}Date;

void timeTravelByHourAndMinute(float distance, float speed, float* hour, float* minute);
int checkFlight(Flight* flight, char* codeSource, char* codeDest);
void initFlight(Flight* flight, AirportManger* airportManger);
void printFlight( Flight* flight);
Date* initDate(Date* date);
void freeFlight(Flight* flight);
