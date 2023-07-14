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
	//대문자로 변환, 소문자로 변환
	{
		FString str(TEXT("rabbit"));
		FString result = str.ToUpper();
		TestEqual(TEXT("FAIL result : change Upper"), result, TEXT("RABBIT"));

		result = str.ToLower();
		TestEqual(TEXT("FAIL result : change Lowwer"), result, TEXT("rabbit"));
	}
	//Operator 사용하기
	{
		FString str1(TEXT("rabbit"));
		FString str2(TEXT("jump"));
		TestEqual(TEXT("FAIL result : size operator"), true , str1 > str2);
	}
	//Printf 사용하기
	{
		FString str(TEXT("rabbit"));
		int miter = 1;
		TestEqual(TEXT("FAIL result : Printf"), FString::Printf(TEXT("%s can jump %d miter"), *str,  miter), TEXT("rabbit can jump 1 miter"));
	}

	/*FString strChar("char");
	FString strWChar(L"wchar");
	FString strTChar(TEXT("wchar"));
		
	strChar = "char";
	strWChar = "wchar";
	strTChar = TEXT("wchar");*/

	

	return true;
}


//	//TArray<int32> ValArr;
//int32 Temp[] = { 10, 20, 30, 5, 10, 15, 20, 25, 30 };
//ValArr.Append(Temp, ARRAY_COUNT(Temp));
//// ValArr == [10,20,30,5,10,15,20,25,30]
//
//ValArr.Remove(20);
// ValArr == [10,30,5,10,15,25,30] 

