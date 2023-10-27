#include "FortPlayerMannequin.h"

#include "FortHeroType.h"
#include "Components/SkeletalMeshComponent.h"

void AFortPlayerMannequin::UpdateMorphTargets() {
}

void AFortPlayerMannequin::ToggleGenderBP() {
}

bool AFortPlayerMannequin::SetWeaponSkeletalMesh(USkeletalMesh* SkeletalMesh) {
    return false;
}

void AFortPlayerMannequin::SetSkeletalMesh(USkeletalMesh* SkeletalMesh) {
}

bool AFortPlayerMannequin::SetPart(EFortCustomPartType Part, UCustomCharacterPart* PartAsset) {
    return false;
}

void AFortPlayerMannequin::SetHeroType(UFortHeroType* NewHeroType) {
}

void AFortPlayerMannequin::SetAthenaCharacterDefAndVariants(UAthenaCharacterItemDefinition* NewAthenaCharacter, const TArray<FMcpVariantChannelInfo>& InOverrideVariants) {
}

bool AFortPlayerMannequin::RemovePart(EFortCustomPartType Part) {
    return false;
}

USkeletalMeshComponent* AFortPlayerMannequin::GetPartSkeletalMeshComponent(EFortCustomPartType Part) const {
    return NULL;
}

EFortCustomGender AFortPlayerMannequin::GetGender() const {
    return CurrentFortHeroType->Gender;
}

void AFortPlayerMannequin::GetAllPartSkeletalMeshComponents(TArray<USkeletalMeshComponent*>& SkeletalMeshComponents) {
}

bool AFortPlayerMannequin::CyclePartBP(EFortCustomPartType Part, bool bNextPart) {
    return false;
}

AFortPlayerMannequin::AFortPlayerMannequin() {
    this->CurrentFortHeroType = NULL;
    this->AthenaCharacter = NULL;
    this->AthenaBackBling = NULL;
    this->CharacterParts[0] = NULL;
    this->CharacterParts[1] = NULL;
    this->CharacterParts[2] = NULL;
    this->CharacterParts[3] = NULL;
    this->CharacterParts[4] = NULL;
    this->CharacterParts[5] = NULL;
    this->CharacterParts[6] = NULL;
    this->MannequinBoundsScale = 1.00f;
    this->bIsMannequinVisible = true;
    this->bMannequinCastsHiddenShadow = false;
    this->CharacterPartList[0] = NULL;
    this->CharacterPartList[1] = NULL;
    this->CharacterPartList[2] = NULL;
    this->CharacterPartList[3] = NULL;
    this->CharacterPartList[4] = NULL;
    this->CharacterPartList[5] = NULL;
    this->CharacterPartColorSwatches[0] = NULL;
    this->CharacterPartColorSwatches[1] = NULL;
    this->CharacterPartColorSwatches[2] = NULL;
    this->CharacterPartColorSwatches[3] = NULL;
    this->CharacterPartColorSwatches[4] = NULL;
    this->CharacterPartColorSwatches[5] = NULL;
    this->CharacterPartColorSwatches[6] = NULL;
    this->ColorSwatchesForCharacterParts[0] = NULL;
    this->ColorSwatchesForCharacterParts[1] = NULL;
    this->ColorSwatchesForCharacterParts[2] = NULL;
    this->ColorSwatchesForCharacterParts[3] = NULL;
    this->ColorSwatchesForCharacterParts[4] = NULL;
    this->ColorSwatchesForCharacterParts[5] = NULL;
    this->AccessoryColorSwatchHandler[0] = NULL;
    this->AccessoryColorSwatchHandler[1] = NULL;
    this->AccessoryColorSwatchHandler[2] = NULL;
    this->AccessoryColorSwatchHandler[3] = NULL;
    this->AccessoryColorSwatchHandler[4] = NULL;
    this->AccessoryColorSwatchHandler[5] = NULL;
    this->ColorSwatches[0] = NULL;
    this->ColorSwatches[1] = NULL;
    this->WeaponSkeletalMesh = NULL;
    this->WeaponAttachSocket = TEXT("RightHand");
    this->bInitialized = false;
    CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Weapon"));
    CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("GameplayOne"));
    CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Face"));
    CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Charm"));
    CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Backpack"));
    CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Hat"));
    CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Body"));
    CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Head"));
    PrimaryActorTick.bCanEverTick = true;
}
#if WITH_EDITOR  
void AFortPlayerMannequin::OnConstruction(const FTransform & Transform)
{
	if (CurrentFortHeroType != nullptr)
	{
		for (TSoftObjectPtr<class UFortHeroSpecialization> SoftHeroSpecialization : CurrentFortHeroType->Specializations)
		{
			UFortHeroSpecialization* HeroSpecialization = SoftHeroSpecialization.Get();

			if (HeroSpecialization == nullptr)
			{
				HeroSpecialization = static_cast<UFortHeroSpecialization*>(SoftHeroSpecialization.ToSoftObjectPath().TryLoad());

				// If HeroSpecialization is finally loaded, let's attempt to Set Character Parts again.
				if (HeroSpecialization != nullptr)
				{
					SetPartsFromHeroSpecialization(HeroSpecialization);
				}
			}
			else
			{
				SetPartsFromHeroSpecialization(HeroSpecialization);
			}
		}
	}
}

