#include <gtest/gtest.h>
#include "Transfer.h"
#include "ContBancar.h"
#include "Exceptii.h"

TEST(TransferTestSuite, TestConstructorSiGetterContBancar2) {
    // Cream un cont bancar pentru destinatarul transferului
    ContBancar destinatar("Destinatar", "123456", 1000.0f, "curent", "parola123");

    // Cream un transfer cu o suma si contul bancar al destinatarului
    Transfer transfer(500.0f, &destinatar);

    // Verificam ca getter-ul pentru contul bancar al destinatarului returneaza contul corect
    EXPECT_EQ(transfer.getContBancar2(), &destinatar);
}

TEST(TransferTestSuite, TestProcesTranzactieSumaAcceptata) {
    // Cream un cont bancar pentru expeditorul transferului cu un sold de 2000
    ContBancar expeditor("Expeditor", "789123", 2000.0f, "curent", "parola789");

    // Cream un cont bancar pentru destinatarul transferului cu un sold de 1000
    ContBancar destinatar("Destinatar", "123456", 1000.0f, "curent", "parola123");

    // Cream un transfer cu o suma si contul bancar al destinatarului
    Transfer transfer(500.0f, &destinatar);

    // Procesam tranzactia
    transfer.procesTranzactie(expeditor);

    // Verificam ca soldul expeditorului s-a actualizat corect
    EXPECT_EQ(expeditor.getsold_cont(), 1499.5f);
    // Verificam ca soldul destinatarului s-a actualizat corect
    EXPECT_EQ(destinatar.getsold_cont(), 1497.5f);
}

TEST(TransferTestSuite, TestProcesareTranzactieSumaNeacceptata) {
    // Cream un cont bancar pentru destinatarul transferului
    ContBancar destinatar("Destinatar", "123456", 1000.0f, "curent", "parola123");

    // Cream un cont bancar pentru expeditorul transferului
    ContBancar expeditor("Expeditor", "654321", 2000.0f, "economii", "parola456");

    // Cream un transfer cu o suma care depaseste pragul acceptat
    Transfer transfer(3000.0f, &destinatar);

    // Procesam tranzactia
    testing::internal::CaptureStdout(); // Redirectionam stdout pentru a testa iesirea

    transfer.procesTranzactie(expeditor);

    std::string output = testing::internal::GetCapturedStdout(); // Capturam iesirea

    // Verificam daca s-a afisat mesajul corespunzator pentru suma neacceptata
    EXPECT_TRUE(output.find("Suma solicitata pentru transfer depaseste pragul de 2000!") != std::string::npos);
}

TEST(TransferTestSuite, TestDisplay) {
    // Cream un cont bancar pentru destinatarul transferului
    ContBancar destinatar("Destinatar", "123456", 1000.0f, "curent", "parola123");

    // Cream un transfer cu o suma si contul bancar al destinatarului
    Transfer transfer(500.0f, &destinatar);

    // Redirectionam iesirea standard catre un stream
    std::stringstream output;

    // Apelam metoda display pentru transfer
    transfer.display(output);

    // Verificam ca afisarea contine corect informatiile despre transfer
    std::string expectedOutput = "Tip tranzactie: transfer\nSuma: 500\nIar contul catre care ati efectuat transferul este detinut de utilizatorul: Destinatar\n";
    EXPECT_EQ(output.str(), expectedOutput);
}

TEST(TransferTestSuite, TestRead) {
    // Cream un cont bancar pentru destinatarul transferului
    ContBancar destinatar("Destinatar", "123456", 1000.0f, "curent", "parola123");

    // Cream un transfer
    Transfer transfer(0.0f, &destinatar);

    // Cream un flux de intrare cu date simulate
    std::istringstream input("transfer 500");

    // Citim datele din flux
    transfer.read(input);

    // Verificam ca datele au fost citite corect
    EXPECT_EQ(transfer.getSuma(), 500.0f);
    EXPECT_EQ(transfer.obtineTipTranzactie(), "Transfer");
}

TEST(TransferTestSuite, TestObtineTipTranzactie) {
    // Cream un cont bancar pentru destinatarul transferului
    ContBancar destinatar("Destinatar", "123456", 1000.0f, "curent", "parola123");

    // Cream un transfer cu o suma si contul bancar al destinatarului
    Transfer transfer(500.0f, &destinatar);

    // Verificam ca metoda obtineTipTranzactie returneaza corect tipul tranzactiei
    EXPECT_EQ(transfer.obtineTipTranzactie(), "Transfer");
}

TEST(TransferTestSuite, TestConstructorCopiere) {
    // Cream un cont bancar pentru destinatarul transferului
    ContBancar destinatar("Destinatar", "123456", 1000.0f, "curent", "parola123");

    // Cream un transfer cu o suma si contul bancar al destinatarului
    Transfer transfer1(500.0f, &destinatar);

    // Copiem transferul initial
    Transfer transfer2(transfer1);

    // Verificam daca suma si contul bancar sunt aceleasi pentru cele doua transferuri
    EXPECT_FLOAT_EQ(transfer1.getSuma(), transfer2.getSuma());
    EXPECT_EQ(transfer1.getContBancar2(), transfer2.getContBancar2());
}

TEST(TransferTestSuite, TestOperatorAtribuire) {
    // Cream un cont bancar pentru destinatarul transferului
    ContBancar destinatar("Destinatar", "123456", 1000.0f, "curent", "parola123");

    // Cream doua transferuri cu sume diferite si acelasi cont bancar destinatar
    Transfer transfer1(500.0f, &destinatar);
    Transfer transfer2(1000.0f, &destinatar);

    // Folosim operatorul de atribuire pentru a asigna transferul 1 transferului 2
    transfer2 = transfer1;

    // Verificam daca suma si contul bancar sunt aceleasi pentru cele doua transferuri
    EXPECT_FLOAT_EQ(transfer1.getSuma(), transfer2.getSuma());
    EXPECT_EQ(transfer1.getContBancar2(), transfer2.getContBancar2());
}


//
// Created by Andra on 4/19/2024.
//
