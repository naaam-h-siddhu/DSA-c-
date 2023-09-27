#include<bits/stdc++.h>
using namespace std;
class Disjoint{
	vector<int> rank,parent;
public:
	Disjoint(int n){
		rank.resize(n+1,0);
		parent.resize(n+1,0);
		for (int i = 0; i < n+1; ++i)
		{
			/* code */
			parent[i] = i;
		}
	}
	int findUparent(int node){
		if(node == parent[node]){
			return node;

		}
		return parent[node] = findUparent(parent[node]);
	}
	void unionByRank(int u , int v){
		int ulp_u = findUparent(u);
		int ulp_v = findUparent(v);
		if(ulp_v == ulp_u) return;
		if(rank[ulp_u] < rank[ulp_v]){
			parent[ulp_u] =ulp_v;

		}
		else if(rank[ulp_v] <rank[ulp_u]){
			parent[ulp_v] = ulp_u;
		}
		else{
			parent[ulp_v] = ulp_u;
			rank[ulp_u]++;
		}
	}
};
int main(){
	Disjoint ds(7);
	ds.unionByRank(1,2);
	ds.unionByRank(2,3);
	ds.unionByRank(4,5);
	ds.unionByRank(6,7);
	ds.unionByRank(5,6);
	
	if(ds.findUparent(3) == ds.findUparent(7)){
		cout<<"same"<<endl;
	}
	else
		cout<<"not same"<<endl;
	ds.unionByRank(3,7);
	if(ds.findUparent(3) == ds.findUparent(7)){
		cout<<"same"<<endl;
	}
	else
		cout<<"not same"<<endl;

	
	return 0;
}