void AFortPlayerMannequin::SetPartsFromHeroSpecialization(UFortHeroSpecialization* HeroSpecialization)
{
	// Reset the character parts
	ResetParts();

	// Loop thru character parts of providen HeroSpecialization
	int CharacterPartCurrentArrayIndex = -1;

	for (TSoftObjectPtr<class UCustomCharacterPart> SoftCharacterPart : HeroSpecialization->CharacterParts)
	{
		CharacterPartCurrentArrayIndex++;
		UCustomCharacterPart* CustomCharacterPart = SoftCharacterPart.Get();

		// If the character part pointer is null, try loading it
		if (CustomCharacterPart == nullptr)
		{
			CustomCharacterPart = static_cast<UCustomCharacterPart*>(SoftCharacterPart.ToSoftObjectPath().TryLoad());
		}

		EFortCustomPartType CharacterPartType = CustomCharacterPart->CharacterPartType;

		/* Remove old Character Part's that have nothing to do with this Hero Specialization */
		if (CharacterPartList[static_cast<int>(CharacterPartType)] != CustomCharacterPart)
		{
			CharacterPartList[static_cast<int>(CharacterPartType)] = nullptr;
		}
		if (CharacterParts[CharacterPartCurrentArrayIndex] != CustomCharacterPart)
		{
			CharacterPartList[CharacterPartCurrentArrayIndex] = nullptr;
		}

		/* Set Character Parts */
		CharacterPartList[static_cast<int>(CharacterPartType)] = CustomCharacterPart;
		CharacterParts[CharacterPartCurrentArrayIndex] = CustomCharacterPart;

		if (CustomCharacterPart != nullptr)
		{
			/* Create the mesh component */
			USkeletalMeshComponent* MeshComponent = NewObject<USkeletalMeshComponent>(this, "CharacterPartMeshComponent" + CharacterPartCurrentArrayIndex);
			MeshComponent->SetupAttachment(this->GetRootComponent());
			MeshComponent->RegisterComponent();

			/* Additional Data implementation */
			TSoftClassPtr<UAnimInstance> AnimClass = nullptr;
			FName AttachSocketName;
			UCustomAccessoryAttachmentData* AttachmentOverrideData;

			UCustomCharacterBodyPartData* BodyPartData = Cast<UCustomCharacterBodyPartData>(CustomCharacterPart->AdditionalData);

			if (BodyPartData) {
				AnimClass = BodyPartData->AnimClass;
			}

			UCustomCharacterAccessoryData* AccessoryData = Cast<UCustomCharacterAccessoryData>(CustomCharacterPart->AdditionalData);

			if (AccessoryData) {
				AnimClass = AccessoryData->AnimClass;
				AttachSocketName = AccessoryData->AttachSocketName;
				AttachmentOverrideData = AccessoryData->AttachmentOverrideData;

				MeshComponent->AttachTo(this->GetRootComponent(), AttachSocketName);
			}

			UClass* AnimClassSoftToHard = AnimClass.LoadSynchronous();
			if (AnimClass != nullptr) {
				MeshComponent->SetAnimInstanceClass(AnimClassSoftToHard);
			}

			/* Set skeletal mesh */
			USkeletalMesh* CharacterPartSkeletalMesh = CustomCharacterPart->SkeletalMesh.Get();

			if (CustomCharacterPart->SkeletalMesh.Get() == nullptr)
			{
				CharacterPartSkeletalMesh = static_cast<USkeletalMesh*>(CustomCharacterPart->SkeletalMesh.ToSoftObjectPath().TryLoad());
			}

			if (CharacterPartSkeletalMesh != nullptr)
			{
				MeshComponent->SetSkeletalMesh(CharacterPartSkeletalMesh, true);
			}
			for (const FCustomPartMaterialOverrideData& OverrideData : CustomCharacterPart->MaterialOverrides)
			{
				if (OverrideData.MaterialOverrideIndex >= 0 && OverrideData.MaterialOverrideIndex < CharacterPartSkeletalMesh->Materials.Num())
				{
					UMaterialInterface* NewMaterial = OverrideData.OverrideMaterial.LoadSynchronous();
					if (NewMaterial)
					{
						CharacterPartSkeletalMesh->Materials[OverrideData.MaterialOverrideIndex].MaterialInterface = NewMaterial;
					}
				}
			}
		}
	}
}

void AFortPlayerMannequin::ResetParts()
{
	/* Get all the children components of the master skeletal mesh */
	TArray<USceneComponent*> SceneComponents;
	this->GetRootComponent()->GetChildrenComponents(true, SceneComponents);

	for (auto Component : SceneComponents)
	{
		// Unregister the component
		Component->UnregisterComponent();
		// Remove it from root
		Component->RemoveFromRoot();
		// Destroy it
		Component->DestroyComponent();
	}
}
#endif


