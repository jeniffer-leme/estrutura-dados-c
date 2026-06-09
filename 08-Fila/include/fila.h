struct elemento {
    int matricula;
    char nome[40];
    float nota1, nota2;
};

typedef struct tipoFila Fila;

Fila* criarFila();
void liberaFila(Fila* fila);

int insereFila(Fila* fila, struct elemento aluno);
int removeFila(Fila* fila);
int consultaFila(Fila* fila, struct elemento *aluno);

int tamanhoFila(Fila* fila);
int filaVazia(Fila* fila);
void imprimeFila(Fila* fila);
