#include <gtest/gtest.h>
#include "ContBancar.h"


TEST(ContBancarTestSuite, TestConstructoriSiGetteri) {
    ContBancar cont("John Doe", "123456123456123456123456", 1000.0f, "economii", "parola1234");

    EXPECT_EQ(cont.getTitularCont(), "John Doe");
    EXPECT_EQ(cont.getnumarCont(), "123456123456123456123456");
    EXPECT_EQ(cont.getsold_cont(), 1000.0f);
    EXPECT_EQ(cont.gettipCont(), "economii");
    EXPECT_EQ(cont.getparola(), "parola1234");
}


TEST(ContBancarTestSuite, TestOperatorAdunare) {
    ContBancar cont("John Doe", "123456123456123456123456", 1000.0f, "economii", "parola123");
    ContBancar contDupaAdunare = cont + 500.0f;

    EXPECT_EQ(contDupaAdunare.getsold_cont(), 1500.0f);
}

TEST(ContBancarTestSuite, TestOperatorScadere) {
    ContBancar cont("John Doe", "123456123456123456123456", 1000.0f, "economii", "parola123");

    /// Testare cu o sumă validă
    ContBancar contDupaScadere1 = cont - 500.0f;
    EXPECT_EQ(contDupaScadere1.getsold_cont(), 500.0f);

    /// Testare cu o sumă invalidă
    ContBancar contDupaScadere2 = cont - 1500.0f;
    /// Verificăm că soldul nu se modifică când suma de retragere depășește soldul
    EXPECT_EQ(contDupaScadere2.getsold_cont(), 1000.0f);
}

TEST(ContBancarTestSuite, TestConstructorDeCopiereSiOperatorDeAtribuire) {
    ContBancar cont1("John Doe", "123456", 1000.0f, "economii", "parola123");
    const ContBancar& cont2 = cont1; /// Constructor de copiere

    EXPECT_EQ(cont2.getTitularCont(), "John Doe");
    EXPECT_EQ(cont2.getnumarCont(), "123456");
    EXPECT_EQ(cont2.getsold_cont(), 1000.0f);
    EXPECT_EQ(cont2.gettipCont(), "economii");
    EXPECT_EQ(cont2.getparola(), "parola123");

    /// Verificare operator de atribuire
    ContBancar cont3("Jane Smith", "789012", 2000.0f, "salariu", "password456");
    cont3 = cont2;

    EXPECT_EQ(cont3.getTitularCont(), "John Doe");
    EXPECT_EQ(cont3.getnumarCont(), "123456");
    EXPECT_EQ(cont3.getsold_cont(), 1000.0f);
    EXPECT_EQ(cont3.gettipCont(), "economii");
    EXPECT_EQ(cont3.getparola(), "parola123");
}

TEST(ContBancarTestSuite, TestOperatorEgalitate) {
    ContBancar cont1("John Doe", "123456", 1000.0f, "economii", "parola123");
    ContBancar cont2("John Doe", "123456", 1000.0f, "economii", "parola123");
    ContBancar cont3("Jane Smith", "789012", 2000.0f, "salariu", "password456");

    /// Verificare egalitate între cont1 și cont2
    EXPECT_TRUE(cont1 == cont2);

    /// Verificare inegalitate între cont1 și cont3
    EXPECT_FALSE(cont1 == cont3);
}

//
// Created by Andra on 4/19/2024.
//
