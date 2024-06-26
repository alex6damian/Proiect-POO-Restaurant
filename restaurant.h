﻿#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "interfata.h"
#include "angajati.h"
#include "produs.h"
#include "produsPui.h"
#include "produsAmestec.h"
#include "produsVita.h"
#include <cstdlib>
#include <ctime>

using namespace std;

class Restaurant: protected Interfata {

protected: // definirea atributelor clasei
    string nume;
    string adresa;
    string telefon;
    vector<Angajati> angajati;
    vector<Produs*> comenzi;

public: // definirea metodelor clasei

    // constructor default
    Restaurant();

    // constructor cu parametri
    Restaurant(string nume, string adresa, string telefon, vector<Angajati> angajati, vector<Produs*> comenzi);

    // copy constructor
    Restaurant(const Restaurant& obj);

    // setter pentru nume
    void setNume(string nume);

    // getter pentru nume
    string getNume() const;

    // setter pentru adresa
    void setAdresa(string adresa);

    // getter pentru adresa
    string getAdresa() const;

    // setter pentru telefon
    void setTelefon(string telefon);

    // getter pentru telefon
    string getTelefon() const;

    // setter pentru angajati
    void setAngajati(const vector<Angajati> angajati);

    // getter pentru angajati
    vector<Angajati> getAngajati() const;

    // setter pentru comenzi
    void setComenzi(const vector<Produs*> comenzi);

    // getter pentru comenzi
    vector<Produs*> getComenzi() const;

    // operator =
    Restaurant& operator=(const Restaurant& obj);

    // operator + intre clase
    Restaurant operator+(const Produs& obj);

    // eliminare comanda
    void eliminareComanda(int index);
    
    // angajatul cu cel mai mare salariu
    Angajati angajatulLunii(const vector<Angajati>& angajati) const {
        return angajati[0];
    }

    // informatii comanda(operator [])
    Produs* operator[](int index) const;

    // ofera produs gratuit
    void oferaProdusGratuit();
    
    // creste salariul angajatului
    void cresteSalariu(int index, double procent);

    // adauga angajat
    Restaurant operator+(const Angajati& obj) const;

    // citire
    istream& citire(istream& in) override {

        in.get();
        cout << "\n Nume restaurant: ";
        getline(in, nume);

        cout << " Adresa restaurant: ";
        getline(in, adresa);

        cout << " Telefon restaurant: ";
        in >> telefon;

        cout<< " Numar angajati: ";
        int n;
        in >> n;

        for (int i = 0; i < n; i++) {
			Angajati* a= new Angajati;
			in >> *a;
			angajati.push_back(*a);
            delete a;
		}

        cout << " Numar comenzi produse pui: ";
        in >> n;

        for(int i=0; i<n; i++){
            Produs* p = new ProdusPui;
            in >> *p;
			comenzi.push_back(p);
		}

        cout << " Numar comenzi produse vita: ";
        in >> n;

        for (int i = 0; i < n; i++) {
            Produs* p = new ProdusVita;
            in >> *p;
            comenzi.push_back(p);
        }

        cout << " Numar comenzi produse amestec: ";
        in >> n;

        for (int i = 0; i < n; i++) {
            Produs* p = new ProdusAmestec;
            in >> *p;
            comenzi.push_back(p);
        }

        return in;
    }

    // afisare
    ostream& afisare(ostream& out) const override{

        out << "\n\n Nume restaurant: " << nume;

        out << "\n Adresa restaurant: " << adresa;

        out << "\n Telefon restaurant: " << telefon;

        out << "\n Numar angajati: " << angajati.size()<<'\n';
        
        for (int i = 0; i < angajati.size(); i++) {
			out << "\n Angajatul " << i + 1 << ":";
			out << angajati[i];
		}

        out << "\n Numar comenzi: " << comenzi.size() << '\n';

        for (int i = 0; i < comenzi.size();i++) {
            out << "\n Comanda " << i + 1 << ":";
			out << *comenzi[i];
        }


        return out;
    }

    // destructor
    ~Restaurant();

    friend istream& operator>>(istream& in, Restaurant& obj);
    friend ostream& operator<<(ostream& out, const Restaurant& obj);
};

