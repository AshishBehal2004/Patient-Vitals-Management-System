#include "PatientFileLoader.h"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#include "Patient.h"
#include "Vitals.h"


using namespace std;


std::vector<Patient*> PatientFileLoader::loadPatientFile(const std::string& file)
{
	vector<Patient*> patients{};

    std::ifstream inFile(file);
    if (inFile.is_open()) {
        // TODO: load your file here
    }

    return patients;
}

void PatientFileLoader::initialiseConnection()
{
    // pretend this initialises a database connection
}

void PatientFileLoader::loadPatients(std::vector<Patient*>& patientIn) {
   
}

void PatientFileLoader::closeConnection() {

}