//
// Created by jvbrates on 1/14/23.
//

#include "graphs.h"
#include <stdlib.h>
#include <stdio.h>
//Vertice
vertice *newVertice(){
        vertice *nV = malloc(sizeof (vertice));
        nV->arestas = NULL;
        nV->flag = false;

        return nV;
}


//Lista de vertices
l_vertice *addvertice(l_vertice* lV, vertice *to){
    //printf("\nFunção Addvertice\n");
    if(!lV){
        lV = malloc(sizeof(l_vertice));
        lV->next = NULL;
        if(to == NULL){
        lV->info = newVertice();
        lV->info->label = 0;
        } else {
            lV->info = to;
        }
        return lV;
    }

    lV->next = addvertice(lV->next, to);
    return lV;
}


//Grafo
grafo *iniciaGrafo(){
    grafo *nG = malloc(sizeof(grafo));
    nG->vertices = NULL;
    nG->vertices = NULL;
    return nG;
}


void addVerticeGrafo(grafo *G){
    if(!G->last || ! G->vertices){
        //printf("Chamando Addvertice %p\n", G->vertices->next);
        G->vertices = addvertice(G->vertices, NULL);
        G->last = G->vertices;
    } else {
        G->last = addvertice(G->last, NULL);
        G->last->next->info->label = G->last->info->label+1;
        G->last = G->last->next;
    }
}


//Retorna a n-ésima vertice numerada a partir de 0 na ordem inseridas
//Caso retorne null negativo, significa que não foi encontrado
vertice *getnvertice(l_vertice *l_V, int n){
    l_vertice *ret = l_V;

    for (;ret!=NULL && n != 0;  ret = ret->next ) {
        n--;
    }
    if(ret)
        return ret->info;
    return NULL;
}

void addArestaGrafo(grafo *G, int from, int to){
    vertice *fVertice = getnvertice(G->vertices, from);
    vertice *tVertice = getnvertice(G->vertices, to);
    if(fVertice && tVertice)
        fVertice->arestas = addvertice(fVertice->arestas,tVertice);
    else
        printf("Vertice(s) não encontrado\n");
}



void imprimir(grafo *g){

    for (l_vertice *i= g->vertices;  i!=NULL ; i=i->next) {
        printf("|%d : ",i->info->label);
        if(i->info->flag)
            printf("(true)");
        else
            printf("(false)");

        for (struct lista * j = i->info->arestas; j != NULL ; j=j->next) {
            printf("%d, ",j->info->label);
        }
        printf("\n");
    }
}


void flagToFalse(l_vertice *l){
    if(l){
        l->info->flag = false;
        flagToFalse(l->next);
    }
}

void addArestas(l_vertice *l){
    for (l_vertice *i = l->info->arestas; i != NULL ; i=i->next) {
        if(i->info->flag == false){
            i->info->flag = true;
            addvertice(l, i->info);

            printf("Pré ordem: %i \n", i->info->label);
        }
    }

    printf("Pós ordem: %i\n", l->info->label);
}


void BreadFirstSearch(vertice *v){

    l_vertice *l = NULL;
    l = addvertice(l, v);

    v->flag = true;

    printf("Pré ordem: %i \n", v->label);

    while (l){
        addArestas(l);
        l = l->next;
    }

}

void DeepFirstSeach(vertice *v){
    if(!v->flag) {
        v->flag = true;

        printf("Pré ordem: %i\n", v->label);

        for (struct lista *i = v->arestas; i != NULL; i = i->next) {
            DeepFirstSeach(i->info);
        }

        printf("Pós ordem: %i\n", v->label);
    }
}


void Search(grafo * G, int source, search mode){

     vertice  * v = getnvertice(G->vertices, source);

    if(!v) {
        printf("Vertice não encontrada");
    } else {
        if(mode == BFS){
            BreadFirstSearch(v);
        } else {
            DeepFirstSeach(v);
        }
    }
}