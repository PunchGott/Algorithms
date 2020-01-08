#include "StructureData/LinkedList/LinkedList.h"

using namespace std;

int main()
{
    LinkedList<int> lnklist{5};
    lnklist.push_back (1);
    lnklist.show ();
    return 0;
}
