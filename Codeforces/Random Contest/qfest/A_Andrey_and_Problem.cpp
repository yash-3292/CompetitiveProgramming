#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<double> arr(n);
    double maxi = 0;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    for(int k=0; k<n; k++){
        double ans = 0;
        for(int i=k; i<n; i++){
            double cnt = arr[i];
            for(int j=k; j<n; j++){
                if(i==j) continue;
                cnt *= (double)((double)1-arr[j]);
            }
            ans += cnt;
        }
        maxi = max(maxi, ans);
    }
    
    cout.setf(ios::fixed);
    cout << setprecision(12) << maxi << "\n";
    return 0;
}
