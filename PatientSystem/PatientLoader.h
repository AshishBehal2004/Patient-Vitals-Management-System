#pragma once
#include "AbstractPatientDatabaseLoader.h"
using namespace std;


class PatientLoader : public AbstractPatientDatabaseLoader
{
public:
	PatientLoader( vector <unique_ptr<AbstractPatientDatabaseLoader>> dbName) : patientsData(dbName){
		
	}

	// Inherited via AbstractPatientDatabaseLoader
	virtual void initialiseConnection() override;

	void loadPatients(vector<AbstractPatientDatabaseLoader*> patients);

	virtual void loadPatients(std::vector<Patient*>& patientIn) override;

	virtual void closeConnection() override;

private:
	
	vector<unique_ptr<AbstractPatientDatabaseLoader> > patientsData;

};

