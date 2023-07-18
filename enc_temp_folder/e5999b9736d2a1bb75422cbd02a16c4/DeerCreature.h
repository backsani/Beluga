#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DeerCreature.generated.h"

/** Please add a class description */
UCLASS(Blueprintable, BlueprintType, Abstract)
class BELUGA_API UDeerCreature : public UObject
{
	GENERATED_BODY()

//public:
//	UFUNCTION(BlueprintCallable)
//		void Init();

public:

	UFUNCTION(BlueprintCallable)
		FString CPP_Hello();

	UFUNCTION(BlueprintPure)
		FName CPP_GetName();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
		void BP_SetHelloMessage();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void BOTH_Update();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FString HelloMsg;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FName Name;
};