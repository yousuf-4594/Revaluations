#include "raylib.h"
#include <iostream>
#include <cstring>
#include <string>
#include <string.h>
#include <cstring>
#include <cstdlib>
#include <time.h>
#include <conio.h>
#include <stdio.h>
#include <fstream>
//#include <windows.h>
#include <ctype.h>
#include <iomanip>
#include <cwchar>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <stdexcept>

#include <iostream>

using namespace std;

string convertToString(char*);
void aboutUs();
int mainMenu();
void box();
void FontSize(int, int);
void currentDateAndTime();
void TextColor(int);
void loadingAnimation();
void CursorPosition(int, int);
void generateReport(string);

//class User;
//class Customer;
//
//


class User
{
protected:
    //int accountNumber;
    char name[40];
    int age;
    char gender;
    char email[30];
    char password[20];
    //virtual int generateAccountNumber() = 0;

public:
    virtual void createNewAccount(char[40], int, char, char[30], char[20]) = 0;
    char* getName();
    //int getAccountNumber();
    char getGender();
    int getAge();
    char* getEmail();
    virtual void storeData() = 0;
    void readData();
    virtual bool login(char[30], char[20]) = 0;
};

class Customer : public User
{
private:
    //int generateAccountNumber();

public:
    void createNewAccount(char[20], int, char, char[30], char[20]);
    bool login(char[30], char[20]);
    void storeData();
    void addData();
    void buy(int);
    void sendEmailToAll(string, string);
    void sendEmail(string, string, string);
};

Customer bhai;






class Property {
    // Node for CDLL
public:
    //---------------------------------------------
    long long int propertyID;
    long int locationID;
    string pageUrl;
    string propertyType;
    long long int price;
    string priceType;
    string location;
    string city;
    string province;
    string locality;
    long double latitude;
    long double longitude;
    int baths;
    string area;
    float areaMarla;
    long double areaSqft;
    string purpose;
    int bedrooms;
    string dateAdded;
    int year;
    int month;
    int day;
    //-----------------------------------------------
    Property* next;
    Property* prev;

    int random;
    Rectangle img;


    Property() {
        next = prev = NULL;

        random = GetRandomValue(0, 10);
        img = { float(random * 248), 0, 248, 138 };
    }

    Property(long long int, long int, string, string, long long int, string, string, string, string, string, long double, long double, int, string, float, long double, string, int, string, int, int, int);
    void print();


    /*Rectangle getimg() {
        return img;
    }*/

};

class Properties {
    // SDLL
private:
public:

    Property* head;
    Property* tail;

    //------------------------------------------------------------
    bool isEmpty();
    void append(long long int, long int, string, string, long long int, string, string, string, string, string, long double, long double, int, string, float, long double, string, int, string, int, int, int);
    void prepend(long long int, long int, string, string, long long int, string, string, string, string, string, long double, long double, int, string, float, long double, string, int, string, int, int, int);
    void print();
    int count();
    void readCSV();
    void search();
    Properties searchByCity(string);
    Properties searchByProvince(string);
    Properties searchByPropertyID(int);
    bool propertyExists(int);
    void sellProperty(int, string);
    void deleteFirstNode();
    void deleteLastNode();
    void deleteNode(int);
    void updateData();
    int partition(Property*, int, int);
    void quickSort(Property*, int, int);
    void sort(string);
    Properties filterByPrice(long long int, long long int);
    Properties filterByArea(long double, long double);
    Properties filterByBeds(int);
    Properties filterByType(string);
    Properties filterByCity(string);
    long long int predictPrice(string, string, int, long double, int, int);
    void generateGraphs(int);

    //--------------------------------------------------------------

    int x = 720, y = 0;


    int totrows = 0;
    int Count = 0;
    int animcounter = 0;
    int animtimer = 0;
    int loadingtimer = 0;
    int viewtopcount = 0;
    int viewdowncount = 0;
    bool down = false;
    bool up = false;
    bool popupflag = false;
    Property* popupdetails;

    string showerror = "";

    bool off = true;




    bool predictedprice_boolean = false;
    long long int tempprdictedprice = 0;

    Properties() {
        head = tail = NULL;
    }
    void assignvals(Properties obj) {
        if (obj.isEmpty()) {
            cout << "No properties" << endl;

            showerror = "No relevant results";
        }
        else {

            showerror = "";
            Property* p = obj.head;
            do {
                append(p->propertyID, p->locationID, p->pageUrl, p->propertyType, p->price, p->priceType, p->location, p->city, p->province, p->locality, p->latitude, p->longitude, p->baths, p->area, p->areaMarla, p->areaSqft, p->purpose, p->bedrooms, p->dateAdded, p->year, p->month, p->day);
                p = p->next;
            } while (p != obj.head);
        }
    }

    void playhouseanim(Texture2D houseanim) {
        if (animcounter >= 3000)
            animcounter = 0;
        DrawTextureRec(houseanim, Rectangle{ float(animcounter),0,200,150 }, Vector2{ 60,54 }, WHITE);
        if (animtimer % 13 == 0)
            animcounter += 200;
        animtimer++;
    }



    void display(Texture2D row, Texture2D bg, Texture2D house, Texture2D row_selected, Font coolfontL, Font coolfontM, Font coolfontS, Texture2D houseanim, Texture2D popupwindow, Font coolfontL2, Font coolfontM2, Font coolfontS2, Texture2D img2022, Texture2D img2021, Texture2D img2020, Texture2D img2019, Texture2D img2018, Texture2D img2017, Customer &user) {
        DrawTexture(bg, 0, 0, WHITE);
        DrawTextEx(coolfontL, showerror.c_str(), Vector2{ 800 ,200 }, 40, 0, BLACK);
        int tempy = y;
        Count = 0;

        if (GetMouseWheelMove() > 0) {
            if (GetMouseWheelMove() > 1)
                y += 40;
            else
                y += 40;
            up = true;
        }
        else if (GetMouseWheelMove() < 0) {
            if (GetMouseWheelMove() < -1)
                y -= 40;
            else
                y -= 40;
            down = true;
        }
        if (y % -240 == 0 && down == true) {        //up ka bnana he viewdown tempdowncount
            viewtopcount++;
            down = false;
        }
        if (y % 240 == 0 && up == true) {
            viewdowncount++;
            up = false;
        }
        Property* iterator = head;
        int temptopcount = viewtopcount;
        int tempdowncount = viewdowncount;


        while (iterator != NULL && tempdowncount > 0) {
            iterator = iterator->prev;
            tempdowncount--;
            tempy -= 240;
        }

        while (iterator != NULL && temptopcount > 0) {
            iterator = iterator->next;
            temptopcount--;
            tempy += 240;
        }
        if (iterator != NULL) {
            do {
                if (CheckCollisionPointRec(GetMousePosition(), Rectangle{ float(x),float(tempy),670,222 })) {
                    DrawTexture(row_selected, x, tempy, WHITE);                                                                  //row bg
                    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                        cout << "selected";
                        popupflag = true;
                        popupdetails = new Property(iterator->propertyID, iterator->locationID, iterator->pageUrl, iterator->propertyType, iterator->price, iterator->priceType, iterator->location, iterator->city, iterator->province, iterator->locality, iterator->latitude, iterator->longitude, iterator->baths, iterator->area, iterator->areaMarla, iterator->areaSqft, iterator->purpose, iterator->bedrooms, iterator->dateAdded, iterator->year, iterator->month, iterator->day);
                        popupdetails->img = iterator->img;
                        predictedprice_boolean = true;


                        loadingtimer = 0;
                    }
                }
                else
                    DrawTexture(row, x, tempy, WHITE);
                DrawTextureRec(house, iterator->img, Vector2{ float(x + 253), float(tempy + 69) }, WHITE);              //house img
                DrawTextEx(coolfontL, iterator->location.c_str(), Vector2{ float(x + 15) , float(tempy + 16) }, 40, 0, BLACK);
                DrawTextEx(coolfontL, ("PKR " + to_string(iterator->price)).c_str(), Vector2{ float(x + 412), float(tempy + 15) }, 40, 0, BLACK);
                DrawTextEx(coolfontS, to_string(round(iterator->areaSqft)).c_str(), Vector2{ float(x + 556), float(tempy + 107) }, 16, 0, BLACK);
                DrawTextEx(coolfontS, to_string(iterator->baths).c_str(), Vector2{ float(x + 556), float(tempy + 139) }, 16, 0, BLACK);
                DrawTextEx(coolfontS, to_string(iterator->bedrooms).c_str(), Vector2{ float(x + 556), float(tempy + 171) }, 16, 0, BLACK);
                DrawTextEx(coolfontS, iterator->propertyType.c_str(), Vector2{ float(x + 15) , float(tempy + 102) }, 16, 0, BLACK);
                string temp = iterator->city + ", " + iterator->province;
                DrawTextEx(coolfontM, temp.c_str(), Vector2{ float(x + 15) , float(tempy + 58) }, 24, 0, BLACK);

                tempy += 240;
                Count++;
                iterator = iterator->next;
            } while (iterator != head && Count < 8);
        }

