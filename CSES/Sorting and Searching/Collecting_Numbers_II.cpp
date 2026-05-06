#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> pos(n+1);
    vector<int> arr(n+1);
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        arr[x] = i+1; 
        pos[i+1] = x;       
    }
    int round = 1;
    for(int i=2; i<=n; i++){
        if(arr[i] < arr[i-1]){
            round++;
        }
    }
    while(m--){
        int p1, p2;
        cin >> p1 >> p2;
        int v1 = pos[p1];
        int v2 = pos[p2];
        
    }
    return 0;
}