#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        sort(arr.begin(), arr.end());
        vector<int> freq1(n+1, 0);
        vector<int> freq2(n+1, 0);
        for(int i=0; i<n; i++) freq2[arr[i]]++;
        int flag = 1;
        for(int i=0; i<n-1; i++){
            freq1[arr[i]]++;
            freq2[arr[i]]--;
            int a1 = -1;
            int a2 = -1;
            for(int j=0; j<=n; j++){
                if(freq1[j] == 0){
                    a1 = j;
                    break;
                }
            }
            for(int j=0; j<=n; j++){
                if(freq2[j] == 0){
                    a2 = j;
                    break;
                }
            }
            if(a1 == a2){
                flag = 0;
                break;
            }
        }
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}