default:
	g++ -o main main.cpp draw_helper.cpp -lncursesw

run: default
	./main

clean:
	rm main