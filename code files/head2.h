#include <bits/stdc++.h>
using namespace std;

    //d_word = detecting word
    //it is the stack implementation using linked list
    //it is for store words given by user and use for detecting it in main text 
    //we use only neccecory functions here 
    class d_word;

    class Node_2{
       public:
        string s;
        Node_2 * next;
        Node_2(string val){
            s = val;
            next = NULL;
        }
       
    };

    class d_word{
        protected:
        Node_2 * head = NULL;
        int top = -1;

        public:
        
        void push(string s){
            if(top==-1){
                Node_2 * n = new Node_2(s);
                head = n;
                top++;
                return;
            }
            Node_2 * n = new Node_2(s);
            n->next = head;
            head = n;
            top++;
        }

        string pop(){
            Node_2 * todelete;
            if(top>=0){
                 Node_2 * todelete = head;
                 head = todelete->next;
                 return todelete->s;
                 top--;
            }
            else{
                cout<<"stack underflow"<<endl;
                return NULL;
            }
            delete todelete;
        }

    };