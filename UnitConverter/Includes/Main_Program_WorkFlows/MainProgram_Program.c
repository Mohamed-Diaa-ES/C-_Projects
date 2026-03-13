#include "MainProgram_interfaces.h"
#include <stdlib.h>
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
                clearScreen();
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
        uint8_t proceeding = 0;
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

                while (!proceeding)
                {

                        printf("Enter the Unit: ");
                        scanf("%hhd", &ToBeConverted->UnitType);
                        if (ToBeConverted->UnitType <= LengthUnitsNumbers && ToBeConverted->UnitType > 0)
                        {
                                proceeding = 1;
                        }
                        else
                        {
                                printf("Invalid Unit Insertion! Please, Re-Enter The Unit!\n");
                        }
                }

                break;
        case Mass:
                printf("\n1-g\n");
                printf("2-kg\n");
                printf("3-t\n");
                printf("4-oz\n");
                printf("5-lb\n");
                printf("6-st\n");

                while (!proceeding)
                {

                        printf("Enter the Unit: ");
                        scanf("%hhd", &ToBeConverted->UnitType);
                        if (ToBeConverted->UnitType <= MassUnitsNumbers && ToBeConverted->UnitType > 0)
                        {
                                proceeding = 1;
                        }
                        else
                        {
                                printf("Invalid Unit Insertion! Please, Re-Enter The Unit!\n");
                        }
                }
                break;
        case Volume:
                printf("\n1-mL\n");
                printf("2-L\n");
                printf("3-m^3\n");
                printf("4-gal\n");

                while (!proceeding)
                {

                        printf("Enter the Unit: ");
                        scanf("%hhd", &ToBeConverted->UnitType);
                        if (ToBeConverted->UnitType <= VolumeUnitsNumbers && ToBeConverted->UnitType > 0)
                        {
                                proceeding = 1;
                        }
                        else
                        {
                                printf("Invalid Unit Insertion! Please, Re-Enter The Unit!\n");
                        }
                }
                break;
        case Time:
                printf("\n1-ms\n");
                printf("2-s\n");
                printf("3-min\n");
                printf("4-h\n");
                printf("5-d\n");
                printf("6-wk\n");

                while (!proceeding)
                {

                        printf("Enter the Unit: ");
                        scanf("%hhd", &ToBeConverted->UnitType);
                        if (ToBeConverted->UnitType <= TimeUnitsNumbers && ToBeConverted->UnitType > 0)
                        {
                                proceeding = 1;
                        }
                        else
                        {
                                printf("Invalid Unit Insertion! Please, Re-Enter The Unit!\n");
                        }
                }
                break;
        case Digital_Storage:
                printf("\n1-b(bit)\n");
                printf("2-B(Byte)\n");
                printf("3-kB\n");
                printf("4-MB\n");
                printf("5-GB\n");
                printf("6-TB\n");

                while (!proceeding)
                {

                        printf("Enter the Unit: ");
                        scanf("%hhd", &ToBeConverted->UnitType);
                        if (ToBeConverted->UnitType <= Digital_StoragUnitsNumbers && ToBeConverted->UnitType > 0)
                        {
                                proceeding = 1;
                        }
                        else
                        {
                                printf("Invalid Unit Insertion! Please, Re-Enter The Unit!\n");
                        }
                }
                break;
        case Speed:
                printf("\n1-m/s\n");
                printf("2-km/h\n");
                printf("3-mph\n");

                while (!proceeding)
                {

                        printf("Enter the Unit: ");
                        scanf("%hhd", &ToBeConverted->UnitType);
                        if (ToBeConverted->UnitType <= SpeedUnitsNumbers && ToBeConverted->UnitType > 0)
                        {
                                proceeding = 1;
                        }
                        else
                        {
                                printf("Invalid Unit Insertion! Please, Re-Enter The Unit!\n");
                        }
                }
                break;
        case Temprature:
                printf("\n1-F\n");
                printf("2-C\n");
                printf("3-K\n");

                while (!proceeding)
                {

                        printf("Enter the Unit: ");
                        scanf("%hhd", &ToBeConverted->UnitType);
                        if (ToBeConverted->UnitType <= TempratureUnitsNumbers && ToBeConverted->UnitType > 0)
                        {
                                proceeding = 1;
                        }
                        else
                        {
                                printf("Invalid Unit Insertion! Please, Re-Enter The Unit!\n");
                        }
                }

                break;

        default:
                printf("Invalid Input Repeat Choice Please\n");
                return 0; // false input
                break;
        }

        ToBeConverted->UnitType--;

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
        }
}

