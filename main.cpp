#include <iostream>
#include "WebsiteMonitor.h"

int main() {
    WebsiteMonitor wm; // Make the monitor
    
    // Load the approved websites and unapproved site descriptions
    wm.loadApprovedSites("approved_sites.txt");
    wm.loadSiteDescriptions("site_descriptions.txt");

    // Simulate websites the kid visited
    std::vector<std::string> visitedSites = {
        "youtube.com",
        "tiktok.com",
        "reddit.com",
        "mathgames.com"
    };

    // Check each site and print result
    for (const auto& site : visitedSites) {
        wm.checkVisitedSite(site);
    }

    return 0; // Done
}
