# Nome do executável
EXECUTABLE = cminus

# Arquivos fonte
FLEX_FILE  = flex.l
BISON_FILE = parser.y

# Estes são gerados pelo Bison e Flex
BISON_C = parser.tab.c
BISON_H = parser.tab.h
LEX_C   = lex.yy.c

# Demais arquivos .c do seu projeto
C_SOURCES = analyze.c globals.c main.c symtab.c $(BISON_C) $(LEX_C)

# Arquivos objeto
OBJECTS = $(C_SOURCES:.c=.o)

# Alvo padrão
all: $(EXECUTABLE)

# Geração do executável
$(EXECUTABLE): $(OBJECTS)
	gcc -o $(EXECUTABLE) $(OBJECTS) -lfl

# Regra geral para compilar qualquer .c em .o
%.o: %.c $(BISON_H)
	gcc -c $< -o $@

# Geração do código C e do header a partir do arquivo Bison
$(BISON_C) $(BISON_H): $(BISON_FILE)
	bison -d $(BISON_FILE)

# Geração do código C a partir do arquivo Flex
$(LEX_C): $(FLEX_FILE) $(BISON_H)
	flex $(FLEX_FILE)

# Execução do programa
run: $(EXECUTABLE)
	./$(EXECUTABLE) in.txt

# Limpeza
clean:
	rm -f $(OBJECTS) $(EXECUTABLE) $(LEX_C) $(BISON_C) $(BISON_H)
