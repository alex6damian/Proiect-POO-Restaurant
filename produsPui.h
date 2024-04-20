#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "produs.h"

using namespace std;

class ProdusPui : virtual public Produs {

protected: // definirea atributelor clasei

	vector<int> ingrediente{5};

public: // definirea metodelor clasei

	// constructor default
	ProdusPui();

	// constructor cu parametri
	ProdusPui(float pret, double cantitate, string valabilitate, string nume, vector<int> ingrediente);

	// getter tipCarne
	string getTipCarne() const;

	// setter ingrediente
	void setingrediente(vector<int> ingrediente);

	// getter ingrediente
	vector<int> getingrediente() const;

	// copy-constructor
	ProdusPui(const ProdusPui& obj);

	// operator =
	ProdusPui& operator=(const ProdusPui& obj);

	// citire
	istream& citire(istream& in) override {

		Produs::citire(in);
		cout << " Ingrediente dorite(1 - da; 0 - nu)\n";

		cout << " 1. Varza: ";
		in >> ingrediente[0];

		cout << " 2. Rosii: ";
		in >> ingrediente[1];

		cout << " 3. Castraveti murati: ";
		in >> ingrediente[2];

		cout << " 4. Cartofi: ";
		in >> ingrediente[3];

		cout << " 5. Ceapa: ";
		in >> ingrediente[4];

		int cantitate = 0;

		for (int i = 0;i < 5;i++)
			if (ingrediente[i])cantitate += 100;
		this->setCantitate(cantitate + 250);

		cout << '\n';

		return in;
	}

	// afisare
	ostream& afisare(ostream& out) const override {

		Produs::afisare(out);

		out << " Ingrediente dorite(1 - da; 0 - nu)";

		out << "\n 1. Varza: " << ingrediente[0];

		out << "\n 2. Rosii: " << ingrediente[1];

		out << "\n 3. Castraveti murati: " << ingrediente[2];

		out << "\n 4. Cartofi: " << ingrediente[3];

		out << "\n 5. Ceapa: " << ingrediente[4] << '\n';

		return out;
	}

	// aplicarea discountului
	void discount(string discount) override {
		if (discount == "Damian") {
			this->setPret(this->getPret() * 0.75);
			cout << "\n Codul de discount a fost aplicat cu succes! Noul pret este: " << this->getPret() << "$\n";
		}
		else
			cout << "\n Codul introdus este invalid!\n";
	}

	// destructor
	~ProdusPui() {};

};

// constructor default
ProdusPui::ProdusPui() : Produs(), ingrediente(5, 0){
	this->Produs::tipCarne = "Pui";
}

// constructor cu parametri
ProdusPui::ProdusPui(float pret, double cantitate, string valabilitate, string nume, vector<int> ingrediente) :
	Produs(pret, cantitate, valabilitate, nume), ingrediente(ingrediente){
	this->Produs::tipCarne = "Pui";
}

// copy-constructor
ProdusPui::ProdusPui(const ProdusPui& obj) : Produs(obj), ingrediente(obj.ingrediente){
	this->Produs::tipCarne = obj.tipCarne;
}

// operator =
ProdusPui& ProdusPui::operator=(const ProdusPui& obj) {
	if (this != &obj) {
		Produs::operator=(obj);
		ingrediente = obj.ingrediente;
	}
	return *this;
}

//getter tipCarne
string ProdusPui::getTipCarne() const {
	return tipCarne;
}

//setter ingrediente
void ProdusPui::setingrediente(vector<int> ingrediente) {
	this->ingrediente = ingrediente;
}

//getter ingrediente
vector<int> ProdusPui::getingrediente() const {
	return ingrediente;
}
