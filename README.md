# 🚀 Minha Jornada no C (Low-Level Learning)

# (Estou fazendo isso com 12 anos)

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

### 📅 Dia 8: Máquina de Estados e Integração de Hardware

- **O que aprendi:** Como gerenciar múltiplos contextos de exibição (States) em um único loop de execução.
- **Conceitos:** Implementação de `enum` para controle de telas, leitura simultânea de múltiplos arquivos do Kernel (`/proc/cpuinfo` e `/proc/meminfo`).
- **Resolução de Bugs:** Filtragem avançada de strings para evitar falsos positivos (ex: ignorar SwapCached ao buscar o cache real).
- **Arquitetura:** Criação de um sistema de navegação bidirecional (Menu -> Detalhes -> Menu) mantendo a persistência dos dados.

### 📅 Dia 9: Estética TUI e Conversão de Tempo Real
- **O que aprendi:** Como implementar sistemas de cores dinâmicas com `ncurses`.
- **Conceitos:** Atributos de vídeo (`attron/attroff`), pares de cores e lógica de alertas (Feedback Visual).
- **Matemática de Sistema:** Conversão de segundos brutos do `/proc/uptime` para o formato HH:MM:SS usando operadores de divisão e resto (`%`).
- **Projeto:** Sentinel Monitor v1.1 - Agora com interface colorida e relógio de tempo de atividade.

### 📅 Dia 10: Motores de Física e Integração de Sistemas
- **O que aprendi:** Como simular leis da natureza (Gravidade e Inércia) manualmente.
- **Conceitos:** Implementação de vetores de velocidade, aceleração constante, detecção de colisão por detecção de sobreposição de retângulos (`CheckCollisionRecs`) e o conceito de "Delta Time" (`GetFrameTime`) para manter a física constante independente do FPS.
- **Integração:** Experimentei a chamada de comandos do sistema via `stdlib.h` (`system()`) para integrar subprojetos (Sistema de Inventário) em tempo real.
- **Projeto:** Mini Block Man v1.0 - Agora com gravidade funcional, pulo e persistência de inventário via arquivo `.txt`.

### 📅 Dia 11: A Barreira de Vidro e a Filosofia Open Source
- **O que aprendi:** A dura realidade da incompatibilidade de software proprietário (Roblox) em hardware legado no Linux. 
- **Conflito:** Testei Novetus, Studio Lite, Vinegar e RetroStudio. Conclusão: O "gargalo" da iGPU e o "Glue" da Microsoft tentaram barrar o progresso.
- **Decisão:** Recusa total ao Windows. O aprendizado agora foca 100% em C e ferramentas que respeitam o usuário. Se o Studio não roda, eu construo minha própria lógica no VS Code.
- 
