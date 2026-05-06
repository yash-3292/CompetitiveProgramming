#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
bool comparePairs(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.first != b.first) {
        return a.first > b.first;
    } else {
        return a.second > b.second;
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int,int>> arr(n);
        for(int i=0; i<n; i++){
            cin >> arr[i].first;
            arr[i].second = i+1;
        }
        sort(arr.begin(), arr.end(), comparePairs);
        ll sum = 0;
        vector<pair<int,int>> arr1(n);
        for(int i=0; i<n; i++){
            arr1[i].first = arr[i].second;
            int x = i/2 + 1;
            sum += (ll)arr[i].first * (ll)x;
            if(i&1) x *= -1;
            arr1[i].second = x;
        }
        sort(arr1.begin(), arr1.end());
        sum *= 2;
        cout << sum << endl;
        cout << 0 << " ";
        for(int i=0; i<n; i++){
            cout << arr1[i].second << " ";
        }
        cout << endl;
    }
    return 0;
}
