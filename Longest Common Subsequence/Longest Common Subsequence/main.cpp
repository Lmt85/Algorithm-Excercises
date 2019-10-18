//
//  main.cpp
//  Longest Common Subsequence
//
//  Created by Luis Mario Trujillo  on 5/5/19.
//  Copyright © 2019 Luis Mario Trujillo . All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
int max(int x,int y){
    if(x<y){
        return y;
    }else{
        return x;
    }
}

int main() {
    int n;
    cin >> n;
    
    for(int x=0;x<n;x++){
        string first;
        string second;
        cin >> first;
        cin >> second;
        int xs = first.size();
        int ys =second.size();
        int matrix[xs+1][ys+1];
        
        for(int x=0;x<=xs;x++){
            for(int y=0;y<=ys;y++){
                if(x==0 || y==0){
                    matrix[x][y]=0;
                }else if(first[x-1]==second[y-1]){
                    matrix[x][y]=matrix[x-1][y-1]+1;
                }else{
                    matrix[x][y]=max(matrix[x-1][y],matrix[x][y-1]);
                }
            }
        }
    
   
        cout << "Case "<<x+1<<": "<< matrix[xs][ys] <<endl;
        
        
        
   }
    
    return 0;
}
/*
 AAAAAAABBAAB
 ABAABBAB
 
 XMJYAUZ
 MZJAWXU
 
 */

