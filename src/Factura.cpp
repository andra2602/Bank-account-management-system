#include "Factura.h"

template<typename Numar, typename Suma>
Factura<Numar, Suma>::Factura(Numar numar, Suma suma) : numarFactura(numar), sumaPlata(suma), platita(false), comision(5) {}

template<typename Numar, typename Suma>
Factura<Numar, Suma>::Factura(const Factura& altaFactura) : numarFactura(altaFactura.numarFactura), sumaPlata(altaFactura.sumaPlata), platita(altaFactura.platita), comision(altaFactura.comision) {}

template<typename Numar, typename Suma>
bool Factura<Numar, Suma>::estePlatita() const { return platita; }

template<typename Numar, typename Suma>
void Factura<Numar, Suma>::afisareDetalii() const {
    std::cout << "Numar factura: " << numarFactura << std::endl;
    std::cout << "Suma plata: " << sumaPlata << std::endl;
}
template<typename Numar, typename Suma>
std::string Factura<Numar, Suma>::getType() const {
    return "Factura";
}
template<typename Numar, typename Suma>
Factura<Numar, Suma>::~Factura() = default;

template class Factura<int,float>;
