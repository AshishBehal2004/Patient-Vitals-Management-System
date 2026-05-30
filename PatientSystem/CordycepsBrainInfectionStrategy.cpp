#include "CordycepsBrainInfectionStrategy.h"
#include <iostream>
#include "PatientAlertLevels.h"
using namespace std;

AlertLevel CordycepsBrainInfectionStrategy::calculateAlertlevel(Vitals vitals) {
    if (vitals.RR > 40) {
        return AlertLevel::Red;
    }
    else if (vitals.RR > 30) {
        return AlertLevel::Orange;
    }
    else if (vitals.RR > 20) {
        return AlertLevel::Green;
    }
}