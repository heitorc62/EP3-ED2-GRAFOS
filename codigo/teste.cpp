#include<iostream>
#include "Grafo.h"

using namespace std;

int main(){
    Grafo<int> grafo = Grafo<int>();
    int V; int E;
    cin >> V >> E;
    int u, v;
    for(int i = 0; i < E; i++){
        cin >> u >> v;
        grafo.addPar(u, v);
    }

    
}