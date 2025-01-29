/////////////////////////////////////////////////////////////////////////////
// Name:        annotscore.h
// Author:      David Lewis
// Created:     2024
// Copyright (c) Authors and others. All rights reserved.
/////////////////////////////////////////////////////////////////////////////

#ifndef __VRV_ANNOTSCORE_H__
#define __VRV_ANNOTSCORE_H__

#include "atts_cmn.h"
#include "atts_shared.h"
#include "controlelement.h"
#include "editorial.h"
#include "timeinterface.h"

namespace vrv {

//----------------------------------------------------------------------------
// AnnotScore
//----------------------------------------------------------------------------

/**
 * This class models the MEI <annot> element where @type is score.
 */
class AnnotScore : public ControlElement, public TimeSpanningInterface, public AttPlist {
public:
    /**
     * @name Constructors, destructors, and other standard methods
     * Reset method reset all attribute classes
     */
    ///@{
    AnnotScore();
    virtual ~AnnotScore();
    // Object *Clone() const override { return new AnnotScore(*this); }
    void Reset() override;
    std::string GetClassName() const override { return "AnnotScore"; }
    ///@}

    /**
     * @name Getter to interfaces
     */
    ///@{
    TimePointInterface *GetTimePointInterface() override { return vrv_cast<TimePointInterface *>(this); }
    const TimePointInterface *GetTimePointInterface() const override
    {
        return vrv_cast<const TimePointInterface *>(this);
    }
    TimeSpanningInterface *GetTimeSpanningInterface() override { return vrv_cast<TimeSpanningInterface *>(this); }
    const TimeSpanningInterface *GetTimeSpanningInterface() const override
    {
        return vrv_cast<const TimeSpanningInterface *>(this);
    }

    /**
     * Get a value for the height of the drawn box
     */
    int GetBoxHeight(const Doc *doc, int unit) const;

    /**
     * Add a text element to an annotation.
     * Only supported elements will be actually added to the child list.
     */
    bool IsSupportedChild(Object *object) override;

    ///@}

    //----------//
    // Functors //
    //----------//

    /**
     * Interface for class functor visitation
     */
    ///@{
    FunctorCode Accept(Functor &functor) override;
    FunctorCode Accept(ConstFunctor &functor) const override;
    FunctorCode AcceptEnd(Functor &functor) override;
    FunctorCode AcceptEnd(ConstFunctor &functor) const override;
    ///@}

protected:
    //
private:
    //
public:
    //
private:
};

} // namespace vrv

#endif
