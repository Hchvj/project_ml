#include<stdio.h>
#include<stdlib.h>
#include<time.h>

float deriveea(int* x,int*y,int n,float a,float b)
{
    float s=0;
    for(int i=0;i<n;i++)
    {
        s=s-2*y[i]*x[i]+2*a*x[i]*x[i]+2*b*x[i];
    }
    s=s/n;
    return s;
}
float deriveeb(int* x,int*y,int n,float a,float b)
{
    float s=0;
    for(int i=0;i<n;i++)
    {
        s=s-2*y[i]+2*a*x[i]+2*b;
    }
    s=s/n;
    return s;
}
void descente_de_gradient(int* X,int* Y,int n,float* a,float* b)
{
    //MSE=somme((y-y')^2)/n=somme(y^2-2ayx-2yb+(ax)^2+2bax+b^2)/n
    float erreur=0.01;
    float pas=0.01;
    while((deriveea(X,Y,n,*a,*b)<=erreur)||(deriveeb(X,Y,n,*a,*b)<=erreur))
    {
        *a=*a-deriveea(X,Y,n,*a,*b)*pas;
        *b=*b-deriveeb(X,Y,n,*a,*b)*pas;
    }
    return;
}
int main()
{
    int n;
    printf("donner le nombre de x et y");
    scanf("%d",&n);
    int X[n];
    int Y[n];
    for(int i=0;i<n;i++)
    {
        printf("donner le %d eme x et y",i+1);
        scanf("%d%d",X[i],Y[i]);
    }
    srand(time(NULL));
    float a=(float)rand()/RAND_MAX;
    float b=(float)rand()/RAND_MAX;
    printf("%d %d",a,b);
    descente_de_gradient(X,Y,n,&a,&b);
    printf("les meuilleurs a et b sont %f et %f",a,b);
}
