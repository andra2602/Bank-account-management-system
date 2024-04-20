//
// Created by Andra on 4/19/2024.
//

#ifndef OOP_RETRAGERE_H
#define OOP_RETRAGERE_H
#include "Tranzactie.h"
#include "Exceptii.h"

class Retragere : public Tranzactie {
public:
    explicit Retragere(float suma);

    [[maybe_unused]] Retragere(const Retragere &r);
    Retragere& operator=(const Retragere &r);

    void procesTranzactie(ContBancar& contBancar) override;
    void display(std::ostream &out) const override;
    void read(std::istream &in) override;
    void afisareDetalii() const override;
    [[nodiscard]] std::string obtineTipTranzactie() const override;

    ~Retragere() override = default;
};
#endif //OOP_RETRAGERE_H
