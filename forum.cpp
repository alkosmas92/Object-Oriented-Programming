#include <iostream>
#include <string>
#include <cstdlib>


using namespace std;

string thread_title[6]={"main και makefile","Posts με ίδια στοιχεία","~Ορίσματα Constructor","Πρόβλημα με την συνάρτηση","Return object","CLASSES"};
string thecreator[7]={" Kostas"," Alexandros"," Izampo"," Aggeliki"," Alexia"," Emi"," Glikeria"};
string post_subject[6]={" library","DI","Exams","Vatmoligia","Projects","Diadikastika"};
string text_post[9]={"Δομές tree,list "," Διαδικασία υποβολής"," Λιστα απο posts "," Αρχεία 2ης άσκησης"," Enhance function"," Merge Lists"," Enhance function"," Τυχαία κλήση destructor"," Άσκοπη κλήση constructor;"};

int id=0;


struct Date{
  private:
    string my_date;
  public:
    string set_date(const string date ){
      my_date=date;
      return my_date;
    }
};

class Post{
  private:
    int post_id;
    string subject,creator,today,text;
    Date my_today;
  public:
    Post(){
        int position  = rand() % 6;
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
      Post *post[10];
  public:
      Thread(){
        int position  = rand() % 6;
        title=thread_title[position ];
        position =rand()%6;
        creator=thecreator[position ];
        today=my_today.set_date("12/12/2012");

        for(int m=0;m<10;m++){
            post[m]=new Post;
          }
      }

    ~Thread(){
      cout<<"Thread subject is "<<title<<" is about to be destroyed"<<endl;
      for(int k=0;k<10;k++){
        delete post[k];
      }
    }
    string thread_subject(){
      return title;
    }

    Post* thread_return_post(int i){
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

      int thread_return_id_post(int i){
              return post[i]->id_post();
      }

    void thread_return_print_post(int num){
      for(int i=0;i<10;i++){
        if(num==post[i]->id_post()){
          post[i]->print_post();
        }
      }
    }
};

struct List_node{
    Post* data = NULL;
    List_node *next = NULL;

    ~List_node(){
      delete data;
    }
};

class List{
  private:
      List_node  *head,*length;
  public:
    List(){
      length=NULL;
      head=NULL;
    }

    ~List(){
      List_node* node=head;
      while (node){
        head=node->next;
        delete node;
        node=head;
      }
    }

    void add(Post* value){

        List_node* list_node = new List_node;
        Post* post=new Post(*value);
        list_node-> data = post;
        list_node-> next = this->head;
          this->head = list_node;
          this->length = list_node;
    }

    void print_list(){
      List_node* head = this->head;
      while(head){
      cout <<"data is: ";
      head->data->print_post() ;
          head = head -> next;
      }
    }
    void setHead(List_node* head_new){
        head=head_new;
    }

    List_node* return_head(){
        return head;
    }

    List_node* return_length(){
        return length;
    }

    void c_Lists(List_node* newhead){
        while (newhead){
            Post* post=new Post(*newhead->data);
            List_node* node =new List_node;
            node->data=post;
            node->next=NULL;
            length->next=node;
            length=node;
            newhead=newhead->next;
        }
    }
};

struct Tree_node {
  string creator;
  List list_post;
  Tree_node *right=NULL,*left=NULL;

  };

  class Tree{
    private:
      Tree_node* root=NULL;
    public:

    Tree(Thread* thread){
        string creator = thread -> thread_return_creator_post(0);
        Post* save_post = thread->thread_return_post(0);
        root=new Tree_node;
        root->creator = creator ;
        root->list_post.add(save_post);
          Tree_node *node;
          node = root;
        for(int i=1; i < 10 ; i++){
          root=node;
            while (root){

              if( thread->thread_return_creator_post(i) < root->creator ){

                if(root->left==NULL){
                  save_post = thread->thread_return_post(i);
                  root->left =new Tree_node;
                  root->left->creator = thread->thread_return_creator_post(i);
                  root->left->list_post.add(save_post);
                  break;
                }
                else{
                  root=root->left;
                }
              }
              else if( thread->thread_return_creator_post(i) > root->creator ){
                  if(root -> right == NULL){
                    save_post = thread->thread_return_post(i);
                    root->right =new Tree_node;
                    root->right->creator = thread->thread_return_creator_post(i);
                    root->right->list_post.add(save_post);
                    break;
                  }
                  else {
                      root=root->right;
                  }
              }
              else if(thread->thread_return_creator_post(i) == root->creator ){
                save_post = thread->thread_return_post(i);
                root->list_post.add(save_post);
                break;
              }
          }

      }
      root = node;
    }

      Tree_node* getRoot(){
        return root;
      }

    ~Tree(){
        destroy_node(root);
      }

    void Tree_enhance(Tree_node* tree_node){
      if(tree_node==NULL){
        return;
      }
      Tree_enhance(tree_node -> left);
      Tree_node* test;
      test = root;
      while( tree_node ){
        if(tree_node->creator < test->creator){
          if(test->left==NULL){
              test->left=new Tree_node;
              test->left->creator = tree_node->creator;
              test->left->list_post.add((tree_node->list_post.return_head())->data);
            if(tree_node->list_post.return_head()->next != NULL){
              test->left->list_post.c_Lists(tree_node->list_post.return_head()->next);
            }
            break;
          }
          else{
            test=test->left;
        }
      }
        else if(tree_node->creator > test->creator){
            if(test->right==NULL){
                test->right=new Tree_node;
                test->right->creator = tree_node->creator;
                test->right->list_post.add((tree_node->list_post.return_head())->data);
              if(tree_node->list_post.return_head()->next != NULL){
                  test->right->list_post.c_Lists(tree_node->list_post.return_head()->next);
                }
              break;
            }
            else{
              test=test->right;
          }
        }
        else if(tree_node->creator == test->creator){
          test->list_post.c_Lists(tree_node->list_post.return_head());
          break;
        }
      }
      Tree_enhance(tree_node -> right);
    }

    void print_tree_node(Tree_node* node){
          if (node == NULL){
              return;
          }
            print_tree_node(node->left);
            cout<<"The creator  "<<node->creator << "  have post with follow data" <<endl;
            node->list_post.print_list();
            print_tree_node(node->right);
    }

    void print_Tree(){
        print_tree_node(root);
        }

    void destroy_node(Tree_node* node)
    {
        if (node == NULL){
            return;
          }
            destroy_node(node->left);
            destroy_node(node->right);
            delete node;
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


      void print_threads(){
        for(int i=0;i<15;i++){
          cout<<thread[i]->thread_subject()<<endl;
        }
      }
      void find_the_thread(string a){
        int i=0;
        for (int i=0 ; i < 15 ; i++) {
            if(a == thread[i]->thread_subject()){
              thread[i]->print_thread();
            }
        }
      }

      void find_the_post(int num){
            for (int i=0 ; i<15 ; i++){
              for(int post_counter=0 ; post_counter <= 2 ; post_counter++){
                  if( num == thread[i]->thread_return_id_post(post_counter)){
                      thread[i]->thread_return_print_post(num);
                      break;
                  }
              }
            }
          }

  void print_sorted(){
    Tree** end_tree;
    end_tree = new Tree*[15];
      for (int i = 0; i < 15; i++) {
          end_tree[i]=new Tree(thread[i]);
      }
      for (int i = 1; i < 15; i++) {
          end_tree[0]->Tree_enhance(end_tree[i]->getRoot());
      }
      end_tree[0]->print_Tree();
      cout<<endl;
      for(int i =0 ; i< 15 ; i++){
          delete  end_tree[i];
      }
      delete[]  end_tree;
  }
};



int main(){
  Forum forum("OOP");
  forum.print_sorted();

  return 0;
}
