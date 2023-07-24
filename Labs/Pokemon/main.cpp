#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Set.h"
#include "hash_map.h"

#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK
#endif
#define CONSOLE 0

using namespace std;

int main(int argc, char* argv[]){

    HashMap<string, string> Pokemon;
    HashMap<string, string> Move;
    HashMap<string, Set<string> > Effect;
    HashMap<string, Set<string> > inEffect;



    ifstream in(argv[1]);
    ostream& out = CONSOLE ? cout : *(new ofstream(argv[2]));

    if (!in) {
    cerr << "Failed to open input file." << endl;
    return 1;
}

    Set<string> str;
    string line;

    while (getline(in, line)) {
        if (line.empty()) continue;

        istringstream iss(line);
        string item1;
        iss >> item1;
        out << item1;

        if (item1 == "Set:"){
            str.clear();
            string item2;
            while(iss >> item2){
                str.insert(item2);
                out << " " << item2 << " ";
            } 
            out << endl << " [" << str.toString() << "]" << endl;
        }

        if (item1 == "Pokemon:"){
            string item2, item3;
            iss >> item2 >> item3;
            out << " " << item2 << " " << item3;

            Pokemon[item2] = item3;
        }
        
        if (item1 == "Pokemon"){
            out << ": " << Pokemon.size() << "/" << Pokemon.max_size() << endl;
            out << Pokemon.toString();
        }

        if (item1 == "Move:"){
            string item2, item3;
            iss >> item2 >> item3;
            out << " " << item2 << " " << item3;

            Move[item2] = item3;
        }
        
        if (item1 == "Moves"){
            out << ": " << Move.size() << "/" << Move.max_size() << endl;
            out << Move.toString();
        }

        if (item1 == "Effective:"){
            Set<string> effectivities;
            string item2;
            iss >> item2;
            out << " " << item2;
            string item3;

            while (iss >> item3) {
                effectivities.insert(item3);
                out << " " << item3;
                }
            Effect[item2] = effectivities;
            
        }

        if (item1 == "Ineffective:"){
            string item2, item3;
            Set<string> ineffectivities;
            iss >> item2;
            out << " " << item2;

            while (iss >> item3) {

                ineffectivities.insert(item3);
                out << " " << item3;
            

                }

            inEffect[item2] = ineffectivities;

            
        }

        if (item1 == "Effectivities"){
            out << ": " << Effect.size() << "/" << Effect.max_size() << endl;
            out << Effect.toString();
        }

        if (item1 == "Ineffectivities"){
            out << ": " << inEffect.size() << "/" << inEffect.max_size() << endl;
            out << inEffect.toString();
        }
        
        if (item1 == "Battle:"){
            string p1, m1, p2, m2, tm1, tm2, tp1, tp2, eff1, eff2, result;
           
            iss >> p1 >> m1 >> p2 >> m2;

            cout << endl << "p1: " << p1 << " Pokemonp1: " << Pokemon[p1] << endl; //type pokemon 1
            cout << "m1: " << m1 << " MOVEm1: " << Move[m1] << endl; //type move 1
            cout << "p2: " << p2 << " Pokemonp2: " <<Pokemon[p2] << endl; //type pokemon 2
            cout << "m2: " << m2 << " MOVEm2: " << Move[m2] << endl << endl; //type move 2

            // if(m1 == "magical_leaf"){
            //     cout << Move[m1]<< endl << endl;
            // }



            if(Effect[Move[m1]].count(Pokemon[p2]) == 1){
                eff1 = "super effective";
            } else if(inEffect[Move[m1]].count(Pokemon[p2]) == 1){
                eff1 = "ineffective";
            }else if (Effect[Move[m1]].count(Pokemon[p2]) == 0) {
                eff1 = "effective";
            } 

            if(Effect[Move[m2]].count(Pokemon[p1]) == 1){
                eff2 = "super effective";
            } else if(inEffect[Move[m2]].count(Pokemon[p1]) == 1){
                eff2 = "ineffective";
            }else if (Effect[Move[m2]].count(Pokemon[p1]) == 0) {
                eff2 = "effective";
            }  

            int p1top2 = Effect[Move[m1]].count(Pokemon[p2]) - inEffect[Move[m1]].count(Pokemon[p2]);
            int p2top1 = Effect[Move[m2]].count(Pokemon[p1]) - inEffect[Move[m2]].count(Pokemon[p1]);
           

            out << " " << p1 << " " << m1 << " " << p2 << " " << m2 << endl;
            out << "  " << p1 << " (" << m1 << ") vs " << p2 << " (" << m2 << ")" << endl;
            out << "  " << p1 << " is a " << Pokemon[p1] << " type Pokemon." << endl;
            out << "  " << p2 << " is a " << Pokemon[p2] << " type Pokemon." << endl;
            out << "  " << m1 << " is a " << Move[m1] << " type move." << endl;
            out << "  " << m2 << " is a " << Move[m2] << " type move." << endl;
            out << "  " << m1 << " is super effective against [" << Effect[Move[m1]] << "] type Pokemon." << endl;
            out << "  " << m1 << " is ineffective against [" << inEffect[Move[m1]] << "] type Pokemon." << endl;
            //   Natu's psybeam is effective against Tyranitar
            out << "  " << p1 << "'s " << m1 << " is " << eff1 << " against " << p2 << endl;
            out << "  " << m2<< " is super effective against [" << Effect[Move[m2]] << "] type Pokemon." << endl;
            out << "  " << m2 << " is ineffective against [" << inEffect[Move[m2]] << "] type Pokemon." << endl;
            out << "  " << p2 << "'s " << m2 << " is " << eff2 << " against " << p1 << endl;
          

            if(p1top2 - p2top1 == 0){
               out << "  " << "The battle between " << p1 << " and " << p2 << " is a tie." << endl;
            } else if(p1top2 - p2top1 > 0){
                out << "  " << "In the battle between " << p1 << " and " << p2 << ", " << p1 << " wins!" << endl;
            } else if(p1top2 - p2top1 < 0){
                out << "  " << "In the battle between " << p1 << " and " << p2 << ", " << p2 << " wins!" << endl;

            }
            out << endl;
        }



        out << endl;
    }

Pokemon.clear();
Move.clear();
Effect.clear();
inEffect.clear();

out.clear();
in.clear();
cout.clear();
if (!CONSOLE) {
    delete &out;
}

return 0;
      

}

