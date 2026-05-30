#pragma once
#include "AbstractAlertLevelStrategy.h"

class CordycepsBrainInfectionStrategy : public AbstractAlertLevelStrategy
{
    virtual AlertLevel calculateAlertlevel(const Patient& patient) override;
};

