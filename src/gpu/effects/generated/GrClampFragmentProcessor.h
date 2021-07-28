/*
 * Copyright 2019 Google LLC
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

/**************************************************************************************************
 *** This file was autogenerated from GrClampFragmentProcessor.fp; do not modify.
 **************************************************************************************************/
#ifndef GrClampFragmentProcessor_DEFINED
#define GrClampFragmentProcessor_DEFINED

#include "include/core/SkM44.h"
#include "include/core/SkTypes.h"

#include "src/gpu/GrFragmentProcessor.h"

class GrClampFragmentProcessor : public GrFragmentProcessor {
public:
    SkPMColor4f constantOutputForConstantInput(const SkPMColor4f& inColor) const override {
        SkPMColor4f input = ConstantOutputForConstantInput(this->childProcessor(0), inColor);
        float clampedAlpha = SkTPin(input.fA, 0.f, 1.f);
        float clampVal = clampToPremul ? clampedAlpha : 1.f;
        return {SkTPin(input.fR, 0.f, clampVal),
                SkTPin(input.fG, 0.f, clampVal),
                SkTPin(input.fB, 0.f, clampVal),
                clampedAlpha};
    }
    static std::unique_ptr<GrFragmentProcessor> Make(std::unique_ptr<GrFragmentProcessor> inputFP,
                                                     bool clampToPremul) {
        return std::unique_ptr<GrFragmentProcessor>(
                new GrClampFragmentProcessor(std::move(inputFP), clampToPremul));
    }
    GrClampFragmentProcessor(const GrClampFragmentProcessor& src);
    std::unique_ptr<GrFragmentProcessor> clone() const override;
    const char* name() const override { return "ClampFragmentProcessor"; }
    bool clampToPremul;

private:
    GrClampFragmentProcessor(std::unique_ptr<GrFragmentProcessor> inputFP, bool clampToPremul)
            : INHERITED(kGrClampFragmentProcessor_ClassID,
                        (OptimizationFlags)ProcessorOptimizationFlags(inputFP.get()) &
                                (kConstantOutputForConstantInput_OptimizationFlag |
                                 kPreservesOpaqueInput_OptimizationFlag))
            , clampToPremul(clampToPremul) {
        this->registerChild(std::move(inputFP), SkSL::SampleUsage::PassThrough());
    }
    std::unique_ptr<GrGLSLFragmentProcessor> onMakeProgramImpl() const override;
    void onGetGLSLProcessorKey(const GrShaderCaps&, GrProcessorKeyBuilder*) const override;
    bool onIsEqual(const GrFragmentProcessor&) const override;
#if GR_TEST_UTILS
    SkString onDumpInfo() const override;
#endif
    GR_DECLARE_FRAGMENT_PROCESSOR_TEST
    using INHERITED = GrFragmentProcessor;
};
#endif