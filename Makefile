CC = gcc
CFLAGS = -O3 -std=c11 -Wall -Wextra

SRC = nofetch.c
EXEC = nofetch

PREFIX ?= /usr/local
BIN_DIR = $(PREFIX)/bin
COMPLETION_DIR = $(PREFIX)/share/bash-completion/completions

all: $(EXEC)

$(EXEC): $(SRC)
	$(CC) $(CFLAGS) -o $@ $<

install: $(EXEC)
	@echo "Installing $(EXEC) to $(DESTDIR)$(BIN_DIR)"
	install -Dm755 $(EXEC) $(DESTDIR)$(BIN_DIR)/$(EXEC)
	@echo "Installing bash completion script to $(DESTDIR)$(COMPLETION_DIR)"
	install -Dm644 nofetch_completion.sh $(DESTDIR)$(COMPLETION_DIR)/nofetch

uninstall:
	@echo "Removing $(DESTDIR)$(BIN_DIR)/$(EXEC)"
	rm -f $(DESTDIR)$(BIN_DIR)/$(EXEC)
	@echo "Removing $(DESTDIR)$(COMPLETION_DIR)/nofetch"
	rm -f $(DESTDIR)$(COMPLETION_DIR)/nofetch

clean:
	rm -f $(EXEC)

.PHONY: all clean install uninstall
