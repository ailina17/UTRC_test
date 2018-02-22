#include <iostream>
#include<fstream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;

int main()
{
   string line;
   vector<string> members;
   ifstream file("SocialNetwork.txt",ios::in);
   if (!file.is_open())
        {
           cout << "Error in opening file!"<<endl;
           return 0;
        }
    cout<<"Reading file ''SocialNetwork.txt''..."<<endl;

   int pos;
   while (getline (file,line))
       {
           pos = line.find(",");
           members.push_back(line.substr(0, pos-1));
           members.push_back(line.substr(pos+1, line.length()-pos));
       }
    sort( members.begin(), members.end());
    members.erase( unique( members.begin(), members.end() ), members.end() );

    cout<<"The number of the networks members is " << members.size() <<endl;

   file.close();

   return 0;
}
