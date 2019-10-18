//
//  main.cpp
//  Reto3
//
//  Created by Luis Mario Trujillo  on 4/11/19.
//  Copyright © 2019 Luis Mario Trujillo . All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <iterator>
#include <unordered_set>

using namespace std;

//funcion auxiliar para checar con cada nodo
bool functaux(int node, const vector<vector<int>> graph, unordered_set<int> visiting, vector<bool> visited){
    if(visiting.find(node)!=visiting.end()){
        return true;
    }
    if(visited[node]){
        return false;
    }
    visiting.insert(node);
    for(const int neigh: graph[node]){
        if(functaux(neigh, graph, visiting,visited)){
            return true;
        }
    }
    visiting.erase(node);
    visited[node] =true;
    return false;
}


int main() {
    int numCursos;
    int numRequisitos;
    //leer num de cursos y de requisistos
    cin >> numCursos >> numRequisitos;
    //se crea un vector de vectores de enteros
    vector<vector<int>> graph(numCursos);
    //se crea un mapa con la llave del nombre y un valor de la materia
    map<string,int> map;
    for(int x=0;x<numCursos;x++){
        string nombre;
        cin >> nombre;
        map.insert(pair<string, int>(nombre,x));
    }
    for(int x=0;x<numRequisitos;x++){
        string a;
        string b;
        cin >> a >> b;
        graph[map[a]].push_back(map[b]);
    }
    unordered_set<int> visiting;
    vector<bool> visited(numCursos, false);
    for(int node=0; node < numCursos; node++){
        if(functaux(node, graph, visiting, visited)){
            cout << "INCORRECT";
            return 0;
        }
       }
     cout <<"CORRECT";
    return 0;
}
