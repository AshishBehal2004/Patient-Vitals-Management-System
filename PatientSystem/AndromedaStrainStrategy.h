#pragma once
#include "AbstractAlertLevelStrategy.h"
class AndromedaStrainStrategy : public AbstractAlertLevelStrategy
{
    AlertLevel calculateAlertlevel(Vitals vitals) override;
};

