//
// Created by Andra on 4/19/2024.
//

#ifndef OOP_CONTBANCAR_H
#define OOP_CONTBANCAR_H

#include <iostream>
#include <string>

class ContBancar {
private:
    std::string TitularCont;
    std::string numarCont;
    float sold_cont;
    std::string tipCont;
    std::string parola;

public:
    friend class ContBancarBuilder;
    explicit ContBancar(std::string titular = "-", std::string numar = "000000000000000000000000", float sold = 0.0, std::string tip = "personal", std::string pass = "0000");
    ContBancar(std::string titular, std::string numar, float sold);
    ContBancar(const ContBancar &auxiliar);
    ContBancar &operator=(const ContBancar &cb);
    bool operator==(const ContBancar &cb) const;

    friend std::istream &operator>>(std::istream &in, ContBancar &cb);
    friend std::ostream &operator<<(std::ostream &out, const ContBancar &cb);

    [[nodiscard]] std::string getTitularCont() const;
    [[nodiscard]] std::string getnumarCont() const;
    [[nodiscard]] float getsold_cont() const;
    [[nodiscard]] std::string gettipCont() const;
    [[nodiscard]] std::string getparola() const;

    void setSold(float suma);

    friend ContBancar operator+(const ContBancar &cb, float suma);
    void depune_suma(float suma);
    friend ContBancar operator-(const ContBancar &cb, float suma);
    void retrage_suma(float suma);
    ~ContBancar();
};
#endif //OOP_CONTBANCAR_H
