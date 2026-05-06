#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll f(int i, vector<int>& arr, vector<ll>& dp){
    if(i == 1) return abs(arr[0]-arr[1]);
    if(i == 2){
        ll mini = arr[0];
        ll maxi = arr[0];
        mini = min(mini, (ll)arr[1]);
        mini = min(mini, (ll)arr[2]);
        maxi = max(maxi, (ll)arr[1]);
        maxi = max(maxi, (ll)arr[2]);
        return abs(mini-maxi);
    }
    if(i == 3){
        return (ll)abs(arr[0]-arr[1]) + abs(arr[2]-arr[3]);
    }

    if(dp[i] != -1) return dp[i];
    ll two = abs(arr[i]-arr[i-1]) + f(i-2, arr, dp);
    ll mini = arr[i-2];
    ll maxi = arr[i-2];
    mini = min(mini, (ll)arr[i-1]);
    mini = min(mini, (ll)arr[i]);
    maxi = max(maxi, (ll)arr[i-1]);
    maxi = max(maxi, (ll)arr[i]);
    ll three = abs(mini-maxi) + f(i-3, arr, dp);

    return dp[i] = min(two, three);
}

ll solve(vector<int>& arr){
    int n = arr.size();
    if(n == 0) return 0;
    if(n == 1) return 1e18;
    vector<ll> dp(n, -1);
    return f(n-1, arr, dp);
}

ll func1(vector<int>& arr){
    vector<int> temp = arr;
    return solve(temp);
}

ll func2(vector<int>& arr){
    int n = arr.size();
    vector<int> temp;
    ll mini = LLONG_MAX;
    ll maxi = 0;
    for(int i=0; i<n; i++){
        if(i == 0 || i == n-1){
            mini = min(mini, (ll)arr[i]);
            maxi = max(maxi, (ll)arr[i]);
        } else{
            temp.push_back(arr[i]);
        }
    }
    return abs(mini-maxi) + solve(temp);
}

ll func3(vector<int>& arr){
    int n = arr.size();
    vector<int> temp;
    ll mini = LLONG_MAX;
    ll maxi = 0;
    for(int i=0; i<n; i++){
        if(i == 0 || i == n-1 || i == 1){
            mini = min(mini, (ll)arr[i]);
            maxi = max(maxi, (ll)arr[i]);
        } else{
            temp.push_back(arr[i]);
        }
    }
    return abs(mini-maxi) + solve(temp);
}

ll func4(vector<int>& arr){
    int n = arr.size();
    vector<int> temp;
    ll mini = LLONG_MAX;
    ll maxi = 0;
    for(int i=0; i<n; i++){
        if(i == 0 || i == n-1 || i == n-2){
            mini = min(mini, (ll)arr[i]);
            maxi = max(maxi, (ll)arr[i]);
        } else{
            temp.push_back(arr[i]);
        }
    }
    return abs(mini-maxi) + solve(temp);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        ll ans1 = func1(arr);
        ll ans2 = func2(arr);
        ll ans3 = func3(arr);
        ll ans4 = func4(arr);
        ll ans = ans1;
        ans = min(ans, ans3);
        ans = min(ans, ans2);
        ans = min(ans, ans4);
        cout << ans << endl;
    }
    return 0;
}