//Sam Emison
//12/08/2025
//Completes the TODOs for Order.hpp

#include "Order.hpp"
#include <stdexcept>

bool Order::containsBook(const Book& book) const {
  for (const auto& line : orderLines) {
    if (line.getBook().getISBN() == book.getISBN()) {
      return true;
    }
  }
  return false;
}

void Order::addOrderLine(const OrderLine& orderLine) {
  if (containsBook(orderLine.getBook())) {
    throw std::invalid_argument("Duplicate book in order");
  }
  orderLines.push_back(orderLine);
}

std::vector<OrderLine> Order::getOrderLines() const {
  return orderLines;
}

int Order::getTotalQuantity() const {
  int total = 0;
  for (const auto& line : orderLines) {
    total += line.getQuantity();
  }
  return total;
}
