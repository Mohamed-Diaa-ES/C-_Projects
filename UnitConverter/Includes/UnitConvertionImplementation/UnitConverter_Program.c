#include "../Macros.h"
#include "UnitConverter_Interface.h"

/**
 * @brief Trnsform the length Value unit to the Meters Unit
 */
uint8_t ToMeters(Unit *ToBeTransformed)
{
    if (ToBeTransformed == NULL)
    {
        return NullCrashing;
    }
    if (ToBeTransformed->Value < 0)
    {
        return Physical_Logic_Error;
    }
    /**
     * @brief prevent transforming Other measured Quanities.
     * @todo  Add a error handling technique (probalbly will be Error Codes).
     */
    if (ToBeTransformed->MeasuredType != Length)
    {
        return Quanitity_MissMatch;
    }
    /**
     * @details This switch case choose the From-To Conversion to convert to Meters.
     *          This Assure me that I do not make relative Conversion to each unit like: CM to KilliMeters
     *          As I transform to Meters I can transform to other from Meter
     *          only by dividing by the Meter to (other unit) Conversion Macro.
     *          This makes the Function Reusable by other units reducing the Function
     */
    switch (ToBeTransformed->UnitType)
    {
    case Meters:
        ToBeTransformed->Value *= Meters_To_Meters;
        break;
    case CM:
        ToBeTransformed->Value *= CM_To_Meters;
        break;
    case KiloMeters:
        ToBeTransformed->Value *= KiloMeters_To_Meters;
        break;
    case Miles:
        ToBeTransformed->Value *= Miles_To_Meters;

        break;
    case Inches:

        ToBeTransformed->Value *= Inches_To_Meters;
        break;
    case Foot:
        ToBeTransformed->Value *= Foot_To_Meters;

        break;
    case Yard:
        ToBeTransformed->Value *= Yard_To_Meters;

        break;

    default:
        return UnRegisteredUnitFortheMeasuredQuantity;
        break;
    }
    ToBeTransformed->UnitType = Meters; // Change the Unit type.
    ToBeTransformed->Value /= Meters_To_Meters;
    return Transformation_Done;
}
/**
 * @brief Trnsform the length Value unit to the Meters Unit
 */
uint8_t ToMiles(Unit *ToBeTransformed)
{
    if (ToBeTransformed == NULL)
    {
        return NullCrashing;
    }
    if (ToBeTransformed->Value < 0)
    {
        return Physical_Logic_Error;
    }
    /**
     * @brief prevent transforming Other measured Quanities.
     * @todo  Add a error handling technique (probalbly will be Error Codes).
     */
    if (ToBeTransformed->MeasuredType != Length)
    {
        return Quanitity_MissMatch;
    }

    ToMeters(ToBeTransformed);         // Transform to Meters.
    ToBeTransformed->UnitType = Miles; // Change The unit type to be in Miles
    ToBeTransformed->Value /= Miles_To_Meters;
    return Transformation_Done;
}

uint8_t ToCM(Unit *ToBeTransformed)
{
    if (ToBeTransformed == NULL)
    {
        return NullCrashing;
    }
    if (ToBeTransformed->Value < 0)
    {
        return Physical_Logic_Error;
    }
    /**
     * @brief prevent transforming Other measured Quanities.
     * @todo  Add a error handling technique (probalbly will be Error Codes).
     */
    if (ToBeTransformed->MeasuredType != Length)
    {
        return Quanitity_MissMatch;
    }
    ToMeters(ToBeTransformed);      // Transform to Meters.
    ToBeTransformed->UnitType = CM; // Change The unit type to be in CM
    ToBeTransformed->Value /= CM_To_Meters;
    return Transformation_Done;
}
uint8_t ToKiloMeters(Unit *ToBeTransformed)
{
    if (ToBeTransformed == NULL)
    {
        return NullCrashing;
    }
    if (ToBeTransformed->Value < 0)
    {
        return Physical_Logic_Error;
    }
    /**
     * @brief prevent transforming Other measured Quanities.
     * @todo  Add a error handling technique (probalbly will be Error Codes).
     */
    if (ToBeTransformed->MeasuredType != Length)
    {
        return Quanitity_MissMatch;
    }
    ToMeters(ToBeTransformed);
    ToBeTransformed->UnitType = KiloMeters;
    ToBeTransformed->Value /= KiloMeters_To_Meters;
    return Transformation_Done;
}

