#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <map>
#include <queue>
#include <stack>
#include <windows.h>
#include <conio.h>
#define MAX_INPUT_LENGTH 100

using namespace std;
COORD coord = {0, 0};
void gotoxy(int a, int b)
{
    coord.X = a;
    coord.Y = b;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void design(int x, int y)
{
    for (int i = 0; i <= x; i++)
        cout << (char)y;
}
void clearScreen()
{
    system("cls");
}
bool userExists(const string &username)
{
    ifstream file("users.csv");
    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string user;
        getline(ss, user, ',');
        if (user == username)
        {
            return true;
        }
    }
    return false;
}
void signUp()
{
    string username, password, email;
    system("color f4");
    gotoxy(65, 4);
    design(15, 177);
    cout << " Sign Up ";
    design(15, 177);
    gotoxy(65, 7);
    cout << "Enter Username: ";
    cin >> username;
    if (userExists(username))
    {
        gotoxy(65, 10);
        cout << "Username already exists! Please choose a different username.\n";
        gotoxy(65, 13);
        cout << "Press any key to continue .... ";
        getch();
        clearScreen();
        return;
    }
    gotoxy(65, 9);
    cout << "Enter Password: ";
    cin >> password;
    gotoxy(65, 11);
    cout << "Enter Email: ";
    cin >> email;
    ofstream file("users.csv", ios::app);
    if (file.is_open())
    {
        file << username << "," << password << "," << email << "\n";
        file.close();
        gotoxy(65, 13);
        cout << "User registered successfully!\n";
    }
    else
    {
        gotoxy(65, 13);
        cout << "Error opening file for writing.\n";
    }
}
string login()
{
    string username, password;
    system("color f4");
    gotoxy(65, 4);
    design(15, 177);
    cout << " Login";
    design(15, 177);
    gotoxy(65, 7);
    cout << "Enter Username: ";
    cin >> username;
    gotoxy(65, 9);
    cout << "Enter Password: ";
    cin >> password;
    if (username == "MH112024")
    {
        if (password == "employee")
            return username;
        else
        {
            cout << "Invalid Password";
            return "";
        }
    }
    ifstream file("users.csv");
    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string user, pass;
        getline(ss, user, ',');
        getline(ss, pass, ',');
        if (user == username && pass == password)
        {
            gotoxy(65, 15);
            cout << "Login successful!\n";
            gotoxy(65, 18);
            cout << "Press any key to continue .... ";
            getch();
            clearScreen();
            return username;
        }
    }
    gotoxy(65, 15);
    cout << "Invalid username or password.\n";
    return "";
}
string loginPage()
{
    while (true)
    {
        system("color f4");
        gotoxy(65, 4);
        design(15, 177);
        cout << " MOVIEHUNT ";
        design(15, 177);
        gotoxy(65, 7);
        cout << "1. Login\n";
        gotoxy(65, 9);
        cout << "2. Sign Up\n";
        gotoxy(65, 11);
        cout << "3. Exit\n";
        gotoxy(65, 13);
        cout << "Select an option: ";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            clearScreen();
            string user_file = login();
            if (!user_file.empty())
            {
                clearScreen();
                gotoxy(65, 6);
                cout << "Welcome to Moviehunt!\n";
                return user_file;
            }
            gotoxy(65, 18);
            cout << "Press any key to continue .... ";
            getch();
            clearScreen();
            break;
        }
        case 2:
        {
            clearScreen();
            signUp();
            gotoxy(65, 15);
            cout << "Press any key to continue .... ";
            getch();
            clearScreen();
            break;
        }
        case 3:
            clearScreen();
            system("color f4");
            gotoxy(65, 4);
            design(15, 177);
            cout << "Thank you for your visit";
            design(15, 177);
            gotoxy(65, 8);
            exit(0);
        default:
            clearScreen();
            gotoxy(65, 4);
            cout << "Invalid option. Please try again.\n";
        }
    }
}

void drawLine(int length, char symbol = '-')
{
    for (int i = 0; i < length; i++)
    {
        cout << symbol;
    }
}

