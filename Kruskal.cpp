#include<iostream> 
#include<algorithm>
#define MAX_SIZE 1000
using namespace std;

struct Edge{
    int u; //�� 
	int v; //�� 
	int w; //Ȩ�� 
}edge[MAX_SIZE];

int flag[MAX_SIZE];
int n;//����
int m;//����
int ans;//Ȩֵ��
int count1;//���� 

//��Ȩ��Ϊ���ݿ��� 
bool cmp(Edge a,Edge b){
    return a.w<b.w;
}

int find(int x){
    return x==flag[x]?flag[x]:flag[x]=find(flag[x]);
}

//�����㷨 
void kruskal(){
    sort(edge,edge+m,cmp);//���ߵ�Ȩֵ����
    
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
	cout<<"����������ͱ������Կո�ָ���"; 
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        flag[i]=i;
    }
	cout<<"������ߵĶ����Ȩ�أ��Կո�ָ���"; 
    for(int i=0;i<m;i++){
        cin>>edge[i].u>>edge[i].v>>edge[i].w;
    }
    kruskal();
    cout<<"��С������Ȩֵ�ͣ�"<<ans<<endl;
    return 0;
}

