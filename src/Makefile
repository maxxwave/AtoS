export LANG=C
export LC_ALL=C
#CXX=mpic++
CXX=gcc
LIBS=-lm -lfftw3
CXXFLAGS = -c -O0 -Ihdr/ #
LINKFLAGS =  #-pg
LIBDIR=
LDFLAGS =   #-L$(LIBDIR)
EXE=ASMS
#langevin dynamics
SRC= main.cpp  create.cpp mat.cpp  storage.cpp fields.cpp integrators/LLG.cpp programs/hysteresis.cpp programs/magnetization.cpp 
OBJ=$(SRC:%.cpp=lib/%.o)

all: $(SRC) $(EXE)

clean: rm -f $(EXE) $(OBJ) rm -f lib/*

$(EXE): $(OBJ)
	$(CXX) $(GITINFO) $(LDFLAGS) $(OBJ) $(LIBS) -o $@

lib/%.o: %.cpp
	$(CXX) $(GITINFO) $(CXXFLAGS) $(LIBS) -c $< -o $@
