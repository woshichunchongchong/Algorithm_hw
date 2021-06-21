#include<iostream>
#define MAX_SIZE 100
#define MAX 100000
using namespace std;

int n=8;
int flag[MAX_SIZE];
int p[MAX_SIZE][MAX_SIZE]={{0,1,MAX,MAX,MAX,MAX,MAX,MAX}, //邻接矩阵 
						   {MAX,0,MAX,2,MAX,MAX,MAX,MAX},
						   {2,MAX,0,MAX,MAX,MAX,MAX,MAX},
						   {MAX,MAX,1,0,MAX,8,MAX,MAX},
						   {MAX,MAX,MAX,2,0,MAX,2,MAX},
						   {MAX,MAX,MAX,MAX,2,0,MAX,MAX},
						   {MAX,MAX,MAX,MAX,MAX,3,0,3},
						   {MAX,MAX,MAX,MAX,MAX,2,MAX,0},};
int dis[MAX_SIZE]; 

void Dijkstra(){
	int min,k;
	for(int i=0;i<n-1;i++){  
            //找到离1号顶点最近的顶点  
            min=MAX;  
            for(int j=0;j<n;j++){  
                if(flag[j]==0 && dis[j]<min){  
                    min=dis[j];  
                    k=j;  
                }  
            }  
            flag[k]=1;  
            for(int x=0;x<n;x++){  
                if(p[k][x]<MAX){  
                    if(dis[x]>dis[k]+p[k][x]){
                    	dis[x]=dis[k]+p[k][x];  
					} 
                }  
            }      
    }  
}

int main(){
	for(int i=0;i<n;++i){
		dis[i]=p[0][i];//a到其他点的距离 
	}
	flag[0]=1;
	for(int i=1;i<n;i++){
		flag[i]=0; 
	}  
    Dijkstra();
	printf("%d ",dis[n-1]);  
	return 0;
}
