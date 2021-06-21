#include<iostream>
#define MAX_SIZE 100
#define MAX 100000
using namespace std;

int main(){
	int a,b;
	int n=4;
	
	int distance[4][4]={{0,2,6,4},
						{MAX,0,3,MAX},
						{7,MAX,0,1},
						{5,MAX,12,0}};
	for(int k=0;k<n;++k){
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				if(distance[i][j]>distance[i][k]+distance[k][j]){
					distance[i][j]=distance[i][k]+distance[k][j];
				}
			}
		}
	}
	cout<<"输入两个点：";
	cin>>a>>b;
	a--;
	b--;
	cout<<"两点间最短路径为："<<distance[a][b]<<endl;
	return 0;
}
