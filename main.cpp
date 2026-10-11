#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

// ============================================================
// DATA STRUCTURES
// ============================================================

struct Student {
    int id;
    string name;
    string registrationNo;
    string course;
    string username;
    string password;
};

struct Lecturer {
    int id;
    string name;
    string department;
    string username;
    string password;
};

struct Unit {
    string code;
    string name;
    int lecturerID;
};

struct Registration {
    int studentID;
    string unitCode;
    string semester;
};

struct Mark {
    int studentID;
    string unitCode;
    double assignment;
    double cat;
    double exam;
    double total;
};

// ============================================================
// GLOBAL DATA
// ============================================================

vector<Student> students;
vector<Lecturer> lecturers;
vector<Unit> units;
vector<Registration> registrations;
vector<Mark> marks;

// ============================================================
// UTILITY FUNCTIONS
// ============================================================

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void pauseScreen() {
    cout << "\nPress ENTER to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int findStudent(int id) {
    for (int i = 0; i < students.size(); i++) {
        if (students[i].id == id)
            return i;
    }
    return -1;
}

int findLecturer(int id) {
    for (int i = 0; i < lecturers.size(); i++) {
        if (lecturers[i].id == id)
            return i;
    }
    return -1;
}

int findUnit(string code) {
    for (int i = 0; i < units.size(); i++) {
        if (units[i].code == code)
            return i;
    }
    return -1;
}

// ============================================================
// FILE SAVING
// ============================================================

void saveStudents() {
    ofstream file("students.txt");

    for (const auto& s : students) {
        file << s.id << "|"
             << s.name << "|"
             << s.registrationNo << "|"
             << s.course << "|"
             << s.username << "|"
             << s.password << "\n";
    }

    file.close();
}

void saveLecturers() {
    ofstream file("lecturers.txt");

    for (const auto& l : lecturers) {
        file << l.id << "|"
             << l.name << "|"
             << l.department << "|"
             << l.username << "|"
             << l.password << "\n";
    }

    file.close();
}

void saveUnits() {
    ofstream file("units.txt");

    for (const auto& u : units) {
        file << u.code << "|"
             << u.name << "|"
             << u.lecturerID << "\n";
    }

    file.close();
}

void saveRegistrations() {
    ofstream file("registrations.txt");

    for (const auto& r : registrations) {
        file << r.studentID << "|"
             << r.unitCode << "|"
             << r.semester << "\n";
    }

    file.close();
}

void saveMarks() {
    ofstream file("marks.txt");

    for (const auto& m : marks) {
        file << m.studentID << "|"
             << m.unitCode << "|"
             << m.assignment << "|"
             << m.cat << "|"
             << m.exam << "|"
             << m.total << "\n";
    }

    file.close();
}

// ============================================================
// FILE LOADING
// ============================================================

void loadStudents() {
    ifstream file("students.txt");
    string line;

    while (getline(file, line)) {
        if (line.empty())
            continue;

        stringstream ss(line);
        string temp;
        Student s;

        getline(ss, temp, '|');
        s.id = stoi(temp);

        getline(ss, s.name, '|');
        getline(ss, s.registrationNo, '|');
        getline(ss, s.course, '|');
        getline(ss, s.username, '|');
        getline(ss, s.password);

        students.push_back(s);
    }

    file.close();
}

void loadLecturers() {
    ifstream file("lecturers.txt");
    string line;

    while (getline(file, line)) {
        if (line.empty())
            continue;

        stringstream ss(line);
        string temp;
        Lecturer l;

        getline(ss, temp, '|');
        l.id = stoi(temp);

        getline(ss, l.name, '|');
        getline(ss, l.department, '|');
        getline(ss, l.username, '|');
        getline(ss, l.password);

        lecturers.push_back(l);
    }

    file.close();
}

void loadUnits() {
    ifstream file("units.txt");
    string line;

    while (getline(file, line)) {
        if (line.empty())
            continue;

        stringstream ss(line);
        string temp;
        Unit u;

        getline(ss, u.code, '|');
        getline(ss, u.name, '|');

        getline(ss, temp);
        u.lecturerID = stoi(temp);

        units.push_back(u);
    }

    file.close();
}

void loadRegistrations() {
    ifstream file("registrations.txt");
    string line;

    while (getline(file, line)) {
        if (line.empty())
            continue;

        stringstream ss(line);
        string temp;
        Registration r;

        getline(ss, temp, '|');
        r.studentID = stoi(temp);

        getline(ss, r.unitCode, '|');
        getline(ss, r.semester);

        registrations.push_back(r);
    }

    file.close();
}

