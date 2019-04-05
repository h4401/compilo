grammar Grammar;

prog: (func)*;

func : type ID '(' (type ID (',' type ID)*)? ')' block;

	
expr: expr '*' expr 		# mult
	| expr '/' expr  	# div
	| expr '+' expr 	# plus
	| expr '-' expr		# minus
	| INT			# const
	| ID			# var
	| '(' expr ')'  	# par
	| execfunc		# exfunc
	;

declvar: type  ID optinit (',' ID optinit )* ';'  
	;

optinit : '=' INT   #init
	|           #initvide       
	;

defvar : ID '=' expr ';'
	;

execfunc : ID '(' param? ')';

block : '{' declvar* statement* '}';

statement : ret			#return	
	| defvar		#defvariable
	;

forblock : 'for' '(' defvar test ';' ID '=' expr ')' block
	;

whileblock : 'while' '(' tests ')' block	#whiletestbefore
	| 'do '	block 'while' '(' tests ')' ';'	#whiletestafter
	;

ifblock : 'if' '(' tests ')' block ('else' block)?;

ret : 'return' expr ';';

tests : test (andor test)*;
test : expr comparator expr;

andor :   '||'			#or
	| '&&'			#and
	;
	
comparator: '=='		#equal
	| '!='			#nonequal
	| '>'			#strictlygreaterthan
	| '<'			#strictlylesserthan
	| '>='			#greaterthan
	| '<='			#lesserthan
	;
param :  expr (',' expr)*;

type: 'int' 		#typeint
	| 'char'	#typechar
	| 'void'	#typevoid
	;

INT : [0-9]+ ;
ID : [a-zA-Z][a-zA-Z0-9]*;
WS : [\t\r\n ] -> skip;


