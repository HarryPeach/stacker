default:
	g++ -o main main.cpp draw_helper.cpp row.cpp -lncursesw

run: default
	./main

clean:
	rm main