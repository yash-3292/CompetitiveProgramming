#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    vector<int> firstPos(51, -1);
    for(int i=0; i<n; i++){
        if(firstPos[arr[i]] == -1) firstPos[arr[i]] = i+1;
    }
    while(q--){
        int t;
        cin >> t;
        cout << firstPos[t] << " ";
        for(int i=0; i<51; i++){
            if(firstPos[i] != -1){
                if(firstPos[i] < firstPos[t]) firstPos[i]++;
            }
        }
        firstPos[t] = 1;
    }
    cout << endl;
    return 0;
}