# 🚀 Minha Jornada no C (Low-Level Learning)

Repositório para registrar minha evolução na programação C, saindo do básico até o controle de hardware no Arch Linux.

### 📅 Dia 1: A Base e a Lógica de Baixo Nível
- **O que aprendi:** A diferença entre linguagens de alto nível (JS) e baixo nível (C).
- **Conceitos:** Compilação com `gcc`, função `main` e o uso de `printf`.
- **Hardware:** Entendi como o código interage com o processador.

### 📅 Dia 2: Memória e Entrada de Dados
- **O que aprendi:** Como o C reserva espaços na RAM (Variáveis).
- **Conceitos:** Tipagem estrita (`int`, `float`, `char`), uso de `scanf` para ler o teclado e o operador `&` (ponteiros básicos).
- **Lógica:** Implementação de condicionais `if/else` para validação de dados.

### 📅 Dia 3: O Kernel e o Sistema de Arquivos
- **O que aprendi:** No Linux, "tudo é um arquivo". Aprendi a ler dados direto do Kernel.
- **Conceitos:** Manipulação de arquivos com `FILE *`, `fopen`, `fgets` e `fclose`.
- **Filtros:** Uso da biblioteca `string.h` e a função `strstr` para filtrar informações específicas do `/proc/cpuinfo`.

### 📅 Dia 4: Aritmética de Ponteiros e Refatoração

- **O que aprendi:** Como transformar texto em dados matemáticos e navegar na memória física.
- **Conceitos:** Uso de `atof`, aritmética de ponteiros (ponteiro + 2) e organização de diretórios via terminal.
- **Projeto:** Criado o CPU-Monitor-Main, capaz de filtrar o Kernel e calcular o clock real do processador.

### 📅 Dia 5: Persistência de Dados e Fluxo de Arquivos

- **O que aprendi:** Como fazer o software "lembrar" das coisas após ser fechado.
- **Conceitos:** Manipulação de escrita com `fprintf`, modos de abertura de arquivo ("a" para append) e prevenção de bugs de escopo.
- **Projeto:** Calculador de Notas, um sistema que gera um banco de dados em .txt com histórico de alunos.

### 📅 Dia 6: Estruturas de Dados e Encapsulamento

- **O que aprendi:** Uso de `atoi`, organização de codigo e `struct` para deixar o codigo mais limpo.
- **Conceitos:** Criação de structs para organizar dados complexos, uso de strcpy (string copy) e atoi (ASCII to Integer).
- **Arquitetura:** Separação entre a lógica de leitura do `/proc` e a exibição final dos dados.

### 📅 Dia 7: TUI (Terminal User Interface) e ncurses

-  **O que aprendi:** Como sair do printf linear e criar interfaces visuais interativas no terminal.
-  **Conceitos:** Manipulação da biblioteca ncurses, captura de teclas em tempo real (getch), controle de janelas e o loop de renderização.
-  **Hardware vs. Software:** Implementação de navegação por setas (teclado) para selecionar módulos do sistema.
-  **Projeto:** Início do Sentinel Monitor, uma ferramenta de monitoramento em tempo real com interface gráfica de terminal (estilo htop).