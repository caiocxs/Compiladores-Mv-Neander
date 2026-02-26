# Variáveis de Compilação
CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS = -lncurses

# Nomes dos Executáveis
EXE_INTERFACE = interface
EXE_NEANDER = mv_neander

# Caminhos dos arquivos fonte
SRC_INTERFACE = interface/ui.c
SRC_NEANDER = neander/mv.c
HDR_NEANDER = neander/mv.h

# --- Alvos Principais ---

# Compila ambos se você digitar apenas 'make'
all: $(EXE_INTERFACE) $(EXE_NEANDER)

# Compila apenas a interface
$(EXE_INTERFACE): $(SRC_INTERFACE)
	$(CC) $(CFLAGS) $(SRC_INTERFACE) -o $(EXE_INTERFACE) $(LDFLAGS)

# O alvo agora depende de neander/mv.c e neander/mv.h
$(EXE_NEANDER): $(SRC_NEANDER) $(HDR_NEANDER)
	$(CC) $(CFLAGS) $(SRC_NEANDER) -o $(EXE_NEANDER)

# --- Utilitários ---

# Limpa os arquivos executáveis
clean:
	rm -f $(EXE_INTERFACE) $(EXE_NEANDER)

# Atalhos para facilitar a escolha no terminal
interface: $(EXE_INTERFACE)
neander: $(EXE_NEANDER)