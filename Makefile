CC=g++
CFLAGS=
LINKLIBS=-lncursesw
OUTPUT=stacker

.PHONY: docs

default:
	$(CC) -o $(OUTPUT) $(CFLAGS) main.cpp draw_helper.cpp row.cpp $(LINKLIBS)

docs:
	doxygen doxygen.config

run: default
	./$(OUTPUT)

clean:
	-@rm $(OUTPUT) 2>/dev/null || true
	-@rm -rf docs/ 2>/dev/null || true