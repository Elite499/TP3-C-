#pragma once
#include <string>
#include <vector>
#include "Produit.h"

class Client{
    public:
    //  declaration de constructeur
        Client();
        Client(std::string prenom, std::string nom, std::vector<Product> panier);

        // declaration getters
        std::string getNom() const;
        std::string getPrenom() const;
        int getId() const;
        std::vector<Product> getPanier() const;

        // methode pour ajouter un produit au panier
        void newProduct(Product produit , int quantite = 1);

         // methode pour  Vider le panier
        void viderPanier();

        //  methode pour modifier la quantité d'un produit ajouté au panier
        void newQuantity(Product produit,int quantite);
        void newQuantity(std::string titre, int quantite);
        //Supprimer un produit du panier
        void delProduct(Product product);
        void delProduct(std::string titre);

         // methode de Surcharger l'opérateur
        friend std::ostream& operator<< (std::ostream& output, Client& client);

    private:
    // declaration des attribues
        std::string m_prenom;
        std::string m_nom;
        int m_id;
        std::vector<Product> m_panier;

        //méthode pour fournir un  seul identifiant
        int identifiant_auto_int();
};

