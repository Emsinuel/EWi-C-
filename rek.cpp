#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
    string word {"lakukaracza"};
    map<char, int> licznik_znakow;
    for(const auto &w : word)
    {
        if(licznik_znakow.find(w) == licznik_znakow.end())
        {
            licznik_znakow[w] = 1;
        }
        else
        {
            licznik_znakow[w]++;
        }
    }
    for(const auto &[key, val] : licznik_znakow)
        cout<<key<<", "<<val<<"\n";
    return 0;
}