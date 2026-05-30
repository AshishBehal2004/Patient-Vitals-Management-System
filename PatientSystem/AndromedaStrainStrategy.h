#pragma once
#include "AbstractAlertLevelStrategy.h"
class AndromedaStrainStrategy : public AbstractAlertLevelStrategy
{
    AlertLevel calculateAlertlevel(Patient patient) override;
};

