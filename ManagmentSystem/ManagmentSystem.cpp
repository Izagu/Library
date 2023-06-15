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
    title = new_title;
}
void Book::set_author(std::string new_author) {
    author = new_author;
}
void Book::set_pages(int new_pages) {
    pages = new_pages;
}
void Library::add_book(std::string bookID, std::string title, std::string author, int pages) {
    bookList.push_back(Book(bookID, title, author,pages));
}
void Library::get_inventory() {
    for (auto& x : bookList) {
        std::cout << "Book ID: " << x.get_id() << " , Title: " << x.get_title() << " , author: " << x.get_author() << " , total pages: " << x.get_pages() << std::endl;
    }
}
void Library::remove_book(std::string bookID) {
    for (auto b = bookList.begin(); b != bookList.end(); b++) {
        if (b.get_id() == bookID) {
            bookList.erase(b);
        }
    }
}