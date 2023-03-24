#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fr first
#define sc second
#define srt(a) sort((a).begin(),(a).end());
#define dsrt(a) sort((a).begin(),(a).end(),greater<>())
bool driver(string a, string b){
	if(a.size()==b.size())
		return a<b;
	return a.size()<b.size();
}
void subset_gen(char *input,char *output,int i,int j,vector<string> &v){
	if(input[i]=='\0'){
		output[j]='\0';
		string temp(output);
		v.pb(temp);
		return;
	}
	output[j]=input[i];
	subset_gen(input,output,i+1,j+1,v);
	subset_gen(input,output,i+1,j,v);

}

int main(){
	char input[100];
	char output[100];
	cin>>input;
	vector<string> v;
	subset_gen(input,output,0,0,v);
	sort(v.begin(), v.end(), driver);
	for(auto it:v){
		if(it=="\0"){
			cout<<"NULL"<<endl;
			continue;
		}
		cout<<it<<endl;
	}
	return 0;
}