#include <iostream>
#include <string>
using namespace std;
string str[100],findString;
int no_of_words;
bool wordBreak(string newString,string finalWord,int pos){
	if(pos==findString.length()&&finalWord==findString){
		return true;
	} else if(pos==findString.length()){
		return false;
	}
	bool found=false,ans1=false,ans2=false;
	newString=newString+findString[pos];
	for(int i=0;i<no_of_words;i++){
		if(newString==str[i]){
			found=true;
		}
	}
	if(found){
		ans1=wordBreak("",finalWord+newString,pos+1);
	}else{
		ans2=wordBreak(newString,finalWord,pos+1);
	}
	return ans2||ans1;
}
int main(){
	bool ans;
	string word;
	cout<<"Enter the no_of_words";
	cin>>no_of_words;
	cout<<"Enter the string to find";
	cin>>findString;
	cout<<"Enter the words";
	for(int i=0;i<no_of_words;i++){
		cin>>str[i];
	}
	ans=wordBreak("","",0);
	if(ans){
		cout<<"Yes";
	}else{
		cout<<"No";
	}
}