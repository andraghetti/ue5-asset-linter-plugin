// Copyright 2019-2020 Gamemakin LLC. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"

#include "LintRules/LintRule_Blueprint_Base.h"

#include "LintRule_IsNamedCorrectly_Base.generated.h"


UCLASS(BlueprintType, Blueprintable, Abstract)
class LINTER_API ULintRule_IsNamedCorrectly_Base : public ULintRule
{
    GENERATED_BODY()

public:
    explicit ULintRule_IsNamedCorrectly_Base(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

    UFUNCTION(BlueprintCallable, Category="Lint")
    static FString BuildSuggestedName(FString CurrentName, FString DesiredPrefix, FString DesiredSuffix = TEXT(""));

protected:
    virtual bool PassesRule_Internal_Implementation(UObject* ObjectToLint, const ULintRuleSet* ParentRuleSet, TArray<FLintRuleViolation>& OutRuleViolations) const override;
};
