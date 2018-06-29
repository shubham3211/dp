#include <iostream>
#include <algorithm>
using namespace std;
int n;
int high_low(int low[],int high[],int pos,int status){
	if(pos==n){
		return 0;
	}
	int ans1=0,ans2=0,ans3=0;
	ans1=low[pos]+high_low(low,high,pos+1,1);
	if(!status){
		ans2=high[pos]+high_low(low,high,pos+1,1);
	}
	ans3=high_low(low,high,pos+1,0);
	return max(ans1,max(ans2,ans3));
}
int high_low_dp(int low[],int high[]){
	int dp[100]={0};
	dp[0]=high[0];
	dp[1]=max(high[1],low[1]+high[0]);
	for(int i=2;i<n;i++){
		int ans1=0,ans2=0;
		//last time nothing happened
		ans1=dp[i-2]+high[i];
		//last time low or high happened
		ans2=dp[i-1]+low[i];
		dp[i]=max(ans1,ans2);
	}
	return dp[n-1];
}
int main(){
	int low[100],high[100],ans;
	cout<<"Enter the number of elements";
	cin>>n;
	cout<<"Enter lower values";
	for(int i=0;i<n;i++){
		cin>>low[i];
	}
	cout<<"Enter higher values";
	for(int i=0;i<n;i++){
		cin>>high[i];
	}
	// ans=high_low(low,high,0,0);
	ans=high_low_dp(low,high);
	cout<<ans<<endl;
}