
# Patient Vitals Management System

A command-line patient monitoring system, built in C++ for COMP1039 (Design Patterns with C++). It watches each patient's vitals, and the moment a patient becomes critical, it automatically alerts the hospital and their GP, no manual checking needed.

## Overview

The system loads a list of patients (from a database, a text file, or both), and lets you record new vitals for any patient: body temperature, blood pressure, heart rate, and respiratory rate. Each time new vitals are entered, the system works out an alert level for that patient: **Green → Yellow → Orange → Red**, by using rules based on what disease they have. As soon as a patient reaches Red, the hospital and their GP are notified right away.

The main goal of this project wasn't just to add these features, it was to add them the *right* way, using four classic design patterns, instead of bolting code on wherever it happened to fit.

## Features

- **Load patients from a file, a database, or both**: by default it loads both (database first, then file), and switching between them only takes one line of code.
- **Each disease has its own alert rules**: Cordyceps Brain Infection, Kepral's Syndrome, and Andromeda Strain each check different vitals, and the right rules are applied automatically whenever new vitals come in.
- **Old records are left alone**: alert levels are only worked out for brand-new vitals, not for the historical data loaded in at startup.
- **Automatic Red-alert notifications**: the instant a patient reaches Red, the hospital and GP are notified automatically. The rest of the system doesn't need to know how those notifications actually work, it just happens.

## Design patterns

| Requirement | Pattern | Why |
|---|---|---|
| Load patients from a file | **Adapter** | `PatientFileLoader` is built to look exactly rom the outside (same `AbstractPatientDatabaseLoader` interface), so the rest of thesystem can't tell the difference between loading from a file or a database. |
| Load patients from file *and* database | **Composite** | `PatientLoader` holds a list o) inside it, but from the outside it still looks like just one loader. Calling it onceloads from every source inside it, in order. |
| Calculate alert level per disease | **Strategy** | Each disease gets its own class for `CordycepsBrainInfectionStrategy`, `KepralsSyndromeStrategy`, `AndromedaStrainStrategy`).This means `Patient` doesn't need to know the actual rules, it just asks whichever strategy it's been given. |
| Alert hospitals and GPs on Red | **Observer** | `HospitalAlertSystemFacade` and `GPNoti sign up to "watch" every patient (as an `AlertLevelObserver`). The moment a patient'salert level changes to Red, the `Patient` itself tells every watcher directly, nobody has to keep checking. |

A full UML class diagram is included in the repo (`PatientSystem/finalpatientmanagementsystemuml.drawio (1).png`).

## Project structure

```
PatientSystem/
├── main.cpp                            # entry point
├── PatientManagementSystem.h/.cpp      # main driver — menu loop, patient lookup
├── Patient.h/.cpp                      # patient data + alert level + observers
├── Person.h/.cpp                       # base class for Patient
├── Vitals.h/.cpp                       # a single vitals measurement
├── AbstractPatientDatabaseLoader.h     # loader interface (Adapter/Composite target)
├── PatientDatabaseLoader.h/.cpp        # mocked database loader
├── PatientFileLoader.h/.cpp            # loads patients from patients.txt
├── PatientLoader.h/.cpp                # combines multiple loaders (Composite)
├── AbstractAlertLevelStrategy.h        # strategy interface
├── CordycepsBrainInfectionStrategy.*   # disease-specific alert rules
├── KepralsSyndromeStrategy.*
├── AndromedaStrainStrategy.*
├── AlertLevelObserver.h                # observer interface
├── HospitalAlertSystemFacade.h/.cpp    # notifies the hospital
├── GPNotificationSystemFacade.h/.cpp   # notifies the GP
└── patients.txt                        # sample patient data
```

## Getting started

Built with **Visual Studio 2022**, using only the C++ standard library, no outside dependencies

1. Clone the repo and open `PatientSystem.sln` in Visual Studio 2022.
2. Build and run (`F5`). `patients.txt` is read relative to the working directory the executable runs from.

## Patient data format

`patients.txt` holds one patient per line, pipe-separated:

```
<id>|<lastName>,<firstName>|<DD-MM-YYYY birthday>|<diagnosis>|<vitals records>
```

Vitals records (optional, semicolon-separated if there's more than one) are `bodyTemperature,bloodPressure,heartRate,respiratoryRate`:

```
jh1074|Jones,Henry|02-10-1974|Cordyceps Brain Infection|37.5,80,60,16;37.5,82,15,16
mm0580|McCartney,Martha|24-05-1980|Kepral's Syndrome|
```

## Usage

```
WELCOME TO HEALTHCO 3000
------------------------

Select an option:
1. List patients
2. Add vitals record
3. Quit
> 2
Patients
jh1074|Jones,Henry|02-10-1974|Cordyceps Brain Infection|37.5,80,60,16;37.5,82,15,16
mm0580|McCartney,Martha|24-05-1980|Kepral's Syndrome|
...

Enter the patient ID to declare vitals for > jh1074
enter body temperature: 36.3
enter blood pressure: 88
enter heart rate: 60
enter respitory rate: 55
Patient: Jones, Henry (jh1074) has an alert level: Red

This is an alert to the hospital:
Patient: Jones, Henry (jh1074) has a critical alert level

This is an notification to the GPs:
Patient: Jones, Henry (jh1074) should be followed up
```

## Tech

C++17. Uses only STL containers, memory in the loaders is managed automatically with `uni external libraries.
