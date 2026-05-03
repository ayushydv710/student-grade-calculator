#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

char calculateGrade(double percentage) {
    if (percentage >= 90) return 'A';
    if (percentage >= 75) return 'B';
    if (percentage >= 60) return 'C';
    if (percentage >= 40) return 'D';
    return 'F';
}

int readMark(const string& subject) {
    int mark;

    while (true) {
        cout << "Enter marks for " << subject << " (0-100): ";
        cin >> mark;

        if (!cin.fail() && mark >= 0 && mark <= 100) {
            return mark;
        }

        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid marks. Please enter a number between 0 and 100.\n";
    }
}

int main() {
    vector<string> subjects = {"Mathematics", "Physics", "Chemistry", "Programming", "English"};
    int total = 0;

    cout << "Student Grade Calculator\n";
    cout << "------------------------\n";

    for (const string& subject : subjects) {
        total += readMark(subject);
    }

    double percentage = static_cast<double>(total) / subjects.size();
    char grade = calculateGrade(percentage);
    string status = grade == 'F' ? "Fail" : "Pass";

    cout << fixed << setprecision(2);
    cout << "\nResult Summary\n";
    cout << "--------------\n";
    cout << "Total Marks: " << total << " / " << subjects.size() * 100 << "\n";
    cout << "Percentage: " << percentage << "%\n";
    cout << "Grade: " << grade << "\n";
    cout << "Status: " << status << "\n";

    return 0;
}
