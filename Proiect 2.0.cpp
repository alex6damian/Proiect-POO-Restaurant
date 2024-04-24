#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include "restaurant.h"
#include "angajati.h"
#include "interfata.h"
#include "produs.h"
#include "produsPui.h"
#include "produsVita.h"
#include "produsAmestec.h"

using namespace std;

int main()
{
	vector<Produs*> produse;

	vector<int> ingrediente(5, 1);
	vector<int> ingrediente1(5, 0);
	vector<int>ingrediente2(5);

	ingrediente2[0] = ingrediente2[1] = 1;
	ingrediente2[2] = ingrediente2[3] = ingrediente2[4] = 0;

	vector<int> sosuri(5, 1);

	ProdusAmestec pa(100, 850, "2", "Tocanita", ingrediente, sosuri, "Cola");
	ProdusPui p1(50, 500, "3", "Pui cu cartofi", ingrediente);
	ProdusVita p2(70, 700, "4", "Vita in sos", sosuri);
	ProdusPui p3(100, 850, "1", "Pui crispy", ingrediente1);
	ProdusPui p4(80, 600, "5", "Salata crispy pui", ingrediente2);
	ProdusVita p5(1500, 200, "1", "Steak", sosuri);
	ProdusAmestec p6(100, 850, "2", "Durum", ingrediente2, sosuri, "Pepsi");

	Angajati a1("Ion Popescu", "0723456789", "Bucatar", 5000);
	Angajati a2("Maria Popescu", "0798765432", "Ospatar", 3500);
	Angajati a3("Ben Dover", "0769420331", "Manager", 8500);

	vector<Angajati> angajati;

	angajati.push_back(a1);
	angajati.push_back(a2);
	angajati.push_back(a3);
	produse.push_back(&p1);
	produse.push_back(&pa);
	produse.push_back(&p2);
	produse.push_back(&p3);
	produse.push_back(&p4);
	produse.push_back(&p5);
	produse.push_back(&p6);

	Restaurant r("Damian's Grill", "Constanta", "0723456789", angajati, produse);

	vector<Restaurant> restaurante;

	restaurante.push_back(r);


	// Meniu CRUD
	int k = 1;
	do {

		cout << "\n\n\n 1. Creeaza Restaurant \n";

		cout << "\n 2. Obtine informatii despre restaurant \n";

		cout << "\n 3. Gestioneaza restaurant \n";

		cout << "\n 4. Sterge Restaurant \n";

		cout << "\n 5. Paraseste aplicatia \n";

		cout << "\n Introducti optiunea dorita: ";

		int op;
		cin >> op;
		switch (op)
		{
		case 1: {
			cout << "\n Ati ales sa creati un restaurant \n\n";

			Restaurant copy;
			cin >> copy;
			restaurante.push_back(copy);

			cout << "\n Restaurantul a fost creat cu succes \n";
			break;
		}

		case 2: {
			if (restaurante.size()) {
				cout << "\n\n\n Ati ales sa obtineti informatii despre un restaurant \n\n";

				for (int i = 0; i < restaurante.size(); i++, cout << '\n')
				{
					cout << ' ' << i + 1 << ". " << restaurante[i].getNume();
				}

				cout << "\n Alegeti restaurantul dorit(dupa id): ";
				int id;
				cin >> id;
				cout << " \n\n\n Ati ales restaurantul " << restaurante[id - 1].getNume() << " cu succes!\n";
				int k1 = 1;
				do {
					int op1;
					cout << "\n 1. Afiseaza toate informatiile despre restaurant \n";

					cout << "\n 2. Afiseaza lista angajatilor \n";

					cout << "\n 3. Afiseaza lista comenzilor \n";

					cout << "\n 4. Afiseaza numele restaurantului \n";

					cout << "\n 5. Afiseaza adresa restaurantului \n";

					cout << "\n 6. Afiseaza numarul de telefon pentru rezervari \n";

					cout << "\n 7. Inapoi \n";

					cout << " \n Introducti optiunea dorita: ";
					cin >> op1;
					switch (op1) {
					case 1: {
						cout << " \n Ati ales sa afisati toate informatiile despre restaurant \n";
						cout << restaurante[id - 1];
						break;
					}
					case 2: {
						cout << " \n Ati ales sa afisati lista angajatilor \n";

						for (int i = 0; i < restaurante[id - 1].getAngajati().size(); i++, cout << '\n')
							cout << " Angajatul " << i + 1 << restaurante[id - 1].getAngajati()[i];

						break;
					}
					case 3: {
						cout << " \n Ati ales sa afisati lista comenzilor \n";
						for (int i = 0;i < restaurante[id - 1].getComenzi().size();i++, cout << '\n')
							cout << " Comanda " << i + 1 << *restaurante[id - 1][i];

						break;
					}
					case 4: {
						cout << " \n Ati ales sa afisati numele restaurantului \n";
						cout << " Numele restaurantului este: " << restaurante[id - 1].getNume() << '\n';

						break;
					}
					case 5: {
						cout << " \n Ati ales sa afisati adresa restaurantului \n";
						cout << " Adresa restaurantului este: " << restaurante[id - 1].getAdresa() << '\n';

						break;
					}
					case 6: {
						cout << " \n Ati ales sa afisati numarul de telefon pentru rezervari \n";
						cout << " Numarul de telefon pentru rezervari este: " << restaurante[id - 1].getTelefon() << '\n';

						break;
					}
					case 7: {
						cout << " \n Ati ales sa va intoarceti la meniul anterior \n";
						k1 = 0;
						break;
					}

					}
				} while (k1 == 1);
			}
			else cout << " \n Nu exista restaurante in baza de date \n";

			break;
		}

		case 3: {
			if (restaurante.size()) {

				cout << " \n Ati ales sa gestionati un restaurant \n\n";

				for (int i = 0; i < restaurante.size(); i++, cout << '\n')
					cout << ' ' << i + 1 << ". " << restaurante[i].getNume();

				cout << "\n Alegeti restaurantul dorit(dupa id): ";

				int id;
				cin >> id;
				cout << " \n Ati ales restaurantul: " << restaurante[id - 1].getNume() << " cu succes!\n";
				int k1 = 1;
				do {
					int op1;

					cout << "\n 1. Adauga personal \n";

					cout << "\n 2. Concediaza angajat \n";

					cout << "\n 3. Creste salariu angajat \n";

					cout << "\n 4. Preia comanda \n";

					cout << "\n 5. Serveste comanda \n";

					cout << "\n 6. Aplica discount unei comenzi \n";

					cout << "\n 7. Ofera un produs gratuit \n";

					cout << "\n 8. Inapoi \n";

					cout << "\n Introducti optiunea dorita: ";
					cin >> op1;

					switch (op1) {
					case 1: {
						cout << "\n Ati ales sa angajati personal \n";
						Angajati a;
						cin >> a;
						restaurante[id - 1] = restaurante[id - 1] + a;
						cout << "\n " << a.getNume() << " a fost angajat cu succes \n";
						break;

					}
					case 2: {
						if (restaurante[id - 1].getAngajati().size()) {

							cout << "\n Ati ales sa concediati un angajat \n\n";

							for (int i = 0;i < restaurante[id - 1].getAngajati().size();i++, cout << '\n')
								cout << ' ' << i + 1 << ". " << restaurante[id - 1].getAngajati()[i].getNume();

							cout << "\n Alegeti angajatul dorit(dupa id): ";

							int id1;
							cin >> id1;

							string nume = restaurante[id - 1].getAngajati()[id1 - 1].getNume();

							vector<Angajati> angajati = restaurante[id - 1].getAngajati();// creare lista auxiliara
							angajati.erase(angajati.begin() + id1 - 1); // stergem
							restaurante[id - 1].setAngajati(angajati); // inlocuim lista veche cu cea noua
							angajati.clear(); // stergem lista auxiliara

							cout << "\n Angajatul " << nume << " a fost concediat cu succes \n";
						}
						else
							cout << "\n Nu exista angajati in restaurantul selectat \n";
						break;
					}
					case 3: {
						if (restaurante[id - 1].getAngajati().size()) {
							cout << "\n Ati ales sa cresteti salariul unui angajat \n\n";

							for (int i = 0;i < restaurante[id - 1].getAngajati().size();i++, cout << '\n')
								cout << ' ' << i + 1 << ". " << restaurante[id - 1].getAngajati()[i].getNume();

							cout << "\n Alegeti angajatul dorit(dupa id): ";

							int id1;
							cin >> id1;
							cout << "\n Introduceti cu cat doriti sa cresteti salariul: ";
							string nume = restaurante[id - 1].getAngajati()[id1 - 1].getNume();

							float salariu;
							cin >> salariu;

							restaurante[id - 1].getAngajati()[id - 1] = restaurante[id - 1].getAngajati()[id - 1] + salariu;
							cout << "\n Salariul angajatului " << nume << " a fost crescut cu succes \n";
						}
						else cout << "\n Nu exista angajati in restaurantul selectat \n";

						break;
					}
					case 4: {

						cout << "\n Ati ales sa preluati o comanda \n";
						cout << " Selectati tipul de produs pe care doriti sa il preluati(Pui - 1, Vita - 2, Amestec - 3): ";
						int tip;
						cin >> tip;
						switch (tip) {
						case 1: {
							Produs* p = new ProdusPui();
							cin >> *p;
							restaurante[id - 1] = restaurante[id - 1] + *p;
							break;
						}
						case 2: {
							Produs* p = new ProdusVita();
							cin >> *p;
							restaurante[id - 1] = restaurante[id - 1] + *p;
							break;
						}
						case 3: {
							Produs* p = new ProdusAmestec();
							cin >> *p;
							restaurante[id - 1] = restaurante[id - 1] + *p;
							break;
						}
						}
						cout << "\n Comanda a fost preluata cu succes \n";
						break;
					}
					case 5: {
						if (restaurante[id - 1].getComenzi().size()) {
							cout << "\n Ati ales sa serviti o comanda \n\n";

							for (int i = 0;i < restaurante[id - 1].getComenzi().size();i++, cout << '\n')
								cout << ' ' << i + 1 << ". " << (*restaurante[id - 1][i]).getNume() << " -> " << (*restaurante[id - 1][i]).getPret() << '$';
							cout << "\n Alegeti comanda dorita(dupa id): ";
							int id1;
							cin >> id1;

							int suma = restaurante[id - 1].getComenzi()[id1 - 1]->getPret();

							string nume = restaurante[id - 1].getComenzi()[id1 - 1]->getNume();

							restaurante[id - 1].eliminareComanda(id1 - 1);

							cout << "\n Comanda cu " << nume << " a fost servita cu succes \n";
							cout << " +" << suma << "$\n";
						}
						else
							cout << "\n Nu exista comenzi in restaurantul selectat \n";
						break;
					}
					case 6: {
						if (restaurante[id - 1].getComenzi().size()) {

							cout << "\n Ati ales sa aplicati discount unei comenzi \n\n";

							for (int i = 0;i < restaurante[id - 1].getComenzi().size();i++, cout << '\n')
								cout << ' ' << i + 1 << ". " << (*restaurante[id - 1][i]).getNume() << " -> " << (*restaurante[id - 1][i]).getPret() << '$';

							cout << "\n Alegeti comanda dorita(dupa id): ";

							int id1;
							cin >> id1;
							cout << "\n Introduceti codul de discount: ";

							string cod;
							cin >> cod;
							restaurante[id - 1][id1 - 1]->discount(cod);
						}
						else
							cout << "\n Nu exista comenzi in restaurantul selectat \n";
						break;
					}
					case 7: {

						cout << "\n Ati ales sa oferiti un produs gratuit \n";

						restaurante[id - 1].oferaProdusGratuit();

						break;
					}
					case 8: {
						cout << " \n Ati ales sa va intoarceti la meniul anterior \n";
						k1 = 0;
						break;
					}
					}
				} while (k1 == 1);
			}
			else cout << "\n Nu exista restaurante in baza de date\n";

			break;
		}

		case 4: {
			if (restaurante.size()) {

				cout << " \n Ati ales sa stergeti un restaurant \n\n";

				for (int i = 0; i < restaurante.size(); i++, cout << '\n')
					cout << ' ' << i + 1 << ". " << restaurante[i].getNume();

				cout << "\n Alegeti restaurantul dorit(dupa id): ";

				int id;

				cin >> id;

				string nume = restaurante[id - 1].getNume();

				restaurante.erase(restaurante.begin() + id - 1);
				cout << "\n Restaurantul " << nume << " a fost sters cu succes \n";
			}

			else cout << " \n Nu exista restaurante in baza de date \n";

			break;
		}

		case 5: {
			cout << " \n Ati ales sa parasiti aplicatia \n";
			k = 0;
			break;
		}
		}

	} while (k == 1);

	return 0;

}

