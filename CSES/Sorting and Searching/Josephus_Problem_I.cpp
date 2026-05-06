#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    list<int> l;
    for(int i=1; i<=n; i++){
        l.push_back(i);
    }
    auto it = l.begin();
    it++;
    if(it == l.end()) it = l.begin();
    while(l.size()){
        if(l.size() == 2){
            cout << *it << " ";
            it++;
            if(it == l.end()) it = l.begin();
            cout << *it << " ";
            break;
        } 
        cout << *it << " ";
        auto temp = it;
        it++;
        if(it == l.end()) it = l.begin();
        it++;
        if(it == l.end()) it = l.begin();
        l.erase(temp);
    }
    cout << endl;
    return 0;
}