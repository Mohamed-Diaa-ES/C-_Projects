#ifndef __UNIT_CONVERTER_H
#define __UNIT_CONVERTER_H
#include <stdint.h>



 
/** 
 * @struct Unit
 * @brief Configuration for the Unit to be transformed.
 */
typedef struct 
{
     /** @var   Unit::Value 
     *  @brief  The Vallue of the Unit to be converted
     */ 
    double  Value;
    /** @var   Unit::UnitType 
     *  @brief  The Unit the value is measurred in like kilograms or grams for example  
     */ 
    uint8_t UnitType;
    /** @var   Unit::MeassuredType
     *  @brief  The thing is to be meassured  like length or mass or speed...etc 
     * @note    IT IS NOT THE SAME AS THE UnitType
     */ 
    uint8_t MeasuredType;

} Unit;

/**
 * @defgroup Length APIs
 * @brief    These are the APIs for the length Conversions and thier units transactions
 * @{ 
 */

 /**
  * @brief  It transforms the Value in the Structure to be in Meters.
  * @param  ToBeTransformed -> It is the Value wanted to be transformed to Meters.
  */
uint8_t ToMeters(Unit* ToBeTransformed);
 /**
  * @brief  It transforms the Value in the Structure to be in Miles.
  * @param  ToBeTransformed -> It is the Value wanted to be transformed To Miles.
  */
uint8_t ToMiles(Unit* ToBeTransformed);
 /**
  * @brief  It transforms the Value in the Structure to be in CM.
  * @param  ToBeTransformed -> It is the Value wanted to be transformed To CM.
  */
uint8_t ToCM(Unit* ToBeTransformed);
 /**
  * @brief  It transforms the Value in the Structure to be in KiloMeters.
  * @param  ToBeTransformed -> It is the Value wanted to be transformed To KiloMeters.
  */
uint8_t ToKiloMeters(Unit* ToBeTransformed);
 /**
  * @brief  It transforms the Value in the Structure to be in Inches.
  * @param  ToBeTransformed -> It is the Value wanted to be transformed To Inches.
  */
uint8_t ToInches(Unit* ToBeTransformed);
 /**
  * @brief  It transforms the Value in the Structure to be in Foot.
  * @param  ToBeTransformed -> It is the Value wanted to be transformed To Foot.
  */
uint8_t ToFoot(Unit* ToBeTransformed);
 /**
  * @brief  It transforms the Value in the Structure to be in Yard.
  * @param  ToBeTransformed -> It is the Value wanted to be transformed To Yard.
  */
uint8_t ToYard(Unit* ToBeTransformed);
/**
 * @}
 */
/**
 * @defgroup Mass
 * @brief    These are the APIs for the Mass Conversions and thier units transactions
 * @{ 
 */
 /**
  * @brief  It transforms the Value in the Structure to be in KiloGrams.
  * @param  ToBeTransformed -> It is the Value wanted to be transformed To KiloGrams.
  */
uint8_t ToKiloGrams(Unit* ToBeTransformed);
 /**
  * @brief  It transforms the Value in the Structure to be in Grams.
  * @param  ToBeTransformed -> It is the Value wanted to be transformed To Grams.
  */
uint8_t ToGrams(Unit* ToBeTransformed);
 /**
  * @brief  It transforms the Value in the Structure to be in Tons.
  * @param  ToBeTransformed -> It is the Value wanted to be transformed To Tons.
  */
uint8_t ToTons(Unit* ToBeTransformed);
 /**
  * @brief  It transforms the Value in the Structure to be in Ounces.
  * @param  ToBeTransformed -> It is the Value wanted to be transformed To Ounces.
  */
uint8_t ToOunces(Unit* ToBeTransformed);
 /**
  * @brief  It transforms the Value in the Structure to be in Pound.
  * @param  ToBeTransformed -> It is the Value wanted to be transformed To Pound.
  */
uint8_t ToPound(Unit* ToBeTransformed);
 /**
  * @brief  It transforms the Value in the Structure to be in Stone.
  * @param  ToBeTransformed -> It is the Value wanted to be transformed To Stone.
  */
uint8_t ToStone(Unit* ToBeTransformed);
/**
 * @}
 */

 
/**
 * @defgroup Volume
 * @brief    These are the APIs for the Volume Conversions and thier units transactions
 * @{ 
 */

  /**
  * @brief  It transforms the Value in the Structure to be in MilliLiter.
  * @param  ToBeTransformed -> It is the Value wanted to be transformed To MilliLiter.
  */
uint8_t ToMilliLiter(Unit* ToBeTransformed);
 /**
  * @brief  It transforms the Value in the Structure to be in Liter.
  * @param  ToBeTransformed -> It is the Value wanted to be transformed To Liter.
  */
uint8_t ToLiter(Unit* ToBeTransformed);
 /**
  * @brief  It transforms the Value in the Structure to be in CubicMeter.
  * @param  ToBeTransformed -> It is the Value wanted to be transformed To CubicMeter.
  */
uint8_t ToCubicMeter(Unit* ToBeTransformed);
 /**
  * @brief  It transforms the Value in the Structure to be in Gallon.
  * @param  ToBeTransformed -> It is the Value wanted to be transformed To Gallon.
  */
