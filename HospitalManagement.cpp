#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include<iomanip>

using namespace std;

struct tm* timeinfo;


class PatientInfo {
public:
    char name[20];
    char address[100];
    char contact[15];
    char age[5];
    char sex[20];
    char blood_gp[10];
    char disease_past[50];
    char id[15];
};

class DiagnosisInfo {
public:
    char symptom[500];
    char diagnosis[500];
    char medicine[500];
    char addmission[30];
    char ward[15];
};

class Appointment {
public:
    char date[15];
    char time[10];
    char doctor[30];
};
class HospitalManagementSystem{
    public:
        static void displayHospitalInfo();
        static void addPatientRecord();
        static void addDiagnosisInfo();
        static void editPatientRecord();
        static void deletePatientRecord();
        static void displayFullHistory();
        static void scheduleAppointment();
        static void viewLatestAppointment();
        static void waitForEnter();
        static void clearScreen();
};

bool login();

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

void HospitalManagementSystem::displayHospitalInfo() {
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



void HospitalManagementSystem::addPatientRecord() {
    ofstream pat_file;
    char fname[20];
    cout << "\n\n\n\nEnter the patient's file name : ";
    cin.ignore();

    cin.getline(fname, sizeof(fname));

    ifstream fileCheck(fname);
    if(fileCheck){
        cout << "\nError: A file with the name " << fname << " already exists. Choose a different file name.\n";
        fileCheck.close();
        return;
    }
    pat_file.open(fname);
    if (!fname) {
        cout << "\nError while opening the file\n";
        return;
    } else {
        PatientInfo patient;

        cout << "\n**********\n";
        pat_file << "\n**********\n\n";  //fn1353 st
        cout << "\nName : ";
        pat_file << "Name : ";
        cin.getline(patient.name, sizeof(patient.name));
        pat_file << patient.name << "\n";
        cout << "\nAddress : ";
        pat_file << "Address : ";
        cin.getline(patient.address, sizeof(patient.address));
        pat_file << patient.address << "\n";
        cout << "\nContact Number : ";
        pat_file << "Contact Number : ";
        cin.getline(patient.contact, sizeof(patient.contact));
        pat_file << patient.contact << "\n";
        cout << "\nAge : ";
        pat_file << "Age : ";
        cin.getline(patient.age, sizeof(patient.age));
        pat_file << patient.age << "\n";
        cout << "\nSex : ";
        pat_file << "Sex : ";
        cin.getline(patient.sex, sizeof(patient.sex));
        pat_file << patient.sex << "\n";
        cout << "\nBlood Group : ";
        pat_file << "Blood Group : ";
        cin.getline(patient.blood_gp,sizeof(patient.blood_gp));
        pat_file << patient.blood_gp << "\n";
        cout << "\nAny Major disease suffered earlier : ";
        pat_file << "Any Major disease suffered earlier : ";
        cin.getline(patient.disease_past, sizeof(patient.disease_past));
        pat_file << patient.disease_past << "\n";
        cout << "\nPatient ID : ";
        pat_file << "Patient ID : ";
        cin.getline(patient.id, sizeof(patient.id));
        pat_file << patient.id << "\n";
        cout << "\n**********\n";
        pat_file << "\n**********\n\n";
        cout << "\nInformation Saved Successfully\n";
    }
    waitForEnter();
    clearScreen();
}

void HospitalManagementSystem::editPatientRecord() {
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
        
        PatientInfo updatedInfo;

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
        cin.getline(updatedInfo.id, sizeof(updatedInfo.id));
        pat_file << updatedInfo.id << "\n";

        cout << "\nPatient record updated successfully.\n";
        pat_file.close();
    }

    waitForEnter();
    clearScreen();
}

void HospitalManagementSystem::addDiagnosisInfo() {
    fstream pat_file;
    char fname[20];
    cout << "\n\nEnter the patient's file name to be opened : ";
    cin.ignore();

    cin.getline(fname, sizeof(fname));
    system("cls");
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
        DiagnosisInfo add;
        
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

        pat_file << "\n*********\n";
        cout << "\n\n" << add.ward << " ward is allotted Successfully\n";
        pat_file.close();
        cout << "\n\n";
        waitForEnter();
        clearScreen();
    }
}


