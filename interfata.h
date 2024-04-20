#pragma once
#include <iostream>
#include <string>

using namespace std;

class Interfata {

public: // definim interfata claselor

    virtual istream& citire(istream&) = 0;
    virtual ostream& afisare(ostream&) const = 0;
    virtual ~Interfata() = default;

};