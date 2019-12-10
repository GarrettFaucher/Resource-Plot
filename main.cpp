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
 * Prompts the user for data graphing choice.
 * Choosing between csv graph or cpu usage
 */
string get_type_choice() {
    cout << "Do you want to graph a csv or show CPU usage?" << endl <<
         "(a) csv" << endl <<
         "(b) cpu usage" << endl <<
         "(c) exit" << endl;
    string option;
    cout << "Select an option: ";
    cin >> option;
    if(option[0] != 'a' && option[0] != 'b' && option[0] != 'c') {
        cin.clear();
        string junk;
        getline(cin, junk);
        cout << "Select an option: ";
        cin >> option;
    }
    if (option[0] == 'a') {
        return "csv";
    } else if (option[0] == 'b') {
        return "cpu";
    } else {
        return "";
    }
}

/*
 * Prompts the user for a filename.
 * Allow the user to enter nothing to use the default file data.csv
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
 * Prompts the user for one of the options from the menu.
 * Validates input: makes sure the user enters exactly one character
 * and that it is one of the four valid options.
 * If it isn't valid, keep prompting for input until a valid option
 * is entered.
 */
char get_plot_choice() {
    cout << "Choose a graph option:" << endl <<
         "(a) bar" << endl <<
         "(b) line" << endl <<
         "(c) scatter" << endl <<
         "(d) exit" << endl;
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

/*
 * Prompts the user for one of the options from the menu.
 * Validates input: makes sure the user enters exactly one character
 * and that it is one of the four valid options.
 * If it isn't valid, keep prompting for input until a valid option
 * is entered.
 */
string get_color_choice() {
    cout << "Choose a graph option:" << endl <<
         "(a) red" << endl <<
         "(b) green" << endl <<
         "(c) blue" << endl <<
         "(d) exit" << endl;
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
    if (option[0] == 'a') {
        return "red";
    } else if (option[0] == 'b') {
        return "green";
    } else if (option[0] == 'c') {
        return "blue";
    } else {
        return "black";
    }
}

int main() {
    cout << "Welcome to the data grapher!" << endl;
    string typeChoice = get_type_choice();
    if (typeChoice == "csv") {
        string filename = get_filename();
        cout << "Using file " << filename << "." << endl;
        char plotChoice = get_plot_choice();
        string colorChoice = " " + get_color_choice();
        cout << "Processing. Go to Python program when it opens. May take a few seconds." << endl;
        string command;
        switch (plotChoice) {
            // Use command-line arguments to pass the filename and plot to the Python file
            case 'a': command = python + " ../graph.py " + filename + " bar" + colorChoice;
                system(command.c_str());
                break;
            case 'b': command = python + " ../graph.py " + filename + " line" + colorChoice;
                system(command.c_str());
                break;
            case 'c': command = python + " ../graph.py " + filename + " scatter" + colorChoice;
                system(command.c_str());
                break;
        }
    } else {
        string colorChoice = " " + get_color_choice();
        cout << "Processing. Go to Python program when it opens. May take a few seconds." << endl;
        string command;
        command = python + " ../graph.py" + " cpu" + " line" + colorChoice;
        system(command.c_str());
    }


    return 0;
}