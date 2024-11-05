#include<iostream>


using namespace std;


void fibo()
{
    int n=10;
    int a=0;
    int b=1;
    cout<<a<<" "<<b<<" ";
    for (int i = 2; i < n; i++)
    {
        int c=a+b;
        a=b;
        b=c;
        cout<<c<<" ";
    }
}


void fibo_recursive(int a,int b,int n)
{
       if (n<=0)
       {
       
       return;
       }
       
       cout<<a<<" ";
        fibo_recursive(b,a+b,n-1);
       
}


int main()
{
fibo();
    fibo_recursive(0,1,10);

    return 0;

}