struct elemento {
    int matricula;
    char nome[50];
    float nota1, nota2, nota3;
};

typedef struct tipoNo *Lista;

Lista* criarLista();
void apagaLista(Lista* inicio);
int insereFinal(Lista* inicio, struct elemento aluno);
int insereInicio(Lista* inicio, struct elemento aluno);
int insereOrdenado(Lista* inicio, struct elemento aluno);
int removeMatricula(Lista* inicio, int matricula);
int removeInicio(Lista* inicio);
int tamanhoLista(Lista* inicio);
int listaVazia(Lista* inicio);
int listaCheia(Lista* inicio);
void imprimeLista(Lista* inicio);
int consultaMatricula(Lista* inicio, int matricula, struct elemento* aluno);
int consultaPosicao(Lista* inicio, int posicao, struct elemento* aluno);
