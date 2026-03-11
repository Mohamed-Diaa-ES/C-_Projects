#include "MainProgram_interfaces.h"

void WelcomingAndQuantityAsking(uint8_t *Choice)
{
        printf("Welcome To Your UnitConverter CLI App: ");
        printf("\nEnter The Quantity you want to measure");
        printf("\n1-Length ");
        printf("\n2-Mass");
        printf("\n3-Volume");
        printf("\n4-Time");
        printf("\n5-Digital_Storage");
        printf("\n6-Speed");
        printf("\n7-Temprature");
        printf("\n8-Exit.");
        printf("\nEnter Your Choice: ");
        scanf("%hhd", &Choice);
}

void TakingInputFromUser(Unit *ToBeConverted)
{
        printf("Enter The Value: ");
        scanf("%lf", &ToBeConverted->Value);
}