void displayHeader(const string &title)
{
    int width = 50;
    cout << "\n";
    drawLine(width, '=');
    cout << "\n";
    cout << " " << title << "\n";
    drawLine(width, '=');
    cout << "\n\n";
}

struct ListNode
{
    string title;
    string genre;
    double rating;
    string director;
    int releaseYear;
    int duration;
    ListNode *next;

    ListNode(string t, string g, double r, string d, int y, int dur)
        : title(t), genre(g), rating(r), director(d), releaseYear(y), duration(dur), next(nullptr) {}
};

class LinkedList
{
public:
    ListNode *head;

    LinkedList() : head(nullptr) {}

    void addMovie(const string &title, const string &genre, double rating, const string &director, int releaseYear, int duration)
    {
        ListNode *newNode = new ListNode(title, genre, rating, director, releaseYear, duration);
        newNode->next = head;
        head = newNode;
    }
    void displayMoviesTree() const
    {
        ListNode *temp = head;
        while (temp)
        {
            cout << "\t\t" << std::setw(30) << std::left << temp->title
                 << setw(20) << temp->genre
                 << setw(10) << temp->rating
                 << setw(30) << temp->director
                 << setw(15) << temp->releaseYear
                 << setw(10) << temp->duration << endl;
            temp = temp->next;
        }
    }
    void displayMovies() const
    {
        ListNode *temp = head;
        int i = 20;
        gotoxy(10, 18);
        cout << "TITLE";
        gotoxy(40, 18);
        cout << "GENRE";
        gotoxy(60, 18);
        cout << "RATING";
        gotoxy(70, 18);
        cout << "DIRECTOR";
        gotoxy(100, 18);
        cout << "RELEASE YEAR";
        gotoxy(120, 18);
        cout << "DURATION";
        while (temp != NULL)
        {
            gotoxy(10, i);
            cout << temp->title;
            gotoxy(40, i);
            cout << temp->genre;
            gotoxy(60, i);
            cout << temp->rating;
            gotoxy(70, i);
            cout << temp->director;
            gotoxy(100, i);
            cout << temp->releaseYear;
            gotoxy(120, i);
            cout << temp->duration;
            i += 2;
            temp = temp->next;
        }
    }
};
struct TreeNode
{
    double rating;
    LinkedList movies;
    TreeNode *left;
    TreeNode *right;

    TreeNode(double r) : rating(r), left(nullptr), right(nullptr) {}
};

class BinaryTree
{
public:
    TreeNode *root;

    BinaryTree() : root(nullptr) {}

    void insertMovie(double rating, const string &title, const string &genre, const string &director, int releaseYear, int duration)
    {
        root = insertRec(root, rating, title, genre, director, releaseYear, duration);
    }

    void displayMoviesByRating(TreeNode *node) const
    {
        if (!node)
            return;
        displayMoviesByRating(node->left);
        node->movies.displayMoviesTree();
        displayMoviesByRating(node->right);
    }

private:
    TreeNode *insertRec(TreeNode *node, double rating, const string &title, const string &genre, const string &director, int releaseYear, int duration)
    {
        if (!node)
        {
            node = new TreeNode(rating);
            node->movies.addMovie(title, genre, rating, director, releaseYear, duration);
        }
        else if (rating < node->rating)
        {
            node->left = insertRec(node->left, rating, title, genre, director, releaseYear, duration);
        }
        else if (rating > node->rating)
        {
            node->right = insertRec(node->right, rating, title, genre, director, releaseYear, duration);
        }
        else
        {
            node->movies.addMovie(title, genre, rating, director, releaseYear, duration);
        }
        return node;
    }
};

class MovieRecommendationPlatform
{
private:
    map<string, LinkedList> genreIndex;
    BinaryTree ratingTree;
    stack<string> recommendationHistory;
    queue<ListNode> movieQueue;

public:
    void addMovie(const string &title, const string &genre, double rating, const string &director, int releaseYear, int duration)
    {
        genreIndex[genre].addMovie(title, genre, rating, director, releaseYear, duration);
        ratingTree.insertMovie(rating, title, genre, director, releaseYear, duration);
    }
    void displayMoviesByGenre(const string &genre) const
    {
        auto it = genreIndex.find(genre);
        if (it != genreIndex.end())
        {
            gotoxy(44, 14);
            cout << "Movies in genre: " << genre << "\n";
            gotoxy(10, 16);
            drawLine(120, '=');
            it->second.displayMovies();
        }
        else
        {
            gotoxy(44, 14);
            cout << "No movies found in genre: " << genre << endl;
        }
    }

