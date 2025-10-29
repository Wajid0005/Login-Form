#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class LoginSystem{
    private:

    string username, password, email;

    public:
     void signup(){
        cout<< "----SIGN-UP----" << endl;

        cin.ignore();

        cout <<"Enter username: ";
        getline(cin,username);

        cout <<"Enter email: ";
        getline(cin, email);

        cout <<"Enter password: ";
        getline(cin, password);

        ofstream file;
        file.open("data.txt", ios::app);

        if (file.is_open()) {

            file << username << endl;
            file << email << endl;
            file << password << endl;
            file.close();

        cout <<"Registration successful!" << endl;
        } else {
            cout <<"Error: Could not open file for writing." << endl;
        }

     }
     void login() {
            cout << "--- LOGIN ---" << endl;
            cin.ignore();

            string search_user, search_pass;
            cout << "Enter username: ";
            getline(cin, search_user);

            cout << "Enter password: ";
            getline(cin, search_pass);

            ifstream file("data.txt");
            bool found = false;

            if(file.is_open()) {

                while (getline(file, username) && getline(file, email) && getline(file, password)) {

                if (username == search_user && password == search_pass) {
                    found = true;
                    cout << "Login successful!" << endl;
                    cout << "Welcome, " << username << "!" << endl;
                    cout << "Your email is: " << email << endl;
                    break;
                }
            }
            file.close();
     }      else {
                cout << "Error: Could not open the file for reading. " << endl;
     }
     if (!found){ 
        cout<< "Login failed: User not found or incorrect password. "<<endl;
     }
    }

     void forgotPassword() {
            cout << "--- FORGOT PASSWORD ---" << endl;
            cin.ignore();


            string search_user, search_email;
            cout<< "Enter your username: ";
            getline(cin, search_user);

            cout << "Enter your email: ";
            getline(cin, search_email);

            ifstream file("data.txt");
            bool found  = false;

            if (file.is_open()) {

                while (getline(file, username) && getline(file, email) && getline(file, password)) {

                    if (username == search_user && email == search_email) {
                        found = true;
                        cout << "Acoount found!" << endl;
                        cout<< "Your password is: " << password << endl;
                        break;
                    }
                }
                file.close();

            } else {
                cout << "Error: Could not open the file for reading." << endl;

            }
            if (!found) {
                cout << "Account not found with the provided username and email." << endl;
            }
        }
};



int main()  {
    LoginSystem user;


    int choice;
    cout <<"1. Login"<< endl;
    cout <<"2. Sign-up (Registration)"<<endl;
    cout <<"3. Forgot Password"<< endl;
    cout <<"4. Exit"<< endl;
    cout <<"Enter your choice: ";

    cin >> choice;


    switch (choice) {
        case 1: 

        user.login();
        break;
        case 2:
            user.signup();
            break;

        case 3:
            user.forgotPassword();
            break;


        case 4:
            cout<< "Goodbye!"<< endl;
            break;
        default:
            cout<< "Invalid choice. Please try again."<<endl;
            break;


    }

    return 0;

}