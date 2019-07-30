#include "agenda.h"

vector<Contact>& Agenda::getContacte() {
	return this->contacte;
}

vector<Contact>& Agenda::getFavorite() {
	return this->favorite;
}

vector<Contact>& Agenda::getIstoric() {
	return this->istoricApeluri;
}

void Agenda::adaugaContact(Contact c) {
	this->contacte.push_back(c);
}

void Agenda::adaugaIstoric(Contact c) {
	this->istoricApeluri.push_back(c);
}

void Agenda::adaugaFav(Contact c) {
	this->favorite.push_back(c);
}

void Agenda::stergeDinAgenda(int poz) {
	this->getContacte().erase(this->getContacte().begin() + poz);
}

void Agenda::stergeUnFavorit(int poz) {
	this->getFavorite().erase(this->getFavorite().begin() + poz);
}
