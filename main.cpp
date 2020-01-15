#include "StructureData/LinkedList/LinkedList.h"

using namespace std;

int main()
{
    LinkedList<int> lnklist(1);
    lnklist.push_back(2);
    lnklist.push_back(3);
    lnklist.push_back(4);
    lnklist.push_back(5);
    lnklist.push_back(6);
    lnklist.show();
    cout << lnklist[2];
    const LinkedList<double> list(3.14);
    cout << list[0];
    return 0;
}