void HospitalManagementSystem::displayFullHistory() {
    fstream pat_file;
    char fname[20];
    cout << "\n\nEnter the patient's file name to be opened : ";
    cin.ignore();
    cin.getline(fname, sizeof(fname));
    system("cls");
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

void HospitalManagementSystem::deletePatientRecord() {
    char id[15];
    cout << "\nEnter the File name to delete: ";
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
void HospitalManagementSystem::scheduleAppointment() {
    fstream pat_file;
    char fname[20];

    cout << "\nEnter the patient's file name to schedule an appointment: ";
    cin.ignore();
    cin.getline(fname, sizeof(fname));

    pat_file.open(fname, ios::in);
    if (!pat_file) {
        cout << "\nPatient record not found.\n";
    } else {
        cout << "\n\n\n\n\t\t\t\t............................. Scheduling Appointment for " << fname << " ................................\n\n\n\n";
        string info;
        while (pat_file.good()) {
            getline(pat_file, info);
            cout << info << "\n";
        }
        cout << "\n";
        pat_file.close();
        pat_file.open(fname, ios::out | ios::app);

        cout << "\nEnter the appointment details:\n";
        struct appointment {
            char date[15];
            char time[10];
            char doctor[30];
        };

        appointment apt;

        cout << "\nAppointment Date (dd/mm/yyyy): ";
        pat_file << "Appointment Date : ";
        cin.getline(apt.date, sizeof(apt.date));
        pat_file << apt.date << "\n";

        cout << "\nAppointment Time (hh:mm AM/PM): ";
        pat_file << "Appointment Time : ";
        cin.getline(apt.time, sizeof(apt.time));
        pat_file << apt.time << "\n";

        cout << "\nAssigned Doctor: ";
        pat_file << "Assigned Doctor : ";
        cin.getline(apt.doctor, sizeof(apt.doctor));
        pat_file << apt.doctor << "\n";

        cout << "\nAppointment scheduled successfully.\n";
        pat_file.close();
    }

    waitForEnter();
    clearScreen();
}
void HospitalManagementSystem::viewLatestAppointment() {
    ifstream pat_file;
    char fname[20];

    cout << "\nEnter the patient's file name to view the latest appointment: ";
    cin.ignore();
    cin.getline(fname, sizeof(fname));

    pat_file.open(fname, ios::in);
    if (!pat_file) {
        cout << "\nPatient record not found.\n";
    } else {
        cout << "\n\n\n\n\t\t\t\t............................. Latest Appointment for " << fname << " ............................\n\n\n\n";
        string info;
        string latestAppointment_d;
        string latestAppointment_t;

        while (pat_file.good()) {
            getline(pat_file, info);
            if (info.find("Appointment Date") != string::npos) {
                latestAppointment_d = info;
            }
            if(info.find("Appointment Time") != string::npos){
                latestAppointment_t = info;
            }
        }

        cout << latestAppointment_d << "\n";
        cout << latestAppointment_t << "\n";
        pat_file.close();
    }

    waitForEnter();
    clearScreen();
}

void HospitalManagementSystem::waitForEnter() {
    cout << "\n\n\t\t\t\t\t\t\t\tPress Enter to continue...";
    cin.ignore();
    cin.get();
}

void HospitalManagementSystem::clearScreen() {
    system("clear");
}
    
int main(){
    char fname[20];
    time_t rawtime;
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    re:
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "\t\t\t\t\t@@ ____________________________________________________________________________________|@@\n";
    cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout << "\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout << "\t\t\t\t\t@@|                                  WELCOME TO                                        |@@\n";
    cout << "\t\t\t\t\t@@|                                                                                    |@@\n";
    cout << "\t\t\t\t\t@@|                           HOSPITAL MANAGEMENT SYSTEM                               |@@\n";
    cout << "\t\t\t\t\t@@|                                                                                    |@@\n";
    cout << "\t\t\t\t\t@@|                                                                                    |@@\n";
    cout << "\t\t\t\t\t@@|                                                                                    |@@\n";
    cout << "\t\t\t\t\t@@|                                                                                    |@@\n";
    cout << "\t\t\t\t\t@@|                                                                                    |@@\n";
    cout << "\t\t\t\t\t@@|                                                                                    |@@\n";
    cout << "\t\t\t\t\t@@|____________________________________________________________________________________|@@\n";
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
        cout << "\t\t\t\t\t\t _________________________________________________________________|\n";
        cout << "\t\t\t\t\t\t|                                           	                   |\n";
        cout << "\t\t\t\t\t\t|             1  >> Add New Patient Record                        |\n";
        cout << "\t\t\t\t\t\t|             2  >> Edit Patient Record                           |\n";
        cout << "\t\t\t\t\t\t|             3  >> Add Diagnosis Information                     |\n";
        cout << "\t\t\t\t\t\t|             4  >> Delete Patient Record                         |\n";
        cout << "\t\t\t\t\t\t|             5  >> Full History of the Patient                   |\n";
        cout << "\t\t\t\t\t\t|             6  >> Information About the Hospital                |\n";
        cout << "\t\t\t\t\t\t|             7  >> Schedule appointment                          |\n";
        cout << "\t\t\t\t\t\t|             8  >> View Latest Appointment                       |\n";
        cout << "\t\t\t\t\t\t|             9  >> Exit the Program                              |\n";
        cout << "\t\t\t\t\t\t|_________________________________________________________________|\n\n";
        a:
        cout << "\t\t\t\t\t\tEnter your choice: ";
        cin >> i;
        if (i > 9 || i < 1) {
            cout << "\n\n\t\t\t\t\t\tInvalid Choice\n";
            cout << "\t\t\t\t\t\tTry again...........\n\n";
            goto a;
        }

        system("clear");

        switch (i) {
            case 1:
                HospitalManagementSystem::addPatientRecord();
                break;
            case 2:
                HospitalManagementSystem::editPatientRecord();
                break;
            case 3:
                HospitalManagementSystem::addDiagnosisInfo();
                break;
            case 4:
                HospitalManagementSystem::deletePatientRecord();
                break;
            case 5:
                HospitalManagementSystem::displayFullHistory();
                break;
            case 6:
                HospitalManagementSystem::displayHospitalInfo();
                break;
            case 7:
                HospitalManagementSystem::scheduleAppointment();
                break;
            case 8:
                HospitalManagementSystem::viewLatestAppointment();
                break;
            case 9:
                cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
                cout << "\t\t\t\t\t@@ _______________________________________________________________________________________|@@\n";
                cout << "\t\t\t\t\t@@|                                           		                                     |@@\n";
                cout << "\t\t\t\t\t@@|                                           		                                     |@@\n";
                cout << "\t\t\t\t\t@@|                                           		                                     |@@\n";
                cout << "\t\t\t\t\t@@|                                           		                                     |@@\n";
                cout << "\t\t\t\t\t@@|                                           		                                     |@@\n";
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
                break;
            default:
                cout << "\n\n\t\t\t\t\t\tInvalid Choice\n";
                cout << "\t\t\t\t\t\tTry again...........\n\n";
        }

        if (i == 9) {
            break;
        }
    }
    return 0;
}
