#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CPlayer_AnimInstance.generated.h"

UCLASS()
class GAME_API UCPlayer_AnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	

public:
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	
	virtual void NativeBeginPlay()override;

protected:
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Anim")
		float Speed;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Anim")
		bool falling;

private:
	class ACPlayer* player;


};
