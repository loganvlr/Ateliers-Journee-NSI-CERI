#include <iostream>
#include <string>
using namespace std;

void welcoming()
{
    cout << "Nous vous souhaitons la bienvenue dans notre atelier sur la cybersécurité !" << endl;
    cout << "Etes-vous prêt à entrer les mots de passes ?" << endl;
    cout << "Appuyez sur Entrée...";
    cin.ignore();
    cout << "C'est parti !" << endl;
}

void checkPassword(string & finded_password, const string & password, const string & input, bool & found)
{
    if (password == input)
    {
        found = true;
    }
    else if (input.length() != password.length())
    {
        cout << "Le mot de passe donné ne fait pas la même taille que celui cherché !" << endl;
    }
    else
    {
        for (int i = 0; i < password.length(); i++)
        {
            if (password[i] == input[i])
            {
                finded_password[i] = input[i];
            }
        }
    }
}

void enterPassword()
{
    const string password = "mypassword";
    string finded_password(password.length(), '*');
    string input;
    bool found = false;
    cout << "Le mot de passe a été initialisé. A vous de jouer !" << endl;
    while (!found)
    {
        cout << "Mot de passe à trouver : " << finded_password << endl;
        cout << "Entrez votre mot de passe : ";
        cin >> input;
        checkPassword(finded_password, password, input, found);
        if (found)
        {
            cout << "Vous avez trouvé ! Le mot de passe était bien " << password << "." << endl;
        }
        else
        {
            cout << "Vous n'avez pas réussi ! Réessayez." << endl;
        }
    }
}

int main() {
    welcoming();
    enterPassword();
    return 0;
}
