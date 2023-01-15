#include <stdio.h>
#include "graphs.h"

void usuario(grafo *g){
    bool flag = true;

    while (flag) {
        printf("Adicionar Vertice - 0\n"
               "Adicionar Aresta - 1\n"
               "BFS - 2\n"
               "DFS - 3\n"
               "Imprimir lista de adjacência - 4\n"
               "Exit - 5\n");


        int op = -1, x, y;

        scanf("%i", &op);

        switch (op) {
            case 0: {
                addVerticeGrafo(g);
                break;
            }
            case 1: {
                printf("De: ");
                scanf("%i", &x);
                printf("Para: ");
                scanf("%i", &y);

                addArestaGrafo(g, x, y);

                break;
            }
            case 2: {
                flagToFalse(g->vertices);
                printf("\n\n______________________\n"
                       "BREADTH FIRST SEARCH\n\n");
                Search(g, 0, BFS);
                break ;
            }
            case 3: {
                flagToFalse(g->vertices);// Setando flags para falso
                printf("\n\n______________________"
                       "\nDEEP FIRST SEARCH\n\n");
                Search(g, 0, DFS);
                break ;
            }
            case 4: {
                imprimir(g);
                break ;
            }
            case 5: {
                flag = false;
                break ;
            }
            default: {
                printf("Opção desconhecida\n");
                break ;
            }
        }
    }
}


int main() {

    printf("Hello, World!\n");

    grafo * g = iniciaGrafo();//Criando Grafo

    //Adicionando Vertices
    addVerticeGrafo(g);
    addVerticeGrafo(g);
    addVerticeGrafo(g);
    addVerticeGrafo(g);
    addVerticeGrafo(g);
    addVerticeGrafo(g);
    addVerticeGrafo(g);
    addVerticeGrafo(g);
    addVerticeGrafo(g);
    addVerticeGrafo(g);
    addVerticeGrafo(g);

    //Setando arestas
    addArestaGrafo(g, 0, 1);
    addArestaGrafo(g, 0, 2);
    addArestaGrafo(g, 0, 3);
    addArestaGrafo(g, 1, 4);
    addArestaGrafo(g, 1, 5);
    addArestaGrafo(g, 4, 8);
    addArestaGrafo(g, 2, 6);
    addArestaGrafo(g, 2, 7);
    addArestaGrafo(g, 8, 7);
    addArestaGrafo(g, 7, 5);
    addArestaGrafo(g, 7, 10);
    addArestaGrafo(g, 3, 9);

    //Imprimindo Grafos como Lista de Adjacência
    imprimir(g);


    printf("\n\n______________________\n"
           "BREADTH FIRST SEARCH\n\n");
    Search(g, 0, BFS);

    flagToFalse(g->vertices);// Setando flags para falso

    printf("\n\n______________________"
           "\nDEEP FIRST SEARCH\n\n");


    Search(g, 0, DFS);

    imprimir(g);

    //Parte chata
    usuario(g);

    return 0;
}
