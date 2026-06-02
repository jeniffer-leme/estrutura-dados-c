struct elemento {
    int num;
};

typedef struct tipoNo *Lista; 


Lista* criarLista();

int inserirOrdenada(Lista* inicio, struct elemento valor);

int removerElemento(Lista* inicio, int valor);

void imprimirLista(Lista* inicio);

void liberarLista(Lista* inicio);
