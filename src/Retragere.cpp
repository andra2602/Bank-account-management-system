#include "Retragere.h"
#include "Exceptii.h"

Retragere::Retragere(float suma) : Tranzactie("retragere", suma) {}

[[maybe_unused]] Retragere::Retragere(const Retragere &r) : Tranzactie(r) {}

Retragere& Retragere::operator=(const Retragere &r) {
    Tranzactie::operator=(r);
    return *this;
}

void Retragere::procesTranzactie(ContBancar& contBancar) {
    float sumaTranzactie = getSuma();
    if (sumaTranzactie > 2000) {
        aruncaExceptieTranzactie("Suma retragerii depaseste 2000!");
    }
    if (contBancar.getsold_cont() >= sumaTranzactie) {
        if (sumaTranzactie > 500) {
            Tranzactie::setComision(5.0f);
        } else {
            Tranzactie::setComision(0.5f);
        }
        contBancar.setSold(contBancar.getsold_cont() - (sumaTranzactie + Tranzactie::comision));
        std::cout << "Retragere de " << sumaTranzactie << " procesată." << std::endl;
        std::cout << "A fost aplicat un comision de retragere, în valoare de: " << Tranzactie::comision << "." << std::endl;
        std::cout << "Soldul curent al contului: " << contBancar.getsold_cont() << std::endl;
    } else {
        std::cout << "Fonduri insuficiente pentru retragere." << std::endl;
    }
}

void Retragere::display(std::ostream &out) const {
    Tranzactie::display(out);
    out << "Aceasta tranzactie nu dispune de informatii aditionale. " << std::endl;
}

void Retragere::read(std::istream &in) {
    Tranzactie::read(in);
    std::cout << "Datele au fost introduse cu succes!" << std::endl;
}

void Retragere::afisareDetalii() const {
    std::cout << "Detalii despre retragere: suma = " << getSuma() << std::endl;
}

std::string Retragere::obtineTipTranzactie() const {
    return "Retragere";
}
//
// Created by Andra on 4/19/2024.
//
