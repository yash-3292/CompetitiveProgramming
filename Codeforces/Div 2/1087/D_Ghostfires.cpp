#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        vector<pair<int,char>> arr(3);
        for(int i=0; i<3; i++){
            cin >> arr[i].first;
        }
        arr[0].second = 'R';
        arr[1].second = 'G';
        arr[2].second = 'B';
        sort(arr.begin(), arr.end(), greater<pair<int,char>>());
        vector<int> ans;
        for(int i=0; i<arr[0].first-1; i++){
            if(ans.empty()) ans.push_back(0);
            else{
                if(ans.back() != 0) ans.push_back(0);
                else break;
            }
            if(arr[1].first == 0 && arr[2].first == 0) continue;
            if(arr[1].first >= arr[2].first){
                ans.push_back(1);
                arr[1].first--;
            } else{
                ans.push_back(2);
                arr[2].first--;
            }
        }
        if(ans.empty() || ans.back() != 0) ans.push_back(0);
        int prev = -1;
        if(ans.size() >= 3){
            prev = ans[ans.size()-2];
        }
        if(arr[1].first && (prev == -1 || prev == 1)){
            ans.push_back(1);
            arr[1].first--;
        } else if(arr[2].first && (prev == -1 || prev == 2)){
            ans.push_back(2);
            arr[2].first--;
        }
        while(true){
            if(ans.back() == 1){
                if(arr[2].first){
                    ans.push_back(2);
                    arr[2].first--;
                } else break;
            } else{
                if(arr[1].first){
                    ans.push_back(1);
                    arr[1].first--;
                } else break;
            }
        }
        if(arr[1].first) cout << arr[1].second;
        else if(arr[2].first) cout << arr[2].second;
        for(auto it : ans) cout << arr[it].second;
        cout << endl;
    }
    return 0;
}