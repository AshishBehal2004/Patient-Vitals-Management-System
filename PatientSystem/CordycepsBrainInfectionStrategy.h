#pragma once
#include "AbstractAlertLevelStrategy.h"

class CordycepsBrainInfectionStrategy : public AbstractAlertLevelStrategy
{
    virtual AlertLevel calculateAlertlevel(Patient patient) override;
};

