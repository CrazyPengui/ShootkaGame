// Shootka Game. All rights reserved!


#include "Menu/STUMenuPlayerController.h"
#include "Menu/STUMenuGameModeBase.h"
#include "Menu/UI/STUMenuHUD.h"

ASTUMenuGameModeBase::ASTUMenuGameModeBase()
{
	PlayerControllerClass = ASTUMenuPlayerController::StaticClass();
	HUDClass = ASTUMenuHUD::StaticClass();
}
