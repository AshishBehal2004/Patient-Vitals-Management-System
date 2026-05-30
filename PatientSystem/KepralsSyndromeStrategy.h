#pragma once
#include "AbstractAlertLevelStrategy.h"
class KepralsSyndromeStrategy : public AbstractAlertLevelStrategy
{
    AlertLevel calculateAlertlevel(Patient patient) override;
};

