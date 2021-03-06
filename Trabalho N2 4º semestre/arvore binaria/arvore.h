typedef struct _no {
    int dado;
    struct _no *pai;
    struct _no *esq;
    struct _no *dir;
} NO;

void inicializar (NO **tree);
int estaVazia (NO *tree);
NO* pesquisar (NO* tree, int valor);
int noExiste (NO* tree, int valor);
void preOrdem (NO *tree);
void posOrdem (NO *tree);
void emOrdem (NO *tree);
void inserir (NO **tree, int valor);
NO* achaMaior (NO* arvore);
int remover (NO **arvore, int dado);
int acharNoRaiz(NO *arvore);
int contarNosFolhas(NO *arvore);
int mostrarNosFolhas(NO *arvore);
int mostrarNosRamos(NO *arvore);
int maior(int a, int b);
int alturaDaArvore(NO *arvore);
int grauArvore(NO *tree);
int profundidadeDoNo(NO* tree, int valor);
int alturaDoNo(NO *arvore);
int nivelDoNo(NO* tree, int valor);
void ancestraisDoNo(NO* tree, int valor);
void descendentesDoNo(NO *tree, int raiz);
void representacaoBarra(NO *x, int b);
void printnode(int c, int b);
