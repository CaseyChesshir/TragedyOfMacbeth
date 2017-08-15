#include <iostream>
#include <fstream>
#include <ostream>
#include <typeinfo>
#include <string.h>
#include "Character.hpp"
#include "json/json.h"
#include "TragedyOfMacbeth.hpp"

using namespace std;

int main(){
    cout << "initializing" << endl;
    
    Json::Value root;
    Json::Reader reader;
    
    ofstream os;
    os.open("output.txt");
    
    
    filebuf fb;
    fb.open("working.json", ios::in);
    istream is(&fb);

	cout << "initialized, beginning to parse" << endl;
    
    bool parsingSuccessful = reader.parse( is, root );
    
    if ( !parsingSuccessful )
    {
        // report to the user the failure and their locations in the document.
        std::cout  << "Failed to parse configuration\n"
        << reader.getFormattedErrorMessages();
        return 1;
    }

	cout << "parsed successfully, creating Characters" << endl;
    
    
    const Json::Value &val = root[0];
    
    int i=0;
    vector<string> firstWitchLines;
    Character *firstWitch = new Character("First Witch", firstWitchLines);
    
    vector<string> secondWitchLines;
    Character *secondWitch = new Character("Second Witch", secondWitchLines);
    
    vector<string> thirdWitchLines;
    Character *thirdWitch = new Character("Third Witch", thirdWitchLines);
    
    vector<string> allLines;
    Character *all = new Character("ALL", allLines);
    
    vector<string> duncanLines;
    Character *duncan = new Character("DUNCAN", duncanLines);
    
    vector<string> malcolmLines;
    Character *malcolm = new Character("MALCOLM",malcolmLines);
    
    vector<string> sergeantLines;
    Character *ladyMacbeth = new Character("LADY MACBETH",sergeantLines);
    
    vector<string> lennoxLines;
    Character *lennox = new Character("LENNOX", lennoxLines);
    
    vector<string> rossLines;
    Character *ross = new Character("ROSS", rossLines);
    
    vector<string> macbethLines;
    Character *macbeth = new Character("MACBETH", macbethLines);
    
    vector<string> banquoLines;
    Character *banquo = new Character("BANQUO", banquoLines);
    
    vector<string> ladymacbethLines;
    Character *ladymacbeth = new Character("LADY MACBETH", ladymacbethLines);
    
    vector<string> macduffLines;
    Character *macduff = new Character("MACDUFF", macduffLines);
    
    vector<pair<string,string>> EntirePlayLines;

	cout << "Characters created. Beginning json iteration" << endl;
    
    for (Json::ValueConstIterator it = root.begin(); it != root.end(); ++it){
        const Json::Value &temp = *it;
        if(temp.get("play_name", "error").compare("macbeth") == 0){
            if (temp.get("speaker","error").compare("ADRIANO DE ARMADO") != 0){
                os << temp.get("line_id","error") << endl;
            }
            pair<string,string> currentpair = make_pair(temp.get("speaker","error").asString(),
                                                        temp.get("text_entry","error").asString());
            EntirePlayLines.push_back(currentpair);
        }
        i++;
    }
    
    string currentspeaker = "";
    
    
    cout << "json iteration complete. Beginning simulation " << endl;
    
    
    for(vector<pair<string,string>>::const_iterator i = EntirePlayLines.begin(); i != EntirePlayLines.end(); ++i){
        if ((*i).first.compare(currentspeaker) != 0){
            os << endl << (*i).first << ": ";
            currentspeaker = (*i).first;
        }
        os << "  " << (*i).second << endl;
    }
    
    cout << "simulation written to output.txt. about to return" << endl;

    return 0;
}
