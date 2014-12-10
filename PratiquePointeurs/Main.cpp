//Ce programme demande à l'utilisateur de saisir un nombre 
//La valeur 0 marque la fin des données.Le programme affiche,
//à la fin, la liste de tous les nombres entrés par l'utilisateur
//ainsi que la somme total des nombres.
//Date de création: 25 Novembre 2014
//Date de modification: 28 Novembre 2014 
//Programmeur: Bryan Tremblay
#include <iostream>
using namespace std;

struct Element
{
	int valeur;
	Element* ptrSuivant = NULL;
};
Element* premierElement = NULL;

void AjouterElement(int donnee);

int main(int argc, char **argv)
{

	/*Syntaxe utile
	int A = 8;
	//Déclaration d'un poiteur 
	int* ptrA = NULL;
	//Affectation de l'addresse d'une variable à un pointeur
	ptrA = &A;
	//Affiche la valeur du pointeur(L'addresse qu'il pointe)
	cout << ptrA << endl;
	//Affiche la valeur contenu à l'addresse pointée
	cout << *ptrA << endl;
	//Allocation mémoire 
	ptrA = new int;
	ptrA = new int[A];
	//Désalocation mémoire
	delete ptrA; //pour un objet créé dynamiquement
	delete [] ptrA; //pour un tableau créé dynamiquement
	*/
	//Variable contenant le nombre entier entré par l'utilisateur
	int valeur;
	//Pointeur temporaire
	Element* ptrElmt = NULL;
	
	//Boucle principale du programme 
	do
	{

	} while (valeur != 0);

	return 0;
}
