#include <vector>
#include <algorithm>

using std::vector;

template < typename T >
void BubbleSort(vector<T> &vec)
{
    for (size_t i = 0; i < vec.size(); i++)
        for (size_t j = 0; j < vec.size() - 1; j++)
            if(vec.at(j) > vec.at(j + 1))
                std::swap(vec[j], vec[j+1]);
}
