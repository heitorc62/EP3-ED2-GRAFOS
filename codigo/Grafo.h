#ifndef GRAFO_H
#define GRAFO_H
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <fstream>
#include <cstdlib>

using namespace std;

template <class Item>
class Grafo
{
public:
    Grafo(){ adjacencias = map<Item, vector<Item>>(); };
    void addPar(Item v1, Item v2);
    void addSingular(Item v);
    void dfsR(Item v, map<Item, bool> & marked);
    void wordLadders();
    void infoCompsConexas();
    vector<string> readWords(string caminho);
    map<Item, vector<Item>> adjacencias;
    map<Item, int> bfs(Item src);
    void distancias(Item src);
    int V; // O número total de vértices
    void imprimeLista();
    void show(vector<Item> lista);
    void randomGraphs(int n, double p);
    vector<Item> maiorComp();
    map<Item, int> compConexa();
};

template<class Item>
void Grafo<Item>::randomGraphs(int n, double p){
    double r;
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            r = (double)(rand() % 100)/(double)100;
            if(r < p){
                addPar(to_string(i), to_string(j));
            }
        }
    }
}

template<class Item>
vector<Item> Grafo<Item>::maiorComp(){
    map<Item, int> componentes = compConexa();
    map<int, vector<Item>> componentes2;
    vector<Item> maior;
    int max = 0, compMax;
    for(auto const& x : componentes){
        componentes2[x.second].push_back(x.first);
        //cout << "O elemento " << x.first << " está na " << x.second << " componente conexa." << endl;
        if(componentes2[x.second].size() > max){
            max = componentes2[x.second].size();
            compMax = x.second;
        }
    }
    //cout << "A maior componente é a componente de número " << compMax << endl;
    // Agora temos um map em que as keys são as componentes conexas e os valores são os vértices que estão em cada componente.
    // Também já sabemos qual é a maior componente conexa.
    for(int i = 0; i < componentes2[compMax].size(); i++){
        maior.push_back(componentes2[compMax][i]);
    }
    return maior;
}


template<class Item>
void Grafo<Item>::show(vector<Item> lista){
    for(int i = 0; i < lista.size(); i++){
        cout << lista[i] << endl;
    }
}

template<class Item>
vector<string> Grafo<Item>::readWords(string caminho){
    vector<string> linhas;
    string linha;
    ifstream input_file(caminho);
    if(!input_file.is_open()){
        cout << "Não foi possível abrir o arquivo " << caminho << endl;
    }
    while(getline(input_file, linha)){  // Enquanto não chegamos ao final do arquivo, colocamos cada linha no vector
        linhas.push_back(linha);
    }
    input_file.close();
    return linhas;
}


template<class Item>
void Grafo<Item>::wordLadders(){
    //cout << "Insira o caminho do arquivo que contém as palavras: " << endl;
    string caminho = "words5.txt";
    //cin >> caminho;
    map<string, vector<string>> dict;
    vector<string> palavras = readWords(caminho);
    //show(palavras);



    for(int i = 0; i < palavras.size(); i++){
        for(int j = 0; j < palavras[i].length(); j++){
            string bucket = palavras[i];
            bucket[j] = '_';
            dict[bucket].push_back(palavras[i]);
        }
    }

    // Adicionar os pares agora!
    for(auto const& bucket : dict){
        for(int i = 0; i < bucket.second.size(); i++){
            for(int j = 0; j < bucket.second.size(); j++){
                if(bucket.second[i] != bucket.second[j]){
                    addPar(bucket.second[i], bucket.second[j]);
                }
            }
        }             
    }
}


/*
Receberemos duplas: u_1 v_1. Isso quer dizer que há uma aresta unindo os
vértices u_1 e v_1. Deveremos colocar u_1 e v_1 como chaves do dicionário,
adicionar u_1 ao vector de adjacências de v_1 e adicionar v_1 ao vector de
adjacências de u_1.
*/

template<class Item>
void Grafo<Item>::infoCompsConexas(){
    map<Item, int> comp = compConexa();
    int* aux = new int[V];
    for(int i = 0; i < V; i++) aux[i] = 0;
    for(auto const& x : comp){
        aux[x.second]++;
        //cout << "O item " << x.first << " pertence à comp conexa: " << x.second << endl;
    }
    int max = 0, media = 0, total = 0;
    for(int i = 0; i < V; i++){
        if(aux[i] == 0){continue;}
        else{
            cout << "A componente conexa " << i << " tem " << aux[i] << " elementos." << endl;
            if(aux[i] > max) max = aux[i];
            total++;
            media += aux[i];
        }
    }
    cout << "A maior componente conexa tem " << max << " elementos." << endl;
    cout << "Há " << total << " componentes conexas." << endl;
    cout << "A quantidade média de elementos em uma componente conexa é: " << media/total << endl;
}



template<class Item>
map<Item, int> Grafo<Item>::compConexa(){
    int c = 0;
    //bool* marked = new bool[V];
    //Item* comp = new int[V];
    map<Item, bool> marked;
    map<Item, int> comp;
    for(auto const& x : adjacencias){
        marked[x.first] = false;
        comp[x.first] = -1;
    }
    for(auto const& x : adjacencias){
        Item u = x.first;
        if(!marked[u]){
            dfsR(u, marked);
            for(auto const& y : adjacencias){
                if(marked[y.first] && comp[y.first] == -1) comp[y.first] = c;
            }
            c++;
        }
    }
    return comp;
}

template<class Item>
void Grafo<Item>::dfsR(Item v, map<Item, bool> & marked){
    marked[v] = true;
    for(int i = 0; i < adjacencias[v].size(); i++){
        Item w = adjacencias[v][i];
        if(!marked[w]){
            dfsR(w, marked);
        }
    }
}

template<class Item>
void Grafo<Item>::imprimeLista(){
    for(auto const& atual : adjacencias){
        cout << atual.first << " -> [ ";
        for(int i = 0; i < atual.second.size(); i++){
            cout << atual.second[i] << " ";
        }
        cout << " ]" << endl;
    }
}



template<class Item>
void Grafo<Item>::distancias(Item src){
    map<Item, int> dist = bfs(src);
    for(auto const& atual : dist){
        if(atual.second == INT_MAX) cout << "O vértice " << src << " e o vértice " << atual.first << " não estão conectados." << endl;
        else if(atual.second == 0) { cout << "é o proprio" << endl;}
        else cout << "A distância do vértice " << src << " ao vértice " << atual.first <<  " é: " << atual.second << endl; 
    }
}

template <class Item>
void Grafo<Item>::addPar(Item v1, Item v2)
{
    if(adjacencias.count(v1) == 0) V++;
    if(adjacencias.count(v2) == 0) V++;
    if(!count(adjacencias[v1].begin(), adjacencias[v1].end(), v2)) adjacencias[v1].push_back(v2);
    if(!count(adjacencias[v2].begin(), adjacencias[v2].end(), v1)) adjacencias[v2].push_back(v1);
}

template<class Item>
void Grafo<Item>::addSingular(Item v){
    if(adjacencias.count(v) == 0) V++;
    adjacencias[v];
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