#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int> arr(n);
        vector<int> freq(m, 0);
        for(int i=0; i<n; i++){
            cin >> arr[i];
            freq[arr[i]%m]++;
        }
        int cnt = 0;
        if(freq[0] > 0) cnt++;
        int i = 1;
        int j = m-1;
        while(i <= j){
            if(i == j){
                if(freq[i] > 0) cnt++;
            } else{
                if(freq[i] > 0 || freq[j] > 0){
                    cnt++;
                    if(freq[i] != freq[j])
                        cnt += abs(freq[i] - freq[j]) - 1;
                }
            }
            i++;
            j--;
        }
        cout << cnt << endl;
    }
    return 0;
}