#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int sum = 0; 
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            if(x == 0) sum++;
            else sum += x;
        }
        cout << sum << endl;
    }
    return 0;
}