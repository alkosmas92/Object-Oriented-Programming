# simple-project-with-c-

 I Implement the C ++ the image of a discussion forum, e.g. “Object Oriented Program-as described below. 
 A forum it consisted of its "title" and a number of threads.
Each thread consists of a "theme", its "creator", the "creation date" and a host of posts. Each post consists of a "numeric identifier" (id, unique for each post), the Its "title", its "creator", its "creation date" and a text. 
   When creating a post, the values of the data are assigned and printed on the screen. When destroyed, the message "Post number: ⟨Post_number⟩ is about to be destroyed ", where⟨Post_number⟩is the numerical reference feature of the post. 
  When creating a thread, its subject, creator and date are assigned of its creation. Also it is printed on the screen the message "Thread with subject:" ⟨Subject⟩ has just been created! ", where the ⟨Subject⟩ is the subject of the thread. When a threadis destructioned,  the message is printed on the screen, "Thread with subject: ⟨Subject⟩ is about to be destroyed ", where ⟨Subject⟩ is the subject of the thread.
When creating a forum, its title is assigned and the message "Forum with title: ⟨Title⟩ has just been created! ", where ⟨Title⟩ is the title of the forum. When destroyed, is displayed on the screen the message "Forum with title: ⟨Title⟩ is about to be destroyed ", where ⟨Title⟩ is the topic of the forum.
 Regarding the behavior of the above, the following applies. For the forum to given the ability to be printed, by printing the titles of its threads. Also given the ability to select a thread by specifying the title and then print the thread. Finally, for the forum to be given the opportunity to select a post, giving it number and then this post to be printed.
 A thread is printed by printing its subject, its creator, the date of publication, his creator and his posts.
 A post is printed, printing its number, its title, its creator, the date of its creation and its text.
 
Example with :
1. I create a forum entitled "Object Oriented Programming"
2. I print the forum
3. I print the thread on "Rules and useful information"
4. I select (randomly) some posts, and print them.

Αssumptions :

-Δηλώνω την class String και class PlaneComponent πριν την πριν της ορίσψ γιατι της καλώ πριν την αρχικοποιησής
τους

-namespace patch το ορίζω γιατί είχα πρόβλημα με την συνάρτηση to_string

-Abstract classes οι Object, Employee, PlaneComponent

-class Object : ορίζω την protected to object_id to οποιο οριζεται εκτός κλάσης και αυξάνεται καθε φορά για
μοναδικότητα και δημιουργώ καποιες βασικές συναρτήσεις και με virtual Object* clone()=0 και String toString()=0
-class String: με κληρονομικότητα απο Object με protected name και δημιουργία βασικών συναρτήσεων με χρήση
έτοιμων συναρτήσεων απο βιβλιοθήκη
- class Employee: public Object με protected String* name_employee και όρισμα virtual workon(PlaneComponent*
pas_com)=0 και report(PlaneComponent* pas_com)=0
- class PlaneComponent : public Object με protected: bool check_clean , bool check_security , bool
check_maintenance οι οποιες μεταβλητές θα αρχικοποιηθούν 0 ως ένδιξη οτι δεν εχουν υλοποιηθεί οι αντιστοιχες
εργασίες που τους αναλογούν,ορίζονται και αντιστοιχες συναρτησείς που βοηθούν την διαχείρηση τους και με το
όρισμα ως virtual την bool ready_check()=0 , virtual void process(Employee* empl)=0
-class SecurityEmployee:public Employee σημαντικο σημειο της κλασής η χρήση των workon και report συναρτήσεων
οι οποίες συνδένται με την PlaneComponent και υλοποιυν τον έλενχο αν έγινε η εργασια και αλλάζουν την
check_security σε 1 ετσι ωστε μας δηλώνει οτι πέρασε η εργασια εκτελέστηκε αλλα και με το report το οποιο
εκτυπώνει και το αντίστοιχο ΟΚ.
- class MaintenanceEmployee:public Employee και class CleaningEmployee:public Employee αντίστοιχες με class
SecurityEmployee:public Employee.
-class Passengercompartment:public PlaneComponent με private Passengercompartment* pas_com = NULL για ελενχο
αν υπαχρει περαιτέρο Passengercompartment και αντιστοιχει constractor για να ικανοποιεί ολες τις συνθήκες με
αντίστοιχη προυπόθεση και στην process η οποία μας οδηγεί το εργαζόμενο να κάνει την εργασία του και να ελένχεται
στην ready_check αν έγιναν ολες οι απαραίτητες του τομέα,και στην equal να γίνονται μια σειρά απο ελένχους.
-PrivateCompartment : public PlaneComponent απλα εναν constractor και εναν distractor
-class EquipmentCompartment : public PrivateCompartment παρόμοιες λειτουργίς με την Passengercompartment με
διαφορα στους την αφαίρεση των ελένχων για τον επιπλέον χώρο
- CargoBay : public PrivateCompartment αντιστοιχες λειτουργιες με SecurityEmployee αλλά χωρίς αμφιβολία για
επιπλέον χώρο εξοπλισμού.
-class Plane : public Object τελική κλάση με private:
String *title;
int space_passenger
CargoBay * cargo_bay
EquipmentCompartment* pas_one
EquipmentCompartment* pas_two
EquipmentCompartment* pas_three
vector<Passengercompartment*> Passenger_compartment
με αντιστοιχες αρχικοποιησεις στον constractor με τις βασικες συναρτήσεις να διατηρουν την προηγουμενη τους
λογίκη αλλά σε μεγαλύτερη εκταση των ελένχων και με τον vector<Passengercompartment*> Passenger_compartment
να προσθέτει καποια στιχεία.
-clone_encrypt_and_print απλη χρήση των συναρτήσεων