        if (popupflag == true && popupdetails != NULL) {
            if (loadingtimer > 3) {
                DrawTexture(popupwindow, 9, 24, WHITE);
                //all ml and other stuff to be displayed here in popup window
                DrawTextureRec(house, popupdetails->img, Vector2{ 370,234 }, WHITE);              //house img
                DrawTextEx(coolfontL2, popupdetails->location.c_str(), Vector2{ 54,302 }, 40, 0, Color{ 215, 227, 252, 255 });
                DrawTextEx(coolfontL2, ("PKR " + to_string(popupdetails->price)).c_str(), Vector2{ 54,234 }, 40, 0, Color{ 193, 211, 254, 255 });
                DrawTextEx(coolfontS2, (to_string(round(popupdetails->areaSqft)) + " Sqft.").c_str(), Vector2{ 413,429 }, 16, 0, Color{ 215, 227, 252, 255 });
                DrawTextEx(coolfontS2, to_string(popupdetails->baths).c_str(), Vector2{ 413,463 }, 16, 0, Color{ 215, 227, 252, 255 });
                DrawTextEx(coolfontS2, to_string(popupdetails->bedrooms).c_str(), Vector2{ 413,495 }, 16, 0, Color{ 215, 227, 252, 255 });
                string temp = popupdetails->city + ", " + popupdetails->province;
                DrawTextEx(coolfontM2, temp.c_str(), Vector2{ 54,354 }, 24, 0, Color{ 215, 227, 252, 255 });

                DrawTextEx(coolfontS2, (to_string(popupdetails->areaMarla) + " Marla").c_str(), Vector2{ 413,397 }, 16, 0, Color{ 215, 227, 252, 255 });
                DrawTextEx(coolfontM2, ("Date added: " + popupdetails->dateAdded).c_str(), Vector2{ 369,559 }, 24, 0, Color{ 215, 227, 252, 255 });
                DrawTextEx(coolfontS2, ("Longtitude: " + to_string(popupdetails->longitude)).c_str(), Vector2{ 369,613 }, 16, 0, Color{ 215, 227, 252, 255 });
                DrawTextEx(coolfontS2, ("Latitude: " + to_string(popupdetails->latitude)).c_str(), Vector2{ 369,645 }, 16, 0, Color{ 215, 227, 252, 255 });
                DrawTextEx(coolfontS2, ("PropertyID: " + to_string(popupdetails->propertyID)).c_str(), Vector2{ 369,758 }, 16, 0, Color{ 215, 227, 252, 255 });

                if (popupdetails->year == 2017)
                    DrawTexture(img2017, 60, 496, WHITE);
                else if (popupdetails->year == 2018)
                    DrawTexture(img2018, 60, 496, WHITE);
                else if (popupdetails->year == 2019)
                    DrawTexture(img2019, 60, 496, WHITE);
                else if (popupdetails->year == 2020)
                    DrawTexture(img2020, 60, 496, WHITE);
                else if (popupdetails->year == 2021)
                    DrawTexture(img2021, 60, 496, WHITE);
                else if (popupdetails->year == 2022)
                    DrawTexture(img2022, 60, 496, WHITE);


                DrawRectangleRounded(Rectangle{ 62, 800, 280, 43 }, 0.3, 0, Color{ 51, 47, 208, 255 });
                DrawTextEx(coolfontM2, "Generate Report", Vector2{ 123,810 }, 24, 0, WHITE);

                DrawRectangleRounded(Rectangle{ 356, 800, 280, 43 }, 0.3, 0, Color{ 239, 35, 60 ,255 });
                DrawTextEx(coolfontM2, "Buy", Vector2{ 479,810 }, 24, 0, WHITE);


                DrawRectangleRounded(Rectangle{ 60, 436, 280, 50 }, 0.3, 0,Color{ 73, 113, 116 ,255});
                DrawRectangle(60, 500-25, 280, 30 , Color{ 73, 113, 116 ,255 });

                //(to_string(round(predictPrice(popupdetails->propertyType, popupdetails->city, popupdetails->baths, popupdetails->areaSqft, popupdetails->bedrooms, popupdetails->year)))).c_str();
                if (predictedprice_boolean == true) {
                    tempprdictedprice = predictPrice(popupdetails->propertyType, popupdetails->city, popupdetails->baths, popupdetails->areaSqft, popupdetails->bedrooms, popupdetails->year);

                    predictedprice_boolean = false;
                }
                DrawTextEx(coolfontS2, "Price in 2023 will be", Vector2{145,442}, 16, 0, Color{ 235, 100, 64, 255});
                DrawTextEx(coolfontM2, (to_string(round(tempprdictedprice))).c_str(), Vector2{ 115,465 }, 24, 0, Color{ 235, 100, 64, 255});
                 
                if (CheckCollisionPointRec(GetMousePosition(), Rectangle{ 62, 800, 280, 43 })) {//gen report colllision
                    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                        generateReport("properties");
                    }
                }
                if (CheckCollisionPointRec(GetMousePosition(), Rectangle{ 356, 800, 280, 43 })) {//buying colllision
                    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                       // user.buy(popupdetails->propertyID);
                    }
                }


                playhouseanim(houseanim);
            }
            loadingtimer++;
        }
    }

    bool getstatus() {
        if (CheckCollisionPointRec(GetMousePosition(), Rectangle{ 16,8,53,53 })) {
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                off = true;
                popupdetails = NULL;

                viewtopcount = 0;
                viewdowncount = 0;
                y = 0;
            }
        }
        return off;
    }


};
Properties properties;








//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@



class EmailNode {
public:
    // int accountNumber;
    string name;
    string email;
    EmailNode* next;

    EmailNode(string, string);
};


class EmailQueue {
private:
    EmailNode* front;
    EmailNode* rear;
public:
    EmailQueue();
    bool isEmpty();
    void enqueue(string, string);
    void dequeue();
    EmailNode* getFront();
    string getFrontEmail();
    void sendEmailToAll();
    void printQueue();
};
//---------------------------------------------------------------------------------------------------------------------------
long long int Properties::predictPrice(string propertyType, string city, int baths, long double area, int bedrooms, int year) {
    Properties searched = searchByCity(city);
    int propType, c;

    // storing data in csv file
    fstream fout;
    fout.open("./python-predict/data.csv", ios::out);
    fout << "property_type,price,city,bath,area_sqft,bedrooms,year" << endl;
    Property* temp = searched.head;
    do {
        propType = 1;   // house
        if (temp->propertyType == "Flat") {
            propType = 2;
        }
        if (temp->city == "Karachi") {
            c = 1;
        }
        else if (temp->city == "Lahore") {
            c = 2;
        }
        fout << propType << "," << temp->price << "," << c << "," << temp->baths << "," << temp->areaSqft << "," << temp->bedrooms << "," << temp->year << endl;
        temp = temp->next;
    } while (temp != searched.head);
    fout.close();

    // calling python program to do prediction
    propType = 1;   // house
    if (propertyType == "Flat") {
        propType = 2;
    }
    if (city == "Karachi") {
        c = 1;
    }
    else if (city == "Lahore") {
        c = 2;
    }
    string command = "python ./python-predict/app.py " + to_string(propType);
    command = command + " ";
    command = command + to_string(c);
    command = command + " ";
    command = command + to_string(baths);
    command = command + " ";
    command = command + to_string(area);
    command = command + " ";
    command = command + to_string(bedrooms);
    command = command + " ";
    command = command + to_string(year);
    const char* str = command.c_str();
    system(str);

    // reading the predicted price
    fstream fin;
    fin.open("./python-predict/price.txt", ios::in);
    long long int predictedPrice;
    fin >> predictedPrice;
    fin.close();
    return predictedPrice;
}

void Properties::generateGraphs(int year) {
    fstream fout;
    fout.open("./python-graphs/data.csv", ios::out);
    fout << "property_type,price,city,bath,area_sqft,bedrooms,year,month,price_type" << endl;
    Property* temp = head;
    do {
        if (temp->year == year) {
            fout << temp->propertyType << "," << temp->price << "," << temp->city << "," << temp->baths << "," << temp->areaSqft << "," << temp->bedrooms << "," << temp->year << "," << temp->month << "," << temp->priceType << endl;
        }
        temp = temp->next;
    } while (temp != head);
    fout.close();

    system("python ./python-graphs/app.py");
}

// USER

void User::readData()
{
    ifstream fin;
    system("cls");
    fin.open("./data/customer.bank", ios::in | ios::binary);
    fin.read((char*)this, sizeof(*this));
    while (fin.eof() == 0)
    {
        // cout << "Acc No: " << this->accountNumber << endl;
        cout << "Name: " << this->name << endl;
        cout << "Email: " << this->email << endl;
        cout << endl;
        fin.read((char*)this, sizeof(*this));
    }
    fin.close();
}

// int User::getAccountNumber()
// {
//     return accountNumber;
// }

char* User::getName()
{
    return name;
}

int User::getAge()
{
    return age;
}

char User::getGender()
{
    return gender;
}

char* User::getEmail()
{
    return email;
}

// CUSTOMER

void Customer::createNewAccount(char n[40], int age, char gender, char e[30], char p[20])
{
    Customer c;
    //c.accountNumber = c.generateAccountNumber();
    strcpy_s(c.name, n);
    c.age = age;
    c.gender = gender;
    strcpy_s(c.email, e);
    strcpy_s(c.password, p);
    c.storeData();
}

//int Customer::generateAccountNumber()
//{
//    ifstream fin;
//    int num;
//    bool isFound = false;
//    srand(time_t(0));
//    fin.open("./data/customer.bank", ios::in | ios::binary);
//    if (!fin)
//    {
//        perror("Error");
//        //Sleep(2000);
//        // exit(1);
//    }
//    else
//    {
//        while (1)
//        {
//            num = (rand() % 10000) + 100000;
//            fin.read((char*)this, sizeof(*this));
//            while (fin.eof() == 0)
//            {
//                if (this->accountNumber == num)
//                {
//                    isFound = true;
//                    break;
//                }
//                fin.read((char*)this, sizeof(*this));
//            }
//            if (isFound == false)
//            {
//                break;
//            }
//        }
//    }
//    fin.close();
//    return num;
//}

void Customer::storeData()
{
    ofstream fout;
    fout.open("./data/customer.bank", ios::app | ios::binary);
    if (!fout)
    {
        perror("Error");
        //Sleep(2000);
    }
    fout.write((char*)this, sizeof(*this));
    fout.close();
}

bool Customer::login(char e[30], char pass[20])
{
    bool idFound = false;
    ifstream fin;
    fin.open("./data/customer.bank", ios::in | ios::binary);
    if (!fin)
    {
        cout << "ERROR, file does not exist" << endl;
    }
    else
    {
        fin.read((char*)this, sizeof(*this));
        while (fin.eof() == 0)
        {
            if (strcmp(e, email) == 0)
            {
                idFound = true;
                if (strcmp(password, pass) == 0)
                {
                    fin.close();
                    return true;
                }
                else
                {
                    return false;
                }
            }
            fin.read((char*)this, sizeof(*this));
        }
        fin.close();
        return false;
    }
}

