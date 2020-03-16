/*
 * Copyright (C) 2018 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "config.h"
#include "LayoutInlineContainer.h"

#if ENABLE(LAYOUT_FORMATTING_CONTEXT)

#include "RenderStyle.h"
#include <wtf/IsoMallocInlines.h>

namespace WebCore {
namespace Layout {

WTF_MAKE_ISO_ALLOCATED_IMPL(InlineContainer);

InlineContainer::InlineContainer(Optional<ElementAttributes> attributes, RenderStyle&& style, BaseTypeFlags baseTypeFlags)
    : Container(attributes, WTFMove(style), baseTypeFlags | InlineContainerFlag)
{
}

bool InlineContainer::establishesInlineFormattingContext() const
{
    if (!isInlineBlockBox())
        return false;

    // 9.4.2 Inline formatting contexts
    // An inline formatting context is established by a block container box that contains no block-level boxes.
    if (auto* firstInFlowChild = this->firstInFlowChild())
        return firstInFlowChild->isInlineLevelBox();

    return false;
}

const Container& InlineContainer::formattingContextRoot() const
{
    // Relatively positioned (inflow) inline container lives in the formatting context where its parent lives unless
    // the parent establishes a formatting context. This is slightly different from the usual behavior which is containing block driven.
    //
    // <div id=outer style="position: absolute">><div id=inner><span style="position: relative">content</span></div></div>
    // While the relatively positioned inline container (span) is placed relative to its containing block "outer", it lives in the inline
    // formatting context established by "inner".
    auto& ancestor = isInFlowPositioned() ? *parent() : *containingBlock();
    if (ancestor.establishesFormattingContext())
        return ancestor;
    return ancestor.formattingContextRoot();
}

}
}

#endif
