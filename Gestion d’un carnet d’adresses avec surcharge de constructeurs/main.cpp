#include <iostream>
#include <string>
using namespace std;


class Contact {
private:
    string nom;
    string telephone;
    string email;

public:

    Contact(string n) {
        nom = n;
        telephone = "Non défini";
        email = "Non défini";
    }

    Contact(string n, string t) {
        nom = n;
        telephone = t;
        email = "Non défini";
    }

    Contact(string n, string t, string e) {
        nom = n;
        telephone = t;
        email = e;
    }

    void afficher() {
        cout << "Nom : " << nom << endl;
        cout << "Téléphone : " << telephone << endl;
        cout << "Email : " << email << endl;
        cout << "------------------------" << endl;
    }
};

int main() {

    Contact c1("Yassine");
    Contact c2("Lamia", "0612345678");
    Contact c3("hiba", "0600112233", "Hiba.ouirouane@example.com");


    cout << "=== Carnet d'adresses ===" << endl;
    c1.afficher();
    c2.afficher();
    c3.afficher();

    return 0;
}
