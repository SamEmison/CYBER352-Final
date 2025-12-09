#include "gtest/gtest.h"
#include "OrderState.hpp"

TEST(Task3, OrderStateTransitions) {
    OrderState state;
    EXPECT_EQ(State::CREATED, state.getCurrentState());
    
    // Valid transition
    EXPECT_NO_THROW(state.transitionTo(State::PAID));
    EXPECT_EQ(State::PAID, state.getCurrentState());
    
    // Invalid transition
    EXPECT_THROW(state.transitionTo(State::DELIVERED), std::runtime_error);
    
    // Valid transition to SHIPPED
    EXPECT_NO_THROW(state.transitionTo(State::SHIPPED));
    
    // Cancel from SHIPPED should fail
    EXPECT_THROW(state.transitionTo(State::CANCELLED), std::runtime_error);
    
    // Deliver should succeed
    EXPECT_NO_THROW(state.transitionTo(State::DELIVERED));
    
    // No more transitions after DELIVERED
    EXPECT_THROW(state.transitionTo(State::PAID), std::runtime_error);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
