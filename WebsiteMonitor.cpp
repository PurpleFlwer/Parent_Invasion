#include "WebsiteMonitor.h"
#include <iostream>
#include <fstream>
#include <sstream>

void WebsiteMonitor::loadApprovedSites(const std::string& filename) {
    std::ifstream file(filename);
    std::string site;
    while (getline(file, site)) {
        approvedSites.push_back(site);
    }
}

void WebsiteMonitor::loadSiteDescriptions(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string site, desc;
        getline(ss, site, '|');
        getline(ss, desc);
        siteDescriptions[site] = desc;
    }
}

void WebsiteMonitor::checkVisitedSite(const std::string& site) {
    bool approved = false;
    for (const auto& allowed : approvedSites) {
        if (site == allowed) {
            approved = true;
            break;
        }
    }

    if (!approved) {
        std::cout << "[ALERT] Unapproved site visited: " << site << "\n";
        if (siteDescriptions.count(site)) {
            std::cout << "→ Description: " << siteDescriptions[site] << "\n";
        } else {
            std::cout << "→ No description available.\n";
        }
    } else {
        std::cout << "[OK] Approved site: " << site << "\n";
    }
}
