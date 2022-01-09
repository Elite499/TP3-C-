#include "Client.h"

    Client::Client(){
        m_id = identifiant_auto_int();
    }

    Client::Client(std::string prenom, std::string nom, std::vector<Product> panier): m_prenom(prenom),
        m_nom(nom), m_panier(panier){
        m_id = identifiant_auto_int();
    }
    // declaration des getters
    std::string Client::getNom() const{ return m_nom;}
    std::string Client::getPrenom() const{ return m_prenom;}
    int Client::getId() const { return m_id;}
    std::vector<Product> Client::getPanier() const{return m_panier;}
   
   //  methode pour ajouter un produit
   void Client::newProduct(Product produit , int quantite )
   {
        produit.setQuantite(quantite);
        m_panier.push_back(produit);
    }
     // methode pour Vider le panier
        void Client::viderPanier(){
        m_panier.erase(m_panier.begin(), m_panier.end());
    }
   // modification de la quantité d'un produit ajoute
       
   void Client::newQuantity(Product produit,int quantite){
       
        for(int i =0 ; i< (int)m_panier.size() ; i++)
            if( m_panier.at(i).getTitre() == produit.getTitre()){
                m_panier.at(i).setQuantite(quantite);
                break;
            }
    }

    void Client::newQuantity(std::string titre, int quantite){
        for(auto& i : m_panier)
            if( i.getTitre() == titre){
                i.setQuantite(quantite);
                break;
            }
    }

     // methode pour Supprimer un produit du panier
        void Client::delProduct(Product product){
        for(int i=0; i< (int)m_panier.size(); i++)
            if( (m_panier.at(i)).getTitre() == product.getTitre()){
                m_panier.erase(m_panier.begin()+i);
                break;
            }
    }
       
        void Client::delProduct(std::string titre){
        for(int i=0; i< (int)m_panier.size(); i++)
            if( (m_panier.at(i)).getTitre() == titre){
                m_panier.erase(m_panier.begin()+i);
                break;
            }
           
    }
   
    //  methode pour surcharge des operateur
    std::ostream& operator<< (std::ostream& output, Client& client)
    {
    output << "ID(" << client.getId() << ") "<< client.getPrenom() << "\t" << client.getNom();
    // \t est utilisé pour mise en forme la listation (tabulation)
    output << "\n \tPanier:" ;
    for(int i=0 ; i< (int)client.m_panier.size();i++)
        output << "\n \t\t" << client.m_panier.at(i) ;
    output << "\n";

    return output;
    }

    int Client::identifiant_auto_int(){
        static int index=0;
	    index++ ;
	    return index;
    }