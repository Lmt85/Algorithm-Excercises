//
//  main.cpp
//  RailRoad
//
//  Created by Luis Mario Trujillo  on 5/6/19.
//  Copyright © 2019 Luis Mario Trujillo . All rights reserved.
//

#include <iostream>
using namespace std;

bool Railroad(int t1[],int t2[],int train[],int t1size, int t2size){
    bool array[t2size+1][t1size+1];
    
    //inicia con true la esquina superior izquierda
    array[0][0]=true;

    //checa la fila
    for(int x=1;x<=t1size;x++){
        if(array[0][x-1]&&t1[x-1]==train[x-1]){
            array[0][x]=true;
        }else{
            array[0][x]=false;
        }
    }
    //checa la columna
    for(int x=1;x<=t2size;x++){
        if(array[x-1][0]&&t2[x-1]==train[x-1]){
            array[x][0]=true;
        }else{
            array[x][0]=false;
        }
    }
    
    for(int x=1;x<=t2size;x++){
        for(int y=1;y<=t1size;y++){
            if(array[x-1][y] && train[x+y-1] == t2[x-1]){
                array[x][y]=true;
            }else if(array[x][y-1] && train[x+y-1] == t1[y-1]){
                array[x][y]=true;
            }else{
                array[x][y]=false;
            }
            
        }
    }
               
    //checar martiz
    /*
    for(int x=0;x<=t2size;x++){
        for(int y=0;y<=t1size;y++){
            cout << array[x][y];
        }
        cout <<endl;
    }
    */

    return array[t1size][t2size];
}

int main() {
    int t1, t2;
    cin >> t1 >> t2;
    while (t1!=0&&t2!=0) {
        int train1[t1];
        int train2[t2];
        int train[t1+t2];
        for(int x=0;x<t1;x++){
            cin >> train1[x];
        }
        for(int x=0;x<t2;x++){
            cin >> train2[x];
        }
        for(int x=0;x<t1+t2;x++){
            cin >> train[x];
        }

        if(Railroad(train1,train2,train,t1,t2)){
            cout << "possible" << endl;
        }else{
            cout << "not possible" << endl;
        }
        
         cin >> t1 >> t2;
        
    }
    return 0;
}

/*
 for(int x=1;x<=t2size;x++){
 for(int y=1;y<=t1size;y++){
 //si esta arriba y a la izquierda
 if(array[x][y-1] && array[x-1][y]){
 if(t1[y-1]==train[x+y-1] || t2[x-1]==train[x+y-1]){
 array[x][y]=true;
 }else{
 array[x][y]=false;
 }
 //si esta a la izquierda
 }else if(array[x][y-1]){
 if(t1[y-1]==train[x+y-1]){
 array[x][y]=true;
 }else{
 array[x][y]=false;
 }
 //si esta a la arriba
 }else if(array[x-1][y]){
 if(t2[x-1]==train[x+y-1]){
 array[x][y]=true;
 }else{
 array[x][y]=false;
 }
 }else{
 array[x][y]=false;
 }
 }
 }
 */
