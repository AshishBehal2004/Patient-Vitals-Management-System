#pragma once
#include "AbstractAlertLevelStrategy.h"
class KepralsSyndromeStrategy : public AbstractAlertLevelStrategy
{
    AlertLevel calculateAlertlevel(const Patient& patient) override;
};

