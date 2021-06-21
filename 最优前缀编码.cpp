#include<iostream>
#include<algorithm>
#define MAX_SIZE 100
using namespace std;

int n,m,e;//ͼ�Ķ����������õ���ɫ�������ߵ�����
int plan=0;//������ 
int p[MAX_SIZE][MAX_SIZE];//���Ӿ���
int color[MAX_SIZE];//��ǰ�� 

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
    	cout<<"����"<<plan<<"Ϊ��" ;
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
	cout<<"�����붥��������ɫ���ͱ������ÿո�ָ���";
	cin>>n>>m>>e;
	
	cout<<"������ߵĶ��㣬�ÿո�ָ���";
    for(int i=1;i<=e;i++){
    	int a,b; //�ߵ��������� 
    	cin>>a>>b;
    	p[a][b]=1; //�б� 
        p[b][a]=1;
	}
	
    backtracking(1);
    
    if(plan>0){
    	cout<<"������Ϊ��"<<plan;
	}
    else{
    	cout<<"NO"<<endl; 
	}
    return 0;
}
