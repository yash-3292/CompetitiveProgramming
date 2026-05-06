#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> x(n);
        vector<int> y(n);
        for(int i=0; i<n; i++) cin >> x[i];
        for(int i=0; i<n; i++) cin >> y[i];
        vector<int> arr(n);
        for(int i=0; i<n; i++) arr[i] = y[i] - x[i];
        sort(arr.begin(), arr.end());
        int i = 0;
        int j = n-1;
        int ans = 0;
        while(arr[i] < 0 && i < j){
            if(abs(arr[i]) <= arr[j]){
                ans += 1;
                i++;
                j--;
            } else{
                i++;
            }
        }
        if(j - i + 1 >= 2){
            int num = j - i + 1;
            ans += num/2;
        }
        cout << ans << endl;
    }
    return 0;
}