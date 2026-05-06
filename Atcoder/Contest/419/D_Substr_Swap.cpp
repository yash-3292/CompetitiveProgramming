#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s;
    cin >> t;
    vector<bool> arr(n,false);
    while(m--){
        int x, y;
        cin >> x >> y;
        arr[x-1] = !arr[x-1];
        arr[y] = !arr[y]; 
    }
    int flag = true;
    for(int i=0; i<n; i++){
        if(arr[i]) flag = !flag;
        if(flag){
            cout << s[i];
        } else{
            cout << t[i];
        }
    }
    cout << endl;
    return 0;
}