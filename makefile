LIBS=-lm -lfftw3
all: ASMS
CXX=g++
EXE= ASMS
ASMS: main.o create.o magnetization.o fields.o mat.o storage.o template.o times.o LLG.o  hysteresis.o time-series.o 

	g++ main.o create.o magnetization.o fields.o mat.o storage.o template.o times.o LLG.o  hysteresis.o time-series.o -o ASMS_run
main.o: src/main.cpp

	g++ -c src/main.cpp

create.o: src/create.cpp

	g++ -c src/create.cpp

fields.o: src/fields.cpp

	g++ -c src/fields.cpp

mat.o: src/mat.cpp

	g++ -c src/mat.cpp

storage.o: src/storage.cpp
	 
	 g++ -c src/storage.cpp

template.o: src/template.cpp

	g++ -c src/template.cpp

times.o: src/times.cpp

	g++ -c src/times.cpp

hysteresis.o: src/programs/hysteresis.cpp

	g++ -c src/programs/hysteresis.cpp

LLG.o: src/integrators/LLG.cpp

	g++ -c src/integrators/LLG.cpp

magnetization.o: src/programs/magnetization.cpp

	g++ -c src/programs/magnetization.cpp

time-series.o: src/programs/time-series.cpp
	g++ -c src/programs/time-series.cpp
clean:
	rm ./*.o ASMS