uint8_t ToInches(Unit *ToBeTransformed)
{
    if (ToBeTransformed == NULL)
    {
        return NullCrashing;
    }
    if (ToBeTransformed->Value < 0)
    {
        return Physical_Logic_Error;
    }
    /**
     * @brief prevent transforming Other measured Quanities.
     * @todo  Add a error handling technique (probalbly will be Error Codes).
     */
    if (ToBeTransformed->MeasuredType != Length)
    {
        return Quanitity_MissMatch;
    }
    ToMeters(ToBeTransformed);
    ToBeTransformed->UnitType = Inches;
    ToBeTransformed->Value /= Inches_To_Meters;
    return Transformation_Done;
}
uint8_t ToFoot(Unit *ToBeTransformed)
{
    if (ToBeTransformed == NULL)
    {
        return NullCrashing;
    }
    if (ToBeTransformed->Value < 0)
    {
        return Physical_Logic_Error;
    }
    /**
     * @brief prevent transforming Other measured Quanities.
     * @todo  Add a error handling technique (probalbly will be Error Codes).
     */
    if (ToBeTransformed->MeasuredType != Length)
    {
        return Quanitity_MissMatch;
    }
    ToMeters(ToBeTransformed);
    ToBeTransformed->UnitType = Foot;
    ToBeTransformed->Value /= Foot_To_Meters;
    return Transformation_Done;
}
uint8_t ToYard(Unit *ToBeTransformed)
{
    if (ToBeTransformed == NULL)
    {
        return NullCrashing;
    }
    if (ToBeTransformed->Value < 0)
    {
        return Physical_Logic_Error;
    }
    /**
     * @brief prevent transforming Other measured Quanities.
     * @todo  Add a error handling technique (probalbly will be Error Codes).
     */
    if (ToBeTransformed->MeasuredType != Length)
    {
        return Quanitity_MissMatch;
    }
    ToMeters(ToBeTransformed);
    ToBeTransformed->UnitType = Yard;
    ToBeTransformed->Value /= Yard_To_Meters;
    return Transformation_Done;
}
uint8_t ToKiloGrams(Unit *ToBeTransformed)
{
    if (ToBeTransformed == NULL)
    {
        return NullCrashing;
    }
    if (ToBeTransformed->Value < 0)
    {
        return Physical_Logic_Error;
    }
    if (ToBeTransformed->Value < 0)
    {
        return Physical_Logic_Error;
    }
    /**
     * @brief prevent transforming Other measured Quanities.
     * @todo  Add a error handling technique (probalbly will be Error Codes).
     */
    if (ToBeTransformed->MeasuredType != Mass)
    {
        return Quanitity_MissMatch;
    }
    switch (ToBeTransformed->UnitType)
    {
    case KiloGrams:
        ToBeTransformed->Value *= KiloGrams_To_KiloGrams;
        break;
    case Grams:
        ToBeTransformed->Value *= Grams_To_KiloGrams;
        break;
    case Tons:
        ToBeTransformed->Value *= Tons_To_KiloGrams;
        break;
    case Ounces:
        ToBeTransformed->Value *= Ounces_To_KiloGrams;

        break;
    case Pound:

        ToBeTransformed->Value *= Pound_To_KiloGrams;
        break;
    case Stone:
        ToBeTransformed->Value *= Stone_To_KiloGrams;

        break;
    default:
        return UnRegisteredUnitFortheMeasuredQuantity;
        break;
    }
    ToBeTransformed->UnitType = KiloGrams;
    ToBeTransformed->Value /= KiloGrams_To_KiloGrams;
    return Transformation_Done;
}

