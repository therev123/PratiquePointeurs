//Ce programme demande à l'utilisateur de saisir un nombre 
//La valeur 0 marque la fin des données.Le programme affiche,
//à la fin, la liste de tous les nombres entrés par l'utilisateur
//ainsi que la somme total de ces nombres. 
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
void AfficherElementListe();
void LibererMemoire();

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
		cout << "Entrez un nombre: ";
		cin >> valeur;
		if (valeur != 0)
		{
			//Appel de la fonction AjouterValeur
			AjouterElement(valeur);
		}
	} while (valeur != 0);

	return 0;
}

void  AjouterElement(int donnee)
{
	//Pointeur temporaire
	Element* Pointeur = NULL;
	//Allocation dynamique d'un objet de type Element
	Pointeur = new Element;
	//Initialisation du membre valeur à la valeur du paramètre donnee
	Pointeur->valeur = donnee;

	//Initialisation du membre ptrSuivant
	//Embêtant déboguer le programme pour voir si tout fonctionne bien
	//Et qu'un élément pointe bien sur le prochaine élément
	Pointeur->ptrSuivant = premierElement;
	//cette ligne est correcte 
	premierElement = Pointeur;
}
void AfficherElementListe()
{
	//Pointeur temporaire 
	Element* Pointeur = premierElement;
	while (Pointeur != NULL)
	{
		//Affiche la valeur contenu dans le premier élément
		cout << Pointeur->valeur << "\n";
		//On passe au pointeur suivant
		Pointeur = Pointeur->ptrSuivant;
	}
}
void LibererMemoire()
{
	//Pointeur temporaire pointant l'élément en tête de liste
	Element* Pointeur = premierElement;
	while (Pointeur != NULL)
	{
		delete Pointeur;
		premierElement = Pointeur->ptrSuivant;
	}
}