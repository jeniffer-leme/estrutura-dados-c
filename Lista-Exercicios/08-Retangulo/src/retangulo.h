struct elemento {
    int id;
    float altura;
    float base;
};

typedef struct tipoLista Lista;

Lista* criarLista();
void apagarLista(Lista* lista);

int inserir(Lista* lista, struct elemento retangulo);
int remover(Lista* lista, int id);

float calcularArea(Lista* lista, struct elemento retangulo, int id);
void imprimir(Lista* lista);