void Customer::buy(int propID) {
    if (properties.propertyExists(propID)) {
        properties.sellProperty(propID, name);
        properties.deleteNode(propID);
    }
}

void Customer::sendEmailToAll(string subject, string content) {
    EmailQueue emailQueue;
    ifstream fin;
    Customer customer;
    system("cls");
    fin.open("./data/customer.bank", ios::in | ios::binary);
    fin.read((char*)&customer, sizeof(customer));
    while (fin.eof() == 0)
    {
        emailQueue.enqueue(customer.name, customer.email);
        fin.read((char*)&customer, sizeof(customer));
    }
    fin.close();

    // storing emails in receiver.txt
    ofstream fout;
    // storing subject in subject.txt
    fout.open("./python-email/subject.txt", ios::out);
    fout << subject;
    fout.close();

    // storing content in content.txt
    fout.open("./python-email/content.txt", ios::out);
    fout << content;
    fout.close();


    while (!emailQueue.isEmpty()) {
        fout.open("./python-email/receiver.txt", ios::out);
        fout << emailQueue.getFrontEmail() << "\n";
        emailQueue.dequeue();
        fout.close();
        system("python send_email.py");
    }


}

void Customer::sendEmail(string email, string subject, string content) {
    ofstream fout;
    fout.open("./python-email/subject.txt", ios::out);
    fout << subject;
    fout.close();

    fout.open("./python-email/content.txt", ios::out);
    fout << content;
    fout.close();

    fout.open("./python-email/receiver.txt", ios::out);
    fout << email;
    fout.close();

    system("python send_email.py");
}

// EMAILNODE

EmailNode::EmailNode(string name, string email) {
    // this->accountNumber = accountNumber;
    this->name = name;
    this->email = email;
    next = NULL;
}

// EMAILQUEUE

EmailQueue::EmailQueue() {
    front = rear = NULL;
}

bool EmailQueue::isEmpty() {
    if (front == NULL && rear == NULL) {
        return true;
    }
    else {
        return false;
    }
}

void EmailQueue::enqueue(string name, string email) {
    EmailNode* e = new EmailNode(name, email);
    if (isEmpty()) {
        front = rear = e;
    }
    else {
        rear->next = e;
        rear = e;
    }
}

void EmailQueue::dequeue() {
    if (isEmpty()) {
        return;
    }
    if (front == rear) {
        delete front;
        front = rear = NULL;
    }
    else {
        EmailNode* temp = front;
        front = front->next;
        delete temp;
    }
}

void EmailQueue::printQueue() {
    if (!isEmpty()) {
        EmailNode* temp = front;
        while (temp != NULL) {
            cout << temp->name << "  " << temp->email << endl;
            temp = temp->next;
        }
    }
    cout << endl;
}

string EmailQueue::getFrontEmail() {
    if (!isEmpty()) {
        return (front->email);
    }
}

void generateReport(string arg) {
    string command = "python ./python-generate-report/app.py " + arg;
    const char* str = command.c_str();
    system(str);
}







//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

//class Stack {
//private:
//    Property* top;
//public:
//    Stack();
//    bool isEmpty();
//    void push(Property* p);
//    void pop();
//    Property* peek();
//
//
//};


string convertToString(char* a) {
    string s = a;
    return s;
}










Property::Property(long long int propertyID, long int locationID, string pageUrl, string propertyType, long long int price, string priceType, string location, string city, string province, string locality, long double latitude, long double longitude, int baths, string area, float areaMarla, long double areaSqft, string purpose, int bedrooms, string dateAdded, int year, int month, int day) {
    this->propertyID = propertyID;
    this->locationID = locationID;
    this->pageUrl = pageUrl;
    this->propertyType = propertyType;
    this->price = price;
    this->priceType = priceType;
    this->location = location;
    this->city = city;
    this->province = province;
    this->locality = locality;
    this->latitude = latitude;
    this->longitude = longitude;
    this->baths = baths;
    this->area = area;
    this->areaMarla = areaMarla;
    this->areaSqft = areaSqft;
    this->purpose = purpose;
    this->bedrooms = bedrooms;
    this->dateAdded = dateAdded;
    this->year = year;
    this->month = month;
    this->day = day;
    next = prev = NULL;
    //--------------------------------------------------
    random = GetRandomValue(0, 10);
    img = { float(random * 248), 0, 248, 138 };
}

void Property::print() {
    cout << setw(7) << propertyType << "  " << setw(12) << price << "  " << setw(40) << location << "  " << setw(10) << city << "  " << setw(10) << province << "  " << setw(10) << areaSqft << "  " << setw(10) << purpose << "  " << dateAdded << endl;
}

// PROPERTIES



