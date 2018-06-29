#include <iostream>
#include <vector>
using namespace std;
int n;
bool partition(int arr[],int pos,int sum1,int sum2,vector<int> v1,vector<int>v2){
	if(pos==n){
		if(sum1==sum2){
			for(vector<int>::iterator it=v1.begin();it!=v1.end();it++){
			cout<<*it<<" ";
			}
			cout<<endl;
			for(vector<int>::iterator it=v2.begin();it!=v2.end();it++){
			cout<<*it<<" ";
			}
			cout<<endl;
			return true;
		} else {
			return 0;
		}
	} 
	int ans1=0,ans2=0;
	v1.push_back(arr[pos]);
	ans1=partition(arr,pos+1,sum1+arr[pos],sum2,v1,v2);
	if(ans1) {
		return true;
	}
	v2.push_back(arr[pos]);
	v1.pop_back();
	ans2=partition(arr,pos+1,sum1,sum2+arr[pos],v1,v2);
	return ans1||ans2;
}
void printPositions(int dp[][100],int i,int j,vector<int> v1,vector<int> v2,int arr[]){
	if(i==0){
		for(vector<int>::iterator it=v1.begin();it!=v1.end();it++){
			cout<<*it<<" ";
		}		
		cout<<endl;
		for(vector<int>::iterator it=v2.begin();it!=v2.end();it++){
			cout<<*it<<" ";
		}		
		cout<<endl;
		return;
	} 
	if(j>=arr[i-1] && dp[i-1][j-arr[i-1]]){
		v1.push_back(arr[i-1]);
		printPositions(dp,i-1,j-arr[i-1],v1,v2,arr);
		v1.pop_back();
	} else if(dp[i-1][j]){
		v2.push_back(arr[i-1]);
		printPositions(dp,i-1,j,v1,v2,arr);
	}
}
bool partitionDp(int arr[],int sum){
	int dp[100][100]={0};
	for(int i=0;i<=n;i++){
		dp[i][0]=true;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=sum;j++){
			if(j>=arr[i-1]){
				dp[i][j]=dp[i-1][j]||dp[i-1][j-arr[i-1]];	
			} else{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	std::vector<int> v1,v2;
	printPositions(dp,n,sum,v1,v2,arr);
	return dp[n][sum];
}
int main(){
	int arr[199],ans,sum=0;
	vector<int> v1,v2;
	cout<<"Enter the number of elements";
	cin>>n;
	cout<<"Enter the elements";
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	for(int i=0;i<n;i++){
		sum+=arr[i];
	}
	// if(sum%2==0){
	// 	ans=partition(arr,0,0,0,v1,v2);
	// 	if(ans){
	// 	cout<<"Yes"<<endl;
	// 	} else{
	// 	cout<<"No"<<endl;
	// 	}
	// } else{
	// 	cout<<"No"<<endl;
	// }

	if(sum%2==0){
		// cout<<sum;
		ans=partitionDp(arr,sum/2);
		if(ans){
		cout<<"Yes";
		} else{
		cout<<"No";
		}
	} else{
		cout<<"No";
	}
}