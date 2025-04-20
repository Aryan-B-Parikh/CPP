#include<iostream>
#include<cmath>
using namespace std;

class Digit
{
    int n;
    public:
    void showdata();
    int enter(int n);
    int compare(Digit);
};

int Digit :: enter(int n)
{
    this->n=n;
}

void Digit :: showdata()
{
    cout<<n<<endl;
}

int Digit :: compare(Digit d)
{
    if(n==d.n)
    {
        return 0;
    }
    else if(n>d.n)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

int main()
{
    Digit d1,d2;
    int n1,n2;
    cout<<"Enter first number: ";
    cin>>n1;
    d1.enter(n1);
    cout<<"Enter second number: ";
    cin>>n2;
    d2.enter(n2);
    d1.showdata();
    d2.showdata();
    int result=d1.compare(d2);
    if(result==0)
        cout<<"Both numbers are equal"<<endl;
    else if(result==1)
        cout<<"First number is greater than second number"<<endl;
    else
        cout<<"Second number is greater than first number"<<endl;
    return 0;

}
