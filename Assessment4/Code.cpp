long long hello(vector<int>&arr){
    long long mod=1e9+7;
    long long n=arr.size();
    long long ans=0;
    for(int b=0;b<32;b++){
         long long one=0;
        for(int i=0;i<n;i++){
            if(arr[i]&(i<<b))one++;
        }
        long long zeroes=n-one;
        ans =  (ans+ ((one+zeroes)%mod)*2);
    }
    return ans;
}
