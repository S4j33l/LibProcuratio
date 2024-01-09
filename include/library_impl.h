#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
class Book
{
public:
    int id;
    std::string title;
    std::string author_name;
    std::string ISBN;
    bool is_available;
    Book() {}
    Book(int id, std::string title, std::string author_name, std::string ISBN, bool is_available)
    {
        this->id = id;
        this->title = title;
        this->author_name = author_name;
        this->ISBN = ISBN;
        this->is_available = is_available;
    }
};
class User
{
public:
    int id;
    std::string username;
    std::string password;
    std::string requestedTitle;
    std::vector<User> users;
    std::vector<Book> issuedBooks;
    User(){};
    User(int id, std::string username, std::string password)
    {
        this->id = id;
        this->username = username;
        this->password = password;
    };
    void showIssuedBooks()
    {
        if (issuedBooks.empty())
        {
            std::cout << "No books issued yet."
                      << "\n";
        }
        else
        {
            std::cout << "Issued books: "
                      << "\n";
            for (int i = 0; i < issuedBooks.size(); i++)
            {
                std::cout << issuedBooks.at(i).title << "\n";
            }
        }
    };
};
class BookNode
{
public:
    Book book;
    BookNode *next;
    BookNode *prev;
    BookNode(Book *book)
    {
        this->book = *book;
        this->next = NULL;
        this->prev = NULL;
    }
};
class BookShelf
{
private:
    BookNode *head = NULL;
    BookNode *tail = NULL;
    BookNode *partition(BookNode *tail, BookNode *head)
    {
        int pivot = head->book.id;
        BookNode *low = tail->prev;
        for (BookNode *high = tail; high != head; high = high->next)
        {
            if (high->book.id <= pivot)
            {
                low = (low == nullptr) ? tail : low->next;
                std::swap(low->book, high->book);
            }
        }
        low = (low == nullptr) ? tail : low->next;
        std::swap(low->book, head->book);
        return low;
    }
    void quicksort(BookNode *tail, BookNode *head)
    {
        if (head != nullptr && tail != head && tail != head->next)
        {
            BookNode *pivot = partition(tail, head);
            quicksort(tail, pivot->prev);
            quicksort(pivot->next, head);
        }
    }

public:
    BookShelf() {}
    void addBook(Book *book)
    {
        BookNode *newBookNode = new BookNode(book);
        if (head == NULL)
        {
            head = newBookNode;
            tail = newBookNode;
        }
        else
        {
            newBookNode->prev = tail;
            tail->next = newBookNode;
            tail = newBookNode;
        }
    }
    void displayAllBooks()
    {
        BookNode *temp = head;
        while (temp != NULL)
        {
            std::cout << temp->book.id << " " << temp->book.title << " " << temp->book.author_name << " " << temp->book.ISBN << "\n";
            temp = temp->next;
        }
    }
    void findBookByTitle(std::string title)
    {
        BookNode *temp = head;
        while (temp != NULL)
        {
            if (temp->book.title == title)
            {
                std::cout << temp->book.id << " " << temp->book.title << " " << temp->book.author_name << " " << temp->book.ISBN << "\n";
                return;
            }
            temp = temp->next;
        }
        std::cout << "Book not found"
                  << "\n";
    }
    void findBookById(int id)
    {
        BookNode *temp = head;
        while (temp != NULL)
        {
            if (temp->book.id == id)
            {
                std::cout << temp->book.id << " " << temp->book.title << " " << temp->book.author_name << " " << temp->book.ISBN << "\n";
                return;
            }
            temp = temp->next;
        }
        std::cout << "Book not found"
                  << "\n";
    }
    void findBookByISBN(std::string ISBN)
    {
        BookNode *temp = head;
        while (temp != NULL)
        {
            if (temp->book.ISBN == ISBN)
            {
                std::cout << temp->book.id << " " << temp->book.title << " " << temp->book.author_name << " " << temp->book.ISBN << "\n";
                return;
            }
            temp = temp->next;
        }
        std::cout << "Book not found"
                  << "\n";
    }
    void deleteBookByTitle(std::string title)
    {
        BookNode *temp = head;
        while (temp != NULL)
        {
            if (temp->book.title == title)
            {
                if (temp == head)
                {
                    head = temp->next;
                    head->prev = NULL;
                    delete temp;
                    return;
                }
                else if (temp == tail)
                {
                    tail = temp->prev;
                    tail->next = NULL;
                    delete temp;
                    return;
                }
                else
                {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    delete temp;
                    return;
                }
            }
            temp = temp->next;
        }
        std::cout << "Book not found"
                  << "\n";
    }
    void deleteBookById(int id)
    {
        BookNode *temp = head;
        while (temp != NULL)
        {
            if (temp->book.id == id)
            {
                if (temp == head)
                {
                    head = temp->next;
                    head->prev = NULL;
                    delete temp;
                    return;
                }
                else if (temp == tail)
                {
                    tail = temp->prev;
                    tail->next = NULL;
                    delete temp;
                    return;
                }
                else
                {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    delete temp;
                    return;
                }
            }
            temp = temp->next;
        }
        std::cout << "Book not found"
                  << "\n";
    }
    void deleteBookByISBN(std::string ISBN)
    {
        BookNode *temp = head;
        while (temp != NULL)
        {
            if (temp->book.ISBN == ISBN)
            {
                if (temp == head)
                {
                    head = temp->next;
                    head->prev = NULL;
                    delete temp;
                    return;
                }
                else if (temp == tail)
                {
                    tail = temp->prev;
                    tail->next = NULL;
                    delete temp;
                    return;
                }
                else
                {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    delete temp;
                    return;
                }
            }
            temp = temp->next;
        }
        std::cout << "Book not found"
                  << "\n";
    }
    void issueBookToUser(User *u)
    {
        BookNode *temp = head;
        std::cout << "Please enter the title of the book you want to issue:"
                  << "\n";
        std::cin >> u->requestedTitle;
        while (temp != NULL)
        {
            if (temp->book.title == u->requestedTitle)
            {
                if (temp->book.is_available)
                {
                    temp->book.is_available = false;
                    std::cout << "Book issued successfully!"
                              << "\n";
                    u->issuedBooks.emplace_back(temp->book);
                    recordBookTransaction(u->username, u->requestedTitle, "issued");
                    return;
                }
                else
                {
                    std::cout << "Book not available/issued already."
                              << "\n";
                    return;
                }
            }
            temp = temp->next;
        }
        if (temp == NULL)
        {
            std::cout << "Book does not exist on the bookshelf"
                      << "\n";
        }
    }
    void returnBook(User *u)
    {
        if (u->issuedBooks.empty())
        {
            std::cout << "There are no books to return"
                      << "\n";
            return;
        }
        BookNode *temp = head;
        std::cout << "Please enter the title of the book you want to return:"
                  << "\n";
        std::cin >> u->requestedTitle;
        while (temp != NULL)
        {
            if (temp->book.title == u->requestedTitle)
            {
                if (!temp->book.is_available)
                {
                    temp->book.is_available = true;
                    std::cout << "Book returned successfully!"
                              << "\n";
                    u->issuedBooks.erase(std::remove_if(u->issuedBooks.begin(), u->issuedBooks.end(), [&](const Book &b)
                                                        { return b.title == u->requestedTitle; }),
                                         u->issuedBooks.end());
                    recordBookTransaction(u->username, u->requestedTitle, "returned");
                    return;
                }
                else
                {
                    std::cout << "Book has not been issued yet"
                              << "\n";
                }
            }
            temp = temp->next;
        }
        if (temp == NULL)
        {
            std::cout << "Book does not exist on the bookshelf"
                      << "\n";
        }
    }
    void recordBookTransaction(const std::string &username, const std::string &bookTitle, const std::string &action)
    {
        std::ofstream file;
        file.open("book_transactions.txt", std::ios_base::app);
        if (file.is_open())
        {
            file << "Username: " << username << ", Book: " << bookTitle << ", Action: " << action << "\n";
            file.close();
        }
        else
        {
            std::cout << "Unable to open file";
        }
    }
    void quicksort()
    {
        quicksort(head, tail);
    }
};
class Library
{
public:
    User u;
    BookShelf bs;
    Library() {}
    Library(User u, BookShelf bs)
    {
        this->u = u;
        this->bs = bs;
    }
    void showMenu()
    {
        std::cout << "\t---------------WELCOME TO LIB PROCURATIO---------------"
                  << "\n";
        std::cout << "\t\tPLEASE SELECT AN OPTION FROM THE FOLLOWING"
                  << "\n";
        std::cout << "1. Create new user"
                  << "\n";
        std::cout << "2. Show all users"
                  << "\n";
        std::cout << "3. Show all books"
                  << "\n";
        std::cout << "4. Search for a book"
                  << "\n";
        std::cout << "5. Return a book"
                  << "\n";
        std::cout << "6. Sort books"
                  << "\n";
        std::cout << "7. Show issued books of current user"
                  << "\n";
        std::cout << "7. Quit"
                  << "\n";
        handleUserChoice();
    }

    void handleUserChoice()
    {
        char userChoice;
        std::cin >> userChoice;
        switch (userChoice)
        {
        case '1':
            break;
        case '2':
            break;
        case '3':
            break;
        case '4':
            break;
        case '5':
            break;
        case '6':
            break;
        case '7':
            break;
        case '8':
            break;
        default:
            std::cout << "Invalid choice. Please try again."
                      << "\n";
            handleUserChoice();
            break;
        }
    }
};