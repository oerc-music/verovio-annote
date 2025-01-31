/////////////////////////////////////////////////////////////////////////////
// Name:        annotscore.cpp
// Author:      David Lewis
// Created:     2024
// Copyright (c) Authors and others. All rights reserved.
/////////////////////////////////////////////////////////////////////////////

#include "annotscore.h"

//----------------------------------------------------------------------------

#include <cassert>

//----------------------------------------------------------------------------

#include "devicecontext.h"
#include "doc.h"
#include "functor.h"
#include "text.h"
#include "verticalaligner.h"
#include "vrv.h"

namespace vrv {

//----------------------------------------------------------------------------
// AnnotScore
//----------------------------------------------------------------------------

static const ClassRegistrar<AnnotScore> s_factory("annotScore", ANNOTSCORE);

AnnotScore::AnnotScore() : ControlElement(ANNOTSCORE, "annotscore-"), PlistInterface(), TimeSpanningInterface()
{
    this->RegisterInterface(PlistInterface::GetAttClasses(), PlistInterface::IsInterface());
    this->RegisterInterface(TimeSpanningInterface::GetAttClasses(), TimeSpanningInterface::IsInterface());

    this->Reset();
}

AnnotScore::~AnnotScore() {}

void AnnotScore::Reset()
{
    ControlElement::Reset();
    PlistInterface::Reset();
    TimeSpanningInterface::Reset();
}

int AnnotScore::GetBoxHeight(const Doc *doc, int unit) const
{
    // This is the height of the visible box. This should use a more sensible metric (rastral size?)
    int boxHeight = doc->GetOptions()->m_octaveLineThickness.GetValue() * unit * 10;
    return boxHeight;
}

int AnnotScore::GetLineWidth(const Doc *doc, int unit) const
{
    // This is the width of the border of the visible box. This should use a more sensible metric, probably
    int boxHeight = doc->GetOptions()->m_octaveLineThickness.GetValue() * unit;
    return boxHeight;
}

bool AnnotScore::IsSupportedChild(Object *child)
{
    if (child->IsTextElement()) {
        assert(dynamic_cast<TextElement *>(child));
    }
    else if (child->Is(ANNOT)) {
        assert(dynamic_cast<AnnotScore *>(child));
    }
    else {
        return false;
    }
    return true;
}

//----------------------------------------------------------------------------
// AnnotScore functor methods
//----------------------------------------------------------------------------

FunctorCode AnnotScore::Accept(Functor &functor)
{
    return functor.VisitAnnotScore(this);
}

FunctorCode AnnotScore::Accept(ConstFunctor &functor) const
{
    return functor.VisitAnnotScore(this);
}

FunctorCode AnnotScore::AcceptEnd(Functor &functor)
{
    return functor.VisitAnnotScoreEnd(this);
}

FunctorCode AnnotScore::AcceptEnd(ConstFunctor &functor) const
{
    return functor.VisitAnnotScoreEnd(this);
}

} // namespace vrv
