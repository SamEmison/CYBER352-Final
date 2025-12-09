#ifndef ORDERLINE_HPP
#define ORDERLINE_HPP

#include "Book.hpp"

class OrderLine {
private:
    Book book;
    int quantity;
    
public:
    //Implemented constructor with validation
    OrderLine(const Book& book, int quantity);
    
    //Implemented getters
    Book getBook() const;
    int getQuantity() const;
    
    //Implemented equality based on book's ISBN
    bool operator==(const OrderLine& other) const;
};

#endif // ORDERLINE_HPP
