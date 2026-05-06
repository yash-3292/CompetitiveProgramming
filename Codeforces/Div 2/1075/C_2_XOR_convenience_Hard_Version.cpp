#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void f(int n){
    cout << n << " ";
    for(int i=2; i<n; i+=2){
        cout << i+1 << " " << i << " ";
    }
    cout << 1 << " ";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n&1){
            f(n-1);
            cout << n << " ";
        } else{
            if(!(n&(n-1))){
                cout << -1;
            } else{
                vector<int> arr(n+1);
                for(int i=1; i<=n; i++) arr[i] = i;
                for(int i=2; i<n; i+=2) swap(arr[i], arr[i+1]);
                int num = (n & ~(n & (n-1)));
                swap(arr[n], arr[num]);
                swap(arr[n], arr[1]);
                for(int i=1; i<=n; i++) cout << arr[i] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}