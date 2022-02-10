// Copyright Epic Games, Inc. All Rights Reserved.


#include "Mee_HTTPGameModeBase.h"
#include "Blueprint/UserWidget.h"


AMee_HTTPGameModeBase::AMee_HTTPGameModeBase()
{
	static ConstructorHelpers::FClassFinder<ULoginWidget> StartWidgetClass(TEXT("WidgetBlueprint'/Game/LoginWidget.LoginWidget_C'"));

	PlayerControllerClass = AEntryPlayerController::StaticClass();

	if (StartWidgetClass.Succeeded())
	{
		LoginWidgetClass = StartWidgetClass.Class;
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(1, 2.0f, FColor::Blue, "StartWidgetClass.Failed");
	}


}

void AMee_HTTPGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	if (IsValid(LoginWidgetClass))
	{
		// ������ �����Ѵ�
		LoginWidget = CreateWidget<ULoginWidget>(GetWorld(), LoginWidgetClass);

		if (IsValid(LoginWidget))
		{
			// ������ ����Ʈ�� �߰��Ѵ�
			LoginWidget->AddToViewport();
		}
	}
}
