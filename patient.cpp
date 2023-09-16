//Class that is used for taking patient information
class Patient
{
    string name;
    int age;
    char gender;
    string assignDr;
    string sickness;
public:
    void setData(string n, int a, char g,string assi){
        name = n;
        age = a;
        gender = g;
        assignDr = assi;
    }
    void setData2(string n, int a, char g, string assi, string s){
        name = n;
        age = a;
        gender = g;
        assignDr = assi;
        sickness = s;
    }
    void getData(){
        cout << "Name: "<<name<<endl;
        cout << "Age: "<<age<<endl;
        cout << "Gender: "<<gender<<endl;
        cout << "Assigned Doctor/Nurse: "<<assignDr<<endl;
    }
    void getData2(){
        cout << "Name: "<<name<<endl;
        cout << "Age: "<<age<<endl;
        cout << "Gender: "<<gender<<endl;
        cout << "Assigned Doctor/Nurse: "<<assignDr<<endl;
        cout << "Patient condition: "<<sickness<<endl;
    }
};