#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    vector<int> isSort(n+1);
    isSort[n] = 1;
    isSort[n-1] = 1;
    for(int i=n-2; i>=0; i--){
        if(isSort[i+1] == 0) isSort[i] = 0;
        else{
            isSort[i] = (arr[i] <= arr[i+1]);
        }
    }
    if(isSort[0]){
        cout << 0 << endl;
        return;
    }
    unordered_map<int,int> totalFreq;
    unordered_map<int,int> freq;
    for(int i=0; i<n; i++){
        totalFreq[arr[i]]++;
    }
    int cnt = 0;
    int ans = totalFreq.size();
    for(int i=0; i<n; i++){
        freq[arr[i]]++;
        if(freq[arr[i]] == 1) cnt++;
        if(freq[arr[i]] == totalFreq[arr[i]]) cnt--;
        if(cnt == 0 && isSort[i+1]){
            ans = min(ans, (int)freq.size());
        }
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}