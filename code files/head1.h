#include <bits/stdc++.h>
using namespace std;

//store and operat on characters using linked list 
class list_for_characters;

class node_1
{
private:
    char c;
    int char_num = 0;
    node_1 *next;
    friend class list_for_characters;
};

class list_for_characters
{
protected:
    node_1 *head;
    node_1 *end;

    int total_diffrent_char = 0;
    int arr[256] = {0};      
    int space = 0;

public:
    int string_len;
    void crete(string s);
    void display();
};

void list_for_characters::crete(string s)
{
    string_len = s.length();
    int n = s.length();
    int i = 0;
    while (n--)
    {

        if (i == 0)
        {
            node_1 *temp = new node_1;
            temp->c = s[i];
            temp->char_num += 1;
            temp->next = NULL;
            head = temp;
            end = temp;
            arr[(int)s[i]] = 1;
            total_diffrent_char += 1;
        }
        else
        {
            if (arr[(int)s[i]] == 0)
            {
                node_1 *temp = new node_1;
                temp->c = s[i];
                temp->char_num += 1;
                temp->next = NULL;
                end->next = temp;
                end = temp;
                arr[(int)s[i]] = 1;
                total_diffrent_char += 1;
            }
            else
            {
                node_1 *temp = new node_1;
                temp = head;
                while (temp->c != s[i])
                {
                    temp = temp->next;
                }
                temp->char_num += 1;
            }
        }
        i++;
    }
}

void list_for_characters::display()
{
    cout << "-----------------------------------------------------------------------------------" << endl;
    cout<<endl;
    cout << "\t\t"
         << "CHARACTERS DEATIL" << endl;
         cout<<endl;
    cout << "-----------------------------------------------------------------------------------" << endl;

    node_1 *temp = head;
    int space_count = 0;
        cout << "character"
             << "        "
             << "number of time it appear"
             << "         "
             << "total weitage in text" << endl;
    while (temp != NULL)
    {
        if (temp->c == ' ')
        {
            space_count = temp->char_num;
        }
        
        cout << "   "
             << "'" << temp->c << "'"
             << "                     \t" << temp->char_num << "                              " << (float)temp->char_num / (float)string_len * 100 << "%" << endl;
        cout << "-----------------------------------------------------------------------------------" << endl;

        temp = temp->next;
    }

    cout << "Total characters in text are :" << string_len << endl;
    cout << endl;
    cout << "In your Text the total diffrent charecters are :" << total_diffrent_char << endl;
    cout << "-----------------------------------------------------------------------------------" << endl;
}
