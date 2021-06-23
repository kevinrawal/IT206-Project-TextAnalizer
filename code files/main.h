#include<bits/stdc++.h>
using namespace std;
#include"head1.h"
#include"head3.h"
#include"head4.h"
#include"head5.h"
#include"head6.h"

//For Opreration purpose

    class operation {
        public:
        list_for_words s2;                     //Declare list for word
        list_for_characters c1; 
        checkthepositive cpt;            //Declare list for char
        string mainstr;               //Declare  string for use
        int positive = 0; 
        int negetive = 0;                  
    //Diffrent function for diffrent purposes.
        void input();
        void character_details();
        void word_detail();
        void check_word();
        void plagrismcheck();
        void declare_word();
        void polarity();
        
    };

    //check wherther your text is positive or negative
    void operation::polarity()
    {
        cpt.polarity();
        node3*temp = s2.head;
        while(temp!= NULL)
        {
            if(search(temp->s,cpt.finalf,101))
            {
                positive++;
            }
            if(search(temp->s,cpt.negetiveword,101))
            {
                negetive++;
            }
            temp = temp->next;
        }
        cout<<"Negitive : "<<(float)negetive/(float)s2.no_words<<endl;
        cout<<"Positive  :"<<(float)positive/(float)s2.no_words<<endl;
        if(((float)negetive/(float)s2.no_words)  > ((float)positive/(float)s2.no_words))
        {
            cout<<"Your Text's sentiment is Negitive"<<endl;
        }
        else if(((float)negetive/(float)s2.no_words) < ((float)positive/(float)s2.no_words))
        {
            
            cout<<"Your Text's sentiment is Positive"<<endl;
        }
        else{
            cout<<"Your Text's sentiment is neutral"<<endl;
        }
    }
    //Taking inout from user
    void operation::input(){
    string strbuffer;
    string strtemp;
    int i = 0;
    while (1)
    {
        //Code for taking multple lines
        cin >> strtemp;
        if (strtemp == "###")
        {
            break;
        }

        if (i == 0)
        {
            strbuffer.append(strtemp);
        }
        else
        {
            strbuffer.append(" ");

            strbuffer.append(strtemp);
        }
        i++;
    }
    mainstr = strbuffer;

    }

    //print character detail
    void operation::character_details(){
            c1.crete(mainstr);
            c1.display();
    }

    
    //print word detail
    void operation::word_detail(){
    s2.display();

    }
    //store words in stack using below code and then use it for display detail
    void operation::declare_word()
    {

    int n = mainstr.length();
    int j = 0;
    string strtemp_2 = "";
    //we are store input as a words 
    while (n > 0)
    {
        if (mainstr[j] == ' ' || mainstr[j] == ',' || mainstr[j] == '?' || mainstr[j] == '.' || mainstr[j] == '!')
        {
            if (mainstr[j] == ' ')
            {
                if (!strtemp_2.empty())
                {
                    s2.insert(strtemp_2);
                    strtemp_2.clear();
                }
            }
            if (mainstr[j] == ',' || mainstr[j] == '?' || mainstr[j] == '.' || mainstr[j] == '!' || mainstr[j] == '>')
            {
                if (!strtemp_2.empty())
                {
                    s2.insert(strtemp_2);
                    strtemp_2.clear();
                }
                else
                {
                    strtemp_2.clear();
                }
            }
        }
        else
        {
            strtemp_2 = strtemp_2 + mainstr[j];
        }
        j++;
        n--;
    }
    if (!strtemp_2.empty())
    {
        s2.insert(strtemp_2);
        strtemp_2.clear();
    }
    }

    //detect word in your text
    void operation::check_word(){
    s2.detect();
    }
    

   //plagarism (or copy) cheker code
    void operation::plagrismcheck(){
    //declaring two string storage (use of linked list)
    storage_for_string s1, s2;

    //taking input from user
    cout << "enter the text on which you want to check plagarism" << endl;
    while (1)
    {
        string s;
        cin >> s;
        if (s == "###")
        {
            break;
        }

        if(!(s=="is" || s=="a" || s=="an" || s=="i" || s=="the")){
            s1.insert(s);
        }
        
    }
    cout << "enter the source text" << endl;
    while (1)
    {
        string s;
        cin >> s;
        if (s == "###")
        {
            break;
        }
         if(!(s=="is" || s=="a" || s=="an" || s=="i" || s=="the")){
            s2.insert(s);
        }
    }

    //convert in to small alfabet (ex: Abc = abc)
    for (int i = 0; i < s1.total_words; i++)
    {
        s1.change_in_small(s1.give(i + 1), i + 1);
    }

    for (int i = 0; i < s2.total_words; i++)
    {
        s2.change_in_small(s2.give(i + 1), i + 1);
    }

    
    //---------------------------------------------------------------------------------
    if (s1.total_words == s2.total_words || s1.total_words==1)
    {
        //variable that count total no of string and match 
        int total_strings = 0;
        int total_mach = 0;
        for (int i = 1; i <= s1.total_words; i++)
        {
            int count_me = 0;
            int max = -1;
            total_strings++;
            for (int j = i; j <= s1.total_words; j++)
            {
                count_me++;
                if (count_me < 20)
                {
                    string str1 = s1.create_string(i, j);
                    string str2 = s2.create_string(1, s2.total_words);

                    //call hash function
                    int ch = search(str1, str2, 101);
                    if (ch == 1)
                    {
                        if (max < j - i)
                        {
                            max = j - i;
                        }
                    }
                }
            }
            if (max >= 0)
            {
                total_mach++;
            }
        }
        float ans = (float)total_mach / (float)total_strings * 100;
        if(ans==100){
            cout<<"text is fully copied from source text"<<endl;
            cout<<"text mach :"<<ans<<"%"<<endl;
        }
        
        //check if the lenght is same but text is not 100% matching below code is same as above but difference is in taking
        //pattern string

        if(ans != 100){
            total_strings = 0;
             total_mach = 0;
                for (int i = 1; i <= s1.total_words; i++)
        {
            int count_me = 0;
            int max = -1;
            total_strings++;
            for (int j = i; j <= s1.total_words; j++)
            {
                count_me++;
                if ( count_me>=2 && count_me < 20)
                {
                    string str1 = s1.create_string(i, j);
                    string str2 = s2.create_string(1, s2.total_words);
                    int ch = search(str1, str2, 101);
                    if (ch == 1)
                    {
                        if (max < j - i)
                        {
                            max = j - i;
                        }
                    }
                }
            }
            if (max >= 0)
            {
                total_mach++;
            }
        }

        float ans =  (float)total_mach / (float)total_strings * 100 ;
        if(ans==0){
            cout<<"text is not copied from source text"<<endl;
            cout<<"text mach :"<<ans<<"%"<<endl;
        }
        else if(ans>0 && ans<=30){
             cout<<"there is very less chance that text is copied from source text"<<endl;
            cout<<"text mach :"<<ans<<"%"<<endl;
        }
        else if(ans>30 && ans<=50){
            cout<<"may be text is copied from source text"<<endl;
            cout<<"text mach :"<<ans<<"%"<<endl;
        }
        else if(ans>50 && ans<=80){
             cout<<"there heigh chance  that text is copied from source text"<<endl;
            cout<<"text mach :"<<ans<<"%"<<endl;
        }
        else{
            cout<<"text is copied from source text"<<endl;
            cout<<"text mach :"<<ans<<"%"<<endl;
        }

        }

    }
    else    //if lenth of both text is not same
    {
        int total_strings = 0;
       int total_mach = 0;

        for (int i = 1; i <= s1.total_words; i++)
        {
            int count_me = 0;
            int max = -1;
            total_strings++;
            for (int j = i; j <= s1.total_words; j++)
            {
                count_me++;
                if ( count_me>=2 && count_me < 20)
                {
                    string str1 = s1.create_string(i, j);
                    string str2 = s2.create_string(1, s2.total_words);
                    int ch = search(str1, str2, 101);
                    if (ch == 1)
                    {
                        if (max < j - i)
                        {
                            max = j - i;
                        }
                    }
                }
            }
            if (max >= 0)
            {
                total_mach++;
            }
        }

       float ans =  (float)total_mach / (float)total_strings * 100 ;
        if(ans==0){
            cout<<"text is not copied from source text"<<endl;
            cout<<"text mach :"<<ans<<"%"<<endl;
        }
        else if(ans>0 && ans<=30){
             cout<<"there is very less chance that text is copied from source text"<<endl;
            cout<<"text mach :"<<ans<<"%"<<endl;
        }
        else if(ans>30 && ans<=50){
            cout<<"may be text is copied from source text"<<endl;
            cout<<"text mach :"<<ans<<"%"<<endl;
        }
        else if(ans>50 && ans<=80){
             cout<<"there heigh chance  that text is copied from source text"<<endl;
            cout<<"text mach :"<<ans<<"%"<<endl;
        }
        else if(ans>80 && ans<100){
            cout<<"text is copied from source text"<<endl;
            cout<<"text mach :"<<ans<<"%"<<endl;
        }
        else{
            cout<<"text is fully copied from source"<<endl;
            cout<<"text mach :"<<ans<<"%"<<endl;
        }
        
    }
    }