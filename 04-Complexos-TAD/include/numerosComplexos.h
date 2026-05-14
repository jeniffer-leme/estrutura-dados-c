typedef struct numerosComplexos NumerosComplexos;

NumerosComplexos* criar(float x, float y);

void liberar(NumerosComplexos* p);

void soma(NumerosComplexos* p, NumerosComplexos* q);

void subtracao(NumerosComplexos* p, NumerosComplexos* q);

void multiplicacao(NumerosComplexos* p, NumerosComplexos* q);

void divisao(NumerosComplexos* p, NumerosComplexos* q);
