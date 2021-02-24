#include <iostream>

using namespace std;

template <class Type>
void SWAP(Type& a, Type& b){
    Type c;
    c = a;
    a = b;
    b = c;
}
