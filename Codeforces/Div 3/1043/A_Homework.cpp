#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string a;
        cin >> a;
        int m;
        cin >> m;
        string b;
        cin >> b;
        string c;
        cin >> c;
        string vlad;
        string Dima;
        for(int i=0; i<m; i++){
            if(c[i] == 'V'){
                vlad += b[i];
            } else{
                Dima += b[i];
            }
        }
        reverse(vlad.begin(), vlad.end());
        cout << vlad;
        cout << a;
        cout << Dima;
        cout << endl;
    }
    return 0;
}