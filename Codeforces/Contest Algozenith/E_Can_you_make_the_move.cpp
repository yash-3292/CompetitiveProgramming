#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n, y;
    cin >> n >> y;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    if(n%2 == 0){
        cout << 0 << endl;
        return 0;
    }
    int xorr = 0;
    for(int i=0; i<n; i++){
        xorr = (xorr^arr[i]);
    }
    
    return 0;
}