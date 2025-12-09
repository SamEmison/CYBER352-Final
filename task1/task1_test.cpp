#include <gtest/gtest.h>
#include "ISBN.hpp"
#include "Book.hpp"
#include "Order.hpp"

TEST(Task1, ISBNValidation) {
    EXPECT_THROW(ISBN("123"), std::invalid_argument);
    EXPECT_THROW(ISBN("abcdefghijklm"), std::invalid_argument);
    EXPECT_THROW(ISBN("978-3-16-148410-0"), std::invalid_argument);
    EXPECT_NO_THROW(ISBN("9783161484100"));
}

TEST(Task1, BookCreation) {
    ISBN isbn("9783161484100");
    EXPECT_THROW(Book(isbn, ""), std::invalid_argument);
    Book book(isbn, "Secure by Design");
    EXPECT_EQ(isbn, book.getISBN());
    EXPECT_EQ("Secure by Design", book.getTitle());
}

TEST(Task1, OrderAggregate) {
    Book book1(ISBN("9783161484100"), "Book 1");
    Book book2(ISBN("9783161484101"), "Book 2");
    
    Order order;
    
    // Add first order line
    OrderLine line1(book1, 2);
    EXPECT_NO_THROW(order.addOrderLine(line1));
    
    // Try to add duplicate book
    OrderLine line2(book1, 1);
    EXPECT_THROW(order.addOrderLine(line2), std::invalid_argument);
    
    // Add different book
    OrderLine line3(book2, 3);
    EXPECT_NO_THROW(order.addOrderLine(line3));
    
    EXPECT_EQ(2, order.getOrderLines().size());
    EXPECT_EQ(5, order.getTotalQuantity());
}

//Added this to start it
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
