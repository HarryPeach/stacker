CC=g++
CFLAGS=-O2
CFLAGS_DEBUG=-Wall -Wextra -Og -g -pedantic
LINKLIBS=-lncursesw
OUTPUT=stacker

.PHONY: docs

default:
	$(CC) -o $(OUTPUT) $(CFLAGS) main.cpp draw_helper.cpp row.cpp $(LINKLIBS)

debug:
	$(CC) -o $(OUTPUT) $(CFLAGS_DEBUG) main.cpp draw_helper.cpp row.cpp $(LINKLIBS)

docs:
	doxygen doxygen.config

run: default
	./$(OUTPUT)

clean:
	-@rm $(OUTPUT) 2>/dev/null || true
	-@rm -rf docs/ 2>/dev/null || true