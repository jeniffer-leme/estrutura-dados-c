# ⚖️ TAD Números Racionais

## 📱 Descrição
Este projeto consiste na implementação de um **Tipo Abstrato de Dados (TAD)** em C para representar e manipular números racionais (frações). O foco principal é demonstrar a aplicação de **alocação dinâmica** e a **modularização de código**, separando a lógica matemática da interface de usuário.

O programa permite que o usuário interaja com frações de forma intuitiva, realizando cálculos automáticos e verificações de igualdade lógica.

---

## 🧩 Funcionalidades
- **Criação Dinâmica**: Alocação de memória para os números racionais utilizando `calloc`.
- **Soma de Racionais**: Cálculo da soma utilizando o mínimo múltiplo comum (MMC) implícito pela fórmula $(a \cdot d + b \cdot c) / (b \cdot d)$.
- **Multiplicação**: Implementação direta do produto de numeradores e denominadores.
- **Teste de Igualdade**: Verificação lógica que identifica se duas frações são equivalentes.
- **Gestão de Memória**: Função de liberação de ponteiros para evitar *memory leaks*.

---

## 🛠️ Tecnologias e Conceitos
- **Linguagem:** C
- **Gestão de Memória:** Alocação dinâmica no *Heap* e manipulação via ponteiros.
- **Encapsulamento:** Definição da `struct` no arquivo de implementação (`.c`), expondo apenas a interface no cabeçalho (`.h`).
- **Interface:** CLI (Command Line Interface).

---

## 📂 Estrutura do Projeto
```text
/
├── include/
│   └── racional.h      # Protótipos das funções e definição do tipo
├── src/
│   ├── racional.c      # Implementação da lógica do TAD
│   └── main.c          # Menu interativo e fluxo do programa
└── README.md
```

---

## 📐 Operações Lógicas
O projeto resolve operações fundamentais de frações:

- **Soma:** Exibe o resultado tanto em formato decimal (float) quanto em formato de fração.
- **Igualdade:** Compara se o Racional 1 é matematicamente idêntico ao Racional 2.

---

##🚀 Como executar os projetos
Cada subpasta contém seu próprio código-fonte. Para compilar e rodar, siga os passos abaixo:

**1. Clone o repositório**

**2. Compile os arquivos fonte:**
```bash
gcc src/*.c -I include -o racionais
```

**3. Execute o programa:**
```bash
./racionais
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
