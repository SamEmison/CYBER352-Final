#include "gtest/gtest.h"
#include "SecureDatabaseAccessor.hpp"

TEST(Task5, SecureExceptionHandling) {
    SecureDatabaseAccessor db("server=localhost;user=admin;password=secret123");
    
    // Test connection exception
    EXPECT_THROW(db.connect(), DatabaseConnectionException);
    
    // Even if we catch, the message should not contain sensitive info
    try {
        db.connect();
        FAIL() << "Should have thrown exception";
    } catch (const DatabaseConnectionException& e) {
        std::string errorMsg = e.what();
        // Error message should NOT contain password
        EXPECT_EQ(errorMsg.find("secret123"), std::string::npos);
        // Should have generic message
        EXPECT_NE(errorMsg.find("Database connection failed"), std::string::npos);
    }
    
    // Test query execution when not connected
    EXPECT_THROW(db.executeQuery("SELECT * FROM users"), DatabaseQueryException);
}

TEST(Task5, EdgeCases) {
    SecureDatabaseAccessor db("wrong_conn_string");
    EXPECT_THROW(db.connect(), DatabaseConnectionException);

    SecureDatabaseAccessor db2("valid_connection_string");
    EXPECT_THROW(db2.executeQuery("SELECT * FROM users"), DatabaseQueryException);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
