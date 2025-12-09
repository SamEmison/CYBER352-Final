#ifndef ORDERLINE_HPP
#define ORDERLINE_HPP

#include "Book.hpp"

class OrderLine {
private:
    Book book;
    int quantity;
    
public:
    // TODO: Implement constructor with validation
    OrderLine(const Book& book, int quantity);
    
    // TODO: Implement getters
    Book getBook() const;
    int getQuantity() const;
    
    // TODO: Implement equality based on book's ISBN
    bool operator==(const OrderLine& other) const;
};

#endif // ORDERLINE_HPP
