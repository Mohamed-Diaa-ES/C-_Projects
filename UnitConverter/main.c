#include "Includes/Macros.h"
#include "Includes/Main_Program_WorkFlows/MainProgram_interfaces.h"
#include "Includes/UnitConvertionImplementation/UnitConverter_Interface.h"
#include "Includes/Macros.h"
#include <stdio.h>
#include <stdlib.h>
void clearScreen();

int main()
{
    Unit ToBeConverted;
    uint8_t choice = 0;
    while (1)
    {
        WelcomingAndQuantityAsking(&choice);
        // as the value of macros is defined to be less than choosen always by one like length is choosed at 1 but it is defined as 0
        if ((choice - 1) == Exit) // exit the program noramlly
        {
            clearScreen();
            ExitProgram();
            return 0;
        }
        //  as the value of macros is defined to be less than choosen always by one like length is choosed at 1 but it is defined as 0
        ToBeConverted.MeasuredType = choice - 1;
        switch (ToBeConverted.MeasuredType)
        {
        case Length:

            TakingInputFromUser(&ToBeConverted);
            // LengthCoversion(&ToBeConverted);
            break;
        case Mass:
            TakingInputFromUser(&ToBeConverted);
            // MassCoversion(&ToBeConverted);
            break;
        case Volume:
            TakingInputFromUser(&ToBeConverted);
            // VolumeCoversion(&ToBeConverted);
            break;
        case Time:
            TakingInputFromUser(&ToBeConverted);
            // TimeCoversion(&ToBeConverted);
            break;
        case Digital_Storage:
            TakingInputFromUser(&ToBeConverted);
            // Digital_StorageCoversion(&ToBeConverted);
            break;
        case Speed:
            TakingInputFromUser(&ToBeConverted);
            // SpeedCoversion(&ToBeConverted);
            break;
        case Temprature:
            TakingInputFromUser(&ToBeConverted);
            TempratureCoversion(&ToBeConverted);
            break;
        default:
            clearScreen();
            printf("Invalid Choice!! Try again ,please. \n");
            break;
        }
    }
}
void clearScreen()
{
    {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
    }
}