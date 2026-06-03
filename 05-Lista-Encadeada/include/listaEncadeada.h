struct elemento {
    int num;
};

typedef struct tipoNo *Lista; 

Lista* criarLista();

int inserirOrdenada(Lista* inicio, struct elemento valor);

int removerElemento(Lista* inicio, int valor);

Lista* intersecao(Lista* l1, Lista* l2);

Lista* diferenca(Lista* l1, Lista* l2);

Lista* merge(Lista* l1, Lista* l2);

void imprimirLista(Lista* inicio);

void liberarLista(Lista* inicio);
