# Variáveis de Compilação
CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS = -lncurses

# Nomes dos Executáveis
EXE_INTERFACE = interface
EXE_NEANDER = mv_neander

# --- Alvos Principais ---

# Compila ambos se você digitar apenas 'make'
all: $(EXE_INTERFACE) $(EXE_NEANDER)

# Compila apenas a interface
# O ncurses precisa da flag -lncurses para linkar a biblioteca
$(EXE_INTERFACE): interface.c
	$(CC) $(CFLAGS) interface.c -o $(EXE_INTERFACE) $(LDFLAGS)

# Compila apenas o mv_neander
# Ele depende do .c e do .h; se o .h mudar, ele recompila
$(EXE_NEANDER): mv_neander.c mv_neander.h
	$(CC) $(CFLAGS) mv_neander.c -o $(EXE_NEANDER)

# --- Utilitários ---

# Limpa os arquivos executáveis
clean:
	rm -f $(EXE_INTERFACE) $(EXE_NEANDER)

# Atalhos para facilitar a escolha no terminal
interface: $(EXE_INTERFACE)
neander: $(EXE_NEANDER)