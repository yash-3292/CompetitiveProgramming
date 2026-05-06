#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool f(int val, vector<int> freq){
    int temp = val;
    while(temp > 9){
        int sum = 0;
        while(temp){
            int d = temp%10;
            if(!freq[d]) return false;
            freq[d]--;
            sum += d;
            temp /= 10;
        }
        temp = sum;
    }
    if(!freq[temp]) return false;
    freq[temp]--;
    int sum = 0;
    for(int i=0; i<10; i++) sum += freq[i]*i;
    return sum == val;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        vector<int> freq(10, 0);
        int n = s.size();
        if(n == 1){
            cout << s << endl;
            continue;
        }
        int ans = -1;
        for(int i=0; i<n; i++) freq[s[i]-'0']++;
        for(int i=1; i<=9*n; i++){
            if(f(i, freq)){
                ans = i;
                break;
            }
        }
        string t;
        int temp = ans;
        while(temp > 9){
            int sum = 0;
            string r;
            while(temp){
                int d = temp%10;
                r += d+'0';
                freq[d]--;
                sum += d;
                temp /= 10;
            }
            temp = sum;
            reverse(r.begin(), r.end());
            t += r;
        }
        t += temp+'0';
        freq[temp]--;
        for(int i=9; i>=0; i--){
            while(freq[i]){
                freq[i]--;
                cout << i;
            }
        }
        cout << t << endl;
    }
    return 0;
}