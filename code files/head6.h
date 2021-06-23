//load and set as string
#include<bits/stdc++.h>

#include<fstream>
using namespace std;

class checkthepositive
{
    public:
    string finalf = " ";
    string negetiveword = " ";
    
    void polarity();
    void feedback(string str,int n);
    
};

void checkthepositive::polarity()
{
    string st2;
    
    ifstream inf("positive.txt");
    if(!inf.is_open())
    {
        cout<<"File not found !"<<endl;
        return;
    }
    while(inf)
    {
    getline(inf,st2);
    finalf.append(" ");
    finalf.append(st2);
    
    }
    ifstream infm("negetive.txt");
    if(!infm.is_open())
    {
        cout<<"File not found !"<<endl;
        return;
    }
    while(infm)
    {
    getline(infm,st2);
    negetiveword.append(" ");
    negetiveword.append(st2);
    
    }
    
    inf.close();
    infm.close();


   
}

void checkthepositive::feedback(string str,int n)
{
if(n == 1)
{
    ofstream fout;  // Create Object of Ofstream
    ifstream fin;
    fin.open("positive1.txt");
    fout.open ("positive1.txt",ios::app); // Append mode
    if(fin.is_open())
        fout<< str;
    fin.close();
    fout.close(); 
}
else if(n == 2)
{
    ofstream fout;  // Create Object of Ofstream
    ifstream fin;
    fin.open("negetive.txt");
    fout.open ("negetive.txt",ios::app); // Append mode
    if(fin.is_open())
        fout<<str;
    fin.close();
    fout.close(); 

}
}




