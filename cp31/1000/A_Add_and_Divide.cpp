#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        int c = b;
        if(b == 1) c++;
        int mini = -1;
        while(true){
            int val = (int)ceil(log(a) / log(c));
            if(pow(c,val) == (double)a) val++;
            val += c - b;
            if(mini == -1){
                mini = val;
            } else if(val <= mini){
                mini = val;
            } else{
                break;
            }
            c++;
        }
        cout << mini << endl;
    }
    return 0;
}
