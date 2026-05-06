#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    int x;
    int mini = INT_MAX;
    for(int i=1; i<=n; i++){
        int val = i + n/i;
        if(n%i != 0) val++;
        if(val < mini){
            mini = val;
            x = i;
        }
    }
    int temp = n;
    while(temp >= x){
        for(int i=x-1; i>=0; i--){
            cout << temp-i << " ";
        }
        temp -= x;
    }
    for(int i=1; i<=temp; i++){
        cout << i << " ";
    }
    cout << endl; 
    return 0;
}