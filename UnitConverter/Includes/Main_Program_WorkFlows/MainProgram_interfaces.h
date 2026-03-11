#ifndef _MAINPROGRAM_INTERFACE_H_
#define _MAINPROGRAM_INTERFACE_H_

#include <stdint.h>
#include "../UnitConvertionImplementation/UnitConverter_Interface.h"
/**
 * 
 */
void WelcomingAndQuantityAsking(uint8_t *Choice);
void TakingInputFromUser(Unit *ToBeConverted);

void LengthCoversion(Unit *ToBeConverted);
void MassCoversion(Unit *ToBeConverted);
void VolumeCoversion(Unit *ToBeConverted);
void TimeCoversion(Unit *ToBeConverted);
void Digital_StorageCoversion(Unit *ToBeConverted);
void SpeedCoversion(Unit *ToBeConverted);
void TempratureCoversion(Unit *ToBeConverted);
void ExitProgram();

#endif