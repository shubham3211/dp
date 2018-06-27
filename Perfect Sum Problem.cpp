#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void perfectSumRecur(vector<int> v,vector<int> mainEle,int sum,int length){
	int sum1=0;
	for(vector<int>::iterator it=mainEle.begin();it!=mainEle.end();it++){
		sum1+=*it;
	}
	if(sum1==sum){
		for(vector<int>::iterator it=mainEle.begin();it!=mainEle.end();it++){
			cout<<*it<<" ";
		}
		cout<<endl;
		return;
	}
	if(sum1>sum || length>=v.size()){
		return;
	}
	perfectSumRecur(v,mainEle,sum,length+1);
	mainEle.push_back(v[length]);
	perfectSumRecur(v,mainEle,sum,length+1);	
}

void printEle(vector<int> v){
	for(std::vector<int>::iterator it =v.begin();it!=v.end();it++){
		cout<<*it<<" ";
	}
	cout<<endl;
}

void printList(vector<int> v,vector<int> mainEle,int sum , int row,bool dp[100][100]){

	if(row==0 && dp[0][sum]){
		printEle(mainEle);
		return;
	}

	if(dp[row-1][sum]){
		printList(v,mainEle,sum,row-1,dp);
	}

	if(sum>=v[row-1]&&dp[row-1][sum-v[row-1]]){
		mainEle.push_back(v[row-1]);
		printList(v,mainEle,sum-v[row-1],row-1,dp);
	}
}

bool perfectSumDp(vector<int> v,int sum){
	bool dp[100][100];
	std::vector<int> mainEle;
	for(int i=0;i<=sum;i++){
		dp[0][i] = false;
	}

	for(int i=0;i<=sum;i++){
		dp[i][0] = true;
	}

	for(int i=1;i<=v.size();i++){
		for(int j=1;j<=sum;j++){
			
			dp[i][j] = dp[i-1][j]||dp[i-1][j-v[i-1]]; 
			
		}
	}

	printList(v,mainEle,sum,v.size(),dp);
}	
int main(){
	int length,element,sum;
	std::vector<int> v,mainEle;
	cout<<"Enter the length";
	cin>>length;
	cout<<"Enter the elements";
	for(int i=0;i<length;i++){
		cin>>element;
		v.push_back(element);
	}
	cout<<"Enter the sum";
	cin>>sum;
	// perfectSum(v,mainEle,sum,0);
	perfectSumDp(v,sum);
}