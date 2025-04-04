#include <iostream>
#include <string>
#include <iomanip> 
using namespace std;

#define MAX_BOOKS 100 

class Book {
private:
    string id, isbn, title, author, edition, publication, category;

public:
    void setBook(string id, string isbn, string title, string author, string edition, string publication, string category) {
        this->id = id;
        this->isbn = isbn;
        this->title = title;
        this->author = author;
        this->edition = edition;
        this->publication = publication;
        this->category = category;
    }

    string getId() { return id; }
    string getISBN() { return isbn; }
    string getCategory() { return category; }

    void displayBook() {
        cout << "| " << setw(10) << id 
             << " | " << setw(15) << isbn 
             << " | " << setw(30) << title 
             << " | " << setw(20) << author 
             << " | " << setw(10) << edition 
             << " | " << setw(15) << publication 
             << " | " << setw(15) << category 
             << " |" << endl;
    }

    void editBook(string isbn, string title, string author, string edition, string publication, string category) {
        this->isbn = isbn;
        this->title = title;
        this->author = author;
        this->edition = edition;
        this->publication = publication;
        this->category = category;
    }
};

class Library {
private:
    Book books[MAX_BOOKS];
    int bookCount;

    string toLower(string str) {
        for (char &c : str) {
            if (c >= 'A' && c <= 'Z') {
                c += ('a' - 'A');
            }
        }
        return str;
    }

    bool isDigit(char c) {
        return c >= '0' && c <= '9';
    }

    bool isValidISBN(const string& isbn) {
        if (isbn == "0") return false;
        for (char c : isbn) {
            if (!isDigit(c)) {
                return false;
            }
        }
        return !isbn.empty();
    }

    bool isDuplicateId(const string& id, const string& category) {
        string lowerId = toLower(id);
        for (int i = 0; i < bookCount; i++) {
            if (toLower(books[i].getId()) == lowerId && books[i].getCategory() == category) {
                return true; 
            }
        }
        return false;
    }

    bool isDuplicateISBN(const string& isbn) {
        for (int i = 0; i < bookCount; i++) {
            if (books[i].getISBN() == isbn) return true; 
        }
        return false;
    }

public:
    Library() { bookCount = 0; }

    void addBook() {
        if (bookCount >= MAX_BOOKS) {
            cout << "Library is full!" << endl;
            return;
        }

        string id, isbn, title, author, edition, publication, category;
        
        while (true) {
            cout << "Enter Category (Fiction/Non-fiction): ";
            cin >> category;
            category = toLower(category);
            if (category == "fiction" || category == "non-fiction") {
                category[0] = toupper(category[0]);
                if (category == "Non-fiction") category[4] = '-';
                break;
            } else {
                cout << "Category not found! Please enter again." << endl;
            }
        }

        while (true) {
            cout << "Enter ID: ";
            getline(cin >> ws, id);
            if (id.empty() || id.find(' ') != string::npos) {
                cout << "Invalid ID! ID should not be empty or contain spaces. Please enter again." << endl;
                continue;
            }
            if (isDuplicateId(id, category)) {
                cout << "Duplicate ID in the same category! Please enter a different ID." << endl;
                continue; 
            }
            break; 
        }

        while (true) {
            cout << "Enter ISBN (positive integers only): ";
            getline(cin >> ws, isbn);
            if (isValidISBN(isbn)) {
                if (isDuplicateISBN(isbn)) {
                    cout << "Duplicate ISBN! Please enter a different ISBN." << endl;
                    continue;
                }
                break; 
            } else {
                cout << "Invalid ISBN! Please enter positive integers only." << endl;
            }
        }

        while (true) {
            cout << "Enter Title: "; 
            getline(cin, title);
            if (title.empty()) {
                cout << "Title cannot be empty! Please enter again." << endl;
                continue;
            }
            break;
        }

        while (true) {
            cout << "Enter Author: "; 
            getline(cin, author);
            if (author.empty()) {
                cout << "Author cannot be empty! Please enter again." << endl;
                continue;
            }
            break;
        }

        while (true) {
            cout << "Enter Edition: "; 
            getline(cin, edition);
            if (edition.empty()) {
                cout << "Edition cannot be empty! Please enter again." << endl;
                continue;
            }
            break;
        }

        while (true) {
            cout << "Enter Publication: "; 
            getline(cin, publication);
            if (publication.empty()) {
                cout << "Publication cannot be empty! Please enter again." << endl;
                continue;
            }
            break;
        }

        books[bookCount].setBook(id, isbn, title, author, edition, publication, category);
        bookCount++;
        cout << "Book added successfully!" << endl;
    }