    void displayMoviesByRating() const
    {
        gotoxy(16, 12);
        cout << std::setw(30) << std::left << "TITLE" << std::setw(20) << "GENRE" << std::setw(10) << "RATING"
             << std::setw(30) << "DIRECTOR" << std::setw(15) << "RELEASE YEAR" << std::setw(10) << "DURATION" << endl;
        gotoxy(16, 14);
        cout << std::string(120, '-') << endl;
        ratingTree.displayMoviesByRating(ratingTree.root);
    }

    void recommendRandomMovie(const string &filename)
    {
        ofstream file(filename, ios::app);
        if (!file.is_open())
        {
            cerr << "Error: Could not open file for writing." << endl;
            return;
        }
        srand(time(0));
        if (genreIndex.empty())
        {
            gotoxy(44, 12);
            cout << "No movies available for recommendation." << endl;
            return;
        }
        auto it = genreIndex.begin();
        advance(it, rand() % genreIndex.size());
        if (it->second.head)
        {
            gotoxy(16, 12);
            cout << std::setw(30) << std::left << "TITLE" << std::setw(20) << "GENRE" << std::setw(10) << "RATING"
                 << std::setw(30) << "DIRECTOR" << std::setw(15) << "RELEASE YEAR" << std::setw(10) << "DURATION" << endl;
            gotoxy(16, 14);
            cout << std::string(120, '-') << endl;
            cout << "\t\t" << std::setw(30) << std::left << it->second.head->title
                 << setw(20) << it->second.head->genre
                 << setw(10) << it->second.head->rating
                 << setw(30) << it->second.head->director
                 << setw(15) << it->second.head->releaseYear
                 << setw(10) << it->second.head->duration << endl;
            file << it->second.head->title << ","
                 << it->second.head->genre << ","
                 << it->second.head->rating << ","
                 << it->second.head->director << ","
                 << it->second.head->releaseYear << ","
                 << it->second.head->duration << "\n";
        }
        file.close();
    }
    void loadMoviesFromFile(const string &filename)
    {
        ifstream file(filename);
        if (!file.is_open())
        {
            cerr << "Error opening file for loading." << endl;
            return;
        }
        string line, title, genre, director, ratingStr, yearStr, durationStr;
        double rating;
        int releaseYear, duration;

        getline(file, line);
        while (getline(file, line))
        {
            stringstream ss(line);
            getline(ss, title, ',');
            getline(ss, genre, ',');
            getline(ss, ratingStr, ',');
            getline(ss, director, ',');
            getline(ss, yearStr, ',');
            getline(ss, durationStr);
            rating = stod(ratingStr);
            releaseYear = stoi(yearStr);
            duration = stoi(durationStr);
            movieQueue.push(ListNode(title, genre, rating, director, releaseYear, duration));
        }
        while (!movieQueue.empty())
        {
            ListNode movie = movieQueue.front();
            addMovie(movie.title, movie.genre, movie.rating, movie.director, movie.releaseYear, movie.duration);
            movieQueue.pop();
        }
        file.close();
    }
    void showRecommendationHistory(const string &filename) const
    {
        ifstream file(filename);
        if (!file.is_open())
        {
            gotoxy(44, 12);
            cerr << "No recommendation history found\n"
                 << endl;
            return;
        }
        stack<string> tempStack;
        string line, title, genre, director, ratingStr, yearStr, durationStr;
        double rating;
        int releaseYear, duration;
        while (getline(file, line))
        {
            stringstream ss(line);
            getline(ss, title, ',');
            getline(ss, genre, ',');
            getline(ss, ratingStr, ',');
            getline(ss, director, ',');
            getline(ss, yearStr, ',');
            getline(ss, durationStr);
            rating = stod(ratingStr);
            releaseYear = stoi(yearStr);
            duration = stoi(durationStr);
            tempStack.push(title);
        }
        gotoxy(44, 12);
        int i = 14;
        while (!tempStack.empty())
        {
            gotoxy(44, i);
            cout << tempStack.top() << endl;
            tempStack.pop();
            i += 2;
        }
        file.close();
    }

