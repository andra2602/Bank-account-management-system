//
// Created by Andra on 4/21/2024.
//

#ifndef OOP_FACTURA_H
#define OOP_FACTURA_H
#include "Tranzactie.h"
#include "ContBancar.h"

class PlatesteFactura : public Tranzactie {
private:
    std::string numarFactura;
    float sumaFactura;
    bool facturaPlatita;

public:
    PlatesteFactura(std::string tip, float s, std::string numar, float suma);

    void procesTranzactie(ContBancar& contBancar) override;
    bool esteFacturaPlatita() const;
    void display(std::ostream &out) const override;
    void read(std::istream &in) override;
};
#endif //OOP_FACTURA_H
