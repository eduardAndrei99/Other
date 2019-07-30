#pragma once
#include <string>

using std::string;

class Contact {
private:
	string nume;
	string numarTelefon;

public:
	Contact(string nume, string numarTelefon) : nume{ nume }, numarTelefon{ numarTelefon } {
	}

	/*
	 * Functie ce returneaza numele din contact
	 */
	string getNume() const {
		return this->nume;
	}

	/*
	 * Functie ce returneaza numarul de telefon din contact
	 */
	string getNumarTelefon() const{
		return this->numarTelefon;
	}

};