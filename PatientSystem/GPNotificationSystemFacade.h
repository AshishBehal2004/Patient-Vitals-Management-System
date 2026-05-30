#pragma once

#include "Patient.h"
#include "AlertLevelObserver.h"

class GPNotificationSystemFacade : public AlertLevelObserver {
public:
	GPNotificationSystemFacade();
	virtual ~GPNotificationSystemFacade();

	void sendGPNotificationForPatient(Patient* p);
	virtual void sendAlertForPatient(Patient* p) override;
};

