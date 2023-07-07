//this main implementation file does not store the class but instead contains the code the user will interact with.
#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>
#include <cctype>
#include "ManagementSystem.h"

const int MAX_CHAR = 40;
int serialNum = 1002;
int booksTotal = 2;
Library library;
void populate();

int main()
{
    //bool bookExists = false; //boolean for if a book exists
    populate();
    std::cout << "----Library Inventory Management System----" << std::endl;
    int userIn = 0;
    while (userIn != 5) {
        //prompt
        std::cout << "\n----Main Menu----" << std::endl;
        std::cout << "How can I help you? (select the corresponding number):" << std::endl;
        std::cout << "1. Add Book " << std::endl;
        std::cout << "2. Remove Book " << std::endl;
        std::cout << "3. Update Book " << std::endl;
        std::cout << "4. Return Inventory List" << std::endl;
        std::cout << "5. Exit" << std::endl;

        std::cin >> userIn;

        //case
        switch (userIn) {
            //create book
        case 1:
            //createBook()
            library.add_book(serialNum);
            booksTotal++;
            serialNum++;
            std::cout << "*Book Added*" << std::endl;
            break;
            //remove book
        case 2:
            std::cout << "\n----Remove Book----\n" << std::endl;
            std::cout << "\nHere are all the books avaliable for removal:\n" << std::endl;
            library.get_inventory();
            library.remove_book();
            std::cout << "*Book Removed*" << std::endl;
            booksTotal--;
            break;
            //update book
        case 3:
            std::cout << "\n----Update Book----\n" << std::endl;
            library.get_inventory();
            std::cout << "\nI listed all the books avaliable for UPDATE above." << std::endl;
            library.update_book();
            std::cout << "*Book Updated*" << std::endl;
            break;
            //search title
        case 4:
            std::cout << "\n----Book Inventory----\n" << std::endl;
            library.get_inventory();
            break;
        case 5:
            std::cout << "\n----Closing Program----\n" << std::endl;
            std::cout << "Total Books: " << booksTotal << std::endl;
            std::cout << "Goodbye..." << std::endl;
            break;
        default:
            std::cout << "Not a valid selection. " << std::endl;
            break;
        }
    }

    return(0);

}
//prepopulates lib with information
void populate() {
    library.prePop("FAD1000", "FRANKENSTEIN", "MARY SHELLY", 247);
    library.prePop("FAD1001", "THE SCARLET LETTER", "NATHANIEL HAWTHORNE", 279);
}

