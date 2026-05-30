#pragma once

#include "Patient.h"
#include "AlertLevelObserver.h"

class HospitalAlertSystemFacade : public AlertLevelObserver
{
public:
	HospitalAlertSystemFacade();
	virtual ~HospitalAlertSystemFacade();

	virtual void sendAlertForPatient(Patient* p) override;

};

