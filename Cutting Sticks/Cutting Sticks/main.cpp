//
//  main.cpp
//  Cutting Sticks
//
//  Created by Luis Mario Trujillo  on 3/11/19.
//  Copyright © 2019 Luis Mario Trujillo . All rights reserved.
//



#include <iostream>
#include <limits.h>

using namespace std;

#define oo INT_MAX



int multiplicacionMatriz(int p[],int n){
    int V[n][n];
    
    for (int i=1; i<=n; i++){
        V[i][i] = 0;
        for (int diag=1; diag<= n-1; diag++){
            for (i = 1; i<=n-diag; i++) {
                int j = i + diag;
                V[i][j] = oo;
                
                
                /*Esta función calcula el valor mínimo entre los diversos valores de:
                 D[i][k] + D[k+1][j] + d[i-1]*d[k]*d[j]
                 para k desde i hasta j-1 */
            }
        }
        
    }
    return V[1][n];
    
}

int main(){
    
    int inp;
    cin >> inp;
    while (inp!=0) {
        int n;
        int C[51], V[51][51];
        cin >> n;
        for (int i=0; i<n; i++){
            cin >> C[i];
            multiplicacionMatriz(V[i], 1);
        }
        
    
        
        cout << "The minimum cutting is " << V[0][n] << "." << endl;
        cin >> inp;
        
        
        
        
        
    
    }


    return 0;
}
