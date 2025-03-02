#include "mylib.h"
#define command string(argv[1])
#define arg1 string(argv[2])
#define arg2 string(argv[3])

using namespace std;

string doc[] {
    "add (or -a) <note>                       --- add note",
    "remove (or -r) <id of note>              --- delete note",
    "list (or -l)                             --- all notes",
    "edit (or -e) <id of note> <new note>     --- edit note"
};

int main(int argc, char* argv[]) {
    if (argc > 2) {
        if (command == "add" || command == "-a") {
            string note;

            for (int i = 2; i < argc; i++){
                note += string(argv[i]);
                note += " ";
            }
            if (add(note, false) != 0) 
                cout << "Error while adding note" << endl;
        }



        else if (command == "remove" || command == "-r") {
            int id = stoi(arg1);
            if (remove(id) != 0) 
                cout << "Error while removing note" << endl;
        }

        else if (command == "edit" || command == "-e") {
            int id = stoi(arg1);
            string new_note;

            for (int i = 3; i < argc; i++){
                new_note += string(argv[i]);
                new_note += " ";
            }

            if (edit(new_note, id) != 0) 
                cout << "Error while editing note" << endl;
        }



        else {
            cout << "Unknown command!" << endl;
        }



    } else if (argc == 2) {
        if (command == "list" || command == "-l"){
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