uint8_t ToGrams(Unit *ToBeTransformed)
{
    if (ToBeTransformed == NULL)
    {
        return NullCrashing;
    }
    if (ToBeTransformed->Value < 0)
    {
        return Physical_Logic_Error;
    }
    if (ToBeTransformed->MeasuredType != Mass)
    {
        return Quanitity_MissMatch;
    }
    ToKiloGrams(ToBeTransformed);
    ToBeTransformed->UnitType = Grams;
    ToBeTransformed->Value /= Grams_To_KiloGrams;
    return Transformation_Done;
}

uint8_t ToTons(Unit *ToBeTransformed)
{
    if (ToBeTransformed == NULL)
    {
        return NullCrashing;
    }
    if (ToBeTransformed->Value < 0)
    {
        return Physical_Logic_Error;
    }
    if (ToBeTransformed->MeasuredType != Mass)
    {
        return Quanitity_MissMatch;
    }
    ToKiloGrams(ToBeTransformed);
    ToBeTransformed->UnitType = Tons;
    ToBeTransformed->Value /= Tons_To_KiloGrams;
    return Transformation_Done;
}

uint8_t ToOunces(Unit *ToBeTransformed)
{
    if (ToBeTransformed == NULL)
    {
        return NullCrashing;
    }
    if (ToBeTransformed->Value < 0)
    {
        return Physical_Logic_Error;
    }
    if (ToBeTransformed->MeasuredType != Mass)
    {
        return Quanitity_MissMatch;
    }
    ToKiloGrams(ToBeTransformed);
    ToBeTransformed->UnitType = Ounces;
    ToBeTransformed->Value /= Ounces_To_KiloGrams;
    return Transformation_Done;
}

uint8_t ToPound(Unit *ToBeTransformed)
{
    if (ToBeTransformed == NULL)
    {
        return NullCrashing;
    }
    if (ToBeTransformed->Value < 0)
    {
        return Physical_Logic_Error;
    }
    if (ToBeTransformed->MeasuredType != Mass)
    {
        return Quanitity_MissMatch;
    }
    ToKiloGrams(ToBeTransformed);
    ToBeTransformed->UnitType = Pound;
    ToBeTransformed->Value /= Pound_To_KiloGrams;
    return Transformation_Done;
}

uint8_t ToStone(Unit *ToBeTransformed)
{
    if (ToBeTransformed == NULL)
    {
        return NullCrashing;
    }
    if (ToBeTransformed->Value < 0)
    {
        return Physical_Logic_Error;
    }
    if (ToBeTransformed->MeasuredType != Mass)
    {
        return Quanitity_MissMatch;
    }
    ToKiloGrams(ToBeTransformed);
    ToBeTransformed->UnitType = Stone;
    ToBeTransformed->Value /= Stone_To_KiloGrams;
    return Transformation_Done;
}

uint8_t ToLiter(Unit *ToBeTransformed)
{
    if (ToBeTransformed == NULL)
    {
        return NullCrashing;
    }
    if (ToBeTransformed->Value < 0)
    {
        return Physical_Logic_Error;
    }
    if (ToBeTransformed->Value < 0)
    {
        return Physical_Logic_Error;
    }
    if (ToBeTransformed->MeasuredType != Volume)
    {
        return Quanitity_MissMatch;
    }
    switch (ToBeTransformed->UnitType)
    {
    case Liter:
        ToBeTransformed->Value *= Liter_To_Liter;
        break;
    case MilliLiter:
        ToBeTransformed->Value *= MilliLiter_To_Liter;
        break;
    case CubicMeter:
        ToBeTransformed->Value *= CubicMeter_To_Liter;
        break;
    case Gallon:
        ToBeTransformed->Value *= Gallon_To_Liter;
        break;
    default:
        return UnRegisteredUnitFortheMeasuredQuantity;
        break;
    }
    ToBeTransformed->UnitType = Liter;
    ToBeTransformed->Value /= Liter_To_Liter;
    return Transformation_Done;
}

