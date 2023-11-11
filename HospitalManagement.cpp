#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include<iomanip>

using namespace std;

struct tm* timeinfo;

// Function declarations
bool login();
void displayHospitalInfo();
void addPatientRecord();
void addDiagnosisInfo();
void editPatientRecord();
void deletePatientRecord();
void displayFullHistory();

void waitForEnter() {
    cout << "Press Enter to continue...";
    cin.ignore();
    cin.get();
}

void clearScreen() {
    system("clear"); // For Linux/macOS,     use "cls" for Windows
}


int main() {
    char fname[20];
    time_t rawtime;
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    // Printing the welcome note
    re:
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "\t\t\t\t\t@@ _______________________________________________________________________________________ @@\n";
    cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout << "\t\t\t\t\t@@|                                  WELCOME TO                                           |@@\n";
    cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
    cout << "\t\t\t\t\t@@|                           HOSPITAL MANAGEMENT SYSTEM                                  |@@\n";
    cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
    cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
    cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
    cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
    cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
    cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
    cout << "\t\t\t\t\t@@|_______________________________________________________________________________________|@@\n";
    cout << "\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n\n\t\t\t\t\t";
    cout << "Press Enter to continue...";
    cin.ignore();

    system("clear");

    int i;
    if (!login()) {
        return 0; // exit the program if login fails
    }

    while (true) {
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  HOSPITAL MANAGEMENT SYSTEM \n\n";
        cout << "\n\n\t\t\t\t\t\tPlease,  Choose from the following Options: \n\n";
        cout << "\t\t\t\t\t\t _________________________________________________________________ \n";
        cout << "\t\t\t\t\t\t|                                           	                  |\n";
        cout << "\t\t\t\t\t\t|             1  >> Add New Patient Record                        |\n";
        cout << "\t\t\t\t\t\t|             2  >> Edit Patient Record                           |\n";
        cout << "\t\t\t\t\t\t|             3  >> Add Diagnosis Information                     |\n";
        cout << "\t\t\t\t\t\t|             4  >> Delete Patient Record                         |\n";
        cout << "\t\t\t\t\t\t|             5  >> Full History of the Patient                   |\n";
        cout << "\t\t\t\t\t\t|             6  >> Information About the Hospital                |\n";
        cout << "\t\t\t\t\t\t|             7  >> Exit the Program                              |\n";
        cout << "\t\t\t\t\t\t|_________________________________________________________________|\n\n";
        a:
        cout << "\t\t\t\t\t\tEnter your choice: ";
        cin >> i;
        if (i > 7 || i < 1) {
            cout << "\n\n\t\t\t\t\t\tInvalid Choice\n";
            cout << "\t\t\t\t\t\tTry again...........\n\n";
            goto a;
        }

        system("clear");

        switch (i) {
            case 1:
                addPatientRecord();
                break;
            case 2:
                editPatientRecord();
                break;
            case 3:
                addDiagnosisInfo();
                break;
            case 4:
                deletePatientRecord();
                break;
            case 5:
                displayFullHistory();
                break;
            case 6:
                displayHospitalInfo();
                break;
            case 7:
                cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
                cout << "\t\t\t\t\t@@ _______________________________________________________________________________________ @@\n";
                cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
                cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
                cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
                cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
                cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
                cout << "\t\t\t\t\t@@|                               THANK YOU FOR USING                                     |@@\n";
                cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
                cout << "\t\t\t\t\t@@|                            HOSPITAL MANAGEMENT SYSTEM                                 |@@\n";
                cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
                cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
                cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
                cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
                cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
                cout << "\t\t\t\t\t@@|                                                                                       |@@\n";
                cout << "\t\t\t\t\t@@|_______________________________________________________________________________________|@@\n";
                cout << "\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n\n\t\t\t\t\t";
                cout << "Press Enter to continue...";
                cin.ignore();
  // Added this line to wait for user input
                break;
            default:
                cout << "\n\n\t\t\t\t\t\tInvalid Choice\n";
                cout << "\t\t\t\t\t\tTry again...........\n\n";
        }

        if (i == 7) {
            break;
        }
    }

    return 0;
}

bool login() {
    string pass = "";
    string input;

    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  HOSPITAL MANAGEMENT SYSTEM \n\n";
    cout << "\t\t\t\t\t\t\t\t------------------------------";
    cout << "\n\t\t\t\t\t\t\t\t\t     LOGIN \n";
    cout << "\t\t\t\t\t\t\t\t------------------------------\n\n";
    cout << "\t\t\t\t\t\t\t\tEnter Password: ";

    cin >> input;

    if (input == "pass") {
        cout << "\n\n\t\t\t\t\t\t\t\tAccess Granted! \n";
        return true;
    } else {
        cout << "\n\n\t\t\t\t\t\t\t\tAccess Aborted...\n\t\t\t\t\t\t\t\tPlease Try Again\n\n";
        return false;
    }
}