    void editBook() {
        string id;
        cout << "Enter ID: "; cin >> id;
        for (int i = 0; i < bookCount; i++) {
            if (books[i].getId() == id) {
                string isbn, title, author, edition, publication, category;
                
                while (true) {
                    cout << "Enter New ISBN (positive integers only): ";
                    getline(cin >> ws, isbn);
                    if (isValidISBN(isbn)) {
                        if (isDuplicateISBN(isbn)) {
                            cout << "Duplicate ISBN! Please enter a different ISBN." << endl;
                            continue;
                        }
                        break; 
                    } else {
                        cout << "Invalid ISBN! Please enter positive integers only." << endl;
                    }
                }

                cin.ignore();

                while (true) {
                    cout << "Enter New Title: "; 
                    getline(cin, title);
                    if (title.empty()) {
                        cout << "Title cannot be empty! Please enter again." << endl;
                        continue;
                    }
                    break;
                }

                while (true) {
                    cout << "Enter New Author: "; 
                    getline(cin, author);
                    if (author.empty()) {
                        cout << "Author cannot be empty! Please enter again." << endl;
                        continue;
                    }
                    break;
                }

                while (true) {
                    cout << "Enter New Edition: "; 
                    getline(cin, edition);
                    if (edition.empty()) {
                        cout << "Edition cannot be empty! Please enter again." << endl;
                        continue;
                    }
                    break;
                }

                while (true) {
                    cout << "Enter New Publication: "; 
                    getline(cin, publication);
                    if (publication.empty()) {
                        cout << "Publication cannot be empty! Please enter again." << endl;
                        continue;
                    }
                    break;
                }

                while (true) {
                    cout << "Enter New Category: "; 
                    getline(cin >> ws, category);
                    category = toLower(category);
                    if (category == "fiction" || category == "non-fiction") {
                        category[0] = toupper(category[0]);
                        if (category == "Non-fiction") category[4] = '-';
                        break;
                    } else {
                        cout << "Invalid category! Please enter 'Fiction' or 'Non-fiction'." << endl;
                    }
                }

                books[i].editBook(isbn, title, author, edition, publication, category);
                cout << "Book edited successfully!" << endl;
                return;
            }
        }
        cout << "Book not found!" << endl;
    }

    void searchBook() {
        string id;
        cout << "Enter ID: "; cin >> id;
        for (int i = 0; i < bookCount; i++) {
            if (books[i].getId() == id) {
                cout << "\n| " << setw(10) << "ID" 
                     << " | " << setw(15) << "ISBN" 
                     << " | " << setw(30) << "Title" 
                     << " | " << setw(20) << "Author" 
                     << " | " << setw(10) << "Edition" 
                     << " | " << setw(15) << "Publication" 
                     << " | " << setw(15) << "Category" 
                     << " |" << endl;

                cout << string(120, '-') << endl;
                books[i].displayBook();
                return;
            }
        }
        cout << "Book not found!" << endl;
    }

    void deleteBook() {
        string id;
        cout << "Enter ID: "; cin >> id;
        for (int i = 0; i < bookCount; i++) {
            if (books[i].getId() == id) {
                books[i].displayBook();
                string choice;
                while (true) {
                    cout << "Do you want to delete this book? (yes/no): ";
                    getline(cin >> ws, choice);
                    
                    if (choice == "yes") {
                        for (int j = i; j < bookCount - 1; j++) {
                            books[j] = books[j + 1];
                        }
                        bookCount--;
                        cout << "Book Deleted successfully" << endl;
                        return;
                    } else if (choice == "no") {
                        cout << "Book deletion canceled." << endl;
                        return;
                    } else {
                        cout << "Invalid input! Please enter 'yes' or 'no'." << endl;
                    }
                }
            }
        }
        cout << "Book not found!" << endl;
    }

    void viewBooksByCategory() {
        string category;
        cout << "Enter Category: "; cin >> category;
        category = toLower(category);
        category[0] = toupper(category[0]);
        if (category == "Non-fiction") category[4] = '-';

        bool found = false;
        for (int i = 0; i < bookCount; i++) {
            if (books[i].getCategory() == category) {
                books[i].displayBook();
                found = true;
            }
        }
        if (!found) cout << "Category not found!" << endl;
    }

    void viewAllBooks() {
        if (bookCount == 0) {
            cout << "No books available!" << endl;
            return;
        }

        cout << "\n| " << setw(10) << "ID" 
             << " | " << setw(15) << "ISBN" 
             << " | " << setw(30) << "Title" 
             << " | " << setw(20) << "Author" 
             << " | " << setw(10) << "Edition" 
             << " | " << setw(15) << "Publication" 
             << " | " << setw(15) << "Category" 
             << " |" << endl;

        cout << string(120, '-') << endl;

        for (int i = 0; i < bookCount; i++) {
            books[i].displayBook();
        }
    }
};

int main() {
    Library library;
    string input;
    int choice;
    bool running = true;
    while (running) {
        cout << "\nLibrary Management System\n";
        cout << "1 - Add Book\n2 - Edit Book\n3 - Search Book\n4 - Delete Book\n5 - View Books by Category\n6 - View All Books\n7 - Exit\n";
        cout << "Enter choice: ";
        getline(cin >> ws, input);
        
        if (input.length() != 1 || input[0] < '1' || input[0] > '7') {
            cout << "Invalid input! Please enter a number between 1 and 7." << endl;
            continue;
        }
        
        choice = input[0] - '0';
        switch (choice) {
            case 1: library.addBook(); break;
            case 2: library.editBook(); break;
            case 3: library.searchBook(); break;
            case 4: library.deleteBook(); break;
            case 5: library.viewBooksByCategory(); break;
            case 6: library.viewAllBooks(); break;
            case 7: running = false; cout << "Exiting..."; break;
        }
    }
    return 0;
}