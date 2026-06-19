struct elemento {
    char letra;
};

typedef struct tipoPilha Pilha;

Pilha* criarPilha();
void liberarPilha(Pilha* pilha);

int pilhaVazia(Pilha* pilha);

int empilhar(Pilha* pilha, struct elemento valor);  
int desempilhar(Pilha* pilha, struct elemento* valor);
