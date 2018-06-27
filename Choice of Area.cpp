#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
using namespace std;
typedef pair<int,int> pi;
int maxArea(pi x,pi y,pi z,int a,int b,map<pair<pi,char>, int>memo,char location){
	pi power = make_pair(a,b);
	pair <pi , char> mainPower;
	mainPower = make_pair(power,location);
	int ans = 0;
	if(a<=0 || b<=0){
		return 0;
	}
	if(memo.find(mainPower)!= memo.end()){
		return memo[mainPower];
	}
	switch(location){
		case 'x': ans = 1+max(maxArea(x,y,z,a+y.first,b+y.second,memo,'y'),
							  maxArea(x,y,z,a+z.first,b+z.second,memo,'z'));
							  break;
		case 'y': ans = 1+max(maxArea(x,y,z,a+x.first,b+x.second,memo,'x'),
							  maxArea(x,y,z,a+z.first,b+z.second,memo,'z'));
							  break;
		case 'z': ans = 1+max(maxArea(x,y,z,a+y.first,b+y.second,memo,'y'),
							  maxArea(x,y,z,a+x.first,b+x.second,memo,'x'));
							  break;  							   
	}

	memo[mainPower] = ans;
	return ans;
}
int main(){
	pi x,y,z;
	x = make_pair(3,2);
	y = make_pair(-5,-10);
	z = make_pair(-20,5);
	int a = 20,b =8,ans;
	std::map<pair<pi,char> , int> memo;
	ans = max((maxArea(x,y,z,a,b,memo,'x'),maxArea(x,y,z,a,b,memo,'y')),
				  maxArea(x,y,z,a,b,memo,'z'));
	cout<<ans;
}