#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int longest_subsquence(int *arr,int n){
	int dp[100];
	// memset(dp,1,sizeof(dp));
	dp[0]=1;
	for(int i=1;i<n;i++){
		dp[i]=1;
		for(int j=0;j<i;j++){
			if(abs(arr[i]-arr[j])==1){
				dp[i]=max(dp[i],dp[j]+1);
			}
		}
	}
	return dp[n-1];
}
int main(){
	int arr[100],n,ans;
	cout<<"Enter the value of n";
	cin>>n;
	cout<<"Enter the elements";
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	ans=longest_subsquence(arr,n);
	cout<<ans;
}