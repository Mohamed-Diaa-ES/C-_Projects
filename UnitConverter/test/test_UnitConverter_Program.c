#include "unity.h"
#include "unity_internals.h"
#include <float.h> // Required for DBL_MAX
#include "../Includes/UnitConvertionImplementation/UnitConverter_Interface.h"
#include "../Includes/Main_Program_WorkFlows/MainProgram_interfaces.h"
#include "../Includes/Macros.h"
TEST_SOURCE_FILE("UnitConverter_Program.c")
TEST_SOURCE_FILE("MainProgram_Program.c")

void setUp() {}
void tearDown() {}

void test_ToMeters_Should_FailAndPreserveData_WhenGivenMass()
{
    // Arrange
    Unit testUnit = {55.5, KiloGrams, Mass};

    // Act
    uint8_t status = ToMeters(&testUnit);

    // Assert
    TEST_ASSERT_EQUAL(Quanitity_MissMatch, status);
    TEST_ASSERT_EQUAL(55.5, testUnit.Value);
    TEST_ASSERT_EQUAL(KiloGrams, testUnit.UnitType); // Unit must not change
}

void test_ToKiloGrams_Should_FailAndPreserveData_WhenGivenVolume()
{
    // Arrange: Valid Volume data, invalid for Mass
    Unit testUnit = {10, Liter, Volume};

    // Act
    uint8_t status = ToKiloGrams(&testUnit);

    // Assert
    TEST_ASSERT_EQUAL(Quanitity_MissMatch, status);
    TEST_ASSERT_EQUAL(10, testUnit.Value);
    TEST_ASSERT_EQUAL(Liter, testUnit.UnitType);
}

void test_ToCelsius_Should_FailAndPreserveData_WhenGivenTime()
{
    // Arrange: Valid Time data, invalid for Temperature
    Unit testUnit = {3600, Hour, Time};

    // Act
    uint8_t status = ToCelsius(&testUnit);

    // Assert
    TEST_ASSERT_EQUAL(Quanitity_MissMatch, status);
    TEST_ASSERT_EQUAL(3600, testUnit.Value);
    TEST_ASSERT_EQUAL(Hour, testUnit.UnitType);
}

void test_ToMegabyte_Should_FailAndPreserveData_WhenGivenSpeed()
{
    // Arrange: Valid Speed data, invalid for Digital Storage
    Unit testUnit = {100, KMPerHr, Speed};

    // Act
    uint8_t status = ToMegabyte(&testUnit);

    // Assert
    TEST_ASSERT_EQUAL(Quanitity_MissMatch, status);
    TEST_ASSERT_EQUAL(100, testUnit.Value);
    TEST_ASSERT_EQUAL(KMPerHr, testUnit.UnitType);
}


void test_ToMeters_Should_HandleNullPointerSafely()
{
    uint8_t status = ToMeters(NULL);
    TEST_ASSERT_EQUAL(NullCrashing, status);
}


void test_ToMeters_Should_FailAndPreserveData_WhenLengthIsNegative()
{
    // Arrange: Length cannot be negative
    Unit testUnit = {-5.5, CM, Length};

    // Act
    uint8_t status = ToMeters(&testUnit);

    // Assert
    TEST_ASSERT_EQUAL(Physical_Logic_Error, status);

    TEST_ASSERT_EQUAL(CM, testUnit.UnitType);
}

void test_ToKiloGrams_Should_FailAndPreserveData_WhenMassIsNegative()
{
    // Arrange: Mass cannot be negative
    Unit testUnit = {-10, Pound, Mass};

    // Act
    uint8_t status = ToKiloGrams(&testUnit);

    // Assert
    TEST_ASSERT_EQUAL(Physical_Logic_Error, status);

    TEST_ASSERT_EQUAL(Pound, testUnit.UnitType);
}

void test_ToCelsius_Should_FailAndPreserveData_WhenKelvinIsBelowAbsoluteZero()
{
    // Arrange: Kelvin cannot drop below 0
    Unit testUnit = {-1, Kelvin, Temprature};

    // Act
    uint8_t status = ToCelsius(&testUnit);

    // Assert
    TEST_ASSERT_EQUAL(Physical_Logic_Error, status);

    TEST_ASSERT_EQUAL(Kelvin, testUnit.UnitType);
}

void test_ToFahrenheit_Should_FailAndPreserveData_WhenCelsiusIsBelowAbsoluteZero()
{
    // Arrange: Celsius cannot drop below -273.15
    Unit testUnit = {-274, Celsius, Temprature};

    // Act
    uint8_t status = ToFahrenheit(&testUnit);

    // Assert
    TEST_ASSERT_EQUAL(Physical_Logic_Error, status);

    TEST_ASSERT_EQUAL(Celsius, testUnit.UnitType);
}

void test_ToBit_Should_CalculateFractionalBits_WhenGivenFractionalBytes()
{
    //Arrange
    Unit testUnit = {1.2, Byte, Digital_Storage};

    // Act
    uint8_t status = ToBit(&testUnit);
    // Assert
    TEST_ASSERT_EQUAL(Transformation_Done, status);
    TEST_ASSERT_EQUAL(((int)1.2/Bit_To_Byte),testUnit.Value );
    
    testUnit.UnitType =Byte ;
    testUnit.Value=5.36 ;
    ToBit(&testUnit);
    TEST_ASSERT_EQUAL(((int)5.36/Bit_To_Byte),testUnit.Value );
    
    
    testUnit.UnitType =Byte ;
    testUnit.Value=500 ;
    ToBit(&testUnit);
    TEST_ASSERT_EQUAL(((int)500/Bit_To_Byte),testUnit.Value );
    TEST_ASSERT_EQUAL(Bit, testUnit.UnitType);

}

void test_handleScanfproblems_Should_PassQuietly_WhenInputIsValid(void)
{
    // Arrange
    uint8_t expected_inputs_read = 2;
    uint8_t actual_inputs_read = 2; 

    // Act
    handleScanfproblems(actual_inputs_read, expected_inputs_read);
    
    // Assert
    //void function LOL
}
void test_LengthCoversion_Should_RouteToMeters_WhenUserSelectedMeters(void)
{
    // Arrange: Create a struct that simulates what happens AFTER user input
    Unit testUnit;
    testUnit.Value = 100.0;
    testUnit.UnitType = CM;         // Starting unit
    testUnit.MeasuredType = Length; 
    
    
    ToMeters(&testUnit);
    
    // Assert
    TEST_ASSERT_EQUAL(Meters, testUnit.UnitType);
}
#define Transformation_Failed 2
void test_ToMeters_Should_Fail_WhenMultiplicationCausesOverflow(void)
{
    // Arrange: Set value to the absolute maximum a 64-bit float can hold.
    Unit testUnit = {DBL_MAX, Miles, Length};
    
    // Act: Attempting to multiply DBL_MAX by 1609.344 will overflow.
    uint8_t status = ToMeters(&testUnit);
    
    TEST_ASSERT_EQUAL(Transformation_Failed, status); 
}