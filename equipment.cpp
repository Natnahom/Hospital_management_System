//Class for equipment
class Equipment
{
    string name;
    int quantity;
    string use;
    int price;
public:
    void setData(string n, int q, string u, int p){
        name = n;
        quantity = q;
        use = u;
        price = p;
    }
    void getData(){
        cout << "Name: "<<name<<endl;
        cout << "Quantity: "<<quantity<<endl;
        cout << "Use: "<<use<<endl;
        cout << "Total Price: "<<price<<endl;
    }
};