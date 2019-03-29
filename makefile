RM = rm
RMFLAGS = -f
ECHO = @echo
COMP = @g++
OBJ = $(REAL:.cpp=.o)
EXE = comp
CLEAN = clean
ANTLR = java -Xmx500M -cp "/usr/local/lib/antlr-4.7.2-complete.jar:$CLASSPATH" org.antlr.v4.Tool
ANTLRRUNTIME=/home/hbinani/Desktop/compilo/antlr
SRCDIR=src

.PHONY : ($CLEAN)

default:
	$(ANTLR) -visitor -no-listener -Dlanguage=Cpp  Grammar.g4 -o ./src
	$(COMP) -DTRACE -g -std=c++11 -I $(ANTLRRUNTIME)/antlr4-runtime/ $(SRCDIR)/*.cpp main.cpp -o $(EXE) $(ANTLRRUNTIME)/lib/libantlr4-runtime.a
	
$(CLEAN):
	$(ECHO) -n "Suppression des fichiers: $(EXE) $(OBJ) -> "
	$(RM) $(RMFLAGS) $(EXE) $(OBJ)
	$(RM) $(RMFLAGS) $(SRCDIR)/Grammar*.o $(SRCDIR)/Grammar*.h $(SRCDIR)/Grammar*.cpp $(SRCDIR)/Grammar*.tokens $(SRCDIR)/Grammar*.interp $(SRCDIR)/Grammar*.class $(SRCDIR)/Grammar*.java $(SRCDIR)/*.log
	$(ECHO) "OK"
