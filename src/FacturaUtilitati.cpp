#include "FacturaUtilitati.h"

template<typename Numar, typename Suma>
FacturaUtilitati<Numar, Suma>::FacturaUtilitati(Numar numar, Suma suma, const std::string& utilitate) :
        Factura<Numar, Suma>(numar, suma), tipUtilitate(utilitate) {}

template<typename Numar, typename Suma>
FacturaUtilitati<Numar, Suma>::FacturaUtilitati(const FacturaUtilitati& altaFactura) :
        Factura<Numar, Suma>(altaFactura), tipUtilitate(altaFactura.tipUtilitate) {}

template<typename Numar, typename Suma>
std::string FacturaUtilitati<Numar, Suma>::getTipUtilitate() const {
    return tipUtilitate;
}

template<typename Numar, typename Suma>
void FacturaUtilitati<Numar, Suma>::afisareDetalii() const {
    Factura<Numar, Suma>::afisareDetalii();
    std::cout << "Tip utilitate: " << tipUtilitate << std::endl;
}
template<typename Numar, typename Suma>
std::string FacturaUtilitati<Numar, Suma>::getType() const {
    return "FacturaUtilitati";
}
template<typename Numar, typename Suma>
void FacturaUtilitati<Numar, Suma>::platesteFactura(ContBancar& contBancar) {
    if (!this->platita ) {
        float suma = this->sumaPlata + comisionUtilitati;
        if(contBancar.getsold_cont() >= suma){
            contBancar.setSold(contBancar.getsold_cont() - suma);
            std::cout << "Factura de utilitati " << this->numarFactura << " pentru " << tipUtilitate << " in valoare de " << this->sumaPlata << " a fost platita." << std::endl;
            std::cout << "Soldul curent al contului: " << contBancar.getsold_cont() << std::endl;
            this->platita = true;
        }
        else {
            std::cout << "Fonduri insuficiente pentru plata facturii de utilitati." << std::endl;
        }
    }
    else {
        std::cout << "Factura de utilitati " << this->numarFactura << " pentru " << tipUtilitate << " a fost deja platita anterior." << std::endl;
    }
}
template class FacturaUtilitati<int,float>;
//
// Created by Andra on 5/19/2024.
//
