struct elemento {
    int matricula;
    char nome[40];
    float nota1, nota2;
};

typedef struct tipoNo *Lista;

Lista* criarLista(Lista* inicio);

int insereInicio(Lista* inicio, struct elemento aluno);
int insereFinal(Lista* inicio, struct elemento aluno);
int insereOrdenado(Lista* inicio, struct elemento aluno);

int removeMatricula(Lista* inicio, int matricula);
int removeInicio(Lista* inicio);
int removeFinal(Lista* inicio);

int tamanhoLista(Lista* inicio);
int listaVazia(Lista* inicio);
void imprimeLista(Lista* inicio);
void apagaLista(Lista* inicio);
