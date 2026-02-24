#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

struct Job{
    int id;
    int deadline;
    int profit;
};

bool compare(Job &a, Job &b){
    return a.deadline < b.deadline;
}

int main(){
    vector<Job> v = {{1,2,100},{2,1,19},{3,2,27},{4,1,25},{5,1,15}};
    
    sort(v.begin(), v.end(), compare);

    priority_queue<int, vector<int>, greater<int>> pq;
    int max_profit = 0;

    for(int i = 0; i < v.size(); i++){
        pq.push(v[i].profit);
        max_profit += v[i].profit;

        if(pq.size() > v[i].deadline){
            max_profit -= pq.top();
            pq.pop();
        }
    }

    cout<<"Max profit is: "<<max_profit<<endl;
}
