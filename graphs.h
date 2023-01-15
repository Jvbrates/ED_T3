//
// Created by jvbrates on 1/14/23.
//

#ifndef T3_ED_GRAPHS_H
#define T3_ED_GRAPHS_H
#include <stdbool.h>

typedef enum {
    DFS,
    BFS
}search;

typedef  struct {
    int label;
    bool flag;
    struct lista* arestas;
} vertice;


typedef struct lista{
    struct lista * next;
    vertice * info;
} l_vertice;


typedef struct g {
    l_vertice *vertices;
    l_vertice *last;

}grafo;

//TODO comentar
grafo *iniciaGrafo();
void addVerticeGrafo(grafo *G);
void addArestaGrafo(grafo *G, int from, int to);
void imprimir(grafo *g);
void BreadFirstSearch(vertice *v);
void flagToFalse(l_vertice *l);
void DeepFirstSeach(vertice *v);
void Search(grafo * G, int source, search mode);
#endif//T3_ED_GRAPHS_H
