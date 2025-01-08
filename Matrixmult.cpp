#include<iostream>
#include<cstring>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
 
double Q[22][22];
double K[22][22];
double V[22][22];
double S[22][22];
double W[22][22];
double C[22][22];
const double e = 2.7182818;
 
int main()
{
    int M,N,D;
    cin>>M>>N>>D;
    for(int i = 0;i<M;i++)
    {
        for(int j = 0;j<D;j++)
        {
            cin>>Q[i][j];
        }
    }
    for(int i = 0;i<N;i++)
    {
        for(int j = 0;j<D;j++)
        {
            cin>>K[j][i];//直接输入KT;
        }
    }
    for(int i = 0;i<N;i++)
    {
        for(int j = 0;j<D;j++)
        {
            cin>>V[i][j];
        }
    }
 
 
    double sd = sqrt(D);
    for(int i = 0;i<M;i++)//计算S
    {
        for(int j = 0;j<N;j++)
        {
            double sum = 0.0;
            for(int p = 0;p<D;p++)
            {
                sum+=(Q[i][p]*K[p][j]);//A BT 矩阵乘法
            }
 
            S[i][j] = (sum/sd);
        }
    }
 
    double eS[22];
    double sume = 0.0;
    for(int i = 0;i<M;i++)
    {
        sume = 0;
        for(int j = 0;j<N;j++)
        {
            eS[j] = pow(e,S[i][j]);
            sume += eS[j];
        }
        for(int j = 0;j<N;j++)
        {
            W[i][j] = eS[j]/sume;
        }
    }
 
    for(int i = 0;i<M;i++)//计算S
    {
        for(int j = 0;j<D;j++)
        {
            double sum = 0.0;
            for(int p = 0;p<N;p++)
            {
                sum+=W[i][p]*V[p][j];//A BT 矩阵乘法
            }
 
            C[i][j] = (sum);
            printf("%.1lf ",C[i][j]);
        }
        cout<<endl;
    }
}
