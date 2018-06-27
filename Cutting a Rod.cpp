#include <iostream>
#include <algorithm>
using namespace std;
int maxPriceRecur(int arr[],int length,int price,int n){
	int maximum = 0;
	if(length<=0){
		return price;
	}
	for(int i=1;i<=n;i++){
		if(i<=length){
			maximum = max(maximum,maxPriceRecur(arr,length-i,price+arr[i-1],n));
		}
	}
	return maximum;
}

int maxPriceDp(int arr[],int length){
	int dp[100] = {0},maximum = 0;
	for(int i=1;i<=length;i++){
		for(int j=0;j<i;j++){
			dp[i] = max(dp[i],arr[j]+dp[i-j-1]);
		}
	}
	return dp[length-i];
}

int main(){
	int arr[100],length,ans,mainLength;
	cout<<"Enter the length of array";
	cin>>length;
	cout<<"enter the elements";
	for(int i=0;i<length;i++){
		cin>>arr[i];
	}
	// cout<<"Enter the mainLength";
	// cin>>mainLength;
	ans = maxPriceDp(arr,length);
	cout<<ans;
}