#pragma once
#include "Vitals.h"
#include "PatientAlertLevels.h"
class AbstractAlertLevelStrategy
{

public:
    virtual AlertLevel calculateAlertlevel(Vitals vitals) = 0;  
    
};