uint8_t ToMilliLiter(Unit *ToBeTransformed)
{
    if (ToBeTransformed == NULL)
    {
        return NullCrashing;
    }
    if (ToBeTransformed->Value < 0)
    {
        return Physical_Logic_Error;
    }
    if (ToBeTransformed->MeasuredType != Volume)
    {
        return Quanitity_MissMatch;
    }
    ToLiter(ToBeTransformed);
    ToBeTransformed->UnitType = MilliLiter;
    ToBeTransformed->Value /= MilliLiter_To_Liter;
    return Transformation_Done;
}

uint8_t ToCubicMeter(Unit *ToBeTransformed)
{
    if (ToBeTransformed == NULL)
    {
        return NullCrashing;
    }
    if (ToBeTransformed->Value < 0)
    {
        return Physical_Logic_Error;
    }
    if (ToBeTransformed->MeasuredType != Volume)
    {
        return Quanitity_MissMatch;
    }
    ToLiter(ToBeTransformed);
    ToBeTransformed->UnitType = CubicMeter;
    ToBeTransformed->Value /= CubicMeter_To_Liter;
    return Transformation_Done;
}

uint8_t ToGallon(Unit *ToBeTransformed)
{
    if (ToBeTransformed == NULL)
    {
        return NullCrashing;
    }
    if (ToBeTransformed->Value < 0)
    {
        return Physical_Logic_Error;
    }
    if (ToBeTransformed->MeasuredType != Volume)
    {
        return Quanitity_MissMatch;
    }
    ToLiter(ToBeTransformed);
    ToBeTransformed->UnitType = Gallon;
    ToBeTransformed->Value /= Gallon_To_Liter;
    return Transformation_Done;
}

uint8_t ToMillisecond(Unit *ToBeTransformed)
{
    if (ToBeTransformed == NULL)
    {
        return NullCrashing;
    }
    if (ToBeTransformed->Value < 0)
    {
        return Physical_Logic_Error;
    }
    if (ToBeTransformed->MeasuredType != Time)
    {
        return Quanitity_MissMatch;
    }
    ToSecond(ToBeTransformed);
    ToBeTransformed->UnitType = Millisecond;
    ToBeTransformed->Value /= MilliSecond_To_Second;
    return Transformation_Done;
}

uint8_t ToSecond(Unit *ToBeTransformed)
{
    if (ToBeTransformed == NULL)
    {
        return NullCrashing;
    }
    if (ToBeTransformed->Value < 0)
    {
        return Physical_Logic_Error;
    }
    if (ToBeTransformed->MeasuredType != Time)
    {
        return Quanitity_MissMatch;
    }
    switch (ToBeTransformed->UnitType)
    {
    case Second:
        ToBeTransformed->Value *= Second_To_Second;
        break;
    case Millisecond:
        ToBeTransformed->Value *= MilliSecond_To_Second;
        break;
    case Minute:
        ToBeTransformed->Value *= Minute_To_Second;
        break;
    case Hour:
        ToBeTransformed->Value *= Hour_To_Second;
        break;
    case Day:
        ToBeTransformed->Value *= Day_To_Second;
        break;
    case Week:
        ToBeTransformed->Value *= Week_To_Second;
        break;
    default:
        return UnRegisteredUnitFortheMeasuredQuantity;
        break;
    }
    ToBeTransformed->UnitType = Second;
    ToBeTransformed->Value /= Second_To_Second;
    return Transformation_Done;
}

