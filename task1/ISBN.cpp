#include "ISBN.hpp"
#include <regex>

// TODO: Implement ISBN class methods
ISBN::ISBN(const std::string& isbn) {
    // Validate: 13 digits, only numbers
    std::regex pattern("^[0-9]{13}$");
    if (!std::regex_match(isbn, pattern)) {
        throw std::invalid_argument("Invalid ISBN format");
    }
    value = isbn;
}

std::string ISBN::getValue() const {
    return value;
}

bool ISBN::operator==(const ISBN& other) const {
    return value == other.value;
}

bool ISBN::operator!=(const ISBN& other) const {
    return !(*this == other);
}

bool ISBN::operator<(const ISBN& other) const {
    return value < other.value;
}
