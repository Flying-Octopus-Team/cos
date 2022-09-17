#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Engine/DeveloperSettings.h"

#include "MovementData.generated.h"

UCLASS()
class COS_API UMovementData : public UDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float DefaultVelocityFactor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float CrouchVelocityFactor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float JumpInitialVelocity;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (ToolTip = "unit: [deg]"))
	float MaxPitchAngle = 100;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (ToolTip = "unit: [deg]"))
	float MinPitchAngle = 100;
};

UCLASS(config = Game, defaultconfig, meta = (DisplayName = "Main Character Movement settings"))
class COS_API UMainCharacterMovementSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UMovementData* GetMovementSettings() const;

private:
	UPROPERTY(config, EditAnywhere, Category = DataAssets, meta = (AllowedClasses = "MovementData"))
	TSoftObjectPtr<UMovementData> MovementDataAsset;
	
};
