//Ce programme demande à l'utilisateur de saisir un nombre 
//La valeur 0 marque la fin des données.Le programme affiche,
//à la fin, la liste de tous les nombres entrés par l'utilisateur
//ainsi que la somme total de ces nombres. 
//Programmeur: Bryan Tremblay
#include <iostream>
#include "MesFonctions.h"
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
	//Variable contenant la somme de tous les nombre entier 
	int resultatSommeElm = 0;
	//Pointeur temporaire
	Element* ptrElmt = NULL;
	
	//Boucle principale du programme 
	do
	{
		cout << "Entrez un nombre: ";
		cin >> valeur;
		if (valeur != 0)
		{
			//Appel de la fonction AjouterElement
			AjouterElement(valeur);
		}
	} while (valeur != 0);
	//Affiche la liste de toutes les valeurs entrées par l'utilisateur
	AfficherElementListe();
	//Additionne tous les éléments ensemble
	for (Element* Pointeur = premierElement; Pointeur != NULL; Pointeur = Pointeur->ptrSuivant)
	{
		resultatSommeElm += Additionner(Pointeur->valeur);
	}
	//Affiche la somme total de tous les éléments
	cout << "La somme de tous les elements est: " << resultatSommeElm << "\n";

	system("pause");
	//Libération de la mémoire
	LibererMemoire();
	return 0;
}

void  AjouterElement(int donnee)
{
	/*Fonction chargée d'ajouter un nouvel élément à la liste chaînée*/
	
	//Pointeur temporaire
	Element* Pointeur = NULL;
	
	//Allocation dynamique d'un objet de type Element
	Pointeur = new Element;
	
	//Initialisation du membre valeur à la valeur du paramètre donnee
	Pointeur->valeur = donnee;

	/*Embêtant déboguer le programme pour voir si tout fonctionne bien
	Et qu'un élément pointe bien sur le prochaine élément*/
	//cette ligne semble finalement correcte 
	//Initialisation du membre ptrSuivant
	Pointeur->ptrSuivant = premierElement;

	//premierElement pointe maintenant sur le nouvel élément
	//Ajout d'un élément en tête de liste
	premierElement = Pointeur;
}
void AfficherElementListe()
{
	/*Fonction chargée d'afficher les données contenues dans la liste chaînée*/
	//Pointeur temporaire 
	Element* Pointeur = premierElement;
	//Tant que pointeur pointe quelque chose d'existant
	while (Pointeur != NULL)
	{
		//Affiche la valeur contenu dans le premier élément
		cout << Pointeur->valeur << "\n";
		
		//Passe à l'élément suivant
		Pointeur = Pointeur->ptrSuivant;
	}
}
void LibererMemoire()
{
	/*Fonction chargée de libérer la mémoire dynamiquement alouée*/

	//Pointeur temporaire pointant l'élément en tête de liste
	Element* Pointeur = NULL;

	//Tant que premierElement pointe vers quelque chose  
	while (premierElement != NULL)
	{
		//Pointeur pointe l'addresse du premier élément 
		Pointeur = premierElement;

		//premierElement pointe maintenant sur l'élément suivant
		premierElement = premierElement->ptrSuivant;

		//Désalocation mémoire de l'élément courant
		delete Pointeur;
	}
}