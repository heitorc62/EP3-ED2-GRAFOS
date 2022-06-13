#ifndef GRAFO_H
#define GRAFO_H
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <queue>

using namespace std;

template <class Item>
class Grafo
{
public:
    Grafo(){};
    void addPar(Item v1, Item v2);
    map<Item, vector<Item>> adjacencias;
    map<Item, int> bfs(Item src);
    void distancias(Item src);
    int V; // O número total de vértices
};
/*
Receberemos duplas: u_1 v_1. Isso quer dizer que há uma aresta unindo os
vértices u_1 e v_1. Deveremos colocar u_1 e v_1 como chaves do dicionário,
adicionar u_1 ao vector de adjacências de v_1 e adicionar v_1 ao vector de
adjacências de u_1.
*/
template<class Item>
void Grafo<Item>::distancias(Item src){
    map<Item, int> dist = bfs(src);
    for(auto const& atual : dist){
        if(atual.second == INT_MAX) cout << "O vértice " << src << " e o vértice " << atual.first << " não estão conectados." << endl;
        else if(atual.second == 0) { continue; }
        else cout << "A distância do vértice " << src << " ao vértice " << atual.first <<  " é: " << atual.second << endl; 
    }
}

template <class Item>
void Grafo<Item>::addPar(Item v1, Item v2)
{
    adjacencias = map<Item, vector<Item>>();
    adjacencias[v1].push_back(v2);
    adjacencias[v2].push_back(v1);
}

template <class Item>
map<Item, int> Grafo<Item>::bfs(Item src)
{
    // bool* marked = new bool[V];
    map<Item, bool> marked;
    map<Item, Item> pred;
    map<Item, int> dist;
    queue<Item> fila;
    for(auto const& x : adjacencias){
        marked[x.first] = false;
        pred[x.first] = Item(); // -1 , null
        dist[x.first] = INT_MAX;
    }

    marked[src] = true;
    dist[src] = 0;
    fila.push(src);

    while(!fila.empty()){
        Item u = fila.front();
        fila.pop();
        for(int i = 0; i < adjacencias[u].size(); i++){
            Item v = adjacencias[u][i];
            if(!marked[v]){
                marked[v] = true;
                dist[v] = dist[u] + 1;
                pred[v] = u;
                fila.push(v);
            }
        }
    } 

    return dist;


/*
    for(auto const& atual : marked){
        if(!atual.second){
            pred[atual.first] = atual.first;
            atual.second = true;

            fila.push(atual.first);
            while(!fila.empty()){
                Item u = fila.front();
                fila.pop();
                for(int j = 0; j < adjacencias[u].size(); j++){
                    Item v = adjacencias[u][j];
                    if(!marked[v]){
                        pred[v] = u;
                        marked[v] = true;
                        fila.push(v);
                        if(v == dest) return true;
                    }
                }
            }
        }
    }
    */
}

#endif