// constructor default
Restaurant::Restaurant() : nume("Necunoscut"), adresa("Necunoscuta"), telefon("Necunoscut"),
angajati(), comenzi() {}

// constructor cu parametri
Restaurant::Restaurant(string nume, string adresa, string telefon, vector<Angajati> angajati, vector<Produs*> comenzi):
nume(nume), adresa(adresa), telefon(telefon), angajati(angajati){
    
    for (int i = 0;i < this->comenzi.size();i++)
        delete this->comenzi[i];

    this->comenzi.clear();

    for (int i = 0;i < comenzi.size();i++)
        if (typeid(ProdusPui) == typeid(*comenzi[i])) {
            Produs *p = new ProdusPui(dynamic_cast<ProdusPui&>(*comenzi[i]));
            this->comenzi.push_back(p);
        }
        else if (typeid(ProdusVita) == typeid(*comenzi[i])) {
            Produs *p = new ProdusVita(dynamic_cast<ProdusVita&>(*comenzi[i]));
            this->comenzi.push_back(p);
        }
        else if (typeid(ProdusAmestec) == typeid(*comenzi[i])) {
            Produs *p = new ProdusAmestec(dynamic_cast<ProdusAmestec&>(*comenzi[i]));
            this->comenzi.push_back(p);
        }
}

// copy constructor
Restaurant::Restaurant(const Restaurant& obj) : nume(obj.nume), adresa(obj.adresa), telefon(obj.telefon), angajati(obj.angajati) {
   
    for (int i = 0;i < this->comenzi.size();i++)
        delete this->comenzi[i];

    this->comenzi.clear();

    for (int i = 0;i < obj.comenzi.size();i++)
        if (typeid(ProdusPui) == typeid(*obj.comenzi[i])) {
            Produs* p = new ProdusPui(dynamic_cast<ProdusPui&>(*obj.comenzi[i]));
            this->comenzi.push_back(p);
        }
        else if (typeid(ProdusVita) == typeid(*obj.comenzi[i])) {
            Produs* p = new ProdusVita(dynamic_cast<ProdusVita&>(*obj.comenzi[i]));
            this->comenzi.push_back(p);
        }
        else if (typeid(ProdusAmestec) == typeid(*obj.comenzi[i])) {
            Produs* p = new ProdusAmestec(dynamic_cast<ProdusAmestec&>(*obj.comenzi[i]));
            this->comenzi.push_back(p);
        }
}

// operator =
Restaurant& Restaurant::operator=(const Restaurant& obj) {

    if (this != &obj) {

        this->nume = obj.nume;

        this->adresa = obj.adresa;

        this->telefon = obj.telefon;

        this->angajati = obj.angajati;

        for (int i = 0;i < this->comenzi.size();i++)
            delete this->comenzi[i];

        this->comenzi.clear();

        for (int i = 0;i < obj.comenzi.size();i++)
            if (typeid(ProdusPui) == typeid(*obj.comenzi[i])) {
                Produs* p = new ProdusPui(dynamic_cast<ProdusPui&>(*obj.comenzi[i]));
                this->comenzi.push_back(p);
            }
            else if (typeid(ProdusVita) == typeid(*obj.comenzi[i])) {
                Produs* p = new ProdusVita(dynamic_cast<ProdusVita&>(*obj.comenzi[i]));
                this->comenzi.push_back(p);
            }
            else if (typeid(ProdusAmestec) == typeid(*obj.comenzi[i])) {
                Produs* p = new ProdusAmestec(dynamic_cast<ProdusAmestec&>(*obj.comenzi[i]));
                this->comenzi.push_back(p);
            }
        
    }
    return *this;
}

// operator + intre clase
Restaurant Restaurant::operator+(const Produs& obj) {

    Restaurant copy = *this;
    if (const ProdusAmestec* amestecPointer = dynamic_cast<const ProdusAmestec*>(&obj)) {
        Produs* p = new ProdusAmestec(*amestecPointer);
        copy.comenzi.push_back(p);
    }
    else if (const ProdusPui* puiPointer = dynamic_cast<const ProdusPui*>(&obj)) {
        Produs* p = new ProdusPui(*puiPointer);
        copy.comenzi.push_back(p);
    }
    else if (const ProdusVita* vitaPointer = dynamic_cast<const ProdusVita*>(&obj)) {
        Produs* p = new ProdusVita(*vitaPointer);
        copy.comenzi.push_back(p);
    }


    return copy;
}

