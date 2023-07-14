#include "BelugaMinimal.h"
#include "Misc/AutomationTest.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaVectorTest, "Beluga.Vector", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FBelugaVectorTest::RunTest(const FString& Parameters)
{

	FVector vec(0.0, 1.0, 0.0);
	vec.X = 2.0;
	TestEqual(TEXT("X"), vec, FVector(2.0, 1.0, 0.0));

	vec.Y = 5.0;
	TestEqual(TEXT("Y"), vec, FVector(2.0, 5.0, 0.0));

	TestEqual(TEXT("Operator"), vec + vec, FVector(4.0, 10.0, 0.0));
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaRotatorTest, "Beluga.Rotator", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FBelugaRotatorTest::RunTest(const FString& Parameters) 
{
	

	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaMatrixTest, "Beluga.Matrix", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FBelugaMatrixTest::RunTest(const FString& Parameters) {
	FMatrix mat = FMatrix::Identity;

	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaTransformTest, "Beluga.Transform", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FBelugaTransformTest::RunTest(const FString& Parameters) {
	FTransform mat = FTransform::Identity;

	return true;
}
