#include <iostream>
#include <string>
#include <utility>
#include <vector>

class ContBancar {
private:
    std:: string TitularCont;
    std:: string numarCont;
    float sold_cont;
    std:: string tipCont;
    std:: string parola;

public:

    /// Constructor implicit cu valori implicite

    explicit ContBancar(std::string titular = "-",std::string numar="000000000000000000000000", float sold=0.0,std::string tip="personal", std::string pass="0000"):TitularCont(std::move(titular)), numarCont(std::move(numar)), sold_cont(sold),tipCont(std::move(tip)),parola(std::move(pass)){
    }

    ContBancar(std::string titular,std::string numar, float sold):TitularCont(std::move(titular)), numarCont(std::move(numar)), sold_cont(sold){
    }

    /// constructor de copiere
    ContBancar(const ContBancar &auxiliar){
        this->numarCont = auxiliar.numarCont;
        this->sold_cont = auxiliar.sold_cont;
        this->TitularCont = auxiliar.TitularCont;
        this->tipCont = auxiliar.tipCont;
        this->parola = auxiliar.parola;
    }

    /// operator= de copiere
    ContBancar &operator=(const ContBancar &cb) {
        this->numarCont = cb.numarCont;
        this->sold_cont = cb.sold_cont;
        this->TitularCont = cb.TitularCont;
        this->tipCont = cb.tipCont;
        this->parola = cb.parola;
        return *this;
    }

    ///supraincarcare operator == de egalitate ca functie membra
    bool operator==(const ContBancar& cb) const {
        return (TitularCont == cb.TitularCont && numarCont == cb.numarCont && sold_cont == cb.sold_cont && tipCont == cb.tipCont && parola == cb.parola);
    }


    /// Operator>> pentru citire (std::istream)
    friend std::istream &operator>>(std::istream &in, ContBancar &cb) {
        std::cout << "Introduceti numele clientului: ";
        in >> cb.TitularCont;
        std::cout << "Introduceti parola: ";
        in >> cb.parola;
        in >> cb.numarCont;
        in >> cb.sold_cont;
        in >> cb.tipCont;
        return in;
    }
    /// Operator<< pentru afișare (std::ostream)
    friend std::ostream &operator<<(std::ostream &out, const ContBancar &cb) {
        out << "Titular cont: " << cb.getTitularCont() << std::endl;
        out << "Număr cont: " << cb.getnumarCont() << std::endl;
        out << "Sold cont: " << cb.getsold_cont() << std::endl;
        out << "Tip cont: " << cb.gettipCont() << std::endl;
        out << "----------------------------------" << std::endl;

        return out;
    }

    [[nodiscard]] std::string getTitularCont()const {return TitularCont;}
    [[nodiscard]] std::string getnumarCont()const {return numarCont;}
    [[nodiscard]] float getsold_cont()const {return sold_cont;}
    [[nodiscard]] std::string gettipCont()const {return tipCont;}
    [[nodiscard]] std::string getparola()const {return parola;}

    void setSold(float suma) {
        sold_cont = suma;
    }
    void setNumeClient(const std::string& nume) {
        TitularCont = nume;
    }
    void setNumarClient(const std::string& numar) {
        numarCont = numar;
    }

//    [[maybe_unused]] void setTipCont(const std::string& tip) {
//        tipCont = tip;
//    }

//    [[maybe_unused]] void setParola(const std::string& pass) {
//        parola= pass;
//    }

    friend ContBancar operator+(const ContBancar& cb,float suma);

    /// Funcție pentru depunere în cont
    void depune_suma(float suma) {
        sold_cont += suma;
    }
    friend ContBancar operator-(const ContBancar& cb,float suma);

    /// Funcție pentru retragere din cont
    void retrage_suma(float suma) {
        if (suma <= sold_cont && (sold_cont - suma) >= 5000) {
            sold_cont -= suma;
        } else {
            std::cout << "Retragerea depaseste limita minima de 5000. Procesul nu poate fi realizat." << std::endl;
        }
    }


    /// Funcție pentru verificarea lungimii numărului contului
    bool esteValid() {
        return numarCont.length() == 24;
    }

    /// Funcție pentru afișarea informațiilor despre cont
//    [[maybe_unused]] void vizualizeazaInformatii() {
//        std::cout << "Titular cont: " << TitularCont <<", Numar cont: " << numarCont << ", Sold: " << sold_cont << std::endl;
//    }
    ///destructor
    ~ContBancar()=default;
};

