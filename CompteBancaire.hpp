#ifndef COMPTEBANCAIRE_HPP
#define COMPTEBANCAIRE_HPP

#include <string>
#include <cstddef>

class CompteBancaire {
private:
    std::string numero;
    double solde;
    std::string* historique;
    std::size_t capacite;
    std::size_t nbOps;

    void agrandirHistorique();
    void ajouterOperation(const std::string& op);

public:
    CompteBancaire();
    CompteBancaire(const std::string& num, double s);

    // Constructeur de copie
    CompteBancaire(const CompteBancaire& other);

    // Constructeur de déplacement
    CompteBancaire(CompteBancaire&& other) noexcept;

    // Destructeur
    ~CompteBancaire();

    void deposer(double montant);
    void retirer(double montant);
    void afficher() const;
};

#endif
