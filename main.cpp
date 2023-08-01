#include <iostream>
#include "Book.h"
#include "Library.h"

using namespace std;
int main() {

    bool finishProgram = false;
    int handling = 0;

    cout << " 1- new book		            2- description	 " << endl;
    cout << " 3- edit book                  4- new description		" << endl;
    cout << " 5- delete book                6-show author 	" << endl;
    cout << " 7- show Library               8- exit	" << endl;


    Library l = { {"J.K Rowling", "Harry Potter"},{"J.R.R Tolkien", "Wladca Pierscieni"} };
    while (!finishProgram) {
        cin >> handling;
        switch (handling)
        {
                case 1: {
                l = l.addBook(l);
                    break;
                case 2:
                    l = l.description(l);
                    break;
                case 3:
                    l = l.bookEdition(l);
                    break;
                case 4:
                    l = l.descriptionEdition(l);
                    break;
                case 5:
                    l = l.deleteBook(l);
                    break;
                case 6:
                    l.author(l);
                    break;
                case 7:
                    l.showLibrary(l);
                    break;
                case 8:
                    finishProgram = true;
                    break;
                default:
                    cout << "wrong number" << endl;
                    break;
            }

        }
    }

    return 0;
}
