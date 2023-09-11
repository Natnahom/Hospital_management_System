#include <iostream>
#include <fstream>
using namespace std;
#include "patient.cpp"
#include "equipment.cpp"

int main()
{

    int ask1,ask2, age, patNum, hurt, pain, price=0;
    string assignDr, name, name2, sickness, line;
    char gender;
    ofstream fileOut;
    ifstream fileIn;
    Patient pat;
    Equipment equ;

    cout << "            Welcome to MediCare"<< endl;
    cout << "********************************************"<< endl;
    restart:
    cout << "Enter only the number(0 to exit)"<< endl;
    cout << "1. Employee"<< endl
         << "2. Patient"<< endl
         << "3. EMERGENCY"<< endl;
    cin >> ask1;
    cout << "-----------------------------------------------" << endl;

    if (ask1 == 1){
        again2:
        cout << "PASSCODE(b to back): ";
        cin >> name;
        if (name == "PAA"){
    
            cout << "1. Add a patient"<< endl
                 << "2. Access patient information"<<endl
                 << "3. Medical inventory"<<endl;
            cin >> patNum;
            cout << "-----------------------------------------------" << endl;

            if (patNum == 1){
                cout << "Instead of a space between words please enter \"_\" \n";
                cout << "Patient Name: ";
                cin >> name2;
                cout << "Patient Age: ";
                cin >> age;
                cout << "Gender: ";
                cin >> gender;
                cout << "Patient's Assigned Doctor/Nurse: ";
                cin >> assignDr;
                cout << "Patients condition: ";
                cin >> sickness;
                cout << "-----------------------------------------------" << endl;
                pat.setData2(name2, age, gender,assignDr,sickness);
                pat.getData2();
                cout << "Patitent Added!!"<<endl;
                cout << "-----------------------------------------------" << endl;

                fileOut.open("Patients.txt", ios::app);
                fileOut <<"Patient Name: "<< name2 << "\n";
                fileOut <<"Patient Age: "<< age << "\n";
                fileOut <<"Gender: "<< gender << "\n";
                fileOut <<"Patient's Assigned Doctor/Nurse: "<< assignDr << "\n";
                fileOut <<"Patients condition: "<< sickness << "\n";
                fileOut << "-----------------------------------------------" << endl;
                fileOut.close();
                goto restart;

            }
            else if (patNum == 2){

                fileIn.open("Patients.txt");
                
                while (getline(fileIn, line)){
                    cout << line << endl;
                }
                fileIn.close();
            goto restart;
            }
            
            else if (patNum == 3){
                cout << "1. Add a laboratory equipment"<< endl
                     << "2. Access laboratory equipment information"<<endl;
                cin >> patNum;

                if (patNum ==1){
                    cout << "Instead of a space between words please enter \"_\" \n";
                    cout << "Equipment Name: ";
                    cin >> name;
                    cout << "Equipment Quantity: ";
                    cin >> ask1;
                    cout << "Equipment Use: ";
                    cin >> name2;
                    cout << "Equipment Price: ";
                    cin >> price;
                    price *= ask1;
                    cout << "-----------------------------------------------" << endl;
                    equ.setData(name,ask1, name2, price);
                    equ.getData();
                    cout << "Equipment Added!!"<<endl;
                    cout << "-----------------------------------------------" << endl;
                
                    fileOut.open("Equipments.txt", ios::app);
                    fileOut <<"Name: "<< name << "\n";
                    fileOut <<"Quantity: "<< ask1 << "\n";
                    fileOut <<"Use: "<< name2 << "\n";
                    fileOut <<"Total Price: "<< price << "\n";
                    fileOut << "-----------------------------------------------" << endl;
                    fileOut.close();
                    goto restart;
                }
            
                else if (patNum == 2){
                fileIn.open("Equipments.txt");

                while (getline(fileIn,line)){
                    cout << line << endl;
                }
                fileIn.close();
                goto restart;
                }
            cout << "-----------------------------------------------" << endl;
            }
            
        }
        else if (name == "b" || name == "B"){
            goto restart;
        }
        else{
            cout << "WRONG PASSCODE!!!"<< endl;
            goto again2;
        }
        
    }
    else if (ask1 == 2){
        
        cout << "1. Access some doctors information "<<endl
             << "2. Calculate medicine price"<<endl
             << "3. Calculate medical laboratory test price"<<endl
             << "4. Continue"<<endl;
        cin >> ask2;
        cout << "-----------------------------------------------" << endl;
        
        if (ask2 == 1){
            fileIn.open("Employee.txt");
            
            while (getline(fileIn,line)){
                cout << line << endl;
            }
            fileIn.close();
            goto restart;
        }

        else if (ask2==2){
            cout << "Medicines" << endl
                 << "1. Analgesics/Pain Relievers" << endl
                 << "2. Antipyretics/Fever Reducers" << endl
                 << "3. Aspirin" << endl
                 << "4. Cough Suppressants/Expectorants" << endl
                 << "5. Decongestants" << endl
                 << "6. Antidiabetic Medications" << endl
                 << "7. Ibuprofen (Advil, Motrin)" << endl
                 << "8. Parastamole" << endl
                 << "9. Dextromethorphan (Robitussin)" << endl
                 << "10. Hydrocortisone cream (Cortizone-10)" << endl
                 << "11. Bacitracin (Neosporin)" << endl
                 << "12. Miconazole (Monistat)" << endl
                 << "13. Tums (Calcium carbonate)" << endl
                 << "14. Melatonin (Sleep aid)" << endl
                 << "15. Multivitamins" << endl;

            again4:
            cout << "Enter the number of the medicine that is on your prescription(0 to exit)"<< endl;
            cin >> ask1;

            if (ask1 >= 1 && ask1 < 5){
                price += 50;
                goto again4;
            }
            else if (ask1 >= 5 && ask1 < 10){
                price += 100;
                goto again4;
            }
            else if (ask1 >= 10 && ask1 <= 15){
                price += 200;
                goto again4;
            }
            else if (ask1 == 0){
                cout << "Medicine Price: " << price << endl;
                cout << "-----------------------------------------------" << endl;
                goto restart;
            }

        }

        else if (ask2 == 3){
            cout << "Medical Laboratory" << endl
                 << "1. MRI" << endl
                 << "2. X-Ray" << endl
                 << "3. Urine tests" << endl
                 << "4. Fecal tests" << endl
                 << "5. Blood tests" << endl;
            again3:
            cout << "Enter the number of the Lab test that is on their prescription(0 to exit)"<< endl;
            cin >> ask1;

            if (ask1 == 1){
                cout << "Enter the number of body parts" << endl;
                cin >> ask2;
            }
            if (ask1 == 1){
                price += 3000 * ask2;
                goto again3;
            }
            else if (ask1 == 2){
                price += 2000;
                goto again3;
            }
            else if (ask1 == 3){
                price += 200;
                goto again3;
            }
            else if (ask1 == 4){
                price += 200;
                goto again3;
            }
            else if (ask1 == 5){
                price += 300;
                goto again3;
            }
            else if (ask1 == 0){
                cout << "Medical Laboratory Price: " << price << endl;
                cout << "-----------------------------------------------" << endl;
                goto restart;
            }
        }
        else if (ask2 == 4){
            cout << "Which part of their body hurts? (Enter the number): "<< endl;  
            cout << "1. Head parts"<< endl
                 << "2. Hand and shoulder parts "<< endl
                 << "3. Chest parts "<< endl
                 << "4. Abdomen parts "<< endl
                 << "5. Lower waist parts "<< endl
                 << "6. Leg parts "<< endl;
            cin >> hurt;
            cout << "What level of pain do they feel from 1 - 10? (1-Low and 10-High): "<< endl;
            cin >> pain;
            if (hurt == 1 && pain > 5){
                assignDr = "Dr. Yilikal Tadele";
            }
            else if (hurt == 1 && pain <= 5){
                assignDr = "Nurse Hermela Nebiyu";
            }
            else if (hurt == 2 && pain > 5){
                assignDr = "Dr. Nigist Haile";
            }
            else if (hurt == 2 && pain <= 5){
                assignDr = "Nurse Chaltu Gemechu";
            }
            else if (hurt == 3 && pain > 5){
                assignDr = "Dr. Biruk Tasew";
            }
            else if (hurt == 3 && pain <= 5){
                assignDr = "Nurse Lideta Ayele";
            }
            else if (hurt == 4 && pain > 5){
                assignDr = "Dr. Dagim Tesfaye";
            }
            else if (hurt == 4 && pain <= 5){
                assignDr = "Nurse Lideta Ayele";
            }
            else if ((hurt == 5 && pain > 5) || (hurt == 6 && pain > 5)){
                assignDr = "Dr. Eleni Asfaw";
            }
            else if (hurt == 5 && pain <= 5 || (hurt == 6 && pain <= 5)){
                assignDr = "Nurse Nahily Asarf";
            }

            cout << "Instead of a space between words please enter \"_\" \n";
            cout << "Name: ";
            cin >> name2;
            cout << "Age: ";
            cin >> age;
            cout << "Gender: ";
            cin >> gender;
            cout << "Ticket Price: ";
            cin >> price;
            cout << "-----------------------------------------------" << endl;
            pat.setData(name2, age, gender, assignDr);
            pat.getData();
            cout << "Ticket Price: "<< price << endl;
            cout << "\nGo to the door that has the name of the doctor that is assigned to you." << endl;
            cout << "-----------------------------------------------" << endl;
            goto restart;
        }
    }

    else if (ask1 == 3){
        cout << "1. Add an emergency patient"<< endl
             << "2. Access emergency patient information"<<endl;
        cin >> patNum;
        if (patNum == 1){
            int lines = 0;
            string line;
            fileIn.open("EMERGENCY.txt");
            
            while (getline(fileIn, line)){
                lines++;
            }
            fileIn.close();
            cout << "\nNo of taken emergency beds: " << lines/6 << "/10"<< endl;

            if ((lines/6) >= 10){
                cout << "Emergency beds are fully occupied!!" << endl;
                goto restart;
            }

            cout << "Instead of a space between words please enter \"_\" \n";
                cout << "Patient Name: ";
                cin >> name2;
                cout << "Patient Age: ";
                cin >> age;
                cout << "Gender: ";
                cin >> gender;
                cout << "Patient's Assigned Doctor/Nurse: ";
                cin >> assignDr;
                cout << "Patients condition: ";
                cin >> sickness;
                cout << "-----------------------------------------------" << endl;
                pat.setData2(name2, age, gender,assignDr,sickness);
                pat.getData2();
                cout << "Emergency Patitent Added!!"<<endl;
                cout << "-----------------------------------------------" << endl;
                fileOut.open("EMERGENCY.txt", ios::app);
                fileOut <<"Patient Name: "<< name2 << "\n";
                fileOut <<"Patient Age: "<< age << "\n";
                fileOut <<"Gender: "<< gender << "\n";
                fileOut <<"Patient's Assigned Doctor/Nurse: "<< assignDr << "\n";
                fileOut <<"Patients condition: "<< sickness << "\n";
                fileOut << "-----------------------------------------------" << endl;
                fileOut.close();
                goto restart;
        }
        else if (patNum == 2){
            fileIn.open("EMERGENCY.txt");

            while (getline(fileIn,line)){
                cout << line << endl;
            }

            fileIn.close();
            goto restart;
        }
    }
    return 0;
}