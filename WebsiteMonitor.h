#ifndef WEBSITE_MONITOR_H
#define WEBSITE_MONITOR_H

#include <string>
#include <vector>
#include <map>

// This is the class that holds everything for monitoring websites
class WebsiteMonitor {
private:
    // Stores the list of websites that are approved
    std::vector<std::string> approvedSites;
    
    // Stores unapproved site names and their descriptions
    std::map<std::string, std::string> siteDescriptions;

public:
    // This function loads the approved sites from a file
    void loadApprovedSites(const std::string& filename);
    
    // This function loads the descriptions of unapproved sites
    void loadSiteDescriptions(const std::string& filename);
    
    // This function checks if a site is allowed or not
    void checkVisitedSite(const std::string& site);
};

#endif
