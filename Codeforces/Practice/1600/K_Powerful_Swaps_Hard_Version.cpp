#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef tree<
    pair<int,int>,
    null_type,
    less<pair<int,int>>,
    rb_tree_tag,
    tree_order_statistics_node_update
> ordered_set;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int,int>> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i].first;
        ordered_set st;
        for(int i=0; i<n; i++){
            arr[i].second = st.size() - st.order_of_key({arr[i].first+1, -1});
            st.insert({arr[i].first, i});
        }
        sort(arr.begin(), arr.end());
        int cnt = 0;
        int flag = 1;
        for(int i=0; i<n; i++){
            cnt += arr[i].second;
            if(cnt > arr[i].first){
                flag = 0;
                break;
            }
        }
        if(flag){
            cout << "YES" << endl;
        } else{
            cout << "NO" << endl;
        }
    }
    return 0;
}