void loadMarks() {
    ifstream file("marks.txt");
    string line;

    while (getline(file, line)) {
        if (line.empty())
            continue;

        stringstream ss(line);
        string temp;
        Mark m;

        getline(ss, temp, '|');
        m.studentID = stoi(temp);

        getline(ss, m.unitCode, '|');

        getline(ss, temp, '|');
        m.assignment = stod(temp);

        getline(ss, temp, '|');
        m.cat = stod(temp);

        getline(ss, temp, '|');
        m.exam = stod(temp);

        getline(ss, temp);
        m.total = stod(temp);

        marks.push_back(m);
    }

    file.close();
}

// ============================================================
// DEFAULT DATA
// ============================================================

void createDefaultData() {

    if (students.empty()) {
        Student s1{
            1001,
            "John Kamau",
            "DIT/01/2024",
            "Diploma in Information Technology",
            "student",
            "1234"
        };

        students.push_back(s1);
    }

    if (lecturers.empty()) {
        Lecturer l1{
            2001,
            "Dr. Peter Mwangi",
            "Information Technology",
            "lecturer",
            "1234"
        };

        lecturers.push_back(l1);
    }

    if (units.empty()) {
        Unit u1{
            "DIT0307",
            "Advanced Operating Systems",
            2001
        };

        units.push_back(u1);
    }

    saveStudents();
    saveLecturers();
    saveUnits();
}

// ============================================================
// ADMINISTRATOR FUNCTIONS
// ============================================================

void addStudent() {

    Student s;

    cout << "\n===== ADD STUDENT =====\n";

    cout << "Student ID: ";
    cin >> s.id;
    clearInput();

    if (findStudent(s.id) != -1) {
        cout << "Student already exists.\n";
        return;
    }

    cout << "Name: ";
    getline(cin, s.name);

    cout << "Registration Number: ";
    getline(cin, s.registrationNo);

    cout << "Course: ";
    getline(cin, s.course);

    cout << "Username: ";
    getline(cin, s.username);

    cout << "Password: ";
    getline(cin, s.password);

    students.push_back(s);
    saveStudents();

    cout << "\nStudent added successfully.\n";
}

void addLecturer() {

    Lecturer l;

    cout << "\n===== ADD LECTURER =====\n";

    cout << "Lecturer ID: ";
    cin >> l.id;
    clearInput();

    if (findLecturer(l.id) != -1) {
        cout << "Lecturer already exists.\n";
        return;
    }

    cout << "Name: ";
    getline(cin, l.name);

    cout << "Department: ";
    getline(cin, l.department);

    cout << "Username: ";
    getline(cin, l.username);

    cout << "Password: ";
    getline(cin, l.password);

    lecturers.push_back(l);
    saveLecturers();

    cout << "\nLecturer added successfully.\n";
}

void addUnit() {

    Unit u;

    cout << "\n===== ADD UNIT =====\n";

    cout << "Unit Code: ";
    cin >> u.code;
    clearInput();

    if (findUnit(u.code) != -1) {
        cout << "Unit already exists.\n";
        return;
    }

    cout << "Unit Name: ";
    getline(cin, u.name);

    cout << "Lecturer ID: ";
    cin >> u.lecturerID;

    if (findLecturer(u.lecturerID) == -1) {
        cout << "Lecturer does not exist.\n";
        return;
    }

    units.push_back(u);
    saveUnits();

    cout << "\nUnit added successfully.\n";
}

void viewStudents() {

    cout << "\n========== STUDENTS ==========\n";

    if (students.empty()) {
        cout << "No students found.\n";
        return;
    }

    for (const auto& s : students) {
        cout << "\nID: " << s.id
             << "\nName: " << s.name
             << "\nRegistration: " << s.registrationNo
             << "\nCourse: " << s.course << "\n";
    }
}

void viewLecturers() {

    cout << "\n========== LECTURERS ==========\n";

    for (const auto& l : lecturers) {
        cout << "\nID: " << l.id
             << "\nName: " << l.name
             << "\nDepartment: " << l.department << "\n";
    }
}

void viewUnits() {

    cout << "\n========== UNITS ==========\n";

    for (const auto& u : units) {

        cout << "\nCode: " << u.code
             << "\nName: " << u.name
             << "\nLecturer ID: " << u.lecturerID
             << "\n";
    }
}

// ============================================================
// STUDENT FUNCTIONS
// ============================================================

