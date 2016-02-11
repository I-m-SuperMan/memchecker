#include <assert.h>
#include <iostream>
#include "memchecker.h"

using namespace std;


int main()
{
    int* p1 = new int(10);
    std::cout << "P1: " << *p1 <<std::endl;
    assert (*p1==10);
    std::cout << "Allocated: "<< getAllocatedMemory() << std::endl;
    delete p1;


    int* p2 = new int[10]; // guaranteed to call the replacement in C++11
    p2[0] = 1;
    std::cout << "Allocated: "<< getAllocatedMemory() << std::endl;
    delete[] p2;
    cout << "Hello World!" << endl;
#if 0
    cout << "nb  new:" << getNbOfNew() << endl;
    cout << "nb free:" << getNbOfFree() << endl;
    cout << "Delta  :" << getNbOfNew() - getNbOfFree() << endl;
#endif
#if NDEBUG
    cout << "check that RELEASE (debug=" << dMemAllocEnabled() <<")"<< endl;
    assert(dMemAllocEnabled() ==0);
#else
    cout << "check that in DEBUG mode  debug="<< dMemAllocEnabled() << endl;
    assert(dMemAllocEnabled());

#endif
    std::cout << "Allocated: "<< getAllocatedMemory() << std::endl;

    return 0;
}



