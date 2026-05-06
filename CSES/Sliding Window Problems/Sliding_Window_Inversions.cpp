#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
template <typename T>
using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update>;
    
int main(){
    int n, k;
    cin >> n >> k;
    ordered_set<int> s;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    int ans = 0;
    int i = 0;
    int j = 0;
    while(j < n){
        
    }
    cout << endl;
}