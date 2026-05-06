#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        vector<pair<int,int>> ans;
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n; i++) cin >> b[i];
        bool swapped = false;
        for (int i = 0; i < n - 1; i++) {
            swapped = false;
            for (int j = 0; j < n - i - 1; j++) {
                if (a[j] > a[j + 1]) {
                    swap(a[j], a[j + 1]);
                    ans.push_back(make_pair(1,j+1));
                    swapped = true;
                }
            }
            if (!swapped) break;
        }
        for (int i = 0; i < n - 1; i++) {
            swapped = false;
            for (int j = 0; j < n - i - 1; j++) {
                if (b[j] > b[j + 1]) {
                    swap(b[j], b[j + 1]);
                    ans.push_back(make_pair(2,j+1));
                    swapped = true;
                }
            }
            if (!swapped) break;
        }
        for(int i=0; i<n; i++){
            if(a[i] > b[i]){
                swap(a[i], b[i]);
                ans.push_back(make_pair(3,i+1));
            }
        }
        // for(auto it : a) cout << it << " ";
        // cout << endl;
        // for(auto it : b) cout << it << " ";
        // cout << endl << endl;
        int size = ans.size();
        cout << size << endl;
        for(pair<int,int> val : ans){
            cout << val.first << " " << val.second << endl;
        }
    }
    return 0;
}