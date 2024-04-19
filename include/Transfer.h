//
// Created by Andra on 4/19/2024.
//

#ifndef OOP_TRANSFER_H
#define OOP_TRANSFER_H
#include "Tranzactie.h"
#include "Exceptii.h"
#include "ContBancar.h"

class Transfer : public Tranzactie {
private:
    ContBancar* contBancar2;
public:
    Transfer(float suma, ContBancar* contBancar2);

    [[maybe_unused]] Transfer(const Transfer &t);
    Transfer& operator=(const Transfer &t);

    void procesTranzactie(ContBancar& contBancar) override;
    void display(std::ostream &out) const override;
    void read(std::istream &in) override;
    void afisareDetalii() const override;
    [[nodiscard]] std::string obtineTipTranzactie() const override;
    ContBancar* getContBancar2() const;

    ~Transfer() override = default;
};
#endif //OOP_TRANSFER_H
