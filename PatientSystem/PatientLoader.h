#pragma once
#include "AbstractPatientDatabaseLoader.h"
#include "PatientDatabaseLoader.h"
#include "PatientFileLoader.h"

using namespace std;


class PatientLoader : public AbstractPatientDatabaseLoader
{
public:
	PatientLoader( vector <unique_ptr<AbstractPatientDatabaseLoader>> dbName) : patientsData(move(dbName)){}
	~PatientLoader();

	// Inherited via AbstractPatientDatabaseLoader
	virtual void initialiseConnection() override;

	virtual void loadPatients(std::vector<Patient*>& patientIn) override;

	virtual void closeConnection() override;

private:
	
	vector<unique_ptr<AbstractPatientDatabaseLoader> > patientsData;
};

