// Copyright (C) 2020 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include <tuple>
#include <vector>
#include <string>
#include <memory>

#include "functional_test_utils/layer_test_utils.hpp"
#include "ngraph_functions/builders.hpp"

typedef std::vector<size_t> TileSpecificParams;
typedef std::tuple<
        TileSpecificParams,
        InferenceEngine::Precision,    // Net precision
        InferenceEngine::SizeVector,   // Input shapes
        LayerTestsUtils::TargetDevice  // Device name
> TileLayerTestParamsSet;

namespace LayerTestsDefinitions {

class TileLayerTest : public testing::WithParamInterface<TileLayerTestParamsSet>,
                      public LayerTestsUtils::LayerTestsCommon {
public:
    static std::string getTestCaseName(testing::TestParamInfo<TileLayerTestParamsSet> obj);

protected:
    void SetUp() override;
};

}  // namespace LayerTestsDefinitions
