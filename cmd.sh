yacc -d grammer.y
lex grammer.l
gcc y.tab.c -O3 -ll -lm
