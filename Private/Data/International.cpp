#include "International.h"

#include "MenuHUD.h"
#include "Internationalization/StringTableRegistry.h"
#include "Kismet/GameplayStatics.h"

International::International()
{
	CurrenCulture = ECultureType::ZH;
	if(!FStringTableRegistry::Get().FindStringTable(FName("ENTable")).IsValid())
	LOCTABLE_FROMFILE_GAME("ENTable","ENNameSpace","Localization/English.csv");
	if(!FStringTableRegistry::Get().FindStringTable(FName("ZHTable")).IsValid())
	LOCTABLE_FROMFILE_GAME("ZHTable","ZHNameSpace","Localization/Chinese.csv");

}

void International::SetCulture(ECultureType::Type NewCulture)
{
	if(CurrenCulture==NewCulture)
		return;
	CurrenCulture = NewCulture;
	//修改菜单ui文本语种
	auto hud = Cast<AMenuHUD>(UGameplayStatics::GetPlayerController(GWorld,0)->GetHUD());
	if(hud) hud->UpdateUIText.ExecuteIfBound();
}

ECultureType::Type International::GetCulture()
{
	return CurrenCulture;
}

FName International::GetCultureAsFname()
{
	switch (CurrenCulture)
	{
		case ECultureType::ZH:
			return FName("ZHTable");
		case ECultureType::EN:
			return FName("ENTable");
	}
	return FName("ZHTable");
}

void International::ShutDown()
{
	if(FStringTableRegistry::Get().FindStringTable(FName("ZHTable")).IsValid())
	FStringTableRegistry::Get().UnregisterStringTable(FName("ZHTable"));
	if(FStringTableRegistry::Get().FindStringTable(FName("ENTable")).IsValid())
	FStringTableRegistry::Get().UnregisterStringTable(FName("ENTable"));
}
