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
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        vector<int> freq(n);
        map<int,int> mpp;
        int maxi = 1;
        for(int i=n-1; i>=0; i--){
            mpp[arr[i]]++;
            freq[i] = mpp[arr[i]];
            if(freq[i] > maxi) maxi = freq[i];
            else if(freq[i] < maxi){
                maxi = freq[i];
                for(int j=i+1; j<n; j++){
                    if(freq[j] <= freq[i]) break;
                    freq[j] = freq[i];
                    mpp[arr[j]] = freq[i];
                }
            }
        }
        cout << maxi << endl;
    }
    return 0;
}