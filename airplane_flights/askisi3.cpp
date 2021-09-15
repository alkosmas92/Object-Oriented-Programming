#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <cstdlib>
#include <sstream>


using namespace std;
int id=0; // use for unique id

class String; //use before create class String
class PlaneComponent; //use before create class PlaneComponent

namespace patch // i had problem with function to_string so find this ready code
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}



class Object{   //create Object with necessery function with virtual clone and toString
  protected:
    int object_id;
  public:
      Object()
      {
          object_id = id++;
          cout << "id is : " << object_id << endl ;
      }

       ~Object(){
          cout << " Object destroyed with id  :" << this->object_id <<  endl;
      }

       int get_id() {
        return object_id;
      }


       bool equal ( Object* x1){
          return x1->object_id==this->get_id();
      }

       bool identical( Object& x2){
          return this == &x2;
      }


      virtual Object*  clone()=0;

      virtual String toString()=0;
};

class String: public Object {
  protected:
      string name;
  public:
      String(std:: string s)
      {
          name=s;
          cout << "String created with id  "<< this->object_id << endl;
      }

      ~String(){
          cout << "String destroyed with id " << this->object_id << endl;
      }

      string get_string_name(){
          return this->name;
      }

      void print_string(){
          cout << this->name << endl;
      }

      int length(){
          string k=this->name;
          return k.length();
      }
      void clear(){
          this->name=this->name.erase();
      }

      String concat( String s){
          String app( name + s.get_string_name());
          return app;
      }

      char at(int k){
          return this->name.at(k);
      }

      void updateAt(int a,char b ){
        name[a]=b;
      }

       String* clone()
      {
          return (new String(*this));
      }

      bool equal ( String *x1){
          if(x1->object_id==this->get_id() && x1->name==this->name)
          {
            return 1;
          }
          else {
            return 0;
          }
      }

      bool identical( String* x2){
          return this == x2;
      }


      String toString(){
          std:: string k = "string with id  " + patch::to_string(this->object_id);
          String kr(k);
          return kr;
      }

 };

 class Employee: public Object{
 protected:
    String* name_employee ;
 public:
    Employee(){
      cout<<"create empleyee with id :" << this-> object_id <<endl;
    }

     ~Employee(){
      cout << "Employee destroyed with id :"<<this->object_id<<endl;
    }

    String* get_name_employee(){
      return this->name_employee;
    }

    virtual void workon(PlaneComponent* pas_com)=0;

    virtual void report(PlaneComponent* pas_com)=0 ;
 };




