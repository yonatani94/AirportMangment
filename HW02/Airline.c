#define _CRT_SECURE_NO_WARNINGS

#include "Airline.h"
#include <stdio.h>
#include <stdarg.h>

void insertFlight(Airline* airline,Flight* flight,AirportManger* airportmanger)
{
	initFlight(flight, airportmanger);
	if(addFlight(airline, flight)==1);

}

int addFlight(Airline* airline, Flight* flight)
{
	Flight* temp;
	airline->allFilght = (Flight**)realloc(airline->allFilght, (airline->countFlight + 1) * sizeof(Flight*));
	if (!airline->allFilght)
		return 0;
	temp = (Flight*)malloc(sizeof(Flight));
	if (!temp)
		return 0;
	*temp = *flight;
	airline->allFilght[airline->countFlight] = temp;
	airline->countFlight++;
	return 1;
}

void initAirline(Airline* airline)
{
	printf("-----------------Airline Init---------------------------\n");

	printf("enter name for company airline : \n");
	char* name = userInput();
	airline->nameCompany = (char*)malloc((strlen(name) + 1) * sizeof(char));
	if (!airline->nameCompany) return;
	strcpy(airline->nameCompany,name);
	printf("how many air plane you want : \n");
	int countAirplane;
	
	if(!scanf("%d%*c", &countAirplane));

	airline->countFlight = 0;
	airline->allFilght = NULL;
	airline->countAirplane = countAirplane;



}

int countFlightsLine(Airline* allFlights, char* codeSource, char* codeDest)
{
	int count = 0;
	for (int i = 0; i < allFlights->countFlight; i++)
	{
		if (checkFlight(allFlights->allFilght[i], codeSource, codeDest) == 1)
			count++;
	}
	return count;
}

void printAirline(Airline* airline)
{
	printf("Comapny name : %s\nNumber of airplane is %d\nNumber of flights is %d\n",airline->nameCompany,airline->countAirplane,airline->countFlight);
	if (airline->countFlight > 0)
	{
		for (int i = 0; i < airline->countFlight; i++)
		{
			printFlight(airline->allFilght[i]);
		}
	}
	
}

void  printCountFlightsLine(Airline* allFlights, AirportManger* airportManger)
{

	printf("Enter Airport Departure Code: ");
	char* source = userInput();
	_strupr(source);
	Airport* airportSource;
	airportSource = find(airportManger, source);
	while (airportSource == NULL || strlen(source) != 3) {
		printf("No Such Airport Exists! Try Again: \n");
		source = userInput();
		_strupr(source);
		airportSource = find(airportManger, source);

	}

	printf("Enter Airport Arrival Code: ");
	char* dst = userInput();
	_strupr(dst);
	Airport* airportDst;
	airportDst = find(airportManger, dst);
	while (strcmp(dst, source) == 0 || airportDst == NULL || strlen(dst) != 3) {
		printf("No Such Airport Exists!/Arrival Cannot Be Identical To Departure! Try Again: ");
		dst = userInput();
		_strupr(dst);
		airportDst = find(airportManger, dst);
	}
	int count = countFlightsLine(allFlights, source, dst);
	if (count > 0)
	{
		printf("The numbers flights between %s and %s is %d\n", source, dst, count);
	}
	else printf("Not such Flight between %s and %s\n", source, dst);
	

	
}

void freeAirline(Airline* airline)
{
	for (int i = 0; i < airline->countFlight; i++)
	{
		freeFlight(airline->allFilght[i],airline->allFilght[i]->date);
		free(airline->allFilght[i]);
	}
	free(airline->allFilght);
	free(airline->nameCompany);
}
