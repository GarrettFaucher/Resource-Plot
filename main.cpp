#include <fstream>
#include <iostream>
using namespace std;

// Different OSs use different CLI commands to run Python
#ifdef _WIN32
const string python = "python";
#else
const string python = "python3";
#endif

/*
 * Prompts the user for a filename.
 * Allow the user to enter nothing to use the default pic (autumn).
 * If the file has extension jpg, jpeg, jpe, or png
 * and it exists in the project folder, return it.
 * Otherwise, return the default pic filename.
 */
string get_filename() {
    cout << "Use a filename (y/n): ";
    char answer;
    cin >> answer;
    if (answer == 'y') {
        cout << "Filename: ";
        string filename;
        cin >> filename;
        return filename;
    } else {
        return "data.csv";
    }
}

/*
 * Prints the main menu of options:
 * (a) flip, (b) mirror, (c) invert, or (d) exit
 */
void print_menu() {
    cout << "Choose a graph option:" << endl <<
         "(a) bar" << endl <<
         "(b) line" << endl <<
         "(c) scatter" << endl <<
         "(d) exit" << endl;
}

/*
 * Prompts the user for one of the options from the menu.
 * Validates input: makes sure the user enters exactly one character
 * and that it is one of the four valid options.
 * If it isn't valid, keep prompting for input until a valid option
 * is entered.
 */
char get_manip_choice() {
    string option;
    cout << "Select an option: ";
    cin >> option;
    if(option[0] != 'a' && option[0] != 'b' && option[0] != 'c' && option[0] != 'd') {
        cin.clear();
        string junk;
        getline(cin, junk);
        cout << "Select an option: ";
        cin >> option;
    }
    return option[0];
}

int main() {
    cout << "Welcome to the data grpaher!" << endl;
    string filename = get_filename();
    cout << "Using file " << filename << "." << endl;
    print_menu();
    char choice = get_manip_choice();
    cout << "Processing. Go to Python program when it opens. May take a few seconds." << endl;
    string command;
    switch (choice) {
        // Use command-line arguments to pass the filename and manip to the Python file
        case 'a': command = python + " ../graph.py " + filename + "bar";
            system(command.c_str());
            break;
        case 'b': command = python + " ../graph.py " + filename + "line";
            system(command.c_str());
            break;
        case 'c': command = python + " ../graph.py " + filename + "scatter";
            system(command.c_str());
            break;
    }

    return 0;
}