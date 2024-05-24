//
// Created by Andra on 5/20/2024.
//

#ifndef OOP_DEPUNEREBUILDER_H
#define OOP_DEPUNEREBUILDER_H
#include "Depunere.h"

class DepunereBuilder {
private:
    float suma;
public:
    DepunereBuilder();

    DepunereBuilder& setSuma(float s);

    Depunere build() const;
};
#endif //OOP_DEPUNEREBUILDER_H
