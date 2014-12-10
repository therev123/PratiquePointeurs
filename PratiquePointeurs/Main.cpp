//Ce programme demande � l'utilisateur de saisir un nombre 
//La valeur 0 marque la fin des donn�es.Le programme affiche,
//� la fin, la liste de tous les nombres entr�s par l'utilisateur
//ainsi que la somme total des nombres.
//Date de cr�ation: 25 Novembre 2014
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
	//D�claration d'un poiteur 
	int* ptrA = NULL;
	//Affectation de l'addresse d'une variable � un pointeur
	ptrA = &A;
	//Affiche la valeur du pointeur(L'addresse qu'il pointe)
	cout << ptrA << endl;
	//Affiche la valeur contenu � l'addresse point�e
	cout << *ptrA << endl;
	//Allocation m�moire 
	ptrA = new int;
	ptrA = new int[A];
	//D�salocation m�moire
	delete ptrA; //pour un objet cr�� dynamiquement
	delete [] ptrA; //pour un tableau cr�� dynamiquement
	*/
	//Variable contenant le nombre entier entr� par l'utilisateur
	int valeur;
	//Pointeur temporaire
	Element* ptrElmt = NULL;
	
	//Boucle principale du programme 
	do
	{

	} while (valeur != 0);

	return 0;
}
