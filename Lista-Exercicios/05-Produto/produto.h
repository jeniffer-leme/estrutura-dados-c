struct elemento {
    int codigo;
    char nome[40];
    float preco;
    int quantidade;
    int data;
};

typedef struct tipoLista Lista;

Lista* criarLista();
void apagaLista(Lista* lista);

int cadastrarProduto(Lista* lista, struct elemento produto);
int apagarProduto(Lista* lista, int codigo);
int atualizarCadastro(Lista* lista, int codigo, struct elemento produto);


int buscarMenorPreco(Lista* lista, struct elemento* produto);
int buscarEstoqueInferior(Lista* lista, struct elemento* produto, float valor);

int gerarRelatorioCres(Lista* lista);
int gerarRelatorioDesc(Lista* lista);
