#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int flag = 1;
    vector<vector<int>> arr(4, vector<int>(4));
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            cin >> arr[i][j];
        }
    }
    int x = -1;
    int y = -1;
    int cntx = 0;
    int cnty = 0;
    for(int i=0; i<4; i++){
        if(arr[i][0] == arr[i][2]){
            if(y == -1) y = abs(arr[i][3] - arr[i][1]);
            else{
                int val = abs(arr[i][3] - arr[i][1]);
            }
        }
    }
    set<pair<int,int>> st;
    for(int i=0; i<4; i++){
        
    }
    return 0;
}