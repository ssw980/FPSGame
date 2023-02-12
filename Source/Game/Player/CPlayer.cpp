#include "CPlayer.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "CPlayer_AnimInstance.h"

ACPlayer::ACPlayer()
{
	PrimaryActorTick.bCanEverTick = true;

	ConstructorHelpers::FObjectFinder<USkeletalMesh> meshAsset(TEXT("SkeletalMesh'/Game/SCK_Casual01/Models/Premade_Characters/MESH_PC_02.MESH_PC_02'"));
	if (meshAsset.Succeeded())
		GetMesh()->SetSkeletalMesh(meshAsset.Object);

	GetMesh()->SetRelativeRotation(FRotator(0,-90,0));
	GetMesh()->SetRelativeLocation(FVector(0,0,-90));

	ConstructorHelpers::FClassFinder<UCPlayer_AnimInstance> animClass(TEXT("AnimBlueprint'/Game/Player/ABP_CPlayer.ABP_CPlayer_C'"));
	if(animClass.Succeeded())
		GetMesh()->SetAnimInstanceClass(animClass.Class);

	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	SpringArm->SetupAttachment(GetCapsuleComponent());
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(SpringArm);

	SpringArm->SetRelativeLocation(FVector(0, 0, 100));
	SpringArm->TargetArmLength = 300.f;
	SpringArm->bDoCollisionTest = true;
	SpringArm->bUsePawnControlRotation = true;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	bUseControllerRotationYaw = false;
	
}

void ACPlayer::BeginPlay()
{
	Super::BeginPlay();
	
	
}

void ACPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward",this,&ACPlayer::OnMoveForward);
	PlayerInputComponent->BindAxis("MoveRight",this,&ACPlayer::OnMoveRight);
	PlayerInputComponent->BindAxis("HorizontalLook",this,&ACPlayer::OnHorizontalLook);
	PlayerInputComponent->BindAxis("VerticalLook",this,&ACPlayer::OnVerticalLook);


	PlayerInputComponent->BindAction("Jump",EInputEvent::IE_Pressed, this,&ACPlayer::OnJump);
}

void ACPlayer::OnMoveForward(float InAxis)
{
	FRotator yaw = FRotator(0, GetControlRotation().Yaw, 0);
	FVector direction = FQuat(yaw).GetForwardVector();
	

	AddMovementInput(direction,InAxis);

}

void ACPlayer::OnMoveRight(float InAxis)
{
	FRotator yaw = FRotator(0, GetControlRotation().Yaw, 0);
	FVector direction = FQuat(yaw).GetRightVector();


	AddMovementInput(direction, InAxis);
}

void ACPlayer::OnHorizontalLook(float InAxis)
{
	AddControllerYawInput(InAxis);
}

void ACPlayer::OnVerticalLook(float InAxis)
{
	AddControllerPitchInput(InAxis);
}

void ACPlayer::OnJump()
{
	Jump();
}
