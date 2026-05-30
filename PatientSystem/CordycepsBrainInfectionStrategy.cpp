#include "CordycepsBrainInfectionStrategy.h"
#include <iostream>
#include "PatientAlertLevels.h"
#include "Vitals.h"
using namespace std;

AlertLevel CordycepsBrainInfectionStrategy::calculateAlertlevel(Patient patient) {
    
    vector <const Vitals*> v = patient.vitals();
    if (v[v.size() -1]->RR() > 40) {
        return AlertLevel::Red;
    }
    else if (v[v.size() - 1]->RR() > 30) {
        return AlertLevel::Orange;
    }
    else if (v[v.size() - 1]->RR() > 20) {
        return AlertLevel::Yellow;
    }
    else {
        return AlertLevel::Green;
    }
}