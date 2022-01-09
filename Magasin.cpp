#include "Magasin.h"

//  defenition des constructeurs
Magasin::Magasin(){

}

Magasin::Magasin(std::vector <Product>& products, std::vector <Client>& clients, std::vector <Commande>& orders){
   
}
// defenition des getters
std::vector <Product > Magasin::getProducts() const { return m_products ;}
std::vector <Client > Magasin::getClients() const { return m_clients ;}
std::vector <Commande > Magasin::getOrders() const { return m_orders ;}
//  definition de la methodes qui permet d'ajouter un nouveau produit
void Magasin::newProduct(Product produit){
    m_products.push_back(produit);
}
// definition de la methodes qui permet d'afficher touts les produits
void Magasin::showProducts(){
    for (int i =0 ; i< m_products.size(); i++)
    {
        std::cout<< m_products[i]<<std::endl;
    }
}
// definition de la methodes qui permet d'afficher un produit avec son nom
void Magasin::showProduct(std::string nom_produit){
    for(auto& i : m_products)
        if( i.getTitre() == nom_produit){
            std::cout << "\n donner des details sur le  produit\n" ;
            std::cout << i << "\n";
            break;
        }
   
}
// definition de la methodes qui permet de mettre  a jour la quantite de produit
void Magasin::newQuantite(std::string nom_produit,int quantite){
   
    if(quantite >= 0){
        for(auto& i : m_products){
       
             if( i.getTitre() == nom_produit){
            i.setQuantite(quantite);
            break;
             }
        }
    }
    else
        std::cout << " il n'y a pas un produits a se nom  .\n";
}

void Magasin::newClient(Client& client){
    m_clients.push_back(client) ;
}

void Magasin::newClient(std::string prenom, std::string nom) {
    std::vector<Product> panier;
    Client client = Client(prenom, nom, panier);
    m_clients.push_back(client) ;

}

void Magasin::newOrder(Commande& order){
    m_orders.push_back(order) ;

}


void Magasin::showClients(){

    std::cout << "\nClients\n";
    std::cout << "Uid" ;

    for(int i = 0 ; i < 9 ; i++) {
        std::cout << " ";
    }
    std::cout << "Identifiant \n";

    for(auto& i:m_clients){
        std::cout << i.getId() ;
        for(int j = 0 ; j < 12 - (int)std::to_string(i.getId()).length() ; j++)
            {std::cout << " ";}
        std::cout << i.getPrenom() << " " << i.getNom() << std::endl ;
    }
    std::cout << std::endl;
    
}

void Magasin::showClient(std::string prenom, std::string nom){
    for(auto& i : m_clients){
        if( i.getPrenom() == prenom &&  i.getNom() == nom){
            std::cout << "\t Affichage du client\n";
            std::cout << "Uid" ;
            for(int i = 0 ; i < 9 ; i++)
                std::cout << " ";
            std::cout << "Identifiant\n";
            std::cout << i.getId() << std::endl;

            for(int j = 0 ; j < (int)std::to_string(i.getId()).length() - 3; j++)
                std::cout << " ";
             std::cout << i.getPrenom() << " " << i.getNom() << std::endl ;

            break;
        }
    }
}

void Magasin::showClient(int id){
    for(auto& i : m_clients){
        if ( i.getId() == id){
            std::cout << "\tAffichage du client\n";
            std::cout << "Uid" ;
            for(int j = 0 ; j < 7 ; j++)
                std::cout << " ";
            std::cout << "Identifiant\n";
            std::cout << i.getId() << std::endl;

            for(int j = 0 ; j < (int)std::to_string(i.getId()).length() - 3; j++)
                std::cout << " ";
             std::cout << i.getPrenom() << " " << i.getNom() << std::endl ;
            break;
        }
    }
}

void Magasin::addProductToShoppingCart(std::string titre, std::string prenom, std::string nom){
    for(auto& i : m_products)
        if( i.getTitre() == titre){
            for(auto& j : m_clients)
                if( j.getPrenom() == prenom || j.getNom() == nom ){
                    j.newProduct(i);
                    break;
                }
            break;
        }
}