bool Properties::isEmpty() {
    if (head == NULL && tail == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Properties::append(long long int propertyID, long int locationID, string pageUrl, string propertyType, long long int price, string priceType, string location, string city, string province, string locality, long double latitude, long double longitude, int baths, string area, float areaMarla, long double areaSqft, string purpose, int bedrooms, string dateAdded, int year, int month, int day) {
    Property* n = new Property(propertyID, locationID, pageUrl, propertyType, price, priceType, location, city, province, locality, latitude, longitude, baths, area, areaMarla, areaSqft, purpose, bedrooms, dateAdded, year, month, day);
    if (isEmpty())
        head = tail = n;
    else
        n->next = head;
    n->prev = tail;
    tail->next = n;
    head->prev = n;
    tail = n;
}

void Properties::prepend(long long int propertyID, long int locationID, string pageUrl, string propertyType, long long int price, string priceType, string location, string city, string province, string locality, long double latitude, long double longitude, int baths, string area, float areaMarla, long double areaSqft, string purpose, int bedrooms, string dateAdded, int year, int month, int day) {
    Property* n = new Property(propertyID, locationID, pageUrl, propertyType, price, priceType, location, city, province, locality, latitude, longitude, baths, area, areaMarla, areaSqft, purpose, bedrooms, dateAdded, year, month, day);
    if (isEmpty())
        head = tail = n;
    else {
        n->next = head;
        n->prev = tail;
        tail->next = n;
        head->prev = n;
        head = n;
    }
}

void Properties::print() {
    if (isEmpty())
        showerror = "No relevant results";
    else {
        showerror = "";
        Property* temp = head;
        do {
            temp->print();
            temp = temp->next;
        } while (temp != head);
    }
}

int Properties::count() {
    int count = 0;
    if (!isEmpty()) {
        Property* temp = head;
        do {
            count++;
            temp = temp->next;
        } while (temp != head);
    }
    return count;
}

void Properties::readCSV() {
    long long int propertyID;
    long int locationID;
    string pageUrl;
    string propertyType;
    long long int price;
    string priceType;
    string location;
    string city;
    string province;
    string locality;
    long double latitude;
    long double longitude;
    int baths;
    string area;
    float areaMarla;
    long double areaSqft;
    string purpose;
    int bedrooms;
    string dateAdded;
    int year;
    int month;
    int day;

    string fname = "./data/property.csv";
    vector<vector<string> > content;
    vector<string> row;
    string line, word;
    fstream file(fname.c_str(), ios::in);
    if (file.is_open()) {
        while (getline(file, line)) {
            row.clear();

            stringstream str(line);

            while (getline(str, word, ','))
                row.push_back(word);
            content.push_back(row);
        }
    }
    else
        cout << "Could not open the file\n";

    file.close();

    for (int i = 1; i < content.size(); i++) {

        propertyID = stoll(content[i][0]);
        locationID = stol(content[i][1]);
        pageUrl = content[i][2];
        propertyType = content[i][3];
        price = stoi(content[i][4]);
        priceType = content[i][5];
        location = content[i][6];
        city = content[i][7];
        province = content[i][8];
        locality = content[i][9];
        locality += content[i][10];
        locality += content[i][11];
        latitude = stold(content[i][12]);
        longitude = stoi(content[i][13]);
        baths = stoi(content[i][14]);
        area = content[i][15];
        areaMarla = stof(content[i][16]);
        areaSqft = stold(content[i][17]);
        purpose = content[i][18];
        bedrooms = stoi(content[i][19]);
        dateAdded = content[i][20];
        year = stoi(content[i][21]);
        month = stoi(content[i][22]);
        day = stoi(content[i][23]);
        append(propertyID, locationID, pageUrl, propertyType, price, priceType, location, city, province, locality, latitude, longitude, baths, area, areaMarla, areaSqft, purpose, bedrooms, dateAdded, year, month, day);
    }
}

void Properties::search() {
    int choice, propID;
    string str;
    while (1) {
        system("cls");
        fflush(stdin);
        cout << "1. Search by city" << endl;
        cout << "2. Search by province" << endl;
        cout << "3. Search by property ID" << endl;
        cout << "4. Go back" << endl;
        cout << "\n\nEnter your choice: ";
        cin >> choice;
        system("cls");
        fflush(stdin);
        if (choice == 1) {
            cout << "Enter city: ";
            getline(cin, str);
            searchByCity(str);
        }
        else if (choice == 2) {
            cout << "Enter province: ";
            getline(cin, str);
            searchByProvince(str);
        }
        else if (choice == 3) {
            cout << "Enter property ID: ";
            cin >> propID;
            searchByPropertyID(propID);
        }
        else if (choice == 4) {
            //loadingAnimation();
            break;
        }
        else {
            cout << "Wrong choice entered, please enter a correct choice" << endl;
            //Sleep(1000);
        }
    }
}

Properties Properties::searchByCity(string city) {
    // Linear Search
    Property* p = head;

    Properties templist;
    do {
        if (p->city == city) {
            templist.append(p->propertyID, p->locationID, p->pageUrl, p->propertyType, p->price, p->priceType, p->location, p->city, p->province, p->locality, p->latitude, p->longitude, p->baths, p->area, p->areaMarla, p->areaSqft, p->purpose, p->bedrooms, p->dateAdded, p->year, p->month, p->day);
        }
        p = p->next;
    } while (p != head);

    if (templist.head == NULL)
        templist.showerror = "No relevant results";
    else
        templist.showerror = "";

    return templist;
}

Properties Properties::searchByProvince(string province) {
    // Linear Search
    Property* p = head;
    Properties temp;
    do {
        if (p->province == province) {
            temp.append(p->propertyID, p->locationID, p->pageUrl, p->propertyType, p->price, p->priceType, p->location, p->city, p->province, p->locality, p->latitude, p->longitude, p->baths, p->area, p->areaMarla, p->areaSqft, p->purpose, p->bedrooms, p->dateAdded, p->year, p->month, p->day);
        }
        p = p->next;
    } while (p != head);

    if (temp.head == NULL)
        temp.showerror = "No relevant results";
    else
        temp.showerror = "";

    return temp;
}

Properties Properties::searchByPropertyID(int ID) {
    // Linear Search
    Property* p = head;
    Properties temp;
    do {
        if (p->propertyID == ID) {
            temp.append(p->propertyID, p->locationID, p->pageUrl, p->propertyType, p->price, p->priceType, p->location, p->city, p->province, p->locality, p->latitude, p->longitude, p->baths, p->area, p->areaMarla, p->areaSqft, p->purpose, p->bedrooms, p->dateAdded, p->year, p->month, p->day);
            break;
        }
        p = p->next;
    } while (p != head);


    if (temp.head == NULL)
        showerror = "No relevant results";
    else
        showerror = "";

    return temp;
}

bool Properties::propertyExists(int ID) {
    Property* p = head;
    do {
        if (p->propertyID == ID) {
            return true;
        }
        p = p->next;
    } while (p != head);
    return false;
}



void Properties::sellProperty(int propID, string name) {
    // Open FIle pointers
    fstream fin, fout, sold;

    // Open the existing file
    fin.open("./data/property.csv", ios::in);

    // Create a new file to store the non-deleted data
    fout.open("temp.csv", ios::out);

    int id, count = 0, i;
    int index;
    string line, word;
    vector<string> row;
    getline(fin, line);
    row.clear();
    stringstream first(line);
    while (getline(first, word, ',')) {
        row.push_back(word);
    }
    int first_size = row.size();
    for (int i = 0; i < first_size - 1; i++) {
        fout << row[i] << ",";
    }
    fout << row[first_size - 1] << "\n";
    // Check if this record exists
    // If exists, leave it and
    // add all other data to the new file
    while (!fin.eof()) {

        row.clear();
        getline(fin, line);
        stringstream s(line);

        while (getline(s, word, ',')) {
            row.push_back(word);
        }
        int row_size = row.size();
        id = stoi(row[0]);

        if (id != propID) {
            if (!fin.eof()) {
                for (i = 0; i < row_size - 1; i++) {
                    fout << row[i] << ",";
                }
                fout << row[row_size - 1] << "\n";
            }
        }
        else {
            count = 1;
            sold.open("./data/sold.csv", ios::out | ios::app);
            for (int i = 0; i < row_size; i++) {
                sold << row[i] << ",";
            }
            sold << name << "\n";
            sold.close();
        }
        if (fin.eof())
            break;
    }
    if (count == 1)
        cout << "Record deleted\n";
    else
        cout << "Record not found\n";

    // Close the pointers
    fin.close();
    fout.close();

    // removing the existing file
    remove("./data/property.csv");

    // renaming the new file with the existing file name
    rename("temp.csv", "./data/property.csv");
}


void Properties::updateData() {

}

void Properties::deleteNode(int propID) {
    if (isEmpty()) {
        return;
    }
    else {
        if (head->propertyID == propID) {
            deleteFirstNode();
        }
        else {
            Property* temp = head;
            do {
                temp = temp->next;
            } while (temp != head && temp->propertyID != propID);
            if (temp->propertyID == propID) {
                if (temp == tail) {
                    deleteLastNode();
                }
                else {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    delete temp;
                }
            }
        }
    }
}

void Properties::deleteFirstNode() {
    if (isEmpty()) {
        return;
    }
    else {
        if (head == tail) {
            delete head;
            head = tail = NULL;
        }
        else {
            Property* temp = head;
            head = head->next;
            tail->next = head;
            head->prev = tail;
            delete temp;
        }
    }
}

void Properties::deleteLastNode() {
    if (isEmpty()) {
        return;
    }
    else {
        if (head == tail) {
            delete head;
            head = tail = NULL;
        }
        else {
            Property* temp = tail;
            tail = tail->prev;
            tail->next = head;
            head->prev = tail;
            delete temp;
        }
    }
}

void Properties::sort(string type) {
    Properties sorted;
    int n = count();
    Property* arr = new Property[n];
    Property* temp = head;
    for (int i = 0; i < n; i++) {
        arr[i] = *temp;
        temp = temp->next;
    }
    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        if (type == "descending") {
            sorted.append(arr[i].propertyID, arr[i].locationID, arr[i].pageUrl, arr[i].propertyType, arr[i].price, arr[i].priceType, arr[i].location, arr[i].city, arr[i].province, arr[i].locality, arr[i].latitude, arr[i].longitude, arr[i].baths, arr[i].area, arr[i].areaMarla, arr[i].areaSqft, arr[i].purpose, arr[i].bedrooms, arr[i].dateAdded, arr[i].year, arr[i].month, arr[i].day);
        }
        else {
            sorted.prepend(arr[i].propertyID, arr[i].locationID, arr[i].pageUrl, arr[i].propertyType, arr[i].price, arr[i].priceType, arr[i].location, arr[i].city, arr[i].province, arr[i].locality, arr[i].latitude, arr[i].longitude, arr[i].baths, arr[i].area, arr[i].areaMarla, arr[i].areaSqft, arr[i].purpose, arr[i].bedrooms, arr[i].dateAdded, arr[i].year, arr[i].month, arr[i].day);
        }
    }
    delete[] arr;
    sorted.print();
}

void Properties::quickSort(Property* arr, int low, int high) {
    if (low < high) {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int Properties::partition(Property* arr, int low, int high) {
    int pivot = arr[high].price; // pivot
    Property temp;
    int i
        = (low
            - 1); // Index of smaller element and indicates
                  // the right position of pivot found so far

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than the pivot
        if (arr[j].price < pivot) {
            i++; // increment index of smaller element
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

Properties Properties::filterByPrice(long long int from, long long int to) {
    Property* temp = head;
    Properties filter;
    do {
        if (temp->price >= from && temp->price <= to) {
            filter.append(temp->propertyID, temp->locationID, temp->pageUrl, temp->propertyType, temp->price, temp->priceType, temp->location, temp->city, temp->province, temp->locality, temp->latitude, temp->longitude, temp->baths, temp->area, temp->areaMarla, temp->areaSqft, temp->purpose, temp->bedrooms, temp->dateAdded, temp->year, temp->month, temp->day);
        }
        temp = temp->next;
    } while (temp != head);


    if (filter.head == NULL)
        showerror = "No relevant results";
    else
        showerror = "";

    return filter;
}

Properties Properties::filterByArea(long double from, long double to) {
    Property* temp = head;
    Properties filter;
    do {
        if (temp->areaSqft >= from && temp->areaSqft <= to) {
            filter.append(temp->propertyID, temp->locationID, temp->pageUrl, temp->propertyType, temp->price, temp->priceType, temp->location, temp->city, temp->province, temp->locality, temp->latitude, temp->longitude, temp->baths, temp->area, temp->areaMarla, temp->areaSqft, temp->purpose, temp->bedrooms, temp->dateAdded, temp->year, temp->month, temp->day);
        }
        temp = temp->next;
    } while (temp != head);

    if (filter.head == NULL)
        showerror = "No relevant results";
    else
        showerror = "";


    return filter;
}

Properties Properties::filterByBeds(int beds) {
    Property* temp = head;
    Properties filter;
    do {
        if (temp->bedrooms == beds) {
            filter.append(temp->propertyID, temp->locationID, temp->pageUrl, temp->propertyType, temp->price, temp->priceType, temp->location, temp->city, temp->province, temp->locality, temp->latitude, temp->longitude, temp->baths, temp->area, temp->areaMarla, temp->areaSqft, temp->purpose, temp->bedrooms, temp->dateAdded, temp->year, temp->month, temp->day);
        }
        temp = temp->next;
    } while (temp != head);

    if (filter.head == NULL)
        showerror = "No relevant results";
    else
        showerror = "";

    return filter;
}

Properties Properties::filterByType(string type) {
    Property* temp = head;
    Properties filter;
    do {
        if (temp->propertyType == type) {
            filter.append(temp->propertyID, temp->locationID, temp->pageUrl, temp->propertyType, temp->price, temp->priceType, temp->location, temp->city, temp->province, temp->locality, temp->latitude, temp->longitude, temp->baths, temp->area, temp->areaMarla, temp->areaSqft, temp->purpose, temp->bedrooms, temp->dateAdded, temp->year, temp->month, temp->day);
        }
        temp = temp->next;
    } while (temp != head);

    if (filter.head == NULL)
        showerror = "No relevant results";
    else
        showerror = "";


    return filter;
}

Properties Properties::filterByCity(string city) {
    Property* temp = head;
    Properties filter;
    do {
        if (temp->city == city) {
            filter.append(temp->propertyID, temp->locationID, temp->pageUrl, temp->propertyType, temp->price, temp->priceType, temp->location, temp->city, temp->province, temp->locality, temp->latitude, temp->longitude, temp->baths, temp->area, temp->areaMarla, temp->areaSqft, temp->purpose, temp->bedrooms, temp->dateAdded, temp->year, temp->month, temp->day);
        }
        temp = temp->next;
    } while (temp != head);

    if (filter.head == NULL)
        showerror = "No relevant results";
    else
        showerror = "";


    return filter;
}
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@










//void generateReport(string arg) {//properties argument
//    string command = "python ./python-generate-report/app.py " + arg;
//    const char* str = command.c_str();
//    system(str);
//}
//
//void Properties::generateGraphs(int year) {
//    fstream fout;
//    fout.open("./python-graphs/data.csv", ios::out);
//    fout << "property_type,price,city,bath,area_sqft,bedrooms,year,month,price_type" << endl;
//    Property* temp = head;
//    do {
//        if (temp->year == year) {
//            fout << temp->propertyType << "," << temp->price << "," << temp->city << "," << temp->baths << "," << temp->areaSqft << "," << temp->bedrooms << "," << temp->year << "," << temp->month << "," << temp->priceType << endl;
//        }
//        temp = temp->next;
//    } while (temp != head);
//    fout.close();
//
//    system("python ./python-graphs/app.py");
//}










//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
/*

class searchnode {
public:
    //------------------------------
    long long int propertyID = 347795;
    long int locationID = 8;
    string pageUrl = "https://www.zameen.com/Property/lahore_model_town_6_kanal_excellent_house_for_sale_in_model_town-347795-8-1.html";
    string propertyType = "House";
    long long int price = 220000000;
    //string priceType;
    string location = "Model Town";
    string city = "Lahore";
    string province = "Punjab";
    string locality = "Model Town, Lahore, Punjab";
    //long double latitude;
    //long double longitude;
    int baths = 4;
    //string area;
    //float areaMarla;
    long double areaSqft = 5445.04;
    string purpose = "For Sale";
    int bedrooms = 4;
    string dateAdded = "07-17-2019";
    //int year= 2019;
    //int month=;
    //int day;

    //------------------------------

    int x;

    Rectangle img;
    searchnode* next;
    searchnode* prev;

    searchnode() {
        next = prev = NULL;
    }


    searchnode() {
        next = NULL;
        prev = NULL;
        x = GetRandomValue(0, 10);
        img = { float(x * 248), 0, 248, 138 };
    }
    Rectangle getimg() {
        return img;
    }
};

class Searchview {
public:
    int x=720, y=0;
    searchnode* head;
    searchnode* tail;

    searchnode* temp;

    Texture2D row = LoadTexture("./row.png");
    Texture2D bg = LoadTexture("./init.png");
    Texture2D house = LoadTexture("./houseImages.png");

    Font coolfontL = LoadFontEx("./glacial_thin.otf", 40, 0, 250);
    Font coolfontM = LoadFontEx("./glacial_thin.otf", 24, 0, 250);
    Font coolfontS = LoadFontEx("./glacial_thin.otf", 16, 0, 250);

    int totrows = 0;
    int count = 0;

    int viewtopcount = 0;
    bool flag = false, flag2=false;

    Searchview() {
        head = NULL;
        temp = NULL;
    }




    void display() {
        DrawTexture(bg, 0, 0, WHITE);
        int tempy = y;
        count = 0;
        flag2 = false;
        if (GetMouseWheelMove() > 0) {
            if (GetMouseWheelMove() > 1)
                y += 10;
            else
                y += 10;
            flag = true;
        }
        else if (GetMouseWheelMove() < 0) {
            if (GetMouseWheelMove() < -1)
                y -= 10;
            else
                y -= 10;
            flag = true;
        }
        if (y % -240 == 0 && flag == true) {
            viewtopcount++;
            flag = false;
        }
        searchnode* iterator = head;
        int tempcount = viewtopcount;

        while (iterator != NULL && tempcount >0) {
            iterator = iterator->next;
            tempcount--;
            tempy += 240;
            cout <<tempcount<<", ";
            flag2 = true;
        }


        while (iterator != NULL && count < 8) {
            DrawTexture(row, x, tempy, WHITE);                                                          //row bg
            DrawTextureRec(house,iterator->getimg(), Vector2{float(x+253), float(tempy+69)}, WHITE);    //house img
            DrawTextEx(coolfontL, iterator->location.c_str(), Vector2{ float(x + 15), float(tempy + 16) }, 40, 0, BLACK);
            DrawTextEx(coolfontL, ("PKR "+to_string(iterator->price)).c_str(), Vector2{float(x + 412), float(tempy + 15)}, 40, 0, BLACK);
            DrawTextEx(coolfontS, to_string(round(iterator->areaSqft)).c_str(), Vector2{ float(x + 556), float(tempy + 107) }, 16, 0, BLACK);
            DrawTextEx(coolfontS, to_string(iterator->baths).c_str(), Vector2{ float(x + 556), float(tempy + 139) }, 16, 0, BLACK);
            DrawTextEx(coolfontS, to_string(iterator->bedrooms).c_str(), Vector2{ float(x + 556), float(tempy + 171) }, 16, 0, BLACK);
            DrawTextEx(coolfontS, iterator->propertyType.c_str(), Vector2{ float(x + 15), float(tempy + 102) }, 16, 0, BLACK);
            string temp = iterator->city + ", " + iterator->province;
            DrawTextEx(coolfontM, temp.c_str(), Vector2{ float(x + 15), float(tempy + 58) }, 24, 0, BLACK);

            tempy += 240;
            count++;
            iterator = iterator->next;
        }
    }
};


*/


//--------------------------------------------------------------------------------------------------------------




//Customer bhai;










//--------------------------------------------------------------------------------------------------------------
class listnode {
public:
    int index;
    string data;
    listnode* next_pointer;
    listnode(int Key, string Data) {
        index = Key;
        data = Data;
        next_pointer = NULL;
    }
};


class recyclerview {
public:
    listnode* head;

    int x, y, width, height;
    Font coolfont;
    int count = 0;

    recyclerview() {
        head = NULL;
        x = 0; y = 0; width = 0; height = 0;
    }
    void setview(int x1, int y1, int w, int h) {
        x = x1;
        y = y1;
        width = w;
        height = h;
        coolfont = LoadFontEx("./assets/glacial_thin.otf", (int)(height - (height * 0.6)), 0, 250);
    }
    void append(int index, string data) {
        listnode* temp = new listnode(index, data);

        if (head == NULL)
            head = temp;
        else {
            listnode* iterator = head;
            while (iterator->next_pointer != NULL)
                iterator = iterator->next_pointer;
            iterator->next_pointer = temp;
        }
        count++;
    }
    void display() {

        int tempy = y;
        listnode* iterator = head;
        while (iterator != NULL) {

            DrawRectangle(x, tempy, width, height, WHITE);
            DrawTextEx(coolfont, iterator->data.c_str(), Vector2{ (float)(x + 10), (float)(tempy + height - (height * 0.6)) }, (float)(height - (height * 0.6)), 0, BLACK);
            DrawLine(x, tempy, x + width, tempy, BLACK);
            tempy += height;
            iterator = iterator->next_pointer;
        }
    }
    int getposition() {
        int tempy = y;
        for (int i = 0; i < count; i++) {
            if (CheckCollisionPointRec(GetMousePosition(), Rectangle{ (float)x,(float)tempy,(float)width,(float)height }))
                return i;
            tempy += height;
        }
        return -100;
    }
    string getval(int pos) {
        if (pos == -100)
            return "Select";
        int i = 0;
        listnode* iterator = head;
        while (i < pos && iterator->next_pointer != NULL) {
            i++;
            iterator = iterator->next_pointer;
        }
        if (iterator != NULL)
            return iterator->data;
        else
            return "Select";
    }
};



class initUI {
public:
    bool off = false;
    int time = 0;
    int x = 0;
    Texture2D init = LoadTexture("./assets/init.png");
    Texture2D init2 = LoadTexture("./assets/init2.png");

    void startup() {
        DrawTexture(init, 0, 0, WHITE);
        DrawTexture(init2, x, 390, WHITE);

        if (x < 83)
            x += 7;
        if (x < 166)
            x += 5;
        if (x < 249)
            x += 4;
        if (x < 332)
            x += 3;
        if (x < 410)
            x += 4;
        else
            time++;

        if (time >= 120)
            off = true;

    }
    bool getstatus() {
        return off;
    }
    ~initUI() {
        UnloadTexture(init);
        UnloadTexture(init2);
    }
};

class mainmenuUI {
public:

    bool flag[3] = { false };   //checks whether button has been pressed or not
    bool off = false;       //turns off display once moving to another screen

    Texture2D bg = LoadTexture("./assets/mainmenu.png");
    Texture2D search = LoadTexture("./assets/search_select.png");
    Font coolfont = LoadFontEx("./assets/glacial_thin.otf", 27, 0, 250);

    //buttons
    Rectangle searchbut = { 1121 , 387 , 33 , 33 };
    Rectangle city = { 521 , 395 , 85 , 33 };
    Rectangle type = { 521 , 466 , 85 , 33 };
    Rectangle filter = { 700 , 466 , 85 , 33 };
    //virtual selection box
    Rectangle to = { 803 , 449 , 171 , 51 };
    Rectangle from = { 993 , 449 , 171 , 51 };
    Rectangle searchbox = { 626 , 379 , 538 , 48 };

    //drop down menu
    recyclerview citylist;
    recyclerview typelist;
    recyclerview filterlist;

    //buttons pr display hone wala text
    string dp1 = "City";
    string dp2 = "Type";
    string dp3 = "Filter";

    //inputs get string values of textboxes
    char inp1[15] = "\0";
    char inp2[15] = "\0";
    char googlesearch[45] = "\0";
    int charcount1 = 0, charcount2 = 0, searchcount = 0, timercount = 0;

    mainmenuUI() {
        citylist.setview(446, 428, 161, 40);
        typelist.setview(446, 499, 161, 40);
        filterlist.setview(625, 499, 161, 40);

        citylist.append(1, "Karachi");
        citylist.append(2, "Lahore");
        citylist.append(3, "Islamabad");

        typelist.append(1, "Plot");
        typelist.append(2, "Rent");
        typelist.append(3, "House");

        filterlist.append(1, "Money Range");
        filterlist.append(2, "Area");
        filterlist.append(3, "Beds");

    }
    void display() {

        DrawTexture(bg, 0, 0, WHITE);
        DrawTextEx(coolfont, dp1.c_str(), Vector2{ 450, 398 }, 27, 1, GRAY);
        DrawTextEx(coolfont, dp2.c_str(), Vector2{ 450, 469 }, 27, 1, GRAY);
        DrawTextEx(coolfont, dp3.c_str(), Vector2{ 629, 469 }, 27, 0, GRAY);

        if (CheckCollisionPointRec(GetMousePosition(), city))
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                flag[0] = true;
                flag[1] = false;
                flag[2] = false;
            }

        if (CheckCollisionPointRec(GetMousePosition(), type))
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                flag[1] = true;
                flag[0] = false;
                flag[2] = false;
            }

        if (CheckCollisionPointRec(GetMousePosition(), filter))
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                flag[2] = true;
                flag[0] = false;
                flag[1] = false;
            }

        if (flag[0] == true) {
            citylist.display();
            int choice = citylist.getposition();
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                //choice selected
                dp1 = citylist.getval(choice);
            }
        }
        else if (flag[1] == true) {
            typelist.display();
            int choice = typelist.getposition();
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                dp2 = typelist.getval(choice);
            }
        }
        else if (flag[2] == true) {
            filterlist.display();
            int choice = filterlist.getposition();
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                dp3 = filterlist.getval(choice);
            }
        }

        dispdefaulttext();
        checkinputs();


        //change mouse pointers
        if (CheckCollisionPointRec(GetMousePosition(), to) || CheckCollisionPointRec(GetMousePosition(), from))
            SetMouseCursor(MOUSE_CURSOR_IBEAM);
        else if (CheckCollisionPointRec(GetMousePosition(), searchbut) || CheckCollisionPointRec(GetMousePosition(), city) || CheckCollisionPointRec(GetMousePosition(), type) || CheckCollisionPointRec(GetMousePosition(), filter) || CheckCollisionPointRec(GetMousePosition(), searchbox))
            SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
        else
            SetMouseCursor(MOUSE_CURSOR_DEFAULT);

        //checking whether mouse has been clicked outside 
        if (!CheckCollisionPointRec(GetMousePosition(), filter) && !CheckCollisionPointRec(GetMousePosition(), type) && !CheckCollisionPointRec(GetMousePosition(), city))
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                for (int i = 0; i < 3; i++)
                    flag[i] = false;

        checksearchcollision();
    }
    void dispdefaulttext() {
        //displays default text on filter options when no input given
        if (charcount1 <= 1 && CheckCollisionPointRec(GetMousePosition(), to) == false && (dp3 == "Money Range" || dp3 == "Area")) {
            DrawTextEx(coolfont, "To", Vector2{ 803, 471 }, 27, 0, WHITE);
        }
        if (charcount1 <= 1 && CheckCollisionPointRec(GetMousePosition(), to) == false && (dp3 == "Beds")) {
            DrawTextEx(coolfont, "Beds", Vector2{ 803, 471 }, 27, 0, WHITE);
        }
        if (charcount2 <= 1 && CheckCollisionPointRec(GetMousePosition(), from) == false && (dp3 == "Money Range" || dp3 == "Area")) {
            DrawTextEx(coolfont, "From", Vector2{ 993, 471 }, 27, 0, WHITE);
        }
        if (searchcount <= 1 && CheckCollisionPointRec(GetMousePosition(), searchbox) == false) {
            DrawTextEx(coolfont, "Search", Vector2{ 626 + 10, 379 + 20 }, 22, 0, GRAY);
        }
    }
    void checkinputs() {
        //gets inputs into filter textboxes
        int key;
        if (dp3 == "Money Range" || dp3 == "Area") {
            if (CheckCollisionPointRec(GetMousePosition(), to)) {
                //input
                SetMouseCursor(MOUSE_CURSOR_IBEAM);
                key = GetCharPressed();

                while (key > 0) {
                    if ((key >= 32) && (key <= 125) && (charcount1 < 12)) {
                        inp1[charcount1] = (char)key;
                        inp1[charcount1 + 1] = '\0'; // Add null terminator at the end of the string.
                        charcount1++;
                    }
                    key = GetCharPressed();  // Check next character in the queue
                }
                if (IsKeyDown(KEY_BACKSPACE) && timercount % 11 == 0) {
                    charcount1--;
                    if (charcount1 < 0) charcount1 = 0;
                    inp1[charcount1] = '\0';
                }
                DrawTextEx(coolfont, inp1, Vector2{ 803, 471 }, 27, 0, BLACK);
                DrawLine(803, 498, 974, 498, BLACK);
            }
            else {
                DrawLine(803, 498, 974, 498, WHITE);
                DrawTextEx(coolfont, inp1, Vector2{ 803, 471 }, 27, 0, WHITE);
            }
            if (CheckCollisionPointRec(GetMousePosition(), from)) {

                //input
                key = GetCharPressed();

                while (key > 0) {
                    if ((key >= 32) && (key <= 125) && (charcount2 < 12)) {
                        inp2[charcount2] = (char)key;
                        inp2[charcount2 + 1] = '\0';
                        charcount2++;
                    }
                    key = GetCharPressed();
                }
                if (IsKeyDown(KEY_BACKSPACE) && timercount % 11 == 0) {
                    charcount2--;
                    if (charcount2 < 0) charcount2 = 0;
                    inp2[charcount2] = '\0';
                }
                DrawTextEx(coolfont, inp2, Vector2{ 993, 471 }, 27, 0, BLACK);
                DrawLine(993, 498, 1164, 498, BLACK);
            }
            else {
                DrawLine(993, 498, 1164, 498, WHITE);
                DrawTextEx(coolfont, inp2, Vector2{ 993, 471 }, 27, 0, WHITE);
            }

        }
        else if (dp3 == "Beds") {
            if (CheckCollisionPointRec(GetMousePosition(), to)) {
                //input
                key = GetCharPressed();
                while (key > 0) {
                    if ((key >= 32) && (key <= 125) && (charcount1 < 12)) {
                        inp1[charcount1] = (char)key;
                        inp1[charcount1 + 1] = '\0';
                        charcount1++;
                    }
                    key = GetCharPressed();
                }
                if (IsKeyDown(KEY_BACKSPACE) && timercount % 11 == 0) {
                    charcount1--;
                    if (charcount1 < 0) charcount1 = 0;
                    inp1[charcount1] = '\0';
                }
                DrawLine(803, 498, 974, 498, BLACK);
                DrawTextEx(coolfont, inp1, Vector2{ 803, 498 - 27 }, 27, 0, BLACK);
            }
            else {
                DrawLine(803, 498, 974, 498, WHITE);
                DrawTextEx(coolfont, inp1, Vector2{ 803, 498 - 27 }, 27, 0, WHITE);
            }
        }
        timercount++;
    }

    void checksearchcollision() {
        int key;
        if (CheckCollisionPointRec(GetMousePosition(), searchbut)) {
            DrawTexture(search, 1126, 392, WHITE);
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {//searchcount > 1 &&
                //char googlesearch contains values to search
                off = true;
                cout << googlesearch;
                //properties.search();-----------------------------------------------------------------------
            }
        }
        if (CheckCollisionPointRec(GetMousePosition(), searchbox)) {
            //input
            key = GetCharPressed();
            while (key > 0) {
                if ((key >= 32) && (key <= 125) && (searchcount < 40)) {
                    googlesearch[searchcount] = (char)key;
                    googlesearch[searchcount + 1] = '\0';
                    searchcount++;
                }
                key = GetCharPressed();
            }
            if (IsKeyDown(KEY_BACKSPACE) && timercount % 7 == 0) {
                searchcount--;
                if (searchcount < 0) searchcount = 0;
                googlesearch[searchcount] = '\0';
            }
        }
        DrawTextEx(coolfont, googlesearch, Vector2{ 626 + 10, 379 + 15 }, 27, 0, BLACK);
        timercount++;
    }

    bool getstatus() {
        return off;
    }
    ~mainmenuUI() {
        UnloadTexture(bg);
        UnloadTexture(search);
    }
};


