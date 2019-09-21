#include<iostream.h>
#include<conio.h>
class sample{
int a,b;
public:
void init(int,float);
friend float mean(sample s);
};
void sample::init(int x,float y)
{a=x;
b=y;}
float mean(sample s)
{return (s.a+s.b)/2.0;
}
void main()
{
sample x;
x.init(2,3.5);
cout<<"mean="<<mean(x);
getch();
}


