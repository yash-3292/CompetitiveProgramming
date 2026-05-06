#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n+1);
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        arr[x] = i+1;        
    }
    int round = 1;
    for(int i=2; i<=n; i++){
        if(arr[i] < arr[i-1]){
            round++;
        }
    }
    cout << round << endl;
    return 0;
}