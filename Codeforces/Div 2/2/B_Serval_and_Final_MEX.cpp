#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    for(int g=0; g<t; g++){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        int l, r;
        int i=0;
        vector<pair<int, int>> ans;
        while(i < arr.size()){
            if(arr[i] > 0){
                i++;
            } else if(arr[i] == 0){
                if(i=0){
                    l=i+1, r=i+2;
                    ans.push_back({l,r});
                    arr.erase(arr.begin() + i);
                    arr.erase(arr.begin() + i + 1);
                    arr.insert(arr.begin() + i, 1);
                } else if(i == arr.size()-1){
                    l=i, r=i+1;
                    ans.push_back({l,r});
                    arr.erase(arr.begin() + i-1);
                    arr.erase(arr.begin() + i);
                    arr.insert(arr.begin() + i-1, 1);
                } else{
                    if(arr[i-1] == 0){
                        l=i, r=i+1;
                        ans.push_back({l,r});
                        arr.erase(arr.begin() + i-1);
                        arr.erase(arr.begin() + i);
                        arr.insert(arr.begin() + i-1, 1);
                    } else if(arr[i+1] == 0){
                        l=i+1, r=i+2;
                        ans.push_back({l,r});
                        arr.erase(arr.begin() + i);
                        arr.erase(arr.begin() + i + 1);
                        arr.insert(arr.begin() + i, 1);
                    } else{
                        l=i+1, r=i+2;
                        ans.push_back({l,r});
                        arr.erase(arr.begin() + i);
                        arr.erase(arr.begin() + i + 1);
                        arr.insert(arr.begin() + i, 1);
                    }
                    i = l-1;
                }
            }
        }
        ans.push_back({1,arr.size()});
        cout << ans.size() << endl;
        for(int i=0; i<ans.size(); i++){
            cout << ans[i].first << " " << ans[i].second << endl;
        }
    }
    return 0;
}