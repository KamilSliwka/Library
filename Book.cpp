//
// Created by kamil on 01.08.2023.
//
#include<iostream>
#include "Book.h"


using namespace std;

ostream& operator<<(ostream& ostr, const Book& b) {
    ostr << " Book :(" << b.title << " , " << b.author <<") "<<b.description;

    return ostr;
}

Book::Book() {
    this->author = " empty";
    this->title = " empty";
    this->description = "";
}

Book::Book(const string& author, const string& title) {
    this->author = author;
    this->title = title;
    this->description = "";
}

Book::Book(string&& author, string&& title) {
    this->author = author;
    this->title = title;
    this->description = "";
}

string Book::getAuthor() {
    return this->author;
}

string Book::getTitle() {
    return this->title;
}

string Book::getDescription() {
    return this->description;
}

void Book::setAuthor(const string& author) {
    this->author = author;
}

void Book::setTitle(const string& title) {
    this->title = title;
}

void Book::setDescription(const string& description) {
    this->description = description;
}

void Book::setAuthor(string&& author) {
    this->author = author;
}

void Book::setTitle(string&& title) {
    this->title = title;
}

Book::Book(const Book& other) {//konstruktor kopiujacy
    this->author = other.author;
    this->title = other.title;
    this->description = other.description;

}

Book& Book::operator=(const Book& right) {//kopiujacy operator przypisania
    Book tmp = right;
    swap(this->author, tmp.author);
    swap(this->title, tmp.title);
    swap(this->description, tmp.description);

    return *this;
}

Book::Book(Book&& other)  { //konstruktor przenoszacy
    author = other.author;
    title= other.title;
    description = other.description;

    author = " ";
    title = " ";
    description = " ";
}

Book& Book::operator=(Book&& right) {//przenoszacy operator przypisania

    swap(author, right.author);
    swap(title, right.title);
    swap(description, right.description);

    return *this;
}
