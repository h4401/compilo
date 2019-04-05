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

ret : 'return' expr ';';


param :  expr (',' expr)*;

type: 'int' 		#typeint
	| 'char'	#typechar
	| 'void'	#typevoid
	;

INT : [0-9]+ ;
ID : [a-zA-Z][a-zA-Z0-9]*;
WS : [\t\r\n ] -> skip;
