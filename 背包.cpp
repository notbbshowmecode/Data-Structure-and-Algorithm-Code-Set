#include<iostream>
using namespace std;
int  one_backpack(int vo[],int val[],int V,int N)
{
    /*int dp[N+1][V+1]= {};
    for(int i = 1 ; i <= N; i++) //begin 1
        for(int m = vo[i]; m <= V; m++)
        {
            dp[i][m] = max(dp[i-1][m],dp[i-1][m-vo[i]]+val[i]);
        }
    return  dp[N][V];*/
    int dp[V+1] = {};
    for(int i = 1 ; i <= N; i++) //begin 1
        for(int m = V; m >=vo[i]; m--) //V->vo[i]
        {
            dp[m] = max(dp[m],dp[m-vo[i]]+val[i]);
        }
    return  dp[V];
}
int Full_bp(int vo[],int val[],int V,int N)
{
    int dp[V+1] = {};
    for(int i = 1 ; i <= N; i++) //begin 1
        for(int m = vo[i]; m <= V; m++) //vo[i]->V
        {
            dp[m] = max(dp[m],dp[m-vo[i]]+val[i]);
        }
    return  dp[V];
}
int k_bp(int vo[],int val[],int k[],int V,int N)
{
    int dp[V+1] = {0};
    for(int i = 1 ; i <= N; i++) //begin 1
        for(int nk = 0; nk < k[i]; nk++) //k
            for(int m = V; m >=vo[i]; m--) //V->vo[i]
            {
                dp[m] = max(dp[m],dp[m-vo[i]]+val[i]);
            }
    return  dp[V];
}
int main()
{
    int vo[]= {0,4,3,3,5,6,7,8,5,4};
    int val[]= {0,6,3,6,5,65,7,8,5,4};
    int k[]= {0,4,3,3,5,6,7,8,5,4}; //for k_bp
    int V=14,N=sizeof(vo)/sizeof(int);
    cout<<"01bp:"<<one_backpack(vo,val,V,N)<<endl;
    cout<<"Full_bp:"<<Full_bp(vo,val,V,N)<<endl;
    cout<<"k_bp:"<<k_bp(vo,val,k,V,N)<<endl;
}
