CC = gcc
CFLAGS = -Wall -g $(shell pkg-config --cflags gtk+-3.0)
LDFLAGS = $(shell pkg-config --libs gtk+-3.0)

# Seznam zdrojových souborů
SRC = $(wildcard *.c)
# Exclude profiling.c from the main application build
MAIN_SRC = $(filter-out profiling.c, $(SRC))
# Vytvoření seznamu objektových souborů ze zdrojových souborů
OBJ = $(MAIN_SRC:.c=.o)
# Jméno výsledného spustitelného souboru
EXEC = calculator

# Výchozí cíl
all: $(EXEC) doc

# Linkování objektových souborů do spustitelného souboru
$(EXEC): $(OBJ)
	$(CC) $(LDFLAGS) $^ -o $@

# Kompilace zdrojových souborů do objektových souborů
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Spustitelný soubor pro profiling
profile:
	$(CC) $(CFLAGS) -o stddev profiling.c $(LDFLAGS)

# Generování dokumentace pomocí Doxygen
doc:
	doxygen Doxyfile

# Čištění projektu (odstranění objektových souborů, spustitelných souborů a dočasných souborů)
clean:
	rm -f $(OBJ) $(EXEC) stddev
	rm -rf doc/html doc/latex  # Odstranění složek s dokumentací, pokud existují

# Spouštění testů (předpokládá existenci skriptu pro testy)
test:
	./run_tests.sh

# Balení projektu do archivu tar.gz
pack:
	tar -czvf project.tar.gz *

# Spouštění hlavního programu
run: $(EXEC)
	./$(EXEC)

# Příklad vstupu pro profiling program
profile_run:
	./stddev < data.txt

.PHONY: all clean test doc pack run profile profile_run
