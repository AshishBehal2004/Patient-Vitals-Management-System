#include "PatientLoader.h"
#include "PatientDatabaseLoader.h"
#include "PatientFileLoader.h"

#include <iomanip>
#include <iostream>
#include <sstream>

#include "Patient.h"
#include "Vitals.h"

using namespace std;

PatientLoader::~PatientLoader() {}
void PatientLoader::initialiseConnection()
{
    // pretend this initialises a database connection
}

void PatientLoader::loadPatients(std::vector<Patient*>& patientIn) {
    patientsData[0]->loadPatients(patientIn);
    patientsData[1]->loadPatients(patientIn);
}


void PatientLoader::closeConnection()
{
    // pretend this initialises a database connection
}