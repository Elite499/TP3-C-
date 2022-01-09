#include "Commande.h"

// definition des constructors
    Commande::Commande(){
        m_id = identifiant_auto_int();
    }

    Commande::Commande(Client& client, bool livraison) : m_client(&client) , m_livraison(livraison){
        m_id = identifiant_auto_int();

        m_products.reserve( m_client->getPanier().size() );
        for(auto& i : m_client -> getPanier() ){
            m_products.push_back(i);
        }
  
    }


// definition des setters
    void Commande::setClient(Client& client){ m_client = &client;}
    
    void Commande::setLivraison(bool livraison){ m_livraison = livraison;}



// defenition des getteurs getters
    Client* Commande::getClient()const { return m_client;}
    std::vector<Product> Commande::getProduct() const {return m_products;}
    int Commande::getId() const { return m_id;}
    bool Commande::getLivraison() const { return m_livraison;}

//Surcharge d'opérateur
    std::ostream& operator<< (std::ostream& output, Commande& commande){
    std::string status ;
    commande.m_livraison ? status = "Livrée" : status = "Pas livrée" ;

    output<<"\nCommande n°" << commande.getId() <<"\t Statut: " << status ;
    // \t est utilisé pour mise en forme la listation (tabulation)
    output << "\n\t"<< "("<<commande.m_client->getId()<<")"<<commande.m_client ->getNom() 
            << "\t"<< commande.m_client->getPrenom()<<std::endl;

    for(auto& i : commande.m_products)
        output << "\t\t" << i << std::endl;
    
    output<<"\n";
    return output;
    }


int Commande::identifiant_auto_int(){
    static int index = 0;
    index++;
    return index ;
    }