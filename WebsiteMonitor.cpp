#include "WebsiteMonitor.h"
#include <iostream>
#include <fstream>
#include <sstream>

// Reads approved websites from the file and stores them
void WebsiteMonitor::loadApprovedSites(const std::string& filename) {
    std::ifstream file(filename); // Open the file
    std::string site;
    while (getline(file, site)) { // Read each line (each site)
        approvedSites.push_back(site); // Add to the approved list
    }
}

// Reads the unapproved site descriptions from the file
void WebsiteMonitor::loadSiteDescriptions(const std::string& filename) {
    std::ifstream file(filename); // Open the file
    std::string line;
    while (getline(file, line)) { // Go through each line
        std::stringstream ss(line); // Split the line at the '|'
        std::string site, desc;
        getline(ss, site, '|'); // Get the site name
        getline(ss, desc);      // Get the description
        siteDescriptions[site] = desc; // Add to map
    }
}

// Checks if the site is approved and prints results
void WebsiteMonitor::checkVisitedSite(const std::string& site) {
    bool approved = false;
    for (const auto& allowed : approvedSites) { // Check all approved sites
        if (site == allowed) { // If it's found
            approved = true;
            break;
        }
    }

    if (!approved) {
        // Not approved? Show alert
        std::cout << "[ALERT] Unapproved site visited: " << site << "\n";
        if (siteDescriptions.count(site)) {
            std::cout << "→ Description: " << siteDescriptions[site] << "\n"; // Show reason
        } else {
            std::cout << "→ No description available.\n";
        }
    } else {
        // Approved? Show okay message
        std::cout << "[OK] Approved site: " << site << "\n";
    }
}
