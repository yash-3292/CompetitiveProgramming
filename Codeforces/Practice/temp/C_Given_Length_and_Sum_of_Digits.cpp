#include<bits/stdc++.h>
using namespace std;

int main(){
    int m, s;
    cin >> m >> s;
    if(s == 0){
        if(m == 1) cout << "0 0" << endl;
        else cout << "-1 -1" << endl;
        return 0;
    }
    string maxsum;
    maxsum += '1';
    for(int i=0; i<m-1; i++){
        maxsum += '0';
    }
    string minsum = maxsum;
    int temp = s-1;
    for(int i=0; i<m; i++){
        if(!temp) break;
        if(maxsum[i] == '1'){
            if(temp >= 8){
                maxsum[i] = '9';
                temp -= 8;
            } else{
                maxsum[i] = (char)(maxsum[i]+temp);
                temp = 0;
            }
        } 
        else{
            if(temp >= 9){
                maxsum = '9';
                temp -= 9;
            } else{
                maxsum[i] = (char)(maxsum[i]+temp);
                temp = 0;
            }
        }
    }
    if(temp){
        cout << -1 << " " << -1 << endl;
        return 0;
    }
    temp = s-1;
    for(int i=m-1; i>=0; i--){
        if(!temp) break;
        if(maxsum[i] == '1'){
            if(temp >= 8){
                maxsum[i] += 8;
                temp -= 8;
            } else{
                maxsum[i] += temp;
                temp = 0;
            }
        } 
        else{
            if(temp >= 9){
                maxsum[i] += 9;
                temp -= 9;
            } else{
                maxsum[i] += temp;
                temp = 0;
            }
        }
    }
    cout << minsum << " " << maxsum << endl;
    return 0;
}