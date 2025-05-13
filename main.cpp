#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include "WebsiteMonitor.h"

// Loads site descriptions into a map
std::map<std::string, std::string> loadSiteLibrary(const std::string& filename) {
    std::map<std::string, std::string> library;
    std::ifstream file(filename);
    std::string line;
    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string site, desc;
        getline(ss, site, '|');
        getline(ss, desc);
        library[site] = desc;
    }
    return library;
}

int main() {
    WebsiteMonitor wm;
    std::map<std::string, std::string> siteLibrary;

    wm.loadApprovedSites("approved_sites.txt");
    siteLibrary = loadSiteLibrary("site_library.txt");

    std::ofstream logFile("visited_log.txt", std::ios::app); // open for appending
    if (!logFile) {
        std::cout << "Could not open log file." << std::endl;
        return 1;
    }

    int choice;
    std::string input;

    std::cout << "==============================\n";
    std::cout << "👩‍👧 SafeSurfer - Parent Tool\n";
    std::cout << "1. Monitor kid's visited websites\n";
    std::cout << "2. Look up website info\n";
    std::cout << "3. Exit\n";
    std::cout << "==============================\n";

    while (true) {
        std::cout << "\nEnter choice (1-3): ";
        std::cin >> choice;
        std::cin.ignore();  // clear input buffer

        if (choice == 1) {
            std::cout << "\nMonitoring mode - type website names to check. Type 'exit' to return to menu.\n";
            while (true) {
                std::cout << "🔍 Enter visited website: ";
                std::getline(std::cin, input);
                if (input == "exit") break;

                bool approved = false;
                for (const auto& site : wm.getApprovedSites()) {
                    if (site == input) {
                        approved = true;
                        break;
                    }
                }

                if (!approved) {
                    std::cout << "[ALERT] Unapproved site visited: " << input << "\n";
                    if (siteLibrary.count(input)) {
                        std::cout << "→ Description: " << siteLibrary[input] << "\n";
                    } else {
                        std::cout << "→ No description available.\n";
                    }
                    logFile << input << " - ALERT: Unapproved\n";
                } else {
                    std::cout << "[OK] Approved site: " << input << "\n";
                    logFile << input << " - OK: Approved\n";
                }
                std::cout << "\n";
            }
        } else if (choice == 2) {
            std::cout << "\nLibrary lookup mode - type a website to learn more. Type 'exit' to return to menu.\n";
            while (true) {
                std::cout << "🔍 Enter website to search: ";
                std::getline(std::cin, input);
                if (input == "exit") break;

                if (siteLibrary.count(input)) {
                    std::cout << "📖 Description: " << siteLibrary[input] << "\n";
                } else {
                    std::cout << "❌ No info available for this site.\n";
                }
            }
        } else if (choice == 3) {
            std::cout << "Goodbye, chica! 👋\n";
            break;
        } else {
            std::cout << "Invalid option. Try again.\n";
        }
    }

    logFile.close();
    return 0;
}
