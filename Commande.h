#pragma once
#include "Client.h"
#include <vector>

class Commande {

    public:
    // declaration des constructors
        Commande();
        Commande(Client& client, bool livraison = false);

    // declaration des setters
    void setClient(Client& client);
    void setLivraison(bool livraison);

    // declaration des getters
        Client* getClient() const;
        std::vector<Product> getProduct() const;
        int getId() const;
        bool getLivraison() const;

    // methode pour surcharger l'opérateur
    friend std::ostream& operator<< (std::ostream& output, Commande& commande);
    private:
    // declaration des menbre prive
        Client* m_client;
        std::vector<Product> m_products;
        bool m_livraison;
        int m_id;
        int identifiant_auto_int();
};