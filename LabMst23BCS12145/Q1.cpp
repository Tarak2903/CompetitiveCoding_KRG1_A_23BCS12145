#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<vector<int>> tasks;
    tasks.push_back({1,3});
    tasks.push_back({2,4});
    tasks.push_back({10,11});
    tasks.push_back({10,12});
    tasks.push_back({8,9});

    sort(tasks.begin(), tasks.end(), [](vector<int> &a, vector<int> &b){
        return (b[1]-b[0]) < (a[1]-a[0]);
    });

    int currEnergy = 0;
    int ans = 0;

    for(int i=0;i<tasks.size();i++){

        int actual = tasks[i][0];
        int minimum = tasks[i][1];

        if(currEnergy < minimum){
            ans += minimum - currEnergy;
            currEnergy = minimum;
        }

        currEnergy -= actual;
    }
cout<<ans;
}
