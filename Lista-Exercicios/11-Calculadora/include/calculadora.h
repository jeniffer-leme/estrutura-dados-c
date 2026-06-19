struct elemento {
    float numero;
};

typedef struct tipoLista Lista;

Lista* criarLista();
void liberarLista(Lista* lista);

int inserirFinal(Lista* lista, struct elemento valor);
int removerFinal(Lista* lista, struct elemento* valor);

int tamanhoLista(Lista* lista);
int listaVazia(Lista* lista);

float somar(float a, float b);
float subtrair(float a, float b);
float multiplicar(float a, float b);
float dividir(float a, float b);
