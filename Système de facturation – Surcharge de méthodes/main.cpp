#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Article {
    string nom;
    double prixUnitaire;
    int quantite;
    double tva;
};


class Facture {
private:
    vector<Article> articles;

public:

    void ajouterArticle(const string& nom, double prix) {
        Article a = {nom, prix, 1, 0.0};
        articles.push_back(a);
    }


    void ajouterArticle(const string& nom, double prix, int quantite) {
        Article a = {nom, prix, quantite, 0.0};
        articles.push_back(a);
    }

    void ajouterArticle(const string& nom, double prix, int quantite, double tva) {
        Article a = {nom, prix, quantite, tva};
        articles.push_back(a);
    }


    void afficherTotal() const {
        double totalHT = 0.0;
        double totalTTC = 0.0;

        cout << "\n=== Détail de la facture ===\n";
        for (const auto& a : articles) {
            double sousTotalHT = a.prixUnitaire * a.quantite;
            double sousTotalTTC = sousTotalHT * (1 + a.tva / 100);

            cout << "Article : " << a.nom
                 << " | PU : " << a.prixUnitaire
                 << " | Qté : " << a.quantite
                 << " | TVA : " << a.tva << "%"
                 << " | Total TTC : " << sousTotalTTC << " Dh" << endl;

            totalHT += sousTotalHT;
            totalTTC += sousTotalTTC;
        }

        cout << "-----------------------------\n";
        cout << "Total HT  : " << totalHT << " Dh\n";
        cout << "Total TTC : " << totalTTC << " Dh\n";
    }
};


int main() {
    Facture f;

    f.ajouterArticle("Clavier", 200.0);
    f.ajouterArticle("Souris", 100.0, 2);
    f.ajouterArticle("Écran", 1500.0, 1, 20.0);
    f.afficherTotal();

    return 0;
}
