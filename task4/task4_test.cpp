#include "gtest/gtest.h"
#include "FeatureToggle.hpp"

TEST(Task4, FeatureToggleSecurity) {
    std::vector<std::string> features = {"new_checkout", "advanced_search", "beta_features"};
    FeatureToggle toggle(features);
    
    // Check non-existent feature
    EXPECT_FALSE(toggle.isEnabled("non_existent_feature"));
    
    // Try to set feature without admin token
    EXPECT_THROW(toggle.setFeatureState("new_checkout", true, "wrong_token"), std::runtime_error);
    
    // Set feature with correct admin token
    EXPECT_NO_THROW(toggle.setFeatureState("new_checkout", true, "admin_token_123"));
    EXPECT_TRUE(toggle.isEnabled("new_checkout"));
    
    // Check timing attack protection (indirectly)
    // We can't easily test timing, but we can test that invalid features return false
    auto start = std::chrono::high_resolution_clock::now();
    toggle.isEnabled("invalid_feature_name_that_is_very_long");
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    
    // Should complete in reasonable time (not hanging)
    EXPECT_LT(duration.count(), 1000); // Less than 1ms
}

TEST(Task4, InvalidFeature) {
    std::vector<std::string> features = {"feature1", "feature2"};
    FeatureToggle toggle(features);
    EXPECT_THROW(toggle.setFeatureState("invalid_feature", true, "admin_token_123"), std::runtime_error);
    EXPECT_FALSE(toggle.isEnabled("invalid_feature"));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