//
//
 class PlaneComponent:public Object {
 protected:

    bool check_clean; //use this bool in order to have check for ready_check by employee on cleaning
    bool check_security;  //use this bool in order to have check for ready_check by employee on security
    bool check_maintenance; //use this bool in order to have check for ready_check by employee on maintainance
   public:
     PlaneComponent(){
       check_clean=0;
       check_security=0;
       check_maintenance=0;
       cout << " PlaneComponent created with id " <<this->object_id << endl;
     }
      ~PlaneComponent(){
         cout << " PlaneComponent destroyed with id :" <<this->object_id<< endl;
     }

      bool get_check_maintenance(){
       return this->check_maintenance;
     }

      bool get_check_clean(){
       return this->check_clean;
     }
      bool get_check_security(){
       return this->check_security;
     }
      void set_check_clean(bool check){
       this->check_clean=check;
     }
      void set_check_security(bool check){
       this->check_security=check;
     }
     void set_check_maintenance(bool check){
       this->check_maintenance=check;
     }

    virtual  bool ready_check()=0;
    virtual  void process(Employee* empl)=0;


 };


 class SecurityEmployee:public Employee{
 public:
         SecurityEmployee(){
             name_employee = new String("unknow ");
             cout<< "SecurityEmployee created with id  : " << this->object_id <<endl;
         }
         ~SecurityEmployee(){
             delete name_employee;
             cout<<"SecurityEmployee destroyed with id  : "<< this->object_id <<endl;
         }

         void workon(PlaneComponent *pas){
             pas->set_check_security(1);
             report(pas);
         }
         void report(PlaneComponent *pas){
             cout<< " SecurityEmployee is OK"<<endl;
         }

         SecurityEmployee* clone()
         {
             return (new SecurityEmployee(*this));
         }


         bool equal(SecurityEmployee* sec_empl){
               if (sec_empl->get_id()==this->object_id && sec_empl->get_name_employee()->equal(this->name_employee) ){
                 return 1;
               }
           return 0;
         }


         bool identical( SecurityEmployee& x2){
             return this == &x2;
         }


         String toString(){
                 string str_SecurityEmployee = "SecurityEmployee with id : ";
                 str_SecurityEmployee = str_SecurityEmployee + patch::to_string(this->object_id);
                 String str_new(str_SecurityEmployee);

             return str_new.concat(*name_employee);
         }

     };

 class MaintenanceEmployee:public Employee{
 public:
       MaintenanceEmployee(){
         name_employee = new String("unknow");
         cout<< "MaintenanceEmployee created with id  : " << this->object_id <<endl;
       }
       ~MaintenanceEmployee(){
           delete name_employee;
           cout<<"MaintenanceEmployee destroyed with id  : "<< this->object_id <<endl;
       }

       void workon(PlaneComponent *pas){
           pas->set_check_maintenance(1);
           return report(pas);
       }
       void report(PlaneComponent *pas){
           cout<<" maintainanceEmployee is OK";

       }

       MaintenanceEmployee* clone()
       {
           return (new MaintenanceEmployee(*this));
       }


       bool equal(MaintenanceEmployee* main_empl){
             if (main_empl->get_id()==this->object_id && main_empl->get_name_employee()->equal(this->name_employee) ){
             return 1;
             }
             return 0;
       }


       bool identical( MaintenanceEmployee& x2){
           return this == &x2;
       }


       String toString(){
           string str_MaintenanceEmployee = "MaintenanceEmployee with id : ";
           str_MaintenanceEmployee = str_MaintenanceEmployee + patch::to_string(this->object_id);
           String str_new(str_MaintenanceEmployee);

         return str_new.concat(*name_employee);
       }
 };
 //
 class CleaningEmployee:public Employee{
 public:


   CleaningEmployee(){
         name_employee = new String("unknow");
         cout<< "CleaningEmployee created with id : " << this->object_id <<endl;
   }
   ~CleaningEmployee(){
         delete name_employee;
         cout<<"CleaningEmployee destroyed with id : "<< this->object_id <<endl;
   }

    void workon(PlaneComponent *pas){
          pas->set_check_clean(1);
           return report(pas);
   }
   void report(PlaneComponent *pas){
          cout<<" cleaningEmployee is OK";

    }

   CleaningEmployee* clone()
   {
          return (new CleaningEmployee(*this));
   }


   bool equal(CleaningEmployee* clea_empl){
          if (clea_empl->get_id()==this->object_id && clea_empl->get_name_employee()->equal(this->name_employee) ){
                  return 1;
              }
          return 0;
   }


    bool identical( CleaningEmployee& x2){
       return this == &x2;
     }


   String toString(){
        string str_CleaningEmployee = "CleaningEmployee with id : ";
        str_CleaningEmployee = str_CleaningEmployee + patch::to_string(this->object_id);
        String str_new(str_CleaningEmployee);

        return str_new.concat(*name_employee);
   }
 };


//
class Passengercompartment:public PlaneComponent{

  private:
      Passengercompartment* pas_com = NULL;
    public:
      Passengercompartment()
      {
        pas_com=new Passengercompartment(true);
        cout<<"the Passengercompartment created with id  "<<this->object_id<<endl;
      }
      Passengercompartment(bool check_more_compartment){
        if(check_more_compartment==1){
                cout<<"the Passengercompartment created with id  "<<this->object_id<<endl;
        }
      }
      ~Passengercompartment(){
        delete pas_com;
        cout << " PassengerCompartment destroyed with "<< id << endl;
      }

      Passengercompartment* get_check_more_compartment(){
        return pas_com;
      }

       void process(Employee* empl){
          empl->workon(this);
          if(this->pas_com!=NULL){
              this->pas_com->process(empl);
          }
      }