class SearchResults {
public:
    int x1 = 0, x2 = 0, timercounter = 0;
    Texture2D loading = LoadTexture("./assets/loading.png");
    Texture2D tr = LoadTexture("./assets/mainmenu.png");
    Texture2D bg = LoadTexture("./assets/init.png");


    Rectangle searchbut = { 1121 , 387 , 310 , 299 };

    bool transition(bool left) {
        if (left == true) {
            if (x2 < -1440)
                return true;//transition ended
            DrawTexture(bg, 0, 0, WHITE);
            DrawTexture(tr, x2, 0, WHITE);
            x2 -= 20;
        }
        else {
            if (x2 > 1440)
                return true;//transition ended
            DrawTexture(bg, 0, 0, WHITE);
            DrawTexture(tr, x2, 0, WHITE);
            x2 += 20;
        }
    }
    void searchresults() {
        DrawTexture(bg, 0, 0, WHITE);

    }
    void displayloading() {
        if (x1 > 3720)
            x1 = 0;
        DrawTextureRec(loading, Rectangle{ (float)x1, 0, 309, 299 }, Vector2{ 565,300 }, WHITE);
        if (timercounter % 8 == 0)
            x1 += 310;
        timercounter++;
    }


    ~SearchResults() {
        UnloadTexture(loading);
    }
};
class login {
public:
    Texture2D popup = LoadTexture("./assets/login.png");
    Font coolfontL = LoadFontEx("./assets/glacial_thin.otf", 40, 0, 250);
    Font coolfontM = LoadFontEx("./assets/glacial_thin.otf", 24, 0, 250);
    Font coolfontS = LoadFontEx("./assets/glacial_thin.otf", 16, 0, 250);

