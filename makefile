CC = g++
EXE = "MathFunctions"
CFLAGS = -lm
DEPS =
OBJ := $(patsubst %.cpp,%.o,$(wildcard *.cpp))

$(EXE) : $(OBJ)
	$(CC) -o $(EXE) $(OBJ) $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(OBJ) $(EXE)