// setter nume
void Restaurant::setNume(string nume) {
    this->nume = nume;
}

// getter nume
string Restaurant::getNume() const {
    return this->nume;
}

// getter adresa
void Restaurant::setAdresa(string adresa) {
    this->adresa = adresa;
}

// getter adresa
string Restaurant::getAdresa() const {
    return this->adresa;
}

// setter telefon
void Restaurant::setTelefon(string telefon) {
    this->telefon = telefon;
}

// getter telefon
string Restaurant::getTelefon() const {
    return this->telefon;
}

// setter angajati
void Restaurant::setAngajati(const vector<Angajati> angajati) {
	this->angajati = angajati;
}

// getter angajati
vector<Angajati> Restaurant::getAngajati() const{
	return this->angajati;
}

// setter comenzi
void Restaurant::setComenzi(const vector<Produs*> comenzi) {
    
    for (int i = 0;i < this->comenzi.size();i++)
        delete this->comenzi[i];

    this->comenzi.clear();

    for (int i = 0;i < comenzi.size();i++)
        if (typeid(ProdusPui) == typeid(*comenzi[i])) {
            Produs* p = new ProdusPui(dynamic_cast<ProdusPui&>(*comenzi[i]));
            this->comenzi.push_back(p);
        }
        else if (typeid(ProdusVita) == typeid(*comenzi[i])) {
            Produs* p = new ProdusVita(dynamic_cast<ProdusVita&>(*comenzi[i]));
            this->comenzi.push_back(p);
        }
        else if (typeid(ProdusAmestec) == typeid(*comenzi[i])) {
            Produs* p = new ProdusAmestec(dynamic_cast<ProdusAmestec&>(*comenzi[i]));
            this->comenzi.push_back(p);
        }

}

// getter comenzi
vector<Produs*> Restaurant::getComenzi() const {
	return this->comenzi;
}

// eliminare comanda
void Restaurant::eliminareComanda(int index) {
    try {
        if (index >= 0 && index < this->comenzi.size())
        {
            delete this->comenzi[index];
            this->comenzi.erase(this->comenzi.begin() + index);
            
        }
        else
            throw out_of_range(" Index invalid! \n");
    }
    catch (const out_of_range& e) {
        cerr << e.what() << '\n';
    }
}

// informatii comanda(operator [])
Produs* Restaurant::operator[](int index) const {
	try {
		if (index >= 0 && index < comenzi.size())
			return comenzi[index];
		else
			throw out_of_range("\n Index invalid! \n");
	}
	catch (const out_of_range& e) {
		cerr << e.what() << '\n';
		return NULL;
	}
}

// ofera produs gratuit
void Restaurant::oferaProdusGratuit() {
    if(comenzi.size()>4){
    srand(static_cast<unsigned>(time(nullptr)));
    int random = rand() % comenzi.size(); // generare numar random
    
    cout << "\n Felicitari! Comanda cu numarul " << random + 1 << " este din partea casei! \n";
    this->comenzi[random]->setPret(0); // pretul devine 0
    }
	else
		cout << "\n Nu exista comenzi suficiente pentru a oferi produse din partea casei! \n";
}

// creste salariul angajatului
void Restaurant::cresteSalariu(int index, double procent) {
    try {
        if (index >= 0 && index < angajati.size()) {
            angajati[index].setSalariu(angajati[index].getSalariu() + angajati[index].getSalariu() * procent / 100);
        }
        else
            throw out_of_range(" Index invalid! \n");
    }
    catch (const out_of_range& e) {
        cerr << e.what() << '\n';
    }
}

// adauga angajat
Restaurant Restaurant::operator+(const Angajati& obj) const {
	Restaurant copy = *this;
	copy.angajati.push_back(obj);
	return copy;
}

// citire
istream& operator>>(istream& in, Restaurant& obj) {
    return obj.citire(in);
}

// afisare
ostream& operator<<(ostream& out, const Restaurant& obj) {
    return obj.afisare(out);
}

// destructor
Restaurant:: ~Restaurant() {

    for(int i=0;i<this->comenzi.size();i++)
        delete this->comenzi[i];

    this->angajati.clear();
    this->comenzi.clear();
}