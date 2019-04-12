# compilo

Code de notre projet de création d'un compilateur de C.

## Usage
``` bash
$ ./comp source.c
```

## Manuel d'installation
Pour Linux / Unix

1. Installer [ANTLR](https://www.antlr.org/download.html)
2. Installer les [runtimes pour fonctionnement avec le langage C++](https://www.antlr.org/download/antlr4-cpp-runtime-4.7.2-source.zip)
3. Cloner ce répertoire
4. Modifier le makefile : modifier ANTLRRUNTIMEDIR et ANTLR et COMP pour correspondre respectivement au répertoire des runtimes, à la commande de lancement de antlr, et au compilateur C++  de votre machine
5. `make`
6. `./comp` suivi du nom du fichier `.c` que vous souhaitez compiler. Le code assembleur sera obtenu dans le fichier `asm.s`

### Tests
Tous les tests sont dans le dossier `tests`

Pour exécuter les tests:

1. S'assurer que les fichiers `doTest.sh` et `allTests.sh` ont les permissions d'exécution
2. Pour faire tout les tests présents dans le dossier `tests`, exécuter la commande :
``` bash
$ ./allTests.sh
````

3. Pour faire un test sur un fichier source en particulier, exécuter la commande :
``` bash
$ ./doTest.sh DIR_TO_TEST/source.c
````

## Fonctionnalités

#### Fonctionnel
- Programme avec plusieurs déclarations (à tout endroit du code) et plusieurs fonctions

- Types de variables : `int`
- Fonction à moins de 6 paramètres.
- Instructions : 
    - déclarations, affectations, initialisations, expression
    - appel fonction, retour fonction
    - `if-else` et `if-else` imbriqués.
- Opérations.
    - binaires : '+', '-', '*'
    - de comparaison : '==', '!=', '<=', '>=', '<', '>'
- Expressions pouvant être :
    - (expr), constante, variable, appelfonction, operation binaire, operation de comparaison. 

#### Non implémenté
- `Include`
- `Putchar()` ou `Getchar()`
- Types de variables : `int32_t`, `int64_t` et `char`
- Variables globales
- Opérateurs unaires
- `for`, `while`, `do while`
- Tableaux
- Optimisations
