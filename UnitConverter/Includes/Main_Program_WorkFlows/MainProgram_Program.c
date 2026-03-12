#include "MainProgram_interfaces.h"
#include <stdio.h>
/**
 * @defgroup    UnitsSymbols
 * @brief       This group has the arrays of strings to hold the symbols of the available Quntities to be used for printing.
 * @{ 
 */
/**
 * @brief This array holds all the symbols available for the Length Quantities to be used in printing for convienience.
 * @note  Ensure the Number of the symbols wanted to be shown is same as the  LengthUnitsNumbers Macro.
 */
const char *Length_Symbols[LengthUnitsNumbers] = {CM_Symb, Meters_Symb, KiloMeters_Symb, Miles_Symb, Inches_Symb, Foot_Symb, Yard_Symb};
/**
 * @brief This array holds all the symbols available for the Mass Quantities to be used in printing for convienience.
 * @note  Ensure the Number of the symbols wanted to be shown is same as the  MassUnitsNumbers Macro.
 */
const char *Mass_Symbols[MassUnitsNumbers] = {Grams_Symb, KiloGrams_Symb, Tons_Symb, Ounces_Symb, Pound_Symb, Stone_Symb};
/**
 * @brief This array holds all the symbols available for the Volume Quantities to be used in printing for convienience.
 * @note  Ensure the Number of the symbols wanted to be shown is same as the  VolumeUnitsNumbers Macro.
 */
const char *Volume_Symbols[VolumeUnitsNumbers] = {MilliLiter_Symb, Liter_Symb, CubicMeter_Symb, Gallon_Symb};
/**
 * @brief This array holds all the symbols available for the Time Quantities to be used in printing for convienience.
 * @note  Ensure the Number of the symbols wanted to be shown is same as the  TimeUnitsNumbers Macro.
 */
const char *Time_Symbols[TimeUnitsNumbers] = {Millisecond_Symb, Second_Symb, Minute_Symb, Hour_Symb, Day_Symb, Week_Symb};
/**
 * @brief This array holds all the symbols available for the Digital_Storage Quantities to be used in printing for convienience.
 * @note  Ensure the Number of the symbols wanted to be shown is same as the  Digital_StorageUnitsNumbers Macro.
 */
const char *Digital_Storage_Symbols[Digital_StoragUnitsNumbers] = {Bit_Symb, Byte_Symb, Kilobyte_Symb, Megabyte_Symb, Gigabyte_Symb, Terabyte_Symb};
/**
 * @brief This array holds all the symbols available for the Speed Quantities to be used in printing for convienience.
 * @note  Ensure the Number of the symbols wanted to be shown is same as the  SpeedUnitsNumbers Macro.
 */
const char *Speed_Symbols[SpeedUnitsNumbers] = {MeterPerSec_Symb, KMPerHr_Symb, Milesperhour_Symb};
/**
 * @brief This array holds all the symbols available for the Temprature Quantities to be used in printing for convienience.
 * @note  Ensure the Number of the symbols wanted to be shown is same as the  TempratureUnitsNumbers Macro.
 */
const char *Temprature_Symbols[TempratureUnitsNumbers] = {Fahrenheit_Symb, Celsius_Symb, Kelvin_Symb};
/**
 * @brief This array holds all the available units numbers of different Quantities.
 * @note  Ensure the Number of the Macros wanted to be used as constraints is same as the  ConvertableQuantitesNumber Macro.
 */
const uint8_t Max_ValueForQuantitySymbol[ConvertableQuantitesNumber] = {LengthUnitsNumbers, MassUnitsNumbers, VolumeUnitsNumbers, TimeUnitsNumbers,
                                                                        Digital_StoragUnitsNumbers, SpeedUnitsNumbers, TempratureUnitsNumbers};
/**
 * @}
 */
void Print_Unit(Unit *ToBePrinted)
{
        switch (ToBePrinted->MeasuredType)
        {
        case Length:
                printf("Measured Quantity: Length, Value= %lf in ", ToBePrinted->Value);
                printf("%s\n", Length_Symbols[ToBePrinted->UnitType]);
                break;
        case Mass:
                printf("Measured Quantity: Mass, Value= %lf in ", ToBePrinted->Value);
                printf("%s\n", Mass_Symbols[ToBePrinted->UnitType]);
                break;
        case Volume:
                printf("Measured Quantity: Volume, Value= %lf in ", ToBePrinted->Value);
                printf("%s\n", Volume_Symbols[ToBePrinted->UnitType]);
                break;
        case Time:
                printf("Measured Quantity: Time, Value= %lf in ", ToBePrinted->Value);
                printf("%s\n", Time_Symbols[ToBePrinted->UnitType]);
                break;
        case Digital_Storage:
                printf("Measured Quantity: Digital_Storage, Value= %lf in ", ToBePrinted->Value);
                printf("%s\n", Digital_Storage_Symbols[ToBePrinted->UnitType]);
                break;
        case Speed:
                printf("Measured Quantity: Speed, Value= %lf in ", ToBePrinted->Value);
                printf("%s\n", Speed_Symbols[ToBePrinted->UnitType]);
                break;
        case Temprature:
                printf("Measured Quantity: Temprature, Value= %lf in ", ToBePrinted->Value);
                printf("%s\n", Temprature_Symbols[ToBePrinted->UnitType]);
                break;
        default:
                // clearScreen();
                printf("Invalid Type!! How did you even reach this far!!! \n");
                return;
                break;
        }
}

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