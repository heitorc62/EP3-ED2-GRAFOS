#ifndef GRAFO_H
#define GRAFO_H
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <queue>


using namespace std;

template <class Item>
class Grafo{
    public:
    Grafo(){};
    void addPar(Item v1, Item v2);
    map<Item, vector<Item>> adjacencias;
    void bfs(Item src, Item dst);
    int V; //O número total de vértices
};
/* 
Receberemos duplas: u_1 v_1. Isso quer dizer que há uma aresta unindo os
vértices u_1 e v_1. Deveremos colocar u_1 e v_1 como chaves do dicionário, 
adicionar u_1 ao vector de adjacências de v_1 e adicionar v_1 ao vector de 
adjacências de u_1.
*/

template <class Item>
void Grafo<Item>::addPar(Item v1, Item v2){
    adjacencias = map<Item, vector<Item>>();
    adjacencias[v1].push_back(v2);
    adjacencias[v2].push_back(v1);
}

template <class Item>
void Grafo<Item>::bfs(Item src, Item dst){
    bool * marked = new bool[V];
    map<Item, Item> pred;
    queue<Item> fila;
}





#endif