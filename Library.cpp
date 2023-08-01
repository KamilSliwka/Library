//
// Created by kamil on 01.08.2023.
//
#include "iostream"
#include "Book.h"
#include "Library.h"
#include <initializer_list>

using namespace std;


ostream& operator<<(std::ostream& ostr, const Library& v) {
    ostr << "Library:{";
    for (std::size_t i = 0; i < v.GetSize(); i++)
    {
        if (i > 0)
            ostr << ',';
        ostr << v[i];
    }
    ostr << '}';
    return ostr;
}

Library::Library(size_t size)
        : size{ size }, array{ new Book[size] }
{

}

Library::Library()
        : Library(0)
{

}

Library::Library(size_t size,Book book)
        : Library(size)
{
    for (size_t i = 0; i < size; i++)
        array[i] = book;
}

Library::Library(initializer_list<Book> list)
        :size{list.size()},array{new Book[list.size()]}
{
    size_t i = 0;
    for (Book book: list) {
        array[i] = book;
        i++;
    }
}

size_t Library::GetSize() const {
    return size;
}

Library::Library(const Library& orig)
        :size(orig.size), array{ new Book[orig.size] }
{
    for (std::size_t i = 0; i < size; i++)
        array[i] = orig.array[i];
}

Library::Library(Library&& orig){
    array = orig.array;
    size = orig.size;
    orig.array = nullptr;
    orig.size = 0;
}

Library& Library::operator=(const Library& right) {
    Library tmp = right;

    swap(array, tmp.array);
    swap(size, tmp.size);
    return *this;
}

Library& Library::operator=(Library&& right){
    swap(array, right.array);
    swap(size, right.size);
    return *this;
}

Book& Library:: operator[](size_t i) {
    return array[i];
}

const Book& Library:: operator[](size_t i) const {
    return array[i];
}

Library:: ~Library()
{
    if (array != nullptr)
        delete[] array;
}

Library Library::addBook(Library library) {
    string author;
    string title;
    cout << "author: " << endl;
    cin >> author;
    cout << "title: " << endl;
    cin >> title;
    Book book= {author, title };
    int size=library.GetSize();
    Library x(size + 1);
    for (int i=0; i < size; i++) {
        x[i] = library[i];
    }
    x[size] = book;
    cout << "book added:" << book<< endl;
    return x;
}

Library Library::deleteBook(Library library) {
    int size = library.GetSize();
    for (int i = 1; i <= size; i++) {
        cout << i << " " << array[i-1] << endl;
    }
    cout << "which number to remove: " << endl;
    int n;
    cin >> n;
    if ((n > 0) && (n < size + 1)) {
        cout<<"delete: "<< array[n-1]<<endl;
        Library x(size - 1);
        for (int i = 0; i < size - 1; i++) {
            if (i >= n - 1) {
                x[i] = library[i + 1];
            }
            else {
                x[i] = library[i];
            }
        }

        return x;
    }
    return library;
}

void Library::author(Library library) {
    int size = library.GetSize();
    Book book;
    for (int i = 0; i < size; i++) {
        book= library[i];
        cout << i + 1 << " " << book.getTitle() << endl;
    }
    cout << "which title: " << endl;
    int n;
    cin >> n;
    if ((n > 0) && (n < size + 1)) {
        book= library[n - 1];
        cout << "author: "<<book.getAuthor() << endl;
    }
}

Library Library::description(Library library) {
    int size = library.GetSize();
    Book book;
    for (int i = 0; i < size; i++) {
        book= library[i];
        cout << i + 1 << " " << book<< endl;
    }
    cout << "which book: " << endl;
    int n;
    cin >> n;
    if ((n > 0) && (n < size + 1)) {
        cout << "enter a description" << endl;
        string description;
        cin >> description;
        book= library[n - 1];
        book.setDescription(description);
        library[n - 1] = book;
        cout << "description entered" << endl;
        return library;
    }
    return library;
}

void Library::showLibrary(Library library) {
    int size = library.GetSize();
    Book book;
    for (int i = 0; i < size; i++) {
        book= library[i];
        cout << i + 1 << " " << book<< endl;

    }

}

Library Library::bookEdition(Library library) {
    int size = library.GetSize();
    Book book;
    for (int i = 0; i < size; i++) {
        book= library[i];
        cout << i + 1 << " " << book<< endl;
    }
    cout << "which book: " << endl;
    int n;
    cin >> n;
    if ((n > 0) && (n < size + 1)) {
        string author;
        string title;
        cout << "author: " << endl;
        cin >> author;
        cout << "title: " << endl;
        cin >> title;
        Book book= { author, title };
        library[n - 1] = book;
        cout << "edited:" << book<< endl;
        return library;
    }
    return library;
}

Library Library::descriptionEdition(Library library) {
    int size = library.GetSize();
    Book book;
    for (int i = 0; i < size; i++) {
        book= library[i];
        cout << i + 1 << " " << book<< endl;
    }
    cout << "which book: " << endl;
    int n;
    cin >> n;
    if ((n > 0) && (n < size + 1)) {
        cout << "enter a new description" << endl;
        string description;
        cin >> description;
        book= library[n - 1];
        book.setDescription(description);
        library[n - 1] = book;
        cout << "edited:" << book<< endl;
        return library;
    }
    return library;
}
