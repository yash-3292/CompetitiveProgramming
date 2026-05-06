#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool query(int i, int j){
    cout << "? " << i << " " << j << "\n";
    cout.flush();
    bool ans;
    cin >> ans;
    return ans;
}

void result(int ans){
    cout << "! " << ans << "\n";
    cout.flush();
    return;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int ans = -1;
        for(int i=5; i<=2*n; i+=2){
            bool val = query(i, i+1);
            if(val){
                ans = i;
                break;
            }
        }
        if(ans != -1){
            result(ans);
            continue;
        }
        bool val1 = query(1, 2);
        if(val1){
            result(1);
            continue;
        }
        bool val2 = query(2, 3);
        if(val2){
            result(2);
            continue;
        }
        bool val3 = query(3, 4);
        if(val3){
            result(3);
            continue;
        }
        result(1);
    }
    return 0;
}