uint8_t ToMinute(Unit *ToBeTransformed)
{
    if (ToBeTransformed == NULL)
    {
        return NullCrashing;
    }
    if (ToBeTransformed->Value < 0)
    {
        return Physical_Logic_Error;
    }
    if (ToBeTransformed->MeasuredType != Time)
    {
        return Quanitity_MissMatch;
    }
    ToSecond(ToBeTransformed);
    ToBeTransformed->UnitType = Minute;
    ToBeTransformed->Value /= Minute_To_Second;
    return Transformation_Done;
}

uint8_t ToHour(Unit *ToBeTransformed)
{
    if (ToBeTransformed == NULL)
    {
        return NullCrashing;
    }
    if (ToBeTransformed->Value < 0)
    {
        return Physical_Logic_Error;
    }
    if (ToBeTransformed->MeasuredType != Time)
    {
        return Quanitity_MissMatch;
    }
    ToSecond(ToBeTransformed);
    ToBeTransformed->UnitType = Hour;
    ToBeTransformed->Value /= Hour_To_Second;
    return Transformation_Done;
}

uint8_t ToDay(Unit *ToBeTransformed)
{
    if (ToBeTransformed == NULL)
    {
        return NullCrashing;
    }
    if (ToBeTransformed->Value < 0)
    {
        return Physical_Logic_Error;
    }
    if (ToBeTransformed->MeasuredType != Time)
    {
        return Quanitity_MissMatch;
    }
    ToSecond(ToBeTransformed);
    ToBeTransformed->UnitType = Day;
    ToBeTransformed->Value /= Day_To_Second;
    return Transformation_Done;
}

uint8_t ToWeek(Unit *ToBeTransformed)
{
    if (ToBeTransformed == NULL)
    {
        return NullCrashing;
    }
    if (ToBeTransformed->Value < 0)
    {
        return Physical_Logic_Error;
    }
    if (ToBeTransformed->MeasuredType != Time)
    {
        return Quanitity_MissMatch;
    }
    ToSecond(ToBeTransformed);
    ToBeTransformed->UnitType = Week;
    ToBeTransformed->Value /= Week_To_Second;
    return Transformation_Done;
}

uint8_t ToBit(Unit *ToBeTransformed)
{
    
    if (ToBeTransformed == NULL)
    {
        return NullCrashing;
    }
    ToBeTransformed->Value=(double)((long long)ToBeTransformed->Value);
    if (ToBeTransformed->Value < 0)
    {
        return Physical_Logic_Error;
    }
    if (ToBeTransformed->MeasuredType != Digital_Storage)
    {
        return Quanitity_MissMatch;
    }
    ToByte(ToBeTransformed);
    ToBeTransformed->UnitType = Bit;
    ToBeTransformed->Value =(double)((int) ToBeTransformed->Value/ Bit_To_Byte);
    return Transformation_Done;
}

uint8_t ToByte(Unit *ToBeTransformed)
{
    
    if (ToBeTransformed == NULL)
    {
        return NullCrashing;
    }
    ToBeTransformed->Value=(double)((long long)ToBeTransformed->Value);
    if (ToBeTransformed->Value < 0)
    {
        return Physical_Logic_Error;
    }
    if (ToBeTransformed->MeasuredType != Digital_Storage)
    {
        return Quanitity_MissMatch;
    }
    switch (ToBeTransformed->UnitType)
    {
    case Byte:
        ToBeTransformed->Value *= Byte_To_Byte;
        break;
    case Bit:
        ToBeTransformed->Value *= Bit_To_Byte;
        break;
    case Gigabyte:
        ToBeTransformed->Value *= Gigabyte_To_Byte;
        break;
    case Terabyte:
        ToBeTransformed->Value *= Terabyte_To_Byte;
        break;
    case Kilobyte:
        ToBeTransformed->Value *= Kilobyte_To_Byte;
        break;
    case Megabyte:
        ToBeTransformed->Value *= Megabyte_To_Byte;
        break;
    default:
        return UnRegisteredUnitFortheMeasuredQuantity;
        break;
    }
    ToBeTransformed->UnitType = Byte;
    ToBeTransformed->Value =(double)((int) ToBeTransformed->Value/ Byte_To_Byte);
    return Transformation_Done;
}

