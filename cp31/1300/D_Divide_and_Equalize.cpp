#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxN = 1e6 + 7;
vector<int> spf(maxN);
void pre(){
    spf[0] = 0;
    for(int i=1; i<maxN; i++) spf[i] = i;
    for(int i=2; i<maxN; i++){
        if(spf[i] == i){
            for(int j=2*i; j<maxN; j+=i){
                if(spf[j] == j){
                    spf[j] = i;
                }
            }
        }
    }
}

void primeDivisors(map<int,int> &mpp, vector<int> &div, int n){
    int temp = n;
    while(temp != 1){
        int prime = spf[temp];
        if(mpp[prime] == 0) div.push_back(prime);
        mpp[prime]++;
        temp /= prime;
    }
}

int main(){
    pre();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        map<int,int> mpp;
        vector<int> div;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            primeDivisors(mpp, div, arr[i]);
        } 
        int flag = 1;
        for(int val : div){
            if(mpp[val] % n != 0){
                flag = 0;
                break;
            }
        }
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}