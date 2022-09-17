#include "MovementData.h"

UMovementData* UMainCharacterMovementSettings::GetMovementSettings() const
{
	return MovementDataAsset.LoadSynchronous();
}