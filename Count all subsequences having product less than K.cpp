#include <iostream>
using namespace std;
int max_product(int *arr,int n,int k){
	int dp[100][100]={0};
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			if(arr[i-1]<=j&&arr[i-1]>0){
				dp[i][j]=1+dp[i-1][j/arr[i-1]];
			}
			dp[i][j]+=dp[i-1][j];
		}
	}
	return dp[n][k];
}
int main(){
	int n,arr[100],ans=0,k;
	cout<<"Enter the value of n";
	cin>>n;
	cout<<"Enter the value of k";
	cin>>k;
	cout<<"Enter the elements";
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	ans=max_product(arr,n,k);
	cout<<ans;
}