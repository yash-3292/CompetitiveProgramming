#include<bits/stdc++.h>
using namespace std;

int main(){
    int x, n;
    cin >> x >> n;
    set<int> st;
    unordered_map<int,int> rem;
    priority_queue<int> pq;
    pq.push(x);
    st.insert(0);
    st.insert(x);
    while(n--){
        int val;
        cin >> val;
        st.insert(val);
        auto it = st.find(val);
        it--;
        pq.push(val-*it);
        int low = *it;
        it++;
        it++;
        pq.push(*it-val);
        int hi = *it;
        rem[hi-low]++;
        while(rem[pq.top()] > 0){
            rem[pq.top()]--;
            pq.pop();
        } 
        cout << pq.top() << " ";
    }
    return 0;
}