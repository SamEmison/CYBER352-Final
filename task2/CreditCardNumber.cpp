//Sam Emison
//12/08/2025
//Completes the TODOs for CreditCardNumber.hpp

#include "CreditCardNumber.hpp"

// Constructor with 16-digit validation
CreditCardNumber::CreditCardNumber(const std::string& num)
  : number(num), hasBeenRead(false) 
{
  std::regex pattern("^[0-9]{16}$");
  if (!std::regex_match(num, pattern)) {
    throw std::invalid_argument("Invalid credit card number format");
  }
}

// Move constructor
CreditCardNumber::CreditCardNumber(CreditCardNumber&& other) noexcept
  : number(std::move(other.number)), hasBeenRead(other.hasBeenRead) 
{
  other.number.clear();
  other.hasBeenRead = true; // moved-from object is consumed
}

// Move assignment
CreditCardNumber& CreditCardNumber::operator=(CreditCardNumber&& other) noexcept {
  if (this != &other) {

    std::fill(number.begin(), number.end(), '0');
    number.clear();
      
      number = std::move(other.number);
      hasBeenRead = other.hasBeenRead;

      other.number.clear();
      other.hasBeenRead = true;
    }
    
    return *this;
}

// Read-once getter
std::string CreditCardNumber::readOnce() const {
  if (hasBeenRead) {
    throw std::runtime_error("Credit card number already read");
  }
  hasBeenRead = true;
  std::string temp = number;

  // Clear memory
  std::fill(number.begin(), number.end(), '0');
  number.clear();

  return temp;
}

// Check if number has been read
bool CreditCardNumber::hasBeenConsumed() const {
  return hasBeenRead;
}

// Destructor
CreditCardNumber::~CreditCardNumber() {
  std::fill(number.begin(), number.end(), '0');
  number.clear();
}
