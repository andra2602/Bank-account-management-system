//
// Created by Andra on 5/20/2024.
//

#ifndef OOP_CONTBANCARBUILDER_H
#define OOP_CONTBANCARBUILDER_H
#include "ContBancar.h"

class ContBancarBuilder {
private:
    ContBancar cb;
public:


    ContBancarBuilder& setTitular(const std::string &TitularCont){
        this->cb.TitularCont = TitularCont;
        return *this;
    }
    ContBancarBuilder& setNumarCont(const std::string &numarCont){
        this->cb.numarCont = numarCont;
        return *this;
    }
    ContBancarBuilder& setSold(const float &sold_cont){
        this->cb.sold_cont = sold_cont;
        return *this;
    }
    ContBancarBuilder& setTip(const std::string &tipCont){
        this->cb.tipCont = tipCont;
        return *this;
    }
    ContBancarBuilder& setParola(const std::string &parola){
        this->cb.parola = parola;
        return *this;
    }
    ContBancar build()
    {
        return cb;
    }
};
#endif //OOP_CONTBANCARBUILDER_H
