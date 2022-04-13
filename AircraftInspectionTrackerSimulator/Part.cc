
#include "Part.h"

#include <iostream>
#include <string>

using namespace std;

//Part
Part::Part(const string& name) : name(name){ }

Part::~Part(){

}

const string& Part::getName() const{
    return name;
}

void Part::addFlightHours(int hours){
    flighthours += hours;
}

void Part::install(Date& date){
    installationDate.setDate(date.getDay(), date.getMonth(), date.getYear());
}

void Part::print(ostream& os) const{
    os << "Part: " << this->getName() << endl;
    os << "Flight Hours: " << this->flighthours << endl;
    os << "Installation Date: " << installationDate.getMonthName() << " " << installationDate.getDay() << ", " << installationDate.getYear() << endl;
}

//FH_Part
FH_Part::FH_Part(const string& name, int hours) : Part(name){
    fh_inspect = hours;
}

FH_Part::~FH_Part(){

}

bool FH_Part::inspection(Date& date) const{
    return flighthours > fh_inspect;
}

void FH_Part::print(ostream& os) const{
    Part::print(os);
    os << "Inspect every: " << fh_inspect << " flight hours" << endl;
}

void FH_Part::printSingle(ostream& os) const{
    os << "Inspect every: " << fh_inspect << " flight hours" << endl;
}

//IT_Part
IT_Part::IT_Part(const string& name, int days) : Part(name){
    it_inspect = days;
}

IT_Part::~IT_Part(){

}

bool IT_Part::inspection(Date& date) const{
    return (date.toDays() - installationDate.toDays()) > it_inspect;
}

void IT_Part::print(ostream& os) const{
    Part::print(os);
    os << "Inspect every: " << it_inspect << " days installed" << endl;
}

void IT_Part::printSingle(ostream& os) const{
    os << "Inspect every: " << it_inspect << " days installed" << endl;
}

//FHIT_Part
FHIT_Part::FHIT_Part(const string& name, int hours, int days) : Part(name), FH_Part(name, hours), IT_Part(name, days) {

}

FHIT_Part::~FHIT_Part(){

}

bool FHIT_Part::inspection(Date& date) const{
    return (FH_Part::inspection(date) || IT_Part::inspection(date));
}

void FHIT_Part::print(ostream& os) const{
    Part::print(os);
    FH_Part::printSingle(os);
    IT_Part::printSingle(os);
}

ostream& operator<<(ostream& ost, Part& p){
    p.print(ost);
    return ost;
}