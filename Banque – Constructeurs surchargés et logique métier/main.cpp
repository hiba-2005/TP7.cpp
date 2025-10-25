#include <iostream>
#include <string>
using namespace std;

class CompteBancaire {
private:
    string titulaire;
    double solde;
    string codeSecurite;

public:

    CompteBancaire(string nom) {
        titulaire = nom;
        solde = 0.0;
        codeSecurite = "0000";
    }


    CompteBancaire(string nom, double s) {
        titulaire = nom;
        solde = s;
        codeSecurite = "0000";
    }

    CompteBancaire(string nom, double s, string code) {
        titulaire = nom;
        solde = s;
        codeSecurite = code;
    }


    void afficherSolde() {
        cout << "Titulaire : " << titulaire << " | Solde : " << solde << " Dh" << endl;
    }

    // Retrait simple
    void retrait(double montant) {
        if (montant <= solde) {
            solde -= montant;
            cout << "Retrait de " << montant << " Dh effectué." << endl;
        } else {
            cout << "Solde insuffisant !" << endl;
        }
    }


    void retrait(double montant, string code) {
        if (code == codeSecurite) {
            if (montant <= solde) {
                solde -= montant;
                cout << "Retrait sécurisé de " << montant << " Dh effectué." << endl;
            } else {
                cout << "Solde insuffisant !" << endl;
            }
        } else {
            cout << "Code de sécurité incorrect !" << endl;
        }
    }
};

int main() {

    CompteBancaire c1("Lamia");
    CompteBancaire c2("Yassine", 2000.0);
    CompteBancaire c3("Said", 5000.0, "1234");

    c1.afficherSolde();
    c2.afficherSolde();
    c3.afficherSolde();

    cout << "\n--- Retraits ---" << endl;
    c2.retrait(500);
    c3.retrait(1000, "1234");
    c3.retrait(1000, "9999");

    return 0;
}
