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
	| expr '==' expr        # eq
	| expr '>' expr 	# gt
	| expr '<' expr 	# lt
	| expr '!=' expr 	# neq
	| expr '>=' expr 	# gte
	| expr '<=' expr 	# lte
	;

declvar: type  ID optinit (',' ID optinit )* ';'  
	;

optinit : '=' INT   #init
	|           #initvide       
	;

defvar : ID '=' expr ';'
	;

execfunc : ID '(' param ')' ;

block : '{' declvar* statement* '}';

statement : ret			#return	
	| defvar		#defvariable
	| execfunc ';'		#exfuncStatement
	| expr ';'		#exprStatement
	| insif			#ifStatement
	;

insif: 'if' '(' expr ')' block inselse? ;

inselse: 'else' block ;

ret : 'return' expr ';';


param :  expr (',' expr)*	#paramFonction
	|			#paramVide
	;			

type: 'int' 		#typeint
	| 'char'	#typechar
	| 'void'	#typevoid
	;

INT : [0-9]+ ;
ID : [a-zA-Z][a-zA-Z0-9]*;
WS : [\t\r\n ] -> skip;
