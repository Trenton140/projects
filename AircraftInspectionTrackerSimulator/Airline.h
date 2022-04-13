
#ifndef AIRLINE_H
#define AIRLINE_H

#include <string>
#include <iostream>
#include "Array.h"
#include "Part.h"
#include "Aircraft.h"

class Airline {
    public:
        
        Airline(const string&);
        ~Airline();
        
        void addAircraft(const string&, const string&);
        void addPart(const string&, int, int);
        bool takeFlight(const string&, int);
        void printAircraft() const;
        void printParts() const;
        void inspectionReport(const string&, Date&) const;
        bool install(const string&, const string&, Date&);

    private:
        const string name;
        Array<Part*> parts;
        Array<Aircraft*> aircrafts;

        //getters
        bool getAircraft(const string&, Aircraft**) const;
        bool getPart(const string&, Part**) const;
};

#endif