void registerUnit(int studentID) {

    string code;

    cout << "\n===== UNIT REGISTRATION =====\n";

    viewUnits();

    cout << "\nEnter unit code: ";
    cin >> code;

    if (findUnit(code) == -1) {
        cout << "Unit does not exist.\n";
        return;
    }

    for (const auto& r : registrations) {

        if (r.studentID == studentID &&
            r.unitCode == code) {

            cout << "You have already registered this unit.\n";
            return;
        }
    }

    Registration r;

    r.studentID = studentID;
    r.unitCode = code;

    cout << "Enter semester: ";
    cin >> r.semester;

    registrations.push_back(r);

    saveRegistrations();

    cout << "\nUnit registered successfully.\n";
    cout << "The unit is now available in the LMS.\n";
}

void viewRegisteredUnits(int studentID) {

    cout << "\n===== REGISTERED UNITS =====\n";

    bool found = false;

    for (const auto& r : registrations) {

        if (r.studentID == studentID) {

            int index = findUnit(r.unitCode);

            if (index != -1) {

                cout << "\nUnit Code: "
                     << units[index].code;

                cout << "\nUnit Name: "
                     << units[index].name;

                cout << "\nSemester: "
                     << r.semester << "\n";

                found = true;
            }
        }
    }

    if (!found)
        cout << "No registered units found.\n";
}

void viewStudentMarks(int studentID) {

    cout << "\n========== MY MARKS ==========\n";

    bool found = false;

    for (const auto& m : marks) {

        if (m.studentID == studentID) {

            cout << "\nUnit: " << m.unitCode
                 << "\nAssignment: " << m.assignment
                 << "\nCAT: " << m.cat
                 << "\nExam: " << m.exam
                 << "\nTotal: " << m.total
                 << "\n";

            found = true;
        }
    }

    if (!found)
        cout << "No marks available.\n";
}

void studentProfile(int studentID) {

    int index = findStudent(studentID);

    if (index == -1)
        return;

    Student& s = students[index];

    cout << "\n========== STUDENT PROFILE ==========\n";

    cout << "Student ID: " << s.id << "\n";
    cout << "Name: " << s.name << "\n";
    cout << "Registration: " << s.registrationNo << "\n";
    cout << "Course: " << s.course << "\n";
}

// ============================================================
// LMS FUNCTIONS
// ============================================================

void viewLMSUnits(int studentID) {

    cout << "\n========== LMS ==========\n";

    bool found = false;

    for (const auto& r : registrations) {

        if (r.studentID == studentID) {

            int index = findUnit(r.unitCode);

            if (index != -1) {

                cout << "\n"
                     << units[index].code
                     << " - "
                     << units[index].name;

                cout << "\nLecturer ID: "
                     << units[index].lecturerID
                     << "\n";

                found = true;
            }
        }
    }

    if (!found)
        cout << "No units are currently available in the LMS.\n";
}

void uploadNotes(int lecturerID) {

    string code;
    string note;

    cout << "\n===== UPLOAD NOTES =====\n";

    cout << "Enter unit code: ";
    cin >> code;
    clearInput();

    int index = findUnit(code);

    if (index == -1) {
        cout << "Unit not found.\n";
        return;
    }

    if (units[index].lecturerID != lecturerID) {
        cout << "You are not assigned to this unit.\n";
        return;
    }

    cout << "Enter note title: ";
    getline(cin, note);

    ofstream file("notes.txt", ios::app);

    file << code << "|" << note << "\n";

    file.close();

    cout << "Notes uploaded successfully.\n";
}

void createAssignment(int lecturerID) {

    string code;
    string title;

    cout << "\n===== CREATE ASSIGNMENT =====\n";

    cout << "Unit code: ";
    cin >> code;
    clearInput();

    int index = findUnit(code);

    if (index == -1 ||
        units[index].lecturerID != lecturerID) {

        cout << "You are not assigned to this unit.\n";
        return;
    }

    cout << "Assignment title: ";
    getline(cin, title);

    ofstream file("assignments.txt", ios::app);

    file << code << "|" << title << "\n";

    file.close();

    cout << "Assignment created successfully.\n";
}

void createCAT(int lecturerID) {

    string code;
    string title;

    cout << "\n===== CREATE CAT =====\n";

    cout << "Unit code: ";
    cin >> code;
    clearInput();

    int index = findUnit(code);

    if (index == -1 ||
        units[index].lecturerID != lecturerID) {

        cout << "You are not assigned to this unit.\n";
        return;
    }

    cout << "CAT title: ";
    getline(cin, title);

    ofstream file("cats.txt", ios::app);

    file << code << "|" << title << "\n";

    file.close();

    cout << "CAT created successfully.\n";
}

