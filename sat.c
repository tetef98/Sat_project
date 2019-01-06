#include<stdio.h>
#include<stdlib.h>


typedef struct clause {
    char value;
    struct clause *next;
} clause;

/*
Fonction: Saisir le nombre de variables dans une clause par l'utilisateur
variable: nb_var indique le nombre de variable / exemple: (a || b) donc 2 variables
*/
int condition1()
{
	int nb_var;
	printf("2) Entrer nombre de variables dans la clause:\n");
   	scanf("%d", &nb_var);
   	
   	return nb_var;
}
/*
Fonction: Saisir le nombre de clause dans l'expression par l'utilisateur
variable: nb_clause indique le nombre de variable / exemple: (a || b) et (A || B) donc 2 clauses
*/
int condition2()
{
	int nb_clause;
	printf("1) Entrer le nombre de clause :\n");
	scanf("%d", &nb_clause);
   	return nb_clause;
}

/*
Fonction: Afficher le tableau de référence qui montre la liste de solutions en fonction des variables lorsqu'on a une clause à deux variables
variable: tab[5][4]  
*/
void affichage1(char tab[5][4])
{
	int i,j;
	for (i=0; i<5; i++)
	{
		for(j=0; j<4; j++)
		{
			printf("| %c |", tab[i][j]);
		}
		printf("\n");
	}
}
/*
Fonction: Afficher le tableau de référence qui montre la liste de solutions en fonction des variables lorsqu'on a une clause à 3 variables
variable: tab[10][6]  
*/
void affichage2(char tab[10][6])
{
	int i,j;
	for (i=0; i<10; i++)
	{
		for(j=0; j<6; j++)
		{
			printf("| %c |", tab[i][j]);
		}
		printf("\n");
	}
}
/*
Fonction: Afficher la liste
variable: une clause (liste clause)
*/
void affichage_liste(clause * l)
{	
	printf("/  %c /", l->value);
	while(l!= NULL)
   	{
   		l = l->next;
   		printf("/  %c /", l->value);
	}
}
//////////////// CREATION DE LA LISTE : Allocation en mémoire d'une clause " ////////////////////:
clause * creation(int valeur)
{
	clause * nouveau;
	nouveau = (clause*)malloc(sizeof(clause));
	nouveau -> next=NULL; // initialiser les valeurs suivantes à NULL pour que chaque pointeur pointe vers un rien
	nouveau -> value=valeur;
	return nouveau ;
}
/*  Fonction Création d'une clause composé de X variables  
variables : nb_var: nombre de variables dans la clause / clause *l = liste contenant clause/ clause * p: liste intermédiaire / valeur : variable dans la clause
*/
clause * saisir_clause (int nb_var)
{	
	clause * l;
	clause * p;
   	char valeur;
   	int i;
   	for(i=0; i<nb_var; i++)
   	{
		printf("Entrer valeur\n");
		scanf("%s", &valeur);
		if((valeur=='a') || (valeur=='b') || (valeur=='c') || (valeur=='A') || (valeur=='B') || (valeur=='C'))
		{
			p=creation(valeur);		 
			p->next=l;
			l=p;
		}
		else{
			printf("Erreur d'entree variable, veuillez ressaisir\n");
			return saisir_clause(nb_var);
		}
	}
	return l;
}


// 2 variables dans une clause.
/*
Tableau qui génère les solutions pour une clause à 2 variables (a b et B C )
*/
void solution1 (char tab[5][4])
{
	int i; int j;	
	for (i=0; i<5; i++)
	{
		for(j=0; j<4; j++)
		{
			tab[0][0]='a';	tab[0][1]='b';  	tab[0][2]='A';	tab[0][3]='B';
			tab[1][0]='1';	tab[1][1]='1';	    tab[1][2]='0';	tab[1][3]='0';
			tab[2][0]='0';	tab[2][1]='0';	    tab[2][2]='1';	tab[2][3]='1';
			tab[3][0]='1';	tab[3][1]='0';	    tab[3][2]='0';	tab[3][3]='1';
			tab[4][0]='0';	tab[4][1]='1';	    tab[4][2]='1';	tab[4][3]='0';
		}
	}
}


