#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int gcd(int a, int b){
    if(a == 0) return b;
    return gcd(b%a, a);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        int mini = -1;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            if(arr[i] != i+1){
                if(mini == -1){
                    mini = abs(arr[i] - i - 1);
                } else{
                    mini = gcd(mini, abs(arr[i] - i - 1));
                }
            }
        }
        cout << mini << endl;
    }
    return 0;
}