//Programmer:Daisy Banas
// Class:COMPSCI2
//  This C++ program allows parents to monitor websites visited by their kids.
// It uses file I/O, a menu system, logging, and a site info lookup.

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>
#include "WebsiteMonitor.h"

// Convert string to lowercase
std::string toLower(const std::string& str) {
    std::string lower = str;
    std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
    return lower;
}

// Load site descriptions into a map
std::map<std::string, std::string> loadSiteLibrary(const std::string& filename) {
    std::map<std::string, std::string> library;
    std::ifstream file(filename);
    std::string line;
    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string site, desc;
        getline(ss, site, '|');
        getline(ss, desc);
        library[toLower(site)] = desc;
    }
    return library;
}

// Get formatted current time
std::string getCurrentTimestamp() {
    time_t now = time(0);
    tm* localtm = localtime(&now);
    char buffer[32];
    strftime(buffer, sizeof(buffer), "[%Y-%m-%d %H:%M:%S]", localtm);
    return std::string(buffer);
}

int main() {
    WebsiteMonitor wm;
    std::map<std::string, std::string> siteLibrary;

    wm.loadApprovedSites("approved_sites.txt");
    siteLibrary = loadSiteLibrary("site_library.txt");

    std::ofstream logFile("visited_log.txt", std::ios::app); // append mode
    if (!logFile) {
        std::cout << "Could not open log file." << std::endl;
        return 1;
    }

    int choice;
    std::string input;

    while (true) {
        std::cout << "\n==============================\n";
        std::cout << "Parent Tool\n";
        std::cout << "1. Monitor kid's visited websites\n";
        std::cout << "2. Look up website info\n";
        std::cout << "3. Exit\n";
        std::cout << "4. View website visit log\n";
        std::cout << "==============================\n";

        std::cout << "Enter choice (1-4): ";
        std::cin >> choice;
        std::cin.ignore();  // clear input buffer

        if (choice == 1) {
            std::cout << "\nMonitoring mode - type website names to check. Type 'exit' to return to menu.\n";
            while (true) {
                std::cout << "Enter visited website: ";
                std::getline(std::cin, input);
                std::string lowered = toLower(input);
                if (lowered == "exit") break;

                bool approved = false;
                for (const auto& site : wm.getApprovedSites()) {
                    if (toLower(site) == lowered) {
                        approved = true;
                        break;
                    }
                }

                std::string timestamp = getCurrentTimestamp();
                if (!approved) {
                    std::cout << "[ALERT] Unapproved site visited: " << input << "\n";
                    if (siteLibrary.count(lowered)) {
                        std::cout << "→ Description: " << siteLibrary[lowered] << "\n";
                    } else {
                        std::cout << "→ No description available.\n";
                    }
                    logFile << timestamp << " " << input << " - ALERT: Unapproved\n";
                } else {
                    std::cout << "[OK] Approved site: " << input << "\n";
                    logFile << timestamp << " " << input << " - OK: Approved\n";
                }
                std::cout << "\n";
            }
        } else if (choice == 2) {
            std::cout << "\nLibrary lookup mode - type a website to learn more. Type 'exit' to return to menu.\n";
            while (true) {
                std::cout << "Enter website to search: ";
                std::getline(std::cin, input);
                std::string lowered = toLower(input);
                if (lowered == "exit") break;

                if (siteLibrary.count(lowered)) {
                    std::cout << "Description: " << siteLibrary[lowered] << "\n";
                } else {
                    std::cout << "No info available for this site.\n";
                }
            }
        } else if (choice == 3) {
            std::cout << "Goodbye\n";
            break;
        } else if (choice == 4) {
            std::cout << "\n===== Website Visit Log =====\n";
            std::ifstream log("visited_log.txt");
            std::string line;
            while (getline(log, line)) {
                std::cout << line << "\n";
            }
            log.close();
        } else {
            std::cout << "Invalid option. Try again.\n";
        }
    }

    logFile.close();
    return 0;
}