// 3 variables dans une clause
/*
Tableau qui génère les solutions pour une clause à 3 variables (a b c et A B C )
*/
void solution2(	char tab[10][6])
{
	int i;
	int j;
	
	for (i=0; i<10; i++)
	{
		for(j=0; j<6; j++)
		{
			tab[0][0]='a';	tab[0][1]='b';	tab[0][2]='c';	tab[0][3]='A'; tab[0][4]='B'; tab[0][5]='C';
			
			tab[1][0]='1';	tab[1][1]='1';	tab[1][2]='1';	tab[1][3]='0'; tab[1][4]='0'; tab[1][5]='0';
			tab[2][0]='0';	tab[2][1]='0';	tab[2][2]='0';	tab[2][3]='1'; tab[2][4]='1'; tab[2][5]='1';
			tab[3][0]='1';	tab[3][1]='0';	tab[3][2]='1';	tab[3][3]='0'; tab[3][4]='1'; tab[3][5]='0';
			tab[4][0]='1';	tab[4][1]='1';	tab[4][2]='0';	tab[4][3]='0'; tab[4][4]='0'; tab[4][5]='1';
			tab[5][0]='1';	tab[5][1]='0';	tab[5][2]='0';	tab[5][3]='0'; tab[5][4]='1'; tab[5][5]='1';
			tab[6][0]='0';	tab[6][1]='1';	tab[6][2]='1';	tab[6][3]='1'; tab[6][4]='0'; tab[6][5]='0';
			tab[7][0]='0';	tab[7][1]='1';	tab[7][2]='0';	tab[7][3]='1'; tab[7][4]='0'; tab[7][5]='1';
			tab[8][0]='0';	tab[8][1]='1';	tab[8][2]='1';	tab[8][3]='1'; tab[8][4]='0'; tab[8][5]='0';
			tab[9][0]='0';	tab[9][1]='0';	tab[9][2]='1';	tab[9][3]='1'; tab[9][4]='1'; tab[9][5]='0';
		}
	}
}



//verification de la clause a 2 variables
/*
Fonction : Utilisant une clause à 2 variables. Elle compare la variable de la liste à celle du tableau de référence et introduit des valeurs
1 si vrai et 0 si faux . l'entier i indique la ligne ou l'on peut trouvé une solution, donc si on 1 comme résultat après comparaison
variables: clause / le tableau et i.
*/

void verif_sol1 (clause * var1, char tab[5][4]){
	int i;
	clause * var2;
	var2=var1->next;
	int tmp=0;
	int q[5];
	int m;
	for(i=1; i<5; i++){	
		if (((var1->value=='a') && (var2->value=='B')) || ((var1->value=='B') && (var2->value=='a'))){
			if(tab[i][0]=='1' || tab[i][3]=='1'){
				m=1;
				tmp=i;
				q[tmp]=tmp;
				printf(" ligne i = %d, m=%d, tmp= %d, q[tmp]=%d \n", i, m, tmp, q[tmp]);
				tmp++;
			}
			else {
				m=0;
				printf("pas de solution: %d %d \n", i, m);
			}
		}
			
		if (((var1->value=='a') && (var2->value=='b')) || ((var1->value=='b' && var2->value=='a'))){
			if (tab[i][0]=='1' || tab[i][1]=='1'){
				m=2;
				q[i]=i;
				printf(" ligne i = %d, m=%d, m[i]= %d\n", i, m, q[i]);
			}
			else {
				printf("pas de solution: %d\n", i);
				m=0;
			}
		}
		
		if (((var1->value=='A') && (var2->value=='b')) || ((var1->value=='b' && var2->value=='A'))){
			if (tab[i][2]=='1' || tab[i][1]=='1'){
				m=3;
				q[i]=i;
				printf(" ligne i = %d, m=%d, m[i]= %d\n", i, m, q[i]);
			}
			else {
				printf("pas de solution: %d\n", i);
				m=0;
			}
		}
			
		if (((var1->value=='A') && (var2->value=='a')) || ((var1->value=='a' && var2->value=='A'))){
			if (tab[i][2]=='1' || tab[i][0]=='1'){
				m=4;
				q[i]=i;
				printf(" ligne i = %d, m=%d, m[i]= %d\n", i, m, q[i]);
			}
			else {
				printf("pas de solution: %d\n", i);
				m=0;
			}
		}
			
		if (((var1->value=='B') && (var2->value=='A')) || ((var1->value=='A' && var2->value=='B'))){
			if (tab[i][2]=='1' || tab[i][3]=='1'){
				m=5;
				q[i]=i;
				printf(" ligne i = %d, m=%d, m[i]= %d\n", i, m, q[i]);
			}
			else {
				printf("pas de solution: %d\n", i);
				m=0;
			}
		}
	}
}


