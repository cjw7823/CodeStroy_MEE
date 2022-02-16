// Fill out your copyright notice in the Description page of Project Settings.


#include "ChattingWidget.h"
#include "Runtime/UMG/Public/UMG.h"
#include "Runtime/UMG/Public/UMGStyle.h" 
#include "Runtime/UMG/Public/Slate/SObjectWidget.h" 
#include "Runtime/UMG/Public/IUMGModule.h" 
#include "Runtime/UMG/Public/Blueprint/UserWidget.h"
#include "UMG/Public/Components/Button.h"

void UChattingWidget::NativeConstruct()
{
	Button_Send->OnClicked.AddDynamic(this, &UChattingWidget::OnClick_Send);
}

void UChattingWidget::OnClick_Send()
{
	//������ �޼����� �����ϴ� 'SendMessageToChannel'�Լ��� BP���� ȣ���Ѵ�.
	//JW_HUD���� connect server �Ѵ�.
	EditableText_Input->SetText(FText::GetEmpty());

	UTextBlock* NewTextBlock = NewObject<UTextBlock>(ScrollBox);
	NewTextBlock->SetText(FText::FromString(""));

	ScrollBox->AddChild(NewTextBlock);
	ScrollBox->ScrollToEnd();
}