uint8_t ToKilobyte(Unit *ToBeTransformed)
{
    
    if (ToBeTransformed == NULL)
    {
        return NullCrashing;
    }
    ToBeTransformed->Value=(double)((long long)ToBeTransformed->Value);
    if (ToBeTransformed->Value < 0)
    {
        return Physical_Logic_Error;
    }
    if (ToBeTransformed->MeasuredType != Digital_Storage)
    {
        return Quanitity_MissMatch;
    }
    ToByte(ToBeTransformed);
    ToBeTransformed->UnitType = Kilobyte;
    ToBeTransformed->Value =(double)((int) ToBeTransformed->Value/ Kilobyte_To_Byte);
    return Transformation_Done;
}

uint8_t ToMegabyte(Unit *ToBeTransformed)
{
    
    if (ToBeTransformed == NULL)
    {
        return NullCrashing;
    }
    ToBeTransformed->Value=(double)((long long)ToBeTransformed->Value);
    if (ToBeTransformed->Value < 0)
    {
        return Physical_Logic_Error;
    }
    if (ToBeTransformed->MeasuredType != Digital_Storage)
    {
        return Quanitity_MissMatch;
    }
    ToByte(ToBeTransformed);
    ToBeTransformed->UnitType = Megabyte;
    ToBeTransformed->Value =(double)((int) ToBeTransformed->Value/ Megabyte_To_Byte);
    return Transformation_Done;
}

uint8_t ToGigabyte(Unit *ToBeTransformed)
{
    
    if (ToBeTransformed == NULL)
    {
        return NullCrashing;
    }
    ToBeTransformed->Value=(double)((long long)ToBeTransformed->Value);
    if (ToBeTransformed->Value < 0)
    {
        return Physical_Logic_Error;
    }
    if (ToBeTransformed->MeasuredType != Digital_Storage)
    {
        return Quanitity_MissMatch;
    }
    ToByte(ToBeTransformed);
    ToBeTransformed->UnitType = Gigabyte;
    ToBeTransformed->Value =(double)((int) ToBeTransformed->Value/ Gigabyte_To_Byte);
    return Transformation_Done;
}

uint8_t ToTerabyte(Unit *ToBeTransformed)
{
    
    if (ToBeTransformed == NULL)
    {
        return NullCrashing;
    }
    ToBeTransformed->Value=(double)((long long)ToBeTransformed->Value);
    if (ToBeTransformed->Value < 0)
    {
        return Physical_Logic_Error;
    }
    if (ToBeTransformed->MeasuredType != Digital_Storage)
    {
        return Quanitity_MissMatch;
    }
    ToByte(ToBeTransformed);
    ToBeTransformed->UnitType = Terabyte;
    ToBeTransformed->Value =(double)((int) ToBeTransformed->Value/ Terabyte_To_Byte);
    return Transformation_Done;
}

uint8_t ToMeterPerSec(Unit *ToBeTransformed)
{
    if (ToBeTransformed == NULL)
    {
        return NullCrashing;
    }
    if (ToBeTransformed->MeasuredType != Speed)
    {
        return Quanitity_MissMatch;
    }
    switch (ToBeTransformed->UnitType)
    {
    case MeterPerSec:
        ToBeTransformed->Value *= MeterPerSec_To_MeterPerSec;
        break;
    case KMPerHr:
        ToBeTransformed->Value *= KMPerHr_To_MeterPerSec;
        break;
    case Milesperhour:
        ToBeTransformed->Value *= Milesperhour_To_MeterPerSec;
        break;
    default:
        return UnRegisteredUnitFortheMeasuredQuantity;
        break;
    }
    ToBeTransformed->UnitType = MeterPerSec;
    ToBeTransformed->Value /= MeterPerSec_To_MeterPerSec;
    return Transformation_Done;
}

