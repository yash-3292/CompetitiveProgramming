#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isSmall(vector<int>& a, vector<int>& b, unordered_map<int,int>& numComp){
    int i = 0;
    int j = 0;
    int n = a.size();
    int m = b.size();
    unordered_map<int,int> prev;
    while(i < n && j < m){
        if(numComp.find(a[i]) != numComp.end() || prev.find(a[i]) != prev.end()){
            i++;
            continue;
        }
        if(numComp.find(b[j]) != numComp.end() || prev.find(b[j]) != prev.end()){
            j++;
            continue;
        }
        if(a[i] < b[j]) return true;
        else if(a[i] > b[j]) return false;
        prev[a[i]] = 1;
        i++;
        j++;
    }
    if(i == n) return true;
    else return false;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>> arr(n);
        for(int i=0; i<n; i++){
            int l;
            cin >> l;
            for(int j=0; j<l; j++){
                int x;
                cin >> x;
                arr[i].push_back(x);
            }
            reverse(arr[i].begin(), arr[i].end());
        }
        unordered_map<int,int> numComp;
        vector<int> blogComp(n, 0);
        for(int i=0; i<n; i++){
            int smallBlog;
            int j = 0;
            while(blogComp[j]) j++;
            smallBlog = j;
            j++;
            while(j < n){
                if(blogComp[j]){
                    j++;
                    continue;
                }
                if(isSmall(arr[j], arr[smallBlog], numComp)) smallBlog = j;
                j++;
            }
            blogComp[smallBlog] = 1;
            for(auto val : arr[smallBlog]){
                if(numComp.find(val) == numComp.end()){
                    cout << val << " ";
                    numComp[val] = 1;
                }
            }
        }
        cout << endl;
    }
    return 0;
}