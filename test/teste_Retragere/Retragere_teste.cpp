#include <gtest/gtest.h>
#include "Retragere.h"
#include "ContBancar.h"
#include "Exceptii.h"

TEST(RetragereTestSuite, TestConstructorCuSuma) {
    // Creăm o retragere cu o sumă specificată
    Retragere retragere(500.0f);

    // Verificăm că suma retragerii este cea specificată
    EXPECT_EQ(retragere.getSuma(), 500.0f);
}

TEST(RetragereTestSuite, TestConstructorDeCopiere) {
    // Creăm o retragere inițială
    Retragere retragere1(300.0f);

    // Folosim constructorul de copiere pentru a crea o a doua retragere
    Retragere retragere2(retragere1);

    // Verificăm că cele două retrageri au aceeași sumă
    EXPECT_EQ(retragere1.getSuma(), retragere2.getSuma());
}

TEST(RetragereTestSuite, TestGetteri) {
    // Creăm o retragere inițială
    Retragere retragere(400.0f);

    // Verificăm că getterul returnează corect suma
    EXPECT_EQ(retragere.getSuma(), 400.0f);

}

TEST(RetragereTestSuite, TestOperatorDeAtribuire) {
    // Creăm două retrageri cu sume diferite
    Retragere retragere1(500.0f);
    Retragere retragere2(700.0f);

    // Folosim operatorul de atribuire pentru a atribui retragerea2 retragerii1
    retragere1 = retragere2;

    // Verificăm că suma retragerii1 este acum aceeași cu suma retragerii2
    EXPECT_EQ(retragere1.getSuma(), retragere2.getSuma());
}
TEST(RetragereTestSuite, TestProcesTranzactieSumaAcceptata) {
    // Creăm un cont bancar cu un sold inițial de 1500
    ContBancar cont("John Smith", "789123", 1500.0f, "curent", "parola789");

    // Creăm o retragere cu o sumă acceptată
    Retragere retragere(700.0f);

    // Procesăm tranzacția
    retragere.procesTranzactie(cont);

    // Verificăm că soldul contului a fost actualizat corect după retragere
    EXPECT_EQ(cont.getsold_cont(), 795.0f);
}

TEST(RetragereTestSuite, TestProcesTranzactieSumaDepasestePragMaxim) {
    // Creăm un cont bancar cu un sold inițial de 3000
    ContBancar cont("Jane Doe", "654321", 3000.0f, "curent", "parola456");

    // Creăm o retragere cu o sumă care depășește pragul maxim
    Retragere retragere(2500.0f);

    // Verificăm că atunci când încercăm să procesăm tranzacția,
    // se aruncă o excepție și soldul rămâne neschimbat
    EXPECT_THROW(retragere.procesTranzactie(cont), ExceptieTranz);
    EXPECT_EQ(cont.getsold_cont(), 3000.0f);
}
TEST(RetragereTestSuite, TestDisplay) {
    // Creăm o retragere cu o sumă specificată
    Retragere retragere(500.0f);

    // Redirecționăm ieșirea standard către un stream
    std::stringstream output;

    // Apelăm metoda display pentru retragere
    retragere.display(output);

    // Verificăm că afișarea conține corect informațiile despre retragere
    std::string expectedOutput = "Tip tranzactie: retragere\nSuma: 500\nAceasta tranzactie nu dispune de informatii aditionale. \n";
    EXPECT_EQ(output.str(), expectedOutput);
}
TEST(RetragereTestSuite, TestRead) {
    // Redirecționăm intrarea standard către un stream
    std::stringstream input("retragere\n600\n");

    // Creăm o retragere
    Retragere retragere(0.0f);

    // Apelăm metoda read pentru retragere
    retragere.read(input);

    // Verificăm că suma a fost citită corect
    EXPECT_EQ(retragere.getSuma(), 600.0f);
}

TEST(RetragereTestSuite, TestObtineTipTranzactie) {
    // Creăm o retragere
    Retragere retragere(0.0f);

    // Verificăm că metoda obtineTipTranzactie returnează corect tipul tranzacției
    EXPECT_EQ(retragere.obtineTipTranzactie(), "Retragere");
}
//
// Created by Andra on 4/19/2024.
//
