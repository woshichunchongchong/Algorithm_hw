#include<iostream>
#include<math.h>
#include<algorithm>
#define MAX_SIZE 100
#define MAX 100000
using namespace std;

struct point{
  double x, y; //坐标 
}p[MAX_SIZE];

int a[MAX_SIZE];// 保存排序的索引

int cmpx(const point& a, const point& b){ //以x排序  
  return a.x < b.x;
}

int cmpy(int &a, int &b){  //以y排序
  return p[a].y < p[b].y;
}

double min(double a, double b){
	return a < b ? a : b;
}

double dis(point& a,point& b){ //计算距离 
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
	double ans=min(nearest(left, mid),nearest(mid+1, right)); //递归求出两边最小距离
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
			ans = min(dis(p[a[i]], p[a[j]]), ans);   //如果有两个点小于两侧的最近对，则选出最小的点
		}
	}
	return ans;
}

int main(){
	int n;  //一共多少个点
	double dmin;
	cout<<"请输入点的个数："
	cin>>n;
	cout<<"请输入点的x和y坐标："<<endl;
	for(int i=0;i<n;i++){
		cin>>p[i].x>>p[i].y;
	}
	sort(p,p+n,cmpx); //按照x大小升序排序
	cout<<"最近的两个点距离是："<<nearest(0, n-1)<<endl;
	return 0;
}

