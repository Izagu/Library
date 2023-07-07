//header files are .h files and usually have class definitions and declarations
#pragma once
#ifndef LIB_H
#define LIB_H

#include <string>
#include <vector>


class Book {
public:
    Book(std::string id_i, std::string title_i, std::string author_i, int pages_i);

    //getters
    std::string get_id();
    std::string get_title();
    std::string get_author();
    int get_pages();

    //setters
    void set_title(std::string new_title);
    void set_author(std::string new_author);
    void set_pages(int new_pages);

    //vars in class
private:
    std::string bookID;
    std::string title;
    std::string author;
    int pages;

};

class Library {
private:
    std::vector<Book> bookList;

public:
    void prePop(std::string , std::string, std::string, int);
    void add_book(int);
    void get_inventory();
    void remove_book();
    void update_book();
};


#endif //LIB_H

