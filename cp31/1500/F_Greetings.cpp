#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template<class T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int,int>> a(n);
        vector<pair<int,int>> b(n);
        for(int i=0; i<n; i++){
            cin >> a[i].first >> b[i].first;
            a[i].second = i;
            b[i].second = i;
        } 
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        vector<pair<int,int>> freq(n);
        for(int i=0; i<n; i++){
            freq[a[i].second].first = i;
            freq[b[i].second].second = i;
        }
        sort(freq.begin(), freq.end());
        vector<int> arr(n);
        for(int i=0; i<n; i++){
            arr[i] = freq[i].second;
        }
        ordered_set<int> s;
        ll ans = 0;
        for(int i=0; i<n; i++){
            int val =  s.size() - s.order_of_key(arr[i]+1);
            ans += val;
            s.insert(arr[i]);
        }   
        cout << ans << endl;
    }
    return 0;
}