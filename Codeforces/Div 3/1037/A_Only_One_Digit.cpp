#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int x;
        cin >> x;
        int temp = x;
        int mini = INT_MAX;
        while(temp > 0){
            mini = min(mini, temp%10);
            temp /= 10;
        }
        cout << mini << endl;
    }
    return 0;
}