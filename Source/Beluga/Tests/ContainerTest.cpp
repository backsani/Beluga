#include "BelugaMinimal.h"
#include "Misc/AutomationTest.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaArrayTest, "Beluga.Array", \
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FBelugaArrayTest::RunTest(const FString& Parameters)
{
	TArray<int32> arr;
	arr.Init(3,4);

	for(int i = 0; i < 4; i++)
		TestEqual(TEXT("FAIL result : Init"), arr[i], 3);
	//arr == [3,3,3,3]

	arr.Add(10);
	TestEqual(TEXT("FAIL result : Add"), arr[4], 10);
	//arr == [3,3,3,3,10]

	arr.Insert(5, 1);
	TestEqual(TEXT("FAIL result : Insert"), arr[1], 5);
	//arr == [3,5,3,3,3,10]

	int32 result = arr.Num();
	TestEqual(TEXT("FAIL result : Num"), result, 6);

	arr.Remove(3);
	for(int i = 0; i > 6; i++)
		TestEqual(TEXT("FAIL result : Remove"), arr[i], !3);
	//arr == [5, 10]

	arr.Add(4);
	//arr == [5, 10, 4]

	//5의 배수 지우기
	arr.RemoveAll( [] (int32 Val) {
		return Val % 5 == 0;
		});
	// arr == [4]

	TestEqual(TEXT("FAIL result : RemoveAll"), arr[0], 4);
	
	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaMapTest, "Beluga.Map", \
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)

	bool FBelugaMapTest::RunTest(const FString& Parameters)
{
	TMap<FName, FString> map = {{TEXT("A"), TEXT("Apple")}, { TEXT("B"), TEXT("Banana") }, { TEXT("C"), TEXT("Cherry") }};
	map.Add(TEXT("D"), TEXT("Durian"));

	TestEqual(TEXT("FAIL result : Map.Add"), map["D"], TEXT("Durian"));

	int32 result = map.Num();
	TestEqual(TEXT("FAIL result : Map.Num"), result, 4);

	FString* strA = map.Find("A");
	TestEqual(TEXT("FAIL result : Map.Find"), *strA, TEXT("Apple"));

	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaSetTest, "Beluga.Set", \
	EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)

	bool FBelugaSetTest::RunTest(const FString& Parameters)
{
	TSet<FString> set = {TEXT("Durian"), TEXT("Fig")};
	int32 startResult = set.Num();
	TestEqual(TEXT("FAIL result : Num"), startResult, 2);
	set.Add("Apple");
	set.Add("Banana");
	set.Add("Cherry");

	int32 result = set.Num();
	TestEqual(TEXT("FAIL result : Num"), result, 5);

	return true;
}