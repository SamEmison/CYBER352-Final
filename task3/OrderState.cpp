//Sam Emison
//12/08/2025
//Completes TODOs for OrderState.hpp

#include "OrderState.hpp"

// Constructor starts in CREATED
OrderState::OrderState() : currentState(State::CREATED) {}

// Getter
State OrderState::getCurrentState() const {
  return currentState;
}

// Helper method: validate allowed transitions
bool OrderState::isValidTransition(State from, State to) const {
  switch (from) {
  case State::CREATED:
    return to == State::PAID || to == State::CANCELLED;
  case State::PAID:
    return to == State::SHIPPED || to == State::CANCELLED;
  case State::SHIPPED:
    return to == State::DELIVERED;
  case State::DELIVERED:
  case State::CANCELLED:
    return false;
  default:
    return false;
  }
}

// Transition method
void OrderState::transitionTo(State newState) {
  if (!isValidTransition(currentState, newState)) {
    throw std::runtime_error("Invalid state transition");
  }
  currentState = newState;
}

// String representation
std::string OrderState::toString() const {
  switch (currentState) {
  case State::CREATED:   return "CREATED";
  case State::PAID:      return "PAID";
  case State::SHIPPED:   return "SHIPPED";
  case State::DELIVERED: return "DELIVERED";
  case State::CANCELLED: return "CANCELLED";
  default:               return "UNKNOWN";
  }
}
