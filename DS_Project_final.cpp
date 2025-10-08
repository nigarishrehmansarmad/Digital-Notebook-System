#include<iostream>
#include<fstream>
using namespace std;

struct subject{
	string note[10];
	string date;
	string topic;
};
class Node{
	public:
		subject data;
		Node* next;
		
		Node(){
			this->data.date="";
			this->data.topic="";
			for(int i=0;i<10;i++){
                this->data.note[i]="";
            }
            this->next=NULL;
		}
		
        Node(subject &d){
            this->data.date=d.date;
            this->data.topic=d.topic;
            for(int i=0;i<10;i++){
                this->data.note[i]=d.note[i];
            }
            this->next=NULL;
        }
};

class Notebook{
    public:
        Node* head;
        Node* tail;
        Notebook(){
            head=new Node();
            tail=head;
       }
        Notebook(subject d){
            head=new Node(d);
            tail=head;
        }
void editFile(string filename, string topic) {
    ifstream fin(filename.c_str());
    ofstream fout("temp.txt"); 

    string line;
    bool found = false;

    while (getline(fin, line)) {
        if (line.find("Topic: " + topic) != string::npos) {
            found = true;
            cout << "Editing Lecture for Topic: " << topic << endl;

            cout << "Enter new date: ";
            cin >> line; 
            fout << "Date: " << line << endl;

            cin.ignore(); 
            cout << "Enter new Topic: ";
            getline(cin, line); 
            fout << "Topic: " << line << endl;

            cout << "Enter new Notes:" << endl;
            for (int i = 0; i < 10; i++) {
                getline(cin, line); 
                fout << line << endl;
            }

            while (getline(fin, line) && line.find("-------------------------") == string::npos) {
            }

            while (getline(fin, line)) {
                fout << line << endl;
            }

            cout << "Lecture edited and saved successfully." << endl;
        } else {
            fout << line << endl;
        }
    }

    fin.close();
    fout.close();

    if (!found) {
        cout << "Topic not found in file." << endl;
    } else {
        remove(filename.c_str());
        rename("temp.txt", filename.c_str());
    }
}

void insertend(string filename){
        subject lec;
        cout<<"Enter date:";
        cin>>lec.date;
        cout<<"Enter Topic:";
        cin.ignore();
        getline(cin, lec.topic);
       
        cout << "Enter Notes:" << endl;
        for (int i = 0; i < 10; i++) {
            getline(cin,lec.note[i]);
        }

        ofstream fout(filename.c_str(), ios::app);
        fout << "Date: " << lec.date << endl;
        fout << "Topic: " << lec.topic << endl;
        fout << "Notes:" << endl;
        for (int i = 0; i < 10; i++) {
            fout << "o "<<lec.note[i] << endl;
        }
   
    fout.close();
        Node* newnode=new Node(lec);
        newnode->next=NULL;
        tail->next=newnode;
        tail=newnode;
}

void print(string filename){
    ifstream fin(filename.c_str());
   
    string line;
   
    while (getline(fin, line)) {
       
        cout << line << endl;
    }
    fin.close();
}

    void search(string filename, string topic) {
    ifstream fin(filename.c_str());

    string line;
    bool found = false;

    while (getline(fin, line)) {
        if (line.find("Topic: " + topic) != string::npos) {
            found = true;
            cout << line << endl;
            getline(fin, line);
            cout << line << endl;
            for (int i = 0; i < 10; i++) {
                getline(fin, line);
                cout << line << endl;
            }
            cout << "-------------------------" << endl;
            break;
        }
    }

    fin.close();

    if (!found) {
        cout << "Topic not found in file." << endl;
    }
}
   
   
void MNU(string filename){
    int c;
    while(c!=5){
    cout<<"1.Add Lecture"<<endl;
    cout<<"2.Edit lecture"<<endl;
    cout<<"3.View lecture"<<endl;
    cout<<"4.Search topic"<<endl;
    cout<<"5.Back to Main"<<endl;
    cin>>c;
    
    switch(c){
    	
    case 1:{
       insertend(filename);
       break;
    }
    case 2:{
        string t;
        cout<<"Enter topic to Edit:";
        cin>>t;
        editFile(filename,t);
        break;
    }
    case 3:{
        print(filename);
        break;
    }
    case 4:{
        string topic;
        cout<<"Enter lecture topic:";
        cin>>topic;
        search(filename,topic);
        break;
    }
    case 5:{
        break;
    }
    default:
        cout<<"Invalid choice"; 
   }
   
}
}
void printList() {
    Node* current = head->next;

    while (current != NULL) {
        cout << "Date: " << current->data.date << endl;
        cout << "Topic: " << current->data.topic << endl;
        cout << "Notes:" << endl;
        for (int i = 0; i < 10; i++) {
            cout << current->data.note[i] << endl;
        }
        cout << "-------------------------" << endl;

        current = current->next;
    }
}

};
int main(){
    Notebook DS;
    Notebook DIS;
    Notebook PR;
    Notebook PAI;
    Notebook MM;
    int ch;
    while(ch!=6){
        cout<<"----------------------MENU----------------------"<<endl;
        cout<<"1.Data Structures"<<endl;
        cout<<"2.Discrete"<<endl;
        cout<<"3.Probability"<<endl;
        cout<<"4.PAI"<<endl;
        cout<<"5.Marketing Management"<<endl;
        cout<<"6.Exit"<<endl;


        cin>>ch;
        switch(ch){
		case 1:{
		    DS.printList();
            DS.MNU("dsfile.txt");
            break;
        }
        case 2:{
            DIS.MNU("discrete.txt");
            break;
        }
        case 3:{
            PR.MNU("prob.txt");
            break;
        }
        case 4:{
            PAI.MNU("pai.txt");
            break;
        }
        case 5:{
            MM.MNU("mm.txt");
            break;
        }
        case 6:{
            break;
        }
        default:{
        cout<<"Notebook not found"<<endl;;
        break;
        }
    }
}
}
