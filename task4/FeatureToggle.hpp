#ifndef FEATURETOGGLE_HPP
#define FEATURETOGGLE_HPP

#include <string>
#include <unordered_map>
#include <vector>
#include <mutex>

class FeatureToggle {
private:
    std::unordered_map<std::string, bool> toggles;
    std::vector<std::string> validFeatures;
    mutable std::mutex mtx;
    
    // Helper method to validate feature name
    bool isValidFeature(const std::string& featureName) const;
    
public:
    //Constructor with initial features
    FeatureToggle(const std::vector<std::string>& features);
    
    //Check if feature is enabled (secure against timing attacks)
    bool isEnabled(const std::string& featureName) const;
    
    //Enable/disable feature (admin only)
    void setFeatureState(const std::string& featureName, bool enabled, const std::string& adminToken);
    
    //Get all feature states
    std::unordered_map<std::string, bool> getAllFeatures() const;
};

#endif // FEATURETOGGLE_HPP
