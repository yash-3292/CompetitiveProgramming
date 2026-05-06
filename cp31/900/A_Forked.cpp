#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int g=0; g<t; g++){
        int a, b;
        pair<int,int> king;
        pair<int,int> queen;
        cin >> a >> b;
        cin >> king.first >> king.second;
        cin >> queen.first >> queen.second;
        vector<pair<int,int>> point;
        if(a != b){
            point = {{a,b},{a,-b},{-a,b},{-a,-b},{b,a},{b,-a},{-b,a},{-b,-a}};
        }
        else{
            point = {{a,b},{a,-b},{-a,b},{-a,-b}};
        }
        int total = 0;
        for(auto val : point){
            pair<int,int> temp = {val.first+king.first, val.second+king.second};
            int flag = 0;
            for(auto val : point){
                pair<int,int> temp1 = {val.first+temp.first, val.second+temp.second};
                if(temp1.first == queen.first && temp1.second == queen.second){
                    flag = 1;
                    break;
                }
            }
            total += flag;
        }
        cout << total << endl;
    }
    return 0;
}