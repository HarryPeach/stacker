.PHONY: docs

default:
	g++ -o main main.cpp draw_helper.cpp row.cpp -lncursesw

docs:
	doxygen doxygen.config

run: default
	./main

clean:
	-@rm main 2>/dev/null || true
	-@rm -rf docs/ 2>/dev/null || true