// verification de la clause a 3 variables
/*
Fonction : Utilisant une clause à 3 variables. Elle compare la variable de la liste à celle du tableau de référence et introduit des valeurs
1 si vrai et 0 si faux . l'entier i indique la ligne ou l'on peut trouvé une solution, donc si on 1 comme résultat après comparaison
variables: clause / le tableau et i.
*/

void verif_sol2 (clause * var1, char tab[10][6]){
	int i;
	clause * var2;
	clause * var3;
	var2=var1->next;
	var3=var2->next;
	int q[10];
	int m;
	for(i=1; i<10; i++){	
	//a B C // B C a // C a B// B a C //C B a // a C B
		if ((((var1->value=='a') && (var2->value=='B')) && (var3->value=='C')) || ((var1->value=='B') && (var2->value=='C') && (var3->value=='a')) 	|| ((var1->value=='C') && (var2->value=='a') && (var3->value=='B'))
        	|| ((var1->value=='a') && (var2->value=='C') && (var3->value=='B')) || ((var1->value=='C') && (var2->value=='B') && (var3->value=='a')) || ((var1->value=='B') && (var2->value=='a') && (var3->value=='C'))){
			if(tab[i][0]=='1' || tab[i][4]=='1' || tab[i][5]=='1'){
				m=1;
				q[i]=i;
				printf(" ligne i = %d, m=%d, m[i]= %d\n", i, m, q[i]);
			}
			else {
				m=0;
				printf("pas de solution: %d %d \n", i, m);
			}
		}

	// A B C // B C A // C A B // B A C //C B A // A C B
		if ((((var1->value=='A') && (var2->value=='B')) && (var3->value=='C')) || ((var1->value=='B') && (var2->value=='C') && (var3->value=='A')) 	|| ((var1->value=='C') && (var2->value=='A') && (var3->value=='B'))
        	|| ((var1->value=='A') && (var2->value=='C') && (var3->value=='B')) || ((var1->value=='C') && (var2->value=='B') && (var3->value=='A')) || ((var1->value=='B') && (var2->value=='A') && (var3->value=='C'))){
			if(tab[i][3]=='1' || tab[i][4]=='1' || tab[i][5]=='1'){
				m=4;
				q[i]=i;
				printf(" ligne i = %d, m=%d, m[i]= %d\n", i, m, q[i]);
			}
			else {
				printf("pas de solution: %d\n", i);
				m=0;
			}
		}
	// a b c // b c a // c a b // b a c // c b a // a c b
		if ((((var1->value=='a') && (var2->value=='b')) && (var3->value=='c')) || ((var1->value=='b') && (var2->value=='c') && (var3->value=='a')) 	|| ((var1->value=='c') && (var2->value=='a') && (var3->value=='b'))
        	|| ((var1->value=='a') && (var2->value=='c') && (var3->value=='b')) || ((var1->value=='c') && (var2->value=='b') && (var3->value=='a')) || ((var1->value=='b') && (var2->value=='a') && (var3->value=='c'))){
			if(tab[i][0]=='1' || tab[i][2]=='1' || tab[i][5]=='1'){
				m=5;
				q[i]=i;
				printf(" ligne i = %d, m=%d, m[i]= %d\n", i, m, q[i]);
			}
			else {
				printf("pas de solution: %d\n", i);
				m=0;
			}
		}
	// A B c // B c A // c A B // B A c // c B A // A c B
		if ((((var1->value=='A') && (var2->value=='B')) && (var3->value=='c')) || ((var1->value=='B') && (var2->value=='c') && (var3->value=='A')) 	|| ((var1->value=='c') && (var2->value=='A') && (var3->value=='B'))
        	|| ((var1->value=='A') && (var2->value=='c') && (var3->value=='B')) || ((var1->value=='c') && (var2->value=='B') && (var3->value=='A')) || ((var1->value=='B') && (var2->value=='A') && (var3->value=='c'))){
			if(tab[i][2]=='1' || tab[i][3]=='1' || tab[i][4]=='1'){
				m=5;
				q[i]=i;
				printf(" ligne i = %d, m=%d, m[i]= %d\n", i, m, q[i]);
			}
			else {
				printf("pas de solution: %d\n", i);
				m=0;
			}
		}

	// A b C // b C A // C A b // A C b // C B a // b A C
		if ((((var1->value=='A') && (var2->value=='b')) && (var3->value=='C')) || ((var1->value=='b') && (var2->value=='C') && (var3->value=='A')) 	|| ((var1->value=='C') && (var2->value=='A') && (var3->value=='b'))
        	|| ((var1->value=='A') && (var2->value=='C') && (var3->value=='b')) || ((var1->value=='C') && (var2->value=='B') && (var3->value=='a')) || ((var1->value=='b') && (var2->value=='A') && (var3->value=='C'))){
			if(tab[i][1]=='1' || tab[i][3]=='1' || tab[i][5]=='1'){
				m=5;
				q[i]=i;
				printf(" ligne i = %d, m=%d, m[i]= %d\n", i, m, q[i]);
			}
			else {
				printf("pas de solution: %d\n", i);
				m=0;
			}
		}
	//	a B c // B c a // c a B // B a c // c B a // a c B
		if ((((var1->value=='a') && (var2->value=='B')) && (var3->value=='c')) || ((var1->value=='B') && (var2->value=='c') && (var3->value=='a')) 	|| ((var1->value=='c') && (var2->value=='a') && (var3->value=='B'))
        	|| ((var1->value=='a') && (var2->value=='c') && (var3->value=='B')) || ((var1->value=='c') && (var2->value=='B') && (var3->value=='a')) || ((var1->value=='B') && (var2->value=='a') && (var3->value=='c'))){
			if(tab[i][0]=='1' || tab[i][2]=='1' || tab[i][4]=='1'){
				m=3;
				q[i]=i;
				printf(" ligne i = %d, m=%d, m[i]= %d\n", i, m, q[i]);
			}
			else {
				printf("pas de solution: %d\n", i);
				m=0;
			}
		}
		
			// 1) A b c // b c A // c A b // b A c // c b A // A c b
		if ((((var1->value=='A') && (var2->value=='b')) && (var3->value=='c')) || ((var1->value=='b') && (var2->value=='c') && (var3->value=='A')) 	|| ((var1->value=='c') && (var2->value=='A') && (var3->value=='b'))
        	|| ((var1->value=='A') && (var2->value=='c') && (var3->value=='b')) || ((var1->value=='c') && (var2->value=='b') && (var3->value=='A')) || ((var1->value=='b') && (var2->value=='A') && (var3->value=='c'))){
			if(tab[i][1]=='1' || tab[i][2]=='1' || tab[i][3]=='1'){
				m=5;
				q[i]=i;
				printf(" ligne i = %d, m=%d, m[i]= %d\n", i, m, q[i]);
			}
			else {
				printf("pas de solution: %d\n", i);
				m=0;
			}
		}
	// 1 a b C // b C a // C a b // a C b // C b a // b a C
		if ((((var1->value=='a') && (var2->value=='b')) && (var3->value=='C')) || ((var1->value=='b') && (var2->value=='C') && (var3->value=='a')) 	|| ((var1->value=='C') && (var2->value=='a') && (var3->value=='b'))
        	|| ((var1->value=='a') && (var2->value=='C') && (var3->value=='b')) || ((var1->value=='C') && (var2->value=='b') && (var3->value=='a')) || ((var1->value=='b') && (var2->value=='a') && (var3->value=='C'))){
			if(tab[i][0]=='1' || tab[i][1]=='1' || tab[i][5]=='1'){
				m=5;
				q[i]=i;
				printf(" ligne i = %d, m=%d, m[i]= %d\n", i, m, q[i]);
			}
			else {
				printf("pas de solution: %d\n", i);
				m=0;
			}
		}
	}
}


int main()
{  	
		printf("\t\t BIENVENUE DANS LE PROJET SAT 2018\n");	
		clause * tab[5];
		char tab1[5][4];
		char tab2[10][6];
		int i;
		
		solution1(tab1);
		solution2(tab2);
		
		affichage1(tab1);
		printf("\n\n");
		affichage2(tab2);
	
		int nb_clause=condition2();
		int nb_var;
		
		for (i=0; i<nb_clause; i++)
		{
			printf("Bonjour, ne faire entrer les variables suivantes: \n a b c et leurs negations respectives: A B C \n ");
			nb_var=condition1();
			tab[i]= saisir_clause(nb_var);
			if(nb_var==1) {
				printf("Une solution est 1\n");
			}
			
			if(nb_var==2) verif_sol1(tab[i], tab1);
			if(nb_var==3) verif_sol2(tab[i], tab2);
			
		}
		affichage_liste(tab[0]);
   		return 0;
}     

