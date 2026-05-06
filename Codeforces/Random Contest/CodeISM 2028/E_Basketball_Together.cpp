#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n, d;
    cin >> n >> d;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end(), greater<int>());
    int totalPlayer = n;
    int win = 0;
    for(int i=0; i<n; i++){
        int player = ceil((double)d/(double)arr[i]);
        if(d%arr[i] == 0) player++;
        if(totalPlayer >= player){
            totalPlayer -= player;
            win++;
        } else{
            break;
        }
    }
    cout << win << endl;
    return 0;
}