void Magasin::addProductToShoppingCart(std::string titre, int id ){

    for(auto& i : m_products)
        if( i.getTitre() == titre){
            for(auto& j : m_clients)
                if( j.getId() == id){
                    j.newProduct(i);
                    break;
                }  
             break;
        }
}

void Magasin::addProductToStore(std::string nom, std::string description, float prix, int quantite){
    Product product = Product(nom, description, quantite, prix);
    m_products.push_back(product);
}


void Magasin::delProductClient(std::string titre, std::string prenom, std::string nom){
    for(auto& i : m_products)
        if( i.getTitre() == titre){
            for(auto& j : m_clients)
                if( j.getPrenom() == prenom || j.getNom() == nom){
                    j.delProduct(titre);
                    break;               
                }
            break;}
}

void Magasin::delProductClient(std::string titre, int id){
    for(auto& i : m_products)
        if( i.getTitre() == titre){
            for(auto& j : m_clients)
                if( j.getId() == id ){
                    j.delProduct(titre);
                    break;
                }
            break;
        }
}

void Magasin::updateProductQuantityClient(std::string titre, int quantite, int id){
    for(auto& i : m_products)
        if( i.getTitre() == titre){
            for(auto& j : m_clients)
                if( j.getId() == id ){
                    j.newQuantity(titre, quantite);
                    break;
                }
            break;
        }
}

void Magasin::updateProductQuantityClient(std::string titre, int quantite, std::string prenom, std::string nom){
    for(auto& i : m_products)
        if( i.getTitre() == titre){
            for(auto& j : m_clients)
                if( j.getPrenom() == prenom || j.getNom() == nom){
                    j.newQuantity(titre, quantite);
                    break;
                }
            break;
        }  
}


//Méthodes pour valider la  commande
bool Magasin::validCommande(Client& client){
    bool valide = true ;
    for(auto& i:client.getPanier())
        for(auto& j:m_products)
            if(i.getTitre() == j.getTitre())
                if( i.getQuantite() >= j.getQuantite()){
                    valide = false;
                    std::cout << " la quantite du produit  ici  est  -- "
                              << i.getTitre() << " -- est : " << j.getQuantite();
                    }                                     

    if(valide){
        Commande commande(client);
        m_orders.push_back(commande);
        //modifier la quantité des produits est present  après  validation
        for(auto& i :client.getPanier())
            for(auto& j: m_products)
                if(i.getTitre() == j.getTitre()){
                    int quantite_restee;
                    quantite_restee = j.getQuantite() - i.getQuantite();
                    j.setQuantite(quantite_restee);
                }

        std::cout << "Commande validee" << std::endl;
        client.viderPanier();
    }

    else
        std::cout << " la Commande ne se trouve pas " << std::endl;
    
    return valide;
}

