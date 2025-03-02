#include "mylib.h"

string get_filepath(){
    string username = getlogin();
    if (username.empty()) {
        cerr << "Ошибка: не удалось получить имя пользователя!" << endl;
    }
    return "/home/" + username + "/.todoconfig";
}

int rewrite_note(int id, string new_note){
    id--;
    string filePath = get_filepath();
    ifstream rf(filePath);
    if (!rf.is_open()) {
        cerr << "Ошибка открытия файла для чтения!" << endl;
        return -1;
    }

    vector<string> lines;
    string line;
    while (getline(rf, line)) {
        lines.push_back(line);
    }
    rf.close();

    if (id < 0 || id >= lines.size()) {
        cerr << "Некорректный ID заметки!" << endl;
        return -1;
    }

    ofstream wf(filePath);
    if (!wf.is_open()) {
        cerr << "Ошибка открытия файла для записи!" << endl;
        return -1;
    }

    for (size_t i = 0; i < lines.size(); ++i) {
        if (i != id) 
            wf << lines[i] << endl;

        else
            wf << new_note;
    }
    wf.close();
    return 0;
}

int add(string note, bool rewrite) {

    string filePath = get_filepath();
    ofstream wf;

    if (rewrite == true)
        wf.open(filePath); 
    else
        wf.open(filePath, ios::app);

    if (!wf.is_open()) {
        cerr << "Ошибка открытия файла для записи!" << endl;
        return -1;
    }

    wf << note << endl;
    wf.close();
    return 0;
}

int remove(int id) {
    if (rewrite_note(id, "") != 0){
        return -1;
    }
    return 0;
}

int edit(string new_note, int id) {
    if (rewrite_note(id, new_note + "\n") != 0){
        return -1;
    }
    return 0;
}

int list(){
    string filePath = get_filepath();
    ifstream rf(filePath);
    string line;

    int n = 0;
    for (int i = 0; getline(rf, line); i++){
        cout << "[" << i+1 << "] " << line << endl;
        n++;
    }
    if (n==0){
        cout << "No notes" << endl;
    }
    rf.close();
    return 0;

}
