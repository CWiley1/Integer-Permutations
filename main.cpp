#include <iostream>
#include <vector>
#include <set>
#include <cassert>
#include <algorithm>

using namespace std;

set<vector<unsigned>> permutations(unsigned n)
{
    set<vector<unsigned>> p;

    if (n == 1)
    {
        vector<unsigned> one;
        one.push_back(1);
        p.insert(one);
        return p;
    }
    p = permutations(n-1);
    vector<unsigned> add;
    set<vector<unsigned>>::iterator it;
    for (it = p.begin(); it != p.end(); it++)
    {
        if (it->size() < n)
        {
            add.push_back(n);
            for (int i = 0; i < it->size(); i++)
            {
                add.push_back((*it)[i]);
            }
            p.erase(it);
            p.insert(add);
            for (int j = 0; j < n - 1; j++)
            {
                swap(add[j],add[j+1]);
                p.insert(add);
            }
         add.erase(add.begin(), add.begin() + add.size());
         it = p.begin();

        }
    }

    return p;





}

int main()
{
    int n = 1234;
    set<vector<unsigned>> p = permutations(n);
    return 0;
}
