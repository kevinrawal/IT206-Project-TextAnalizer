#include<bits/stdc++.h>
using namespace std;
    //store strings using  linked list 
    //this is for our plagarism detection function 

    class storage_for_string;

    class node{
        protected:
        string str;
        node * next;
    
        int index_no = 0;

        node(string s){
            str = s;
            next = NULL;
                        
        }

        friend class storage_for_string;
    };

    class storage_for_string{
           protected:
           node * head = NULL;
           node * end  = NULL;
           public:
           void insert(string s);
           void display();
           string give(int index);
           void change_in_small(string s ,int j);
           void change(string s,int n);      
           string create_string(int i , int j);
           int total_words = 0;
    };

            //INSERT
           void storage_for_string::insert(string s){
               node * n = new node(s);
               if(head == NULL){
                   head = n;
                   end = n;
                   n->index_no = 1;
                   total_words++;
                   return ;
               }

               end->next = n;
               n->index_no = end->index_no + 1;
               end = n;
               total_words++;
           }
          //DISPLAY
           void storage_for_string::display(){
               node * temp = head;
               while(temp!=NULL){
                   cout<<temp->str<<" "<<temp->index_no<<endl;
                   temp = temp->next;
               }
           }

           string storage_for_string::give(int i){
               node * temp = head;
               while(temp!=NULL){
                   if(temp->index_no == i){
                       return temp->str;
                   }
                  temp = temp->next;
               }

               return NULL;   
           }


        //change in small
        void storage_for_string::change_in_small(string s  ,int j){
            int n = s.length();
            int flag = 0;

            for(int i=0; i<n ; i++){
                if(s[i]>=65 && s[i]<=90){
                    s[i] = s[i] + 32 ;
                    flag = 1;
                }
            }
                if(flag==1){
                    change(s , j);
                }
        }
        //change in exixting string 
        void storage_for_string::change(string s, int n){
                node * temp = head;
                while(temp->index_no != n){
                    temp = temp->next;
                }

                temp->str = s;
        }
        //create new string using stored strings
        string storage_for_string::create_string(int i,int j){
            string buffer;
            node * temp  = head;
            while(temp->index_no != i){
                temp = temp->next;
            }
            while(temp->index_no != j){

                if(temp->index_no == i){
                    buffer = buffer + temp->str;
                }
                else{
                    buffer = buffer +" "+temp->str ;
                }
                temp = temp->next;
            }
                if(temp->index_no == i){
                    buffer = buffer + temp->str;
                }
                else{
                    buffer = buffer +" "+temp->str ;
                }
            return buffer;
        }
        