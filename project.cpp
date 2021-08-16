#include<iostream>
#include<iomanip>
#include <vector>
#include<algorithm>
using namespace std;

void PrintMenu()    //Function to print menu
{
    cout<<endl;
    cout<<"The functions provided and their choices in this database are:\n";
    cout<<"\t1: Enter data of a Ship Docking\n";
    cout<<"\t2: Notification of a Ship Leaving the dock\n";
    cout<<"\t3: Search the details of a Ship\n";
    cout<<"\t4: Get details of all the ships in the dock\n";
    cout<<"\t5: Modify details of a Ship currently at dock\n";
    cout<<"\tOther values: Exit category\n";
    cout<<"Enter your choice:\n";
}
// Base class called Ship
//template <typename X>
class Ship
{
    protected:
            string shipName, captain;
            int yearbuilt;
            //static int count;
    public:
    // Ship() : shipName("no_name"), yearbuilt(0) {count++;}
    Ship(string shipName, string captName, int yearbuilt){
        this -> shipName = shipName;
        this -> captain = captName;
        this -> yearbuilt = yearbuilt;
        //count++;
    }
    virtual void ShipDocking() = 0; //Absolute virtual function
    virtual void ShipLeaving() = 0; //Absolute virtual function
};

//int Ship::count = 0;

// Derived class called CruiseShip
class CruiseShip : public Ship
{
    private:
        int passengerCount; // in numbers
    public:
    CruiseShip():Ship("", "", 0)
    {
        // shipName = "";
        // captain = "";
        // yearbuilt = "";
        passengerCount = 0;
        //count++;
    }
    CruiseShip(string Name, string captName, int year, int passenger):Ship(Name, captName, year)
    {
        // this -> shipName = shipName;
        // this -> captain = captName;
        // this -> yearbuilt = yearbuilt;
        this -> passengerCount = passengerCount;
        //count++;
    }
    void ShipDocking()
    {
        cout<<"Enter the details of the Cruise Ship Docking:\n";
        cin>>shipName>>captain>>yearbuilt>>passengerCount;
    }    
    void ShipLeaving()
    {
        cout<<"The Cruise Ship leaving the dock is:\n";
        cout<<"Ship Name: "<<shipName<<endl;
        cout<<"Captain Name: "<<captain<<endl;
        cout<<"Built Year: "<<yearbuilt<<endl;
        cout<<"Passenger Count: "<<passengerCount<<endl;
    }
    void getdata()
    {
        cout<<"Ship Name: "<<shipName<<endl;
        cout<<"Captain Name: "<<captain<<endl;
        cout<<"Built Year: "<<yearbuilt<<endl;
        cout<<"Passenger Count: "<<passengerCount<<endl;
    }
    string getCapt()
    {
        return captain;
    }
};

// Derived class called CargoShip
template <typename X>
class CargoShip : public Ship
{
    private:
        X cargoCapacity; // in kgs, can be either int or double
    public:
    CargoShip():Ship("", "", 0) 
    {
        cargoCapacity = 0;
        //count++;
    }
    CargoShip(string Name, string captName, int year, X cargoCapacity):Ship(Name, captName, year)
    {
        this -> shipName = shipName;
        this -> captain = captName;
        this -> yearbuilt = yearbuilt;
        this -> cargoCapacity = cargoCapacity;
        //count++;
    }
    void ShipDocking()
    {
        cout<<"Enter the details of the Cargo Ship Docking:\n";
        cin>>shipName>>captain>>yearbuilt>>cargoCapacity;
    }
    void ShipLeaving()
    {
        cout<<"The Cargo Ship leaving the dock is:\n";
        cout<<"Ship Name: "<<shipName<<endl;
        cout<<"Captain Name: "<<captain<<endl;
        cout<<"Built Year: "<<yearbuilt<<endl;
        cout<<"Cargo Capacity: "<<cargoCapacity<<endl;
    }
    void getdata()
    {
        cout<<"Ship Name: "<<shipName<<endl;
        cout<<"Captain Name: "<<captain<<endl;
        cout<<"Built Year: "<<yearbuilt<<endl;
        cout<<"Cargo Capacity: "<<cargoCapacity<<endl;
    }
    string getCapt()
    {
        return captain;
    }
};

