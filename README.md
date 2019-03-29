# compilo

Code de notre projet de création d'un compilateur de C à partir de l'outil ANTLR4.

## Manuel d'installation
Pour Linux / Unix

1. Installer [ANTLR](https://www.antlr.org/download.html)
2. Installer les [runtimes pour fonctionnement avec le langage C++](https://www.antlr.org/download/antlr4-cpp-runtime-4.7.2-source.zip)
3. Cloner ce répertoire
4. Modifier le makefile : modifier ANTLRRUNTIMEDIR et ANTLR et COMP pour correspondre respectivement au répertoire des runtimes, à la commande de lancement de antlr, et au compilateur C++  de votre machine
5. `make`
6. `./exe` suivi du nom du fichier `.c` que vous souhaitez compiler. Le code assembleur sera obtenu dans le fichier `asm.s`
