//
//  main.cpp
//  BeagleBalls
//
//  Created by Luis Mario Trujillo  on 5/5/19.
//  Copyright © 2019 Luis Mario Trujillo . All rights reserved.
//

#include <iostream>
using namespace std;

int BeagleBalls(int arrV[],int arrB[],int iv, int ib, int vivos,int totalV,int totalB){
    //si se llega a la ultima bala se acaba
    if(ib==totalB){
        return 0;
    }else{
        //se calcula la vida despues de la bala
        int restante=arrV[iv]-arrB[ib];
        //si solo mata a ese
        if(restante==0){
            ib++;
            iv++;
            vivos--;
            //si matan a todos
            if(vivos==0){
                vivos=totalV;
            }
            cout <<vivos << endl;
            BeagleBalls(arrV, arrB, iv, ib, vivos,totalV,totalB);
            //le baja la vida
        }else if(restante>0){
            arrV[iv]=restante;
            ib++;
            cout <<vivos << endl;
            BeagleBalls(arrV, arrB, iv, ib, vivos,totalV, totalB);
            //lo mata y hiere al siguiente
        }else if(restante<0){
            iv++;
            vivos--;
            //si matan a todos
            if(vivos==0){
                vivos=totalV;
                ib++;
                iv=0;
                cout <<vivos << endl;
            }else{
                arrB[ib]=-restante;
            }
            BeagleBalls(arrV, arrB, iv, ib, vivos,totalV, totalB);
        }
    }
    return 0;
}

int main() {
    int s, bb;
    cin >> s >> bb;
    int lives[s], balls[bb];
    for(int x=0;x<s;x++){
        cin >> lives[x];
    }
    for(int x=0;x<bb;x++){
        cin >> balls[x];
    }
    
    BeagleBalls(lives, balls, 0, 0, s,s,bb);
    
    return 0;
}

/*

 5 5
 1 2 1 2 1
 3 10 1 1 1
 
 5 4
 3 2 5 1 2
 5 1 10 3
 
 */

