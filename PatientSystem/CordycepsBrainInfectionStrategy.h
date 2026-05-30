#pragma once
#include "AbstractAlertLevelStrategy.h"

class CordycepsBrainInfectionStrategy : public AbstractAlertLevelStrategy
{
    virtual AlertLevel calculateAlertlevel(Vitals vitals) override;
};

