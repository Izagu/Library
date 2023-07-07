// LibraryManagement.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Implementations files must include the corresponding header file because the compiler needs to see the declarations first before
//seeing the code for each declaration

#include <iostream>
#include <string>
#include <cstdint>
#include <vector>
#include "ManagementSystem.h"

//upper case function
std::string capString(const std::string& s) {
    std::string capS = s;
    for (char& c : capS) {
        c = std::toupper(c);
    }
    return capS;
}

Book::Book(std::string id_i, std::string title_i, std::string author_i, int pages_i) {
    bookID = id_i;
    title = title_i;
    author = author_i;
    pages = pages_i;
}
//getters
std::string Book::get_id() {
    return bookID;
}
std::string Book::get_title() {
    return title;
}
std::string Book::get_author() {
    return author;
}
int Book::get_pages() {
    return pages;
}
void Book::set_title(std::string new_title) {
    std::string capT = capString(new_title);
    title = capT;
}
void Book::set_author(std::string new_author) {
    std::string capA = capString(new_author);
    author = capA;
}
void Book::set_pages(int new_pages) {
    pages = new_pages;
}
void Library::prePop(std::string bookID, std::string title, std::string author, int pages) {
    bookList.push_back(Book(bookID, title, author, pages));
}
void Library::add_book(int serialNum) {
    std::string I;
    std::string T;
    std::string A;
    int P;
    int genre = 0;
    int reader = 0;
    std::cout << "\n---- Adding a new book. ----\n" << std::endl;
    std::cout << "Please provide the title:";
    std::cin.ignore();
    getline(std::cin, T);
    std::string capT = capString(T);
    std::cout << "Please provide the author:";
    getline(std::cin, A);
    std::string capA = capString(A);
    std::cout << "Please provide the number of pages:";
    std::cin >> P;

    while ((genre <= 0) && (genre < 2)) {
        //prompt to create ID number
        std::cout << "\nIs this book a fiction or nonfiction? (select the corresponding number)" << std::endl;
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
        std::cout << "\nIs this book suitable for children, young adults, adult, or all? (select the corrresponding number):" << std::endl;
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
    bookList.push_back(Book(I, capT, capA, P));
}
void Library::get_inventory() {
    for (auto& x : bookList) {
        std::cout << "Book ID: " << x.get_id()  << " , Title: " << x.get_title() << " , author: " << x.get_author() << " , total pages: " << x.get_pages() << std::endl;
    }
}
void Library::remove_book() {
    std::string forDeletion;
    std::cout << "Please provide the ID of the book you would like to remove:";
    std::cin.ignore();
    getline(std::cin, forDeletion);
    bookList.erase(std::remove_if(bookList.begin(), bookList.end(), [&](auto& obj) {
        return forDeletion.compare(obj.get_id()) == 0;
        }), bookList.end());

}
void Library::update_book() {
    std::string bookItem;
    int selection = 0;
    std::cout << "Please provide the ID of the book you would like to update (This item is case sensative):" << std::endl;
    std::cin.ignore();
    getline(std::cin, bookItem);
    while ((selection <= 0) && (selection < 4)) {
        std::string newT;
        std::string newA;
        int newP;
        std::cout << "\nWhat would you like to update? (select the corresponding number):" << std::endl;
        std::cout << "1. Title" << std::endl;
        std::cout << "2. Author" << std::endl;
        std::cout << "3. Pages" << std::endl;
        std::cout << "4. All" << std::endl;
        std::cin >> selection;
        switch (selection) {
        case 1:
            std::cout << "\nPlease provide the new title:";
            std::cin.ignore();
            getline(std::cin, newT);
            for(auto& x : bookList) {
                if (bookItem.compare(x.get_id()) == 0){ x.set_title(newT);}
            }
            break;
        case 2:
            std::cout << "\nPlease provide the new author:";
            std::cin.ignore();
            getline(std::cin, newA);
            for (auto& x : bookList) {
                if (bookItem.compare(x.get_id()) == 0) { x.set_author(newA); }
            }
            break;
        case 3:
            std::cout << "\nPlease provide the number of pages:";
            std::cin >> newP;
            for (auto& x : bookList) {
                if (bookItem.compare(x.get_id()) == 0) { x.set_pages(newP); }
            }
            break;
        case 4:
            std::cout << "\nPlease provide the new title:";
            std::cin.ignore();
            getline(std::cin, newT);
            std::cout << "\nPlease provide the new author:";
            getline(std::cin, newA);
            std::cout << "\nPlease provide the number of pages:";
            std::cin >> newP;
            for (auto& x : bookList) {
                if (bookItem.compare(x.get_id()) == 0) {
                    x.set_title(newT);
                    x.set_author(newA);
                    x.set_pages(newP);
                }
            }
            break;
        default:
            std::cout << "Not a valid entry. Try Again." << std::endl;
            break;
        }
    }
}

