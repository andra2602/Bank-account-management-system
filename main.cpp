#include <iostream>
#include <string>
#include <vector>

#include "./include/ContBancar.h"
#include "Tranzactie.h"
#include "Depunere.h"
#include "Exceptii.h"
#include "Retragere.h"
#include "Transfer.h"


void readAndDisplayObjects(int n,std::vector<ContBancar> &listaConturi) {
    std::string  name;
    std::cout << "\tIntroduceti numele: ";
    std::cin >> name;
    int i = 0;
    while(i<n) {
        std::string accountNum;
        std::string accountType;
        std::string password;
        bool validAccountNum = false;
        std::cout << "\tIntroduceti un numar de cont, acesta trebuie sa aiba 24 de caractere: ";
        std::cin >> accountNum;
        try{
            if (accountNum.length() == 24) {
                validAccountNum = true;
            }
            else{
                aruncaEroareCont();
            }
        }catch(const Exceptie &ex) {
            std::cout << "!!! Eroare la creare !!!" << std::endl;
            const auto *exCont = dynamic_cast<const EroareCont *>(&ex);
            if (exCont) {
                // Dacă dynamic_cast reușește, avem o instanță de EroareCont
                std::cout << "Detalii: " << exCont->what() << std::endl;
            } else {
                // Dacă dynamic_cast eșuează, ex nu este o instanță de EroareCont
                std::cout << "Eroare nu este de tipul EroareCont." << std::endl;
            }
        }
        if (validAccountNum) {
            std::cout << "\tIntroduceti tipul de cont pe care il doriti (personal sau economii): ";
            std::cin >> accountType;
            std::cout << "\tSuma initiala a contului: ";
            float balance;
            std::cin >> balance;
            std::cout << "\tIntroduceti parola: ";
            std::cin >> password;

            listaConturi.emplace_back(name,accountNum,balance,accountType,password);
            std::cout << "\tCont creat cu succes." << std::endl;
            i++;
        }
    }

    std::cout << "Conturi introduse:" << std::endl;
    std::vector<ContBancar>::size_type startIndex = std::max(static_cast<std::vector<ContBancar>::size_type>(0), listaConturi.size() - n);
    for (std::vector<ContBancar>::size_type index=startIndex; index < listaConturi.size(); index++) {
        std::cout << listaConturi[index] << std::endl;
    }
}
int main() {
    int optiune;
    ContBancar clientActual;
    ContBancar clientDestinatar;
    std::vector<ContBancar> listaConturi;
    listaConturi.emplace_back("Ionescu", "123456789123456789123456",600,"personal","Ionescu1234");
    listaConturi.emplace_back("Cirstea", "A2b9C4d7E1f8G3h6I5j2K9l4",5000,"personal","Cirstea1234");
    listaConturi.emplace_back("Popescu", "xqnwhG2Yq5zfg4JDPbGkG9VR",1000,"personal","Popescu1234");
    listaConturi.emplace_back("Dobrinoiu", "K6RAvQwfDsjUvNZASc88u3zF",10235,"economii","Dobrinoiu1234");
    listaConturi.emplace_back("Iordache", "7UmHecHqYkRuB48xeKvgg8qT",5,"personal","Iordache1234");
    listaConturi.emplace_back("Miinescu", "bVj7Ka4zh7d9GhdtgrfLhjh6",58,"personal","Miinescu1234");
    listaConturi.emplace_back("Paun", "HMFbQdhEQRNyfcRFaRsMUwVL",123,"personal","Paun1234");
    listaConturi.emplace_back("Calina", "Q6J8LSKjK3uUyBq8JxJegZL9",3,"personal","Calina1234");
    listaConturi.emplace_back("Bica", "668w2dSYdsfm45uFfdvZvueV",1200,"personal","Bica1234");
    listaConturi.emplace_back("Stefan", "rrmdrP7KrH67ZLLZPrxcdpqs",55000,"economii","Stefan1234");

    std::cout << "Meniu:" << std::endl;
    do {
        std::cout << "1. Creaza cont nou" << std::endl;
        std::cout << "2. Login" << std::endl;
        std::cout << "3. Iesire" << std::endl;
        std::cout << "Alege o optiune: " <<std::endl;
        std::cout << "Daca nu aveti deja cont,va rugam sa selectati 1!"<< std::endl;
        std::cout << "Altfel,apasati 2!"<<std::endl;
        std::cin >> optiune;
        switch (optiune) {
            case 1:
            {
                int n;
                std::cout<<"Cate conturi doriti sa va creati?"<<std::endl;
                std::cin>>n;
                if(n>0){
                    readAndDisplayObjects(n,listaConturi);
                }
                break;
            }
            case 2:
            {
                std::string numeUtilizator, parola, numarCont;
                std::vector<Tranzactie*> tranzactii;
                std::cout << "Introduceti numele de utilizator: ";
                std::cin >> numeUtilizator;
                std::cout << std:: endl;
                std::cout << "Introduceti numarul contului dumneavoastra: ";
                std::cin >> numarCont;
                std::cout << std:: endl;
                std::cout << "Introduceti parola: ";
                std::cin >> parola;
                try{
                    bool ok =false;
                    for (const auto & i : listaConturi) {
                        if (i.getTitularCont() == numeUtilizator && i.getparola() == parola && i.getnumarCont()== numarCont) {
                            clientActual = i;
                            std::cout << "Autentificare reusita. Bine ai venit, " << numeUtilizator << "!" << std::endl;
                            ok =true;
                            break;
                        }
                    }

                    if (ok == 0) {
                        aruncaEroareAutentificare("Autentificare esuata. Datele de conectare au fost introduse incorect.");
                    }
                }catch (const Exceptie &ex) {
                    if (const auto *autentificareEx = dynamic_cast<const EroareAutentificare *>(&ex)) {
                        std::cout << "Eroare la autentificare: " << autentificareEx->what() << std::endl;
                    } else {
                        // Tratează alte tipuri de excepții Eroare
                        std::cout << "Eroare generica: " << ex.what() << std::endl;
                    }
                    break;
                }

                int suboptiune;
                do {
                    std::cout << "\nMeniu cont curent:" << std::endl;
                    std::cout << "1. Vizualizeaza contul meu" << std::endl;
                    std::cout << "2. Realizeaza tranzactii" << std::endl;
                    std::cout << "3. Interogare sold" << std::endl;
                    std::cout << "4. Vizualizeaza ultimele tranzactii" << std::endl;
                    std::cout << "5. Delogare" << std::endl;
                    std::cout << "Alege o optiune: ";
                    std::cin >> suboptiune;

                    switch (suboptiune) {
                        case 1: {
                            std::cout << "Informatii despre cont-ul autentificat in acest moment:" << std::endl;
                            std::cout << clientActual;
                            break;
                        }
                        case 2: {
                            std::string op_tranz;
                            float suma;
                            std::cout << "Ce tip de tranzactie doriti sa realizati?" << std::endl;
                            std::cout << "Ca si optiuni de tranzactii aveti: depunere, retragere, transfer."
                                      << std::endl;
                            std::cin >> op_tranz;
                            std::cout << "Introduceti suma dorita: " << std::endl;
                            std::cin >> suma;
                            if (op_tranz != "depunere" && op_tranz != "retragere" && op_tranz != "transfer") {
                                std::cout
                                        << "Tipul de tranzactie selectat este necunoscut.\n Va rugam sa reluati procesul cu unul din tipurile de tranzactii specificat."
                                        << std::endl;
                                break;
                            } else {
                                Tranzactie *tranzactie = nullptr;
                                try {
                                    if (op_tranz == "depunere") {
                                        tranzactie = new Depunere(suma);
                                    } else if (op_tranz == "retragere") {
                                        tranzactie = new Retragere(suma);
                                    } else if (op_tranz == "transfer") {
                                        std::string numeClientDestinatar, numarContDestinatar;
                                        std::cout
                                                << "Introduceti numele titularului contului catre care vreti sa se execute transferul:"
                                                << std::endl;
                                        std::cin >> numeClientDestinatar;
                                        std::cout
                                                << "Introduceti numarul contului catre care vreti sa se execute transferul:"
                                                << std::endl;
                                        std::cin >> numarContDestinatar;

                                        // Caută contul destinatar în listaConturi
                                        ContBancar *destinatar = nullptr;
                                        for (auto &cont: listaConturi) {
                                            if (cont.getnumarCont() == numarContDestinatar &&
                                                cont.getTitularCont() == numeClientDestinatar) {
                                                destinatar = &cont;
                                                break;
                                            }
                                        }
                                        if (destinatar == nullptr) {
                                            std::cout
                                                    << "Contul destinatar nu a fost gasit. Transferul nu poate fi efectuat."
                                                    << std::endl;
                                            break;
                                        }
                                        // Dacă contul destinatar a fost găsit, efectuează transferul
                                        tranzactie = new Transfer(suma, destinatar);
                                    }
                                    if(tranzactie != nullptr)
                                    {
                                        tranzactie->procesTranzactie(clientActual);
                                        tranzactii.push_back(tranzactie);
                                    }
                                } catch (const Exceptie &ex) {
                                    // Aici prindem excepția folosind tipul de bază (upcast)
                                    std::cout << "!!! Eroare la efectuarea tranzactiei !!!"<<std::endl;
                                    const auto *exTranz = dynamic_cast<const ExceptieTranz *>(&ex);
                                    if(exTranz){
                                        std::cout<<"Motiv: "<<exTranz->what()<<std::endl;
                                    }
                                    else{
                                        std::cout << "Eroarea nu este de tipul ExceptieTranz." << std::endl;
                                    }
                                    /*std::cout << "Tranzactia nu poate fi efectuata!" << std::endl << "Motiv: "
                                              << ex.what() << std::endl;*/
                                }

                            }
                            break;
                        }
                        case 3:
                            std::cout << "Soldul contului dumneavoastra este: " << clientActual.getsold_cont()
                                      << std::endl;
                            break;
                        case 4: {
                            if (tranzactii.empty())
                                std::cout << "Inca nu ati efectuat tranzactii." << std::endl;
                            else {
                                std::cout << "Ultimele tranzactii:" << std::endl;
                                for (auto &tranzactie: tranzactii) {
                                    if (auto *depunere = dynamic_cast<Depunere *>(tranzactie)) {
                                        std::cout << "Tranzactie de " << depunere->obtineTipTranzactie()
                                                  << " efectuata." << std::endl;
                                        depunere->afisareDetalii();
                                    } else if (auto *retragere = dynamic_cast<Retragere *>(tranzactie)) {
                                        std::cout << "Tranzactie de " << retragere->obtineTipTranzactie()
                                                  << " efectuata." << std::endl;
                                        retragere->afisareDetalii();
                                    } else if (auto *transfer = dynamic_cast<Transfer *>(tranzactie)) {
                                        std::cout << "Tranzactie de " << transfer->obtineTipTranzactie()
                                                  << " efectuata." << std::endl;
                                        transfer->afisareDetalii();
                                    }
                                }
                            }
                            break;
                        }
                        case 5: {
                            std::cout << "Delogare realizata cu succes!" << std::endl;
                            std::cout << "O zi frumoasa!" << std::endl;
                            for (auto *tranzactie: tranzactii) {
                                delete tranzactie;
                            }
                            std::cout << std::endl;
                            std::cout << std::endl;
                            break;
                        }

                        default:
                            std::cout << "Optiune invalida. Te rog sa alegi o optiune valida." << std::endl;
                    }
                } while (suboptiune != 5);
                break;
            }
            case 3:
            {std::cout<<"Iesire din aplicatie!"<<std::endl;
                break;}
            default:
                std::cout << "Optiune invalida. Te rog sa alegi o optiune valida." << std::endl;
        }
    } while (optiune != 3);
    return 0;
}