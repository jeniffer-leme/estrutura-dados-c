struct elemento {
    int numeros;
};

typedef struct tipoLista Lista;

Lista* criarLista();
void apagaLista(Lista* lista);

int insereElemento(Lista* lista, struct elemento valor);
int removeElemento(Lista* lista, int num);

Lista* uniaoListas(Lista* L1, Lista* L2);
void imprimeLista(Lista* lista);
