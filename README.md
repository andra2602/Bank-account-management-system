# **Banking Management System**  

## **Description**  
This project implements an **interactive console-based system** for managing **bank accounts**, allowing users to perform various financial operations. The system supports multiple types of accounts and transactions and is built using **advanced object-oriented programming (OOP) concepts**, **design patterns** such as **Singleton** and **Builder**, and a modular structure.

The project adheres to mandatory requirements and leverages **inheritance, exceptions, abstract classes, operator overloading, and virtual functions**, providing a **complete and modular implementation**.  
Key components include:
- **Bank Account class**: Manages personal and savings accounts.
- **Transaction class**: Handles deposits, withdrawals, and transfers.
- **Invoice class**: Manages utility bills through the `InvoiceUtilities` subclass.

### **Implemented Design Patterns**  
- ✅ **Singleton** – Ensures a single instance for managing bank accounts.  
- ✅ **Builder** – Constructs complex objects (e.g., bank accounts) in a **modular and clear** manner.  

---

## **Technologies Used**  
- **Programming Language**: C++  
- **Paradigm**: Object-Oriented Programming (OOP)  
- **Testing**: Unit tests to validate implemented functionalities  

---

## **Main Features**  
✔ **Bank Account Management** – Supports different account types (personal, savings).  
✔ **Financial Transactions** – Deposits, withdrawals, and transfers between accounts.  
✔ **Comprehensive Financial Operations** – Various banking operations.  
✔ **Authentication & Security System** – Verifies user identity.  
✔ **Monitoring & Auditing** – Logs all user actions.  
✔ **Custom Exceptions** – Robust error handling.  
✔ **Interactive Menu** – Easy console-based interaction.  

---

## **Project Objectives**  
✔️ Develop a **robust system** for managing bank accounts and transactions.  

✔️ Strengthen **OOP knowledge** gained during the course.  

✔️ Implement **advanced features** using complex **OOP concepts**.  

✔️ Ensure modularity and extensibility through **structured testing and validation**.  

---

