#include <gtest/gtest.h>
#include "Depunere.h"
#include "ContBancar.h"
#include "Exceptii.h"

TEST(DepunereTestSuite, TestConstructoriSiGetteri) {
    Depunere depunere(500.0f);

    EXPECT_EQ(depunere.obtineTipTranzactie(), "Depunere");
    EXPECT_EQ(depunere.getSuma(), 500.0f);
}

TEST(DepunereTestSuite, TestProcesTranzactie) {
    ContBancar cont("John Doe", "123456", 1000.0f, "economii", "parola123");
    Depunere depunere(200.0f);

    depunere.procesTranzactie(cont);

    EXPECT_EQ(cont.getsold_cont(), 1199.0f);
}

TEST(DepunereTestSuite, TestProcesTranzactieDepasirePragMaxim) {
    // Creăm un cont bancar cu un sold inițial de 1000 și tipul "economii"
    ContBancar cont("John Doe", "123456", 1000.0f, "economii", "parola123");

    // Creăm o depunere cu o sumă care depășește pragul maxim
    Depunere depunere(70000.0f);

    // Verificăm că atunci când încercăm să procesăm tranzacția,
    // se aruncă o excepție și soldul rămâne neschimbat
    EXPECT_THROW(depunere.procesTranzactie(cont), ExceptieTranz);
    EXPECT_EQ(cont.getsold_cont(), 1000.0f);
}

TEST(DepunereTestSuite, TestAfisareDetalii) {
    Depunere depunere(300.0f);

    /// Redirecționăm ieșirea standard catre un stream pentru a putea verifica afișarea
    testing::internal::CaptureStdout();
    depunere.afisareDetalii();
    std::string output = testing::internal::GetCapturedStdout();

    /// Verificăm dacă șirul obținut este cel așteptat
    EXPECT_EQ(output, "Detalii despre depunere: suma = 300\n");
}

TEST(DepunereTestSuite, TestConstructorDeCopiere) {
    // Creăm o depunere inițială
    Depunere depunere1(500.0f);

    // Folosim constructorul de copiere pentru a crea o a doua depunere
    const Depunere& depunere2(depunere1);

    // Verificăm că cele două depuneri au aceeași sumă
    EXPECT_EQ(depunere1.getSuma(), depunere2.getSuma());
}

TEST(DepunereTestSuite, TestOperatorDeAtribuire) {
    // Creăm două depuneri cu sume diferite
    Depunere depunere1(200.0f);
    Depunere depunere2(300.0f);

    // Folosim operatorul de atribuire pentru a atribui depunerea2 depuneri1
    depunere1 = depunere2;

    // Verificăm că suma depunerii1 este acum aceeași cu suma depunerii2
    EXPECT_EQ(depunere1.getSuma(), depunere2.getSuma());
}

//
// Created by Andra on 4/19/2024.
//
