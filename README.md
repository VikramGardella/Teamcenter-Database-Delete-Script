# **Teamcenter Database Deletion Automation**  

## **Overview**  
This C++ tool automates the tedious process of **deleting items from the Teamcenter Database**, handling **POM reference severance** at multiple levels to ensure a clean and complete deletion. When an item is referenced in various assemblies, manually removing all dependencies is time-consuming—this tool automates that process, making it faster and error-free.  

### **How It Works**  
1. **Scans the database** to identify all **direct and indirect POM references** to the target item.  
2. **Recursively severs** all dependencies, ensuring no orphaned references remain.  
3. **Validates database integrity** before final deletion.  
4. **Deletes the specified item** once all references are safely removed.  

### **Technical Highlights**  
- **Optimized recursive deletion** to handle deeply nested references  
- **Multi-threaded processing** for improved efficiency  
- **Error handling & logging** to prevent unintended data loss  
- **Command-line interface (CLI)** for ease of use  

### **Installation & Usage**  
1. Clone the repository:  
   ```sh
   git clone <repo-url>
   cd Teamcenter-Database-Delete-Script-master
   ```  
2. Compile the program:  
   ```sh
   g++ -o tcDelete main.cpp -lpthread  
   ```  
3. Run the tool with the target item ID:  
   ```sh
   ./tcDelete <item_ID>  
   ```  

### **Disclaimer**  
This tool is intended for **internal use only** and should be used with caution. **Ensure proper backups** before executing deletions, as irreversible data loss can occur.  

---  
