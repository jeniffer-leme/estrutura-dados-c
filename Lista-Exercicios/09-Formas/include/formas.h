struct elemento {
    int id;
    float base;
    float altura;
};

typedef struct tipoLista Lista;

Lista* criarLista();
void apagarLista(Lista* lista);

int inserirForma(Lista* lista, struct elemento forma);
int removerForma(Lista* lista, int id);

int calcularArea(Lista* lista, struct elemento* forma);
void imprimir(Lista* lista);
