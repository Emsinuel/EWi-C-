#include <iostream>
#include <vector>

using namespace std;

vector <int> qsort(vector <int> vec);
void print_vec(vector <int> vec);
vector <int> scal(vector <int> less, int pivot, vector <int> high);

int main(){
    vector <int> vec {4, 6, 3, 2, 7, 8, 1};
    print_vec(qsort(vec));
    return 0;
}

vector <int> qsort(vector <int> vec)
{
    if(vec.size() < 2)
        return vec;
    else
    {
        vector <int> less;
        vector <int> high;
        int pivot {vec[vec.size() / 2]};

        for(int v : vec)
            if(v < pivot)
                less.push_back(v);
            else if(v > pivot)
                high.push_back(v);

        less = qsort(less); 
        high = qsort(high);

        return scal(less, pivot, high);
    }
}
void print_vec(vector <int> vec)
{
    for(int v : vec)
        cout<<v << ", ";
}
vector <int> scal(vector <int> less, int pivot, vector <int> high)
{
    vector <int> ans;
    for(int l : less)
        ans.push_back(l);
    ans.push_back(pivot);
    for(int h : high)
        ans.push_back(h);
    return ans;
}