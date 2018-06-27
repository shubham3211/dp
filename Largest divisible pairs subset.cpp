#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dividePairRecur(vector<int> v,vector<int> mainEle,int length){
		if(length==v.size()){
			return mainEle.size();
		}
		int length1 = dividePairRecur(v,mainEle,length+1);
		for(vector<int>::iterator it =mainEle.begin();it!=mainEle.end();it++){
			if(v[length]<=*it&&*it%v[length]!=0){
				return length1;
			}
		}
		mainEle.push_back(v[length]);
		int length2 = dividePairRecur(v,mainEle,length+1);
		return max(length1,length2);
}
	
int dividePairDp(std::vector<int> v){

	int dp[100] = {0},ans=0,maximum=0;
	for(int i=0;i<v.size();i++){
		ans = 0;
		for(int j=0;j<=i;j++){
			if(v[j]%v[i]==0){
				if(dp[j]+1>ans){
					ans = dp[j]+1; 
				}
			}
		}
		dp[i] = ans;
	}

	maximum = *max_element(dp,dp+v.size());

	return maximum;
}

int main(){
	std::vector<int> v,mainEle;
	int length,element,m,ans,max;
	max = 0;
	cout<<"Enter the size";
	cin>>length;
	for(int i=0;i<length;i++){
		cin>>element;
		v.push_back(element);
	}
	std::sort(v.begin(), v.end(), std::greater<int>());
	// ans = dividePairRecur(v,mainEle,0);
	ans = dividePairDp(v);
	cout<<"The maximum length is"<<ans;
}