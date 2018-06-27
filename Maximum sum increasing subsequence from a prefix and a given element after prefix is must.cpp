#include <iostream>
using namespace std;
int max_sum(int *arr,int n,int index,int k){
	int dp[100]={0};
	dp[0]=arr[0];
	for(int i=1;i<=index;i++){
		for(int j=0;j<i;j++){
			if(arr[i]>arr[j]){
				dp[i]=max(dp[i],dp[j]+arr[i]);
			}
		}
	}
	for(int i=0;i<=index;i++){
		if(arr[k]>arr[i]){
			dp[index+1]=max(dp[index+1],dp[i]+arr[k]);
		}
	}
	return dp[index+1];
}
int main(){
	int n,index,k,arr[100],ans;
	cout<<"Enter the value of n";
	cin>>n;
	cout<<"Enter the value of index";
	cin>>index;
	cout<<"Enter the value of k";
	cin>>k;
	cout<<"Enter the elements";
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	ans=max_sum(arr,n,index,k);
	cout<<ans;		
}