#ifndef _MACROS__H
#define _MACROS__H

/**
 * @defgroup Physical_Limits Physical Boundary Limits
 * @brief   Macros defining the absolute minimum physical values to prevent impossible states.
 * @{
 */

/**
 * @brief The lowest possible value for standard physical quantities (Length, Mass, Volume, Time, Speed, Digital Storage).
 */
#define ABSOLUTE_MINIMUM_STANDARD 0.0

/**
 * @brief Absolute zero in Kelvin. Temperature cannot drop below this.
 */
#define ABSOLUTE_ZERO_KELVIN 0.0

/**
 * @brief Absolute zero in Celsius.
 */
#define ABSOLUTE_ZERO_CELSIUS -273.15

/**
 * @brief Absolute zero in Fahrenheit.
 */
#define ABSOLUTE_ZERO_FAHRENHEIT -459.67

/**
 * @}
 */
/**
 * @details This macro used to be used by the programmer == 1 used
 *          when using handleScanfproblems function to Enhance Error handling
 *          it literally means we have passed one input to scanf.
 */
#define OneInputToScanf 1
/**
 * @defgroup ActionCodes
 * @brief    This Group Defines the Error and the action codes used to handle the Actions.
 * @{
 */
/**
 * @brief This macro tells the main app that the transaction is done with no errors
 */
#define Transformation_Done 1
/**
 * @brief  The value violates the laws of physics
 * */
#define Physical_Logic_Error 3

#define NullCrashing 2 // handle the NullCrashing
/**
 * @brief This macro tells the main.c File that there is something like transforming kilobytes to grams.
 */
#define Quanitity_MissMatch 255
/**
 * @brief This macro tells the main app that the transaction is done with no errors
 */
#define UnRegisteredUnitFortheMeasuredQuantity 0
/**
 * @brief This macro tells the main app to exit from the program
 */
#define Exit 7
/**
 * @}
 */
/**
 * @defgroup MeasuredType
 * @brief   These are the macros to define every type registered of measure like: Mass,Time,...etc.
 * @{
 */
/**
 * @brief This Macro Defines the Number of the Quantities that Can be Converted by the application.
 */
#define ConvertableQuantitesNumber 7
/**
 * @brief This Macro Defines the length for the Meassured Quanitiy
 */
#define Length 0

/**
 * @brief This Macro Defines the Mass for the Meassured Quanitiy
 */

#define Mass 1
/**
 * @brief This Macro Defines the Volume for the Meassured Quanitiy
 */

#define Volume 2
/**
 * @brief This Macro Defines the Time for the Meassured Quanitiy
 */

#define Time 3
/**
 * @brief This Macro Defines the Digital_Storage for the Meassured Quanitiy
 */

#define Digital_Storage 4
/**
 * @brief This Macro Defines the Speed for the Meassured Quanitiy
 */

#define Speed 5
/**
 * @brief This Macro Defines the Temprature for the Meassured Quanitiy
 */
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
 * @brief This Macro Defines the Number of the Units that Can be Converted by the application in the  Length.
 */
#define LengthUnitsNumbers 7
/**
 * @defgroup Length Units
 * @brief   Macros to distinguish between the Length Macros
 * @{

 */
/**
 * @brief This Macro Defines the CM Unit The length value measured in.
 */

#define CM 0
/**
 * @brief This Macro Defines the Meters Unit The length value measured in.
 */

#define Meters 1
/**
 * @brief This Macro Defines the KiloMeters Unit The length value measured in.
 */

#define KiloMeters 2
/**
 * @brief This Macro Defines the Miles Unit The length value measured in.
 */

#define Miles 3
/**
 * @brief This Macro Defines the Inches Unit The length value measured in.
 */

#define Inches 4
/**
 * @brief This Macro Defines the Foot Unit The length value measured in.
 */

#define Foot 5
/**
 * @brief This Macro Defines the Yard Unit The length value measured in.
 */
#define Yard 6

/**
 * @}
 */

/**
 * @defgroup Length_symbols
 * @brief   Macros to have the units in symbols
 * @{
 */

#define CM_Symb "cm"

#define Meters_Symb "m"

#define KiloMeters_Symb "km"

#define Miles_Symb "mi"

#define Inches_Symb "in"

#define Foot_Symb "F"

#define Yard_Symb "yd"

/**
 * @}
 */

/**
 * @defgroup Length Conversions
 * @brief   Macros to Define transitions From Other units to Meters
 * @{

 */
/**
 * @brief This Macro Defines the Multiplied value to return to meters and when divde by it you get the unit you transformed to.
 */

#define Meters_To_Meters 1
/**
 * @brief This Macro Defines the Multiplied value to return to meters and when divde by it you get the unit you transformed From.
 */

