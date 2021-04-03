#define _CRT_SECURE_NO_WARNINGS

#include "Airport.h"
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>


void printAirport( Airport* a)
{
	printf("Airport Code: %s, Airport Name: %s, Airport Country: %s, Latitude: %.3f, Longitude: %.3f\n", a->IATA, a->name, a->country, a->latitude, a->longitude);
}

void freeAirport(Airport* a)
{
	free(a->name);
	free(a->country);
	free(a->IATA);
}






float possibleRange(float num,int min,int max)
{
	
	if (num >= min && num <= max)
		return num;
	else
	{
		printf("invaild range try agian\n");
	
		while (num < min || num > max)
		{
			if(!scanf("%f", &num));
			if (num >= min && num <= max)
				return num;
		}
			}
}


char* upperCaseFirstChar(char* str)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		//check first character is lowercase alphabet
		if (i == 0)
		{
			if ((str[i] >= 'a' && str[i] <= 'z'))
				str[i] = str[i] - 32; //subtract 32 to make it capital
			continue; //continue to the loop
		}
		else
		{
			//all other uppercase characters should be in lowercase
			if (str[i] >= 'A' && str[i] <= 'Z')
				str[i] = str[i] + 32; //subtract 32 to make it small/lowercase
		}
	}
	return str;
}


char* userInput()
{ //הפוקנציה מאתחלת פוינטר
	char* ptr;
	int spaceFlag = 0;
	int length = 0;
	char c = '0';
	ptr = calloc(1, sizeof(char));
	
	while (c != '\n') {
		c = getchar();
		if (c == ' ') spaceFlag++;
		if (c == EOF || c == '\n') {
			break;
		}
		else if (c == ' ' && strlen(ptr) == 0); //מטפל ברווח בתחילת הסטרינג
			
		else if (c != ' ' || spaceFlag == 1) {//מטפל ברווחים בין מילים+מוסיף אותיות
			ptr = (char*)realloc(ptr, sizeof(char) * (length + 1));
			if (!ptr) return NULL;
			ptr[length] = c;
			ptr[length + 1] = '\0';
			length++;
		}
	}
	if (ptr[length - 1] == ' ') {//מסיר רווח בסוף הסטרינג
		ptr[length - 1] = '\0';
	}
	return ptr;
}


void initAirport(Airport* airport)
{
	printf("-----------------Airport Init---------------------------\n");

	printf("Enter name for airport: \n");
	fflush(stdin);
	char* name = userInput();
	airport->name = (char*)malloc((strlen(name) + 1) * sizeof(char));
	if (!airport->name) return;
	name = upperCaseFirstChar(name);
	strcpy(airport->name, name);
	printf("Enter a country name: \n");
	char* country = userInput();
	airport->country = (char*)malloc((strlen(country) + 1) * sizeof(char));
	if (!airport->country) return;
	strcpy(airport->country, country);
	printf("Enter a Code IATA [3] : \n");
	char* code = userInput();
	if (strlen(code) != 3) {
		while (strlen(code) != 3) {
				printf("Code Must Be In 3 Letter Format! Try Again: ");
				code = userInput();
						}
					}
	airport->IATA = (char*)malloc((strlen(code) + 1) * sizeof(char));
	if (!airport->IATA) return NULL;
	_strupr(code);
	strcpy(airport->IATA,code);
	printf("Enter a latitude :\n");
	float lati;
	if (!scanf("%f%*c", &lati));
	lati = possibleRange(lati,MINFI, MAXFI);
	airport->latitude = lati;
	printf("Enter a longtitude :\n");
	float longi;
	if(!scanf("%f%*c", &longi));
	longi = possibleRange(longi, MINDELTA, MAXDELTA);
	airport->longitude = longi;

}
int sameAirport(Airport* a, Airport* b)
{
	if(strcmp(*a->IATA ,*b->IATA)!=0)
	return 0;

	return 1;
}

int exsistAirpott(Airport* a, char* code)
{
	if(strcmp(code,a->IATA)==0)
	return 1;

	return 0;
}

float distansceBetweenAirports(Airport* a, Airport* b)
{
    float dst = CalculateDistance(a->latitude, a->longitude, b->latitude,b->longitude);
    return dst;
}

float CalculateDistance(double nLat1, double nLon1, double nLat2, double nLon2)
{
	double dLat = (nLat2 - nLat1) *
		M_PI / 180.0;
	double dLon = (nLon2 - nLon1) *
		M_PI / 180.0;

	// convert to radians 
	nLat1 = (nLat1)*M_PI / 180.0;
	nLat2 = (nLat2)*M_PI / 180.0;

	// apply formulae 
	double a = pow(sin(dLat / 2), 2) +
		pow(sin(dLon / 2), 2) *
		cos(nLat1) * cos(nLat2);
	double rad = 6371;
	double c = 2 * asin(sqrt(a));
	return rad * c * 0.621371192; // km to miles
}



