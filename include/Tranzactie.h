//
// Created by Andra on 4/19/2024.
//

#ifndef OOP_TRANZACTIE_H
#define OOP_TRANZACTIE_H

#include <iostream>
#include <string>
#include "ContBancar.h" // Pentru a utiliza clasa ContBancar

class Tranzactie {
private:
    std::string tipTranzactie;
    float suma{};
protected:
    virtual void display(std::ostream &out) const;
    virtual void read(std::istream &in);
public:
    Tranzactie(std::string tip, float s);
    Tranzactie(const Tranzactie &t);
    Tranzactie& operator=(const Tranzactie &t);
    friend std::ostream& operator<<(std::ostream &out, const Tranzactie &tranzactie);
    friend std::istream& operator>>(std::istream &in, Tranzactie &tranzactie);
    bool operator<(const Tranzactie& other) const;
    [[maybe_unused]] static float comision;

    [[maybe_unused]] static void setComision(float value);

    virtual void procesTranzactie(ContBancar& contBancar) = 0;
    [[nodiscard]] float getSuma() const;
    virtual void afisareDetalii() const = 0;
    [[nodiscard]] virtual std::string obtineTipTranzactie() const;

    virtual ~Tranzactie() = default;
};
#endif //OOP_TRANZACTIE_H
