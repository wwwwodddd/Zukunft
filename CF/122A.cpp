#include <iostream>
int l;
main(){
std::cin>>l;
std::cout<<(l%4==0||l%7==0||l%47==0||l%74==0||l%477==0 ? "YES":"NO");
}

//4 7 47 74 447 474 477 747 774
