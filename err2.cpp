#include<iostream.h>
#include<stdio.h>
class staticfunction
{
static int count;
public:
static void setcount()
{
count++;
}
void displaycount()
{
cout<<count;
}
};
int staticfunction::count=10;
void main()
{
staticfunction obj1;
obj1.setcount();
staticfunction::setcount();
obj1.displaycount();
getch();
}
