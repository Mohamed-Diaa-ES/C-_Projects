#include "MainProgram_interfaces.h"
#include <stdio.h>
/**
 * @fn    ChooseUnitConverted
 * @brief HelperFunction to the Function @fn TakingInputFromUser
 */
uint8_t ChooseUnitConverted(Unit *ToBeConverted)
{

        switch (ToBeConverted->MeasuredType)
        {
        case Length:
                printf("\n1-cm\n");
                printf("2-m\n");
                printf("3-km\n");
                printf("4-mi\n");
                printf("5-in\n");
                printf("6-F\n");
                printf("7-yd\n");
                break;
        case Mass:
                printf("1-g\n");
                printf("2-kg\n");
                printf("3-t\n");
                printf("4-oz\n");
                printf("5-lb\n");
                printf("6-st\n");
                break;
        case Volume:
                printf("1-mL\n");
                printf("2-L\n");
                printf("3-m^3\n");
                printf("4-gal\n");

                break;
        case Time:
                printf("1-ms\n");
                printf("2-s\n");
                printf("3-min\n");
                printf("4-h\n");
                printf("5-d\n");
                printf("6-wk\n");

                break;
        case Digital_Storage:
                printf("1-b(bit)\n");
                printf("2-B(Byte)\n");
                printf("3-kB\n");
                printf("4-MB\n");
                printf("5-GB\n");
                printf("6-TB\n");

                break;
        case Speed:
                printf("1-m/s\n");
                printf("2-km/h\n");
                printf("3-mph\n");

                break;
        case Temprature:
                printf("1-F\n");
                printf("2-C\n");
                printf("3-K\n");

                break;

        default:
                printf("Invalid Input Repeat Choice Please\n");
                return 0; // false input
                break;
        }
        printf("Enter the Unit: ");
        scanf("%hhd", &ToBeConverted->UnitType);
        return 1; // True Action
}

void WelcomingAndQuantityAsking(uint8_t *Choice)
{
        if (*Choice == 0)
        {
                printf("Welcome To Your UnitConverter CLI App: ");
                printf("\nEnter The Quantity you want to measure");
        }
        else
        {
                printf("\nEnter The Next Quantity you want to measure");
        }
        printf("\n1-Length ");
        printf("\n2-Mass");
        printf("\n3-Volume");
        printf("\n4-Time");
        printf("\n5-Digital_Storage");
        printf("\n6-Speed");
        printf("\n7-Temprature");
        printf("\n8-Exit.");
        printf("\nEnter Your Choice: ");
        scanf("%hhd", Choice);
}

void TakingInputFromUser(Unit *ToBeConverted)
{
        printf("Enter The Value: ");
        scanf("%lf", &ToBeConverted->Value);
        uint8_t proceeding = 0;
        while (!proceeding)
        {
                printf("Choose The Unit From The List: ");
                proceeding = ChooseUnitConverted(ToBeConverted);
                //  as the value of macros is defined to be less than choosen always by one like length is choosed at 1 but it is defined as 0
                ToBeConverted->UnitType -= 1;
        }
}

void ExitProgram()
{
        printf("Have A Nice Day!");
}

void LengthCoversion(Unit *ToBeConverted)//takes each value and convert it to other unit
{
        Unit SpecificationUnit;
        uint8_t proceeding = 0;
        while (!proceeding)
        {
                printf("Choose The unit you want to convert to: ");
                proceeding = ChooseUnitConverted(&SpecificationUnit);
        }
        switch (SpecificationUnit)
        {
        case constant expression:
                /* code */
                break;
        
        default:
                break;
        }
        
    
}
void MassCoversion(Unit *ToBeConverted)
{
    
}
void VolumeCoversion(Unit *ToBeConverted)
{
    
}
void TimeCoversion(Unit *ToBeConverted)
{
    
}
void Digital_StorageCoversion(Unit *ToBeConverted)
{
    
}
void SpeedCoversion(Unit *ToBeConverted)
{
    
}
void TempratureCoversion(Unit *ToBeConverted)
{
    
}