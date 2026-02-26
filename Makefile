# Variáveis de Compilação
CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS = -lncurses

# Nomes dos Executáveis
EXE_INTERFACE = ui
EXE_NEANDER = mv_neander

# Caminhos dos arquivos fonte
SRC_INTERFACE = interface/ui.c interface/window.c interface/position.c
HDR_INTERFACE = interface/ui.h interface/window.h interface/position.h
SRC_NEANDER = neander/mv.c
HDR_NEANDER = neander/mv.h

# --- Alvos Principais ---

#Declarar os alvos que NÃO são arquivos físicos (.PHONY)
.PHONY: all clean interface neander

# Compila ambos se você digitar apenas 'make'
all: $(EXE_INTERFACE) $(EXE_NEANDER)

# Compila apenas a interface
$(EXE_INTERFACE): $(SRC_INTERFACE) $(HDR_INTERFACE)
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