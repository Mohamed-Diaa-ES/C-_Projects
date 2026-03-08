#ifndef __UNIT_CONVERTER_H
#define __UNIT_CONVERTER_H
#include <stdint.h>


/**
 * @defgroup Length
 * @brief    These are the Functions Declarations and the structures for the length Conversions
 * @{ 
 */

typedef struct 
{
    float   Value;
    uint8_t UnitType;
    uint8_t MeasuredType;

} LengthUnit;

float ToMeters();
float ToMiles();
float ToCM();
float ToKiloMeters();
float ToInches();
float ToYard();
/**
 * @}
 */
/**
 * @defgroup Mass
 * @brief    These are the Functions Declarations and the structures for the Mass Conversions
 * @{ 
 */
typedef struct 
{
    float   Value;
    uint8_t UnitType;
    uint8_t MeasuredType;

} MassUnit;
float ToKiloGrams();
float ToGrams();
float ToTons();
float ToOunces();
float ToPound();
float ToStone();
/**
 * @}
 */

 
/**
 * @defgroup Volume
 * @brief    These are the Functions Declarations and the structures for the Volume Conversions
 * @{ 
 */
typedef struct 
{
    float   Value;
    uint8_t UnitType;
    uint8_t MeasuredType;

} VolumeUnit;
float ToMilliLiter();
float ToLiter();
float ToCubicMeter();
float ToGallon();
/**
 * @}
 */
/**
 * @defgroup Time
 * @brief    These are the Functions Declarations and the structures for the Time Conversions
 * @{ 
 */
typedef struct 
{
    float   Value;
    uint8_t UnitType;
    uint8_t MeasuredType;

} TimeUnit;
float ToMillisecond();
float ToSecond();
float ToMinute();
float ToHour();
float ToDay();
float ToWeek();
/**
 * @}
 */
/**
 * @defgroup Digital_Storage
 * @brief    These are the Functions Declarations and the structures for the Digital_Storage Conversions
 * @{ 
 */
typedef struct 
{
    float   Value;
    uint8_t UnitType;
    uint8_t MeasuredType;

} Digital_StorageUnit;
float ToBit();
float ToByte();
float ToKilobyte();
float ToMegabyte();
float ToGigabyte();
float ToTerabyte();
/**
 * @}
 */
/**
 * @defgroup Speed
 * @brief    These are the Functions Declarations and the structures for the Speed Conversions
 * @{ 
 */
typedef struct 
{
    float   Value;
    uint8_t UnitType;
    uint8_t MeasuredType;

} SpeedUnit;
float ToBitMeterPerSec();
float ToBitKMPerHr();
float ToBitMilesperhour();


/**
 * @}
 */
/**
 * @defgroup Temprature
 * @brief    These are the Functions Declarations and the structures for the Temprature Conversions
 * @{ 
 */
typedef struct 
{
    float   Value;
    uint8_t UnitType;
    uint8_t MeasuredType;

} TempratureUnit;
float ToFahrenheit();
float ToCelsius();
float ToKelvin();
/**
 * @}
 */
#endif