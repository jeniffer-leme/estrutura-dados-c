# 🔢 Calculadora de Números Complexos (TAD)

## 📱 Descrição
Este projeto consiste em um **Tipo Abstrato de Dados (TAD)** desenvolvido em C para manipulação de números complexos. Ele permite realizar operações matemáticas fundamentais entre dois números na forma algébrica ($a + bi$), garantindo a integridade dos dados através do encapsulamento e da alocação dinâmica de memória.

O programa utiliza um **menu interativo** no terminal para que o usuário possa:
- 🆕 **Criar** dois números complexos (definindo parte real e imaginária);
- ➕ Realizar a **Soma**;
- ➖ Realizar a **Subtração**;
- ✖️ Realizar a **Multiplicação** (aplicando a propriedade distributiva e $i^2 = -1$);
- ➗ Realizar a **Divisão** (utilizando a técnica do conjugado);
- 🧹 **Liberar** a memória alocada dinamicamente ao encerrar.

---

## 🛠️ Tecnologias e Conceitos Utilizados
- **Linguagem:** C.
- **Modularização:** Divisão do código em `numerosComplexo.h` (interface), `numerosComplexos.c` (implementação) e `main.c` (testes/fluxo do usuário).
- **Ponteiros e Memória:** Uso de `calloc` para criação das estruturas e `free` para destruição.
- **Proteção de Dados:** Verificação de inicialização (não permite calcular sem antes criar os números).

---

## 📐 Operações Matemáticas Implementadas

Abaixo, as fórmulas que o sistema processa automaticamente:

1. **Soma:** $(a + bi) + (c + di) = (a+c) + (b+d)i$
2. **Subtração:** $(a + bi) - (c + di) = (a-c) + (b-d)i$
3. **Multiplicação:** $(a + bi) \cdot (c + di) = (ac - bd) + (ad + bc)i$
4. **Divisão:** Utiliza a multiplicação pelo conjugado do denominador para eliminar a parte imaginária da base.

---

## 📂 Estrutura de Arquivos
```text
/
├── include/
│   └── numerosComplexo.h  # Definição da struct e protótipos
├── src/
│   ├── numerosComplexos.c # Lógica das funções matemáticas
│   └── main.c             # Interface com o usuário (Menu)
└── README.md
```

---

##🚀 Como executar os projetos

**1. Clone o repositório**
**2. No terminal, compile todos os arquivos .c:**
```bash
gcc src/*.c -I include -o calculadora
```

**3. Execute o programa:**
```bash
./calculadora
```

--- 

## 📩 Contato
<p align="left">
  <a href="https://github.com/jeniffer-leme">
    <img src="https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white" alt="GitHub" />
  </a>
  <a href="https://www.linkedin.com/in/jeniffer-leme/">
    <img src="https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white" alt="LinkedIn" />
  </a>
</p>

- **📧 Email:** [jenifferl.dossantos@gmail.com](mailto:jenifferl.dossantos@gmail.com)
- **📞 Telefone/WhatsApp:** +55 (16) 99614-3331