#define CM_To_Meters .01
/**
 * @brief This Macro Defines the Multiplied value to return to meters and when divde by it you get the unit you transformed From.
 */

#define KiloMeters_To_Meters 1000
/**
 * @brief This Macro Defines the Multiplied value to return to meters and when divde by it you get the unit you transformed From.
 */

#define Miles_To_Meters 1609.344
/**
 * @brief This Macro Defines the Multiplied value to return to meters and when divde by it you get the unit you transformed From.
 */

#define Inches_To_Meters 0.0254
/**
 * @brief This Macro Defines the Multiplied value to return to meters and when divde by it you get the unit you transformed From.
 */

#define Foot_To_Meters 0.3048
/**
 * @brief This Macro Defines the Multiplied value to return to meters and when divde by it you get the unit you transformed From.
 */
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
 * @brief This Macro Defines the Number of the Units that Can be Converted by the application in the  Mass.
 */
#define MassUnitsNumbers 6
/**
 * @defgroup Mass Units
 * @brief   Macros to distinguish between the Mass Macros
 * @{

/**
 * @brief This Macro Defines the Grams Unit The Mass value measured in.
 */

#define Grams 0
/**
 * @brief This Macro Defines the KiloGrams Unit The Mass value measured in.
 */

#define KiloGrams 1
/**
 * @brief This Macro Defines the Tons Unit The Mass value measured in.
 */
#define Tons 2
/**
 * @brief This Macro Defines the Ounces Unit The Mass value measured in.
 */

#define Ounces 3
/**
 * @brief This Macro Defines the Pound Unit The Mass value measured in.
 */

#define Pound 4
/**
 * @brief This Macro Defines the Stone Unit The Mass value measured in.
 */
#define Stone 5
/**
 * @}
 */
/**
 * @defgroup Mass_symbols
 * @brief   Macros to have the units in symbols
 * @{
 */

#define Grams_Symb "g"

#define KiloGrams_Symb "kg"

#define Tons_Symb "t"

#define Ounces_Symb "oz"

#define Pound_Symb "lb"

#define Stone_Symb "st"

/**
 * @}
 */
/**
 * @defgroup Mass Conversions
 * @brief   Macros to Define transitions From Other Units to KiloGrams
 * @{

/**
 * @brief This Macro Defines the Multiplied value to return to KiloGrams and when divde by it you get the unit you transformed From.
 */

#define KiloGrams_To_KiloGrams 1
/**
 * @brief This Macro Defines the Multiplied value to return to KiloGrams and when divde by it you get the unit you transformed From.
 */

#define Grams_To_KiloGrams .001
/**
 * @brief This Macro Defines the Multiplied value to return to KiloGrams and when divde by it you get the unit you transformed From.
 */

#define Tons_To_KiloGrams 1000
/**
 * @brief This Macro Defines the Multiplied value to return to KiloGrams and when divde by it you get the unit you transformed From.
 */

#define Ounces_To_KiloGrams 0.0283495
/**
 * @brief This Macro Defines the Multiplied value to return to KiloGrams and when divde by it you get the unit you transformed From.
 */

#define Pound_To_KiloGrams 0.453592
/**
 * @brief This Macro Defines the Multiplied value to return to KiloGrams and when divde by it you get the unit you transformed From.
 */

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
 * @brief This Macro Defines the Number of the Units that Can be Converted by the application in the  Volume.
 */
#define VolumeUnitsNumbers 4
/**
 * @defgroup Volume Units
 * @brief   Macros to distinguish between the Volume Macros
 * @{

/**
 * @brief This Macro Defines the MilliLiter Unit The Volume value measured in.
 */

#define MilliLiter 0
/**
 * @brief This Macro Defines the Liter Unit The Volume value measured in.
 */

#define Liter 1
/**
 * @brief This Macro Defines the CubicMeter Unit The Volume value measured in.
 */

#define CubicMeter 2
/**
 * @brief This Macro Defines the Gallon Unit The Volume value measured in.
 */
#define Gallon 3
/**
 * @}
 */
/**
 * @defgroup Volume_symbols
 * @brief   Macros to have the units in symbols
 * @{
 */

#define MilliLiter_Symb "mL"

#define Liter_Symb "L"

#define CubicMeter_Symb "m"

#define Gallon_Symb "gal"

/**
 * @}
 */
/**
 * @defgroup Volume Conversions
 * @brief   Macros to Define transitions From Other Units to Liter
 * @{

 */
/**
 * @brief This Macro Defines the Multiplied value to return to Liter and when divde by it you get the unit you transformed From.
 */

