/*
 * Fakih Laurance
 * Stiinte UIBS, matematica informatica
 * Proiect OOP 
 * Cerinta problema: o aplicatie care gestioneaza o agenda telefonica
 * Agenda telefonica contine contacte
 * Favorite : contacte favorite
 * Un contact contine : un nume si un numar de telefon
 * In aplicatie se poate adauga un contact, se poate sterge un contact
 * Se pot introduce la favorite anumite contacte, sterge
 * Istoric apel: apelurile care s au facut
*/

#include <iostream>
#include <vector>
#include "Ui.h"
#include "teste.h"

using namespace std;

void testAll() {
	testContact();
	testAgPrincipala();
	testFavorite();
	testApeluri();
}

int main() {

	testAll();
	Ui ui;
	ui.start();

	return 0;
}