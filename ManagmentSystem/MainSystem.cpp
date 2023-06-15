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
void createBook();

int main()
{
    //bool bookExists = false; //boolean for if a book exists
    populate();
    std::cout << "----Library Inventory Management System----" << std::endl;
    int userIn = 0;
    while (userIn != 7) {
        //prompt
        std::cout << "\nPlease enter the line number associated to the following options: " << std::endl;
        std::cout << "1. Add Book " << std::endl;
        std::cout << "2. Remove Book " << std::endl;
        std::cout << "3. Update Book " << std::endl;
        std::cout << "4. Search Author" << std::endl;
        std::cout << "5. Search Title" << std::endl;
        std::cout << "6. Return Inventory List" << std::endl;
        std::cout << "7. Exit" << std::endl;

        std::cin >> userIn;

        //case
        switch (userIn) {
        case 1:
            createBook();
            booksTotal++;
            serialNum++;
            break;
        case 2:
            std::cout << "remove book was selected" << std::endl;
            break;
        case 3:
            std::cout << "update book was selected" << std::endl;
            break;
        case 4:
            std::cout << "search author was selected" << std::endl;
            break;
        case 5:
            std::cout << "search title was selected" << std::endl;
            break;
        case 6:
            std::cout << "Inventory" << std::endl;
            library.get_inventory();
            break;
        case 7:
            std::cout << "Total Books: " << booksTotal << std::endl;
            std::cout << "Closing program..." << std::endl;
            break;
        default:
            std::cout << "Not a valid selection. " << std::endl;
            break;
        }
    }

    return(0);

}

//prompt user for new book info and creates book
void createBook() {
    std::string I;
    std::string T;
    std::string A;
    int P;
    int genre = 0;
    int reader = 0;
    std::cout << "---- Adding a new book. ----" << std::endl;
    std::cout << "Please provide the title:";
    std::cin.ignore();
    getline(std::cin, T);
    std::cout << "Please provide the author:";
    getline(std::cin, A);
    std::cout << "Please provide the number of pages:";
    std::cin >> P;

    while ((genre <= 0) && (genre < 2)) {
        //prompt
        std::cout << "Is this book a fiction or nonfiction? Select the corresponding number from the list below." << std::endl;
        std::cout << "1. Fiction" << std::endl;
        std::cout << "2. Nonfiction" << std::endl;
        std::cin >> genre;

        switch (genre) {
        case 1:
            I.append("F");
            break;
        case 2:
            I.append("N");
            break;
        default:
            std::cout << "Not a valid entry. Try Again." << std::endl;
            break;
        }
    }
    while ((reader <= 0) && (reader < 4)) {
        std::cout << "Is this book suitable for children, young adults, adult, or all? Select the corrresponding number from the list below." << std::endl;
        std::cout << "1. Children" << std::endl;
        std::cout << "2. Young Adults" << std::endl;
        std::cout << "3. Adults" << std::endl;
        std::cout << "4. All" << std::endl;
        std::cin >> reader;
        switch (reader) {
        case 1:
            I.append("CH");
            break;
        case 2:
            I.append("YA");
            break;
        case 3:
            I.append("AD");
            break;
        case 4:
            I.append("AL");
            break;
        default:
            std::cout << "Not a valid entry. Try Again." << std::endl;
            break;
        }
    }
    std::string itos = std::to_string(serialNum);
    I.append(itos);
    library.add_book(I, T, A, P);
}

//prepopulates the information
void populate() {
    library.add_book("FAD1000", "FRANKENSTEIN", "MARY SHELLY", 247);
    library.add_book("FAD1001", "THE SCARLET LETTER", "NATHANIEL HAWTHORNE", 279);
}

