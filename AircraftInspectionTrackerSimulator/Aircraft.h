
#ifndef AIRCRAFT_H
#define AIRCRAFT_H

#include <string>
#include <iostream>
#include "Array.h"
#include "Part.h"

class Aircraft {
    friend ostream& operator<<(ostream&, const Aircraft&);

    public:
        Aircraft(const string&, const string&);
        virtual ~Aircraft();

        const string& getRegistration() const;

        void install(Part*, Date&);
        void takeFlight(int hours);
        void inspectionReport(Date& d, Array<Part*>&) const;

        virtual void print(ostream& os) const;

    private:
        const string type;
        const string registration;
        int flighthours;
        Array<Part*> parts;
};

#endif