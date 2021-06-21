#include<iostream>
#include<algorithm>
#define MAX_SIZE 100
using namespace std;

int n,m,e;//图的顶点数，可用的颜色数量，边的数量
int plan=0;//方案数 
int p[MAX_SIZE][MAX_SIZE];//链接矩阵
int color[MAX_SIZE];//当前解 

bool judge(int a){
    for(int i=1;i<=n;i++){
        if(p[a][i] && color[i]==color[a]){
            return false;
        }
    }
    return true;
}

void backtracking(int point){
    if(point>n){
    	plan++;
    	cout<<"方案"<<plan<<"为：" ;
        for(int i=1;i<=n;i++){
            cout<<color[i]<<" ";
        }
        cout<<endl;
    }
	else{
        for(int i=1;i<=m;i++){
            color[point]=i;
            if(judge(point)){
                backtracking(point+1);
            }
            color[point]=0;
        }
    }
}

int main(){
	cout<<"请输入顶点数、颜色数和边数，用空格分隔：";
	cin>>n>>m>>e;
	
	cout<<"请输入边的顶点，用空格分隔：";
    for(int i=1;i<=e;i++){
    	int a,b; //边的两个顶点 
    	cin>>a>>b;
    	p[a][b]=1; //有边 
        p[b][a]=1;
	}
	
    backtracking(1);
    
    if(plan>0){
    	cout<<"方案数为："<<plan;
	}
    else{
    	cout<<"NO"<<endl; 
	}
    return 0;
}
