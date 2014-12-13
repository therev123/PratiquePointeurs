//Ce programme demande � l'utilisateur de saisir un nombre 
//La valeur 0 marque la fin des donn�es.Le programme affiche,
//� la fin, la liste de tous les nombres entr�s par l'utilisateur
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
	//Affiche la liste de toutes les valeurs entr�es par l'utilisateur
	AfficherElementListe();
	//Additionne tous les �l�ments ensemble
	for (Element* Pointeur = premierElement; Pointeur != NULL; Pointeur = Pointeur->ptrSuivant)
	{
		resultatSommeElm += Additionner(Pointeur->valeur);
	}
	//Affiche la somme total de tous les �l�ments
	cout << "La somme de tous les elements est: " << resultatSommeElm << "\n";

	system("pause");
	//Lib�ration de la m�moire
	LibererMemoire();
	return 0;
}

void  AjouterElement(int donnee)
{
	/*Fonction charg�e d'ajouter un nouvel �l�ment � la liste cha�n�e*/
	
	//Pointeur temporaire
	Element* Pointeur = NULL;
	
	//Allocation dynamique d'un objet de type Element
	Pointeur = new Element;
	
	//Initialisation du membre valeur � la valeur du param�tre donnee
	Pointeur->valeur = donnee;

	/*Emb�tant d�boguer le programme pour voir si tout fonctionne bien
	Et qu'un �l�ment pointe bien sur le prochaine �l�ment*/
	//cette ligne semble finalement correcte 
	//Initialisation du membre ptrSuivant
	Pointeur->ptrSuivant = premierElement;

	//premierElement pointe maintenant sur le nouvel �l�ment
	//Ajout d'un �l�ment en t�te de liste
	premierElement = Pointeur;
}
void AfficherElementListe()
{
	/*Fonction charg�e d'afficher les donn�es contenues dans la liste cha�n�e*/
	//Pointeur temporaire 
	Element* Pointeur = premierElement;
	//Tant que pointeur pointe quelque chose d'existant
	while (Pointeur != NULL)
	{
		//Affiche la valeur contenu dans le premier �l�ment
		cout << Pointeur->valeur << "\n";
		
		//Passe � l'�l�ment suivant
		Pointeur = Pointeur->ptrSuivant;
	}
}
void LibererMemoire()
{
	/*Fonction charg�e de lib�rer la m�moire dynamiquement alou�e*/

	//Pointeur temporaire pointant l'�l�ment en t�te de liste
	Element* Pointeur = NULL;

	//Tant que premierElement pointe vers quelque chose  
	while (premierElement != NULL)
	{
		//Pointeur pointe l'addresse du premier �l�ment 
		Pointeur = premierElement;

		//premierElement pointe maintenant sur l'�l�ment suivant
		premierElement = premierElement->ptrSuivant;

		//D�salocation m�moire de l'�l�ment courant
		delete Pointeur;
	}
}