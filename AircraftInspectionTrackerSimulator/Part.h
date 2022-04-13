
#ifndef PART_H
#define PART_H

#include <iostream>
#include <string>

#include "defs.h"
#include "Date.h"

using namespace std;

class Part {

    friend ostream& operator<<(ostream&, const Part&);

    public:
        Part(const string&);
        virtual ~Part();

        const string& getName() const;

        void addFlightHours(int);
        void install(Date&);

        virtual bool inspection(Date&) const = 0;
        virtual void print(ostream& os) const;
    
    private:
        const string name;
    
    protected:
        Date installationDate;
        int flighthours;
};

class FH_Part : virtual public Part {
    public:
        FH_Part(const string&, int);
        virtual ~FH_Part();

        virtual bool inspection(Date&) const;

        virtual void print(ostream& os) const;
        virtual void printSingle(ostream& os) const;

    private:
        int fh_inspect;
};

class IT_Part : virtual public Part {
    public:
        IT_Part(const string&, int);
        virtual ~IT_Part();

        virtual bool inspection(Date&) const;

        virtual void print(ostream& os) const;
        virtual void printSingle(ostream& os) const;

    private:
        int it_inspect;
};

class FHIT_Part : public FH_Part, public IT_Part {
    public:
        FHIT_Part(const string&, int, int);
        virtual ~FHIT_Part();

        virtual bool inspection(Date&) const;

        virtual void print(ostream& os) const;
};

#endif