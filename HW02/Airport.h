



#pragma once

#define M_PI 3.14159265358979323846

#define MAXFI 90
#define MINFI -90
#define MAXDELTA 180
#define MINDELTA -180

typedef struct {
	char* name;
	char* country;
	char* IATA;
	float latitude, longitude;
}Airport;

void initAirport(Airport* airport);
int sameAirport(Airport* a, Airport* b);
int exsistAirpott(Airport* a,char* code);
float distansceBetweenAirports(Airport* a, Airport* b);
float CalculateDistance(double nLat1, double nLon1, double nLat2, double nLon2);
char* userInput();
float possibleRange(float num, int min, int max);
void printAirport( Airport* a);
void freeAirport(Airport* a);
char* upperCaseFirstChar(char* str);

