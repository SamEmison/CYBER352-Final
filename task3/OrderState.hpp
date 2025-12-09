#ifndef ORDERSTATE_HPP
#define ORDERSTATE_HPP

#include <stdexcept>
#include <string>

enum class State {
    CREATED,
    PAID,
    SHIPPED,
    DELIVERED,
    CANCELLED
};

class OrderState {
private:
    State currentState;
    
    //Helper method to check if transition is valid
    bool isValidTransition(State from, State to) const;
    
public:
    //Implement constructor
    OrderState();
    
    //Implement state transition method
    void transitionTo(State newState);
    
    //Implement getter
    State getCurrentState() const;
    
    //Implement string representation
    std::string toString() const;
};

#endif // ORDERSTATE_HPP