uint8_t ToKMPerHr(Unit *ToBeTransformed)
{
    if (ToBeTransformed == NULL)
    {
        return NullCrashing;
    }
    if (ToBeTransformed->MeasuredType != Speed)
    {
        return Quanitity_MissMatch;
    }
    ToMeterPerSec(ToBeTransformed);
    ToBeTransformed->UnitType = KMPerHr;
    ToBeTransformed->Value /= KMPerHr_To_MeterPerSec;
    return Transformation_Done;
}

uint8_t ToMilesperhour(Unit *ToBeTransformed)
{
    if (ToBeTransformed == NULL)
    {
        return NullCrashing;
    }
    if (ToBeTransformed->MeasuredType != Speed)
    {
        return Quanitity_MissMatch;
    }
    ToMeterPerSec(ToBeTransformed);
    ToBeTransformed->UnitType = Milesperhour;
    ToBeTransformed->Value /= Milesperhour_To_MeterPerSec;
    return Transformation_Done;
}
uint8_t ToCelsius(Unit *ToBeTransformed)
{

    if (ToBeTransformed == NULL)
    {
        return NullCrashing;
    }
    if ((ToBeTransformed->UnitType == Kelvin && ToBeTransformed->Value < 0.0) ||
        (ToBeTransformed->UnitType == Celsius && ToBeTransformed->Value < -273.15) ||
        (ToBeTransformed->UnitType == Fahrenheit && ToBeTransformed->Value < -459.67))
    {
        return Physical_Logic_Error;
    }
    if (ToBeTransformed->MeasuredType != Temprature)
    {
        return Quanitity_MissMatch;
    }
    switch (ToBeTransformed->UnitType)
    {
    case Celsius:
        ToBeTransformed->Value = Celsius_To_Celsius(ToBeTransformed->Value);
        break;
    case Fahrenheit:
        ToBeTransformed->Value = Fahrenheit_To_Celsius(ToBeTransformed->Value);
        break;
    case Kelvin:
        ToBeTransformed->Value = Kelvin_To_Celsius(ToBeTransformed->Value);
        break;

    default:
        break;
    }
    ToBeTransformed->UnitType = Celsius;
    return Transformation_Done;
}
uint8_t ToFahrenheit(Unit *ToBeTransformed)
{
    if (ToBeTransformed == NULL)
    {
        return NullCrashing;
    }
    if ((ToBeTransformed->UnitType == Kelvin && ToBeTransformed->Value < 0.0) ||
        (ToBeTransformed->UnitType == Celsius && ToBeTransformed->Value < -273.15) ||
        (ToBeTransformed->UnitType == Fahrenheit && ToBeTransformed->Value < -459.67))
    {
        return Physical_Logic_Error;
    }
    if (ToBeTransformed->MeasuredType != Temprature)
    {
        return Quanitity_MissMatch;
    }
    ToCelsius(ToBeTransformed);
    ToBeTransformed->Value = Celsius_To_Fahrenheit(ToBeTransformed->Value);
    ToBeTransformed->UnitType = Fahrenheit;
    return Transformation_Done;
}

uint8_t ToKelvin(Unit *ToBeTransformed)
{
    if (ToBeTransformed == NULL)
    {
        return NullCrashing;
    }
    if ((ToBeTransformed->UnitType == Kelvin && ToBeTransformed->Value < 0.0) ||
        (ToBeTransformed->UnitType == Celsius && ToBeTransformed->Value < -273.15) ||
        (ToBeTransformed->UnitType == Fahrenheit && ToBeTransformed->Value < -459.67))
    {
        return Physical_Logic_Error;
    }
    if (ToBeTransformed->MeasuredType != Temprature)
    {
        return Quanitity_MissMatch;
    }
    ToCelsius(ToBeTransformed);
    ToBeTransformed->Value = Celsius_To_Kelvin(ToBeTransformed->Value);
    ToBeTransformed->UnitType = Kelvin;
    return Transformation_Done;
}
