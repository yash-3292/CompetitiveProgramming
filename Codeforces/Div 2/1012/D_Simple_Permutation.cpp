#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxN = 1e5 + 10;
bool isPrime[maxN];

void pre(){
    isPrime[0] = isPrime[1] = false;
    for(int i=2; i<maxN; i++) isPrime[i] = true;
    for(int i=2; i*i<maxN; i++){
        if(isPrime[i]){
            for(int j=i*i; j<maxN; j+=i){
                isPrime[j] = false;
            }
        }
    }
}

void solve(){
    int n;
    cin >> n;
    int i = 1; 
    int j = n;
    int x;
    while(i <= j){
        if(isPrime[i]) x = i;
        if(isPrime[j]) x = j;
        i++;
        j--;
    }
    j = x;
    i = x-1;
    while(i > 0 && j <= n){
        cout << j << " " << i << " ";
        i--;
        j++;
    }
    while(i > 0){
        cout << i << " ";
        i--;
    }
    while(j <= n){
        cout << j << " ";
        j++;
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    pre();
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}