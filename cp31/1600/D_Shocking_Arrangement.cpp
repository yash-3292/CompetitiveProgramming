#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> pos;
        vector<int> neg;
        bool isfoolZero = true;
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            if(x!=0) isfoolZero = false;
            if(x >= 0) pos.push_back(x);
            else neg.push_back(x);
        }
        if(isfoolZero){
            cout << "No" << endl;
            continue;
        }
        cout << "Yes" << endl;
        int p = pos.size();
        n = neg.size();
        sort(pos.begin(), pos.end());
        sort(neg.begin(), neg.end());
        int total = 0;
        int i = 0;
        for(int j=0; j<n; j++){
            int val = -1*neg[j];
            while(i < p && total<val){
                cout << pos[i] << " ";
                total += pos[i];
                i++;
            }
            cout << neg[j] << " ";
            total += neg[j];
        }
        cout << endl;
    }
    return 0;
}