#include "ContBancar.h"

ContBancar::ContBancar(std::string titular, std::string numar, float sold, std::string tip, std::string pass)
        : TitularCont(std::move(titular)), numarCont(std::move(numar)), sold_cont(sold), tipCont(std::move(tip)), parola(std::move(pass)) {}
ContBancar::ContBancar(std::string titular, std::string numar, float sold)
        : TitularCont(std::move(titular)), numarCont(std::move(numar)), sold_cont(sold) {}

ContBancar::ContBancar(const ContBancar &auxiliar) {
    this->numarCont = auxiliar.numarCont;
    this->sold_cont = auxiliar.sold_cont;
    this->TitularCont = auxiliar.TitularCont;
    this->tipCont = auxiliar.tipCont;
    this->parola = auxiliar.parola;
}

ContBancar &ContBancar::operator=(const ContBancar &cb) {
    this->numarCont = cb.numarCont;
    this->sold_cont = cb.sold_cont;
    this->TitularCont = cb.TitularCont;
    this->tipCont = cb.tipCont;
    this->parola = cb.parola;
    return *this;
}

bool ContBancar::operator==(const ContBancar &cb) const {
    return (TitularCont == cb.TitularCont && numarCont == cb.numarCont && sold_cont == cb.sold_cont && tipCont == cb.tipCont && parola == cb.parola);
}

std::istream &operator>>(std::istream &in, ContBancar &cb) {
    std::cout << "Introduceti numele clientului: ";
    in >> cb.TitularCont;
    std::cout << "Introduceti parola: ";
    in >> cb.parola;
    in >> cb.numarCont;
    in >> cb.sold_cont;
    in >> cb.tipCont;
    return in;
}

std::ostream &operator<<(std::ostream &out, const ContBancar &cb) {
    out << "Titular cont: " << cb.getTitularCont() << std::endl;
    out << "Număr cont: " << cb.getnumarCont() << std::endl;
    out << "Sold cont: " << cb.getsold_cont() << std::endl;
    out << "Tip cont: " << cb.gettipCont() << std::endl;
    out << "----------------------------------" << std::endl;

    return out;
}

std::string ContBancar::getTitularCont() const { return TitularCont; }
std::string ContBancar::getnumarCont() const { return numarCont; }
float ContBancar::getsold_cont() const { return sold_cont; }
std::string ContBancar::gettipCont() const { return tipCont; }
std::string ContBancar::getparola() const { return parola; }

void ContBancar::setSold(float suma) { sold_cont = suma; }

ContBancar operator+(const ContBancar &cb, float suma) {
    ContBancar temp(cb);
    temp.depune_suma(suma);
    return temp;
}

void ContBancar::depune_suma(float suma) { sold_cont += suma; }

ContBancar operator-(const ContBancar &cb, float suma) {
    ContBancar temp(cb);
    if (suma < temp.getsold_cont()) {
        temp.retrage_suma(suma);
    }
    return temp;
}

void ContBancar::retrage_suma(float suma) {
    if (suma <= sold_cont && suma <= 2000) {
        sold_cont -= suma;
    } else {
        std::cout << "Procesul nu poate fi realizat." << std::endl;
    }
}

ContBancar::~ContBancar() = default;
//
// Created by Andra on 4/19/2024.
//
