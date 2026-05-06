#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m; 
    cin >> n >> m;
    multiset<int> mst;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        mst.insert(x);
    }
    for(int i=0; i<m; i++){
        int x;
        cin >> x;
        auto it = mst.upper_bound(x);
        if(it == mst.begin()) cout << -1 << endl;
        else{
            it--;
            cout << *it << endl;
            mst.erase(it);
        }
    }
    return 0;
}