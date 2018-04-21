compile: compile.y compile.l
	bison -d  -v compile.y 
	flex compile.l
	g++ -o $@ compile.tab.c lex.yy.c -lfl -std=c++11
