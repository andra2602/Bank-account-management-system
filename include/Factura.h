//
// Created by Andra on 4/21/2024.
//

#ifndef OOP_FACTURA_H
#define OOP_FACTURA_H
#include <iostream>
#include "ContBancar.h"

template<typename Numar, typename Suma>
class Factura {
protected:
    Numar numarFactura;
    Suma sumaPlata;
    bool platita;
    float comision;
public:
    Factura(Numar numar, Suma suma);
    Factura(const Factura& altaFactura);
    Numar getNumarFactura() const;
    Suma getSumaPlata() const;
    bool estePlatita() const;

    virtual std::string getType() const;
    virtual void afisareDetalii() const;
    virtual void platesteFactura(ContBancar& contBancar) = 0;
    virtual ~Factura();
};
#endif //OOP_FACTURA_H
