#pragma once

#include "learn_context.h"

#include <catboost/libs/data/pool.h>

#include <library/grid_creator/binarization.h>

#include <util/generic/vector.h>
#include <util/generic/hash_set.h>

void GenerateBorders(const TPool& pool, TLearnContext* ctx, TVector<TFloatFeature>* floatFeatures);

int GetClassesCount(const TVector<float>& target, int classesCount);

void ConfigureMalloc();

void UpdateQueriesInfo(const TVector<ui32>& queriesId, int begin, int end, TVector<TQueryInfo>* queryInfo);

TVector<TQueryEndInfo> GetQueryEndInfo(const TVector<TQueryInfo>& queriesInfo, int learnSampleCount);

void CalcErrors(
    const TTrainData& data,
    const TVector<THolder<IMetric>>& errors,
    bool hasTrain,
    bool hasTest,
    TLearnContext* ctx
);
