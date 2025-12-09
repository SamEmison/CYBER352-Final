//Sam Emison
//12/08/2025
//Completes the TODOs for FeatureToggle.hpp


#include "FeatureToggle.hpp"
#include <stdexcept>
#include <algorithm>
#include <cstring>

// Helper: constant-time comparison to prevent timing attacks
static bool secureCompare(const std::string& a, const std::string& b) {
  if (a.size() != b.size()) return false;
  unsigned char result = 0;
  for (size_t i = 0; i < a.size(); i++) {
    result |= a[i] ^ b[i];
  }
  return result == 0;
}

// Constructor
FeatureToggle::FeatureToggle(const std::vector<std::string>& features) {
  validFeatures = features;
    for (const auto& f : features) {
      toggles[f] = false;
    }
}

// Validate feature name
bool FeatureToggle::isValidFeature(const std::string& featureName) const {
  for (const auto& f : validFeatures) {
    if (secureCompare(f, featureName)) return true;
  }
  return false;
}

// Check if enabled (secure)
bool FeatureToggle::isEnabled(const std::string& featureName) const {
  std::lock_guard<std::mutex> lock(mtx);
  if (!isValidFeature(featureName)) return false;
  return toggles.at(featureName);
}

// Set feature state (admin token required)
void FeatureToggle::setFeatureState(const std::string& featureName, bool enabled, const std::string& adminToken) {
  const std::string correctToken = "admin_token_123";
  if (!secureCompare(adminToken, correctToken)) throw std::runtime_error("Not authorized");

  std::lock_guard<std::mutex> lock(mtx);
  if (!isValidFeature(featureName)) throw std::invalid_argument("Invalid feature name");
  toggles[featureName] = enabled;
}

// Get all features
std::unordered_map<std::string, bool> FeatureToggle::getAllFeatures() const {
    std::lock_guard<std::mutex> lock(mtx);
    return toggles;
}

