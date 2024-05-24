//
// Created by Andra on 4/19/2024.
//

#ifndef OOP_EXCEPTII_H
#define OOP_EXCEPTII_H
#include <exception>

class Exceptie : public std::exception {
public:
    [[nodiscard]] const char* what() const noexcept override = 0;
};

class ExceptieTranz : public Exceptie {
private:
    const char* message;
public:
    explicit ExceptieTranz(const char* msg);
    [[nodiscard]] const char* what() const noexcept override;
};

void aruncaExceptieTranzactie(const char* errorMessage);

class EroareCont : public Exceptie {
public:
    [[nodiscard]] const char* what() const noexcept override;
};

void aruncaEroareCont();

class EroareAutentificare : public Exceptie {
private:
    const char* message;
public:
    explicit EroareAutentificare(const char* msg);
    [[nodiscard]] const char* what() const noexcept override;
};


#endif //OOP_EXCEPTII_H
