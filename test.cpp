#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "WebsiteMonitor.h"

void testApprovedSites() {
    WebsiteMonitor wm;
    wm.loadApprovedSites("approved_sites.txt");

    std::vector<std::string> approved = wm.getApprovedSites();

    if (std::find(approved.begin(), approved.end(), "youtube.com") != approved.end()) {
        std::cout << "✅ Test passed: youtube.com is in approved list\n";
    } else {
        std::cout << "❌ Test failed: youtube.com not found\n";
    }
}

void testSiteDescriptions() {
    WebsiteMonitor wm;
    wm.loadSiteDescriptions("site_library.txt");

    std::cout << "Running test: checkVisitedSite(\"tiktok.com\")\n";
    wm.checkVisitedSite("tiktok.com");
}

void testApprovedCheck() {
    WebsiteMonitor wm;
    wm.loadApprovedSites("approved_sites.txt");

    std::cout << "Running test: checkVisitedSite(\"pbs.org\")\n";
    wm.checkVisitedSite("pbs.org");
}

int main() {
    std::cout << "🔍 Running WebsiteMonitor Tests...\n\n";
    testApprovedSites();
    std::cout << "\n";
    testSiteDescriptions();
    std::cout << "\n";
    testApprovedCheck();
    std::cout << "\nAll tests finished.\n";
    return 0;
}
