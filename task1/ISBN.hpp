#ifndef ISBN_HPP
#define ISBN_HPP

#include <string>
#include <stdexcept>

class ISBN {
private:
    std::string value;
    
public:
    // TODO: Implement constructor with validation
    ISBN(const std::string& isbn);
    
    // TODO: Implement getter
    std::string getValue() const;
    
    // TODO: Implement equality operators
    bool operator==(const ISBN& other) const;
    bool operator!=(const ISBN& other) const;
    
    // TODO: Implement for use in collections
    bool operator<(const ISBN& other) const;
};

#endif // ISBN_HPP
