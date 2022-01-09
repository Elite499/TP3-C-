#pragma once

#include <string>
#include <iostream>

class Product{

    public:
    // declaration des constructeur
        Product();
        Product(std::string titre, std::string description, int quantite,double prix);

        //declaration des getters
        std::string getTitre() const;
        std::string getDescription()const ;
        int getQuantite() const ;
        void gestionUtilisateurs();

        double getPrix() const ;

        //declaration des setters
        void setTitre(std::string& titre);
        void setDescription(std::string&description);
        void setQuantite(int quantite);
        void setPrix(double prix);

        // methode pour surcharger  l'operateur
        friend std::ostream& operator<< (std::ostream &output, Product& product);

    private:
    // declaration des attribues
        std::string m_titre;
        std::string m_description;
        int m_quantite;
        double m_prix;
};