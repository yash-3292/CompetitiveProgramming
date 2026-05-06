#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    vector<ll> sum(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    sum[0] = (ll)arr[0];
    for(int i=1; i<n; i++){
        sum[i] = sum[i-1] + (ll)arr[i];
    }
    ll summ = 0;
    for(int i=0; i<=n-k; i++){
        summ += sum[i+k-1];
        if(i != 0) summ -= sum[i-1];
    }
    double ans = (double)summ / (double)(n-k+1);
    printf("%.10lf\n", ans);
    return 0;
}