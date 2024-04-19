#include "Exceptii.h"

// Implementarea clasei ExceptieTranz
ExceptieTranz::ExceptieTranz(const char* msg) : message(msg) {}

const char* ExceptieTranz::what() const noexcept {
    return this->message;
}

void aruncaExceptieTranzactie(const char* errorMessage) {
    throw ExceptieTranz(errorMessage);
}

// Implementarea clasei EroareCont
const char* EroareCont::what() const noexcept {
    return "Numarul de cont nu este valid. Va rugam sa reincercati.";
}

void aruncaEroareCont() {
    throw EroareCont();
}

// Implementarea clasei EroareAutentificare
EroareAutentificare::EroareAutentificare(const char* msg) : message(msg) {}

const char* EroareAutentificare::what() const noexcept {
    return this->message;
}

void aruncaEroareAutentificare(const char* errorMessage) {
    throw EroareAutentificare(errorMessage);
}
//
// Created by Andra on 4/19/2024.
//