    void filterMoviesByRating(double minRating)
    {
        bool found = false;
        gotoxy(16, 14);
        cout << setw(30) << left << "TITLE" << setw(20) << "GENRE" << setw(10) << "RATING"
             << setw(30) << "DIRECTOR" << setw(15) << "RELEASE YEAR" << setw(10) << "DURATION" << endl;
        gotoxy(16, 16);
        cout << string(120, '-') << endl;
        for (const auto &[genre, movies] : genreIndex)
        {
            ListNode *node = movies.head;
            while (node)
            {
                if (node->rating >= minRating)
                {
                    cout << "\t\t" << setw(30) << left << node->title
                         << setw(20) << node->genre
                         << setw(10) << node->rating
                         << setw(30) << node->director
                         << setw(15) << node->releaseYear
                         << setw(10) << node->duration << endl;
                    found = true;
                }
                node = node->next;
            }
        }

        if (!found)
        {
            cout << "No movies found with a rating of " << minRating << " or higher.\n";
        }
    }

    void filterMoviesByReleaseYearRange(int startYear, int endYear)
    {
        bool found = false;
        gotoxy(16, 16);
        cout << setw(30) << left << "TITLE" << setw(20) << "GENRE" << setw(10) << "RATING"
             << setw(30) << "DIRECTOR" << setw(15) << "RELEASE YEAR" << setw(10) << "DURATION" << endl;
        gotoxy(16, 18);
        cout << string(120, '-') << endl;
        for (const auto &[genre, movies] : genreIndex)
        {
            ListNode *node = movies.head;
            while (node)
            {
                if (node->releaseYear >= startYear && node->releaseYear <= endYear)
                {
                    cout << "\t\t" << std::setw(30) << left << node->title
                         << setw(20) << node->genre
                         << setw(10) << node->rating
                         << setw(30) << node->director
                         << setw(15) << node->releaseYear
                         << setw(10) << node->duration << endl;
                    found = true;
                }
                node = node->next;
            }
        }

        if (!found)
        {
            cout << "No movies found released between " << startYear << " and " << endYear << ".\n";
        }
    }
};

void displayMenu()
{
    gotoxy(44, 8);
    design(15, 177);
    cout << "  Movie Recommendation Platform  ";
    design(15, 177);
    cout << endl;
    gotoxy(44, 12);
    cout << "1. Search movies by genre\n";
    gotoxy(44, 14);
    cout << "2. Display movies by rating\n";
    gotoxy(44, 16);
    cout << "3. Recommend a random movie\n";
    gotoxy(44, 18);
    cout << "4. Show history\n";
    gotoxy(44, 20);
    cout << "5. Filter Movies By Rating\n";
    gotoxy(44, 22);
    cout << "6. Filter Movies By Release Year Range\n";
    gotoxy(44, 24);
    cout << "7. Recommend My Type movies\n";
    gotoxy(44, 26);
    cout << "8. Search for a Movie\n";
    gotoxy(44, 28);
    cout << "0. Exit\n";
    gotoxy(44, 30);
    drawLine(65, '=');
    gotoxy(44, 32);
    cout << "Enter your choice: ";
}
void displayModification()
{
    gotoxy(44, 8);
    design(15, 177);
    cout << "  Movie Recommendation Platform  ";
    design(15, 177);
    cout << endl;
    gotoxy(44, 12);
    cout << "1. Add a new movie\n";
    gotoxy(44, 14);
    cout << "2. Remove a movie\n";
    gotoxy(44, 16);
    cout << "3. Modify the details of a movie\n";
    gotoxy(44, 18);
    cout << "4. View All Movies\n";
    gotoxy(44, 20);
    cout << "0. Exit\n";
    gotoxy(44, 22);
    drawLine(65, '=');
    gotoxy(44, 24);
    cout << "\nEnter your choice: ";
    gotoxy(44, 24);
}
class DataModification
{
public:
    ListNode *head;

