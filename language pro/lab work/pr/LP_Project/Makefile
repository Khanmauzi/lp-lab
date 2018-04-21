compiler: compiler.y compiler.l
	bison -d  -v compiler.y 
	flex compiler.l
	g++ -o $@ compiler.tab.c lex.yy.c -lfl -std=c++11
