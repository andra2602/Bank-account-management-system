#include "Depunere.h"
#include "Exceptii.h" // Pentru a utiliza aruncarea excepției în procesTranzactie

Depunere::Depunere(float suma) : Tranzactie("depunere", suma) {}

[[maybe_unused]] Depunere::Depunere(const Depunere &d) : Tranzactie(d) {}

Depunere& Depunere::operator=(const Depunere& d) {
    Tranzactie::operator=(d);
    return *this;
}

void Depunere::procesTranzactie(ContBancar& contBancar) {
    float sumaTranzactie = getSuma();
    if (sumaTranzactie > PRAG_MAX_DEPUNERE) {
        aruncaExceptieTranzactie("Suma depunerii este prea mare! Nu se pot realiza depuneri cu astfel de sume!");
    }
    if (sumaTranzactie > 500) {
        Tranzactie::setComision(0.02f);
    } else {
        Tranzactie::setComision(0.005f);
    }
    contBancar.setSold(contBancar.getsold_cont() + sumaTranzactie * (1 - Tranzactie::comision));
    std::cout << "Depunere de " << sumaTranzactie << " procesată." << std::endl;
    std::cout << "A fost aplicat un comision de depunere, în valoare de: " << sumaTranzactie * Tranzactie::comision << "." << std::endl;
    std::cout << "Soldul curent al contului: " << contBancar.getsold_cont() << std::endl;
}

void Depunere::display(std::ostream &out) const {
    Tranzactie::display(out);
    out << "Iar pragul maxim de depunere este: " << PRAG_MAX_DEPUNERE << std::endl;
}

void Depunere::read(std::istream &in) {
    Tranzactie::read(in);
    std::cout << "Datele au fost introduse cu succes!" << std::endl;
}

void Depunere::afisareDetalii() const {
    std::cout << "Detalii despre depunere: suma = " << getSuma() << std::endl;
}

std::string Depunere::obtineTipTranzactie() const {
    return "Depunere";
}
//
// Created by Andra on 4/19/2024.
//