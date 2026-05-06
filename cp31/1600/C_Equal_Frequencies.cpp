#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<pair<int,int>> arr(26);
        for(int i=0; i<26; i++){
            arr[i].first = 0;
            arr[i].second = i;
        }
        for(int i=0; i<n; i++) arr[s[i]-'a'].first++;
        sort(arr.begin(), arr.end());
        reverse(arr.begin(), arr.end());
        int ans = -1;
        int mini = INT_MAX;
        for(int i=1; i<=26; i++){
            if(n%i == 0){
                int element = n/i;
                int cnt = 0;
                for(int j=0; j<i; j++){
                    if(arr[j].first < element) cnt += element - arr[j].first;
                }
                if(cnt < mini){
                    ans = i;
                    mini = cnt;
                }
            }
        }
        vector<pair<char,int>> take;
        vector<int> skip(26,0);
        for(int i=0; i<26; i++){
            int element = n/ans;
            if(i < ans){
                if(arr[i].first >= element) skip[arr[i].second] =  arr[i].first - element;
                else take.push_back({arr[i].second+'a', element - arr[i].first});
            } else{
                skip[arr[i].second] = arr[i].first;
            }
        }
        string t = s;
        for(int i=0; i<n; i++){
            if(skip[t[i]-'a'] > 0){
                skip[t[i]-'a']--;
                t[i] = take.back().first;
                take.back().second--;
                if(take.back().second <= 0) take.pop_back();
            }
        }
        cout << mini << endl;
        cout << t << endl;
    }
    return 0;
}