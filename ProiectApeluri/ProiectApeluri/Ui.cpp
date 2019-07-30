#include "Ui.h"
using std::cout;
using std::cin;
void Ui::arataMeniu() {
	cout << "-------------------------------\n";
	cout << "|[1] Arata agenda             |\n";
	cout << "|[2] Adauga contact           |\n";
	cout << "|[3] Sterge contact           |\n";
	cout << "|[4] Suna                     |\n";
	cout << "|[5] Adauga la favorite       |\n";
	cout << "|[6] Afiseaza favorite        |\n";
	cout << "|[7] Sterge contact favorit   |\n";
	cout << "|[8] Afiseaza istoric apeluri |\n";
	cout << "|[0] Exit                     |\n";
	cout << "-------------------------------\n";
	cout << "\n";
	return;
}

void Ui::adaugaContact() {
	string nume;
	string numar;
	cout << "Numele ";
	cin >> nume;
	cout << "\nNumarul ";
	cin >> numar;
	Contact c{ nume, numar };
	this->agenda.adaugaContact(c);
	cout << "Adaugat.\n";
	return;
}

void Ui::afiseazaAgenda() {
	int poz = 1;
	vector<Contact>& ag = this->agenda.getContacte();
	if (ag.size() == 0) {
		cout << "Agenda goala!\n";
	}
	for (const auto& contact : ag) {
		cout << "[" << poz++ << "] ";
		cout << contact.getNume() << " " << contact.getNumarTelefon() << "\n";
	}
	cout << "\n";
	return;
}

void Ui::stergeAgenda() {
	this->afiseazaAgenda();
	cout << "Introduceti numarul pe care vreti sa il stergeti ";
	int poz;
	cin >> poz;
	vector<Contact>& ag = this->agenda.getContacte();
	if (poz < 1 || poz > ag.size()) {
		cout << "Gresit\n";
		return;
	}
	this->agenda.stergeDinAgenda(poz - 1);
	//ag.erase(ag.begin() + poz - 1);
	cout << "Sters.\n";
	return;
}

void Ui::suna() {
	this->afiseazaAgenda();
	vector<Contact>& ag = this->agenda.getContacte();
	if (ag.size() == 0) {
		return;
	}
	cout << "Introduceti indicele pe care vreti sa sunati : ";
	int poz;
	cin >> poz;
	if (poz < 1 || poz > ag.size()) {
		cout << "Gresit\n";
		return;
	}
	this->agenda.adaugaIstoric(ag[poz - 1]);
	cout << "Ati sunat pe " << ag[poz-1].getNume()<<"\n";
	return;
}

void Ui::afiseazaIstoric() {
	int poz = 1;
	vector<Contact>& ag = this->agenda.getIstoric();
	if (ag.size() == 0) {
		cout<<"Nu ati sunat pe nimeni momentan!\n";
		return;
	}
	for (const auto& contact : ag) {
		cout << "[" << poz++ << "] ";
		cout << contact.getNume() << " " << contact.getNumarTelefon() << "\n";
	}
	cout << "\n";
	return;
}

void Ui::adaugaFavorit() {
	this->afiseazaAgenda();
	vector<Contact>& ag = this->agenda.getContacte();
	if (ag.size() == 0) {
		return;
	}
	cout << "Introduceti numarul pe care vreti sa il adaugati la favorite  ";
	int poz;
	cin >> poz;
	if (poz < 1 || poz > ag.size()) {
		cout << "Gresit\n";
		return;
	}
	this->agenda.adaugaFav(ag[poz - 1]);
	cout << "Adaugat la favorite.\n";
	return;
}

void Ui::afiseazaFavorite() {
	int poz = 1;
	vector<Contact>& ag = this->agenda.getFavorite();
	if (ag.size() == 0) {
		cout << "Nu aveti contacte favorite!\n";
		return;
	}
	for (const auto& contact : ag) {
		cout << "[" << poz++ << "] ";
		cout << contact.getNume() << " " << contact.getNumarTelefon() << "\n";
	}
	cout << "\n";
	return;
}

void Ui::stergeFavorit() {
	this->afiseazaFavorite();
	vector<Contact>& ag = this->agenda.getFavorite();
	if (ag.size() == 0) {
		return;
	}
	cout << "Introduceti numarul pe care vreti sa il stergeti ";
	int poz;
	cin >> poz;
	if (poz < 1 || poz > ag.size()) {
		cout << "Gresit\n";
		return;
	}
	this->agenda.stergeUnFavorit(poz - 1);
	//ag.erase(ag.begin() + poz - 1);
	cout << "Sters.\n";
	return;
}

void Ui::start() {
	while (true) {
		this->arataMeniu();
		int cerinta;
		cin >> cerinta;
		if (cerinta == 2) {
			adaugaContact();
		}
		else if (cerinta == 1) {
			afiseazaAgenda();
		}
		else if (cerinta == 0) {
			return;
		}
		else if (cerinta == 3) {
			stergeAgenda();
		}
		else if (cerinta == 4) {
			suna();
		}
		else if (cerinta == 8) {
			afiseazaIstoric();
		}
		else if (cerinta == 5) {
			adaugaFavorit();
		}
		else if (cerinta == 6) {
			afiseazaFavorite();
		}
		else if (cerinta == 7) {
			stergeFavorit();
		}
	}
}