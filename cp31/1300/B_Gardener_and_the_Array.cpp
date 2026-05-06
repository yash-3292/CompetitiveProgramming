#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        map<int,int> mpp;
        vector<vector<int>> arr;
        for(int i=0; i<n; i++){
            int k;
            cin >> k;
            vector<int> arr1(k);
            for(int j=0; j<k; j++){
                cin >> arr1[j];
                mpp[arr1[j]]++;
            }
            arr.push_back(arr1);
        }
        int flagi = 0;
        for(int i=0; i<n; i++){
            int k = arr[i].size();
            int flag = 1;
            for(int j=0; j<k; j++){
                if(mpp[arr[i][j]] == 1){
                    flag = 0;
                    break;
                }
            }
            if(flag){
                flagi = 1;
                break;
            }
        }
        if(flagi) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}