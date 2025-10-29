C++ Console Login System 🔐
A simple C++ console app for user registration, login, and password recovery, with all data saved to a local data.txt file.

✨ Features
User Sign Up

User Log In

Forgot Password

Data saved to data.txt

🚀 How It Works
The LoginSystem class manages all logic. ofstream (output stream) is used in signup() to write new user data to data.txt. ifstream (input stream) is used in login() to read the file and find a matching user.

💡 Code Highlights
1. The Class "Blueprint"
C++

class LoginSystem{
    private:
        string username, password, email;
    public:
        void signup();
        void login();
        void forgotPassword();
};
2. Signing Up (Writing to File)
We use ofstream in ios::app (append mode) to add new users without erasing old ones.

C++

#include <fstream> // Add this header

void signup(){
    // ...get user, email, pass...
    ofstream file;
    file.open("data.txt", ios::app); 
    file << username << endl;
    file << email << endl;
    file << password << endl;
    file.close();
}
3. Logging In (Reading from File)
We use ifstream and a while loop to read the file 3 lines at a time (user, email, pass) to find a match.

C++

#include <fstream> // Add this header

void login() {
    // ...get search_user, search_pass...
    ifstream file("data.txt");
    bool found = false;

    while (getline(file, username) && getline(file, email) && getline(file, password)) {
        if (username == search_user && password == search_pass) {
            found = true;
            break; // Found them!
        }
    }
    // ...check if 'found' is true or false...
}
4. The cin.ignore() Trick
This vital line clears the "Enter" key press left by the menu's cin >> choice;, preventing getline() from skipping input.

C++

cin.ignore(); 
cout << "Enter username: ";
getline(cin, username); // This now works correctly
💻 How to Run
Save the code as login.cpp.

Compile it: g++ login.cpp -o login

Run it: ./login
