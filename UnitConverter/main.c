#include "Includes/Main_Program_WorkFlows/MainProgram_interfaces.h"
#include "Includes/UnitConvertionImplementation/UnitConverter_Interface.h"
#include "Includes/Macros.h"
#include <stdio.h>

int main()
{
    Unit ToBeConverted;
    uint8_t choice = 0;
    while (1)
    {
        WelcomingAndQuantityAsking(&choice);
        TakingInputFromUser(&ToBeConverted);

        switch (choice)
        {
        case Length:

            LengthCoversion(&ToBeConverted);
            break;
        case Mass:
            MassCoversion(&ToBeConverted);
            break;
        case Volume:
            VolumeCoversion(&ToBeConverted);
            break;
        case Time:
            TimeCoversion(&ToBeConverted);
            break;
        case Digital_Storage:
            Digital_StorageCoversion(&ToBeConverted);
            break;
        case Speed:
            SpeedCoversion(&ToBeConverted);
            break;
        case Temprature:
            TempratureCoversion(&ToBeConverted);
            break;
        case Exit:
            ExitProgram();
            break;

        default:
            break;
        }
    }
}