    Font coolfontL2 = LoadFontEx("./assets/glacial.otf", 40, 0, 250);
    Font coolfontM2 = LoadFontEx("./assets/glacial.otf", 32, 0, 250);
    Font coolfontS2 = LoadFontEx("./assets/glacial.otf", 16, 0, 250);

    bool status = false;
    string type = "login";

    Rectangle button = { 1273,6,72,72 };
    Rectangle cancel = { 931,39,36,36 };


    Color save = { 0, 53, 102 ,255 };
    Color bg = { 173, 181, 189,255 };

    char email[30] = "\0";
    char pass[20] = "\0";
    char bogus[20] = "\0";
    char name[40] = "\0";
    char age[3] = "\0";

    int emailc = 0;
    int passc = 0;
    int namec = 0;
    int agec = 0;
    int bogusc = 0;

    int timercount = 0;

    int errortype = 0;
    int errortimer = 0;


    void buttonclick() {
        if (status == false && CheckCollisionPointRec(GetMousePosition(), button)) {
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                status = true;
                type = "login";



                strcpy_s(email, "\0");
                strcpy_s(pass, "\0");
                strcpy_s(bogus, "\0");
                strcpy_s(name, "\0");
                strcpy_s(age, "\0");

                emailc = 0;
                passc = 0;
                namec = 0;
                agec = 0;
                bogusc = 0;

                timercount = 0;

            }
        }
    }

    void displaylogin() {
        if (status == true && type == "login") {
            DrawTexture(popup, 0, 0, WHITE);
            DrawTextEx(coolfontL2, "Login", Vector2{ 542, 233 }, 40, 0, BLACK);
            DrawTextEx(coolfontM2, "Email", Vector2{ 542, 327 }, 32, 0, GRAY);
            DrawTextEx(coolfontM2, "Password", Vector2{ 542, 443 }, 32, 0, GRAY);
            DrawTextEx(coolfontS2, "Already have an Account", Vector2{ 542, 834 }, 16, 0, GRAY);
            DrawTextEx(coolfontS2, "Sign-in", Vector2{ 700, 834 }, 16, 0, SKYBLUE);

            //DrawRectangle(542, 359, 416, 50, bg);
            //DrawRectangle(542, 475, 416, 50, bg);
            //DrawRectangle(542, 750, 416, 50, save);


            DrawRectangleRounded(Rectangle{ 542, 359, 416, 50 }, 0.4, 0, bg);
            DrawRectangleRounded(Rectangle{ 542, 475, 416, 50 }, 0.4, 0, bg);
            DrawRectangleRounded(Rectangle{ 542, 750, 416, 50 }, 0.4, 0, save);

            DrawTextEx(coolfontM2, "Save", Vector2{ 710, 760 }, 32, 1, RAYWHITE);

            if (CheckCollisionPointRec(GetMousePosition(), Rectangle{ 690,832,53,26 })) {
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                    type = "signup";


                    strcpy_s(email, "\0");
                    strcpy_s(pass, "\0");
                    strcpy_s(bogus, "\0");
                    strcpy_s(name, "\0");
                    strcpy_s(age, "\0");

                    emailc = 0;
                    passc = 0;
                    namec = 0;
                    agec = 0;
                    bogusc = 0;

                }
            }
            //____________________________________________________________________________________________________
            int key, key2;
            if (CheckCollisionPointRec(GetMousePosition(), Rectangle{ 542, 359, 416, 50 })) {
                //input NAME
                key = GetCharPressed();
                while (key > 0) {
                    if ((key >= 32) && (key <= 125) && (emailc < 30)) {
                        email[emailc] = (char)key;
                        email[emailc + 1] = '\0';
                        emailc++;
                    }
                    key = GetCharPressed();
                }
                if (IsKeyDown(KEY_BACKSPACE) && timercount % 7 == 0) {
                    emailc--;
                    if (emailc < 0) emailc = 0;
                    email[emailc] = '\0';
                }
            }
            DrawTextEx(coolfontM2, email, Vector2{ 542, 359 }, 32, 0, Color{ 20, 33, 61,255 });

            //______________________________________________________________________________________________________

            if (CheckCollisionPointRec(GetMousePosition(), Rectangle{ 545, 475, 416, 50 })) {
                //input NAME
                key2 = GetCharPressed();
                while (key2 > 0) {
                    if ((key2 >= 32) && (key2 <= 125) && (passc < 20)) {
                        bogus[bogusc] = '*';
                        bogus[bogusc + 1] = '\0';
                        bogusc++;

                        pass[passc] = (char)key2;
                        pass[passc + 1] = '\0';
                        passc++;
                    }
                    key2 = GetCharPressed();
                }
                if (IsKeyDown(KEY_BACKSPACE) && timercount % 7 == 0) {
                    passc--;
                    if (passc < 0) passc = 0;
                    pass[passc] = '\0';

                    bogusc--;
                    if (bogusc < 0) bogusc = 0;
                    bogus[bogusc] = '\0';
                }
            }
            DrawTextEx(coolfontM2, bogus, Vector2{ 545, 475 }, 32, 0, Color{ 20, 33, 61,255 });

            if (CheckCollisionPointRec(GetMousePosition(), Rectangle{ 542, 750, 416, 50 })) {
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                    if (bhai.login(email, pass) == true) {
                        errortype = 2;

                    }
                    else {
                        errortype = 1;
                    }

                    errortimer = 0;
                    status = false;
                }
            }
        }
        if (CheckCollisionPointRec(GetMousePosition(), cancel)) {
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                status = false;
            }
        }
    }
    void dispsignup() {
        if (status == true && type == "signup") {
            DrawTexture(popup, 0, 0, WHITE);
            DrawTextEx(coolfontL2, "Sign up", Vector2{ 542, 233 }, 40, 0, BLACK);

            DrawTextEx(coolfontM2, "Name", Vector2{ 542, 327 }, 32, 0, GRAY);
            DrawTextEx(coolfontM2, "Age", Vector2{ 542, 427 }, 32, 0, GRAY);
            DrawTextEx(coolfontM2, "Email", Vector2{ 542, 526 }, 32, 0, GRAY);
            DrawTextEx(coolfontM2, "Password", Vector2{ 542, 626 }, 32, 0, GRAY);

            //DrawRectangle(542, 359, 416, 50, bg);
            //DrawRectangle(542, 475, 416, 50, bg);
            //DrawRectangle(542, 750, 416, 50, save);


            DrawRectangleRounded(Rectangle{ 542, 359, 416, 50 }, 0.4, 0, bg);
            DrawRectangleRounded(Rectangle{ 542, 459, 416, 50 }, 0.4, 0, bg);
            DrawRectangleRounded(Rectangle{ 542, 558, 416, 50 }, 0.4, 0, bg);
            DrawRectangleRounded(Rectangle{ 542, 658, 416, 50 }, 0.4, 0, bg);

            DrawRectangleRounded(Rectangle{ 542, 750, 416, 50 }, 0.4, 0, save);

            DrawTextEx(coolfontM2, "Save", Vector2{ 710, 760 }, 32, 1, RAYWHITE);

            int key1, key2, key3, key4;

            //____________________________________________________________________________________________________
            if (CheckCollisionPointRec(GetMousePosition(), Rectangle{ 542, 558, 416, 50 })) {
                //input NAME
                key1 = GetCharPressed();
                while (key1 > 0) {
                    if ((key1 >= 32) && (key1 <= 125) && (emailc < 30)) {
                        email[emailc] = (char)key1;
                        email[emailc + 1] = '\0';
                        emailc++;
                    }
                    key1 = GetCharPressed();
                }
                if (IsKeyDown(KEY_BACKSPACE) && timercount % 7 == 0) {
                    emailc--;
                    if (emailc < 0) emailc = 0;
                    email[emailc] = '\0';
                }
            }
            DrawTextEx(coolfontM2, email, Vector2{ 542, 558 }, 32, 0, Color{ 20, 33, 61,255 });
            //____________________________________________________________________________________________________
            if (CheckCollisionPointRec(GetMousePosition(), Rectangle{ 542, 658, 416, 50 })) {
                //input NAME
                key2 = GetCharPressed();
                while (key2 > 0) {
                    if ((key2 >= 32) && (key2 <= 125) && (passc < 20)) {
                        pass[passc] = (char)key2;
                        pass[passc + 1] = '\0';
                        passc++;
                    }
                    key2 = GetCharPressed();
                }
                if (IsKeyDown(KEY_BACKSPACE) && timercount % 7 == 0) {
                    passc--;
                    if (passc < 0) passc = 0;
                    pass[passc] = '\0';
                }
            }
            DrawTextEx(coolfontM2, pass, Vector2{ 542, 658 }, 32, 0, Color{ 20, 33, 61,255 });
            //____________________________________________________________________________________________________
            if (CheckCollisionPointRec(GetMousePosition(), Rectangle{ 542, 359, 416, 50 })) {
                //input NAME
                key3 = GetCharPressed();
                while (key3 > 0) {
                    if ((key3 >= 32) && (key3 <= 125) && (namec < 40)) {
                        name[namec] = (char)key3;
                        name[namec + 1] = '\0';
                        namec++;
                    }
                    key3 = GetCharPressed();
                }
                if (IsKeyDown(KEY_BACKSPACE) && timercount % 7 == 0) {
                    namec--;
                    if (namec < 0) namec = 0;
                    name[namec] = '\0';
                }
            }
            DrawTextEx(coolfontM2, name, Vector2{ 542, 359 }, 32, 0, Color{ 20, 33, 61,255 });
            //____________________________________________________________________________________________________
            if (CheckCollisionPointRec(GetMousePosition(), Rectangle{ 542, 459, 416, 50 })) {
                //input NAME
                key4 = GetCharPressed();
                while (key4 > 0) {
                    if ((key4 >= 32) && (key4 <= 125) && (agec < 3)) {
                        age[agec] = (char)key4;
                        age[agec + 1] = '\0';
                        agec++;
                    }
                    key4 = GetCharPressed();
                }
                if (IsKeyDown(KEY_BACKSPACE) && timercount % 7 == 0) {
                    agec--;
                    if (agec < 0) agec = 0;
                    age[agec] = '\0';
                }
            }
            DrawTextEx(coolfontM2, age, Vector2{ 542, 459 }, 32, 0, Color{ 20, 33, 61,255 });
            //____________________________________________________________________________________________________



            if (CheckCollisionPointRec(GetMousePosition(), Rectangle{ 542, 750, 416, 50 })) {
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {


                    cout << name << endl << atoi(age) << endl << "M" << endl << email << endl << pass;

                    bhai.createNewAccount(name, atoi(age), 'M', email, pass);
                    string content = "Dear " + convertToString(name);
                    content += "<br>Welcome to Revaluations<br>Regards<br>Team Revaluations";
                    bhai.sendEmail(email, "Welcome to Revaluations", content);
                    errortype = 3;
                    errortimer = 0;
                    status = false;
                }
            }


        }
        if (CheckCollisionPointRec(GetMousePosition(), cancel)) {
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                status = false;
            }
        }
    }
    void disperror() {
        if (errortype == 1 && errortimer < 250) {
            DrawRectangle(539, 13, 413, 69, Color{ 239, 35, 60 ,255 });
            DrawTextEx(coolfontM2, "Invalid Username or Password", Vector2{ 539 + 10, 25 }, 32, 0, WHITE);
            errortimer++;
        }
        else if (errortype == 2 && errortimer < 250) {
            DrawRectangle(539, 13, 413, 69, Color{ 67, 97, 238,255 });
            DrawTextEx(coolfontM2, "Login Succesful", Vector2{ 539 + 10, 25 }, 32, 0, WHITE);
            errortimer++;
        }
        else if (errortype == 3 && errortimer < 250) {
            DrawRectangle(539, 13, 413, 69, Color{ 114, 9, 183 ,255 });
            DrawTextEx(coolfontM2, "Account Succesfully Created", Vector2{ 539 + 10, 25 }, 32, 0, WHITE);
            errortimer++;
        }
        if (errortimer > 250) {
            errortype = 0;
        }
    }

};




