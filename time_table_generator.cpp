#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
const int no_of_days = 5;
const int no_of_class = 8;
const int no_of_subject = 8;
class timetable
{
private:
  string subjects[no_of_subject] = {"Analytical Skills for Engineers", "Coding Skill-1", "Oops with cpp", "Data structures-2", "Digital Electronics", "Python", "Co-circular activities", "comunity services and social responsibility"};
  string sub_codes[no_of_subject]= {"AEC-105", "CSE-201", "CES-202", "CSE-203", "CSE-204", "CSE-205", "VAC-103", "VAC-104"};
  string weekdays[5] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
  string timetable[no_of_days][no_of_class][no_of_subject];

public:
  void input()
  {
    cout << "Enter 8 subject names and codes" << endl;
    for (int i = 0; i < no_of_subject; i++)
    {
      cout << "Subject " << i + 1 << endl;
      cout << "Enter name: ";
      getline(cin, subjects[i]);
      cout << "Enter Code: ";
      getline(cin, sub_codes[i]);
    }
  }
  void initialize()
  {
    for (int i = 0; i < no_of_days; i++)
    {
      for (int j = 0; j < no_of_class; j++)
      {
        for (int k = 0; k < no_of_subject; k++)
        {
          timetable[i][j][k] = "No class";
        }
      }
    }
  }
  int index(int dayno, int classno, int subject)
  {
    return (dayno * 13 + classno * 17 + subject * 19) % no_of_subject;
  }
  void create_tt()
  {
    int m;
    for (int i = 0; i < no_of_days; i++)
    {
      for (int j = 0; j < no_of_class; j++)
      {
        for (int k = 0; k < no_of_subject; k++)
        {
          m = index(i, j, k);
          timetable[i][j][k] = sub_codes[m];
        }
      }
    }
  }
  void display_timetables()
  {
    const int column_width = 10;

    cout << "Class-wise Timetable for 5 weekdays:\n\n";

    for (int j = 0; j < no_of_class; j++)
    {
      cout << "Class " << (j + 1) << ":\n";
      cout << "|" << setw(column_width + 1) << " Day|";
      cout << "\n";
      for (int i = 0; i < no_of_days; i++)
      {
        cout << "|" << setw(column_width) << weekdays[i] << "|";
        for (int k = 0; k < no_of_subject; k++)
        {
          if (k == 4)
            cout << " Lunch Break |";
          if (k == 2 || k == 6)
            cout << " Break | ";
          cout << setw(column_width) << timetable[i][j][k] << "|";
        }
        cout << "\n";
      }

      cout << "\n";
    }
    return;
  }
  void display_subjects()
  {
    cout << endl
         << "SUBJECT CODES: " << endl;
    for (int i = 0; i < no_of_subject; i++)
    {
      cout << sub_codes[i] << "-->" << subjects[i] << endl;
    }
    return;
  }
  void get_subject()
  {
    int class_no, day_no, period_no;
    cout << "Enter class number (1-" << no_of_class << "): ";
    cin>>class_no;
    while(class_no < 1 || class_no > no_of_class)
    {
        cout << "Invalid class number. Please enter a number between 1 and " << no_of_class << "." << endl;
        cout << "Enter class number (1-" << no_of_class << "): ";
        cin>>class_no;
    }
    cout << "Enter day number (1-" << no_of_days << "): ";
    cin>>day_no;
    while(day_no < 1 || day_no > no_of_days)
    {
        cout << "Invalid class number. Please enter a number between 1 and " << no_of_days << "." << endl;
        cout << "Enter day number (1-" << no_of_days << "): ";
        cin>>day_no;
    }
     cout << "Enter period number (1-" << no_of_subject << "): ";
    cin>>period_no;
    while(period_no < 1 || period_no > no_of_subject)
    {
        cout << "Invalid class number. Please enter a number between 1 and " << no_of_subject << "." << endl;
        cout << "Enter peroid number (1-" << no_of_subject << "): ";
        cin>>period_no;
    }
    cout << "Subject at Class " << class_no << ", Day " << weekdays[day_no - 1] << ", Period " << period_no << ": ";
    cout << timetable[day_no - 1][class_no - 1][period_no - 1] << endl;
    return;
  }
};
int main()
{
  timetable T;
  T.initialize();
  int choice = 1;
  cout << "---------------------Timetable generator---------------------" << endl;
  while (choice == 1)
  {
    int ch;
    cout<<"-------------------------------------------------------------"<<endl;
    cout << "1 to enter the input the subject names and subject codes." << endl;
    cout << "2 to display the timetable." << endl;
    cout << "3 to display subject " << endl;
    cout << "4 to get subject at a particular period for a particular class" << endl;
    cout << "5 to exit" << endl;
    cout<<"-------------------------------------------------------------"<<endl;
    cout << "Enter choice: ";
    if (!(cin >> ch))
    {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Invalid input. Please enter a number from 1-7." << endl;
      continue;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    switch (ch)
    {
    case 1:
      T.input();
      break;
    case 2:
      T.create_tt();
      T.display_timetables();
      break;
    case 3:
      T.display_subjects();
      break;
    case 4:
      T.get_subject();
      break;
    case 5:
      choice = 0;
      break;
    default:
      cout << "Please Enter a Valid Input from 1-7 only" << endl;
      break;
    }
  }
  cout << "*************** END OF PROGRAM ***************" << endl;
  cout << "---------------------------------------------" << endl;
  return 0;
}