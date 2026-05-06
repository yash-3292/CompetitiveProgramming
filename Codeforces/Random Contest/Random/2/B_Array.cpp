#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    map<int,int> mpp;
    for(int i=0; i<n; i++) mpp[arr[i]]++;

    if(mpp.size() < k){
        cout << -1 << " " << -1 << endl;
        return 0;
    }

    int l = 0;
    int r = n-1;

    while(l < r){
        if(mpp.size() > k){
            mpp[arr[l]]--;
            if(mpp[arr[l]] == 0){
                mpp.erase(arr[l]);
            }
        } else{
            if(mpp[arr[l]] > 1){
                mpp[arr[l]]--;
            } else{
                break;
            }
        }
        l++;
    }

    while(l < r){
        if(mpp.size() > k){
            mpp[arr[r]]--;
            if(mpp[arr[r]] == 0){
                mpp.erase(arr[r]);
            }
        } else{
            if(mpp[arr[r]] > 1){
                mpp[arr[r]]--;
            } else{
                break;
            }
        }
        r--;
    }

    cout << l+1 << " " << r+1 << endl;
    return 0;
}