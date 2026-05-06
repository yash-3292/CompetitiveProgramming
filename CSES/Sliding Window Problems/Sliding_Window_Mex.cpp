#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    set<int> st;
    for(int i=0; i<100100; i++){
        st.insert(i);
    }
    map<int,int> mpp;
    int i = 0;
    int j = 0;
    while(j < n){
        if(mpp[arr[j]] == 0) st.erase(arr[j]);
        mpp[arr[j]]++;
        if(j-i+1 > k){
            mpp[arr[i]]--;
            if(mpp[arr[i]] == 0) st.insert(arr[i]);
            i++;
        }
        if(j-i+1 == k) cout << *st.begin() << " ";
        j++;
    }
    cout << endl;
    return 0;
}