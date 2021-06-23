#include <bits/stdc++.h>
#include "head2.h"
using namespace std;

//here we use linked list to store words.

class list_for_words;

class node3
{
public:
    int no;
    string s;
    node3 *next;

    node3(string st)
    {
        s = st;
        no = 1;
        next = NULL;
    }
   
};
class checkthepositive;
class list_for_words
{
    public:
    node3 *head = NULL;
    node3 *traversal = NULL;
    
    void insert(string s); 
    void display();
    int no_words = 0;
    int no_diff_words=0;
    void detect();
  
};


void list_for_words::insert(string s)
{

    if (head == NULL)
    {
        node3 *n = new node3(s);
        head = n;
        traversal = n;
        no_words++;
        no_diff_words++;
        return;
    }

    node3 *temp = head;

    while (temp != NULL)
    {
        if (!(s.compare(temp->s)))
        {
            temp->no++;
            no_words++;
            return;
        }
        temp = temp->next;
    }
    node3 *n = new node3(s);
    traversal->next = n;
    traversal = n;
    no_words++;
    no_diff_words++;
}

void list_for_words::display()
{
    cout<<endl;
    cout << "\t\t WORDS DETAILS" << endl;
    cout << "-----------------------------------------------------------------------------------" << endl;
    node3 *temp = head;
cout<<"word"<<"\t\t\t\t"<<"no of time it appear"<<"\t\t\t"<<"total weitage in text"<<endl;
cout<<endl;
    while (temp != NULL)
    {
         cout<<temp->s<<"\t\t\t\t\t"<<temp->no<<"\t\t\t\t"<< (float)temp->no / (float)no_words * 100<<"%"<<endl;
        cout << "-----------------------------------------------------------------------------------" << endl;
        cout<<endl;
        temp = temp->next;
    }

    cout<<"total number of words are :"<<no_words<<endl;
    cout<<endl;
    cout<<"total number of different words are :"<<no_diff_words<<endl;
    cout << "-----------------------------------------------------------------------------------" << endl;
}

//function for detecting word in string 
void list_for_words::detect()
{
    //use of head 2
    d_word w;
    cout << "-----------------------------------------------------------------------------------" << endl;
    cout << "enter words you want to detect" << endl;
    int count = 0;
    
    while (1)
    {
        string s;
        cin >> s;
        if (s == "###")
        {
            break;
        }

        w.push(s);
        count++;
    }

    if (count == 0)
    {
       cout<<"you not enter anything"<<endl;
    }

    cout<<"Word"<<"\t\t\t\t"<<"no of time it found"<<endl;
    while (count > 0)
    {
      
        node3 *temp = head;
        string check_word = w.pop();
        int flag = 0;
        
        while (temp != NULL)
        {
           
            if (!(check_word.compare(temp->s)))
            {
            cout<<temp->s<<"\t\t\t\t"<<temp->no<<endl;
            cout << "-----------------------------------------------------------------------------------" << endl;
            flag=1;
            break;
            }
            temp = temp->next;
        }
        if(flag==0){
            cout<<check_word<<"\t\t\t\t"<<"is not found in the text"<<endl;
            cout << "-----------------------------------------------------------------------------------" << endl;
        }
         count--;
    }
}
