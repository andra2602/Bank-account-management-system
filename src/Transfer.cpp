#include "Transfer.h"
#include "Exceptii.h"

Transfer::Transfer(float suma, ContBancar* contBancar2) : Tranzactie("transfer", suma), contBancar2(contBancar2) {}

[[maybe_unused]] Transfer::Transfer(const Transfer &t) : Tranzactie(t), contBancar2(t.contBancar2) {}

Transfer& Transfer::operator=(const Transfer &t) {
    Tranzactie::operator=(t);
    contBancar2 = t.contBancar2;
    return *this;
}

void Transfer::procesTranzactie(ContBancar& contBancar) {
    float sumaTranzactie = getSuma();
    if (sumaTranzactie > 2000) {
        aruncaExceptieTranzactie("Suma solicitata pentru transfer depaseste pragul de 2000!");
    }
    if (sumaTranzactie > 500) {
        Tranzactie::setComision(5.0f);
    } else {
        Tranzactie::setComision(0.5f);
    }

    float sumaTransfer = sumaTranzactie + Tranzactie::comision;

    if (sumaTransfer <= contBancar.getsold_cont()) {
        contBancar.setSold(contBancar.getsold_cont() - sumaTransfer);
        if (sumaTranzactie > 500) {
            Tranzactie::setComision(0.02f);
        } else {
            Tranzactie::setComision(0.005f);
        }
        contBancar2->setSold(contBancar2->getsold_cont() + sumaTranzactie * (1 - Tranzactie::comision));
        std::cout << "Suma de " << sumaTranzactie << " a fost transferata catre " << contBancar2->getTitularCont() << ", cu contul " << contBancar2->getnumarCont() << std::endl;
        std::cout << "Transferul a fost realizat cu succes." << std::endl;
        std::cout << "Soldul dumneavoastra curent este: " << contBancar.getsold_cont() << std::endl;
    } else {
        std::cout << "Fonduri insuficiente pentru transfer." << std::endl;
    }
}

void Transfer::display(std::ostream &out) const {
    Tranzactie::display(out);
    out << "Iar contul catre care ati efectuat transferul este detinut de utilizatorul: " << contBancar2->getTitularCont() << std::endl;
}

void Transfer::read(std::istream &in) {
    Tranzactie::read(in);
    std::cout << "Datele au fost introduse cu succes!" << std::endl;
}

void Transfer::afisareDetalii() const {
    if (contBancar2 != nullptr) {
        std::cout << "Detalii despre transfer: suma = " << getSuma() << ", catre contul cu numarul " << contBancar2->getnumarCont() << std::endl;
    }
}

std::string Transfer::obtineTipTranzactie() const {
    return "Transfer";
}

//
// Created by Andra on 4/19/2024.
//
