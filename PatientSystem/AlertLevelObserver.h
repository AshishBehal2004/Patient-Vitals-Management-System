#pragma once

class Patient;
class AlertLevelObserver
{
public:
    virtual void  sendAlertForPatient(Patient* p) = 0;
    virtual ~AlertLevelObserver() = default;
};

