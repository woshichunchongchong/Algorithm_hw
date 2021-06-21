#include<iostream>
#include<math.h>
#include<algorithm>
#define MAX_SIZE 100
#define MAX 100000
using namespace std;

struct point{
  double x, y; //���� 
}p[MAX_SIZE];

int a[MAX_SIZE];// �������������

int cmpx(const point& a, const point& b){ //��x����  
  return a.x < b.x;
}

int cmpy(int &a, int &b){  //��y����
  return p[a].y < p[b].y;
}

double min(double a, double b){
	return a < b ? a : b;
}

double dis(point& a,point& b){ //������� 
  return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

double nearest(int left, int right){
	if(left==right){
		return MAX;
	} 	
	if(left+1==right){
		return dis(p[left],p[right]);
	}
	int mid=(left+right)/2;
	double ans=min(nearest(left, mid),nearest(mid+1, right)); //�ݹ����������С����
	int i,j,c=0;
	for(i=left;i<=right;++i){
		if(p[mid].x-ans<=p[i].x && p[i].x<=p[mid].x+ans){
			a[c++]=i;
		}
	}
	sort(a,a+c,cmpy);
	for(i=0;i<c;++i){
		int k=i+7>c ? c:i+7;  
		for(j=i+1;j<k;j++){
			if (p[a[j]].y - p[a[i]].y > ans){
				break;
			}  
			ans = min(dis(p[a[i]], p[a[j]]), ans);   //�����������С�����������ԣ���ѡ����С�ĵ�
		}
	}
	return ans;
}

int main(){
	int n;  //һ�����ٸ���
	double dmin;
	cout<<"�������ĸ�����"
	cin>>n;
	cout<<"��������x��y���꣺"<<endl;
	for(int i=0;i<n;i++){
		cin>>p[i].x>>p[i].y;
	}
	sort(p,p+n,cmpx); //����x��С��������
	cout<<"���������������ǣ�"<<nearest(0, n-1)<<endl;
	return 0;
}

