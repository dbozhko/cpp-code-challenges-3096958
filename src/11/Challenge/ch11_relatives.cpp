// C++ Code Challenges, LinkedIn Learning

// Challenge #11: Finding Relatives
// Write an application that reads a list of people's names in a CSV file and outputs the first pair of people it finds to be possibly related based on their family names.
// Assume that all entries have one name and one family name.
// Entries are separated by commas.
// Names and family names are separated by spaces.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

// Finding Relatives, main()
// Summary: This application displays the first pair of possible relatives from a list of names in a CSV file.
int notmain(){
    std::fstream file ("names.csv", std::ios::in);
    // Read the CSV file.
    if(file.is_open()){

        std::string line;
        std::vector<std::pair<std::string, std::string>> family;
        while(getline(file, line)){
            std::istringstream ss(line);
            std::string name;
            while(getline(ss, name, ',')){
                // Extract family name
                std::istringstream name_ss(name);
                std::string first_name, family_name;
                name_ss >> first_name >> family_name;

                // Check for possible relatives
                for(const auto& existing_family_name : family){
                    if(existing_family_name.second == family_name){
                        std::cout << "Possible relatives found: " << first_name << " " << family_name << " and another person with family name " << existing_family_name.first << " " << family_name << "\n\n" << std::flush;
                        file.close();
                        return 0;
                    }
                }
                family.push_back(std::make_pair(first_name, family_name));
            }
        }
    
        file.close();
    }
    else{
        std::cout << "Something went wrong\n" << std::flush;
        return 1;
    }

    // Write your code here

    std::cout << "No relatives found.\n\n" << std::flush;    
    return 0;
}
 