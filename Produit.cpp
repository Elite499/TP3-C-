#include "Produit.h"
// defenition des constructeur
Product::Product(){

}

Product::Product(std::string titre, std::string description, int quantite,double prix):
m_titre(titre),m_description(description),m_quantite(quantite),m_prix(prix){

}
// definition des getters
std::string Product::getTitre() const {return m_titre;}
std::string Product::getDescription() const{ return m_description;}
int Product::getQuantite() const {return m_quantite;}
double Product::getPrix() const {return m_prix;}
// definition des setters
void Product::setTitre(std::string& titre){ m_titre = titre;}
void Product::setDescription(std::string& description){ m_description= description;}
void Product::setQuantite(int quantite){  
    if(quantite > 0 || quantite ==0)
        m_quantite = quantite;
    else {
        m_quantite = 0;
        std::cout << " la quantite d'un produit par defaut   " << getTitre() << " est 0.\n";
    }
}
void Product::setPrix(double prix){  
      while (prix < 0 || prix ==0){
        std::cout<<" Inserer le  prix valide "<<std::endl;
        std::cin>>prix;
    }
    if(prix > 0)
        m_prix = prix;
     }

//defenition de surcharge de l operateur
std::ostream& operator<< (std::ostream &output, Product& product){
    output << "titre = " << product.getTitre() << std::endl <<"description = " <<product.getDescription()<< std::endl<<"quantite = "<< product.getQuantite() << std::endl<<" prix =" << product.getPrix()<<std::endl;
    return output ;
}
