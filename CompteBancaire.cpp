#include <iostream>
#include <algorithm>
#include <utility>
#include "CompteBancaire.hpp"

CompteBancaire::CompteBancaire()
    : numero("NON_DEFINI"),
      solde(0.0),
      historique(new std::string[10]),
      capacite(10),
      nbOps(0) {
}

CompteBancaire::CompteBancaire(const std::string& num, double s)
    : numero(num),
      solde(s),
      historique(new std::string[10]),
      capacite(10),
      nbOps(0) {

    ajouterOperation(
        "Creation du compte avec solde " + std::to_string(s)
    );
}

void CompteBancaire::agrandirHistorique() {
    std::size_t nouvelleCap = (capacite == 0) ? 10 : capacite * 2;

    std::string* nouveau = new std::string[nouvelleCap];

    for (std::size_t i = 0; i < nbOps; i++) {
        nouveau[i] = historique[i];
    }

    delete[] historique;

    historique = nouveau;
    capacite = nouvelleCap;
}

void CompteBancaire::ajouterOperation(const std::string& op) {
    if (nbOps == capacite) {
        agrandirHistorique();
    }

    historique[nbOps] = op;
    nbOps++;
}

CompteBancaire::CompteBancaire(const CompteBancaire& other)
    : numero(other.numero),
      solde(other.solde),
      historique(new std::string[other.capacite]),
      capacite(other.capacite),
      nbOps(other.nbOps) {

    for (std::size_t i = 0; i < nbOps; i++) {
        historique[i] = other.historique[i];
    }
}

CompteBancaire::CompteBancaire(CompteBancaire&& other) noexcept
    : numero(std::move(other.numero)),
      solde(other.solde),
      historique(other.historique),
      capacite(other.capacite),
      nbOps(other.nbOps) {

    other.historique = nullptr;
    other.capacite = 0;
    other.nbOps = 0;
    other.solde = 0.0;
}

CompteBancaire::~CompteBancaire() {
    delete[] historique;
}

void CompteBancaire::deposer(double montant) {
    if (montant <= 0) {
        std::cerr << "Montant de depot invalide" << std::endl;
        return;
    }

    solde += montant;

    ajouterOperation(
        "Depot de " + std::to_string(montant)
    );
}

void CompteBancaire::retirer(double montant) {
    if (montant <= 0 || montant > solde) {
        std::cerr << "Retrait impossible" << std::endl;
        return;
    }

    solde -= montant;

    ajouterOperation(
        "Retrait de " + std::to_string(montant)
    );
}

void CompteBancaire::afficher() const {
    std::cout << "Compte " << numero
              << " - Solde : " << solde << std::endl;

    std::cout << "Historique des operations :" << std::endl;

    for (std::size_t i = 0; i < nbOps; i++) {
        std::cout << "  " << historique[i] << std::endl;
    }
}

