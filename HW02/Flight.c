#define _CRT_SECURE_NO_WARNINGS

#include "Flight.h"
#include <string.h>
#include <stdio.h>
#include<stdlib.h>

void timeTravelByHourAndMinute(float distance, float speed, float* hour, float* minute)
{
	float byHour = 0;
	byHour = distance / speed;
	*hour = byHour;
	float byMin = byHour * 60;
	*minute = byMin;

}

int checkFlight(Flight* flight, char* codeSource, char* codeDest)
{
	if(strcmp(flight->dest->IATA,codeDest)==0 && strcmp(flight->source->IATA, codeSource) == 0)
	return 1;

	return 0;
}




void initFlight(Flight* flight,AirportManger* airportManger)
{
	printf("-----------------Flight Init---------------------------\n");
	printf("Enter a hour for flight between 0-23\n");
	int hourStart;
	if (!scanf("%d", &hourStart));
	while (hourStart < 0 || hourStart > 23)
	{
		printf("invaild hour\nEnter a hour for flight between 0-23\n");
		if (!scanf("%d", &hourStart));

	}
	flight->hour = hourStart;
	
	printf("Enter a speed for flight[MPH] : \n");
	float speed;
	if (!scanf("%f%*c", &speed));
	flight->speed = speed;
	printf("Enter date for flight (DD/MM/YYYY format) : \n");
	//Date* date = (Date*)malloc(sizeof(Date));
	//if (!date) return NULL;
	
	flight->date = (Date*)malloc(sizeof(Date));
	//flight->date = (char*)malloc((strlen(date) + 1)*sizeof(char));
	if (!flight->date) return;
	flight->date = initDate(flight->date);
	
	//strcpy(flight->date, date);
	printf("Enter Airport Departure Code: ");
		char* source = userInput();
		_strupr(source);
		Airport* airportSource;
		airportSource = find(airportManger, source);
		while (airportSource == NULL) {
			printf("No Such Airport Exists! Try Again: \n");
			source = userInput();
			_strupr(source);
			airportSource = find(airportManger, source);

		}
		flight->source = airportSource;
	
		printf("Enter Airport Arrival Code: ");
		char* dst = userInput();
		_strupr(dst);
		Airport* airportDst;
		airportDst = find(airportManger, dst);
		while (strcmp(dst, source) == 0 || airportDst == NULL) {
			printf("No Such Airport Exists!/Arrival Cannot Be Identical To Departure! Try Again: ");
			dst = userInput();
			_strupr(dst);
			airportDst = find(airportManger, dst);
		}
	
		flight->dest = airportDst;
		printf("Flight Added Successfully!\n");




}

Date* initDate(Date* date)
{
		
		int num;
		char* date = malloc(sizeof(char) * 11);
		char* day;
		char* month;
		char* year;
		printf("Enter Day [1-31]: ");
		day = userInput();
		num = atoi(day);
		
		while (num < 1 || num>31) {
			printf("Day Not In Range! Try Again: ");
			day = userInput();
			num = atoi(day);
		}
		//if(!strcat(strcpy(date, day),"/"));
		date->day = num;

		printf("Enter Month [1-12]: ");
		month = userInput();
		num = atoi(month);
		while (num < 1 || num>12) {
			printf("Month Not In Range! Try Again: ");
			month = userInput();
			num = atoi(month);
		}
		date->month;
		//if(!strcat(strcat(date, month), "/"));
		printf("Enter Year [1970-2100]: ");
		year = userInput();
		num = atoi(year);
		while (num < 1970 || num>2100) {
			printf("Year Not In Range! Try Again: ");
			year = userInput();
			num = atoi(year);
		}
	//	strcat(date, year);
		date->year = year;
		
		return date;
	

}

void freeFlight(Flight* flight)
{
	free(flight->date);
	
}



void printFlight( Flight* flight)
{

	printf("\nsource flight\tdest flight\tFlight time\tDate Flight\tSpeed Flight\t\n---------------\t---------------\t---------------\t---------------\t---------------\t\n%s\t\t%s\t\t%d:00\t\t%s\t%.3f [Mph] \n",
		flight->source->IATA, flight->dest->IATA, flight->hour, flight->date, flight->speed);
	printf("\n");
	float distance = distansceBetweenAirports(flight->source, flight->dest);
	printf("Distance of flight is %f\n", distance);
	float hour,  minute;
	timeTravelByHourAndMinute(distance, flight->speed, &hour, &minute);

	printf("The Time in Hours is %.3f\nThe Time in Minutes is %.3f\n",hour ,minute);


}
