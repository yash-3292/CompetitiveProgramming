#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    vector<int> freq(m,-1);
    int flag = 1;
    for(int i=0; i<n; i++){
        int val = arr[i]%m;
        if(freq[val] != -1){
            flag = 0;
            break;
        }
        freq[val] = arr[i];
    }
    if(!flag){
        cout << 0 << endl;
        return 0;
    }
    ll ans = 1;
    for(int i=0; i<m; i++){
        if(freq[i] != -1){
            for(int j=i+1; j<m; j++){
                if(freq[j] != -1){
                    if(freq[i] > freq[j]) ans = (((ll)(i-j))*ans)%m;
                    else ans = (((ll)(j-i))*ans)%m;
                } 
            }
        }
    }
    ans = (ans+m)%m;
    cout << ans << endl;
    return 0;
}