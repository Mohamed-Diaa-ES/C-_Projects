#ifndef __UNIT_CONVERTER_H
#define __UNIT_CONVERTER_H
#include <stdint.h>



/**
 * @defgroup LengthFunctions
 * @brief    These are the Functions Declarations  and the structures for the length Conversions
 * @{ 
 */

typedef struct 
{
    
} LengthUnit;

float TransfromToMeters();
float TransfromToMiles();
float TransfromToCM();
float TransfromToKiloMeters();
float TransfromToInches();
float TransfromToYard();
float TransfromToMiles();
/**
 * @}
 */
/**
 * @defgroup Mass Functions
 * @brief    These are the Functions Declarations and the structures for the Mass Conversions
 * @{ 
 */
float TransfromToKiloGrams();
float TransfromToGrams();
float TransfromToTons();
float TransfromToOunces();
float TransfromToPound();
float TransfromToStone();
/**
 * @}
 */
#endif