      bool ready_check(){
        if(this->get_check_clean()==1 && this->get_check_security()==1){
          cout<<"Passengercompartment OK!"<<endl;
          return 1;
        }
        else
        {
          cout<<"Passengercompartment NOT OK!"<<endl;
          return 0;
        }
      }
      Passengercompartment* clone()
      {
          return (new Passengercompartment(*this));
      }

      bool equal ( Passengercompartment* x1){
         if(x1->get_id() == this->object_id && x1->get_check_clean() == this ->check_clean && x1->get_check_security() == this->check_security )
          if( pas_com !=NULL && x1->get_check_more_compartment()!=NULL )
            if(pas_com->get_id() == get_check_more_compartment()->get_id() && pas_com ->get_check_clean() == x1->get_check_more_compartment()->get_check_clean() && pas_com->get_check_security() == x1 ->get_check_more_compartment()->get_check_security()){
              return 1;
            }
         else {return 0;}
      }

      bool identical(const Passengercompartment& x2){
       return this == &x2;
      }


  String toString(){
    string string_passengercompartment = "PassengerCompartment with id : ";
    string_passengercompartment = string_passengercompartment + patch::to_string(this->object_id);
    string_passengercompartment = string_passengercompartment + "check_security : ";
    if(check_security == 1){
      string_passengercompartment = string_passengercompartment + " true ";
    }
    else{
      string_passengercompartment = string_passengercompartment +" false ";
    }
    string_passengercompartment = string_passengercompartment + " check_clean : ";
    if(check_clean == 1){
      string_passengercompartment = string_passengercompartment + " true ";
    }
    else{
      string_passengercompartment = string_passengercompartment +" false ";
    }
    String str_new(string_passengercompartment);
    if(pas_com!=NULL){
      return str_new.concat(pas_com->toString());
   }
  return str_new;
  }
};

class PrivateCompartment : public PlaneComponent{


  public:
    PrivateCompartment()
    {
          cout<<"the PrivateCompartment created with id "<<this->object_id<<endl;
    }
    ~PrivateCompartment(){
        cout << " PrivateCompartment destroyed with id :" << this->object_id <<  endl;
    }
};

class EquipmentCompartment : public PrivateCompartment{

public:
  EquipmentCompartment()
  {
      cout<<"the EquipmentCompartment created with id "<<this->object_id<<endl;
  }
  ~EquipmentCompartment(){
      cout << " EquipmentCompartment  destroyed with" <<this->object_id << endl;
  }

  bool ready_check(){
    if( this->get_check_maintenance()==1 && this->get_check_security()==1){
      cout<<"EquipmentCompartment OK!"<<endl;
      return 1;
    }
    else
    {
      cout<<"EquipmentCompartment NOT OK!"<<endl;
      return 0;
    }
  }

  void process( Employee* empl){
     empl->workon(this);
   }

   EquipmentCompartment* clone()
     {
         return (new EquipmentCompartment(*this));
     }

   bool equal ( EquipmentCompartment* x1){
      if(x1->get_id() == this->object_id && x1->get_check_clean() == this ->check_clean && x1->get_check_security() == this->check_security && x1->get_check_maintenance() == this->check_maintenance )
          return 1;
      else
        return 0;
    }

    bool identical(const PrivateCompartment& x2){
      return this == &x2;
    }


   String toString(){
     string str_EquipmentCompartment = "EquipmentCompartment with id : ";
     str_EquipmentCompartment = str_EquipmentCompartment + patch::to_string(this->object_id);
     str_EquipmentCompartment = str_EquipmentCompartment + "check_security : ";
     if(check_security == 1){
       str_EquipmentCompartment = str_EquipmentCompartment + " true ";
     }
     else{
       str_EquipmentCompartment = str_EquipmentCompartment + " false ";
     }
     str_EquipmentCompartment = str_EquipmentCompartment + "check_clean : ";
     if(check_clean == 1){
       str_EquipmentCompartment = str_EquipmentCompartment + " true ";
     }
     else{
       str_EquipmentCompartment = str_EquipmentCompartment + " false ";
     }
     str_EquipmentCompartment = str_EquipmentCompartment + "check_security : ";
     if(check_security == 1){
       str_EquipmentCompartment = str_EquipmentCompartment + " true ";
     }
     else{
       str_EquipmentCompartment = str_EquipmentCompartment + " false ";
     }

     String str_new(str_EquipmentCompartment);

   return str_new;
   }
//
 };