uint8_t ToGallon(Unit* ToBeTransformed);
/**
 * @}
 */
/**
 * @defgroup Time
 * @brief    These are the APIs for the Time Conversions and thier units transactions
 * @{ 
 */

  /**
  * @brief  It transforms the Value in the Structure to be in Millisecond.
  * @param  ToBeTransformed -> It is the Value wanted to be transformed To Millisecond.
  */
uint8_t ToMillisecond(Unit* ToBeTransformed);
 /**
  * @brief  It transforms the Value in the Structure to be in Second.
  * @param  ToBeTransformed -> It is the Value wanted to be transformed To Second.
  */
uint8_t ToSecond(Unit* ToBeTransformed);
 /**
  * @brief  It transforms the Value in the Structure to be in Minute.
  * @param  ToBeTransformed -> It is the Value wanted to be transformed To Minute.
  */
uint8_t ToMinute(Unit* ToBeTransformed);
 /**
  * @brief  It transforms the Value in the Structure to be in Hour.
  * @param  ToBeTransformed -> It is the Value wanted to be transformed To Hour.
  */
uint8_t ToHour(Unit* ToBeTransformed);
 /**
  * @brief  It transforms the Value in the Structure to be in Day.
  * @param  ToBeTransformed -> It is the Value wanted to be transformed To Day.
  */
uint8_t ToDay(Unit* ToBeTransformed);
 /**
  * @brief  It transforms the Value in the Structure to be in Week.
  * @param  ToBeTransformed -> It is the Value wanted to be transformed To Week.
  */
uint8_t ToWeek(Unit* ToBeTransformed);
/**
 * @}
 */
/**
 * @defgroup Digital_Storage
 * @brief    These are the APIs for the Digital_Storage Conversions and thier units transactions
 * @{ 
 */

  /**
  * @brief  It transforms the Value in the Structure to be in Bit.
  * @param  ToBeTransformed -> It is the Value wanted to be transformed To Bit.
  */
uint8_t ToBit(Unit* ToBeTransformed);
 /**
  * @brief  It transforms the Value in the Structure to be in Byte.
  * @param  ToBeTransformed -> It is the Value wanted to be transformed To Byte.
  */
uint8_t ToByte(Unit* ToBeTransformed);
 /**
  * @brief  It transforms the Value in the Structure to be in Kilobyte.
  * @param  ToBeTransformed -> It is the Value wanted to be transformed To Kilobyte.
  */
uint8_t ToKilobyte(Unit* ToBeTransformed);
 /**
  * @brief  It transforms the Value in the Structure to be in Megabyte.
  * @param  ToBeTransformed -> It is the Value wanted to be transformed To Megabyte.
  */
uint8_t ToMegabyte(Unit* ToBeTransformed);
 /**
  * @brief  It transforms the Value in the Structure to be in Gigabyte.
  * @param  ToBeTransformed -> It is the Value wanted to be transformed To Gigabyte.
  */
uint8_t ToGigabyte(Unit* ToBeTransformed);
 /**
  * @brief  It transforms the Value in the Structure to be in Terabyte.
  * @param  ToBeTransformed -> It is the Value wanted to be transformed To Terabyte.
  */
uint8_t ToTerabyte(Unit* ToBeTransformed);
/**
 * @}
 */
/**
 * @defgroup Speed
 * @brief    These are the APIs for the Speed Conversions and thier units transactions
 * @{ 
 */

  /**
  * @brief  It transforms the Value in the Structure to be in MeterPerSec.
  * @param  ToBeTransformed -> It is the Value wanted to be transformed To MeterPerSec.
  */
uint8_t ToMeterPerSec(Unit* ToBeTransformed);
 /**
  * @brief  It transforms the Value in the Structure to be in KMPerHr.
  * @param  ToBeTransformed -> It is the Value wanted to be transformed To KMPerHr.
  */
uint8_t ToKMPerHr(Unit* ToBeTransformed);
 /**
  * @brief  It transforms the Value in the Structure to be in Milesperhour.
  * @param  ToBeTransformed -> It is the Value wanted to be transformed To Milesperhour.
  */
uint8_t ToMilesperhour(Unit* ToBeTransformed);


/**
 * @}
 */
/**
 * @defgroup Temprature
 * @brief    These are the APIs for the Temprature Conversions and thier units transactions
 * @{ 
 */

  /**
  * @brief  It transforms the Value in the Structure to be in Fahrenheit.
  * @param  ToBeTransformed -> It is the Value wanted to be transformed To Fahrenheit.
  */
uint8_t ToFahrenheit(Unit* ToBeTransformed);
 /**
  * @brief  It transforms the Value in the Structure to be in Celsius.
  * @param  ToBeTransformed -> It is the Value wanted to be transformed To Celsius.
  */
uint8_t ToCelsius(Unit* ToBeTransformed);
 /**
  * @brief  It transforms the Value in the Structure to be in Kelvin.
  * @param  ToBeTransformed -> It is the Value wanted to be transformed To Kelvin.
  */
uint8_t ToKelvin(Unit* ToBeTransformed);
/**
 * @}
 */
#endif