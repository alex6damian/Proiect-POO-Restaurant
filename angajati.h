#pragma once
#include <iostream>
#include <string>
#include "interfata.h"

using namespace std;

class Angajati: protected Interfata{

protected: // definirea atributelor clasei
    string nume;
    string telefon;
    string functie;
    float salariu;
    const int id;
    static int contorId;

public: // definirea metodelor clasei

    // constructor default
    Angajati();

    // constructor cu parametri
    Angajati(string nume, string telefon, string functie, float salariu);

    // copy-constructor
    Angajati(const Angajati& obj);

    // operator =
    Angajati& operator=(const Angajati& obj);

    // setter pentru nume
    void setNume(string nume);

    // getter pentru nume
    string getNume() const;

    // setter pentru telefon
    void setTelefon(string telefon);

    // getter pentru telefon
    string getTelefon() const;

    // setter pentru functie
    void setFunctie(string functie);

    // getter pentru functie
    string getFunctie() const;

    // setter pentru salariu
    void setSalariu(float salariu);

    // getter pentru salariu
    float getSalariu() const;

    // getter pentru id
    const int getId() const;

    // supraincarare indexare[]
    void operator[](int index) const;

    // supraincarcare operator +
    Angajati operator+(float valoare);

    //citire
    istream& citire(istream& in){

		cout << "\n Nume angajat: ";
        in.get();
        getline(in, nume);
		cout << " Telefon angajat: ";
        getline(in, telefon);
		cout << " Functie angajat: ";
        getline(in, functie);
		cout << " Salariu angajat: ";
		in >> salariu;

		return in;
	}

    //afisare
    ostream& afisare(ostream& out) const{

        out << "\n Nume angajat: " << nume << '\n';

        out << " Telefon angajat: " << telefon << '\n';

        out << " Functie angajat: " << functie << '\n';

        out << " Salariu angajat: " << salariu << "$\n";

        out<< " ID angajat: " << id << '\n';

        return out;
    }

    // destructor
    ~Angajati() {};

    friend istream& operator>>(istream& in, Angajati& obj);
    friend ostream& operator<<(ostream& out, const Angajati& obj);
};

// constructor default
Angajati::Angajati() : nume("Necunoscut"), telefon("Necunoscut"),functie("Necunoscuta")
,salariu(0),id(++contorId) {}

// constructor cu parametri
Angajati::Angajati(string nume, string telefon, string functie, float salariu) : nume(nume),
telefon(telefon), functie(functie), salariu(salariu), id(++contorId) {}

// copy-constructor
Angajati::Angajati(const Angajati& obj) :nume(obj.nume), telefon(obj.telefon), functie(obj.functie), salariu(obj.salariu), id(obj.id) {}

// operator =
Angajati& Angajati::operator=(const Angajati& obj) {
    if (this != &obj) {
        nume = obj.nume;
        telefon = obj.telefon;
        functie = obj.functie;
        salariu = obj.salariu;
    }
    return *this;
}

// setter pentru nume
void Angajati::setNume(string nume) {
    this->nume = nume;
}

// getter pentru nume
string Angajati::getNume() const {
    return this->nume;
}

// setter pentru telefon
void Angajati::setTelefon(string telefon) {
    this->telefon = telefon;
}

// getter pentru telefon
string Angajati::getTelefon() const {
    return this->telefon;
}

// setter pentru functie
void Angajati::setFunctie(string functie) {
    this->functie = functie;
}

// getter pentru functie
string Angajati::getFunctie() const {
    return this->functie;
}

// setter pentru salariu
void Angajati::setSalariu(float salariu) {
    this->salariu = salariu;
}

// getter pentru salariu
float Angajati::getSalariu() const {
    return this->salariu;
}

// getter pentru id
const int Angajati::getId() const {
	return this->id;
}

// supraincarare indexare[]
void Angajati::operator[](int index) const {
    if (index == 0)
        cout << "\n " << Angajati::getNume() << '\n';
    else if (index == 1)
        cout << "\n " << Angajati::getTelefon() << '\n';
    else if (index == 2)
        cout << "\n " << Angajati::getFunctie() << '\n';
    else if (index == 3)
        cout << "\n " << Angajati::getSalariu() << '\n';
    else if (index == 4)
        cout << "\n " << Angajati::getId() << '\n';
    else
        cout << "\n Index invalid \n";
}

// supraincarcare operator +
Angajati Angajati::operator+(float valoare) {
    Angajati copie = *this;
    copie.salariu += valoare;
    return copie;
}

// citire
istream& operator>>(istream& in, Angajati& obj) {
	return obj.citire(in);
}

// afisare
ostream& operator<<(ostream& out, const Angajati& obj) {
	return obj.afisare(out);
}

// initializare static
int Angajati::contorId = 0;
