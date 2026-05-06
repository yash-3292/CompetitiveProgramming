#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n;
        cin >> s;
        int flag = 0;
        int low = 0;
        int high = s.size()-1;
        int pall = 1;
        while(low <= high){
            if(s[low] < s[high]){
                pall = 0;
                break;
            }
            else if(s[low] > s[high]){
                pall = 0;
                flag = 1;
                break;
            }
            low++;
            high--;
        }
        if(pall || n%2 == flag){
            cout << s << endl;
            continue;
        } 
        string t = s;
        reverse(t.begin(),t.end());
        if(flag == 0){
            s = s.append(t);
            cout << s << endl;
        } else{
            t = t.append(s);
            cout << t << endl;
        }
    }
    return 0;
}
