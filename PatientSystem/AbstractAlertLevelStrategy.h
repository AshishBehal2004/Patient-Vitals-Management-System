#pragma once
#include "Patient.h"
#include "PatientAlertLevels.h"
class AbstractAlertLevelStrategy
{

public:
    virtual AlertLevel calculateAlertlevel(Patient patient) = 0;  
};

