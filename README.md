# Parent_Invasion Project

My Computer Science 2 Project  
It’s a C++ program that helps parents:
- Monitor the websites their kids visit
- Look up website names to learn what they’re used for

 What It Does

🧩 When you run the program, you choose between two options:

### 1️⃣ Monitor Mode
- Type in a website your child visited
- It checks if it's approved (based on a text file)
- If it’s **not approved**, it shows an alert and tells you what the site is for
It also saves the site visit in `visited_log.txt` so parents can review history

### 2️⃣ Site Library Mode
- Type in **any** website (even if your kid didn’t visit it)
- The program tells you what that site is typically used for
- Helps parents recognize new or unfamiliar websites
  
Files Included
'main.cpp' - The program starter and simulation
'WebsiteMonitor.h' -the class blueprint 
'WebsiteMonitor.cpp' -The code that loads and checks sites
'aprroved_sites.txt' -List of approved websites
'site_library.txt' -Info about popular websites for parental reference
'visited_log.txt -Log file that saves all visited sites with result

How To Run
1. Make sure all files are in the same folder  
2. Open a terminal or command prompt  
3. Compile with: g++ main.cpp WedsiteMonitor.cpp-o monitor

## 📌 Note
This is a simulation for educational use.  
It doesn't actually monitor real browsing, but it shows how a real tool could work.

Ideas for the Future:
-Turn it into a real-time background app
-Connect to live site reputation databases
