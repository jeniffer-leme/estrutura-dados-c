struct elemento {
    int numeros;
};

typedef struct tipoLista Lista;

Lista* criarLista();
void liberarLista(Lista* lista);

int inserirOrdenado(Lista* lista, struct elemento valor);
int removerElemento(Lista* lista, int valor);

Lista* mergeListas(Lista* L1, Lista* L2);
void imprimirLista(Lista* lista);
