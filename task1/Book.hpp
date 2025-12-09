#ifndef BOOK_HPP
#define BOOK_HPP

#include "ISBN.hpp"
#include <string>

class Book {
private:
    ISBN isbn;
    std::string title;
    
public:
    //Implemented constructor with validation
    Book(const ISBN& isbn, const std::string& title);
    
    //Implemented getters
    ISBN getISBN() const;
    std::string getTitle() const;
    
    //Implemented equality based on ISBN
    bool operator==(const Book& other) const;
};

#endif // BOOK_HPP