// ============================================================
// LECTURER MARKS
// ============================================================

void enterMarks(int lecturerID) {

    string code;
    int studentID;

    cout << "\n========== ENTER MARKS ==========\n";

    cout << "Unit code: ";
    cin >> code;

    int unitIndex = findUnit(code);

    if (unitIndex == -1) {
        cout << "Unit does not exist.\n";
        return;
    }

    if (units[unitIndex].lecturerID != lecturerID) {
        cout << "You are not assigned to this unit.\n";
        return;
    }

    cout << "Student ID: ";
    cin >> studentID;

    if (findStudent(studentID) == -1) {
        cout << "Student does not exist.\n";
        return;
    }

    bool registered = false;

    for (const auto& r : registrations) {

        if (r.studentID == studentID &&
            r.unitCode == code) {

            registered = true;
            break;
        }
    }

    if (!registered) {
        cout << "Student is not registered for this unit.\n";
        return;
    }

    double assignment;
    double cat;
    double exam;

    cout << "Assignment mark (0-20): ";
    cin >> assignment;

    cout << "CAT mark (0-20): ";
    cin >> cat;

    cout << "Exam mark (0-60): ";
    cin >> exam;

    if (assignment < 0 || assignment > 20 ||
        cat < 0 || cat > 20 ||
        exam < 0 || exam > 60) {

        cout << "\nInvalid marks.\n";
        cout << "Assignment must be 0-20.\n";
        cout << "CAT must be 0-20.\n";
        cout << "Exam must be 0-60.\n";

        return;
    }

    double total = assignment + cat + exam;

    bool updated = false;

    for (auto& m : marks) {

        if (m.studentID == studentID &&
            m.unitCode == code) {

            m.assignment = assignment;
            m.cat = cat;
            m.exam = exam;
            m.total = total;

            updated = true;
            break;
        }
    }

    if (!updated) {

        Mark m;

        m.studentID = studentID;
        m.unitCode = code;
        m.assignment = assignment;
        m.cat = cat;
        m.exam = exam;
        m.total = total;

        marks.push_back(m);
    }

    saveMarks();

    cout << "\nMarks successfully saved.\n";
    cout << "Total Mark: " << total << "/100\n";
    cout << "The updated mark is now available through the Student Portal.\n";
}

void lecturerStudents(int lecturerID) {

    cout << "\n========== REGISTERED STUDENTS ==========\n";

    for (const auto& u : units) {

        if (u.lecturerID == lecturerID) {

            cout << "\nUNIT: "
                 << u.code
                 << " - "
                 << u.name << "\n";

            for (const auto& r : registrations) {

                if (r.unitCode == u.code) {

                    int index = findStudent(r.studentID);

                    if (index != -1) {

                        cout << "  "
                             << students[index].id
                             << " - "
                             << students[index].name
                             << "\n";
                    }
                }
            }
        }
    }
}

// ============================================================
// STUDENT LOGIN
// ============================================================

int studentLogin() {

    string username;
    string password;

    cout << "\n========== STUDENT LOGIN ==========\n";

    cout << "Username: ";
    cin >> username;

    cout << "Password: ";
    cin >> password;

    for (const auto& s : students) {

        if (s.username == username &&
            s.password == password) {

            cout << "\nLogin successful.\n";

            return s.id;
        }
    }

    cout << "\nInvalid username or password.\n";

    return -1;
}

// ============================================================
// LECTURER LOGIN
// ============================================================

int lecturerLogin() {

    string username;
    string password;

    cout << "\n========== LECTURER LOGIN ==========\n";

    cout << "Username: ";
    cin >> username;

    cout << "Password: ";
    cin >> password;

    for (const auto& l : lecturers) {

        if (l.username == username &&
            l.password == password) {

            cout << "\nLogin successful.\n";

            return l.id;
        }
    }

    cout << "\nInvalid username or password.\n";

    return -1;
}

// ============================================================
// STUDENT MENU
// ============================================================

void studentMenu(int studentID) {

    int choice;

    do {

        cout << "\n========================================\n";
        cout << "           STUDENT PORTAL\n";
        cout << "========================================\n";

        cout << "1. View Profile\n";
        cout << "2. Register Unit\n";
        cout << "3. View Registered Units\n";
        cout << "4. Access LMS\
