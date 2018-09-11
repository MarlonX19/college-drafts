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
    for(int i = 0; i<strlen(nome); i++){
     nome[i] = tolower(nome[i]);
    }
    return nome;
}

int somaChar(char *palavra){
   int t = strlen(palavra);
   int count = 0;

   for(int i=0; i<(t); i++) {
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

int main()
{   No *no;
     char nome[20];
     int op = 0;
     int ra =0;

     no = inicializar(no);
     no = inserir(no, "marlon", 99856);
     no = inserir(no, "mar", 88565);
     no = inserir(no, "rob", 11580);

   while(op > -1 && op < 7) {
           printf("\nSelecione a opcao que deseja!\n");

            printf("<1> Inserir aluno na arvore\n");
            printf("<2> Mostrar pre ordem\n");
            printf("<3> Mostrar pos ordem\n");
            printf("<4> Mostrar em ordem\n");
            printf("<5> Encontrar aluno na arvore\n");
            printf("<6> Sair\n");
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

            default:
              printf("Opcao invalida!\n");
        }
    }

    return 0;
}
