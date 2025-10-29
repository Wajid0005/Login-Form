# 🔐 C++ Console Login System

A simple **C++ console app** for user registration, login, and password recovery — all data saved locally in `data.txt`.

---

## ✨ Features

* Sign Up
* Log In
* Forgot Password
* Data saved to `data.txt`

---

## ⚙️ How It Works

The `LoginSystem` class manages all logic using file handling:

* **`ofstream`** writes new users (append mode).
* **`ifstream`** reads and verifies login credentials.

---

## 💻 Example Code Snippets

**Class Blueprint**

```cpp
class LoginSystem {
private:
    string username, password, email;
public:
    void signup();
    void login();
    void forgotPassword();
};
```

**Sign Up**

```cpp
ofstream file("data.txt", ios::app);
file << username << endl << email << endl << password << endl;
file.close();
```

**Log In**

```cpp
ifstream file("data.txt");
while (getline(file, username) && getline(file, email) && getline(file, password))
    if (username == u && password == p) found = true;
```

---

## ▶️ Run It

```bash
g++ login.cpp -o login
./login
```

---

## 📂 Data Format

```
username
email
password
```

---

## 🧠 Tip

Use `cin.ignore()` before `getline()` to prevent skipped inputs.

---

## 🧰 Built With

* C++
* fstream (file handling)

---
