#include<bits/stdc++.h>
using namespace std;
bool check(string &s1,string &s2){
    int x=min(s1.size(),s2.size());

    for(int i=0;i<x;i++){
        if(s1[i]==s2[i])return false;
    }
    return true;
}
int main(){
    vector<string>ans = {"a","aa","aaa"};
    unsigned int maxi=0;
    int n=ans.size();

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j)continue;

            if(check(ans[i],ans[j])){
                    maxi=max(maxi,ans[i].size()*ans[j].size());
            }
        }
    }
    cout<<maxi;

}
