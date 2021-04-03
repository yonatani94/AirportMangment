#define _CRT_SECURE_NO_WARNINGS

#include"AirportManger.h"
#include <stdio.h>
#include <string.h>
#include <stdarg.h>


int exsistAirpotInManger(AirportManger* Am,char* code)
{
	for (int i = 0; i < Am->countAirport; i++)
	{
		if (exsistAirpott(Am->allAirport[i], code))
			return 1;
	}
	return 0;
}


void addAirportTo(AirportManger* Am, Airport* airport,int index)
{
	Airport* temp = NULL;
	int check = 0;
	
	if(index!=0)
		
	temp = findByIndex(Am, airport->IATA,index);
	
	if (temp == NULL&& index>=0)
	{
		addAirport(Am, airport,index);

		
		
	}
	else {

	
	while (exsistAirpotInManger(Am, airport->IATA))
	{
		printf("Not possible two airprot with the same Code IATA try agian\n");
		initAirport(airport);
		temp = findByIndex(Am, airport->IATA, index);
		if (temp == NULL && index >= 0)
		{
			addAirport(Am, airport, index);
			break;


		}

	}
	
}
	
}


int addAirport(AirportManger* Am, Airport* airport,int index)
{
	Airport* temp;
	if (!Am->allAirport)
		return 0;
	temp = (Airport*)malloc(sizeof(Airport));
	if (!temp)
		return 0;
	*temp = *airport;
	Am->allAirport[index] = temp;
	index++;
	return 1;

}

Airport* findByIndex(AirportManger* Am,char* code,int index)
{
	int i;
	for ( i = 0; i < index; i++)
	{
		if (strcmp(Am->allAirport[i]->IATA,code)==0)
			return Am->allAirport[i];
		
	}
	return NULL;
}

Airport* find(AirportManger* Am, char* code)
{
	int i;
	for (i = 0; i < Am->countAirport; i++)
	{
		if (strcmp(Am->allAirport[i]->IATA, code) == 0)
			return Am->allAirport[i];

	}
	return NULL;
}

void initAirportManger(AirportManger* Am, Airport* airport)
{
	printf("-----------------AirportManger Init---------------------------\n");

	printf("How many airlines do you want? \n");
	fflush(stdin);
	if (!scanf("%d%*c", &Am->countAirport));
	Am->allAirport = (Airport**)malloc(sizeof(Airport*) * Am->countAirport);
	if (!Am->allAirport) return NULL;
	for (int i = 0; i < Am->countAirport; i++)
	{
		initAirport(airport,Am);
		addAirportTo(Am, airport, i);
	}

	printf("Add successfuly airports to airport manger\n");
	
}

void InsertAirport(AirportManger* Am, Airport* airport)
{
	Airport* temp;
	Am->allAirport = (Airport**)realloc(Am->allAirport, (Am->countAirport + 1) * sizeof(Airport*));
	if (!Am->allAirport) return;
	temp = (Airport*)malloc(sizeof(Airport));
	if (!temp) return;
	*temp = *airport;
	Am->allAirport[Am->countAirport] = temp;
	Am->countAirport++;
	printf("Add successfuly airport to airport manger\n");
}

void printManager( AirportManger* apm) 
{
	printf("\nPrinting Airport Manager Data:\n");
	printf("Number of Airports: %d\n", apm->countAirport);
	for (int i = 0; i < apm->countAirport; i++) {
		printAirport(apm->allAirport[i]);
	}
}

void freeAirportManger(AirportManger* Am)
{
	for (int i = 0; i < Am->countAirport; i++)
	{
		freeAirport(Am->allAirport[i]);
		free(Am->allAirport[i]);
	}
	free(Am->allAirport);
}
