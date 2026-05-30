#pragma once

#include "PatientAlertLevels.h"
class Patient;
class AbstractAlertLevelStrategy
{

public:
    virtual AlertLevel calculateAlertlevel(const Patient& patient) = 0;  
    virtual ~AbstractAlertLevelStrategy() = default;
};