// Derived class called WarShip
template <typename X>
class WarShip : public Ship{
    X weaponCapacity; // in kgs, can be either int or double
public:
    // Warship(string Name = "", string captain = "", int year = 0, int cap = 0):Ship(Name, captain, year)
    // {
    //     weaponCapacity = cap;
    //     //count++;
    // }
    WarShip():Ship("", "", 0)
    {
        // shipName = "";
        // captain = "";
        // yearbuilt = 0;
        weaponCapacity = 0;
    }
    WarShip(string shipName, string captName, int yearbuilt, X weaponCapacity)
    {
        this -> shipName = shipName;
        this -> captain = captName;
        this -> yearbuilt = yearbuilt;
        this -> weaponCapacity = weaponCapacity;
        //count++;
    }
    void ShipDocking()
    {
        cout<<"Enter the details of the War Ship Docking:\n";
        cin>>shipName>>captain>>yearbuilt>>weaponCapacity;
    }
    void ShipLeaving()
    {
        cout<<"The War Ship leaving the dock is:\n";
        cout<<"Ship Name: "<<shipName<<endl;
        cout<<"Captain Name: "<<captain<<endl;
        cout<<"Built Year: "<<yearbuilt<<endl;
        cout<<"Weapon Capacity: "<<weaponCapacity<<endl;
    }
    void getdata()
    {
        cout<<"Ship Name: "<<shipName<<endl;
        cout<<"Captain Name: "<<captain<<endl;
        cout<<"Built Year: "<<yearbuilt<<endl;
        cout<<"Weapon Capacity: "<<weaponCapacity<<endl;
    }
    string getCapt()
    {
        return captain;
    }
};

