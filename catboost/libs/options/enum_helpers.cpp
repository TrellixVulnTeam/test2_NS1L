#include "enum_helpers.h"
#include <util/string/cast.h>

bool IsSupportedOnGpu(ELossFunction lossFunction) {
    switch (lossFunction) {
        case ELossFunction::RMSE:
        case ELossFunction::Logloss:
        case ELossFunction::CrossEntropy:
            return true;
        default:
            return false;
    }
}

bool IsClassificationLoss(ELossFunction lossFunction) {
    return (lossFunction == ELossFunction::Logloss ||
            lossFunction == ELossFunction::CrossEntropy ||
            lossFunction == ELossFunction::MultiClass ||
            lossFunction == ELossFunction::MultiClassOneVsAll ||
            lossFunction == ELossFunction::AUC ||
            lossFunction == ELossFunction::Accuracy ||
            lossFunction == ELossFunction::Precision ||
            lossFunction == ELossFunction::Recall ||
            lossFunction == ELossFunction::F1 ||
            lossFunction == ELossFunction::TotalF1 ||
            lossFunction == ELossFunction::MCC);
}

bool IsClassificationLoss(const TString& lossFunction) {
    return IsClassificationLoss(FromString<ELossFunction>(lossFunction));
}

bool IsMultiClassError(ELossFunction lossFunction) {
    return (lossFunction == ELossFunction::MultiClass ||
            lossFunction == ELossFunction::MultiClassOneVsAll);
}

bool IsPairwiseError(ELossFunction lossFunction) {
    return (lossFunction == ELossFunction::PairLogit);
}

bool IsQuerywiseError(ELossFunction lossFunction) {
    return (lossFunction == ELossFunction::QueryRMSE);
}

bool IsPlainMode(EBoostingType boostingType) {
    return (boostingType == EBoostingType::Plain);
}
