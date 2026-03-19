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
/**
 * @brief Evaluates the return status of a conversion and prints the appropriate feedback.
 * @param status_code The uint8_t code returned by the conversion functions.
 */
void Handle_Conversion_Status(uint8_t status_code)
{
        switch (status_code)
        {
        case Transformation_Done:
                break;

        case UnRegisteredUnitFortheMeasuredQuantity:
                printf("\n[ERROR] Unregistered Unit: The system does not support this conversion path.\n");
                break;

        case NullCrashing:
                printf("\n[FATAL SYSTEM ERROR] Null Pointer Dereference prevented in conversion module.\n");
                break;

        case Physical_Logic_Error:
                printf("\n[ERROR] Physical Logic Violation: The provided value breaks physical boundaries (e.g., negative length or below absolute zero).\n");
                break;

        case Quanitity_MissMatch:
                printf("\n[ERROR] Quantity Mismatch: Cannot convert between incompatible physical domains.\n");
                break;

        default:
                printf("\n[UNKNOWN ERROR] The conversion module returned an undefined status code: %d\n", status_code);
                break;
        }
}

uint8_t IsUnitTrue(Unit *ToBeConverted, uint8_t AvaialbleUnitsNumber)
{
        uint8_t proceeding = 0;
        while (!proceeding)
        {
                printf("Enter the Unit: ");
                uint8_t isvalidInput = scanf("%hhd", &ToBeConverted->UnitType);
                if (isvalidInput != 1)
                {
                        /* code */
                        handleScanfproblems(isvalidInput, OneInputToScanf); // 1 is just the number of the arguments to help input resolving
                        continue;
                }

                if (ToBeConverted->UnitType <= AvaialbleUnitsNumber && ToBeConverted->UnitType > 0)
                {
                        proceeding = 1;
                }
                else
                {

                        printf("Invalid Unit Insertion! Please, Re-Enter The Unit Number!\n");
                        proceeding = 0;
                }
        }
}

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

                proceeding = IsUnitTrue(ToBeConverted, LengthUnitsNumbers);

                break;
        case Mass:
                printf("\n1-g\n");
                printf("2-kg\n");
                printf("3-t\n");
                printf("4-oz\n");
                printf("5-lb\n");
                printf("6-st\n");

                proceeding = IsUnitTrue(ToBeConverted, MassUnitsNumbers);

                break;
        case Volume:
                printf("\n1-mL\n");
                printf("2-L\n");
                printf("3-m^3\n");
                printf("4-gal\n");

                proceeding = IsUnitTrue(ToBeConverted, VolumeUnitsNumbers);

                break;
        case Time:
                printf("\n1-ms\n");
                printf("2-s\n");
                printf("3-min\n");
                printf("4-h\n");
                printf("5-d\n");
                printf("6-wk\n");

                proceeding = IsUnitTrue(ToBeConverted, TimeUnitsNumbers);

                break;
        case Digital_Storage:
                printf("\n1-b(bit)\n");
                printf("2-B(Byte)\n");
                printf("3-kB\n");
                printf("4-MB\n");
                printf("5-GB\n");
                printf("6-TB\n");

                proceeding = IsUnitTrue(ToBeConverted, Digital_StoragUnitsNumbers);

                break;
        case Speed:
                printf("\n1-m/s\n");
                printf("2-km/h\n");
                printf("3-mph\n");

                proceeding = IsUnitTrue(ToBeConverted, SpeedUnitsNumbers);

                break;
        case Temprature:
                printf("\n1-F\n");
                printf("2-C\n");
                printf("3-K\n");

                proceeding = IsUnitTrue(ToBeConverted, TempratureUnitsNumbers);

                break;

        default:
                printf("Invalid Input Repeat Choice Please\n");
                return 0; // false input
                break;
        }

        ToBeConverted->UnitType--; // to match defined inputs

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
        while (1)
        {
                printf("\nEnter Your Choice: ");
                uint8_t isvalidInput = scanf("%hhd", Choice);
                clearScreen();
                if (isvalidInput != 1)
                {
                        handleScanfproblems(isvalidInput, OneInputToScanf); // 1 is just the number of the arguments to help input resolving
                }
                else
                {
                        return;
                }
        }
}

