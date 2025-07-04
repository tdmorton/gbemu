#output: main.o chip8.o
#	g++ main.o chip8.o -o output

#main.o: main.cpp
#	g++ -c main.cpp

#chip8.o: chip8.cpp
#	g++ -c chip8.cpp


#OBJS specifies which files to compile as part of the project
OBJS = main.c cpu.c mmu.c cartridge.c ppu.c

#CC specifies which compiler we're using
CC = gcc

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -w -g

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lSDL2 -lSDL2_image

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = gbemu

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
	

	
clean: 
	rm gbemu