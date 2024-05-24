//
// Created by Andra on 4/19/2024.
//

#ifndef OOP_DEPUNERE_H
#define OOP_DEPUNERE_H
#include "Tranzactie.h"
class DepunereBuilder;
class Depunere : public Tranzactie {
private:
    static constexpr float PRAG_MAX_DEPUNERE = 10000.0f;
    friend class DepunereBuilder;
    explicit Depunere(float suma);
public:

    [[maybe_unused]] Depunere(const Depunere &d);
    Depunere& operator=(const Depunere& d);

    void procesTranzactie(ContBancar& contBancar) override;
    void display(std::ostream &out) const override;
    void read(std::istream &in) override;
    void afisareDetalii() const override;
    [[nodiscard]] std::string obtineTipTranzactie() const override;

    ~Depunere() override = default;
};

#endif //OOP_DEPUNERE_H
