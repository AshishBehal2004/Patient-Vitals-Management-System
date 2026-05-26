#include "PatientFileLoader.h"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "Patient.h"
#include "Vitals.h"


using namespace std;


std::vector<Patient*> PatientFileLoader::loadPatientFile(const std::string& file)
{
	vector<Patient*> patients{};

    std::ifstream inFile(file);
    if (inFile.is_open()) {
        // TODO: load your file here
        std::string line;
        while (getline(inFile, line)) {
            cout << line << "\n";
            char separator = '|';
            std::vector<std::string> temp_record;
            string temp;
            int i = 0;
            while (line[i] != '\0') {
                if (line[i] != separator) {
                    temp += line[i];
                }
                else {
                    temp_record.push_back(temp);
                    temp.clear();
                }
                i++;
            }
            char name_separator = ',';
            int j = 0;
            vector<string> stored_name;
            string temp_string;
            while (j != temp_record[1].size()) {

                if (temp_record[1][j] != name_separator) {
                    temp_string += temp_record[1][j];
                }
                else {
                    stored_name.push_back(temp_string);
                    temp_string.clear();
                }
                j++;
            }
            stored_name.push_back(temp_string);
            temp_record.push_back(temp);
            
            tm tm = {};

            istringstream ss(temp_record[2]);
            ss >> get_time(&tm, "%d-%m-%Y");

            time_t date = mktime(&tm);
            Patient* temp_patient = new Patient(stored_name[1], stored_name[0], tm);
            //std::cout << stored_name[0] << " "<<  stored_name[1];

            patients.push_back(temp_patient);
            temp_patient->addDiagnosis(temp_record[3]);
            //temp_patient->addVitals(temp_record[4]);
            
        }
        inFile.close();
    }

    return patients;
}

void PatientFileLoader::initialiseConnection()
{
    // pretend this initialises a database connection
}

void PatientFileLoader::loadPatients(std::vector<Patient*>& patientIn) {
    std::vector<Patient*> patients = loadPatientFile(filename);
    patientIn.insert(patientIn.end(), patients.begin(), patients.end());

}

void PatientFileLoader::closeConnection() {

}