#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n, x;
    cin >> n >> x;
    vector<pair<int,int>> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i].first;
        arr[i].second = i+1;
    }
    sort(arr.begin(), arr.end());
    for(int k=0; k<n; k++){
        int i = 0;
        int j = n-1;
        if(i == k) i++;
        if(j == k) j--;
        while(i < j){
            ll val = (ll)arr[i].first + (ll)arr[j].first + (ll)arr[k].first;
            if(val == (ll)x){
                cout << arr[i].second << " " << arr[j].second << " " << arr[k].second << endl;
                return 0;
            } else if(val > (ll)x){
                j--;
                if(j == k) j--;
            } else{
                i++;
                if(i == k) i++;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}