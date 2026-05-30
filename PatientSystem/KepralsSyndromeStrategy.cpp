#include "KepralsSyndromeStrategy.h"
#include "PatientAlertLevels.h"
#include "Vitals.h"
#include "Patient.h"
using namespace std;

AlertLevel KepralsSyndromeStrategy::calculateAlertlevel(const Patient& patient ) {

    vector <const Vitals*> v = patient.vitals();

    if (patient.age() < 12 && v[v.size() - 1]->HR() > 120) {
        return AlertLevel::Red;
    }
    else if (patient.age() >= 12 && v[v.size() - 1]->HR() > 100) {
        return AlertLevel::Red;
    }
    else {
        return AlertLevel::Green;
    }
}