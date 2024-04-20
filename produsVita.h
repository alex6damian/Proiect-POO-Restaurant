#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "produs.h"

using namespace std;

class ProdusVita : virtual public Produs {

protected: // definirea atributelor clasei

	vector<int> sosuri{5};

public: // definirea metodelor clasei

	// constructor default
	ProdusVita();

	// constructor cu parametri
	ProdusVita(float pret, double cantitate, string valabilitate, string nume, vector<int> sosuri);

	// getter tipCarne
	string getTipCarne() const;

	// setter sosuri
	void setsosuri(vector<int> sosuri);

	// getter sosuri
	vector<int> getsosuri() const;

	// copy-constructor
	ProdusVita(const ProdusVita& obj);

	// operator =
	ProdusVita& operator=(const ProdusVita& obj);

	// citire
	istream& citire(istream& in) override{

		Produs::citire(in);
		cout << " Sosuri dorite(1 - da; 0 - nu)\n";

		cout << " 1. Maioneza usturoi: ";
		in >> sosuri[0];
		cout << " 2. Maioneza picanta: ";
		in >> sosuri[1];
		cout << " 3. Ketchup dulce: ";
		in >> sosuri[2];
		cout << " 4. Sos curry: ";
		in >> sosuri[3];
		cout << " 5. Mix 13 condimente: ";
		in >> sosuri[4];

		int cantitate = 0;
		for (int i = 0;i < 5;i++)
			if (sosuri[i])cantitate += 100;
		this->setCantitate(cantitate + 250);

		cout << '\n';

		return in;
	}

	// afisare
	ostream& afisare(ostream& out) const override{

		Produs::afisare(out);

		out << " Sosuri dorite(1 - da; 0 - nu)";

		out << "\n 1. Maioneza usturoi: " << sosuri[0];

		out << "\n 2. Maioneza picanta: " << sosuri[1];

		out << "\n 3. Ketchup dulce: " << sosuri[2];

		out << "\n 4. Sos curry: " << sosuri[3];

		out << "\n 5. Mix 13 condimente: " << sosuri[4] << '\n';

		return out;
	}

	// aplicarea discountului
	void discount(string discount) override {
		if (discount == "Damian") {
			this->setPret(this->getPret() * 0.85);
			cout << "\n Codul de discount a fost aplicat cu succes! Noul pret este: " << this->getPret() << "$\n";
		}
		else
			cout << "\n Codul introdus este invalid!\n";
	}


	// destructor
	~ProdusVita() {};

};

// constructor default
ProdusVita::ProdusVita() : Produs(), sosuri(5, 0) {
	this->Produs::tipCarne = "Vita";
}

// constructor cu parametri
ProdusVita::ProdusVita(float pret, double cantitate, string valabilitate, string nume, vector<int> sosuri) :
	Produs(pret, cantitate, valabilitate, nume), sosuri(sosuri) {
	this->Produs::tipCarne = "Vita";
}

// copy-constructor
ProdusVita::ProdusVita(const ProdusVita& obj) : Produs(obj), sosuri(obj.sosuri){
	this->Produs::tipCarne = obj.tipCarne;
}

// operator =
ProdusVita& ProdusVita::operator=(const ProdusVita& obj) {
	if (this != &obj) {
		Produs::operator=(obj);
		sosuri = obj.sosuri;
	}
	return *this;
}

//getter tipCarne
string ProdusVita::getTipCarne() const {
	return tipCarne;
}

//setter sosuri
void ProdusVita::setsosuri(vector<int> sosuri) {
	this->sosuri = sosuri;
}

//getter sosuri
vector<int> ProdusVita::getsosuri() const {
	return sosuri;
}