## **Project Structure**  
📂 **include/** – Header files (`.h`)  

📂 **src/** – Class implementations (`.cpp`)  

📂 **tests/** – Unit test files  

📂 **data/** – Input/output files for testing  

---

## **Key Classes**  

### **1. Bank Account Class**  
**Attributes**:  
- Account number  
- Balance  
- Account holder  
- Account type  
- Password  

**Overloaded Operators**:  
✅ `<<`, `>>`, `=`  

---

### **2. Transaction Class** (Base Class)  
- **Derived Classes**: `Deposit`, `Withdrawal`, `Transfer`  
- Manages deposit and withdrawal amounts, **fund verification**, and **account transfers**  

---

### **3. Invoice Class** (Base Class)  
- `InvoiceUtilities` extends `Invoice` to manage **utility bills**  

---

## **Design Patterns**  
- **Singleton** – Ensures a **single instance** for managing **bank accounts**, preventing multiple instances of the same class.  
- **Builder** – Constructs **complex objects**, such as bank accounts and transactions, in a **flexible and modular** way.  

---

## **How to Run the Project**  

### **1️⃣ Clone the repository**  
```bash
git clone https://github.com/username/banking-management.git  
cd banking-management
```

### **2️⃣ Compile the project using g++**  
```bash
g++ -Wall -o banking src/*.cpp
```

### **3️⃣ Run the program**  
```bash
./banking
```

### **4️⃣ Run unit tests**  
```bash
./tests/test_banking
```

---

## **Advanced Features**  
🔹 **Inheritance & Polymorphism** – Upcasting & Downcasting  

🔹 **Abstract Classes** – Defining a clear hierarchy  

🔹 **Custom Exceptions** – Handling invalid transactions  

🔹 **Design Patterns** – Singleton & Builder for a **robust and extensible system** 

🔹 **Overloaded Operators** – `<<`, `>>`, `=` for efficient object handling  

---

## **Final Thoughts**  
This project provides **a complete banking management system**, leveraging **OOP principles, robust design patterns, and a structured approach to security and transaction management**. The implementation follows **best practices**, ensuring **modularity, maintainability, and performance optimization**.  

___



# Banking Management System 
## Descriere
Acest proiect implementează o consolă interactivă pentru gestionarea conturilor bancare, permițând utilizatorilor să efectueze diverse operațiuni financiare. Sistemul suportă mai multe tipuri de conturi și tranzacții și este construit utilizând concepte avansate de programare orientată pe obiecte (OOP), design patterns precum Singleton și Builder, și un sistem modular.

Proiectul respectă cerințele obligatorii și utilizează moștenirea, excepțiile, clase abstracte, suprascrierea operatorilor și funcții virtuale, oferind o implementare completă și modulară. În cadrul proiectului, există clase specifice care gestionează conturile bancare și tranzacțiile financiare. Printre acestea se numără clasa de bază Cont Bancar și clasa de Tranzacție. Clasa Cont Bancar permite gestionarea conturilor bancare (conturi personale, conturi de economii), iar clasa Tranzactie și clasele derivate de aceasta (Depunere, Retragere, Transfer) permit efectuarea tranzacțiilor.

De asemenea, este utilizată clasa Factura, moștenită de FacturaUtilitati, care permite gestionarea facturilor pentru utilități. 

Proiectul integrează design patterns, cum ar fi :
- [x] **Singleton** -> pentru a asigura crearea unei singure instanțe de gestionare a conturilor bancare
- [x] **Builder** -> pentru a construi obiecte complexe, cum ar fi conturile bancare, într-un mod modular și clar.

## Tehnologii utilizate
Limbaj de programare: C++
Paradigmă: Programare orientată pe obiecte (OOP)
Testare: Teste unitare pentru validarea funcționalităților implementate


##  Funcționalități principale
- [x]  Gestionarea conturilor bancare – diferite tipuri de conturi (ex: cont personal, cont de economii)
- [x]  Tranzacții financiare – depozite, retrageri, transferuri între conturi
- [x]  O multitudine de operatii tipice 
- [x]  Sistem de autentificare și securitate – verificarea identității utilizatorilor
- [x]  Monitorizare și audit – jurnalizarea acțiunilor efectuate
- [x]  Excepții personalizate – tratarea erorilor într-un mod robust
- [x]  Meniu interactiv – interacțiune facilă prin consolă

## Scopul proiectului
✔️ Dezvoltarea unui sistem robust pentru gestionarea conturilor bancare și a tranzacțiilor

✔️ Fixarea și aprofundarea cunoștințelor dobândite în cadrul cursului

✔️ Integrarea unor funcționalități avansate prin utilizarea unor concepte complexe OOP

✔️ Testarea și validarea funcționalităților printr-un sistem modular și extensibil

## Structura proiectului
📂 include/ – fișiere header (.h)

📂 src/ – implementările claselor (.cpp)

📂 tests/ – fișiere pentru testele unitare

📂 data/ – fișiere de intrare/ieșire pentru testare

## Clasele principale

- Clasa de bază Cont Bancar
  
Atribute: număr cont, sold, titular, tip cont, parola

Operatori suprascrisi: <<, >>, =

- Clasa Tranzactie – clasa de bază pentru tranzacții

Clase derivate: Depunere, Retragere, Transfer care implementează tranzacții specifice

Gestionarea sumelor de depus sau retras, verificarea fondurilor, și transferuri între conturi

- Clasa Factura – clasa de bază pentru facturi
  
FacturaUtilitati moștenește Factura și permite gestionarea facturilor pentru utilități

## Design Patterns
- Singleton – asigură că există o singură instanță pentru gestionarea conturilor bancare, prevenind instanțierea multiplelor obiecte ale aceleași clase.
- Builder – este utilizat pentru construirea obiectelor complexe, cum ar fi conturile bancare și tranzacțiile, într-un mod flexibil și modular.
  

## Cum rulezi proiectul?
1️⃣ Clonează repository-ul
``` bash
git clone https://github.com/username/banking-management.git  
cd banking-management
```
2️⃣ Compilează proiectul cu g++
```bash
g++ -Wall -o banking src/*.cpp
```
3️⃣ Rulează programul

```bash
./banking
```
4️⃣ Rulează testele unitare

```bash
./tests/test_banking
```
🔄 Meniu interactiv

## Caracteristici avansate
🔹 Moștenire și polimorfism – Upcasting și Downcasting 

🔹 Clase abstracte 

🔹 Excepții personalizate – Tratarea erorilor pentru tranzacții invalide

🔹 Design Patterns – Singleton și Builder pentru implementarea unui sistem robust și extensibil

🔹 Operatori suprascrisi – <<, >>, = pentru gestionarea obiectelor
