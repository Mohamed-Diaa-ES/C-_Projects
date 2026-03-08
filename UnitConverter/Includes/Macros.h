#ifndef _MACROS__H
#define _MACROS__H

/**
 * @defgroup MeasuredType
 * @brief   These are the macros to define every type registered of measure like: Mass,Time,...etc.
 * @{
 */
#define Length 0
#define Mass 1
#define Volume 2
#define Time 3
#define Digital_Storage 4
#define Speed 5
#define Temprature 6
/**
 * @}
 */
/**
 * @defgroup Length Macros
 * @brief   These are the Macros Needed for Length Conversions
 * @{
 */
/**
 * @defgroup Length Units
 * @brief   Macros to distinguish between the Length Macros
 * @{
 */
#define CM 0
#define Meters 1
#define KiloMeters 2
#define Miles 3
#define Inches 4
#define Foot 5
#define Yard 6

/**
 * @}
 */
/**
 * @defgroup Length Conversions
 * @brief   Macros to Define transitions From Other units to Meters
 * @{
 */
#define Meters_To_Meters 1
#define CM_To_Meters .01
#define KiloMeters_To_Meters 1000
#define Miles_To_Meters 1609.344
#define Inches_To_Meters 0.0254
#define Foot_To_Meters 0.3048
#define Yard_To_Meters 0.9144

/**
 * @}
 */

/**
 * @}
 */
/**
 * @defgroup Mass Macros
 * @brief   These are the Macros Needed for Mass Conversions
 * @{
 */
/**
 * @defgroup Mass Units
 * @brief   Macros to distinguish between the Mass Macros
 * @{
 */
#define Grams 0
#define KiloGrams 1
#define Tons 2
#define Ounces 3
#define Pound 4
#define Stone 5
/**
 * @}
 */
/**
 * @defgroup Mass Conversions
 * @brief   Macros to Define transitions From Other Units to KiloGrams
 * @{
 */
#define KiloGrams_To_KiloGrams 1
#define Grams_To_KiloGrams .001
#define Tons_To_KiloGrams 1000
#define Ounces_To_KiloGrams 0.0283495
#define Pound_To_KiloGrams 0.453592
#define Stone_To_KiloGrams 6.35029

/**
 * @}
 */

/**
 * @}
 */
/**
 * @defgroup Volume Macros
 * @brief   These are the Macros Needed for Volume Conversions
 * @{
 */
/**
 * @defgroup Volume Units
 * @brief   Macros to distinguish between the Volume Macros
 * @{
 */
#define MilliLiter 0
#define Liter 1
#define CubicMeter 2
#define Gallon 3
/**
 * @}
 */
/**
 * @defgroup Volume Conversions
 * @brief   Macros to Define transitions From Other Units to Liter
 * @{
 */
#define Liter_To_Liter 1
#define MilliLiter_To_Liter .001
#define CubicMeter_To_Liter 1000
#define Gallon_To_Liter 3.78541
/**
 * @}
 */
/**
 * @}
 */
/**
 * @defgroup Time Macros
 * @brief   These are the Macros Needed for Time Conversions
 * @{
 */
/**
 * @defgroup Time Units
 * @brief   Macros to distinguish between the Time Macros
 * @{
 */
#define Millisecond 0
#define Second 1
#define Minute 2
#define Hour 3
#define Day 4
#define Week 5
/**
 * @}
 */
/**
 * @defgroup Time Conversions
 * @brief   Macros to Define transitions From Other Units to Second
 * @{
 */
#define Second_To_Second 1
#define MilliSecond_To_Second .001
#define Minute_To_Second 60
#define Hour_To_Second 3600
#define Day_To_Second 86400
#define Week_To_Second 604800
/**
 * @}
 */
/**
 * @}
 */
/**
 * @defgroup Digital_Storage
 * @brief   These are the Macros Needed for Digital_Storage Conversions
 * @{
 */
/**
 * @defgroup Digital_Storage Units
 * @brief   Macros to distinguish between the Digital_Storage Macros
 * @{
 */
#define Bit 0
#define Byte 1
#define Kilobyte 2
#define Megabyte 3
#define Gigabyte 4
#define Terabyte 5
/**
 * @}
 */
/**
 * @defgroup Digital_Storage Conversions
 * @brief   Macros to Define transitions From Other Units to Second
 * @{
 */
#define Byte_To_Byte        1
#define Bit_To_Byte         0.125
#define Kilobyte_To_Byte    1024
#define Megabyte_To_Byte    1048576
#define Gigabyte_To_Byte    1073741824
#define Terabyte_To_Byte    1099511627776
/**
 * @}
 */
/**
 * @}
 */

/**
 * @defgroup Speed
 * @brief   These are the Macros Needed for Speed Conversions
 * @{
 */
/**
 * @defgroup Speed Units
 * @brief   Macros to distinguish between the Speed Macros
 * @{
 */
#define MeterPerSec 0
#define KMPerHr 1
#define Milesperhour 2
/**
 * @}
 */
/**
 * @defgroup Speed Conversions
 * @brief   Macros to Define transitions From Other Units to Meter Per Second
 * @{
 */
#define MeterPerSec_To_MeterPerSec        1
#define KMPerHr_To_MeterPerSec         0.277778
#define Milesperhour_To_MeterPerSec    0.44704

/**
 * @}
 */
/**
 * @}
 */
/**
 * @defgroup Temprature
 * @brief   These are the Macros Needed for Temprature Conversions
 * @{
 */
        /**
         * @defgroup Temprature Units
         * @brief   Macros to distinguish between the Temprature Macros
         * @{
         */
        #define Fahrenheit 0
        #define Celsius 1
        #define Kelvin 2
        /**
         * @}
         */
        /**
         * @defgroup Temprature Conversions
         * @brief   Macros to Define transitions From Other Units to Celsius
         * @{
         */
        #define Celsius_To_Celsius(Value)        (Value)*1
        #define Fahrenheit_To_Celsius(Value)     (Value-32)*5./9.
        #define Kelvin_To_Celsius(Value)         Value-273.15
        #define Celsius_To_Fahrenheit(Value)     (Value*9./5.)+32
        #define Celsius_To_Kelvin(Value)         Value+273.15
        /**
         * @}
         */
/**
 * @}
 */
#endif