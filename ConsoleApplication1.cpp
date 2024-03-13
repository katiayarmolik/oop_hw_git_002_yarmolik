#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>

using namespace std;

class Student {
private:
    int id;
    string name;
    int age;
    float gpa;
public:
    Student(int id, string name, int age, float gpa) : id(id), name(name), age(age), gpa(gpa) {}

    int getId() const { return id; }
    string getName() const { return name; }
    int getAge() const { return age; }
    float getGpa() const { return gpa; }

    void setName(string name) { this->name = name; }
    void setAge(int age) { this->age = age; }
    void setGpa(float gpa) { this->gpa = gpa; }

    void display() const {
        cout << "ID: " << id << "\n";
        cout << "Ім'я: " << name << "\n";
        cout << "Вік: " << age << "\n";
        cout << "середній бал: " << gpa << "\n";
    }
};
void createStudent(std::vector<Student>& students) {
    int id;
    string name;
    int age;
    float gpa;

    cout << "Введіть ученя ID: ";
    cin >> id;
    cin.ignore();

    cout << "Введіть ім'я студента: ";
    getline(cin, name);

    cout << "Введіть студентський вік: ";
    cin >> age;

    cout << "Введіть середній бал студента: ";
    cin >> gpa;

    students.push_back(Student(id, name, age, gpa));
}

void readStudents(const vector<Student>& students) {
    for (const auto& student : students) {
        student.display();
        cout << "------------------------- " << endl;
    }
}

void updateStudent(vector<Student>& students) {
    int id;
    string name;
    int age;
    float gpa;

    cout << "Введіть ідентифікатор студента для оновлення: ";
    cin >> id;

    for (auto& student : students) {
        if (student.getId() == id) {
            cout << "Введіть нове ім'я студента: ";
            cin.ignore();
            getline(cin, name);
            student.setName(name);

            cout << "Введіть новий студентський вік: ";
            cin >> age;
            student.setAge(age);

            cout << "Введіть новий середній бал студента: ";
            cin >> gpa;
            student.setGpa(gpa);

            cout << "Студент успішно оновлений!" << endl;
            return;
        }
    }

    cout << "Студент не знайдений. " << endl;
}

void deleteStudent(vector<Student>& students) {
    int id;

    cout << "Введіть ідентифікатор студента для видалення: ";
    cin >> id;

    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->getId() == id) {
            students.erase(it);
            cout << "Студента успішно видалено!" << endl;
            return;
        }
    }

    cout << "Студент не знайдений. " << endl;
}
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::vector<Student> students;

    int choice;
    do {
        cout << "\n1.Створити студента " << endl;
        cout << "2. Список учнів " << endl;
        cout << "3. Оновити студента " << endl;
        cout << "4. Видалити студента " << endl;
        cout << "5. Вихід " << endl;
        cout << "Введіть свій вибір: " << endl;
        cin >> choice;

        switch (choice) {
        case 1:
            createStudent(students);
            break;
        case 2:
            readStudents(students);
            break;
        case 3:
            updateStudent(students);
            break;
        case 4:
            deleteStudent(students);
            break;
        case 5:
            cout << "до побачення!" << endl;
            break;
        default:
            cout << "Невірний вибір. Будь ласка спробуйте ще раз." << endl;
        }
    } while (choice != 5);
}
