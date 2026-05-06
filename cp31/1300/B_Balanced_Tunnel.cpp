#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    map<int,int> fine;
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];
    int i = 0;
    int j = 0;
    int ans = 0;
    while(j < n && i < n){
        if(fine[a[i]] == 1){
            i++;
            continue;
        }
        if(a[i] == b[j]){
            i++;
            j++;
        } else{
            ans++;
            fine[b[j]] = 1;
            j++;
        }
    }
    cout << ans << endl;
    return 0;
}