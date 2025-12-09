#ifndef SECUREDATABASEACCESSOR_HPP
#define SECUREDATABASEACCESSOR_HPP

#include <string>
#include <stdexcept>
#include <memory>

// Custom exception classes
class DatabaseException : public std::runtime_error {
public:
    DatabaseException(const std::string& message) : std::runtime_error(message) {}
};

class DatabaseConnectionException : public DatabaseException {
public:
    DatabaseConnectionException() : DatabaseException("Database connection failed") {}
};

class DatabaseQueryException : public DatabaseException {
public:
    DatabaseQueryException() : DatabaseException("Database query failed") {}
};

class SecureDatabaseAccessor {
private:
    std::string connectionString;
    bool isConnected;
    
    //Helper to sanitize error messages
    std::string sanitizeErrorMessage(const std::string& rawError) const;
    
public:
    //Constructor
    SecureDatabaseAccessor(const std::string& connString);
    
    //Connect to database
    void connect();
    
    //Execute query
    std::string executeQuery(const std::string& query);
    
    //Disconnect
    void disconnect();
    
    bool connected() const;
};

#endif // SECUREDATABASEACCESSOR_HPP