bool Magasin::validCommande(std::string prenom, std::string nom){
    bool valide = true ;
    Client* client;
    bool client_trouve = false;
    //vérifier que le client existe
    for(auto&i : m_clients)
        if(i.getPrenom() == prenom && i.getNom() == nom ){
            client = &i;
            client_trouve = true ;
            break;
        }

    if(client_trouve)
    for(auto& i:client -> getPanier())
        for(auto& j:m_products)
            if(i.getTitre() == j.getTitre())
                if( i.getQuantite() >= j.getQuantite()){
                    valide = false;
                    std::cout << " la quantite du produit ici est   -- "
                              << i.getTitre() << " -- est : " << j.getQuantite();
                    }                                     

    if(valide){
        Commande commande(*client);
        m_orders.push_back(commande); 
        for(auto& i :client->getPanier())
            for(auto& j: m_products)
                if(i.getTitre() == j.getTitre()){
                    int quantite_restee;
                    quantite_restee = j.getQuantite() - i.getQuantite();
                    j.setQuantite(quantite_restee);
                }

        std::cout << " la Commande  est validee" << std::endl;
        client->viderPanier();
    }
    else if(!client_trouve)
        std::cout << "Commande n'existe pas  ,  aucun client ici " << std::endl;
    
    return valide;
}
bool Magasin::validCommande(int id){
    bool valide = true ;
    Client *client;
    bool client_trouve = false;
    //vérification que le  client existe
    for(auto&i : m_clients)
        if(i.getId() == id ){
            client = &i;
            client_trouve = true ;
            break;
        }


    for(auto& i:client->getPanier())
        for(auto& j:m_products)
            if(i.getTitre() == j.getTitre())
                if( i.getQuantite() > j.getQuantite()){
                    valide = false;
                    std::cout << "[ERROR - PAS VALIDE] la quantite  du produit   "
                              << i.getTitre() << "  est : " << j.getQuantite() << ". Le client en a demande " << i.getQuantite() << std::endl;
                    }                                     

    if(valide){
        Commande commande(*client);
        m_orders.push_back(commande); 
        std::cout << "Commande validee" << std::endl;
        client->viderPanier();
    }
    else if(!client_trouve)
        std::cout << " la Commande ne se trouve pas ici ,  aucun client ici " << std::endl;
    
    return valide;
}


//méthode  qui permer de mettre  à jour du statut de la commande
bool Magasin::updateCommandeStatus(int id , bool status){
    //trouver la commande en se servant de son id
    bool commande_trouvee = false;

    for(auto&i : m_orders)
        if(i.getId() == id ){
            i.setLivraison(status);
            commande_trouvee = true ;
            break;
        }    
    
    if(commande_trouvee)
        std::cout << "Mise à jour la  statut de la commande reussie\n";
    else
        std::cout << "Mise à jour la  statut de la commande ne reussie pas  \n";

    return commande_trouvee ;   
}


void Magasin::showCommandePassees(){
    std::cout << "\t---Affichage des commandes passées---\n";
    for(auto& i : m_orders)
        if(i.getLivraison())
            std::cout << i << std::endl;
}

//méthode affichage des commandes d'un client donné

void Magasin::showCommandesClient(int id){
    std::cout << "\t---Affichage des commandes du client qui a l'ID suivant  " << id << " ---\n";
    for(auto& i : m_orders){
        std::cout << " afficher le client avec son ID " << std::endl;
        if( i.getClient()->getId() == id)
            std::cout << i << std::endl;
    }

}

void Magasin::showCommandesClient(std::string prenom, std::string nom){
    std::cout << "\t---Affichage des commandes du client " << prenom << " "<< nom << " ---\n";
    for(auto& i : m_orders)
        if( i.getClient()->getPrenom() == prenom && i.getClient()->getNom() == nom)
            std::cout << i << std::endl;
}

bool Magasin::productExist(std::string titre){
    for(auto&i : m_products)
        if(i.getTitre() == titre)
            return true;
    return false;
}

Product* Magasin::productFind(std::string titre){
    for(auto&i : m_products)
        if(i.getTitre() == titre)
            return &i;
    //si on trouve pas le produit correspondant on fait un return
    return nullptr;
}

//méthode qui vérifie l'existance d'un client avec ( son nom et prenom)
bool Magasin::clientExist(std::string prenom, std::string nom){
    for(auto& i:m_clients)
        if( i.getPrenom() == prenom && i.getNom() == nom)
            return true ;

    return false ;
}

//méthode qui vérifie l'exisrtance d'un client avec son ID
bool Magasin::clientExist(int id){
    for(auto& i:m_clients)
        if( i.getId() == id)
            return true;
    
    return false;
}

//méthode qui retourne un client trouvé avec  son nom et son  prénom
Client* Magasin::clientFind(std::string prenom , std::string nom){
    if(clientExist(prenom,nom)){
        for(auto& i:m_clients)
            if( i.getPrenom() == prenom && i.getNom() == nom)
                return &i ;//client trouvé
    } 
    
    else
        std::cout << " client n'existe pas \n";
    
    return nullptr;
}
