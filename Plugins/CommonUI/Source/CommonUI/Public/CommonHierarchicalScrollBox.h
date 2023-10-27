#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=UMG -ObjectName=ScrollBox -FallbackName=ScrollBox
#include "CommonHierarchicalScrollBox.generated.h"

UCLASS(Blueprintable)
class COMMONUI_API UCommonHierarchicalScrollBox : public UScrollBox {
    GENERATED_BODY()
public:
    UCommonHierarchicalScrollBox();
};

