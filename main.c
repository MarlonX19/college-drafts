#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct _no {
  int ra;
  char nome[20];
  struct _no *esq;
  struct _no *dir;
}No;


char* toLowerString(char *nome){
	int i;
    for( i = 0; i < strlen(nome); i++){
     nome[i] = tolower(nome[i]);
    }
    return nome;
}

int somaChar(char *palavra){
   int t = strlen(palavra);
   int count = 0;
	int i;
   for(i = 0; i < (t); i++) {
    count += palavra[i];
   }

   return count;
}


No* inicializar(No *root){
  root = NULL;
  return root;
}

int estaVazia(No *root){
 if(root==NULL)
   return 1;
 else
 return 0;
}

No* inserir(No *root, char *nome, int ra){
              if(root == NULL){
                root = (No*)malloc(sizeof(No));
                strcpy(root->nome, nome);
                root->ra = ra;
                root->esq = NULL;
                root->dir = NULL;
              }

               else if (somaChar(nome) < somaChar(root->nome)){
                root->esq = inserir(root->esq, nome, ra);
              }

              else if (somaChar(nome) > somaChar(root->nome)){
                root->dir = inserir(root->dir, nome, ra);
              }

      return root;
}

void arv_emordem(No *root){

       if(root!=NULL){
        arv_emordem(root->esq);
        printf("%s %d \n", root->nome, root->ra);
        arv_emordem(root->dir);
       }

}


void arv_preordem(No *root){

   if(root!=NULL){
     printf("%s %d \n", root->nome, root->ra);
     arv_preordem(root->esq);
     arv_preordem(root->dir);
   }

}

void arv_posordem(No *root){
    if(root!=NULL){
      arv_posordem(root->esq);
      arv_posordem(root->dir);
      printf("%s %d \n", root->nome, root->ra);
    }
}


void encontrarNome(No *root, char *nome){
     if(estaVazia(root)==1){
              printf("Arvore vazia ou nome nao encontrado, sem dados para exibir!\n\n");
            }

      else {

            if(somaChar(nome) == somaChar(root->nome)){
                printf("Aluno encontrado! \n Nome: %s \n RA: %d ", root->nome, root->ra);
              }

            else  if(somaChar(nome) < somaChar(root->nome)){
              encontrarNome(root->esq, nome);
            }

             else if(somaChar(nome) > somaChar(root->nome)){
               encontrarNome(root->dir, nome);
             }

        }

}

/* COMPARA TOTAL DE VALORES DE DUAS ARVORES*/
int compara(No *A, No *B){
	printf("COMPARANDO... \n");
	int somaA = somaARV(A);
	printf("---------------------- \n");
	int somaB = somaARV(B);
	printf("---------------------- \n");
	
	printf("arv A = %d \n", somaA);
	printf("arv b = %d \n", somaB);
	
	if(somaA == somaB) return 0;
	 return 1;
}


/*SOMA VALORES DA ARVORE*/
int somaARV(No *arv){
	int s = 0;
	
	if(arv != NULL){
		s+= somaARV(arv->esq);
		s+= arv->ra;
		printf("valor = %d \n", arv->ra );
		s+= somaARV(arv->dir);
	}
	
	return s;
}

int main()
{   No *no;
     char nome[20];
     int op = 0;
     int ra =0;
     
     No *no2;
     int comp;

     no = inicializar(no);
     no = inserir(no, "marlon", 6);
     no = inserir(no, "mar", 7);
     no = inserir(no, "rob", 5);
     
     no2 = inicializar(no2);
     no2 = inserir(no2, "marlon", 9);
     no2 = inserir(no2, "mar", 8);
     no2 = inserir(no2, "rob", 1);

   while(op > -1 && op < 7) {
           printf("\nSelecione a opcao que deseja!\n");

            printf("<1> Inserir aluno na arvore\n");
            printf("<2> Mostrar pre ordem\n");
            printf("<3> Mostrar pos ordem\n");
            printf("<4> Mostrar em ordem\n");
            printf("<5> Encontrar aluno na arvore\n");
            printf("<6> Sair\n");
            printf("<7> COMPARA (valores de duas arv)\n");
              scanf("%d", &op);

    switch(op) {
            case 1:
                printf("Digite o nome do aluno: ");
                scanf("%s", nome);
                toLowerString(nome);
                printf("Digite o RA do aluno: ");
                scanf("%d", &ra);
                no = inserir(no, nome, ra);
                break;
            case 2:
               arv_preordem(no);
               break;

            case 3:
              arv_posordem(no);
              break;

            case 4:
               arv_emordem(no);
               break;

           case 5:
                printf("Digite o nome do aluno a procurar: ");
                scanf("%s", nome);
                toLowerString(nome);
               encontrarNome(no, nome);
               break;

            case 6:
              printf("Você está saindo, tecle qualquer tecla para sair agora!");
               getchar();
               op = -1;
               break;
               
            case 7:
            	comp = compara(no, no2);
            	if(comp == 0) printf("\n iguais \n");
            	else printf("\n diferentes \n");
            	break;
            

            default:
              printf("Opcao invalida!\n");
        }
    }

    return 0;
}
