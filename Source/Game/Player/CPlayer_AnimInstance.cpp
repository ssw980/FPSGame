#include "CPlayer_AnimInstance.h"
#include "CPlayer.h"
#include "Kismet/KismetMathLibrary.h"

void UCPlayer_AnimInstance::NativeBeginPlay()
{
	player = Cast<ACPlayer>(TryGetPawnOwner());
}

void UCPlayer_AnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	if (player == nullptr) return;
	Speed = player->GetVelocity().Size2D();

	
}