class CargoBay : public PrivateCompartment{
private:

    EquipmentCompartment *eq_com;

public:
  CargoBay()
  {
    this->eq_com=new EquipmentCompartment;
    cout<<"the CargoBay created with id "<<this->object_id<<endl;
  }

  ~CargoBay(){
      delete eq_com;
      cout << " CargoBay destroyed with id  " <<this->object_id<< endl;
  }

  EquipmentCompartment* get_eq_com(){
      return eq_com;
  }


 bool ready_check(){
    if(this->get_check_clean()==1 && this->get_check_security()==1 && this->get_check_security()==1){
      cout<<"PassengerCompartment OK!"<<endl;
      return 1;
    }
    else
    {
      cout<<"PassengerCompartment NOT OK!"<<endl;
      return 0;
    }
  }

  void process(Employee* empl){
      empl->toString();
      empl->workon(this);
      eq_com->process(empl);
     }


   CargoBay* clone()
     {
         return (new CargoBay(*this));
     }

   bool equal ( CargoBay* x1){
      if(x1->get_id() == this->object_id && x1->get_check_clean() == this ->check_clean &&  x1->get_check_maintenance() == this->check_maintenance )
          return 1;
      else
        return 0;
    }

    bool identical(const CargoBay& x2){
      return this == &x2;
    }


     String toString(){
      string str_CargoBay = "CargoBay with id : ";
      str_CargoBay = str_CargoBay + patch::to_string(this->object_id);
      str_CargoBay = str_CargoBay + "check_security : ";
      if(check_security == 1){
            str_CargoBay = str_CargoBay + " true ";
      }
      else{
            str_CargoBay = str_CargoBay + " false ";
        }
      str_CargoBay = str_CargoBay + "check_clean : ";
      if(check_clean == 1){
            str_CargoBay = str_CargoBay + " true ";
      }
      else{
          str_CargoBay = str_CargoBay + " false ";
      }

      String str_new(str_CargoBay);
      str_new = str_new.concat(eq_com->toString());

      return str_new;
      }


 };







//
// //
// //
class Plane : public Object
{
private:
      String *title;
      int space_passenger;
      CargoBay *  cargo_bay;
      EquipmentCompartment* pas_one;
      EquipmentCompartment* pas_two;
      EquipmentCompartment* pas_three;
      vector<Passengercompartment*> Passenger_compartment;

public:
      Plane(){
          title = new String("Airbus");
          space_passenger=rand()%520;
          cargo_bay = new CargoBay();
          pas_one = new EquipmentCompartment();
          pas_two = new EquipmentCompartment();
          pas_three = new EquipmentCompartment();
          int passengercompartment_count = space_passenger/60;
          Passenger_compartment.resize(passengercompartment_count);
          for(int i=0 ; i < passengercompartment_count ; i++ ){
            Passenger_compartment[i] = new Passengercompartment();
          }
          cout<< "The plane with id  "<<this->object_id<<"created"<<endl;
      }
      String* get_title(){
        return this->title;
      }

      int get_space_passenger(){
        return this->space_passenger;
      }
      EquipmentCompartment* get_pas_two(){
        return this->pas_one;         //EquipmentCompartment
      }
      EquipmentCompartment* get_pas_one(){
        return this->pas_two;         //EquipmentCompartment
      }
      EquipmentCompartment* get_pas_three(){
        return this->pas_three;       //EquipmentCompartment
      }
      CargoBay* get_cargo_bay(){
        return this->cargo_bay;     //Cargo
      }

      vector<Passengercompartment*> get_Passengers_compartments(){
          return this->Passenger_compartment;
      }


  bool ready_check(){
    if(pas_one->ready_check() && pas_two->ready_check() && pas_three->ready_check() && cargo_bay->ready_check()){
      for(int i=0 ; i < Passenger_compartment.size() ; i++){
        if(Passenger_compartment[i]->ready_check()==false){
          return false;
        }
      }
      return true;
    }
    return false;
  }

