#define _CRT_SECURE_NO_WARNINGS
// autor : Yehonatan arami 205781776
#include "Airport.h"
#include "Airline.h"
#include "Flight.h"
#include "AirportManger.h"
void main()
{

	
	Airport airport;
	AirportManger airportManger;
	Flight flight;
	Airline airline;
	
		int choice = 0;
		initAirportManger(&airportManger, &airport);
		initAirline(&airline);

	printf("\n---------------------------Main Menu-----------------------------------\n");
	while (choice != -1) {
		printf("\nOptions:\n1. Add flight to airline\n2. Add airport to manager\n3. Print airline data\n4. Print manager data\n5. Print flights between airports\n-1 exit");
		printf("\nYour Choice: ");
		if(!scanf("%d%*c", &choice));
		if (choice == 1) {
			insertFlight(&airline, &flight, &airportManger);
			
		}
		else if (choice == 2) {
			initAirport(&airport);
			InsertAirport(&airportManger, &airport);
		
		}
		else if (choice == 3) {
			printAirline(&airline);
			
		}
		else if (choice == 4) {
			printManager(&airportManger);
		}
		else if (choice == 5) {
			printCountFlightsLine(&airline, &airportManger);
		}
		else if (choice == -1) {
			freeAirportManger(&airportManger);
			freeAirline(&airline);
			printf("Thank You, Goodbye!\n");
			break;
		}
		else {
			printf("Invalid Option!\n");
		}
	}
}