int main() {

    int w = 1440, h = 900;
    InitWindow(w, h, "Revaluations");   //  w = 1440,  h = 900

    //-----------------------
    initUI ui;
    mainmenuUI menuUi;
    SearchResults searchRes;
    Properties holder;
    login loginUi;

    properties.readCSV();



    //-----------------------
    Texture2D men = LoadTexture("./assets/mainmenu.png");
    Texture2D row = LoadTexture("./assets/row.png");
    Texture2D row_selected = LoadTexture("./assets/row_selected.png");
    Texture2D bg = LoadTexture("./assets/init.png");
    Texture2D bgback = LoadTexture("./assets/init3.png");
    Texture2D house = LoadTexture("./assets/houseImages.png");
    Image temp = LoadImage("./assets/houseanim.png");
    ImageResize(&temp, 3200, 150);
    Texture2D houseanim = LoadTextureFromImage(temp);
    Texture2D popupwindow = LoadTexture("./assets/popup.png");





    Font coolfontL = LoadFontEx("./assets/glacial_thin.otf", 40, 0, 250);
    Font coolfontM = LoadFontEx("./assets/glacial_thin.otf", 24, 0, 250);
    Font coolfontS = LoadFontEx("./assets/glacial_thin.otf", 16, 0, 250);

    Font coolfontL2 = LoadFontEx("./assets/glacial.otf", 40, 0, 250);
    Font coolfontM2 = LoadFontEx("./assets/glacial.otf", 24, 0, 250);
    Font coolfontS2 = LoadFontEx("./assets/glacial.otf", 16, 0, 250);


    Image analysis1;
    Image analysis2;
    Image analysis3;
    Image analysis4;
    Image analysis5;
    Image analysis6;


    Texture2D img1;
    Texture2D img2;
    Texture2D img3;
    Texture2D img4;
    Texture2D img5;
    Texture2D img6;

    bool initialisemldata = true;
    //-----------------------

    SetTargetFPS(120);


    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(YELLOW);

        if (ui.off == false) {
            ui.startup();
            if (initialisemldata == true && ui.off == true) {

                string content = "<!DOCTYPE html><html><title>REVALUATIONS</title><head></head><body background-color: #DBF9FC;><h1>PROMOTION OFFER</h1><div style=\"font-family:verdana\">All new users are now being informed that a large amount of real estate all around country has been displayed on our app. </div><br><a href=\"\"><img src=\"https://cdn.searchenginejournal.com/wp-content/uploads/2022/06/1600-x-840-px-629f6c69d3f26-sej-1520x800.png\" alt= alt=\"centered image\"  style=\"width:420px;height:420px;\"></a><br><h3>\"Come fast and get hold of your dream Home\"</h3><h4> Your Sincerly,</h4><h4> Revaluation Team.</h4></body></html>";
                bhai.sendEmailToAll("Revaluations - Promotion Offer", content);
                properties.generateGraphs(2017);
                analysis1 = LoadImage("./python-graphs/plot1.png");
                properties.generateGraphs(2018);
                analysis2 = LoadImage("./python-graphs/plot1.png");
                properties.generateGraphs(2019);
                analysis3 = LoadImage("./python-graphs/plot1.png");
                properties.generateGraphs(2020);
                analysis4 = LoadImage("./python-graphs/plot1.png");
                properties.generateGraphs(2021);
                analysis5 = LoadImage("./python-graphs/plot1.png");
                properties.generateGraphs(2022);
                analysis6 = LoadImage("./python-graphs/plot1.png");

                ImageResize(&analysis1, 280, 280);
                ImageResize(&analysis2, 280, 280);
                ImageResize(&analysis3, 280, 280);
                ImageResize(&analysis4, 280, 280);
                ImageResize(&analysis5, 280, 280);
                ImageResize(&analysis6, 280, 280);

                img1 = LoadTextureFromImage(analysis1);
                img2 = LoadTextureFromImage(analysis2);
                img3 = LoadTextureFromImage(analysis3);
                img4 = LoadTextureFromImage(analysis4);
                img5 = LoadTextureFromImage(analysis5);
                img6 = LoadTextureFromImage(analysis6);



                initialisemldata = false;
            }

        }
        else if (menuUi.off == false && holder.off == true && ui.off == true) {
            DrawTexture(men, 0, 0, WHITE);
            if (loginUi.status == false)
                menuUi.display();

            if (menuUi.off == true) {
                holder.off = false;
                cout << menuUi.dp1 << menuUi.dp2 << menuUi.dp3;
            }
            loginUi.buttonclick();
            loginUi.displaylogin();
            loginUi.dispsignup();
            loginUi.disperror();


        }
        else if (menuUi.off == true && holder.off == false) {
            holder.off = false;

            if (menuUi.dp1 == "City" && menuUi.dp2 == "Type" && menuUi.dp3 == "Filter") {
                cout << menuUi.dp1 << menuUi.dp2 << menuUi.dp3;
                holder.assignvals(properties);
                holder.display(row, bgback, house, row_selected, coolfontL, coolfontM, coolfontS, houseanim, popupwindow, coolfontL2, coolfontM2, coolfontS2, img6, img5, img4, img3, img2, img1, bhai);
            }
            else if (menuUi.dp1 != "City" && menuUi.dp1 != "Select") {
                holder.assignvals(properties.filterByCity(menuUi.dp1));
                holder.display(row, bgback, house, row_selected, coolfontL, coolfontM, coolfontS, houseanim, popupwindow, coolfontL2, coolfontM2, coolfontS2, img6, img5, img4, img3, img2, img1, bhai);
            }
            else if (menuUi.dp2 != "Type" && menuUi.dp1 != "Select") {
                holder.assignvals(properties.filterByType(menuUi.dp2));
                holder.display(row, bgback, house, row_selected, coolfontL, coolfontM, coolfontS, houseanim, popupwindow, coolfontL2, coolfontM2, coolfontS2, img6, img5, img4, img3, img2, img1, bhai);
            }
            else if (menuUi.dp2 != "Filter" && menuUi.dp1 != "Select") {
                if (menuUi.dp3 == "Money Range") {
                    //cout << stold(menuUi.inp2) << "\t" << stold(menuUi.inp1)<<"\n";
                    //stold(menuUi.inp2), stold(menuUi.inp1)
                    holder.assignvals(properties.filterByPrice(stold(menuUi.inp2), stold(menuUi.inp1)));
                    holder.display(row, bgback, house, row_selected, coolfontL, coolfontM, coolfontS, houseanim, popupwindow, coolfontL2, coolfontM2, coolfontS2, img6, img5, img4, img3, img2, img1, bhai);
                }
                else if (menuUi.dp3 == "Area") {
                    holder.assignvals(properties.filterByArea(stold(menuUi.inp2), stold(menuUi.inp1)));
                    holder.display(row, bgback, house, row_selected, coolfontL, coolfontM, coolfontS, houseanim, popupwindow, coolfontL2, coolfontM2, coolfontS2, img6, img5, img4, img3, img2, img1, bhai);
                }
                else if (menuUi.dp3 == "Beds") {
                    holder.assignvals(properties.filterByBeds(stoi(menuUi.inp1)));
                    holder.display(row, bgback, house, row_selected, coolfontL, coolfontM, coolfontS, houseanim, popupwindow, coolfontL2, coolfontM2, coolfontS2, img6, img5, img4, img3, img2, img1, bhai);
                }
                //holder.assignvals(properties.filterByType(menuUi.dp2));
                //holder.display(row, bg, house, coolfontL, coolfontM, coolfontS);
            }


            if (holder.getstatus() == true) {
                menuUi.off = false;

                holder.head = NULL;
                holder.tail = NULL;

                menuUi.dp1 = "City";
                menuUi.dp2 = "Type";
                menuUi.dp3 = "Filter";


            }

        }

        //DrawTexture(houseanim, 0, 0, WHITE);

        /*holder.assignvals(properties.searchByCity("Lahore"));
        holder.display(row, bg, house, coolfontL, coolfontM, coolfontS);*/
        //}

        //else if(searchRes.transition(1) == true && menuUi.off==true)
            //properties.display(row, bg, house, coolfontL, coolfontM, coolfontS);
            //searchRes.displayloading();
        //if (searchRes.transition(1) == true) {

        //}

        EndDrawing();
    }
    CloseWindow();
    return 0;
}