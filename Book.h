//
// Created by kamil on 01.08.2023.
//

#ifndef LIBRARY_BOOK_H
#define LIBRARY_BOOK_H

#include "string"

using namespace std;

class Book {
private:

    string author;
    string title;
    string description;

public:
    Book();

    Book(const string& author,const string& title);

    Book(string&& author, string&& title);

    string getAuthor();

    string getTitle();

    string getDescription();

    void setAuthor(const string& author);

    void setTitle(const string& title);

    void setDescription(const string& description);

    void setAuthor(string&& author);

    void setTitle(string&& title);

    friend ostream& operator<<(ostream& ostr, const Book& b );

    Book(const Book& other);

    Book& operator=(const Book& right);

    Book(Book&& other);

    Book& operator=(Book&& right);
};


#endif //LIBRARY_BOOK_H
