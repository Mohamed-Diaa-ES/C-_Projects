#ifndef _MAINPROGRAM_INTERFACE_H_
#define _MAINPROGRAM_INTERFACE_H_

#include <stdint.h>
#include "../UnitConvertionImplementation/UnitConverter_Interface.h"
#include "../Macros.h"
/**
 * @fn       WelcomingAndQuantityAsking
 * @brief    Welcoming The User and ask him To choose the quantity.
 * @param    Choice Pointer to the quantity choice the user take from the function.
 */
void WelcomingAndQuantityAsking(uint8_t *Choice);
/**
 * @fn       TakingInputFromUser
 * @brief    takes the input of the unit wanted to be converted
 * @param    ToBeConverted Pointer to main input unit to be added.
 */
void TakingInputFromUser(Unit *ToBeConverted);
/**
 * @fn       LengthCoversion
 * @brief    Convert the length to the available option wanted to be used
 * @param    ToBeConverted Pointer to main input unit to be converted.
 */
void LengthCoversion(Unit *ToBeConverted);
/**
 * @fn       MassCoversion
 * @brief    Convert the Mass to the option wantted to be used
 * @param    ToBeConverted Pointer to main input unit to be converted.
 */
void MassCoversion(Unit *ToBeConverted);
/**
 * @fn       VolumeCoversion
 * @brief    Convert the Volumeto the option wantted to be used
 * @param    ToBeConverted Pointer to main input unit to be converted.
 */
void VolumeCoversion(Unit *ToBeConverted);
/**
 * @fn       TimeCoversion
 * @brief    Convert the Time to the option wantted to be used
 * @param    ToBeConverted Pointer to main input unit to be converted.
 */
void TimeCoversion(Unit *ToBeConverted);
/**
 * @fn       Digital_StorageCoversion
 * @brief    Convert the Digital_Storage to the option wantted to be used
 * @param    ToBeConverted Pointer to main input unit to be converted.
 */
void Digital_StorageCoversion(Unit *ToBeConverted);
/**
 * @fn       SpeedCoversion
 * @brief    Convert the Speed to the option wantted to be used
 * @param    ToBeConverted Pointer to main input unit to be converted.
 */
void SpeedCoversion(Unit *ToBeConverted);
/**
 * @fn       TempratureCoversion
 * @brief    Convert the Temprature to the option wantted to be used
 * @param    ToBeConverted Pointer to main input unit to be converted.
 */
void TempratureCoversion(Unit *ToBeConverted);
/**
 * @fn       ExitProgram
 * @brief    Show a message before getting out of the app
 */
void ExitProgram();
/**
 * @fn       clearScreen
 * @brief    It clears the screen of the system
 */
void clearScreen();
/**
 * @fn      IsUserProceeding
 * @brief   Asks the user if he is continuing to use the app after the conversion
 */
signed char IsUserProceeding();
/**
 * @fn      handleScanfproblems
 * @brief   it handles the scanf problems that could occur when invalid input is Entered
 * @param    valid          This is the returned value of the scanf function to know if the system is valid.
 * @param    howManyInputs  This is used to know how many inputs scanf should read to use in detecting possible Errors.
 */
void handleScanfproblems(uint8_t valid,uint8_t howManyInputs);



#endif