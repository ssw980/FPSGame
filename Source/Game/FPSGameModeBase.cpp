#include "FPSGameModeBase.h"
#include "Player/CPlayer.h"

AFPSGameModeBase::AFPSGameModeBase()
{
	 ConstructorHelpers::FClassFinder<APawn> pawnClass(TEXT("Blueprint'/Game/Player/BP_CPlayer.BP_CPlayer_C'"));

	 if(pawnClass.Succeeded())
	 DefaultPawnClass = pawnClass.Class;
}