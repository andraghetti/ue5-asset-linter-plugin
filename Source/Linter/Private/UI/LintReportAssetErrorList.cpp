// Copyright 2019-2020 Gamemakin LLC. All Rights Reserved.

#include "UI/LintReportAssetErrorList.h"

#include "LintRule.h"
#include "LinterStyle.h"
#include "UI/LintReportAssetError.h"

#include "EditorStyleSet.h"
#include "Framework/Views/ITypedTableView.h"
#include "IContentBrowserSingleton.h"
#include "Widgets/Views/SListView.h"

#define LOCTEXT_NAMESPACE "LintReport"

void SLintReportAssetErrorList::Construct(const FArguments& Args)
{
	RuleViolations = Args._RuleViolations;
	const float PaddingAmount = FLinterStyle::Get()->GetFloat("Linter.Padding");

	ChildSlot
	[
		SNew(SListView<TSharedPtr<FLintRuleViolation>>)
		.SelectionMode(ESelectionMode::None)
		.ListItemsSource(&RuleViolations.Get())
		.OnGenerateRow_Lambda([&](TSharedPtr<FLintRuleViolation> InItem, const TSharedRef<STableViewBase>& OwnerTable)
		{
		return SNew(STableRow<TSharedPtr<FLintRuleViolation>>, OwnerTable)
			[
				SNew(SLintReportAssetError)
				.RuleViolation(InItem)
			];
		})
	];
}
