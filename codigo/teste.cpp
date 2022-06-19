#include<iostream>
#include <math.h>
#include <climits>
#include <vector>
#include <map>
#include <climits>
#include "Grafo.h"

using namespace std;

Grafo<string> input1(){
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
    return grafo;
}


Grafo<string> input2(){
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
    Grafo<string> grafo = input2();
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
    int n;
    double p;
    cout << "Insira o total de vértices desejados no grafo: ";
    cin >> n;
    cout << "Insira a probabilidade de dois vértices estarem ligados: ";
    cin >> p;
    grafo.randomGraphs(n, p);
    grafo.imprimeLista();
    cout << "O grafo possui " << grafo.V << " vértices." << endl;
}

void comps(){
    Grafo<string> grafo = input2();
    grafo.infoCompsConexas();
}

void componentegigante(){
    Grafo<string> grafo = Grafo<string>();
    int n;
    double p, e;
    //cout << "Insira o total (n) de vértices desejados no grafo: ";
    cin >> n;
    //cout << "A propriedade das componentes gigantes em um grafo, é tal que se a probabilidade de dois vértices estarem ligados é p, então: " << endl;
    //cout << "se p <= (1 - ε)/n, então, com alta probabilidade as componentes conexas serão pequenas, com O(log n) elementos." << endl;
    //cout << "se p >= (1 + ε)/n, então, surge uma componente gigante no grafo." << endl;
    //cout << "Note que O(log " << n << ") = " << "O(" << log10(n) << ")" << endl;
    //cout << "Então, como n = " << n << " e tomando ε = 0.12: " << endl;
    //cout << "Insira p <= " << (double)(1 - e)/(double)n << " se quiser componentes pequenas." << endl;
    //cout << "Insira p >= " << (1 + e)/n << " se quiser componente gigante." << endl;
    //cout << "Insira p: ";
    cin >> p;
    grafo.randomGraphs(n, p);
    grafo.infoCompsConexas();

}

void seisGraus(){
    Grafo<string> grafo = Grafo<string>();
    int n;
    double p;
    //cout << "Insira o total de vértices desejados no grafo: ";
    cin >> n;
    //cout << "Insira a probabilidade de dois vértices estarem ligados: ";
    cin >> p;
    grafo.randomGraphs(n, p);
    //grafo.imprimeLista();
    int cont = 0;
    double media1, media2;
    vector<string> maior = grafo.maiorComp();
    for (int i = 0; i < maior.size(); i++){
        map<string, int> aux = grafo.bfs(maior[i]);
        media1 = cont = 0;
        for(auto const& x : aux){
            if(x.second == INT_MAX || x.second == 0){continue;}
            media1 += x.second;
            cont++;
        }
        media1 /= cont;
        media2 += media1;
    }
    media2 /= maior.size();
    cout << "n = " << n << endl;
    cout << "p = " << p << endl;
    cout << "A distância média entre dois vértices da maior componente conexa do grafo gerado é: " << media2 << endl;
    
    


    
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
    seisGraus();
    //componentegigante();
    
}