#include "Factura.h"

PlatesteFactura::PlatesteFactura(std::string tip, float s, std::string numar, float suma)
        : Tranzactie(std::move(tip), s), numarFactura(std::move(numar)), sumaFactura(suma), facturaPlatita(false) {}

void PlatesteFactura::procesTranzactie(ContBancar& contBancar) {
    if (!facturaPlatita) {
        sumaFactura = getSuma();
        if (contBancar.getsold_cont() >= sumaFactura) {
            if (sumaFactura > 500) {
                Tranzactie::setComision(5.0f);
            } else {
                Tranzactie::setComision(0.5f);
            }
            contBancar.setSold(contBancar.getsold_cont() - (sumaFactura + Tranzactie::comision));
            std::cout << "Factura " << numarFactura << " in valoare de " << sumaFactura << " a fost platita." << std::endl;
            std::cout << "Soldul curent al contului: " << contBancar.getsold_cont() << std::endl;
            facturaPlatita = true;
        } else {
            std::cout << "Fonduri insuficiente pentru plata facturii." << std::endl;
        }
    } else {
        std::cout << "Factura " << numarFactura << " a fost deja platita anterior." << std::endl;
    }
}

bool PlatesteFactura::esteFacturaPlatita() const {
    return facturaPlatita;
}

void PlatesteFactura::display(std::ostream &out) const {
    Tranzactie::display(out);
    out << "Numar factura: " << numarFactura << std::endl;
    out << "Suma factura: " << sumaFactura << std::endl;
    out << "Factura platita: " << (facturaPlatita ? "Da" : "Nu") << std::endl;
}

void PlatesteFactura::read(std::istream &in) {
    Tranzactie::read(in);
    in >> numarFactura;
    in >> sumaFactura;
    facturaPlatita = false;
}
//
// Created by Andra on 4/21/2024.
//
