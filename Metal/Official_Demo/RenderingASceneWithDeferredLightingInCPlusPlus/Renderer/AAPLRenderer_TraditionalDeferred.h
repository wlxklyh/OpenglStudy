/*
See LICENSE folder for this sample’s licensing information.

Abstract:
Header for the renderer class which performs Metal setup and per frame rendering for a traditional
 deferred renderer used for macOS devices without Apple Silicon and the iOS & tvOS simulators.
*/

#ifndef AAPLRenderer_TraditionalDeferred_h
#define AAPLRenderer_TraditionalDeferred_h

#include "AAPLRenderer.h"
#include "CPPMetal.hpp"

class Renderer_TraditionalDeferred : public Renderer
{
public:

    explicit Renderer_TraditionalDeferred(MTK::View & view);

    virtual ~Renderer_TraditionalDeferred();

    void drawInView(MTK::View & view);

    void drawableSizeWillChange(MTK::View & view, const MTL::Size & size);

#if SUPPORT_BUFFER_EXAMINATION

    void validateBufferExaminationMode();

#endif

private:

    MTL::RenderPipelineState m_lightPipelineState;

    MTL::RenderPassDescriptor m_GBufferRenderPassDescriptor;
    MTL::RenderPassDescriptor m_finalRenderPassDescriptor;

    void loadMetal();

    void drawDirectionalLight(MTL::RenderCommandEncoder & renderEncoder);

    void drawPointLights(MTL::RenderCommandEncoder & renderEncoder);

};
#endif // AAPLRenderer_TraditionalDeferred_h
