#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        int sum = s[0]-'0';
        int cnt = 1;
        vector<int> arr;
        for(int i=1; i<n; i++) arr.push_back(s[i]-'0');
        sort(arr.begin(), arr.end());
        for(int i=0; i<n-1; i++){
            if(sum+arr[i] < 10){
                sum += arr[i];
                cnt++;
            } else break;
        }
        int ans = n - cnt;
        sum = 1;
        cnt = 0;
        for(int i=0; i<n-1; i++){
            if(sum+arr[i] < 10){
                sum += arr[i];
                cnt++;
            } else break;
        }
        ans = min(ans, n-cnt);
        cout << ans << endl;
    }
    return 0;
}