void displayHospitalInfo() {
    ifstream file;
    file.open("hos.txt");
    if (!file) {
        cout << "\nError while opening the file\n";
        return;
    } else {
        cout << "\n\n\n\n\n\n\n\t\t\t\t\t   ...........................Information about the Hospital.............................\n\n";
        string line;
        if (file.is_open()) {
            while (getline(file, line)) {
                cout << line << "\n\t\t";
            }
            file.close();
        } else {
            cout << "Unable to open the file\n";
        }
        cout << "\n\n\t\t";
        waitForEnter();
        clearScreen();
    }
}



void addPatientRecord() {
    ofstream pat_file;
    char fname[20];
    cout << "\n\n\n\nEnter the patient's file name : ";
    cin.ignore();

    cin.getline(fname, sizeof(fname));
    pat_file.open(fname);
    if (!fname) {
        cout << "\nError while opening the file\n";
        return;
    } else {
        struct patient_info {
            char name[20];
            char address[100];
            char contact[15];
            char age[5];
            char sex[20];
            char blood_gp[10];
            char disease_past[50];
            char id[15];
        };

        patient_info ak;
        cout << "\n********************************************************************\n";
        pat_file << "\n********************************************************************\n\n";  //fn1353 st
        cout << "\nName : ";
        pat_file << "Name : ";
        cin.getline(ak.name, sizeof(ak.name));
        pat_file << ak.name << "\n";
        cout << "\nAddress : ";
        pat_file << "Address : ";
        cin.getline(ak.address, sizeof(ak.address));
        pat_file << ak.address << "\n";
        cout << "\nContact Number : ";
        pat_file << "Contact Number : ";
        cin.getline(ak.contact, sizeof(ak.contact));
        pat_file << ak.contact << "\n";
        cout << "\nAge : ";
        pat_file << "Age : ";
        cin.getline(ak.age, sizeof(ak.age));
        pat_file << ak.age << "\n";
        cout << "\nSex : ";
        pat_file << "Sex : ";
        cin.getline(ak.sex, sizeof(ak.sex));
        pat_file << ak.sex << "\n";
        cout << "\nBlood Group : ";
        pat_file << "Blood Group : ";
        cin.getline(ak.blood_gp,sizeof(ak.blood_gp));
        pat_file << ak.blood_gp << "\n";
        cout << "\nAny Major disease suffered earlier : ";
        pat_file << "Any Major disease suffered earlier : ";
        cin.getline(ak.disease_past, sizeof(ak.disease_past));
        pat_file << ak.disease_past << "\n";
        cout << "\nPatient ID : ";
        pat_file << "Patient ID : ";
        cin.getline(ak.id, sizeof(ak.id));
        pat_file << ak.id << "\n";
        cout << "\n********************************************************************\n";
        pat_file << "\n********************************************************************\n\n";
        cout << "\nInformation Saved Successfully\n";
    }
    waitForEnter();
    clearScreen();
}

void editPatientRecord() {
    fstream pat_file;
    char id[15];

    cout << "\nEnter the patient's file name to edit: ";
    cin.ignore();
    cin.getline(id, sizeof(id));

    pat_file.open(id, ios::in);
    if (!pat_file) {
        cout << "\nPatient record not found.\n";
    } else {
        cout << "\n\n\n\n\t\t\t\t............................. Editing Patient Record for ID: " << id << " ................................\n\n\n\n";
        string info;
        while (pat_file.good()) {
            getline(pat_file, info);
            cout << info << "\n";
        }
        cout << "\n";
        pat_file.close();
        pat_file.open(id, ios::out | ios::app);

        cout << "\nEnter the updated patient information:\n";
        struct patient_info {
            char name[20];
            char address[100];
            char contact[15];
            char age[5];
            char sex[20];
            char blood_gp[10];
            char disease_past[50];
            char newId[15];
        };

        patient_info updatedInfo;

        cout << "\nUpdated Name : ";
        pat_file << "Updated Name : ";
        cin.getline(updatedInfo.name, sizeof(updatedInfo.name));
        pat_file << updatedInfo.name << "\n";

        cout << "\nUpdated Address : ";
        pat_file << "Updated Address : ";
        cin.getline(updatedInfo.address, sizeof(updatedInfo.address));
        pat_file << updatedInfo.address << "\n";

        cout << "\nUpdated Contact Number : ";
        pat_file << "Updated Contact Number : ";
        cin.getline(updatedInfo.contact, sizeof(updatedInfo.contact));
        pat_file << updatedInfo.contact << "\n";

        cout << "\nUpdated Age : ";
        pat_file << "Updated Age : ";
        cin.getline(updatedInfo.age, sizeof(updatedInfo.age));
        pat_file << updatedInfo.age << "\n";

        cout << "\nUpdated Sex : ";
        pat_file << "Updated Sex : ";
        cin.getline(updatedInfo.sex, sizeof(updatedInfo.sex));
        pat_file << updatedInfo.sex << "\n";

        cout << "\nUpdated Blood Group : ";
        pat_file << "Updated Blood Group : ";
        cin.getline(updatedInfo.blood_gp, sizeof(updatedInfo.blood_gp));
        pat_file << updatedInfo.blood_gp << "\n";

        cout << "\nUpdated Disease Past : ";
        pat_file << "Updated Disease Past : ";
        cin.getline(updatedInfo.disease_past, sizeof(updatedInfo.disease_past));
        pat_file << updatedInfo.disease_past << "\n";

        cout << "\nEnter the updated Patient ID : ";
        pat_file << "Updated Patient ID : ";
        cin.getline(updatedInfo.newId, sizeof(updatedInfo.newId));
        pat_file << updatedInfo.newId << "\n";

        cout << "\nPatient record updated successfully.\n";
        pat_file.close();
    }

    waitForEnter();
    clearScreen();
}

