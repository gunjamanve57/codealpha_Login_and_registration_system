#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

class User{
    private:
         string username;
         string password;

    public:
        // check duplication username
        bool userExists(string uname)
        {
            ifstream fin("user.txt");
            string u,p;
            while(fin>>u>>p)
            {
                if(u == uname)
                {
                    fin.close();
                    return true;
                }
            }
            fin.close();
            return false;
        }
        // Registration
        void registration(){
            cout<<"\n========== REGISTRATION ============\n";
            cout<<"Enter Username :\n";
            cin>>username;

            if(username.empty()){
                cout<<"Username cannot be empty!";
                return;
            }

            if(userExists(username))
            {
                cout<<"Username already exists.Try another username.\n";
                return;
            }
            cout<<"Enter password :";
            cin>>password;

            if(password.length()<6){
                cout<<" Password must be at least 6 character long!\n";
                return;
            }
            ofstream fout("users.txt",ios::app);
            fout<<username<<" "<<password<<endl;
            fout.close();
            cout<<"User Registered successfully!\n";
        }

        // Login
        void loginUser(){
            cout<<"\n============== LOGIN ==============\n";

            int attempts = 3;
            while(attempts--)
            {
                string uname,pass;

                cout<<"Enter Username: ";
                cin>>uname;

                cout<<"Enter  password: ";
                cin>>pass;

                ifstream fin("users.txt");

                string u,p;
                bool found =false;
   
                while(fin >> u >> p)
                {
                    if(u == uname && p == pass){
                        found =true;
                        break;
                    }
                }
                fin.close();

                if(found)
                {
                    cout<<"Login successful!\n";
                    return;
                }
                else{
                    cout<<"Invalid username && password!\n";
                    if(attempts>0){
                        cout<<"Attempts Left:"<< attempts <<endl;
                    }
                }
            }
            cout<<"Account Locked ! maximum login attempts exceeded.\n";
        }
};
int main(){
    User user;
    int choice;
    do{
        cout<<"\n============= LOGIN & REGISTRATION SYSTEM  ================\n";
        
        cout<<"1 Register\n";
        cout<<"2.Login\n";
        cout<<"3.Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice){
          case 1:
              user.registration();
               break;
          case 2:
              user.loginUser();
              break;
          case 3:
              cout<<"Thankyou for using the system!\n";
              break;
           default:
              cout<<"Invalid choice! Please Try Again.\n"  ;     
        }
    }while(choice != 3);
    return 0;
}