Parent_Invasion Project
This is a project for Computer Science 2:
A C++ program that works with parents to help them monitor the websites their kids visit. 

What It Does
-It loads a lists of approved websites from a file
-It checks websites kids visits
-If the site is "Not Approved", it will show an alert. 
-It has descriptions to certain sites so if their kid wanders into a not approved site the 
parents will be notified and shown a small description as to what that site is used for. 

Files Included
'main.cpp' - The program starter and simulation
'WebsiteMonitor.h' -the class blueprint 
'WebsiteMonitor.cpp' -The code that loads and checks sites
'aprroved_sites.txt' -List of approved websites
'site_descriptions.txt' -Descriptions of unapproved websites

How To Run
Compile it using terminal:
'''bash
g++ main.cpp WedsiteMonitor.cpp-o monitor

## 📌 Note
This is a simulation for educational use.  
It doesn't actually monitor real browsing, but it shows how a real tool could work.
