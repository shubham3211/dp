#include <iostream>
#include <algorithm>
using namespace std;
int gsr(int n){
	if(n==1){
		return 1;
	}
	int ans;
	return 1+gsr(n-gsr(gsr(n-1)));
}
void pgsr(int n){
	for(int i=1;i<=n;i++){
		cout<<gsr(i)<<" ";
	}
}
int gsrd(int n){
	int dp[100]={0};
	for(int i=1;i<=n;i++){
		dp[i]=1+dp[i-dp[dp[i-1]]];
	}
	for(int i=1;i<=n;i++){
		cout<<dp[i]<<" ";
	}
}
int main(){
	int ans,n;
	cout<<"Enter the value of n";
	cin>>n;
	gsrd(n);

}