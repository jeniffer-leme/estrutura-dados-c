struct elemento {
    int num;
};

typedef struct tipoNo *Lista; 

Lista* criarLista();

int inserirOrdenada(Lista* inicio, struct elemento valor);

int removerElemento(Lista* inicio, int valor);

int intersecao(Lista* inicio, struct elemento valor);

int diferenca(Lista* inicio, struct elemento valor);

int merge(Lista* inicio, struct elemento valor);

void imprimirLista(Lista* inicio);

void liberarLista(Lista* inicio);
