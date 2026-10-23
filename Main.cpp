#include <iostream>
#include <utility>
#include "CompteBancaire.hpp"

int main() {
    // Creation du compte
    CompteBancaire c1("FR123456", 500.0);

    c1.deposer(200);
    c1.retirer(150);

    std::cout << " Compte c1 " << std::endl;
    c1.afficher();

    // Constructeur de copie
    CompteBancaire c2 = c1;

    std::cout << "\n Compte c2 (copie) " << std::endl;
    c2.afficher();

    // Constructeur de deplacement
    CompteBancaire c3 = std::move(c1);

    std::cout << "\n Compte c3 (deplacement) " << std::endl;
    c3.afficher();

    return 0;
}