#define Liter_To_Liter 1
/**
 * @brief This Macro Defines the Multiplied value to return to Liter and when divde by it you get the unit you transformed From.
 */

#define MilliLiter_To_Liter .001
/**
 * @brief This Macro Defines the Multiplied value to return to Liter and when divde by it you get the unit you transformed From.
 */

#define CubicMeter_To_Liter 1000
/**
 * @brief This Macro Defines the Multiplied value to return to Liter and when divde by it you get the unit you transformed From.
 */
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
 * @brief This Macro Defines the Number of the Units that Can be Converted by the application in the  Time.
 */
#define TimeUnitsNumbers 6
/**
 * @defgroup Time Units
 * @brief   Macros to distinguish between the Time Macros
 * @{
 */

/**
 * @brief This Macro Defines the Millisecond Unit The Time value measured in.
 */

#define Millisecond 0
/**
 * @brief This Macro Defines the Second Unit The Time value measured in.
 */

#define Second 1
/**
 * @brief This Macro Defines the Minute Unit The Time value measured in.
 */

#define Minute 2
/**
 * @brief This Macro Defines the Hour Unit The Time value measured in.
 */

#define Hour 3
/**
 * @brief This Macro Defines the Day Unit The Time value measured in.
 */

#define Day 4
/**
 * @brief This Macro Defines the Week Unit The Time value measured in.
 */
#define Week 5
/**
 * @}
 */
/**
 * @defgroup Time_symbols
 * @brief   Macros to have the units in symbols
 * @{
 */

#define Millisecond_Symb "ms"

#define Second_Symb "s"

#define Minute_Symb "min"

#define Hour_Symb "h"
#define Day_Symb "d"
#define Week_Symb "wk"

/**
 * @}
 */
/**
 * @defgroup Time Conversions
 * @brief   Macros to Define transitions From Other Units to Second
 * @{

 */
/**
 * @brief This Macro Defines the Multiplied value to return to Second and when divde by it you get the unit you transformed From.
 */

#define Second_To_Second 1
/**
 * @brief This Macro Defines the Multiplied value to return to Second and when divde by it you get the unit you transformed From.
 */

#define MilliSecond_To_Second .001
/**
 * @brief This Macro Defines the Multiplied value to return to Second and when divde by it you get the unit you transformed From.
 */

#define Minute_To_Second 60
/**
 * @brief This Macro Defines the Multiplied value to return to Second and when divde by it you get the unit you transformed From.
 */

#define Hour_To_Second 3600
/**
 * @brief This Macro Defines the Multiplied value to return to Second and when divde by it you get the unit you transformed From.
 */

#define Day_To_Second 86400
/**
 * @brief This Macro Defines the Multiplied value to return to Second and when divde by it you get the unit you transformed From.
 */
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
 * @brief This Macro Defines the Number of the Units that Can be Converted by the application in the length.
  Digital_Storage
  */

#define Digital_StoragUnitsNumbers 6
/**
 * @defgroup Digital_Storage Units
 * @brief   Macros to distinguish between the Digital_Storage Macros
 * @{

 */
/**
 * @brief This Macro Defines the Bit Unit The Digital_Storage value measured in.
 */
#define Bit 0
/**
 * @brief This Macro Defines the Byte Unit The Digital_Storage value measured in.
 */

#define Byte 1
/**
 * @brief This Macro Defines the Kilobyte Unit The Digital_Storage value measured in.
 */

#define Kilobyte 2
/**
 * @brief This Macro Defines the Megabyte Unit The Digital_Storage value measured in.
 */

#define Megabyte 3
/**
 * @brief This Macro Defines the Gigabyte Unit The Digital_Storage value measured in.
 */

#define Gigabyte 4
/**
 * @brief This Macro Defines the Terabyte Unit The Digital_Storage value measured in.
 */
#define Terabyte 5
/**
 * @}
 */
/**
 * @defgroup Digital_Storage_symbols
 * @brief   Macros to have the units in symbols
 * @{
 */

#define Bit_Symb "b(bit)"

#define Byte_Symb "B(Byte)"

#define Kilobyte_Symb "kB"

#define Megabyte_Symb "MB"
#define Gigabyte_Symb "GB"
#define Terabyte_Symb "TB"

/**
 * @}
 */
/**
 * @defgroup Digital_Storage Conversions
 * @brief   Macros to Define transitions From Other Units to Second
 * @{

 */
/**
 * @brief This Macro Defines the Multiplied value to return to Byte and when divde by it you get the unit you transformed From.
 */

#define Byte_To_Byte 1
/**
 * @brief This Macro Defines the Multiplied value to return to Byte and when divde by it you get the unit you transformed From.
 */
