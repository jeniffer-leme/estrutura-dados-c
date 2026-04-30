typedef struct racionais Racionais;

Racionais* criarRacionais(int n, int d);

void liberar(Racionais* p);

void soma(Racionais* p, Racionais* q);

void multiplicacao(Racionais* p, Racionais* q);

void testeIgualdade(Racionais*p, Racionais* q);
