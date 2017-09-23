Compiler = gcc
Sources = src/*
Src = src/*.c
SourceDir = src/
Output = test
OutputDir = bin/
IncludeDir = include/

all:
	$(Compiler) $(Src) -o $(OutputDir)$(Output) -lSDL2

clear:
	rm -rf $(OutputDir)*

gitaddsrc:
	git add $(Sources)

gitaddbin:
	git add $(OutputDir) 
