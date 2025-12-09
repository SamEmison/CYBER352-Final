//Sam Emison
//12/8/2025
//Completes TODOs for Orderline.hpp

#include "OrderLine.hpp"
#include <stdexcept>

OrderLine::OrderLine(const Book& book, int quantity)
  : book(book), quantity(quantity)
{
  if (quantity < 1) {
    throw std::invalid_argument("Quantity must be >= 1");
  }
}

Book OrderLine::getBook() const {
  return book;
}

int OrderLine::getQuantity() const {
  return quantity;
}

bool OrderLine::operator==(const OrderLine& other) const {
  return book.getISBN() == other.book.getISBN();
}
