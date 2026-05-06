#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> nums(n);
        vector<pair<int,int>> arr;
        for(int i=0; i<n; i++){
            cin >> nums[i];
            if(nums[i] < i+1) arr.push_back(make_pair(nums[i], i+1));
        }
        sort(arr.begin(), arr.end());
        int size = arr.size();
        ll cnt = 0;
        vector<int> array(size);
        for(int i=0; i<size; i++) array[i] = arr[i].first;
        for(int i=0; i<size; i++){
            cnt += (ll)(size - (upper_bound(array.begin(), array.end(), arr[i].second) - array.begin()));
        }
        cout << cnt << endl;
    }
    return 0;
}