void TakingInputFromUser(Unit *ToBeConverted)
{
        printf("Enter The Value: ");
        while (1)
        {
                uint8_t isvalidInput = scanf("%lf", &ToBeConverted->Value);
                if (isvalidInput != 1)
                {
                        handleScanfproblems(isvalidInput, OneInputToScanf); // 1 is just the number of the arguments to help input resolving
                }
                else
                {

                        uint8_t proceeding = 0;
                        while (!proceeding)
                        {
                                printf("Choose The Unit From The List: ");
                                proceeding = ChooseUnitConverted(ToBeConverted);
                        }
                        return;
                }
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
        uint8_t status = 0;

        while (!proceeding)
        {
                clearScreen();
                printf("Choose The unit you want to convert to: ");
                proceeding = ChooseUnitConverted(&SpecificationUnit);
        }
        switch (SpecificationUnit.UnitType)
        {
        case CM:
                SpecificationUnit = *ToBeConverted;
                status = ToCM(&SpecificationUnit);

                break;
        case Meters:
                SpecificationUnit = *ToBeConverted;
                status = ToMeters(&SpecificationUnit);

                break;
        case KiloMeters:
                SpecificationUnit = *ToBeConverted;
                status = ToKiloMeters(&SpecificationUnit);

                break;
        case Miles:
                SpecificationUnit = *ToBeConverted;
                status = ToMiles(&SpecificationUnit);

                break;
        case Inches:
                SpecificationUnit = *ToBeConverted;
                status = ToInches(&SpecificationUnit);

                break;
        case Foot:
                SpecificationUnit = *ToBeConverted;
                status = ToFoot(&SpecificationUnit);

                break;
        case Yard:
                SpecificationUnit = *ToBeConverted;
                status = ToYard(&SpecificationUnit);

                break;

        default:
                break;
        }
        Handle_Conversion_Status(status);
        clearScreen();
        Print_Unit(ToBeConverted);
        Print_Unit(&SpecificationUnit);
}
void MassCoversion(Unit *ToBeConverted)
{
        Unit SpecificationUnit = *ToBeConverted;
        uint8_t proceeding = 0;
        uint8_t status = 0;

        while (!proceeding)
        {
                clearScreen();
                printf("Choose The unit you want to convert to: ");
                proceeding = ChooseUnitConverted(&SpecificationUnit);
        }
        switch (SpecificationUnit.UnitType)
        {
        case Grams:
                SpecificationUnit = *ToBeConverted;
                status = ToGrams(&SpecificationUnit);

                break;
        case KiloGrams:
                SpecificationUnit = *ToBeConverted;
                status = ToKiloGrams(&SpecificationUnit);

                break;
        case Tons:
                SpecificationUnit = *ToBeConverted;
                status = ToTons(&SpecificationUnit);

                break;
        case Ounces:
                SpecificationUnit = *ToBeConverted;
                status = ToOunces(&SpecificationUnit);

                break;
        case Pound:
                SpecificationUnit = *ToBeConverted;
                status = ToPound(&SpecificationUnit);

                break;
        case Stone:
                SpecificationUnit = *ToBeConverted;
                status = ToStone(&SpecificationUnit);

                break;

        default:
                break;
        }
        Handle_Conversion_Status(status);
        clearScreen();
        Print_Unit(ToBeConverted);
        Print_Unit(&SpecificationUnit);
}
void VolumeCoversion(Unit *ToBeConverted)
{
        Unit SpecificationUnit = *ToBeConverted;
        uint8_t proceeding = 0;
        uint8_t status = 0;

        while (!proceeding)
        {
                clearScreen();
                printf("Choose The unit you want to convert to: ");
                proceeding = ChooseUnitConverted(&SpecificationUnit);
        }
        switch (SpecificationUnit.UnitType)
        {
        case MilliLiter:
                SpecificationUnit = *ToBeConverted;
                status = ToMilliLiter(&SpecificationUnit);

                break;
        case Liter:
                SpecificationUnit = *ToBeConverted;
                status = ToLiter(&SpecificationUnit);

                break;
        case CubicMeter:
                SpecificationUnit = *ToBeConverted;
                status = ToCubicMeter(&SpecificationUnit);

                break;
        case Gallon:
                SpecificationUnit = *ToBeConverted;
                status = ToGallon(&SpecificationUnit);

                break;

        default:
                break;
        }
        Handle_Conversion_Status(status);
        clearScreen();
        Print_Unit(ToBeConverted);
        Print_Unit(&SpecificationUnit);
}
void TimeCoversion(Unit *ToBeConverted)
{
        Unit SpecificationUnit = *ToBeConverted;
        uint8_t proceeding = 0;
        uint8_t status = 0;

        while (!proceeding)
        {
                clearScreen();
                printf("Choose The unit you want to convert to: ");
                proceeding = ChooseUnitConverted(&SpecificationUnit);
        }
        switch (SpecificationUnit.UnitType)
        {
        case Millisecond:
                SpecificationUnit = *ToBeConverted;
                status = ToMillisecond(&SpecificationUnit);

                break;
        case Second:
                SpecificationUnit = *ToBeConverted;
                status = ToSecond(&SpecificationUnit);

                break;
        case Minute:
                SpecificationUnit = *ToBeConverted;
                status = ToMinute(&SpecificationUnit);

                break;
        case Hour:
                SpecificationUnit = *ToBeConverted;
                status = ToHour(&SpecificationUnit);

                break;
        case Day:
                SpecificationUnit = *ToBeConverted;
                status = ToDay(&SpecificationUnit);

                break;
        case Week:
                SpecificationUnit = *ToBeConverted;
                status = ToWeek(&SpecificationUnit);

                break;

        default:
                break;
        }
        Handle_Conversion_Status(status);
        clearScreen();
        Print_Unit(ToBeConverted);
        Print_Unit(&SpecificationUnit);
}
void Digital_StorageCoversion(Unit *ToBeConverted)
{
        Unit SpecificationUnit = *ToBeConverted;
        uint8_t proceeding = 0;
        uint8_t status = 0;

        while (!proceeding)
        {
                clearScreen();
                printf("Choose The unit you want to convert to: ");
                proceeding = ChooseUnitConverted(&SpecificationUnit);
        }
        switch (SpecificationUnit.UnitType)
        {
        case Bit:
                SpecificationUnit = *ToBeConverted;
                status = ToBit(&SpecificationUnit);
                break;
        case Byte:
                SpecificationUnit = *ToBeConverted;
                status = ToByte(&SpecificationUnit);
                break;
        case Kilobyte:
                SpecificationUnit = *ToBeConverted;
                status = ToKilobyte(&SpecificationUnit);
                break;
        case Megabyte:
                SpecificationUnit = *ToBeConverted;
                status = ToMegabyte(&SpecificationUnit);
                break;
        case Gigabyte:
                SpecificationUnit = *ToBeConverted;
                status = ToGigabyte(&SpecificationUnit);
                break;
        case Terabyte:
                SpecificationUnit = *ToBeConverted;
                status = ToTerabyte(&SpecificationUnit);
                break;

        default:
                break;
        }
        Handle_Conversion_Status(status);
        clearScreen();
        Print_Unit(ToBeConverted);
        Print_Unit(&SpecificationUnit);
}
void SpeedCoversion(Unit *ToBeConverted)
{
        Unit SpecificationUnit = *ToBeConverted;
        uint8_t proceeding = 0;
        uint8_t status = 0;

        while (!proceeding)
        {
                clearScreen();
                printf("Choose The unit you want to convert to: ");
                proceeding = ChooseUnitConverted(&SpecificationUnit);
        }
        switch (SpecificationUnit.UnitType)
        {
        case MeterPerSec:
                SpecificationUnit = *ToBeConverted;
                status = ToMeterPerSec(&SpecificationUnit);
                break;
        case KMPerHr:
                SpecificationUnit = *ToBeConverted;
                status = ToKMPerHr(&SpecificationUnit);
                break;
        case Milesperhour:
                SpecificationUnit = *ToBeConverted;
                status = ToMilesperhour(&SpecificationUnit);
                break;
        default:
                break;
        }
        Handle_Conversion_Status(status);
        clearScreen();
        Print_Unit(ToBeConverted);
        Print_Unit(&SpecificationUnit);
}
void TempratureCoversion(Unit *ToBeConverted)
{
        Unit SpecificationUnit = *ToBeConverted;
        uint8_t proceeding = 0;
        uint8_t status = 0;
        Print_Unit(ToBeConverted);
        while (!proceeding)
        {
                clearScreen();
                printf("Choose The unit you want to convert to: ");
                proceeding = ChooseUnitConverted(&SpecificationUnit);
        }
        switch (SpecificationUnit.UnitType)
        {
        case Fahrenheit:
                SpecificationUnit = *ToBeConverted;

                status = ToFahrenheit(&SpecificationUnit);

                break;
        case Kelvin:
                SpecificationUnit = *ToBeConverted;

                status = ToKelvin(&SpecificationUnit);

                break;
        case Celsius:
                SpecificationUnit = *ToBeConverted;

                status = ToCelsius(&SpecificationUnit);

        default:
                break;
        }
        Handle_Conversion_Status(status);
        clearScreen();
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

signed char IsUserProceeding()
{
        uint8_t ans = 0;
        while (1)
        {
                printf("\nEnter Your Choice:(Y,N) ");
                scanf(" %c", &ans);
                if (ans == 'n' || ans == 'N')
                {

                        return 'n';
                }
                else if (ans == 'y' || ans == 'Y')
                {

                        return 'y';
                }
                else
                {
                        printf("INVALID INPUT TRY AGAIN.");
                }
        }
}

void handleScanfproblems(uint8_t valid, uint8_t howManyInputs)
{
        if (valid == howManyInputs)
        {
                return;
        }
        else
        {
                int garbage;
                while (garbage = getchar() != '\n' && garbage != EOF)
                        ;
        }
        printf("\nThis is invalid Input please enter a number\n");
}