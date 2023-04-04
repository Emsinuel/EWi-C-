#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::cin;
using std::map;
using std::vector;
using std::string;

void add_participant(vector <string> &names);
void add_price(vector <string> &awards);
void show(vector <string> names, vector <string> awards);
void random(vector <string> names, vector <string> awards);

int main(){
    vector <string> names {};
    vector <string> awards {};
    char choice {};

    //Sample list of participants
    names = {"Mariusz", "Kamil", "Grzegorz", "Tomasz", "Piotrek"};
    //Sample list of prizes
    awards ={"Cup", "cupon"};

    do
    {
        cout<<"A - Add a tournament participant, \n";
        cout<<"P - Add a prize to the tournament, \n";
        cout<<"S - Show tournament participants and prizes, \n";
        cout<<"T - Start the draw, \n";
        cout<<"B - Exit menu, \n";

        cout<<"Enter your choice: \n";
        cin>>choice;

        if(choice == 'a' || choice == 'A')
            add_participant(names);
        else if(choice == 'p' || choice == 'P')
            add_price(awards);
        else if(choice == 's' || choice == 'S')
            show(names, awards);
        else if(choice == 't' || choice == 'T')
            random(names, awards);
        else
            cout<<"This option does not exist. \n";
    } while (choice != 'b' && choice != 'B');
    

    return 0;
}
void add_participant(vector <string> &names)
{
    string name {};
    cout<<"Enter the participant's name: \n";
    cin>>name;
    names.push_back(name);
}
void add_price(vector <string> &awards)
{
    string price {};
    cout<<"Enter a name for your reward: \n";
    cin>>price;
    awards.push_back(price);
}
void show(vector <string> names, vector <string> awards)
{
    cout<<"Number of participants: \n";
    cout<<names.size()<<"\n";
    cout<<"Participants: \n";
    for(const auto &n : names)
        cout<<n<<"\n";

    cout<<"Number of awards: \n";
    cout<<awards.size()<<"\n";
    cout<<"Awards: \n";
    for(const auto &a : awards)
        cout<<a<<"\n";
}
void random(vector <string> names, vector <string> awards)
{
    map <string, string> ans {};
    srand(time(0));

    while(names.size() >= 1 && awards.size() >= 1)
    {
        int index_n = rand() % names.size();
        int index_a = rand() % awards.size();
        ans[names[index_n]] = awards[index_a];
        names.erase(names.begin() + index_n);
        awards.erase(awards.begin() + index_a);
    }
    for(const auto &[key, val] : ans)
        cout<<"Participian: "<<key<<", Reward: "<<val<<"\n";
}