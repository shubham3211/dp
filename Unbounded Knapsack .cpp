#include <iostream>
using namespace std;
int uKnapsack(int *weight,int *val,int totalWeight,int n){
	if(n==0||totalWeight==0){
		return 0;
	}
	int val1,val2=0,val3=0;
	val1=uKnapsack(weight,val,totalWeight,n-1);
	if(totalWeight-weight[n-1]>=0){
		val2=val[n-1]+uKnapsack(weight,val,totalWeight-weight[n-1],n);
		val3=val[n-1]+uKnapsack(weight,val,totalWeight-weight[n-1],n-1);
	}
	return max(val1,max(val2,val3));
}
int uKnapsackRecur(int *weight,int *val,int totalWeight,int n){
	if(totalWeight==0){
		return 0;
	}
	int ans=0;
	for(int i=0;i<n;i++){
		if(totalWeight-weight[i]>=0)
		ans=max(ans,val[i]+uKnapsack(weight,val,totalWeight-weight[i],n));
	}
	return ans;
}
int uKnapsackDp1(int *weight,int *val,int totalWeight,int n){
	int dp[400]={0};
	for(int i=0;i<=totalWeight;i++){
		for(int j=0;j<n;j++){
			if(weight[j]<=i){
				dp[i]=max(dp[i],dp[i-weight[j]]+val[j]);
			}
		}
	}
	return dp[totalWeight];	
}
int uKnapsackDp(int *weight,int *val,int totalWeight,int n){
	int knap[700][700];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=totalWeight;j++){
			if(i==0||j==0){
				knap[i][j]=0;
			}
			else{
				knap[i][j]=knap[i-1][j];
				for(int k=1;j-(weight[i-1]*k)>=0;k++){
					knap[i][j]=max(knap[i][j],val[i-1]*k+knap[i-1][j-weight[i-1]*k]);
				}
			}
		}
	}
	// for(int i=0;i<=n;i++){
	// 	for(int j=0;j<=totalWeight;j++){	
	// 		cout<<knap[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	return knap[n][totalWeight];
}
int main(){
	int weight[100],val[100],totalWeight=0,n,ans;
	cout<<"Enter the number of elements";
	cin>>n;
	cout<<"Enter the weights of the items";
	for(int i=0;i<n;i++){
		cin>>weight[i];
	}
	cout<<"Enter the price of the items";
	for(int i=0;i<n;i++){
		cin>>val[i];
	}
	cout<<"Enter the totalWeight";
	cin>>totalWeight;
	ans=uKnapsackDp1(weight,val,totalWeight,n);
	cout<<ans;
}