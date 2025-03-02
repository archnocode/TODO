#include "mylib.h"
#define arg1 string(argv[1])
#define arg2 string(argv[2])

using namespace std;

string doc[] {
    "add (or -a) <note>                       --- add note",
    "remove (or -r) <id of note>              --- delete note",
    "list (or -l)                             --- all notes"
};

int main(int argc, char* argv[]) {
    if (argc > 2) {
        if (arg1== "add" || arg1 == "-a") {
            string note;

            for (int i = 2; i < argc; i++){
                note += string(argv[i]);
                note += " ";
            }
            if (add(note, false) != 0) 
                cout << "Error while adding note" << endl;
        }



        else if (arg1 == "remove" || arg1 == "-r") {
            int id = stoi(argv[2]);
            if (remove(id) != 0) 
                cout << "Error while removing note" << endl;
        }



        else {
            cout << "Unknown command!" << endl;
        }



    } else if (argc == 2) {
        if (arg1 == "list" || arg1== "-l"){
            if (list() != 0) 
                cout << "Error while listing notes" << endl;
        }
    }


    else {
        cout << "COMMANDS" << endl;
        for (string doca : doc)
            cout << doca << endl;
    }


    return 0;
}


