#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

//pinakes me dosmenes times
string thread_title[6]={"main και makefile","Posts με ίδια στοιχεία","~Ορίσματα Constructor","Κανόνες και χρήσιμες πληροφορίες","Return object","CLASSES"};
string thecreator[7]={" Kostas"," Alexandros"," Izampo"," Aggeliki"," Alexia"," Emi"," Glikeria"};
string post_subject[6]={" library","DI","Exams","Vatmoligia","Projects","Diadikastika"};
string text_post[9]={"Δομές tree,list "," Διαδικασία υποβολής"," Λιστα απο posts "," Αρχεία 2ης άσκησης"," Enhance function"," Merge Lists"," Enhance function"," Τυχαία κλήση destructor"," Άσκοπη κλήση constructor;"};

int id=0; //arxikopoisi tou id ton post

struct Date{ //domi imerominias
  private:
    string my_date;
  public:
    string set_date(const string date ){
      my_date=date;
      return my_date;
    }
};

class Post{ //domi post
  private:
    int post_id;
    string subject,creator,today,text;
    Date my_today;
  public:
    Post(){
        int position  = rand() % 6; //topothetisi timwn
        post_id=id++;
        subject=post_subject[position ];
        position  = rand() % 7;
        creator=thecreator[position ];
        position =rand() % 9;
        text=text_post[position ];
        today=my_today.set_date("12/12/2012");
    }

    ~Post(){
    cout<<"Post number:"<<post_id<<" is about to be destroyed"<<endl;
    }

    int id_post(){
        return post_id;
    }

    string post_creator(){
        return creator;
    }


    void print_post(){
      cout<<"Post ID is:"<< post_id <<" Subject post:"<< subject <<"  Creator is:"<< creator<< "  Text einai : " << text <<" Date is:"<< today <<endl;
    }

};

class Thread{
  private:

      string title,creator,today;
      Date my_today;
      Post *post[10]; //orizw statiko pinaka apo post
  public:
      Thread(){
        int position  = rand() % 6;
        title=thread_title[position ];
        position =rand()%7;
        creator=thecreator[position ];
        today=my_today.set_date("12/12/1512");

        for(int m=0;m<10;m++){  //pernw tis times twn post sto pinaka
            post[m]=new Post;
         }
      }

    ~Thread(){
      cout<<"Thread title is "<<title<<" is about to be destroyed"<<endl;
      for(int k=0;k<10;k++){
        delete post[k];
      }
    }
    string find_title(){
      return title;
    }

    void print_title(){
      cout<<"title is:"<<title<<endl;
    }

    Post* thread_return_post(int i){ //gurizei post
      return post[i];
    }

    string thread_return_creator_post(int i){
      return post[i]->post_creator();
    }

    void print_thread(){
       cout<<"Thread subject is "<<title<<" Creator is "<<creator<<" Date is "<<today<<endl;
       for(int m =0 ; m<10 ; m++){
         post[m]->print_post();
        }
      }

      int thread_return_id_post(int num){
              return post[num]->id_post();
      }

    void from_thread_to_print_post(int id){

      for(int i=0;i<10;i++){
            if(id==post[i]->id_post()){
          post[i]->print_post();
        }
      }
    }
};

class Forum {
    private:
        string forum_subject;
        Date my_today;
        string today;
        Thread *thread[15];
      public:
      Forum(string subject){
        forum_subject=subject;
        today=my_today.set_date("12/12/2012");
        cout<<"Forum with subject: "<<forum_subject<<" has just been created"<<endl;
        cout<<"Forum date: "<<today<<endl;
        for(int i=0;i<15;i++){
            thread[i]=new Thread;
          }
        }

        ~Forum(){
            for(int i=0;i<15;i++){
              delete thread[i];
            }
          }

      void print_threads(){ //ektipwnei ola ta threads
        for(int i=0;i<15;i++){
          cout<<thread[i]->find_title()<<endl;
        }
      }
      void find_the_thread(string title){ //ektipwnei ola ta post sugkekrimenou thread me
        int i=0;
        for (int i=0 ; i < 15 ; i++) {
            if(title == thread[i]->find_title()){
              thread[i]->print_thread();
              break;
            }
        }
      }

    void find_the_post(int num){ //ektipwnei ena post pou epilegoume
          for (int i=0 ; i<15 ; i++){
            for(int post_counter=0 ; post_counter <= 9 ; post_counter++){
                if( num == thread[i]->thread_return_id_post(post_counter)){
                    thread[i]->from_thread_to_print_post(num);
                    break;
                }
            }
          }
        }
  };

int main ()
{
  Forum forum("OPP");
  forum.print_threads();
  forum.find_the_thread("Κανόνες και χρήσιμες πληροφορίες");
  forum.find_the_post(12);
}
