//
//  main.cpp
//  Maximum path in triangle
//
//  Created by Luis Mario Trujillo  on 3/29/19.
//  Copyright © 2019 Luis Mario Trujillo . All rights reserved.
//

#include <iostream>
using namespace std;
int main() {
    int cycles;
    cin >> cycles;
    for(int x=0;x<cycles;x++){
        int n;
        cin >> n;
        int arr[n][n];
        for(int r=0;r<n;r++){
            for (int c=0; c<n; c++) {
                if(c>r){
                    arr[r][c]=0;
                }else{
                    cin >> arr[r][c];
                }
            }
        }
    
        for(int r=n-2;r>=0;r--){
            for (int c=0; r>=c; c++) {
                if(arr[r+1][c]>arr[r+1][c+1]){
                arr[r][c]=arr[r][c]+arr[r+1][c];
                }else{
                    arr[r][c]=arr[r][c]+arr[r+1][c+1];
                }
            }
        }
            cout << arr[0][0] <<endl;
    }
    

    return 0;
}
