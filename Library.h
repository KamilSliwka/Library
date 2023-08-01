//
// Created by kamil on 01.08.2023.
//

#ifndef LIBRARY_LIBRARY_H
#define LIBRARY_LIBRARY_H
#include "Book.h"
#include <initializer_list>

using namespace std;

class Library {
private:

    Book* array;
    size_t size;

public:

    friend ostream& operator<<(std::ostream& ostr, const Library& v);

    Library();

    Library(size_t size);

    Library(size_t size, Book b);

    Library(initializer_list<Book> list);

    Library(const Library& orig);

    Library(Library&& orig);

    Library& operator=(const Library& right);

    Library& operator=(Library&& right);

    Book& operator[](size_t index);

    const Book& operator[](size_t index) const;

    size_t GetSize() const;

    ~Library();

    Library addBook(Library l);

    Library deleteBook(Library l);

    void author(Library l);

    Library description(Library l);

    void showLibrary(Library l);

    Library bookEdition(Library l);

    Library descriptionEdition(Library l);
};


#endif //LIBRARY_LIBRARY_H
