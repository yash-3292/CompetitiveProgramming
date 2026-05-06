#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    vector<pair<int,int>> crosses;
    vector<pair<int,int>> temp1;
    vector<pair<int,int>> temp2;
    int flag = 1;
    int row = n;
    for(int i=n-1; i>=0; i--){
        if(arr[i] == 0) continue;
        if(arr[i] == 1){
            if(row < 0){
                flag = 0;
                break;
            }
            crosses.push_back({row, i+1});
            temp1.push_back({row,i+1});
            row--;
            continue;
        }
        if(arr[i] == 2){
            if(temp1.empty()){
                flag = 0;
                break;
            } else{
                crosses.push_back({temp1.back().first, i+1});
                temp2.push_back({temp1.back().first, i+1});
                temp1.pop_back();
            }
            continue;
        }
        if(arr[i] == 3){
            if(!temp2.empty()){
                if(row < 0){
                    flag = 0;
                    break;
                }
                crosses.push_back({row, i+1});
                crosses.push_back({row, temp2.back().second});
                temp2.pop_back();
                temp2.push_back({row,i+1});
                row--;
            } else if(!temp1.empty()){
                if(row < 0){
                    flag = 0;
                    break;
                }
                crosses.push_back({row, i+1});
                crosses.push_back({row, temp1.back().second});
                temp1.pop_back();
                temp2.push_back({row,i+1});
                row--;
            } else{
                flag = 0;
                break;
            }
        }
    }
    if(!flag){
        cout << -1 << endl;
        return 0;
    }
    if(crosses.size() > 2*n){
        cout << -1 << endl;
        return 0;
    }
    cout << crosses.size() << endl;
    for(auto it : crosses) cout << it.first << " " << it.second << endl;
    return 0;
}