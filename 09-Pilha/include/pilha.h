struct elemento {
    int matricula;
    char nome[40];
    float nota1, nota2;
};

typedef struct tipoPilha Pilha;

Pilha* criarPilha();
void apagaPilha(Pilha* topo);

int push(Pilha* topo, struct elemento aluno);
int pop(Pilha* topo);
int consultaTopo(Pilha* topo, struct elemento *aluno);

int tamanhoPilha(Pilha* topo);
int pilhaVazia(Pilha* topo);
void imprimePilha(Pilha* topo);
