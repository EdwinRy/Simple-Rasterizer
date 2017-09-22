Compiler = gcc
Sources = src/*
Src = src/*.c
SourceDir = src/
Output = test
OutputDir = bin/
IncludeDir = include/

all:
	$(Compiler) $(Src) -o $(OutputDir)$(Output)	

clear:
	rm -rf $(OutputDir)

gitadd:
	git add $(Sources)