void ExitProgram()
{
        printf("Have A Nice Day!");
}

void LengthCoversion(Unit *ToBeConverted) // takes each value and convert it to other unit
{
        Unit SpecificationUnit = *ToBeConverted;
        uint8_t proceeding = 0;
        while (!proceeding)
        {
                printf("Choose The unit you want to convert to: ");
                proceeding = ChooseUnitConverted(&SpecificationUnit);
        }
        switch (SpecificationUnit.UnitType)
        {
        case CM:
                SpecificationUnit = *ToBeConverted;
                ToCM(&SpecificationUnit);

                break;
        case Meters:
                SpecificationUnit = *ToBeConverted;
                ToMeters(&SpecificationUnit);

                break;
        case KiloMeters:
                SpecificationUnit = *ToBeConverted;
                ToKiloMeters(&SpecificationUnit);

                break;
        case Miles:
                SpecificationUnit = *ToBeConverted;
                ToMiles(&SpecificationUnit);

                break;
        case Inches:
                SpecificationUnit = *ToBeConverted;
                ToInches(&SpecificationUnit);

                break;
        case Foot:
                SpecificationUnit = *ToBeConverted;
                ToFoot(&SpecificationUnit);

                break;
        case Yard:
                SpecificationUnit = *ToBeConverted;
                ToYard(&SpecificationUnit);

                break;

        default:
                break;
        }
        Print_Unit(ToBeConverted);
        Print_Unit(&SpecificationUnit);
}
void MassCoversion(Unit *ToBeConverted)
{
        Unit SpecificationUnit = *ToBeConverted;
        uint8_t proceeding = 0;
        while (!proceeding)
        {
                printf("Choose The unit you want to convert to: ");
                proceeding = ChooseUnitConverted(&SpecificationUnit);
        }
        switch (SpecificationUnit.UnitType)
        {
        case Grams:
                SpecificationUnit = *ToBeConverted;
                ToGrams(&SpecificationUnit);

                break;
        case KiloGrams:
                SpecificationUnit = *ToBeConverted;
                ToKiloGrams(&SpecificationUnit);

                break;
        case Tons:
                SpecificationUnit = *ToBeConverted;
                ToTons(&SpecificationUnit);

                break;
        case Ounces:
                SpecificationUnit = *ToBeConverted;
                ToOunces(&SpecificationUnit);

                break;
        case Pound:
                SpecificationUnit = *ToBeConverted;
                ToPound(&SpecificationUnit);

                break;
        case Stone:
                SpecificationUnit = *ToBeConverted;
                ToStone(&SpecificationUnit);

                break;

        default:
                break;
        }
        Print_Unit(ToBeConverted);
        Print_Unit(&SpecificationUnit);
}
void VolumeCoversion(Unit *ToBeConverted)
{
        Unit SpecificationUnit = *ToBeConverted;
        uint8_t proceeding = 0;
        while (!proceeding)
        {
                printf("Choose The unit you want to convert to: ");
                proceeding = ChooseUnitConverted(&SpecificationUnit);
        }
        switch (SpecificationUnit.UnitType)
        {
        case MilliLiter:
                SpecificationUnit = *ToBeConverted;
                ToMilliLiter(&SpecificationUnit);

                break;
        case Liter:
                SpecificationUnit = *ToBeConverted;
                ToLiter(&SpecificationUnit);

                break;
        case CubicMeter:
                SpecificationUnit = *ToBeConverted;
                ToCubicMeter(&SpecificationUnit);

                break;
        case Gallon:
                SpecificationUnit = *ToBeConverted;
                ToGallon(&SpecificationUnit);

                break;

        default:
                break;
        }
        Print_Unit(ToBeConverted);
        Print_Unit(&SpecificationUnit);
}
void TimeCoversion(Unit *ToBeConverted)
{
        Unit SpecificationUnit = *ToBeConverted;
        uint8_t proceeding = 0;
        while (!proceeding)
        {
                printf("Choose The unit you want to convert to: ");
                proceeding = ChooseUnitConverted(&SpecificationUnit);
        }
        switch (SpecificationUnit.UnitType)
        {
        case Millisecond:
                SpecificationUnit = *ToBeConverted;
                ToMillisecond(&SpecificationUnit);

                break;
        case Second:
                SpecificationUnit = *ToBeConverted;
                ToSecond(&SpecificationUnit);

                break;
        case Minute:
                SpecificationUnit = *ToBeConverted;
                ToMinute(&SpecificationUnit);

                break;
        case Hour:
                SpecificationUnit = *ToBeConverted;
                ToHour(&SpecificationUnit);

                break;
        case Day:
                SpecificationUnit = *ToBeConverted;
                ToDay(&SpecificationUnit);

                break;
        case Week:
                SpecificationUnit = *ToBeConverted;
                ToWeek(&SpecificationUnit);

                break;

        default:
                break;
        }

        Print_Unit(ToBeConverted);
        Print_Unit(&SpecificationUnit);
}
void Digital_StorageCoversion(Unit *ToBeConverted)
{
        Unit SpecificationUnit = *ToBeConverted;
        uint8_t proceeding = 0;
        while (!proceeding)
        {
                printf("Choose The unit you want to convert to: ");
                proceeding = ChooseUnitConverted(&SpecificationUnit);
        }
        switch (SpecificationUnit.UnitType)
        {
        case Bit:
                SpecificationUnit = *ToBeConverted;
                ToBit(&SpecificationUnit);
                break;
        case Byte:
                SpecificationUnit = *ToBeConverted;
                ToByte(&SpecificationUnit);
                break;
        case Kilobyte:
                SpecificationUnit = *ToBeConverted;
                ToKilobyte(&SpecificationUnit);
                break;
        case Megabyte:
                SpecificationUnit = *ToBeConverted;
                ToMegabyte(&SpecificationUnit);
                break;
        case Gigabyte:
                SpecificationUnit = *ToBeConverted;
                ToGigabyte(&SpecificationUnit);
                break;
        case Terabyte:
                SpecificationUnit = *ToBeConverted;
                ToTerabyte(&SpecificationUnit);
                break;

        default:
                break;
        }
        Print_Unit(ToBeConverted);
        Print_Unit(&SpecificationUnit);
}
void SpeedCoversion(Unit *ToBeConverted)
{
        Unit SpecificationUnit = *ToBeConverted;
        uint8_t proceeding = 0;
        while (!proceeding)
        {
                printf("Choose The unit you want to convert to: ");
                proceeding = ChooseUnitConverted(&SpecificationUnit);
        }
        switch (SpecificationUnit.UnitType)
        {
        case MeterPerSec:
                SpecificationUnit = *ToBeConverted;
                ToMeterPerSec(&SpecificationUnit);
                break;
        case KMPerHr:
                SpecificationUnit = *ToBeConverted;
                ToKMPerHr(&SpecificationUnit);
                break;
        case Milesperhour:
                SpecificationUnit = *ToBeConverted;
                ToMilesperhour(&SpecificationUnit);
                break;
        default:
                break;
        }
        Print_Unit(ToBeConverted);
        Print_Unit(&SpecificationUnit);
}
void TempratureCoversion(Unit *ToBeConverted)
{
        Unit SpecificationUnit = *ToBeConverted;
        uint8_t proceeding = 0;
        Print_Unit(ToBeConverted);
        while (!proceeding)
        {
                printf("Choose The unit you want to convert to: ");
                proceeding = ChooseUnitConverted(&SpecificationUnit);
        }
        switch (SpecificationUnit.UnitType)
        {
        case Fahrenheit:
                SpecificationUnit = *ToBeConverted;

                ToFahrenheit(&SpecificationUnit);

                SpecificationUnit.UnitType = Fahrenheit;
                break;
        case Kelvin:
                SpecificationUnit = *ToBeConverted;

                ToKelvin(&SpecificationUnit);

                SpecificationUnit.UnitType = Kelvin;

                break;
        case Celsius:
                SpecificationUnit = *ToBeConverted;

                ToCelsius(&SpecificationUnit);

                SpecificationUnit.UnitType = Celsius;

        default:
                break;
        }

        Print_Unit(ToBeConverted);
        Print_Unit(&SpecificationUnit);
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