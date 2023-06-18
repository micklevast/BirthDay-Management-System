// Anna Siddiqi
// asa467
// 301555182

#include "a4_birthdaylib.hpp"
#include "a4_birthdayBST.hpp"
#include <fstream>
#include<string>
#include <iostream>


void add_birthday(BirthdayBST* bst) {
    Birthday *birthday = new Birthday;
    cout << "Enter year: ";
    cin >> birthday->year;
    cout << "Enter month (1-12): ";
    cin >> birthday->month;
    cout << "Enter day (1-31): ";
    cin >> birthday->day;
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, birthday->name);
    cout << "Enter known for: ";
    getline(cin, birthday->knownFor);

    if (bst->findNodeByYMDN(birthday->year, birthday->month, birthday->day, birthday->name) == nullptr) {
        bst->insertNode(birthday);
        cout << "Birthday added." << endl;
    } else {
        cout << "An entry with the same birthday and name already exists. Nothing added." << endl;
    }
}



void list_birthdays( BirthdayBST* bst) {
    bst->inOrderPrint(cout);
}

void lookup_birthday(BirthdayBST* bst) {
    int month, day;
    cout << "Enter month (1-12): ";
    cin >> month;
    cout << "Enter day (1-31): ";
    cin >> day;
    bool found = false;
    if(bst->findNodeByMD(month, day) == nullptr)
    {
        cout<<"No birthdays found for this month and day."<<endl;
        return;
    }
    else 
    {
        bst->printAllNodeWithMatchingMD(month, day, cout);
    }
}

void save_entries(BirthdayBST *bst, string filename) {
    if(filename.size() == 0)
    {
        cout<<"No birthday file loaded. Please load a file first.";
        return;
    }
    ofstream outfile(filename);

    // traverse the bst and save the entries on file
    bst->inOrderPrint(outfile);

    outfile.close();
    cout << "Saved " << bst->getSize() << " entries." << endl;
}


void load_entries(BirthdayBST * root, const string &filename)
{
    ifstream infile(filename);
    if (!infile)
    {
        cout << "File not found." << endl;
        return;
    }
    // entries.clear();
    int year, month, day;
    string dob, name, known_for;
    while (getline(infile, dob, '-'))
    {
        // cout<<dob<<endl;
        // Extract year
        year = stoi(dob);

        // Extract month
        getline(infile, dob, '-');
        month = stoi(dob);

        // Extract day
        getline(infile, dob, '\n');
        day = stoi(dob);

        // Extract name and known_for
        getline(infile, name, '\n');
        getline(infile, known_for, '\n');

        Birthday* b =  create_Birthday(year, month, day, name, known_for);
        root->insertNode(b);
        
        string lineseparator;
        getline(infile, lineseparator, '\n');
    }
    infile.close();
    cout << "Loaded " << root->getSize() << " entries." << endl;
}

// function to terminate the program – thank the user and end the program.
void quit_program() {
    cout << "Thank you for using the Birthday program." << endl;
    // terminate the program
    exit(0);
}

int main()
{
    // vector<Birthday> entries;
    BirthdayBST *head = new BirthdayBST();
    cout<<"====================================================== \n";
    cout<<"==============Famous Birthdays Lookup System ========= \n";
    cout<<" ======================= Anna =================== \n";
    cout<<" =====================301555182=============== \n";
    cout<<" ================= anna_siddiqi@sfu.ca============== \n";
    cout<<" ====================================================\n";

    FILE *file = NULL;

    int user_choice;
    string given_file = "";

    cout<<"Please pick a number between 1-6, then click enter (choose 1 first)\n";

    cout<<"1) to load a birthday file.\n";
    cout<<"2) to list birthdays sorted by Month-day \n";
    cout<<"3) to add birthday \n";
    cout<<"4) to look up a birthday \n";
    cout<<"5) to save entries \n";
    cout<<"6) to terminate the program \n";

    // scanf("%d", &user_choice);
    cin>>user_choice;

    do
    {
        switch (user_choice)
        {

        case 1:
            // ask for user input
            cout<<"Option: 1 Enter the full name of the birthday file (with extension):";

            // obtain user input
           cin>>given_file;

            // file = fopen(given_file, "r");
                load_entries(head,  given_file);
                cout<<"====================================================\n";
            break;

            case 2:
                list_birthdays(head);
                break;

            case 3:
                add_birthday( head);
                cout<<"====================================================\n";
                break;
            case 4:
                lookup_birthday( head);
                cout<<"====================================================\n";
                break;
            case 5:
                cout<<"Enter the name of the file you want to save to: ";
                cin>>given_file;
                save_entries(head,  given_file);
                cout<<"====================================================\n";
                break;
            case 6:
                quit_program();
                break;
            

        default:
            cout<<"Invalid input. Please choose a number between 1 and 6.\n";
            break;

            

        } // switch statement

        cout<<"Please pick a number between 1-6, then click enter"<<endl;
        // scanf("%d", &user_choice);
        cin>>user_choice;
    } while (true);

    return 0;
}
