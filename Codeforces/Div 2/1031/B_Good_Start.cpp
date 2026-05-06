#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int w, h, a, b;
        cin >> w >> h >> a >> b;
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(abs(x2 - x1) < a){
            if(abs(y2-y1) % b != 0){
                cout << "No" << endl;
                continue;
            }
        }
        else if(abs(y2 - y1) < b){
            if(abs(x2-x1) % a != 0){
                cout << "No" << endl;
                continue;
            }
        }
        else{
            if(abs(x2-x1) % a != 0 && abs(y2-y1) % b != 0){
                cout << "No" << endl;
                continue;
            } 
        }
        cout << "Yes" << endl;
    }
    return 0;
}