void addDiagnosisInfo() {
    fstream pat_file;
    char fname[20];
    cout << "\n\nEnter the patient's file name to be opened : ";
    cin.ignore();

    cin.getline(fname, sizeof(fname));
    system("clear");
    pat_file.open(fname, ios::in);
    if (!pat_file) {
        cout << "\nError while opening the file\n";
        return;
    } else {
        cout << "\n\n\n\n\t\t\t\t........................................ Information about " << fname << " ........................................\n\n\n\n";
        string info;
        while (pat_file.good()) {
            getline(pat_file, info);
            cout << info << "\n";
        }
        cout << "\n";
        pat_file.close();
        pat_file.open(fname, ios::out | ios::app);
        cout << "\n";
        cout << "Adding more information in patient's file................on : " << asctime(timeinfo) << endl;
        pat_file << "\nDescription of " << asctime(timeinfo) << "\n";
        struct app {
            char symptom[500];
            char diagnosis[500];
            char medicine[500];
            char addmission[30];
            char ward[15];
        };
        app add;
        
        cout << "\nSymptoms : ";
        pat_file << "Symptoms : ";
        cin.getline(add.symptom, sizeof(add.symptom));
        pat_file << add.symptom << "\n";

        cout << "\nDiagnosis : ";
        pat_file << "Diagnosis : ";
        cin.getline(add.diagnosis, sizeof(add.diagnosis));
        pat_file << add.diagnosis << "\n";

        cout << "\nMedicines : ";
        pat_file << "Medicines : ";
        cin.getline(add.medicine, sizeof(add.medicine));
        pat_file << add.medicine << "\n";

        cout << "\nAddmission Required? : ";
        pat_file << "Addmission Required? : ";
        cin.getline(add.addmission, sizeof(add.addmission));
        pat_file << add.addmission << "\n";

        cout << "\nType of ward : ";
        pat_file << "Type of ward : ";
        cin.getline(add.ward, sizeof(add.ward));
        pat_file << add.ward << "\n";

        pat_file << "\n*************************************************************************\n";
        cout << "\n\n" << add.ward << " ward is allotted Successfully\n";
        pat_file.close();
        cout << "\n\n";
        waitForEnter();
        clearScreen();
    }
}


void displayFullHistory() {
    fstream pat_file;
    char fname[20];
    cout << "\n\nEnter the patient's file name to be opened : ";
    cin.ignore();
    cin.getline(fname, sizeof(fname));
    system("clear");
    pat_file.open(fname, ios::in);
    if (!pat_file) {
        cout << "\nError while opening the file\n";
        return;
    } else {
        cout << "\n\n\n\n\t\t\t\t........................................ Full Medical History of " << fname << " ........................................\n\n\n\n";
        string info;
        while (pat_file.good()) {
            getline(pat_file, info);
            cout << info << "\n";
        }
        cout << "\n";
    }
    waitForEnter();
    clearScreen();
}

void deletePatientRecord() {
    char id[15];
    cout << "\nEnter the patient's ID to delete: ";
    cin.ignore();
    cin.getline(id, sizeof(id));

    if (remove(id) != 0) {
        cout << "\nError deleting patient record.\n";
    } else {
        cout << "\nPatient record deleted successfully.\n";
    }

    waitForEnter();
    clearScreen();
}