    DataModification() : head(nullptr) {}

    void loadMoviesFromFile()
    {
        ifstream file("movies.csv");
        if (!file.is_open())
        {
            cerr << "Error opening file for loading." << endl;
            return;
        }

        string line, title, genre, director, ratingStr, yearStr, durationStr;
        double rating;
        int releaseYear, duration;

        getline(file, line);

        while (getline(file, line))
        {
            stringstream ss(line);
            getline(ss, title, ',');
            getline(ss, genre, ',');
            getline(ss, ratingStr, ',');
            getline(ss, director, ',');
            getline(ss, yearStr, ',');
            getline(ss, durationStr);

            rating = stod(ratingStr);
            releaseYear = stoi(yearStr);
            duration = stoi(durationStr);

            addMovie(title, genre, rating, director, releaseYear, duration);
        }
        file.close();
    }

    void saveToCSV()
    {
        ofstream file("movies.csv");
        if (!file.is_open())
        {
            cerr << "Error opening file for saving." << endl;
            return;
        }

        file << "Title,Genre,Rating,Director,Release Year,Duration (min)\n";

        ListNode *temp = head;
        while (temp)
        {
            file << temp->title << "," << temp->genre << "," << temp->rating << ","
                 << temp->director << "," << temp->releaseYear << "," << temp->duration << endl;
            temp = temp->next;
        }

        file.close();
    }

    void addMovie(const string &title, const string &genre, double rating, const string &director, int releaseYear, int duration)
    {
        ListNode *newNode = new ListNode(title, genre, rating, director, releaseYear, duration);
        newNode->next = head;
        head = newNode;
    }

    void updateMovie(const string &oldTitle, const string &newTitle, const string &genre, double rating, const string &director, int releaseYear, int duration)
    {
        ListNode *temp = head;
        while (temp)
        {
            if (temp->title == oldTitle)
            {
                temp->title = newTitle;
                temp->genre = genre;
                temp->rating = rating;
                temp->director = director;
                temp->releaseYear = releaseYear;
                temp->duration = duration;
                gotoxy(44, 28);
                cout << "Movie updated successfully!\n";
                saveToCSV();
                return;
            }
            temp = temp->next;
        }
        gotoxy(44, 28);
        cout << "Movie with the title '" << oldTitle << "' not found!\n";
    }
    void view()
    {
        ListNode *temp = head;
        gotoxy(16, 14);
        cout << setw(30) << left << "TITLE" << setw(20) << "GENRE" << setw(10) << "RATING"
             << setw(30) << "DIRECTOR" << setw(15) << "RELEASE YEAR" << setw(10) << "DURATION" << endl;
        gotoxy(16, 16);
        cout << string(120, '-') << endl;
        while (temp != NULL)
        {
            cout << "\t\t" << setw(30) << left << temp->title
                 << setw(20) << temp->genre
                 << setw(10) << temp->rating
                 << setw(30) << temp->director
                 << setw(15) << temp->releaseYear
                 << setw(10) << temp->duration << endl;
            temp = temp->next;
        }
    }

    void deleteMovie(const string &title)
    {
        ListNode *temp = head;
        ListNode *prev = nullptr;

        if (temp != nullptr && temp->title == title)
        {
            head = temp->next;
            delete temp;
            gotoxy(44, 16);
            cout << "Movie '" << title << "' deleted successfully!\n";
            saveToCSV();
            return;
        }

        while (temp != nullptr && temp->title != title)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            gotoxy(44, 16);
            cout << "Movie with the title '" << title << "' not found!\n";
            return;
        }

        prev->next = temp->next;
        delete temp;
        gotoxy(44, 16);
        cout << "Movie '" << title << "' deleted successfully!\n";
        saveToCSV();
    }
};
void loadMovieDatabase(const string &databaseFile, map<string, vector<string>> &movieDatabase)
{
    ifstream file(databaseFile);
    if (!file.is_open())
    {
        cerr << "Error opening movie database file.\n";
        return;
    }

    std::string line, title, genre;
    getline(file, line);
    while (getline(file, line))
    {
        std::stringstream ss(line);
        getline(ss, title, ',');
        getline(ss, genre, ',');
        movieDatabase[genre].push_back(title);
    }

    file.close();
}

