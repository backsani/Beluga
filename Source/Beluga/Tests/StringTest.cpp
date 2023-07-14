#include "BelugaMinimal.h"
#include "Misc/AutomationTest.h"


IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaStringTest, "Beluga.String", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FBelugaStringTest::RunTest(const FString& Parameters)
{
	{
		TestTrue(TEXT("Always FAIL"), false);

	}
	//길이 구하기
	{
		FString str(TEXT("apple"));
		int result = str.Len();
		if(result == 5)
			TestTrue(TEXT("5"), true);
		else
			TestTrue(TEXT("FAIL result : LenFun"), false);
	}
	//Left 사용하기
	{
		FString str(TEXT("rabbit"));
		FString result = str.Left(3);
		TestEqual(TEXT("FAIL result : LeftFun"), result, "rab");
		
	}
	//mid 사용하기
	{
		FString str(TEXT("rabbit"));
		FString result = str.Mid(2,3);
		TestEqual(TEXT("FAIL result : MidFun"), result, "bbi");

	}
	//Right 사용하기
	{
		FString str(TEXT("rabbit"));
		FString result = str.Right(3);
		TestEqual(TEXT("FAIL result : RightFun"), result, "bit");

	}
	//Replace 사용하기
	{
		FString str(TEXT("rabbit"));
		FString result = str.Replace(TEXT("rabbit"), TEXT("apple"));
		TestEqual(TEXT("FAIL result : ReplaceFun"), result, "apple");

	}
	//Insert 사용하기
	{
		FString str(TEXT("rabbit "));
		str.InsertAt(7, TEXT("jump"));
		TestEqual(TEXT("FAIL result : InsertFun"), str, "rabbit jump");
	}
	//Split 사용하기
	{
		FString str(TEXT("rabbit jump"));
		TArray<FString> strArray;
		strArray.AddDefaulted(2);
		str.Split(TEXT(" "), &strArray[0], &strArray[1]);
		TestEqual(TEXT("FAIL result : SplitFun"), strArray[0], "rabbit");
		TestEqual(TEXT("FAIL result : SplitFun"), strArray[1], "jump");
	}
	//IsEmpty 사용하기
	{
		FString str(TEXT("rabbit jump"));
		TestEqual(TEXT("FAIL result : IsEmptyFun"), str.IsEmpty(), false);
	}
	//RemoveAt 사용하기 
	{
		FString str(TEXT("rabbit"));
		str.RemoveAt(2,2);
		TestEqual(TEXT("FAIL result : RemoveAtFun"), str, "rait");

	}
	//Find 사용하기 
	{
		FString str(TEXT("rabbit"));
		int result = str.Find("b");
		TestEqual(TEXT("FAIL result : RemoveAtFun"), result, 2);

	}
	/*
	FString OriginalString = "Hello World! Welcome to Unreal Engine";
	TArray<FString> SplitArray;
	OriginalString.Split(SplitArray, TEXT(" "), ESearchCase::CaseSensitive, ESearchDir::FromStart);

	*/
	//Shrink 사용하기
	/*{
		FString str(TEXT("rabbit"));
		str.Shrink();
		TestEqual(TEXT("FAIL result : rabbit"), str, "rabbit");
	}*/

	//		AddError(FString::Printf(TEXT("Expected '%s' to be true."), What), 1);
	//		TestEqual(TEXT("Operator []"), strApple[0], L'A');


	/*FString strChar("char");
	FString strWChar(L"wchar");
	FString strTChar(TEXT("wchar"));
		
	strChar = "char";
	strWChar = "wchar";
	strTChar = TEXT("wchar");*/

	

	return true;
}

// 생성
		// char		"asdf"
		// wchar	L"asdf"
		// tchar	TEXT("asdf")

	// 대입 연산자 = 

	// Printf

	// Format
		// FStringFormatNamedArguments
		// FStringFormatOrderedArguments

	// operator []

	// 대소비교

	// TCHAR* 얻기
	// operator*

	// 길이 구하기

	// Replace

	// Insert

	// clear

	// Split

	// IsEmpty

	// Shrink

//	//TArray<int32> ValArr;
//int32 Temp[] = { 10, 20, 30, 5, 10, 15, 20, 25, 30 };
//ValArr.Append(Temp, ARRAY_COUNT(Temp));
//// ValArr == [10,20,30,5,10,15,20,25,30]
//
//ValArr.Remove(20);
// ValArr == [10,30,5,10,15,25,30] 

	//RemoveAt

	// find 로 인덱스

	

	// 대문자로 변환, 소문자로 변환

// Printf
// Format
	//FStringFormatNamedArguments
	//FStringFormatOrderedArguments





























//IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaStringTest, "Beluga.String", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)
//
//bool FBelugaStringTest::RunTest(const FString& Parameters)
//{
//	// 생성, 대입
//	{
//		FString strChar("char");
//		FString strWChar(L"wchar");
//		FString strTChar(TEXT("wchar"));
//
//		strChar = "char";
//		strWChar = "wchar";
//		strTChar = TEXT("wchar");
//	}
//
//	// Printf
//	{
//		TestEqual(TEXT("Printf"), FString::Printf(TEXT("%d %f %s"), 123, 1.0f, TEXT("string")), TEXT("123 1.000000 string"));
//	}
//
//	// Format
//	{
//		{
//			FStringFormatNamedArguments NamedArgs;
//			NamedArgs.Add(TEXT("First"), 123);
//			NamedArgs.Add(TEXT("Second"), 1.0f);
//			NamedArgs.Add(TEXT("Third"), TEXT("string"));
//
//			TestEqual(TEXT("FormatNamedArguments"), FString::Format(TEXT("{First} {Second} {Third}"), NamedArgs), TEXT("123 1.000000 string"));
//		}
//		
//		{
//			FStringFormatOrderedArguments OrderedArgs;
//			OrderedArgs.Add(123);
//			OrderedArgs.Add(1.0f);
//			OrderedArgs.Add(TEXT("string"));
//			
//			TestEqual(TEXT("FormatOrderedArgs"), FString::Format(TEXT("{0} {1} {2}"), OrderedArgs), TEXT("123 1.000000 string"));
//		}
//	}
//
//	FString strApple(TEXT("Apple"));
//	FString strBanana(TEXT("Banana"));
//
//	// Operators
//	{
//		// []
//		{
//			TestEqual(TEXT("Operator []"), strApple[0], L'A');
//		}
//
//		// < >
//		{
//			TestTrue(TEXT("Operator <"), strApple < strBanana);
//		}
//	}
//
//	return true;
//}
//
//IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaNameTest, "Beluga.Name", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)
//
//bool FBelugaNameTest::RunTest(const FString& Parameters)
//{
//	return true;
//}