int main()
{
    CruiseShip c;
    CargoShip<int> car;
    WarShip<int> w;
    vector<CruiseShip> cruise;
    vector< CargoShip<int> > cargo;
    vector< WarShip<int> > war;
    int choice, type, i;
    string ch, capt;
    vector<CruiseShip>::iterator cr;
    vector<CargoShip<int> >::iterator ca;
    vector<WarShip<int> >::iterator wa;
    cout<<"\t\tWelcome to RMS Docks:\n";
    do
    {
        cout<<"Enter the Type of Ship to be operated on:\n";
        cout<<"Enter 1 for CruiseShip, 2 for CargoShip, 3 for WarShip:\n";
        cin>>type;
        switch (type)   
        {
        case 1:
            cout<<"You have Selected CruiseShip type:\n";
            do
            {
                PrintMenu();
                cin>>choice;
                switch (choice)
                {
                case 1:
                    c.ShipDocking();
                    cruise.push_back(c);
                    cout << endl;
                    break;      
                case 2:
                    if(cruise.empty())
                    {
                        cout<<"Error! No CruiseShips in dock.\n";
                        break;
                    }
                    cout<<"Enter the captain of the ship leaving the dock:\n";
                    cin>>capt;
                    for(cr = cruise.begin();cr<=cruise.end();cr++)
                    {
                        if(cr->getCapt() == capt)
                        {
                            cr->ShipLeaving();
                            cruise.erase(cr);
                            break;
                        }
                        else if(cr == cruise.end())
                        {
                            cout<<"Error! No captain found\n";
                            break;
                        }
                    }
                    // cout << endl;
                    break;
                case 3:
                    if(cruise.empty())
                    {
                        cout<<"Error! No CruiseShips in dock.\n";
                        break;
                    }
                    cout<<"Enter the captain of the ship whose details are required:\n";
                    cin>>capt;
                    //vector<CruiseShip>::iterator it;
                    for(cr = cruise.begin();cr<=cruise.end();cr++)
                    {
                        if(cr->getCapt() == capt)
                        {
                            cout<<"The details requested are:\n";
                            cr->getdata();
                            break;
                        }
                        else if(cr == cruise.end())
                        {
                            cout<<"Error! No captain found\n";
                            break;
                        }
                    }
                    // cout << endl;
                    // break;
                case 4:
                    int i;
                    if(cruise.empty())
                    {
                        cout<<"The dock has no Cruiseships currently.\n";
                        break;
                    }
                    cout<<"The details of all the ships are:\n";
                    for(cr = cruise.begin(), i=1;cr<cruise.end();cr++, i++)
                    {
                        cout<<"The details of Ship "<<i<<":"<<endl;
                        cr->getdata();
                        cout<<endl;
                    }
                    // cout << endl;
                    break;
                case 5:
                    if(cruise.empty())
                    {
                        cout<<"Error! No CruiseShips in dock.\n";
                        break;
                    }
                    cout<<"Enter the captain of the ship whose details are to be changed:\n";
                    cin>>capt;
                    for(cr = cruise.begin();cr<=cruise.end();cr++)
                    {
                        if(cr->getCapt() == capt)
                        {
                            cout<<"The Ship details will be changed:\n";
                            cr->ShipDocking();
                            break;
                        }
                        else if(cr == cruise.end())
                        {
                            cout<<"Error! No captain found\n";
                            break;
                        }
                    }
                    // cout << endl;
                    break;
                }
            }
            while(choice <= 5);
            cout<<"Exiting category.\n" << endl;
            break;
        case 2:
            cout<<"You have Selected CargoShip type:\n";
            //CargoShip<int> car;
            do
            {    
                PrintMenu();
                cin>>choice;
                switch (choice)
                {
                case 1:
                    car.ShipDocking();
                    cargo.push_back(car);
                    cout << endl;
                    break;
                case 2:
                    if(cargo.empty())
                    {
                        cout<<"Error! No Cargoships in dock.\n";
                        break;
                    }
                    cout<<"Enter the captain of the ship leaving the dock:\n";
                    cin>>capt;
                    for(ca = cargo.begin();ca<=cargo.end();ca++)
                    {
                        if(ca->getCapt() == capt)
                        {
                            ca->ShipLeaving();
                            cargo.erase(ca);
                            break;
                        }
                        else if(ca == cargo.end())
                        {
                            cout<<"Error! No captain found\n";
                            break;
                        }
                    }
                    //cout << endl;
                    break;
                case 3:
                    if(cargo.empty())
                    {
                        cout<<"Error! No Cargoships in dock.\n";
                        break;
                    }
                    cout<<"Enter the captain of the ship whose details are required:\n";
                    cin>>capt;
                    //vector<CargoShip>::iterator it;
                    for(ca = cargo.begin();ca<=cargo.end();ca++)
                    {
                        if(ca->getCapt() == capt)
                        {
                            cout<<"The details requested are:\n";
                            ca->getdata();
                            break;
                        }
                        else if(ca == cargo.end())
                        {
                            cout<<"Error! No captain found\n";
                            break;
                        }
                    }
                    //cout << endl;
                    break;
                case 4:
                    if(cargo.empty())
                    {
                        cout<<"The dock has no Cargoships currently.\n";
                        break;
                    }
                    cout<<"The details of all the ships are:\n";
                    for(ca = cargo.begin(), i=1;ca<cargo.end();ca++, i++)
                    {
                        cout<<"The details of Ship "<<i<<":"<<endl;
                        ca->getdata();
                        cout<<endl;
                    }
                    //cout << endl;
                    break;
                case 5:
                    if(cargo.empty())
                    {
                        cout<<"Error! No Cargoships in dock.\n";
                        break;
                    }
                    cout<<"Enter the captain of the ship whose details are to be changed:\n";
                    cin>>capt;
                    for(ca = cargo.begin();ca<=cargo.end();ca++)
                    {
                        if(ca->getCapt() == capt)
                        {
                            cout<<"The Ship details will be changed:\n";
                            ca->ShipDocking();
                            break;
                        }
                        else if(ca == cargo.end())
                        {
                            cout<<"Error! No captain found\n";
                            break;
                        }
                    }
                    //cout << endl;
                    break;
                }
            }
            while(choice <= 5);
            cout<<"Exiting category.\n" << endl;
            break;
        
        case 3:
            cout<<"You have Selected WarShip type:\n";
            //Warship<int> w;
            do
            {    
                PrintMenu();
                cin>>choice;
                switch (choice)
                {
                case 1:
                    w.ShipDocking();
                    war.push_back(w);
                    cout << endl;
                    break;
                case 2:
                    if(war.empty())
                    {
                        cout<<"Error! No Warships in dock.\n";
                        break;
                    }
                    cout<<"Enter the captain of the ship leaving the dock:\n";
                    cin>>capt;
                    for(wa = war.begin();wa<=war.end();wa++)
                    {
                        if(wa->getCapt() == capt)
                        {
                            wa->ShipLeaving();
                            war.erase(wa);
                            break;
                        }
                        else if(wa == war.end())
                        {
                            cout<<"Error! No captain found\n";
                            break;
                        }
                    }
                    //cout << endl;
                    break;
                case 3:
                    if(war.empty())
                    {
                        cout<<"Error! No Warships in dock.\n";
                        break;
                    }
                    cout<<"Enter the captain of the ship whose details are required:\n";
                    cin>>capt;
                    for(wa = war.begin();wa<=war.end();wa++)
                    {
                        if(wa->getCapt() == capt)
                        {
                            cout<<"The details requested are:\n";
                            wa->getdata();
                            break;
                        }
                        else if(wa == war.end())
                        {
                            cout<<"Error! No captain found\n";
                            break;
                        }
                    }
                    //cout << endl;
                    break;
                case 4:
                    if(war.empty())
                    {
                        cout<<"The dock has no Warships currently.\n";
                        break;
                    }
                    cout<<"The details of all the ships are:\n";
                    for(wa = war.begin(), i=1;wa<war.end();wa++, i++)
                    {
                        cout<<"The details of Ship "<<i<<":"<<endl;
                        wa->getdata();
                        cout<<endl;
                    }
                    //cout << endl;
                    break;
                case 5:
                    if(war.empty())
                    {
                        cout<<"Error! No Warships in dock.\n";
                        break;
                    }
                    cout<<"Enter the captain of the ship whose details are to be changed:\n";
                    cin>>capt;
                    for(wa = war.begin();wa<=war.end();wa++)
                    {
                        if(wa->getCapt() == capt)
                        {
                            cout<<"The Ship details will be changed:\n";
                            wa->ShipDocking();
                            break;
                        }
                        else if(wa == war.end())
                        {
                            cout<<"Error! No captain found\n";
                            break;
                        }
                    }
                    //cout << endl;
                    break;
                }
            }
            while(choice <= 5);
            cout<<"Exiting category.\n" << endl;
            break;
        default:
            cout<<"Error! Invalid input\n" << endl;
            break;
        }
        cout<<"Do you want to continue?(Yes/No):\n";
        cin>>ch;
    }while(ch != "No");
    return 0;
}