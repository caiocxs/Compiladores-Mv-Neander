# Neander

 O [Neander](https://www.inf.ufrgs.br/arq/wiki/doku.php?id=neander) é um processador hipotético criado com fins estritamente didáticos, projetado para introduzir os conceitos fundamentais de organização e arquitetura de computadores. Ele é a primeira e mais simples de uma série de arquiteturas (seguida por Ahmes, Ramses e César) apresentadas na obra "Fundamentos de Arquitetura de Computadores" do professor Raul Fernando Weber (UFRGS). 

Este projeto tem como objetivo simular o ciclo de busca e execução do processador Neander utilizando C. O programa interpreta as instruções contidas em arquivos binários gerados pelo montador, reproduzindo o comportamento lógico do hardware.

## Compilação

Para compilar o projeto, você pode usar o `gcc`. Certifique-se de incluir todos os arquivos fonte:

```bash
gcc main.c mv_neander.c -o neander -Wall
```

## Como usar

O simulador recebe como argumento obrigatório o caminho para o arquivo binário (imagem da memória). Opcionalmente, pode-se definir o valor inicial do *Program Counter* (PC).

**Sintaxe:**
```bash
./neander <arquivo_binario> [pc_inicial]
```
## Comandos

O simulador suporta as seguintes instruções do set original do Neander:

```markdown
## Instruções Implementadas
- [ ] NOP (00h)
- [ ] STA (10h) - Armazenamento
- [ ] LDA (20h) - Carregamento
- [ ] ADD (30h) - Soma
- [ ] OR (40h) - Lógica OU
- [ ] AND (50h) - Lógica E
- [ ] NOT (60h) - Negação
- [ ] JMP (80h) - Desvio Incondicional
- [ ] JN (90h) - Desvio se Negativo (Em desenvolvimento)
- [ ] JZ (A0h) - Desvio se Zero (Em desenvolvimento)
```