#define Bit_To_Byte 0.125
/**
 * @brief This Macro Defines the Multiplied value to return to Byte and when divde by it you get the unit you transformed From.
 */

#define Kilobyte_To_Byte 1024
/**
 * @brief This Macro Defines the Multiplied value to return to Byte and when divde by it you get the unit you transformed From.
 */

#define Megabyte_To_Byte 1048576
/**
 * @brief This Macro Defines the Multiplied value to return to Byte and when divde by it you get the unit you transformed From.
 */

#define Gigabyte_To_Byte 1073741824
/**
 * @brief This Macro Defines the Multiplied value to return to Byte and when divde by it you get the unit you transformed From.
 */
#define Terabyte_To_Byte 1099511627776
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
 * @brief This Macro Defines the Number of the Units that Can be Converted by the application in the  Speed.
 */
#define SpeedUnitsNumbers 3
/**
 * @defgroup Speed Units
 * @brief   Macros to distinguish between the Speed Macros
 * @{

/**
 * @brief This Macro Defines the MeterPerSec Unit The Speed value measured in.
*/

#define MeterPerSec 0
/**
 * @brief This Macro Defines the KMPerHr Unit The Speed value measured in.
 */

#define KMPerHr 1
/**
 * @brief This Macro Defines the Milesperhour Unit The Speed value measured in.
 */
#define Milesperhour 2
/**
 * @}
 */
/**
 * @defgroup Speed_symbols
 * @brief   Macros to have the units in symbols
 * @{
 */

#define MeterPerSec_Symb "m/s"

#define KMPerHr_Symb "km/h"

#define Milesperhour_Symb "mph"

/**
 * @}
 */
/**
 * @defgroup Speed Conversions
 * @brief   Macros to Define transitions From Other Units to Meter Per Second
 * @{

 */

/**
 * @brief This Macro Defines the Multiplied value to return to Meter Per Sec and when divde by it you get the unit you transformed From.
 */

#define MeterPerSec_To_MeterPerSec 1

/**
 * @brief This Macro Defines the Multiplied value to return to Meter Per Sec and when divde by it you get the unit you transformed From.
 */

#define KMPerHr_To_MeterPerSec 0.277778

/**
 * @brief This Macro Defines the Multiplied value to return to Meter Per Sec and when divde by it you get the unit you transformed From.
 */
#define Milesperhour_To_MeterPerSec 0.44704

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
 * @brief This Macro Defines the Number of the Units that Can be Converted by the application in the length Temprature
 */
#define TempratureUnitsNumbers 3
/**
 * @defgroup Temprature Units
 * @brief   Macros to distinguish between the Temprature Macros
 * @{

 */
/**
 * @brief This Macro Defines the Fahrenheit Unit The Temprature value measured in.
 */

#define Fahrenheit 0
/**
 * @brief This Macro Defines the Celsius Unit The Temprature value measured in.
 */

#define Celsius 1
/**
 * @brief This Macro Defines the Kelvin Unit The Temprature value measured in.
 */
#define Kelvin 2
/**
 * @}
 */
/**
 * @defgroup Temprature_symbols
 * @brief   Macros to have the units in symbols
 * @{
 */

#define Fahrenheit_Symb "F"

#define Celsius_Symb "C"

#define Kelvin_Symb "K"

/**
 * @defgroup Temprature Conversions
 * @brief   Macros to Define transitions From Other Units to Celsius
 * @{

 */

/**
 * @brief This Macro Defines the Multiplied value to return to Celesius From Celesius.
 * @note This does not mean when Divding By it you return it to Celsius.
 */

#define Celsius_To_Celsius(Value) ((Value) * 1)
/**
 * @brief This Macro Defines the Multiplied value to return to Celesius From Kelving.
 * @note This does not mean when Divding By it you return it to Kelvin.
 */

#define Fahrenheit_To_Celsius(Value) ((Value - 32) * 5. / 9.)
/**
 * @brief This Macro Defines the Multiplied value to return to Celesius From Kelving.
 * @note This does not mean when Divding By it you return it to Kelvin.
 */

#define Kelvin_To_Celsius(Value) (Value - 273.15)
/**
 * @brief This Macro Defines the Multiplied value to return to Fahrenheit.
 * @note This does not mean when Divding By it you return it to Fahrenheit.
 */

#define Celsius_To_Fahrenheit(Value) ((Value * 9. / 5.) + 32)
/**
 * @brief This Macro Defines the Multiplied value to return to Kelvin.
 * @note This does not mean when Divding By it you return it to kevlin.
 */
#define Celsius_To_Kelvin(Value) (Value + 273.15)
/**
 * @}
 */
/**
 * @}
 */
#endif