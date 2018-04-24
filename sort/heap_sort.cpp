#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
void max_heapify(int A[],int i,int n)//递归实现堆性质的维护, 假设i节点的左右子树满足性质
{
    int l = 2*i;
    int r = 2*i+1;
    int largest = i;
    if(l <= n&& A[l] > A[i])
        largest = l;
    if(r <= n&& A[r] > A[largest])
        largest = r;
    if(largest != i)
    {
        A[i] = A[largest]^A[i];
        A[largest] = A[i]^A[largest];
        A[i] = A[i]^A[largest];
        max_heapify(A,largest,n);
    }
}
void max_creatdui(int A[],int n)//堆的创建,利用堆的维护，自底向上维护一次(倒数第二层到最顶层）
{
    for(int i = n/2;i >=1 ;i--)
    {
        max_heapify(A,i,n);
    }
}
void heapsort(int A[],int n)
{
    if(n==1)return ;
    int t = A[1];    //将最大的树与最后一个
    A[1] = A[n];
    A[n] = t;
  /*  A[1] = A[n]^A[1];
    A[n] = A[1]^A[n];
    A[1] = A[1]^A[n];*/
    max_heapify(A,1,n-1);
    heapsort(A,n-1);
}
bool cmp(int a,int b)  //cmp return 0 交换AB
{
    if(a>b)return 0;
    else return 1;
}
main()
{
    int A[100] = {000,5,6,8,9,1,2,5,3,6,4};
   max_creatdui(A,10);
    heapsort(A,10);
  //  sort(A+1,A+11,cmp);
    for(int i = 1;i<=10;i++)cout<<A[i]<<" ";
}
