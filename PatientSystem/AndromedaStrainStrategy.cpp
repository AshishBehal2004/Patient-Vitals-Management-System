#include "AndromedaStrainStrategy.h"
#include <iostream>
#include "Vitals.h"
using namespace std;
#include "Patient.h"
AlertLevel AndromedaStrainStrategy::calculateAlertlevel(const Patient& patient) {
    vector <const Vitals*> v = patient.vitals();

    if (v[v.size() - 1]->BP() > 140) {
        return AlertLevel::Red;
    }
    else if (v[v.size() - 1]->BP() > 130) {
        return AlertLevel::Orange;
    }
    else if (v[v.size() - 1]->BP() > 110) {
        return AlertLevel::Yellow;
    }
    else {
        return AlertLevel::Green;
    }

}