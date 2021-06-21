#include<iostream> 
#include<algorithm>
#define MAX_SIZE 1000
using namespace std;

struct Edge{
    int u; //点 
	int v; //点 
	int w; //权重 
}edge[MAX_SIZE];

int flag[MAX_SIZE];
int n;//点数
int m;//边数
int ans;//权值和
int count1;//辅助 

//以权重为依据快排 
bool cmp(Edge a,Edge b){
    return a.w<b.w;
}

int find(int x){
    return x==flag[x]?flag[x]:flag[x]=find(flag[x]);
}

//核心算法 
void kruskal(){
    sort(edge,edge+m,cmp);//将边的权值排序
    
    for(int i=0;i<m;i++){
    	int uu=find(edge[i].u);
        int vv=find(edge[i].v);
        if(uu==vv){
            continue;
        }
        ans+=edge[i].w;
        flag[vv]=uu;
        if(++count1==n-1){
            break;
        }
    }
}
int main(){
	cout<<"请输入点数和边数，以空格分隔："; 
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        flag[i]=i;
    }
	cout<<"请输入边的顶点和权重，以空格分隔："; 
    for(int i=0;i<m;i++){
        cin>>edge[i].u>>edge[i].v>>edge[i].w;
    }
    kruskal();
    cout<<"最小生成树权值和："<<ans<<endl;
    return 0;
}

