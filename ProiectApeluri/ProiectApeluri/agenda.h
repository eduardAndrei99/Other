#pragma once
#include "contact.h"
#include <vector>
#include <string>

using std::vector;
using std::string;

class Agenda {
private:
	vector<Contact>contacte;
	vector<Contact>favorite;
	vector<Contact>istoricApeluri;

public:

	Agenda() {
	}

	/*
	 * Functie ce returneaza vectorul de contacte
	 */
	vector<Contact>& getContacte();
	
	/*
	 * Functie ce returneaza vectorul de contacte favorite
	 */
	vector<Contact>& getFavorite();

	/*
	 * Functie ce returneaza istoricul apelurilor
	 */
	vector<Contact>& getIstoric();

	/*
	 * Functie ce adauga un contact in agenda
	 */
	void adaugaContact(Contact c);

	/*
	 * Functie ce adauga un contact la apeluri trimise
	 */
	void adaugaIstoric(Contact c);

	/*
	 * Functie ce adauga un contact la favorite
	 */
	void adaugaFav(Contact c);

	/*
	 * Functie ce sterge din agenda un contact
	 */
	void stergeDinAgenda(int poz);

	/*
	 * Functie ce sterge din agenda un contact
	 */
	void stergeUnFavorit(int poz);

};