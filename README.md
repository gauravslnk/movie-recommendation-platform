# 🎬 Movie Recommendation Platform

A console-based C++ application that provides personalized movie recommendations using structured data and simple algorithms. Designed with both users and administrators in mind, the platform offers a rich set of features to explore, filter, and manage a movie database stored in CSV files.

---

## 🚀 Features

### 👥 User Features
- **Sign Up / Login**: Secure user authentication system.
- **Search by Genre**: Browse movies based on preferred genres.
- **Filter Options**:
  - By **Rating**
  - By **Release Year Range**
- **Random Movie Recommendation**
- **Watch & Recommendation History**
- **Smart Recommendations**: Based on user preferences and history.
- **Search by Title**: Auto-complete style search to find exact matches.

### 🔐 Admin Features
- **Add New Movie**
- **Remove Movie**
- **Modify Movie Details**
- **View Full Movie Database**

---

### 🔐 Admin Access

> ⚙️ **Admin functionality is hardcoded** for simplicity during development.

```
Username: MH112024  
Password: employee
```

---
### 💾 Data Management
- **CSV File Handling**: All movie and user data is stored and managed via CSV files.
- **Persistent Storage**: All changes are saved automatically.

---

## 🛠️ Technical Stack

| Component       | Details                                 |
|-----------------|------------------------------------------|
| **Language**    | C++                                      |
| **UI**          | Console-based (Windows)                  |
| **Storage**     | CSV Files                                |
| **Data Structures** | Linked Lists, Binary Trees, Maps, Stacks, Queues |
| **OS Support**  | Windows only (due to use of Windows-specific functions) |

---

## 📂 File Structure

```

movie-recommendation/
├── movie-recommendation.cpp     # Main source code
├── movies.csv                   # Movie data
├── users.csv                    # User data
├── .gitignore
└── README.md

````

---

## ▶️ How to Run

### 🔧 Compile

```bash
g++ -std=c++20 movie-recommendation.cpp -o movie-recommendation
````

### ▶️ Execute

```bash
./movie-recommendation
```

---

## 🧠 Concepts Applied

* File I/O using CSV
* Object-oriented design
* Use of STL containers (`map`, `queue`, etc.)
* Manual memory management (linked lists, binary trees)
* Console UI with cursor positioning (Windows API)

---

## 📌 Limitations

* Platform-dependent: Works only on **Windows** due to use of Windows-specific functions.
* No GUI or database yet (CSV-based for simplicity).

---

## 📅 Future Improvements

* Cross-platform support (remove Windows API dependencies)
* GUI using Qt or similar
* Integration with online movie APIs (e.g., TMDb)
* Login encryption / password hashing
* Unit testing

---

## 🙌 Contributing

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

---

## 📄 License

This project is open-source and available under the [MIT License](LICENSE).

---


