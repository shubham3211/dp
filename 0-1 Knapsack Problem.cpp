#include <iostream>
using namespace std;
int knapsackRecur(int *weight,int *val,int totalWeight,int n){
	if(n==0||totalWeight==0){
		return 0;
	}
	int val1=0,val2=0;
	val1=knapsackRecur(weight,val,totalWeight,n-1);
	if(totalWeight-weight[n-1]>=0){
		val2=knapsackRecur(weight,val,totalWeight-weight[n-1],n-1)+val[n-1];
	}
	return max(val1,val2);
}
int knapsackDp(int *weight,int *val,int totalWeight,int n){
	int knap[100][100];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=totalWeight;j++){
			if(i==0||j==0){
				knap[i][j]=0;
			} else if(weight[i-1]<=j){
				knap[i][j]=max(knap[i-1][j],knap[i-1][j-weight[i-1]]+val[i-1]);
			} else{
				knap[i][j]=knap[i-1][j];
			}
		}
	}
	return knap[n][totalWeight];
}
void printDP(int *weight,int *val,int totalWeight,int n){
	int knap[100][100];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=totalWeight;j++){
			if(i==0||j==0){
				knap[i][j]=0;
			} else if(weight[i-1]<=j){
				knap[i][j]=max(knap[i-1][j],knap[i-1][j-weight[i-1]]+val[i-1]);
			} else{
				knap[i][j]=knap[i-1][j];
			}
		}
	}
	int ans=knap[n][totalWeight];
	cout<<ans<<" "<<endl;
	for(int i=n;i>0;i--){
		if(knap[i][totalWeight]==val[i-1]+knap[i-1][totalWeight-weight[i-1]]){
			totalWeight-=weight[i-1];
			cout<<weight[i-1]<<" ";
		}
	}
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
	printDP(weight,val,totalWeight,n); 
	
}