void loadUserWatchlist(const string &watchlistFile, set<string> &watchedMovies, set<string> &watchedGenres)
{
    ifstream file(watchlistFile);
    if (!file.is_open())
    {
        cerr << "Error opening user watchlist file.\n";
        return;
    }

    string line, title, genre;
    getline(file, line);
    while (getline(file, line))
    {
        stringstream ss(line);
        getline(ss, title, ',');
        getline(ss, genre, ',');
        watchedMovies.insert(title);
        watchedGenres.insert(genre);
    }

    file.close();
}
void recommendMovies(const map<string, vector<string>> &movieDatabase, const set<string> &watchedMovies,
                     const set<string> &watchedGenres)
{
    int i = 14;
    for (const auto &genre : watchedGenres)
    {
        if (movieDatabase.count(genre))
        {
            for (const auto &movie : movieDatabase.at(genre))
            {
                if (watchedMovies.find(movie) == watchedMovies.end())
                {
                    gotoxy(44, i);
                    i = i + 2;
                    cout << "- " << movie << " (" << genre << ")\n";
                }
            }
        }
    }
}

void recommendOnPreference(string moviefile, string userfile)
{
    map<string, vector<string>> movieDatabase;
    set<string> watchedMovies;
    set<string> watchedGenres;

    loadMovieDatabase(moviefile, movieDatabase);
    loadUserWatchlist(userfile, watchedMovies, watchedGenres);
    recommendMovies(movieDatabase, watchedMovies, watchedGenres);
}

void getSuggestions(const string &input, vector<string> &suggestions, const vector<string> &keywords)
{
    suggestions.clear();
    for (const auto &keyword : keywords)
    {
        if (keyword.find(input) == 0)
        {
            suggestions.push_back(keyword);
        }
    }
}

void clearLine(int x, int y, int length)
{
    gotoxy(x, y);
    std::cout << std::string(length, ' ');
    gotoxy(x, y);
}

void displaySuggestions(const std::vector<std::string> &suggestions, int startX, int startY)
{
    int y = startY;
    for (const auto &suggestion : suggestions)
    {
        gotoxy(startX, y);
        cout << "  " << suggestion << "  ";
        y++;
    }

    for (int i = y; i < startY + 50; i++)
    {
        gotoxy(startX, i);
        cout << std::string(50, ' ');
    }
}

