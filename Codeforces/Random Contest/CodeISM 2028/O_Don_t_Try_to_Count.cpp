#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int g=0; g<t; g++){
        int n, m;
        cin >> n >> m;
        string x, s;
        cin >> x;
        cin >> s;
        int i = 0;
        int flag = 0;
        do{
            if(x==s){
                cout << i << endl;
                flag = 1;
                break;
            }
            if(x.find(s) != string::npos){
                cout << i << endl;
                flag = 1;
                break;
            }
            x.append(x);
            i++;
        }while(x.length() < 2*s.length());
        if(flag) continue;
        if(x.find(s) != string::npos){
            cout << i << endl;
            continue;
        }
        cout << -1 << endl;
    }
    return 0;
}