/// operator ca functie non-membra
ContBancar operator+(const ContBancar& cb, float suma) {
    ContBancar temp(cb);
    temp.depune_suma(suma);
    return temp;
}
ContBancar operator-(const ContBancar& cb, float suma) {
    ContBancar temp(cb);
    if (suma < temp.getsold_cont()) {
        temp.retrage_suma(suma);
    }
    return temp;
}

class Tranzactie {
private:
    ContBancar ContBancar_1;
    ContBancar ContBancar_2;
    std::string tipTranzactie;
    float suma{};

public:
    Tranzactie() : tipTranzactie(""), suma(0.0) {
        /// Constructor de inițializare fără parametri
    }

    [[maybe_unused]] Tranzactie(std::string tip, float s) : tipTranzactie(std::move(tip)), suma(s) {}

    [[maybe_unused]] Tranzactie(ContBancar& cont_crt, ContBancar& cont2): ContBancar_1(cont_crt),ContBancar_2(cont2){}


    /// Constructor de copiere
    Tranzactie(const Tranzactie &t){
        this->tipTranzactie = t.tipTranzactie;
        this->suma = t.suma;
    }

    // Operator= de copiere
    Tranzactie& operator=(const Tranzactie &t) {
        if (this != &t) {
            tipTranzactie = t.tipTranzactie;
            suma = t.suma;
        }
        return *this;
    }


    /// Operator<< pentru afișare (std::ostream)
    friend std::ostream& operator<<(std::ostream &out, const Tranzactie &t) {
        out << "Tip tranzactie: " << t.tipTranzactie;
        out << "Suma: " << t.suma;
        return out;
    }

    /// Operator>> pentru citire (std::istream)
    friend std::istream& operator>>(std::istream &in, Tranzactie &t) {
        in >> t.tipTranzactie;
        in >> t.suma;
        return in;
    }


    void procesTranzactie(ContBancar &ContBancar_crt) {
        std::cout << "Ce tip de tranzactie doriti sa faceti?" << std::endl;
        std::cout << "Optiuni tranzactii: depunere, retragere, transfer." << std::endl;
        std::cin >> tipTranzactie;
        std::cout << "Introduceti suma dorita: " << std::endl;
        std::cin >> suma;
        if (tipTranzactie == "depunere") {
            ContBancar_crt.setSold(ContBancar_crt.getsold_cont() + suma);
            std::cout << "Depunere de " << suma << " procesată." << std::endl;
            std::cout << "Soldul curent al contului: " << ContBancar_crt.getsold_cont() << std::endl;
        } else if (tipTranzactie == "retragere") {
            ContBancar_crt.setSold(ContBancar_crt.getsold_cont() - suma);
            std::cout << "Retragere de " << suma << " procesată." << std::endl;
            std::cout << "Soldul contului: " << ContBancar_crt.getsold_cont() << std::endl;
        } else if (tipTranzactie == "transfer") {
            std::string nume2;
            std::string numar2;
            std::cout << "In ce cont doriti sa efectuati transferul?Introduceti numele si numarul contului respectiv." <<std::endl;
            std::cout << "Nume:";
            std::cin >> nume2;
            std::cout <<std::endl;
            std::cout << "Numar:";
            std::cin >> numar2;
            std::cout <<std::endl;
            ContBancar_2.setNumeClient(nume2);
            ContBancar_2.setNumarClient(numar2);
            if (suma <= ContBancar_crt.getsold_cont() && ContBancar_crt.esteValid() && ContBancar_2.esteValid()) {
                ContBancar_crt.setSold(ContBancar_crt.getsold_cont() - suma);
                ContBancar_2.setSold(ContBancar_2.getsold_cont() + suma);
                std::cout << "Suma " << suma << " a fost transferata catre " << ContBancar_2.getTitularCont() << ", cu contul " << ContBancar_2.getnumarCont() << std::endl;
                std::cout << "Transferul a fost realizat cu succes." << std::endl;
                std::cout << "Soldul dumneavoastra curent este: " << ContBancar_crt.getsold_cont() << std::endl;
            } else {
                std::cout << "Fonduri insuficiente pentru transfer." << std::endl;
            }
        } else {
            std::cout << "Tip de tranzacție necunoscut." << std::endl;
        }

    }
    /// Destructor
    ~Tranzactie()=default;
};

