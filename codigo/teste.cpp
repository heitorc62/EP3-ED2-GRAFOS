#include<iostream>
#include <climits>
#include "Grafo.h"

using namespace std;

int main(){
    Grafo<string> grafo = Grafo<string>();
    int V; int E;
    cout << "Insira o número de vértices e arestas V E" << endl;
    cin >> V >> E;
    string u, v;
    for(int i = 0; i < E; i++){
        cout << "Insira um par de vértices u v" << endl;
        cin >> u >> v;
        grafo.addPar(u, v);
    }
    cout << "Insira o vértice que quer calcular distâncias: ";
    string epa;
    cin >> epa;
    //grafo.imprimeLista();
    grafo.distancias(epa);

    
}