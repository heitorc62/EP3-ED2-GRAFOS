#include<iostream>
#include <climits>
#include "Grafo.h"

using namespace std;

Grafo<string> input(){
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
    while(grafo.V < V){
        cout << "Ainda faltam " << V - grafo.V << " vértices para serem adicionados. Adicione um vértice: " << endl;
        string novo;
        cin >> novo;
        grafo.addSingular(novo);
    }
    return grafo;
}


 void distancias(){
    Grafo<string> grafo = input();
    cout << "Insira o vértice que quer calcular distâncias: ";
    string epa;
    cin >> epa;
    grafo.distancias(epa);
}


void wordLadders(){
    Grafo<string> grafo = Grafo<string>();
    grafo.wordLadders();
    grafo.imprimeLista();
    cout << "O grafo possui " << grafo.V << " vértices." << endl;
}


void randomGrafo(){
    Grafo<string> grafo = Grafo<string>();
    grafo.randomGraphs();
    grafo.imprimeLista();
    cout << "O grafo possui " << grafo.V << " vértices." << endl;
}

void comps(){
    Grafo<string> grafo = input();
    grafo.infoCompsConexas();

}



int main(){
    /*
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
    */
    //grafo.imprimeLista();
    //grafo.distancias(epa);
    /*
    Grafo<string> grafo = Grafo<string>();
    grafo.wordLadders();
    grafo.imprimeLista();
    cout << grafo.V << endl;
    */
    comps();
    
}