#pragma once
#include <iostream>
#include <string>
#include "interfata.h"

using namespace std;

class Produs : protected Interfata {

protected: // definirea atributelor clasei
	float pret;
	double cantitate;
	string valabilitate;
	string nume;
	string tipCarne;

public: // definirea metodelor clasei

	// constructor default
	Produs();

	// constructor cu parametri
	Produs(float pret, double cantitate, string valabilitate, string nume);

	// copy-constructor
	Produs(const Produs& obj);

	// operator =
	Produs& operator=(const Produs& obj);

	// setter pentru pret
	void setPret(float pret);

	// getter pentru pret
	float getPret() const;

	// setter pentru cantitate
	void setCantitate(double cantitate);

	// getter pentru cantitate
	double getCantitate() const;

	// setter pentru valabilitate
	void setValabilitate(string valabilitate);

	// getter pentru valabilitate
	string getValabilitate() const;

	// setter pentru nume
	void setNume(string nume);

	// getter pentru nume
	string getNume() const;

	// citire
	istream& citire(istream& in) override{

		cout << "\n Nume produs: ";
		in.get();
		getline(in, nume);
		cout << " Pret produs: ";
		in >> pret;
		cout << " Valabilitate produs: ";
		in.get();
		getline(in, valabilitate);

		return in;
	}

	// afisare
	ostream& afisare(ostream& out) const override {

		out << "\n Nume produs: " << nume;

		out << "\n Pret produs: " << pret<< "$";

		out << "\n Cantitate produs: " << cantitate << " grame";

		out << "\n Valabilitate produs: " << valabilitate << " zile";

		out<< "\n Tip carne: " << tipCarne << '\n';

		return out;
	}
	
	// aplicam discount
	virtual void discount(string discount) = 0;

	// destructor
	virtual ~Produs() {};

	friend istream& operator>>(istream& in, Produs& obj);
	friend ostream& operator<<(ostream& out, const Produs& obj);

};

// constructor default
Produs::Produs() : pret(0), cantitate(0), valabilitate("Necunoscuta"), nume("Necunoscut"), tipCarne("Necunoscut") {}

// constructor cu parametri
Produs::Produs(float pret, double cantitate, string valabilitate, string nume) : 
	pret(pret), cantitate(cantitate), valabilitate(valabilitate), nume(nume), tipCarne("Necunoscut") {}

// copy-constructor
Produs::Produs(const Produs& obj) : pret(obj.pret), cantitate(obj.cantitate), 
valabilitate(obj.valabilitate), nume(obj.nume), tipCarne(obj.tipCarne) {}

// operator =
Produs& Produs::operator=(const Produs& obj) {
	if (this != &obj) {
		pret = obj.pret;
		cantitate = obj.cantitate;
		valabilitate = obj.valabilitate;
		nume = obj.nume;
		tipCarne = obj.tipCarne;
	}
	return *this;
}

// setter pentru pret
void Produs::setPret(float pret) {
	this->pret = pret;
}

// getter pentru pret
float Produs::getPret() const {
	return pret;
}

// setter pentru cantitate
void Produs::setCantitate(double cantitate) {
	this->cantitate = cantitate;
}

// getter pentru cantitate
double Produs::getCantitate() const {
	return cantitate;
}

// setter pentru valabilitate
void Produs::setValabilitate(string valabilitate) {
	this->valabilitate = valabilitate;
}

// getter pentru valabilitate
string Produs::getValabilitate() const {
	return valabilitate;
}

// setter pentru nume
void Produs::setNume(string nume) {
	this->nume = nume;
}

// getter pentru nume
string Produs::getNume() const {
	return nume;
}

// operator >>
istream& operator>>(istream& in, Produs& obj) {
	return obj.citire(in);
}

// operator <<
ostream& operator<<(ostream& out, const Produs& obj) {
	
	return obj.afisare(out);
	
}