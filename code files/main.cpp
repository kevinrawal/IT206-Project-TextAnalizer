#include <bits/stdc++.h>
#include "main.h"
using namespace std;

int main()
{
    int n;

    operation o1;

    int check = 0;

    while (1)
    {

        cout << "-------------------------------------------------------------------------------------------------" << endl;
        cout << "press 1 for input" << endl;
        cout << "press 2 for characters detail" << endl;
        cout << "press 3 for word detail" << endl;
        cout << "press 4 for find word" << endl;
        cout << "press 5 for plagarism detector" << endl;
        cout<<"Press 9 for Exit"<<endl;
        cout << "enter '###' for close the input" << endl;
        cout << "-------------------------------------------------------------------------------------------------" << endl;

        int n;
        cin >> n;
        if (n == 9)
        {
            break;
        }
        switch (n)
        {
        case 1:
            o1.input();
            break;
        case 2:
            o1.character_details();
            break;
        case 3:
            if (check == 0)
            {
                o1.declare_word();
                check = 1; 
            }
            o1.word_detail();
            cout<<"Enter : 1 for Know your text Sentiments \n Else Enter 0 for Exit :"<<endl;
            int amb;
            cin>>amb;
            if(amb == 1) o1.polarity();
            else break;
            break;
        case 4:
            if (check == 0)
            {
                o1.declare_word();
                check = 1;
            }
            o1.check_word();
            break;
        case 5:
            o1.plagrismcheck();
            break;
        default:
            cout << "INVALID" << endl;
            break;
        }
    }

    return 0;
}