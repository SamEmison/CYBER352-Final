#ifndef ORDER_HPP
#define ORDER_HPP

#include "OrderLine.hpp"
#include <vector>
#include <memory>

class Order {
private:
    std::vector<OrderLine> orderLines;
    
    // TODO: Helper method to check if book already exists in order
    bool containsBook(const Book& book) const;
    
public:
    // TODO: Add an order line with validation
    void addOrderLine(const OrderLine& orderLine);
    
    // TODO: Get all order lines
    std::vector<OrderLine> getOrderLines() const;
    
    // TODO: Get total quantity of books in order
    int getTotalQuantity() const;
};

#endif // ORDER_HPP
