struct retangulo {
    float base;
    float altura;
};

struct triangulo {
    float base;
    float altura;
};

struct circulo {
    float raio;
};

typedef struct tipoLista Lista;

typedef enum {
    RETANGULO,
    TRIANGULO,
    CIRCULO
} tipoFormas;

struct elementos {
    int id;
    tipoFormas formas;

    union {
        struct retangulo ret;
        struct triangulo tri;
        struct circulo circ;
    } figura;
};

Lista* criarLista();
void apagarLista(Lista* lista);

int inserirForma(Lista* lista, struct elementos forma);
int removerForma(Lista* lista, int id);

float calcularArea(Lista* lista, struct elementos* forma);
void imprimir(Lista* lista);
