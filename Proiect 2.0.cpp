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
// i love fortnite
int main()
{
	vector<Produs*> produse;
	vector<int> ingrediente(5,1);
	vector<int> sosuri(5, 1);
	ProdusAmestec pa(100, 850, "2", "Kebab", ingrediente, sosuri, "Cola");
	ProdusPui p1(50, 500, "3", "Pui cu cartofi", ingrediente);
	ProdusVita p2(70, 700, "4", "Vita cu sos", sosuri);

	Restaurant r;
	r = r + pa + p1 + p2;
	Angajati a, a1, a2;
	r = r + a + a1 + a2;
	vector<Restaurant> restaurante;
	restaurante.push_back(r);
	// Meniu CRUD
	int k = 1;
	do {
		
		cout << "\n\n\n 1. Creeaza Restaurant \n";

		cout<< "\n 2. Obtine informatii despre restaurant \n";

		cout<< "\n 3. Gestioneaza restaurant \n";

		cout<< "\n 4. Sterge Restaurant \n";

		cout << "\n 5. Paraseste aplicatia \n";
		
		cout<<"\n Introducti optiunea dorita: ";

		int op;
		cin >> op;
		switch (op)
		{
		case 1: {
			cout << "\n Ati ales sa creati un restaurant \n";

			Restaurant copy;
			cin >> copy;
			restaurante.push_back(copy);

			cout << "\n Restaurantul a fost creat cu succes \n";
			break;
			}

		case 2: {
			cout << "\n\n\n Ati ales sa obtineti informatii despre un restaurant \n";
			
			for(int i = 0; i < restaurante.size(); i++,cout<<'\n')
			{
				cout <<' '<< i + 1 << ". " << restaurante[i].getNume();
			}

			cout<<"\n Alegeti restaurantul dorit(dupa id): ";
			int id;
			cin >> id;
			cout<<" \n\n\n Ati ales restaurantul "<<restaurante[id-1].getNume()<<" cu succes!\n";
			int k1 = 1;
			do { 
				int op1;
				cout << "\n 1. Afiseaza toate informatiile despre restaurant \n";
				
				cout<< "\n 2. Afiseaza lista angajatilor \n";

				cout<< "\n 3. Afiseaza lista comenzilor \n";

				cout<< "\n 4. Afiseaza numele restaurantului \n";

				cout<< "\n 5. Afiseaza adresa restaurantului \n";

				cout<< "\n 6. Afiseaza numarul de telefon pentru rezervari \n";

				cout<< "\n 7. Inapoi \n";

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
					for(int i=0;i<restaurante[id-1].getComenzi().size();i++, cout<<'\n')
						cout << " Comanda "<< i + 1  << *restaurante[id - 1][i];
	
					break;
				}
				case 4: {
					cout << " \n Ati ales sa afisati numele restaurantului \n";
					cout << " Numele restaurantului este: " << restaurante[id - 1].getNume()<<'\n';

					break;
				}
				case 5: {
					cout << " \n Ati ales sa afisati adresa restaurantului \n";
					cout << " Adresa restaurantului este: " << restaurante[id - 1].getAdresa()<<'\n';

					break;
				}
				case 6: {
					cout << " \n Ati ales sa afisati numarul de telefon pentru rezervari \n";
					cout << " Numarul de telefon pentru rezervari este: " << restaurante[id - 1].getTelefon()<<'\n';

					break;
				}
				case 7: {
					cout<<" \n Ati ales sa va intoarceti la meniul anterior \n";
					k1 = 0;
					break;
				}
				
				}
			} while (k1 == 1);
			
			break;
		}
		
		case 3:{	
		cout << " \n Ati ales sa gestionati un restaurant \n";
		for(int i = 0; i < restaurante.size(); i++,cout<<'\n')
			cout<<' '<< i + 1 << ". " << restaurante[i].getNume();
		cout<<"\n Alegeti restaurantul dorit(dupa id): ";

		int id;
		cin >> id;
		cout<<" \n Ati ales restaurantul: "<<restaurante[id-1].getNume()<<" cu succes!\n";
		int k1 = 1;
		do {
			int op1;

			cout<<"\n 1. Adauga angajat \n";

			cout<<"\n 2. Concediaza angajat \n";

			cout<<"\n 3. Creste salariu angajat \n";

			cout<<"\n 4. Adauga comanda \n";

			cout<< "\n 5. Elimina comanda \n";

			cout <<"\n 6. Aplica discount unei comenzi \n";

			cout<<"\n 7. Ofera un produs gratuit \n";

			cout<<"\n 8. Inapoi \n";

			cout<<"\n Introducti optiunea dorita: ";
			cin >> op1;

			switch (op1) {
			case 1: {
				cout << "\n Ati ales sa adaugati un angajat \n";
				Angajati a;
				cin >> a;
				restaurante[id - 1] = restaurante[id - 1] + a;
				cout << "\n Angajatul a fost adaugat cu succes \n";
				break;

			}
			case 2: {
				cout << "\n Ati ales sa concediati un angajat \n";
				for (int i = 0;i < restaurante[id - 1].getAngajati().size();i++, cout << '\n')
					cout << ' ' << i+1 << ". " << restaurante[id - 1].getAngajati()[i].getNume();
				cout << "\n Alegeti angajatul dorit(dupa id): ";
				int id1;
				cin >> id1;
				vector<Angajati> angajati=restaurante[id-1].getAngajati();// creare lista auxiliara
				angajati.erase(angajati.begin() + id1 - 1); // stergem
				restaurante[id - 1].setAngajati(angajati); // inlocuim lista veche cu cea noua
				angajati.clear(); // stergem lista auxiliara
				cout << "\n Angajatul cu id-ul " << id1 << " a fost concediat cu succes \n";
				break;
			}
			case 3: {
				cout << "\n Ati ales sa cresteti salariul unui angajat \n";
				for (int i = 0;i < restaurante[id - 1].getAngajati().size();i++, cout << '\n')
					cout << ' ' << i+1 << ". " << restaurante[id - 1].getAngajati()[i].getNume();
				cout << "\n Alegeti angajatul dorit(dupa id): ";
				int id1;
				cin >> id1;
				cout << "\n Introduceti cu cat doriti sa cresteti salariul: ";
				float salariu;
				cin >> salariu;
				restaurante[id - 1].getAngajati()[id - 1] = restaurante[id - 1].getAngajati()[id - 1] + salariu;
				cout << "\n Salariul angajatului cu id-ul " << id1 << " a fost crescut cu succes \n";
				break;
			}
			case 4: {
				cout << "\n Ati ales sa adaugati o comanda \n";
				cout<< " Selectati tipul de produs pe care doriti sa il comandati(Pui - 1, Vita - 2, Amestec - 3): ";
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
				cout << "\n Comanda a fost adaugata cu succes \n";
				break;
			}
			case 5:
			{
				cout << "\n Ati ales sa eliminati o comanda \n";
				for (int i = 0;i < restaurante[id - 1].getComenzi().size();i++, cout << '\n')
					cout << ' ' << i + 1 << ". " << (*restaurante[id - 1][i]).getNume()<< " -> "<< (*restaurante[id - 1][i]).getPret()<<'$';
				cout << "\n Alegeti comanda dorita(dupa id): ";
				int id1;
				cin >> id1;
				restaurante[id-1].eliminareComanda(id1);
				cout << "\n Comanda cu id-ul " << id1 << " a fost eliminata cu succes \n";
				break;
			}
			case 6:
			{
			cout << "\n Ati ales sa aplicati discount unei comenzi \n";
			for (int i = 0;i < restaurante[id - 1].getComenzi().size();i++, cout << '\n')
			cout << ' ' << i + 1 << ". " << (*restaurante[id - 1][i]).getNume() << " -> " << (*restaurante[id - 1][i]).getPret()<<'$';
			cout<<"\n Alegeti comanda dorita(dupa id): ";
			int id1;
			cin >> id1;
			cout << "\n Introduceti codul de discount: ";
			string cod;
			cin >> cod;
			restaurante[id-1][id1-1]->discount(cod);
			break;
			}
			case 7:
			{
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

		break;
		}

		case 4: {
			cout << " \n Ati ales sa stergeti un restaurant \n";
			for (int i = 0; i < restaurante.size(); i++, cout << '\n')
				cout << ' ' << i + 1 << ". " << restaurante[i].getNume();
			cout << "\n Alegeti restaurantul dorit(dupa id): ";
			int id;
			cin >> id;
			restaurante.erase(restaurante.begin() + id - 1);
			cout << "\n Restaurantul cu id-ul " << id << " a fost sters cu succes \n";
			
			break;
		}	

		case 5: {
			cout << " \n Ati ales sa parasiti aplicatia \n";
			k = 0;
			break;
		}
		}

	}while(k==1);


	return 0;
}

