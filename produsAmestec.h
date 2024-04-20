#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "produs.h"
#include "produsPui.h"
#include "produsVita.h"

using namespace std;

class ProdusAmestec :   public ProdusPui,  public ProdusVita
{
protected: // definirea atributelor clasei
	string bautura;
	vector<int> ingredienteSos{10};

public: // definirea metodelor clasei

	// constructor default
	ProdusAmestec();

	// constructor cu parametri
	ProdusAmestec(float pret, double cantitate, string valabilitate, string nume,
		vector<int>ingrediente,vector<int>sosuri, string bautura);

	// copy constructor
	ProdusAmestec(const ProdusAmestec& obj);

	// operator =
	ProdusAmestec& operator=(const ProdusAmestec& obj);

	// setter bautura
	void setBautura(string bautura);

	// getter bautura
	string getBautura() const;

	// setter ingredienteSos
	void setingredienteSos(vector<int>ingredienteSos);

	// getter ingredienteSos
	vector<int> getIngredienteSos() const;

	// citire
	istream& citire(istream& in) override {

		ProdusVita::citire(in);

		cout << " Ingrediente dorite(1 - da; 0 - nu)\n";

		cout << " 1. Varza: ";
		in >> ingredienteSos[5];

		cout << " 2. Rosii: ";
		in >> ingredienteSos[6];

		cout << " 3. Castraveti murati: ";
		in >> ingredienteSos[7];

		cout << " 4. Cartofi: ";
		in >> ingredienteSos[8];

		cout << " 5. Ceapa: ";
		in >> ingredienteSos[9];

		int cantitate = 0;

		for (int i = 0;i < 5;i++)
			if (ingredienteSos[i+5])cantitate += 100;
		//this->setCantitate(cantitate+this->getCantitate());

		cout << " Bautura: ";
		in.get();
		getline(in, bautura);

		cout<<'\n';

		return in;
	}

	// afisare
	ostream& afisare(ostream& out) const override{

		ProdusVita::afisare(out);

		out << " Ingrediente dorite(1 - da; 0 - nu)";

		out << "\n 1. Varza: " << ingredienteSos[5];

		out << "\n 2. Rosii: " << ingredienteSos[6];

		out << "\n 3. Castraveti murati: " << ingredienteSos[7];

		out << "\n 4. Cartofi: " << ingredienteSos[8];

		out << "\n 5. Ceapa: " << ingredienteSos[9];

		out << "\n Bautura: " << bautura << '\n';

		return out;

	}

	// aplicarea discountului
	void discount(string discount) override {
		if (discount == "Damian") {
			this->setPret(this->getPret() * 0.8);
			cout << "\n Codul de discount a fost aplicat cu succes! Noul pret este: " << this->getPret() << "$\n";
		}
		else
			cout << "\n Codul introdus este invalid!\n";
	}

	// destructor
	~ProdusAmestec() {};

};

// constructor default
ProdusAmestec::ProdusAmestec() : ProdusPui(), ProdusVita(),ingredienteSos(10,0), bautura("Necunoscuta") {
	this->Produs::tipCarne="Amestec";
}

// constructor cu parametri
ProdusAmestec::ProdusAmestec(float pret, double cantitate, string valabilitate, string nume,
	vector<int>ingrediente,vector<int>sosuri, string bautura) :
	ProdusPui(pret, cantitate, valabilitate, nume, ingrediente),
	ProdusVita(pret, cantitate, valabilitate, nume, sosuri), ingredienteSos(10,0), bautura(bautura) {
	
	this->pret = pret;
	this->cantitate = cantitate;
	this->valabilitate = valabilitate;
	this->nume = nume;

	for (int i = 0;i < 5;i++)
		this->ingredienteSos[i] = sosuri[i];

	for(int i=0;i<5;i++)
		this->ingredienteSos[i+5]=ingrediente[i];
	
	
	this->Produs::tipCarne = "Amestec";
}

// copy constructor
ProdusAmestec::ProdusAmestec(const ProdusAmestec& obj) :
	ProdusPui(obj), ProdusVita(obj), bautura(obj.bautura), ingredienteSos(obj.ingredienteSos){
	this->Produs::tipCarne= "Amestec";
}

// operator =
ProdusAmestec& ProdusAmestec::operator=(const ProdusAmestec& obj) {

	if (this != &obj) {
		ProdusPui::operator=(obj);
		this->bautura = obj.bautura;
		this->ingredienteSos = obj.ingredienteSos;
	}

	return *this;
}

// setter bautura
void ProdusAmestec::setBautura(string bautura) {
	this->bautura = bautura;
}

// getter bautura
string ProdusAmestec::getBautura() const {
	return bautura;
}

// setter ingredienteSos
void ProdusAmestec::setingredienteSos(vector<int> ingredienteSos) {
	this->ingredienteSos = ingredienteSos;
}

// getter ingredienteSos
vector<int> ProdusAmestec::getIngredienteSos() const {
	return ingredienteSos;
}
