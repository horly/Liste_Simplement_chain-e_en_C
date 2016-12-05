#include<stdio.h>
#include<stdlib.h>
//Déclaration d'une liste simplement chainée
typedef struct maillon
{
	int valeur;
	struct maillon *suivant;
} maillon, *List;

//création d'une nouvelle liste, une fonction qui crée une nouvelle liste 
List new_List(void)
{
	return NULL;
}

//Tester si une liste est vide ou pas, c'est un boolean qui retourne vrai ou faux
bool isEmpty_List(List list)
{
	if(list == NULL)			
	{
		return true;
	}
	else
	{
		return false;
	}
} 

//Afficher les éléments d'une liste 
void display(List li)
{
	struct maillon *p = li;		//pointeur de parcours 
	if(isEmpty_List(li))
	{
		printf("La liste est vide\n");
	}
	
	while(p != NULL)
	{
		printf("[%d]>", p->valeur);
		p = p->suivant;
	}
	printf("NILL\n");
}

//insertion à la tête de la liste 
List add_head(List li, int x)
{
	struct maillon *p_new = (maillon*) malloc(sizeof(*p_new));   //creation d'une nouvelle espace mémoire 	
	if(p_new == NULL)											//si l'allocation est égale à null alors impossible d'insérer
	{
		printf("Allocation échouee");
	}
	
	if (isEmpty_List(li))
	{
		p_new->valeur = x;
		p_new->suivant = NULL;
	}
	else 													//sinon le champ valeur reçoit la valeur 
	{														//et le champ lien pointe sur la tête de la liste 
		p_new->valeur = x;
		p_new->suivant = li;
	}
	return p_new;
}

List add_end(List li, int x)
{
	struct maillon *p_new = (maillon*) malloc(sizeof(*p_new));   //creation d'une nouvelle espace mémoire 	
	if(p_new != NULL)										 	//si l'allocation est différent de null on affecre la valeur et le pointeur par null
	{
		p_new->valeur = x;
		p_new->suivant = NULL;
		
		if(li == NULL)					//si la tête de la liste est vide on fait la même chose
		{
			li = p_new;
		}
		else 
		{
			struct maillon *p = li;
			while(p->suivant !=NULL)
			{
				p = p->suivant;
			}
			p->suivant = p_new;
		}
	}
	return li;
}

List delete_head(List li)		//suprimmer à la tête de la liste
{
		struct maillon *p = (maillon*) malloc(sizeof(*p)); 
		if(p == NULL)
		{
			printf("Allocation échouee");
		}
		
		if(isEmpty_List(li))
		{
			printf("rien a supprimer car la liste est vide");
		}
		else
		{
			p = li->suivant;
			free(li);
			li=NULL;
		}
	return p;
}

List delete_end(List li)
{
	struct maillon *p = (maillon*) malloc(sizeof(*p)); 
		if(p == NULL)
		{
			printf("Allocation échouee");
		}
		
		if(isEmpty_List(li))
		{
			printf("rien a supprimer car la liste est vide");
		}
			struct maillon *prec = (maillon*) malloc(sizeof(*prec));
			p = li;
			prec = li;
			
			while(p != NULL)
			{
				prec = p;
				p = p->suivant;
			}
			prec = NULL;
			free(p);
			p = NULL;
		return li;
}
main()
{
	List L = new_List();			//exemple d'une Creation d'une liste vide en appellant la fonction new_List						//Création d'une liste qu'on veux inserer les éléments
	
	printf("Ajout a la tete de la liste : ");
	L = add_head(L, 5);				//insertion de l'élément 5, 7, 6
	L = add_head(L, 6);
	L = add_head(L, 7);
	display(L);
	
	printf("\n");
	printf("apres supression a la tete : ");
	L = delete_head(L);
	display(L);
	
	printf("\n");
	printf("apres supression a la fin : ");
	L = delete_end(L);
	
	printf("\n");
	
	printf("Ajout a la fin de la liste : ");
	List L1 = new_List();
	L1 = add_end(L1, 10);
	L1 = add_end(L1, 20);
	L1 = add_end(L1, 30);
	display(L1);
	
	printf("\n");
	printf("apres supression a la tete : ");
	L1 = delete_head(L1);
	display(L1);
	
	/*if(isEmpty_List(L))				//Tester si la liste est vide ou non et afficher le message 	
	{
		printf("La liste est vide\n");
	}
	else
	{
		printf("La liste est pleine\n");
	}
	system("pause");*/
}

