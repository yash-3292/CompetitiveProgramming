#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    priority_queue<int,vector<int>,greater<int>> pq;
    while(n--){
        int query;
        cin >> query;
        if(query == 1){
            int x;
            cin >> x;
            pq.push(x);
        } else{
            cout << pq.top() << endl;
            pq.pop();
        }
    }
    return 0;
}