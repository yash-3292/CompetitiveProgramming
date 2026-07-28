#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

pair<int,int> f(vector<int>& arr){
    int n = arr.size();
    map<int,int> vis;
    vis[arr[0]] = 0;
    for(int i=1; i<n; i++){
        if(arr[i] != arr[i-1]){
            if(vis.find(arr[i]) != vis.end()){
                return {vis[arr[i]], i};
            } else{
                vis[arr[i]] = i;
            }
        }
    }
    return {-1,-1};
}

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    pair<int,int> ans = f(arr);
    if(ans.first == -1){
        cout << "YES" << endl;
        return;
    }
    int single1 = 1;
    int single2 = 1;
    if(ans.first != 0 && arr[ans.first-1] == arr[ans.first]) single1 = 0;
    if(ans.first != n-1 && arr[ans.first+1] == arr[ans.first]) single1 = 0;
    if(ans.second != 0 && arr[ans.second-1] == arr[ans.second]) single2 = 0;
    if(ans.second != n-1 && arr[ans.second+1] == arr[ans.second]) single2 = 0;
    if(single1){
        if(ans.second-1 >= 0){
            swap(arr[ans.first], arr[ans.second-1]);
            pair<int,int> val = f(arr);
            if(val.first == -1){
                cout << "YES" << endl;
                return;
            }
            swap(arr[ans.first], arr[ans.second-1]);
        }
        int j = ans.second+1;
        while(j < n){
            if(arr[j-1] != arr[j]) break;
            j++;
        }
        if(j < n){
            swap(arr[ans.first], arr[j]);
            pair<int,int> val = f(arr);
            if(val.first == -1){
                cout << "YES" << endl;
                return;
            }
            swap(arr[ans.first], arr[j]);
        }
    }
    if(single2){
        if(ans.first-1 >= 0){
            swap(arr[ans.second], arr[ans.first-1]);
            pair<int,int> val = f(arr);
            if(val.first == -1){
                cout << "YES" << endl;
                return;
            }
            swap(arr[ans.second], arr[ans.first-1]);
        }
        int j = ans.first+1;
        while(j < n){
            if(arr[j-1] != arr[j]) break;
            j++;
        }
        if(j < n){
            swap(arr[ans.second], arr[j]);
            pair<int,int> val = f(arr);
            if(val.first == -1){
                cout << "YES" << endl;
                return;
            }
            swap(arr[ans.second], arr[j]);
        }
    }
    int flag = 1;
    for(int i=ans.first; i<ans.second-1; i++){
        if(arr[ans.first] != arr[i]){
            flag = 0;
            break;
        }
    }
    if(flag){
        int j1 = ans.second+1;
        while(j1 < n){
            if(arr[j1-1] != arr[j1]) break;
            j1++;
        }
        j1--;
        int ind = -1;
        for(int i=0; i<n; i++){
            if(i < ans.first || i > j1){
                if(arr[i] == arr[ans.first]){
                    ind = i;
                    break;
                }
            }
        }
        if(ind != -1){
            swap(arr[ans.second-1], arr[ind]);
            pair<int,int> val = f(arr);
            if(val.first == -1){
                cout << "YES" << endl;
                return;
            }
            swap(arr[ans.second-1], arr[ind]);
        } else{
            swap(arr[ans.second-1], arr[ans.first]);
            pair<int,int> val = f(arr);
            if(val.first == -1){
                cout << "YES" << endl;
                return;
            }
            swap(arr[ans.second-1], arr[ans.first]);

            swap(arr[ans.second-1], arr[j1]);
            pair<int,int> val1 = f(arr);
            if(val1.first == -1){
                cout << "YES" << endl;
                return;
            }
            swap(arr[ans.second-1], arr[j1]);
        }
    }
    cout << "NO" << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}