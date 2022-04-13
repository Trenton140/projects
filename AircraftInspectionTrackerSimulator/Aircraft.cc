
#include "Aircraft.h"

#include <iostream>
#include <string>

using namespace std;

Aircraft::Aircraft(const string& type, const string& registration) : type(type), registration(registration){
    
}

Aircraft::~Aircraft(){

}

const string& Aircraft::getRegistration() const{
    return registration;
}

void Aircraft::install(Part* p, Date& d){
    p->install(d);
    if(parts.isFull()){
        cout << "Parts Array is full!" << endl;
        return;
    }
    parts.add(p);
}

void Aircraft::takeFlight(int hours){
    flighthours += hours;
    for(int i = 0; i < parts.getSize(); i++){
        parts[i]->addFlightHours(hours);
    }
}

void Aircraft::inspectionReport(Date& d, Array<Part*>& ps) const{
    for(int i = 0; i < parts.getSize(); i++){
        if(parts[i]->inspection(d)){
            ps.add(parts[i]);
        }
    }
}

void Aircraft::print(ostream& os) const{
    os << "Aircraft: " << type << endl;
    os << "Registration: " << registration << endl;
}

ostream& operator<<(ostream& ost, Aircraft& ac){
    ac.print(ost);
    return ost;
}