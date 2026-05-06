#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct node {
    int l;
    int r;
    int real;
};

bool comp(node p1, node p2){
    return p1.real < p2.real;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<node> arr(n);
        for(int i=0; i<n; i++){
            cin >> arr[i].l >> arr[i].r >> arr[i].real;
        }
        sort(arr.begin(), arr.end(), comp);
        map<int,int> mpp;
        mpp[k] = 1;
        int maxi = k;
        for(int i=0; i<n; i++){
            auto it = mpp.upper_bound(arr[i].l);
            if(it != mpp.end()){
                if(it->first <= arr[i].r){
                    mpp[arr[i].real] = 1;
                    maxi = max(maxi, arr[i].real);
                    continue;
                }
            }
            if(it == mpp.begin()) continue;
            it--;
            if(it->first == arr[i].l){
                mpp[arr[i].real] = 1;
                maxi = max(maxi, arr[i].real);
            }
        }
        cout << maxi << endl;
    }
    return 0;
}