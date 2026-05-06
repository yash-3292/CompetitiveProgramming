#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int f(int i, vector<vector<char>>& arr, vector<int>& pos){
    if(i == 8) return 1;

    int ans = 0;
    for(int j=0; j<8; j++){
        if(arr[i][j] == '*') continue;
        int flag = 1;
        for(int row=0; row<i; row++){
            if(j == pos[row]){
                flag = 0;
                break;
            } else if(abs(j-pos[row]) == abs(row-i)){
                flag = 0;
                break;
            }
        }
        if(flag){
            pos.push_back(j);
            ans += f(i+1, arr, pos);
            pos.pop_back();
        }
    }
    return ans;
}

int main(){
    vector<vector<char>> arr(8, vector<char>(8));
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            cin >> arr[i][j];
        }
    }
    vector<int> pos;
    int ans = f(0, arr, pos);
    cout << ans << endl;
    return 0;
}