#ifndef WEBSITE_MONITOR_H
#define WEBSITE_MONITOR_H

#include <string>
#include <vector>
#include <map>

class WebsiteMonitor {
private:
    std::vector<std::string> approvedSites;
    std::map<std::string, std::string> siteDescriptions;

public:
    void loadApprovedSites(const std::string& filename);
    void loadSiteDescriptions(const std::string& filename);
    void checkVisitedSite(const std::string& site);
};

#endif
