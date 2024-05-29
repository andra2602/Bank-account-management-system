#include <gtest/gtest.h>
#include "Transfer.h"
#include "ContBancar.h"
#include "Exceptii.h"

TEST(TransferTestSuite, TestConstructor) {
    // Cream un cont bancar pentru destinatarul transferului
    ContBancar destinatar("Destinatar", "123456", 1000.0f, "curent", "parola123");

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

#include <stdexcept>

TEST(TransferTest, SumaNeconforma) {
    ContBancar expeditor("Expeditor", "789123", 2000.0f, "curent", "parola789");

    // Cream un cont bancar pentru destinatarul transferului cu un sold de 1000
    ContBancar destinatar("Destinatar", "123456", 1000.0f, "curent", "parola123");

    // Transferăm o sumă mai mare decât pragul maxim permis
    Transfer transfer(2500.0f, &destinatar);

    // Verificăm că funcția aruncă excepția corespunzătoare
    EXPECT_THROW(transfer.procesTranzactie(expeditor), ExceptieTranz);

    // Verificăm că nu s-a modificat soldul contului inițial
    EXPECT_FLOAT_EQ(expeditor.getsold_cont(), 2000.0);

    // Verificăm că nu s-a modificat soldul contului destinatar
    EXPECT_FLOAT_EQ(destinatar.getsold_cont(), 1000.0);
}




//
// Created by Andra on 4/19/2024.
//
