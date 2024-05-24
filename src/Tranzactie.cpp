#include "Tranzactie.h"

void Tranzactie::display(std::ostream &out) const {
    out << "Tip tranzactie: " << tipTranzactie << std::endl;
    out << "Suma: " << suma << std::endl;
}

void Tranzactie::read(std::istream &in) {
    in >> tipTranzactie;
    in >> suma;
}

Tranzactie::Tranzactie(std::string tip, float s) : tipTranzactie(std::move(tip)), suma(s) {}

Tranzactie::Tranzactie(const Tranzactie &t) {
    this->tipTranzactie = t.tipTranzactie;
    this->suma = t.suma;
}

Tranzactie& Tranzactie::operator=(const Tranzactie &t) {
    if (this != &t) {
        tipTranzactie = t.tipTranzactie;
        suma = t.suma;
    }
    return *this;
}

std::ostream& operator<<(std::ostream &out, const Tranzactie &tranzactie) {
    tranzactie.display(out);
    return out;
}

std::istream& operator>>(std::istream &in, Tranzactie &tranzactie) {
    tranzactie.read(in);
    return in;
}
bool Tranzactie::operator<(const Tranzactie& other) const {
    return suma < other.suma;
}

[[maybe_unused]] float Tranzactie::comision = 0.005f;

[[maybe_unused]] void Tranzactie::setComision(float value) {
    comision = value;
}

float Tranzactie::getSuma() const {
    return suma;
}

std::string Tranzactie::obtineTipTranzactie() const {
    return tipTranzactie;
}//
// Created by Andra on 4/19/2024.
//
