
#include "Airline.h"

#include <iostream>
#include <string>

using namespace std;

Airline::Airline(const string& name) : name(name){

}

Airline::~Airline(){
    for(int i = 0; i < parts.getSize(); i++){
        delete parts[i];
    }
    for(int i = 0; i < aircrafts.getSize(); i++){
        delete aircrafts[i];
    }
}

void Airline::addAircraft(const string& name, const string& registration){
    if(aircrafts.isFull()){
        cout << "Aircrafts Array full!";
        return;        
    }
    Aircraft *ac = new Aircraft(name, registration);
    aircrafts.add(ac);
}

void Airline::addPart(const string& part, int fh_inspect, int it_inspect){
    if(parts.isFull()){
        cout << "Parts Array full!";
        return;  
    }
    if(fh_inspect != 0 && it_inspect != 0){
        FHIT_Part *p = new FHIT_Part(part, fh_inspect, it_inspect);
        parts.add(p);
    }
    else if(fh_inspect == 0){
        IT_Part *p = new IT_Part(part, it_inspect);
        parts.add(p);
    }
    else if(it_inspect == 0){
        FH_Part *p = new FH_Part(part, fh_inspect);
        parts.add(p);
    }
}

bool Airline::takeFlight(const string& reg, int hours){
    Aircraft *ac;
    if(getAircraft(reg, &ac)){
        ac->takeFlight(hours);
        return true;
    }
    return false;
}

void Airline::printAircraft() const{
    cout << aircrafts << endl;
}

void Airline::printParts() const{
    cout << parts << endl;
}

void Airline::inspectionReport(const string& reg, Date& d) const{
    Aircraft *ac;
    Array<Part*> ps;
    if(getAircraft(reg, &ac)){
        cout << "The following parts from " << reg << " require inspection:" << endl;
        ac->inspectionReport(d, ps);
        for(int i = 0; i < ps.getSize(); i++){
            (ps[i])->print(cout);
            cout << endl;
        }
        cout << endl;
        return;
    }
    cout << "Aircraft not found!";
}

bool Airline::install(const string& reg, const string& part, Date& d){
    Aircraft *ac;
    Part *p;
    if(getAircraft(reg, &ac)){
        if(getPart(part, &p)){
            ac->install(p, d);
            return true;
        }
        cout << "Part not found!";
        return false;
    }
    cout << "Aircraft not found!";
    return false;
}

//getters
bool Airline::getAircraft(const string& reg, Aircraft** ac) const{
    for(int i = 0; i < aircrafts.getSize(); i++){
        if(aircrafts[i]->getRegistration() == reg){
            *ac = aircrafts[i];
            return true;
        }
    }
    return false;
}

bool Airline::getPart(const string& part, Part** p) const{
    for(int i = 0; i < parts.getSize(); i++){
        if(parts[i]->getName() == part){
            *p = parts[i];
            return true;
        }
    }
    return false;
}