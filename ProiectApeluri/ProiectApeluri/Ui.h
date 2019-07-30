#pragma once
#include "agenda.h"
#include <iostream>

class Ui {
private:
	Agenda agenda;
public:

	Ui() {
	}

	/*
	 * Functie ce returneaza agenda
	 */
	Agenda getAgenda() {
		return this->agenda;
	}

	/*
	 * Functie ce afiseaza meniul
	 */
	void arataMeniu();

	/*
	 * Functie ce porneste aplicatia
	 */
	void start();

	/*
	 * Functie de adaugare a unui contact
	 */
	void adaugaContact();

	/*
	 * Functie ce afiseaza agenda
	 */
	void afiseazaAgenda();

	/*
	 * Functie ce sterge un contact din agenda
	 */
	void stergeAgenda();

	/*
	 * Functie ce suna un contact
	 */
	void suna();

	/*
	 * Functie ce afiseaza istoricul apelurilor
	 */
	void afiseazaIstoric();

	/*
	 * Functie ce adauga un contact la favorit
	 */
	void adaugaFavorit();

	/*
	 * Functie ce afiseaza contactele favorite
	 */
	void afiseazaFavorite();

	/*
	 * Functie ce sterge contactul favorit
	 */
	void stergeFavorit();

};