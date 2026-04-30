# 🏗️ Estruturas de Dados em C (TADs)

## 📱 Descrição
Este repositório centraliza meus estudos e implementações de **Tipos Abstratos de Dados (TADs)** e **Estruturas de Dados Dinâmicas** utilizando a linguagem C. O objetivo principal é consolidar conceitos fundamentais de baixo nível antes de avançar para estruturas mais complexas como Listas Encadeadas, Pilhas e Árvores.

Os projetos focam em:
- 🛠️ **Modularização**: Separação rigorosa entre interface (`.h`) e implementação (`.c`).
- 🧠 **Gestão de Memória**: Uso estratégico de `malloc`/`calloc` para alocação dinâmica e `free` para prevenção de *memory leaks*.
- 🔢 **Lógica Matemática**: Implementação de operações complexas (Racionais e Números Complexos).
- 🛡️ **Robustez**: Tratamento de erros, como verificações de ponteiros nulos e divisões por zero.

---

## 📂 Organização do Repositório

O repositório é organizado por níveis de complexidade, seguindo uma trilha de aprendizado estruturada:

| Pasta | Descrição | Conceitos Chave |
| :--- | :--- | :--- |
| `01-Ponteiro` | Atividades de introdução e manipulação de endereços. | Armazenamento e acesso a endereços de memória. |
| `02-Alocacao-Dinamica` | Exercícios de reserva e liberação de memória em tempo de execução. | Uso de `malloc`/`calloc` e gerenciamento de memória no sistema. |
| `03-Racionais-TAD` | Projeto de manipulação de frações e simplificação. | Estruturas básicas (TAD) e aritmética. |
| `04-Complexos-TAD` | Calculadora de números complexos com menu interativo. | Ponteiros aplicados a structs, `math.h` e distributiva. |
| `05-Listas-Encadeadas` | (Em breve) Implementação de nós dinâmicos e cadeias de dados. | Encadeamento e ponteiros de ponteiros. |

---

## 🛠️ Tecnologias e Ferramentas
- **Linguagem:** C (Padrão C11/C17)
- **Compilador:** GCC (GNU Compiler Collection)
- **Interface:** CLI (Interface de Linha de Comando)
- **Ambiente:** VS Code / Terminal Linux

---

## 🧩 Funcionalidades Destacadas (TAD Complexos)
- **Criação Dinâmica:** Alocação de memória em tempo de execução para os números complexos[cite: 1].
- **Operações Aritméticas:**
  - Soma e Subtração de partes reais e imaginárias.
  - Multiplicação via distributiva considerando $i^2 = -1$.
  - Divisão complexa utilizando a técnica do conjugado.
- **Menu Interativo:** Fluxo de usuário com proteção contra operações em dados não inicializados.
- **Limpeza de Memória:** Função dedicada para desalocar todos os ponteiros ao encerrar o programa[cite: 1].

---

## 🎥 Demonstração (Terminal)
```bash
========= MENU =========
1. Definir Números Complexos
2. Soma
3. Subtração
4. Multiplicação
5. Divisão
0. Sair

Digite a opção desejada: 2

--------- SOMA ---------
NC1: 2.00 + i3.00
NC2: 1.00 + i2.00
Soma: 3.00 + i5.00
```

---

##🚀 Como executar os projetos
Cada subpasta contém seu próprio código-fonte. Para compilar e rodar, siga os passos abaixo:

**1. Clone o repositório:**
```bash
git clone https://github.com/jeniffer-leme/estrutura-dados-c
```

**2. Acesse a pasta do projeto desejado:**
```bash
cd 04-Complexos-TAD
```

**3. Compile utilizando o GCC:**
```bash
gcc src/*.c -I include -o programa
```

**4. Execute o programa:**
```bash
./programa
```

---

## 🧬 Estrutura de um TAD (Conceito)
Diferente de objetos em linguagens de alto nível, o TAD em C utiliza ponteiros para esconder a implementação da `struct`, garantindo que o usuário do TAD acesse os dados apenas através das funções autorizadas no arquivo de cabeçalho.

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
