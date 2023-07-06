// LibraryManagement.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Implementations files must include the corresponding header file because the compiler needs to see the declarations first before
//seeing the code for each declaration

#include <iostream>
#include <string>
#include <cstdint>
#include <vector>
#include "ManagementSystem.h"



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
    std::string capT = new_title;
    for (char& c : capT) {
        c = std::toupper(c);
    }
    title = capT;
}
void Book::set_author(std::string new_author) {
    std::string capA = new_author;
    for (char& c : capA) {
        c = std::toupper(c);
    }
    author = capA;
}
void Book::set_pages(int new_pages) {
    pages = new_pages;
}
void Library::add_book(std::string bookID, std::string title, std::string author, int pages) {
    bookList.push_back(Book(bookID, title, author,pages));
}
void Library::get_inventory() {
    for (auto& x : bookList) {
        std::cout << "Book ID: " << x.get_id()  << " , Title: " << x.get_title() << " , author: " << x.get_author() << " , total pages: " << x.get_pages() << std::endl;
    }
}
void Library::remove_book(std::string bID) {
    bookList.erase(std::remove_if(bookList.begin(), bookList.end(), [&](auto& obj) {
        return bID.compare(obj.get_id()) == 0;
        }), bookList.end());

}
void Library::update_book() {
    std::string bookItem;
    int selection = 0;
    std::cout << "\n----Update Book----" << std::endl;
    std::cout << "\nPlease provide the ID of the book you would like to update (This item is case sensative):" << std::endl;
    std::cin.ignore();
    getline(std::cin, bookItem);
    while ((selection <= 0) && (selection < 4)) {
        std::string newT;
        std::string newA;
        int newP;
        std::cout << "\nWhat would you like to update? (select the corresponding number from the following):" << std::endl;
        std::cout << "1. Title" << std::endl;
        std::cout << "2. Author" << std::endl;
        std::cout << "3. Pages" << std::endl;
        std::cout << "4. All" << std::endl;
        std::cin >> selection;
        switch (selection) {
        case 1:
            std::cout << "\nPlease provide the new title:" << std::endl;
            std::cin.ignore();
            getline(std::cin, newT);
            for(auto& x : bookList) {
                if (bookItem.compare(x.get_id()) == 0){ x.set_title(newT);}
            }
            break;
        case 2:
            std::cout << "\nPlease provide the new author:" << std::endl;
            std::cin.ignore();
            getline(std::cin, newA);
            for (auto& x : bookList) {
                if (bookItem.compare(x.get_id()) == 0) { x.set_author(newA); }
            }
            break;
        case 3:
            std::cout << "\nPlease provide the number of pages:" << std::endl;
            std::cin >> newP;
            for (auto& x : bookList) {
                if (bookItem.compare(x.get_id()) == 0) { x.set_pages(newP); }
            }
            break;
        case 4:
            std::cout << "\nPlease provide the new title:" << std::endl;
            std::cin.ignore();
            getline(std::cin, newT);
            std::cout << "\nPlease provide the new author:" << std::endl;
            getline(std::cin, newA);
            std::cout << "\nPlease provide the number of pages:" << std::endl;
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

