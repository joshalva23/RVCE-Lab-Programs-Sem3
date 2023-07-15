#include <iostream>
int main()
{
    int n;
    std::cout<<"Enter the number:";
    std::cin>>n;
    if((n&(n-1)))
    {
        std::cout<<"Not Power of 2"<<std::endl;
    }
    else
    {
        std::cout<<"Power of 2"<<std::endl;
    }
}