#include <gtest/gtest.h>
#include "Exceptii.h"

/// Test pentru aruncarea si capturarea exceptiei ExceptieTranz
TEST(ExceptionTestSuite, TestExceptieTranz) {
    const char* errorMessage = "A aparut o exceptie de tranzactie!";
    try {
        aruncaExceptieTranzactie(errorMessage);
        FAIL() << "Exceptie ExceptieTranz nu a fost aruncata!";
    } catch (const ExceptieTranz& e) {
        EXPECT_STREQ(e.what(), errorMessage);
    } catch (...) {
        FAIL() << "Exceptie ExceptieTranz aruncata, dar nu a fost capturata corect!";
    }
}


/// Test pentru aruncarea si capturarea exceptiei EroareCont
TEST(ExceptionTestSuite, TestEroareCont) {
    try {
        aruncaEroareCont();
        FAIL() << "Exceptie EroareCont nu a fost aruncata!";
    } catch (const EroareCont& e) {
        EXPECT_STREQ(e.what(), "Numarul de cont nu este valid. Va rugam sa reincercati.");
    } catch (...) {
        FAIL() << "Exceptie EroareCont aruncata, dar nu a fost capturata corect!";
    }
}

/// Test pentru aruncarea si capturarea exceptiei EroareAutentificare
TEST(ExceptionTestSuite, TestEroareAutentificare) {
    const char* errorMessage = "A aparut o eroare de autentificare!";
    try {
        aruncaEroareAutentificare(errorMessage);
        FAIL() << "Exceptie EroareAutentificare nu a fost aruncata!";
    } catch (const EroareAutentificare& e) {
        EXPECT_STREQ(e.what(), errorMessage);
    } catch (...) {
        FAIL() << "Exceptie EroareAutentificare aruncata, dar nu a fost capturata corect!";
    }
}
//
// Created by Andra on 4/19/2024.
//