int main() {
    int optiune;
    ContBancar clientActual;
    ContBancar newClient;
    std::vector<ContBancar> listaConturi;
    listaConturi.emplace_back("Ionescu", "123456789123456789123456",600,"personal","Ionescu1234");
    listaConturi.emplace_back("Cirstea", "A2b9C4d7E1f8G3h6I5j2K9l4M7n1O8p3",5000,"personal","Cirstea1234");
    listaConturi.emplace_back("Popescu", "xqnwhG2Yq5zfg4JDPbGkG9VR",1000,"personal","Popescu1234");
    listaConturi.emplace_back("Dobrinoiu", "K6RAvQwfDsjUvNZASc88u3zF",10235,"economii","Dobrinoiu1234");
    listaConturi.emplace_back("Iordache", "7UmHecHqYkRuB48xeKvgg8qT",5,"personal","Iordache1234");
    listaConturi.emplace_back("Miinescu", "bVj7Ka4zh7d9GhdtgrfLhjh6",58,"personal","Miinescu1234");
    listaConturi.emplace_back("Paun", "HMFbQdhEQRNyfcRFaRsMUwVL",123,"personal","Paun1234");
    listaConturi.emplace_back("Calina", "Q6J8LSKjK3uUyBq8JxJegZL9",3,"personal","Calina1234");
    listaConturi.emplace_back("Bica", "668w2dSYdsfm45uFfdvZvueV",1200,"personal","Bica1234");
    listaConturi.emplace_back("Stefan", "rrmdrP7KrH67ZLLZPrxcdpqs",55000,"economii","Stefan1234");

    std::cout << "Meniu:" << std::endl;
    float balance;
    do {
        std::cout << "1. Creaza cont nou" << std::endl;
        std::cout << "2. Login" << std::endl;
        std::cout << "3. Vizualizeaza contul meu" << std::endl;
        std::cout << "4. Realizeaza tranzactii" << std::endl;
        std::cout << "5. Interogare sold" << std::endl;
        std::cout << "6. Iesire" << std::endl;
        std::cout << "Alege o optiune: ";
        std::cin >> optiune;

        switch (optiune) {
            case 1:
            {
                std::string name;
                std::string accountNum;
                std::string accountType;
                std::string password;
                bool validAccountNum = false;

                std::cout << "\tIntroduceti numele: ";
                std::cin >> name;
                std::cout << "\tIntroduceti un numar de cont, acesta trebuie sa aiba 24 de caractere: ";
                std::cin >> accountNum;
                std::cout << "\tIntroduceti tipul de cont pe care il doriti (personal sau economii): ";
                std::cin >> accountType;

                if (accountNum.length() == 24) {
                    validAccountNum = true;
                }

                if (validAccountNum) {
                    std::cout << "\tSuma initiala a contului: ";
                    std::cin >> balance;
                    std::cout << "\tIntroduceti parola: ";
                    std::cin >> password;

                    listaConturi.emplace_back(name,accountNum,balance,accountType,password);
                    std::cout << "\tCont creat cu succes." << std::endl;
                } else {
                    std::cout << "\tNumarul de cont nu este valid. Va rugam sa reincercati." << std::endl;
                }
                break;
            }
            case 2:
            {
                std::string numeUtilizator, parola, numarCont;

                std::cout << "Introduceti numele de utilizator: ";
                std::cin >> numeUtilizator;
                std::cout << std:: endl;
                std::cout << "Introduceti numarul contului dumneavoastra: ";
                std::cin >> numarCont;
                std::cout << std:: endl;
                std::cout << "Introduceti parola: ";
                std::cin >> parola;

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
                    std::cout << "Autentificare esuata. Nume de utilizator sau parola incorecte." << std::endl;
                }
                break;
            }
            case 3:
            {std::cout << "Informatii despre cont-ul autentificat in acest moment:" << std::endl;
                std::cout << clientActual;
                break;}
            case 4:
            {   Tranzactie tranzactie;
                tranzactie.procesTranzactie(clientActual);
                break;
            }
            case 5:
                std::cout << "Soldul contului dumneavoastra este: " << clientActual.getsold_cont() << std::endl;
                break;
            case 6:
                std::cout << "Iesire din aplicatie." << std::endl;
                break;
            default:
                std::cout << "Optiune invalida. Te rog sa alegi o optiune valida." << std::endl;
        }
    } while (optiune != 6);
    return 0;
}