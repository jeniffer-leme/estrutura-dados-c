struct elemento {
    int matricula;
    char nome[40];
    float nota1, nota2;
};

typedef struct tipoNo *Pilha;

Pilha* criarLista();
void liberarPilha(Pilha* topo);

