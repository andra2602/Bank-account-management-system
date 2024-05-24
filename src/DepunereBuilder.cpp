#include "DepunereBuilder.h"

DepunereBuilder::DepunereBuilder() : suma(0.0f) {}

DepunereBuilder& DepunereBuilder::setSuma(float s) {
    this->suma = s;
    return *this;
}

Depunere DepunereBuilder::build() const {
    return Depunere(suma);
}