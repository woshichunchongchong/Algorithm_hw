#include<iostream>
#include<string.h>
#include<algorithm>
#define MAX_SIZE 100
using namespace std;

int n,m;
int dp[MAX_SIZE][MAX_SIZE]; //把j元投给前i项的收益 
int val[MAX_SIZE][MAX_SIZE]; 

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++){
			cin>>val[i][j];    //投第i项j元获得的收益 
		}
	}
	
	//dp
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++){
			for(int k=0;k<=j;k++){
				if(dp[i][j]<dp[i-1][j-k]+val[i][k]){
					dp[i][j]=dp[i-1][j-k]+val[i][k];  
				}
			}
		}
	}
	cout<<"最大收益为："<<dp[n][m]<<endl; 
}
