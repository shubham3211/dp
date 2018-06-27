#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int > pi;
bool myFunc(pi A,pi B){
	return A.second<B.second;
}
int max_length(vector<pi> v,int maximum,int pos,int length){
	if(pos==v.size()){
		return length;
	}
	int l1=0,l2=0;
	l1=max_length(v,maximum,pos+1,length);
	if(v[pos].first>maximum){
		l2=max_length(v,v[pos].second,pos+1,length+1);
	}
	return max(l1,l2);
}
int max_length_Dp(vector<pi> v){
	std::vector<int> dp;
	int ans=0;
	dp.resize(v.size(),1);
	for(int i=1;i<v.size();i++){
		for(int j=0;j<i;j++){
			if(v[j].second<v[i].first){
				dp[i]=max(dp[i],dp[j]+1);
			}
		}
	}
	for(std::vector<int>::iterator it=dp.begin();it!=dp.end();it++){
		ans=max(ans,*it);
	}
	return ans;
}
int max_length_Print(vector<pi> v){
	std::vector<int> dp;
	std::vector<pi> printVec[v.size()];
	dp.resize(v.size(),1);
	int ans=0;
	printVec[0].push_back(v[0]);
	for(int i=1;i<v.size();i++){
		for(int j=0;j<i;j++){
			if(v[j].second<v[i].first&&dp[i]<dp[j]+1){
				dp[i]=dp[j]+1;
				printVec[i]=printVec[j];
			}
		}
		printVec[i].push_back(v[i]);
	}
	for(std::vector<int>::iterator it=dp.begin();it!=dp.end();it++){
		ans=max(ans,*it);
	}
	for(int i=0;i<v.size();i++){
		for(vector<pi>::iterator it=printVec[i].begin();it!=printVec[i].end();it++){
			cout<<(*it).first<<" "<<(*it).second<<" ";
		}
		cout<<endl;
	}
	return ans;
}
int main(){
	int n,ans;
	pi val;
	std::vector<pi> v;
	cout<<"Enter the number of pair";
	cin>>n;
	for(int i=0;i<n;i++){
        cin>>val.first;
        cin>>val.second;
        v.push_back(val);       
	}
	sort(v.begin(),v.end(),myFunc);
	// for(std::vector<pi>::iterator it=v.begin();it!=v.end();it++){
	// 	cout<<(*it).first<<" "<<(*it).second<<endl;
	// }
	ans=max_length_Print(v);
	cout<<ans;
}