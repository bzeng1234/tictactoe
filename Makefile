SOURCES=player.cc tictactoe.cc tictactoe_main.cc
EXECUTABLE=tictactoe.out

all: $(EXECUTABLE)

$(EXECUTABLE):
	@echo EXE: Compiling and linking $(SOURCES) to create $@
	g++ $(SOURCES) -o $(EXECUTABLE)

clean:
	rm -rf $(EXECUTABLE)
