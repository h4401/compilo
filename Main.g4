grammar Main;

prog: (func)*;

func : deffunc | declfunc;

	
expr: expr ('*'|'/') expr # multdiv
	| expr ('+'|'-') expr # addsub
	| INT			# const
	| VAR			# var
	| '(' expr ')'  	# par
	| execfunc		# exfunc
	;

declvar: TYPE VAR (',' VAR)* ';'
	;

defvar : TYPE VAR '=' expr ';'
	| VAR '=' expr ';'
	;

deffunc : TYPE VAR '(' declparam? ')' block 
	;

declfunc : TYPE VAR '(' declparam? ')' ';';  

execfunc : VAR '(' param? ')';

block : '{' statement* '}';

statement : ret
	| defvar
	| expr
	| declvar
	;

ret : 'return' expr ';';

declparam : TYPE VAR (',' TYPE VAR)*;

param :  expr (',' expr)*;

TYPE: 'int'
	| 'char'
	| 'void'
	;

INT : [0-9]+ ;
VAR : [a-zA-Z][a-zA-Z0-9]*;
WS : [\t\r\n ] -> skip;


