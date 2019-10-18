//
//  main.cpp
//  RockyTheBeagle
//
//  Created by Luis Mario Trujillo  on 4/7/19.
//  Copyright © 2019 Luis Mario Trujillo . All rights reserved.
//
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <climits>

using namespace std;

#define INF INT_MAX

vector<vector<pair<int, int>>> G(20);

vector<int> Dist;
/*
int conversion(char letra){
    switch (letra) {
        case 'A':
            return 1;
            break;
        case 'B':
            return 2;
            break;
        case 'C':
            return 3;
            break;
        case 'D':
            return 4;
            break;
        case 'E':
            return 5;
            break;
        case 'F':
            return 6;
            break;
        case 'G':
            return 7;
            break;
        case 'H':
            return 8;
            break;
        case 'I':
            return 9;
            break;
        case 'J':
            return 10;
            break;
        case 'K':
            return 11;
            break;
        case 'L':
            return 12;
            break;
        case 'M':
            return 13;
            break;
        case 'N':
            return 14;
            break;
        case 'O':
            return 15;
            break;
        case 'P':
            return 16;
            break;
        case 'Q':
            return 17;
            break;
        case 'R':
            return 18;
            break;
        case 'S':
            return 19;
            break;
        case 'T':
            return 20;
            break;
            
    }
    return 0;
}
*/
void Dijkstra(int N){
    // AquÃ­ va tu codigo.
    priority_queue<pair<int, int>,
    vector<pair<int, int>>,
    greater<pair<int, int>>>
    Q;
    Dist.assign(N, INF);
    Dist[0] = 0;
    pair<int, int> p(0, 0);
    Q.push(p);
    while (!Q.empty())
    {
        int u = Q.top().first;
        Q.pop();
        for (int i = 0; i < G[i].size(); i++)
        {
            pair<int, int> p = G[u][i];
            int v = p.first;
            int w = p.second;
            if (Dist[v] > Dist[u] + w)
            {
                Dist[v] = Dist[u] + w;
                pair<int, int> nvo(v, Dist[v]);
                Q.push(nvo);
            }
        }
    }
}

int main(){
    int veces;
    cin >> veces;
    //for(int x=0;x<veces;x++){
        int N, M, u, v, w;
        cin >> N >> M;
        
        for (int i = 0; i < M; ++i){
            cin >> u >> v >> w;
            u = u - 65;
            v = v - 65;
            pair<int, int> n1(v - 1, w);
            pair<int, int> n2(u - 1, w);
            G[u - 1].push_back(n1);
            G[v - 1].push_back(n2);
        }
        Dijkstra(N);
    
         cout << endl
         << "Distancias Mínimas" << endl;
         for (int i = 1; i < N; i++)
         cout << "1 -> " << (i + 1) << ": " << Dist[i] << " " << endl;
         ;
         
        /*
        int max=0, pos=0;
        for (int i = 1; i < N-1; i++){
            if(Dist[i]>max){
                max=Dist[i];
                pos=i;
            }
        }
         */
        
        
    //}
    
    
    
    
    
    
    return 0;
}