    String toString(){
          std::string str_plane = "Plane with id  = ";
          str_plane = str_plane + patch::to_string(this->object_id);
          str_plane = str_plane + " name: Airbus  space_passenger =" + patch::to_string(space_passenger) + " and" ;
          String str_plane2(str_plane);
          String s(str_plane);
              str_plane2 = s.concat(cargo_bay->toString());
              s = str_plane2;
              str_plane2 = s.concat(pas_one->toString());
              s = str_plane2;
              str_plane2 = s.concat(pas_two->toString());
              s = str_plane2;
              str_plane2 = s.concat(pas_three->toString());
              s = str_plane2;
            for(int i=0 ; i < Passenger_compartment.size() ; i++ ){
                str_plane2 = s.concat(Passenger_compartment[i]->toString());
                s = str_plane2;
            }
            return str_plane2;
      }

      Plane* clone()
        {
            return (new  Plane(*this));
        }

      bool equal ( Plane* x1){
         if(x1->get_id() == this->object_id && this->title->equal(x1->get_title()) && x1->get_space_passenger() == this->space_passenger && cargo_bay->equal(x1->get_cargo_bay()))
         {
          if(pas_one->equal(x1->get_pas_one())/* && pas_two->equal(x1->get_pas_two()) && pas_three->equal(x1->get_pas_three())*/ && Passenger_compartment.size() == x1->get_Passengers_compartments().size())
            for (int i = 0; i < Passenger_compartment.size(); i++)
            {
              if (Passenger_compartment[i]->equal(x1->get_Passengers_compartments()[i]) == 0 ) {
                  return 0;
              }
            }
              return 1;
         }
         return 0;
       }

       bool identical(Plane& x2){
         return this == &x2;
       }


      void process(Employee* empl){
          String s = empl->toString();
          s.print_string();
          cargo_bay->process(empl);
          pas_one->process(empl);
          pas_two->process(empl);
          pas_three->process(empl);
          for(int i=0 ; i < Passenger_compartment.size() ; i++ ){
              Passenger_compartment[i]->process(empl);
          }
      }

      ~Plane(){
        delete title;
        delete cargo_bay;
        delete pas_one;
        delete pas_two;
        delete pas_three;
      for (vector<Passengercompartment*> :: iterator ch = Passenger_compartment.begin() ; ch !=Passenger_compartment.end(); ++ch)
      {
            Passengercompartment* go = *ch;
        delete  go;
        go=NULL;
      }
      Passenger_compartment.clear();
      cout<<"Plane destroyed with id  :" << this->object_id <<endl;
    }
  };


  void clone_encrypt_and_print(Object* object){
      String ob1ject_string = object->toString();
      String object_clone_string = object->clone()->toString();

    if (object->clone()->equal(object)){
       cout<<" EQUAL" << endl;
      }
    else{  cout<<" NOT EQUAL"<<endl;}

      cout<<" LENGTH :"<<object_clone_string.length()<<endl;

      for (int i = 0; i < rand() % object_clone_string.length(); i++) {
          object_clone_string.updateAt(rand() % object_clone_string.length() , object_clone_string.at(rand() % object_clone_string.length()) );
      }

      ob1ject_string.print_string();
      object_clone_string.print_string();
      String str = ob1ject_string.concat(object_clone_string);

      cout <<"LENGTH with concat "<<str.length()<< endl;
    if (str.length() % 2 == 1) {
          cout<< str.at(str.length() / 2)<< endl;
      }
    else{
          cout<< str.at(str.length() / 2)<< endl;
          cout<< str.at(str.length() / 2 +1)<< endl;

      }
      str.clear();
      cout<< "LENGTH with clear  " <<str.length()<<endl;

      }

int main(){
  Plane plane;
  SecurityEmployee securityEmployee;
  CleaningEmployee cleaningEmployee;
  MaintenanceEmployee maintenanceEmployee;

  plane.process (&securityEmployee);
  plane.process(&cleaningEmployee);

  plane.process (&maintenanceEmployee);
  if (plane.ready_check()) {
      cout << "Plane ready to take off!"<<endl;
  }
  clone_encrypt_and_print(&plane);

}
