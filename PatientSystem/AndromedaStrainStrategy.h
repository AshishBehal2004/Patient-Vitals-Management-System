#pragma once
#include "AbstractAlertLevelStrategy.h"
class AndromedaStrainStrategy : public AbstractAlertLevelStrategy
{
    AlertLevel calculateAlertlevel(const Patient& patient) override;
};

