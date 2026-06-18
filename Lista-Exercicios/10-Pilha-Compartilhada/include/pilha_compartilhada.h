#define NUM 20

struct elemento {
    int chave;
};

typedef struct tipoPilha Pilha;

Pilha* criarPilha();
void liberarPilha(Pilha* pilha);

int push(Pilha* pilha, struct elemento valor, int num);
int pop(Pilha* pilha, struct elemento* valor, int num);

int pilhaVazia(Pilha* pilha, int num);
int pilhaCheia(Pilha* pilha);
void imprimirPilha(Pilha* pilha, int num);
