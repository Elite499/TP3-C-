#pragma once

#include "Produit.h"
#include "Client.h"
#include "Commande.h"

#include <string>
#include <iostream>
#include <vector>

using namespace std;


class Magasin {
public:
//declaration des constructeur
    Magasin();

    Magasin(std::vector<Product> &products, std::vector<Client> &clients, std::vector<Commande> &orders);

    // declaration des getters
    std::vector<Product> getProducts() const;

    std::vector<Client> getClients() const;

    std::vector<Commande> getOrders() const;

    //methode pour ajouter un nouveau produit
    void newProduct(Product produit);

    // methode pour affichager produit
    void showProducts();
    void showProduct(std::string nom_produit);

    //update quantity
    void newQuantite(std::string nom_produit, int quantite);

    // methode pour ajouter un nouveau client
    void newClient(Client &client);

    //ajouter un client avec  son nom et  prénom
    void newClient(std::string prenom, std::string nom);

    //méthode affichage des tous les clients du magasin
    void showClients();

    //méthode affichage d'un client
    void showClient(std::string prenom, std::string nom);

    void showClient(int id);

    //méthode  pour ajouter  un produit au panier
    void addProductToShoppingCart(std::string titre, std::string prenom, std::string nom);

    void addProductToShoppingCart(std::string titre, int id);

    //méthode suprimer un produit du panier d'un client
    void delProductClient(std::string titre, std::string prenom, std::string nom);

    void delProductClient(std::string titre, int id);

    //méthode modification de la  quantité d'un produit du panier d'achat d'un client
    void updateProductQuantityClient(std::string titre, int quantite, int id);

    void updateProductQuantityClient(std::string titre, int quantite, std::string prenom, std::string nom);

    //méthodes pour  valider la commande
    bool validCommande(Client &client);

    bool validCommande(std::string prenom, std::string nom);

    bool validCommande(int id);

    //méthode mise à jour du statut de la commande
    bool updateCommandeStatus(int id, bool status);

    //méthode affichage des commandes passées
    void showCommandePassees();

    //méthode affichage des commandes d'un client donné
    void showCommandesClient(int id);

    void showCommandesClient(std::string prenom, std::string nom);

    bool productExist(std::string titre);

    //méthode qui retourne un produit  par son titre
    Product *productFind(std::string titre);

    //méthode qui vérifie l'existance d'un client (  nom et prenom)
    bool clientExist(std::string prenom, std::string nom);

    //méthode qui vérifie l'exisrtance d'un client avec ID
    bool clientExist(int id);

    //méthode qui retourne un client trouvé par ( nom est prénom)
    Client *clientFind(std::string prenom, std::string nom);

    void newOrder(Commande &order);

    void addProductToStore(std::string nom, std::string description, float prix, int quantite);

private:
//declaration des attributs
    std::vector<Product> m_products;
    std::vector<Client> m_clients;
    std::vector<Commande> m_orders;
};
