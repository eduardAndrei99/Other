#include "teste.h"
#include <assert.h>

void testContact() {
	Contact c1{ "ion","123" };
	Contact c2{ "gheorhe","333" };
	Contact c3{ "maria","000" };
	assert(c1.getNume() == "ion");
	assert(c1.getNumarTelefon() == "123");
	assert(c2.getNume() == "gheorhe");
	assert(c2.getNumarTelefon() == "333");
	assert(c3.getNume() == "maria");
	assert(c3.getNumarTelefon() == "000");
}

void testAgPrincipala() {
	Agenda ag;
	Contact c1{ "ion","123" };
	Contact c2{ "edy","111" };
	ag.adaugaContact(c1);
	ag.adaugaContact(c2);
	vector<Contact> v = ag.getContacte();
	assert(v[0].getNume() == "ion");
	assert(v[0].getNumarTelefon() == "123");
	assert(v[1].getNume() == "edy");
	assert(v[1].getNumarTelefon() == "111");
	assert(ag.getContacte().size() == 2);
	ag.stergeDinAgenda(0);
	assert(ag.getContacte().size() == 1);
	ag.stergeDinAgenda(0);
	assert(ag.getContacte().size() == 0);
}

void testFavorite() {
	Agenda ag;
	Contact c1{ "ion","123" };
	Contact c2{ "edy","111" };
	ag.adaugaFav(c1);
	assert(ag.getFavorite().size() == 1);
	ag.adaugaFav(c2);
	assert(ag.getFavorite().size() == 2);
	ag.stergeUnFavorit(0);
	vector<Contact> k = ag.getFavorite();
	assert(k[0].getNumarTelefon() == "111");
	assert(k[0].getNume() == "edy");
	assert(ag.getFavorite().size() == 1);
	ag.stergeUnFavorit(0);
	assert(ag.getFavorite().size() == 0);
}

void testApeluri() {
	Agenda ag;
	Contact c1{ "ion","123" };
	Contact c2{ "edy","111" };
	ag.adaugaIstoric(c1);
	assert(ag.getIstoric().size() == 1);
	ag.adaugaIstoric(c1);
	assert(ag.getIstoric().size() == 2);
	ag.adaugaIstoric(c2);
	assert(ag.getIstoric().size() == 3);
	vector<Contact> v = ag.getIstoric();
	assert(v[0].getNume() == "ion");
	assert(v[0].getNumarTelefon() == "123");
	assert(v[1].getNume() == "ion");
	assert(v[1].getNumarTelefon() == "123");
	assert(v[2].getNume() == "edy");
	assert(v[2].getNumarTelefon() == "111");
}