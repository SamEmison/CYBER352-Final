#ifndef BOOK_HPP
#define BOOK_HPP

#include "ISBN.hpp"
#include <string>

class Book {
private:
    ISBN isbn;
    std::string title;
    
public:
    // TODO: Implement constructor with validation
    Book(const ISBN& isbn, const std::string& title);
    
    // TODO: Implement getters
    ISBN getISBN() const;
    std::string getTitle() const;
    
    // TODO: Implement equality based on ISBN
    bool operator==(const Book& other) const;
};

#endif // BOOK_HPP
