//
// Created by Andra on 5/19/2024.
//

#ifndef OOP_FACTURAUTILITATI_H
#define OOP_FACTURAUTILITATI_H
#include "Factura.h"
#include "ContBancar.h"
#include <string>

template<typename Numar, typename Suma>
class FacturaUtilitati : public Factura<Numar, Suma> {
private:
    std::string tipUtilitate;
    static constexpr float comisionUtilitati = 10.0f;

public:
    FacturaUtilitati(Numar numar, Suma suma, const std::string& utilitate);
    FacturaUtilitati(const FacturaUtilitati& altaFactura);
    std::string getTipUtilitate() const;
    void afisareDetalii() const override;
    std::string getType() const override;
    void platesteFactura(ContBancar& contBancar) override;
    virtual ~FacturaUtilitati() = default;
};
#endif //OOP_FACTURAUTILITATI_H
