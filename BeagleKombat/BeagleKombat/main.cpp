//
//  main.cpp
//  BeagleKombat
//
//  Created by Luis Mario Trujillo  on 5/2/19.
//  Copyright © 2019 Luis Mario Trujillo . All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main() {
    int n, k;
    string sequence;
    vector<int> valores;
    cin >> n >> k;
    int damages[n];
    for(int x=0;x<n;x++){
        cin >> damages[x];
    }
    cin >> sequence;
    bool past_equal=false;
    int total=0;
    
    for(int x=0;x<n;x++){
        //si son iguales
        if(sequence[x]==sequence[x+1]){
            //checar si el pasado fue igual
            if(past_equal){
                //checar si cabe
                if(valores.size()<k){
                    valores.push_back(damages[x]);
                }else{
                    //si no cabe ver si es mayor al menor
                    sort(valores.begin(), valores.end(),greater<int>());
                    if(valores.back()<damages[x]){
                        valores.pop_back();
                        valores.push_back(damages[x]);
                    }
                }
                //si el pasado no fue igual añadir a lista de espera
            }else{
                if(valores.size()<k){
                    valores.push_back(damages[x]);
                }
                
                
            }
            past_equal=true;
        //si no son iguales
        }else{
            //checar si el pasado fue igual
            if(past_equal){
                //si hay lugar lo metes
                if(valores.size()<k){
                    valores.push_back(damages[x]);
                }else{
                    //si no cabe ver si es mayor al menor
                    sort(valores.begin(), valores.end(),greater<int>());
                    if(valores.back()<damages[x]){
                        valores.pop_back();
                        valores.push_back(damages[x]);
                    }
                }
                //ya que no es igual y pasado sí checas para sumar
                for(int x=0;x<k;x++){
                    total=total+valores.back();
                    valores.pop_back();
                }
            //si el pasado no fue igual
            }else{
                total=total+damages[x];
            }
            past_equal=false;
        }
    }
    
    cout << total <<endl;
    
    return 0;
}

/*
7 3
1 5 16 18 7 2 10
baaaaca
 */


/*
 if(past_equal){
 sort(valores.begin(), valores.end(),greater<int>());
 if(valores.size()<k){
 valores.push_back(damages[x++]);
 }else{
 if(valores.back()<damages[x++]){
 valores.pop_back();
 valores.push_back(damages[x++]);
 }
 }
 }else{
 if(valores.size()<k){
 valores.push_back(damages[x]);
 valores.push_back(damages[x++]);
 }else{
 sort(valores.begin(), valores.end(),greater<int>());
 if(valores.back()<damages[x++]){
 valores.pop_back();
 valores.push_back(damages[x++]);
 }
 }
 past_equal=true;
 }
 differentEnd=true;
 }else{
 if(differentEnd){
 for(int x=0;x<k;x++){
 cout << total << " = " <<valores.back()<<endl;
 total=total+valores.back();
 valores.pop_back();
 }
 differentEnd=false;
 }else{
 total=total+damages[x];
 }
 past_equal=false;
 */