void searchForMovie()
{
    vector<std::string> movieDatabase;
    ifstream file("movies.csv");
    if (!file.is_open())
    {
        cerr << "Error opening movie database file.\n";
        return;
    }

    string line, title, genre;
    getline(file, line);
    while (getline(file, line))
    {
        stringstream ss(line);
        getline(ss, title, ',');
        getline(ss, genre, ',');
        movieDatabase.push_back(title);
    }
    file.close();

    string input;
    vector<std::string> suggestions;

    const int inputX = 44, inputY = 12;
    const int suggestionsX = 44, suggestionsY = 14;

    while (true)
    {
        gotoxy(inputX, inputY);
        cout << "Enter text for completion: ";
        input.clear();
        char ch;

        while (true)
        {
            ch = _getch();
            if (ch == '\r')
            {
                getSuggestions(input, suggestions, movieDatabase);
                displaySuggestions(suggestions, suggestionsX, suggestionsY);
                return;
            }
            else if (ch == '\b')
            {
                if (!input.empty())
                {
                    input.pop_back();
                    clearLine(inputX + 27, inputY, MAX_INPUT_LENGTH);
                    gotoxy(44, 12);
                    cout << "Enter text for completion: " << input;
                }
            }
            else if (ch >= 32 && ch <= 126)
            {
                if (input.size() < MAX_INPUT_LENGTH - 1)
                {
                    input.push_back(ch);
                    gotoxy(44, 12);
                    cout << "Enter text for completion: " << input;
                }
            }

            getSuggestions(input, suggestions, movieDatabase);
            gotoxy(44, 12);
            cout << "Enter text for completion: " << input;
            displaySuggestions(suggestions, suggestionsX, suggestionsY);
        }

        getSuggestions(input, suggestions, movieDatabase);
        displaySuggestions(suggestions, suggestionsX, suggestionsY);
    }
}
int main()
{
    string filename = loginPage();
    if (filename == "MH112024")
    {
        DataModification modify;
        modify.loadMoviesFromFile();
        int choice;

        do
        {
            displayModification();
            cin >> choice;
            clearScreen();
            cin.ignore();

            if (choice == 1)
            {
                string title, genre, director;
                double rating;
                int releaseYear, duration;
                gotoxy(44, 8);
                design(15, 177);
                cout << "  Movie Recommendation Platform  ";
                design(15, 177);
                cout << endl;
                gotoxy(44, 12);
                cout << "Enter movie title: ";
                getline(cin, title);
                gotoxy(44, 14);
                cout << "Enter movie genre: ";
                getline(cin, genre);
                gotoxy(44, 16);
                cout << "Enter movie rating (0 to 10): ";
                cin >> rating;
                cin.ignore();
                gotoxy(44, 18);
                cout << "Enter movie director: ";
                getline(cin, director);
                gotoxy(44, 20);
                cout << "Enter release year: ";
                cin >> releaseYear;
                gotoxy(44, 22);
                cout << "Enter duration (in minutes): ";
                cin >> duration;
                gotoxy(44, 24);
                modify.addMovie(title, genre, rating, director, releaseYear, duration);
                cout << "Movie added successfully!\n";
                modify.saveToCSV();
                cout << "\n\n\n\t\t\t\t\t\t\tPress any key to continue ";
                getch();
                clearScreen();
            }
            else if (choice == 2)
            {
                gotoxy(44, 8);
                design(15, 177);
                cout << "  Movie Recommendation Platform  ";
                design(15, 177);
                cout << endl;
                gotoxy(44, 12);
                string ttl;
                cout << "Enter the movie name to delete ";
                getline(cin, ttl);
                modify.deleteMovie(ttl);
                cout << "\n\n\n\t\t\t\t\t\t\tPress any key to continue ";
                getch();
                clearScreen();
            }
            else if (choice == 3)
            {
                gotoxy(44, 8);
                design(15, 177);
                cout << "  Movie Recommendation Platform  ";
                design(15, 177);
                cout << endl;
                gotoxy(44, 12);
                string title, oldtitle, genre, director;
                double rating;
                int releaseYear, duration;
                cout << "Enter the name of movie to update";
                getline(cin, oldtitle);
                gotoxy(44, 14);
                cout << "Enter the updated details of movie\n";
                gotoxy(44, 16);
                cout << "Enter movie title: ";
                getline(cin, title);
                gotoxy(44, 18);
                cout << "Enter movie genre: ";
                getline(cin, genre);
                gotoxy(44, 20);
                cout << "Enter movie rating (0 to 10): ";
                cin >> rating;
                cin.ignore();
                gotoxy(44, 22);
                cout << "Enter movie director: ";
                getline(cin, director);
                gotoxy(44, 24);
                cout << "Enter release year: ";
                cin >> releaseYear;
                gotoxy(44, 26);
                cout << "Enter duration (in minutes): ";
                cin >> duration;
                modify.updateMovie(oldtitle, title, genre, rating, director, releaseYear, duration);
                cout << "\n\n\n\t\t\t\t\t\t\tPress any key to continue ";
                getch();
                clearScreen();
            }
            else if (choice == 4)
            {
                gotoxy(44, 8);
                design(15, 177);
                cout << "  Movie Recommendation Platform  ";
                design(15, 177);
                modify.view();
                cout << "\n\n\n\t\t\t\t\t\t\tPress any key to continue ";
                getch();
                clearScreen();
            }
            else if (choice == 0)
            {
                cout << "\n\n\n\t\t\t\t\t\t\tPress any key to continue ";
                getch();
                clearScreen();
                loginPage();
            }
            else
            {
                cout << "Invalid choice! Please try again.\n";
            }
            cout << "\n";
            modify.saveToCSV();
        } while (choice != 0);
    }
    else
    {
        filename = filename + ".csv";
        MovieRecommendationPlatform platform;
        platform.loadMoviesFromFile("movies.csv");
        int choice;

        do
        {
            displayMenu();
            cin >> choice;
            cin.ignore();
            clearScreen();

            if (choice == 1)
            {
                gotoxy(44, 8);
                design(15, 177);
                cout << "  Movie Recommendation Platform  ";
                design(15, 177);
                cout << endl;
                gotoxy(44, 12);
                string genre;
                cout << "Enter genre to search for: ";
                getline(cin, genre);
                platform.displayMoviesByGenre(genre);
                cout << "\n\n\n\t\t\t\t\t\t\tPress any key to continue ";
                getch();
                clearScreen();
            }
            else if (choice == 2)
            {
                gotoxy(44, 8);
                design(15, 177);
                cout << "  Movie Recommendation Platform  ";
                design(15, 177);
                cout << endl;
                platform.displayMoviesByRating();
                cout << "\n\n\n\t\t\t\t\t\t\tPress any key to continue ";
                getch();
                clearScreen();
            }
            else if (choice == 3)
            {
                gotoxy(44, 8);
                design(15, 177);
                cout << "  Movie Recommendation Platform  ";
                design(15, 177);
                cout << endl;
                platform.recommendRandomMovie(filename);
                cout << "\n\n\n\t\t\t\t\t\t\tPress any key to continue ";
                getch();
                clearScreen();
            }
            else if (choice == 4)
            {
                gotoxy(44, 8);
                design(15, 177);
                cout << "  Movie Recommendation Platform  ";
                design(15, 177);
                cout << endl;

                platform.showRecommendationHistory(filename);
                cout << "\n\n\n\t\t\t\t\t\t\tPress any key to continue ";
                getch();
                clearScreen();
            }
            else if (choice == 5)
            {
                gotoxy(44, 8);
                design(15, 177);
                cout << "  Movie Recommendation Platform  ";
                design(15, 177);
                cout << endl;
                gotoxy(44, 12);
                double minRating;
                cout << "Enter the minimum rating: ";
                cin >> minRating;
                platform.filterMoviesByRating(minRating);
                cout << "\n\n\n\t\t\t\t\t\t\tPress any key to continue ";
                getch();
                clearScreen();
            }
            else if (choice == 6)
            {
                gotoxy(44, 8);
                design(15, 177);
                cout << "  Movie Recommendation Platform  ";
                design(15, 177);
                cout << endl;
                gotoxy(44, 12);
                int startYear, endYear;
                cout << "Enter the start year: ";
                cin >> startYear;
                gotoxy(44, 14);
                cout << "Enter the end year: ";
                cin >> endYear;
                platform.filterMoviesByReleaseYearRange(startYear, endYear);
                cout << "\n\n\n\t\t\t\t\t\t\tPress any key to continue ";
                getch();
                clearScreen();
            }
            else if (choice == 7)
            {
                gotoxy(44, 8);
                design(15, 177);
                cout << "  Movie Recommendation Platform  ";
                design(15, 177);
                cout << endl;
                gotoxy(44, 12);
                cout << "A Movie Based on your watchList is :  ";
                recommendOnPreference("movies.csv", filename);
                cout << "\n\n\n\t\t\t\t\t\t\tPress any key to continue ";
                getch();
                clearScreen();
            }
            else if (choice == 8)
            {
                gotoxy(44, 8);
                design(15, 177);
                cout << "  Movie Recommendation Platform  ";
                design(15, 177);
                cout << endl;
                searchForMovie();
                gotoxy(0, 18);
                cout << "\n\n\n\t\t\t\t\t\t\tPress any key to continue ";
                getch();
                clearScreen();
            }
            else if (choice == 0)
            {
                gotoxy(44, 8);
                design(15, 177);
                cout << "  Movie Recommendation Platform  ";
                design(15, 177);
                cout << endl;
                gotoxy(44, 12);
                cout << "Exiting the program. Thank you!\n";
                gotoxy(44, 14);
                cout << "Press [ENTER] to return back to main menu.";
                getch();
                clearScreen();
                loginPage();
            }
            else
            {
                cout << "Invalid choice! Please try again.\n";
            }

            cout << "\n";
        } while (choice != 0);
    }
    return 0;
}
