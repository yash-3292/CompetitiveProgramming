#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    multiset<int> mulset;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        auto it = mulset.upper_bound(x);
        mulset.insert(x);
        if(it != mulset.end()) mulset.erase(it);
    }
    cout << mulset.size() << endl;
    return 0;
}