#include "MainProgram_interfaces.h"
/**
 * @fn    ChooseUnitConverted
 * @brief HelperFunction to the Function @fn TakingInputFromUser
 */
void ChooseUnitConverted(Unit *ToBeConverted)
{
        switch (ToBeConverted->MeasuredType)
        {
        case Length:
                printf("1-cm\n");
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
                break;
        }
}

void WelcomingAndQuantityAsking(uint8_t *Choice)
{
        if (Choice == 0)
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
        scanf("%hhd", &Choice);
}

void TakingInputFromUser(Unit *ToBeConverted)
{
        printf("Enter The Value: ");
        scanf("%lf", &ToBeConverted->Value);
        printf("Enter The Unit: \n");

        scanf("%lf", &ToBeConverted->UnitType);
}
