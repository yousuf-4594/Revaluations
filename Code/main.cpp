// Compile using:  g++ -std=c++11 main.cpp -o main.exe && ./main.exe

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
#include <windows.h>
#include <ctype.h>
#include <iomanip>
#include <cwchar>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <stdexcept>
using namespace std;

string convertToString(char *);
void aboutUs();
int mainMenu();
void box();
void FontSize(int, int);
void currentDateAndTime();
void TextColor(int);
void loadingAnimation();
void CursorPosition(int, int);
void generateReport(string);

class Property
{
    // Node for CDLL
public:
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
    Property *next;
    Property *prev;

    Property();
    Property(long long int, long int, string, string, long long int, string, string, string, string, string, long double, long double, int, string, float, long double, string, int, string, int, int, int);
    void print();
};

class Properties
{
    // SDLL
private:
    Property *head;
    Property *tail;

public:
    Properties();
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
    // void buy();
    void sellProperty(int, string);
    void deleteFirstNode();
    void deleteLastNode();
    void deleteNode(int);
    int partition(Property *, int, int);
    void quickSort(Property *, int, int);
    Properties sort(string);
    Properties filterByPrice(long long int, long long int);
    Properties filterByArea(long double, long double);
    Properties filterByBeds(int);
    Properties filterByType(string);
    Properties filterByCity(string);
    long long int predictPrice(string, string, int, long double, int, int);
    void generateGraphs(int);
};
Properties properties;

class User
{
protected:
    int accountNumber;
    char name[40];
    int age;
    char gender;
    char email[30];
    char password[20];
    virtual int generateAccountNumber() = 0;
    void inputPassword(char[20]);

public:
    virtual void createNewAccount(char [20], int, char, char [30], char[20]) = 0;
    void setName();
    void setGender();
    void setEmail();
    void setPassword();
    char *getName();
    int getAccountNumber();
    char getGender();
    int getAge();
    char *getEmail();
    virtual void storeData() = 0;
    void readData();
    void setAge();
    virtual bool login(char [30], char [20]) = 0;
    virtual void viewMyInfo() = 0;
    virtual void portal() = 0;
    virtual int portalMenu() = 0;
    virtual void deleteAccount() = 0;
    virtual void accountSetting() = 0;
    virtual void updateEmail(int) = 0;
    virtual void updateInfo(int) = 0;
    virtual void updateContactNumber(int) = 0;
    virtual void changePassword(int) = 0;
};

class Customer : public User
{
private:
    int generateAccountNumber();

public:
    void createNewAccount(char [20], int, char, char [30], char[20]);
    void viewTransactionHistory();
    bool login(char [30], char [20]);
    void viewMyInfo();
    void portal();
    int portalMenu();
    void storeData();
    void deleteAccount();
    void accountSetting();
    void updateEmail(int);
    void updateInfo(int);
    void updateContactNumber(int);
    void changePassword(int);
    void addData();
    void buy(int);
    void sendEmailToAll(string, string);
    void sendEmail(string, string, string);
};

class Stack{
    private:
        Property *top;
    public:
        Stack();
        bool isEmpty();
        void push(Property *p);
        void pop();
        Property *peek();


};

class EmailNode{
    public:
        int accountNumber;
        string name;
        string email;
        EmailNode *next;

        EmailNode(int, string, string);
};


class EmailQueue{
    private:
        EmailNode *front;
        EmailNode *rear;
    public:
        EmailQueue();
        bool isEmpty();
        void enqueue(int, string, string);
        void dequeue();
        EmailNode * getFront();
        string getFrontEmail();
        void sendEmailToAll();
        void printQueue();
};

int main()
{
    int mainMenuChoice;
    properties.readCSV();
    // cout << properties.predictPrice("Flat", "Lahore", 2, 2800, 3, 2021);
    // properties.generateGraphs(2019);
    Customer customer;
    string subject = "FAST Properties - Automated Email";
    string content = "Dear User,<br>This is an automated email for testing purpose<br>Regards,<br>Sufiyaan Usmani";
    // customer.sendEmail("k213195@nu.edu.pk", "Subject", "This is a content");
    // customer.sendEmailToAll(subject, content);
    // generateReport("properties");
    // properties.sort("descending");
    // properties.filterByPrice(10000, 5000000);
    // properties.filterByBeds(2);
    // properties.filterByCity("Lahore");
    // getch();
    // init();
    while (1)
    {
        system("cls");
        mainMenuChoice = mainMenu();
        switch (mainMenuChoice)
        {
        case 1:
            system("cls");
            system("title Search");
            properties.search();
            break;
        case 2:
            system("cls");
            system("title Properties");
            properties.print();
            break;
        case 3:
            system("cls");
            system("title Predict");
            // properties.predict();
            break;
        case 4:
            system("cls");
            system("title Login as user");
            cout << customer.login("k213195@nu.edu.pk", "sufiyaan");
            getch();
            break;
        case 5:
            system("cls");
            system("title Login as admin");
            // admin.login();
        case 6:
            system("cls");
            system("title Create new account");
            break;
        case 7:
            system("cls");
            system("title About us");
            aboutUs();
            break;
        case 8:
            system("cls");
            CursorPosition(40, 10);
            system("title Good Bye");
            box();
            // Sleep(2000);
            TextColor(7);
            exit(0);
            break;
        default:
            system("cls");
            system("title ERROR :(");
            CursorPosition(0, 0);
            system("color 4F");
            cout << "Wrong choice entered, try again!";
            Beep(1000, 300);
            Sleep(2000);
            system("color 0F");
            break;
        }
    }
    return 0;
}

string convertToString(char *a)
{
    string s = a;
    return s;
}

void CursorPosition(int x, int y)
{

    COORD c;
    c.X = x;
    c.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void loadingAnimation()
{
    int i;
    system("cls");
    system("color 0A");
    CursorPosition(56, 10);
    cout << "Loading";
    CursorPosition(40, 12);
    printf("[");
    CursorPosition(78, 12);
    printf("]");
    CursorPosition(41, 12);
    for (i = 1; i <= 37; i++)
    {
        printf("%c", 177);
    }
    CursorPosition(41, 12);
    for (i = 1; i <= 37; i++)
    {
        Sleep(30);
        printf("%c", 219);
    }
    CursorPosition(0, 0);
    system("cls");
    system("color 0F");
}

void TextColor(int ForgC)
{
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    // We use csbi for the wAttributes word.
    if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        // Mask out all but the background attribute, and add in the forgournd     color
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
}

void currentDateAndTime()
{
    time_t t; // not a primitive datatype
    time(&t);

    cout << ctime(&t);
}

void FontSize(int x, int y)
{

    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = x; // Width of each character in the font
    cfi.dwFontSize.Y = y; // Height
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = 700;                  // For normal: FW_NORMAL
    std::wcscpy(cfi.FaceName, L"Courier"); // Choose your font
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}

void box()
{
    CursorPosition(40, 7);
    TextColor(1);
    for (int i = 0; i < 40; i++)
        cout << "-";
    TextColor(2);
    CursorPosition(44, 13);
    cout << "ThankYou for using Our Service:)";
    TextColor(1);
    for (int i = 0; i < 11; i++)
    {
        CursorPosition(39, 8 + i);
        cout << "|\n";
    }
    CursorPosition(40, 19);
    for (int i = 0; i < 40; i++)
        cout << "-";
    for (int i = 0; i < 11; i++)
    {
        CursorPosition(80, 8 + i);
        cout << "|\n";
    }
    cout << endl;
}

int mainMenu()
{
    int choice, i;
    char ch;
    system("color 0F");
    system("cls");
    system("title FAST PROPERTIES - MAIN MENU");
    CursorPosition(0, 0);
    TextColor(10);
    currentDateAndTime();
    CursorPosition(32, 3);
    FontSize(0, 21);
    TextColor(11);
    cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 FAST PROPERTIES \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
    for (i = 1; i <= 10; i++)
    {
        CursorPosition(31, 3 + i);
        printf("|");
    }
    for (i = 1; i <= 10; i++)
    {
        CursorPosition(91, 3 + i);
        printf("|");
    }
    for (i = 1; i <= 60; i++)
    {
        CursorPosition(31 + i, 14);
        printf("-");
    }
    TextColor(15);
    CursorPosition(33, 5);
    cout << "1. Search";
    CursorPosition(33, 6);
    cout << "2. View all properties";
    CursorPosition(33, 7);
    cout << "3. Predict Price";
    CursorPosition(33, 8);
    cout << "4. Login as user";
    CursorPosition(33, 9);
    cout << "5. Login as admin";
    CursorPosition(33, 10);
    cout << "6. Create new account";
    CursorPosition(33, 11);
    cout << "7. About Us";
    CursorPosition(33, 12);
    cout << "8. Exit";
    CursorPosition(32, 15);
    cout << "Enter your choice: ";
    fflush(stdin);
    i = 0;
    while (1)
    {
        ch = getch();
        if (ch >= '1' && ch <= '9' && i == 0)
        {
            cout << ch;
            choice = ch - '0';
            i++;
        }
        else if (ch == 13 && i == 1)
        {
            break;
        }
        else if (ch == 8 && i != 0)
        {
            i--;
            cout << "\b \b";
        }
    }
    return choice;
}

void aboutUs()
{
    system("cls");
    int j;
    for (j = 21; j >= 0; j--)
    {
        if (j == 21)
        {
            system("color 01");
        }
        if (j == 19)
        {
            system("color 02");
        }
        if (j == 18)
        {
            system("color 03");
        }
        if (j == 17)
        {
            system("color 04");
        }
        if (j == 16)
        {
            system("color 05");
        }
        if (j == 15)
        {
            system("color 06");
        }
        if (j == 14)
        {
            system("color 07");
        }
        if (j == 13)
        {
            system("color 08");
        }
        if (j == 12)
        {
            system("color 09");
        }
        if (j == 11)
        {
            system("color 0A");
        }
        if (j == 10)
        {
            system("color 0B");
        }
        if (j == 9)
        {
            system("color 0C");
        }
        if (j == 8)
        {
            system("color 0D");
        }
        if (j == 7)
        {
            system("color 0E");
        }
        if (j == 6)
        {
            system("color 0F");
        }
        if (j == 5)
        {
            system("color 01");
        }
        if (j == 4)
        {
            system("color 02");
        }
        if (j == 3)
        {
            system("color 03");
        }
        if (j == 2)
        {
            system("color 0C");
        }
        if (j == 1)
        {
            system("color 0E");
        }
        if (j == 0)
        {
            system("color 0F");
        }
        system("cls");
        CursorPosition(46, j - 1);
        printf("THIS SYSTEM IS DESIGNED BY");
        CursorPosition(46, j + 1);
        printf("Sufiyaan Usmani  (21K-3195)");
        CursorPosition(46, j + 2);
        printf("Yousuf Ahmed     (21K-4594)");
        CursorPosition(46, j + 3);
        printf("Qasim Hasan      (21K-3210)");
        CursorPosition(0, 0);
        Sleep(600);
    }
}

// PROPERTY

Property::Property(){
    next = prev = NULL;
}

Property::Property(long long int propertyID, long int locationID, string pageUrl, string propertyType, long long int price, string priceType, string location, string city, string province, string locality, long double latitude, long double longitude, int baths, string area, float areaMarla, long double areaSqft, string purpose, int bedrooms, string dateAdded, int year, int month, int day)
{
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
}

void Property::print()
{
    cout << setw(7) << propertyType << "  " << setw(12) << price << "  " << setw(40) << location << "  " << setw(10) << city << "  " << setw(10) << province << "  " << setw(10) << areaSqft << "  " << setw(10) << purpose << "  " << dateAdded << endl;
}

// PROPERTIES

Properties::Properties()
{
    head = tail = NULL;
}

bool Properties::isEmpty()
{
    if (head == NULL && tail == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Properties::append(long long int propertyID, long int locationID, string pageUrl, string propertyType, long long int price, string priceType, string location, string city, string province, string locality, long double latitude, long double longitude, int baths, string area, float areaMarla, long double areaSqft, string purpose, int bedrooms, string dateAdded, int year, int month, int day)
{
    Property *n = new Property(propertyID, locationID, pageUrl, propertyType, price, priceType, location, city, province, locality, latitude, longitude, baths, area, areaMarla, areaSqft, purpose, bedrooms, dateAdded, year, month, day);
    if (isEmpty())
    {
        head = tail = n;
    }
    else
    {
        n->next = head;
        n->prev = tail;
        tail->next = n;
        head->prev = n;
        tail = n;
    }
}

void Properties::prepend(long long int propertyID, long int locationID, string pageUrl, string propertyType, long long int price, string priceType, string location, string city, string province, string locality, long double latitude, long double longitude, int baths, string area, float areaMarla, long double areaSqft, string purpose, int bedrooms, string dateAdded, int year, int month, int day)
{
    Property *n = new Property(propertyID, locationID, pageUrl, propertyType, price, priceType, location, city, province, locality, latitude, longitude, baths, area, areaMarla, areaSqft, purpose, bedrooms, dateAdded, year, month, day);
    if (isEmpty())
    {
        head = tail = n;
    }
    else
    {
        n->next = head;
        n->prev = tail;
        tail->next = n;
        head->prev = n;
        head = n;
    }
}

void Properties::print()
{
    if (isEmpty())
    {
        cout << "No properties" << endl;
    }
    else
    {
        Property *temp = head;
        do
        {
            temp->print();
            temp = temp->next;
        } while (temp != head);
    }
}

int Properties::count()
{
    int count = 0;
    if (!isEmpty())
    {
        Property *temp = head;
        do
        {
            count++;
            temp = temp->next;
        } while (temp != head);
    }
    return count;
}

void Properties::readCSV()
{
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
    if (file.is_open())
    {
        while (getline(file, line))
        {
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

    for (int i = 1; i < content.size(); i++)
    {
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

void Properties::search(){
    int choice, propID;
    string str;
    while(1){
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
        if(choice == 1){
            cout << "Enter city: ";
            getline(cin, str);
            searchByCity(str);
        }else if(choice == 2){
            cout << "Enter province: ";
            getline(cin, str);
            searchByProvince(str);
        }else if(choice == 3){
            cout << "Enter property ID: ";
            cin >> propID;
            searchByPropertyID(propID);
        }else if(choice == 4){
            loadingAnimation();
            break;
        }else{
            cout << "Wrong choice entered, please enter a correct choice" << endl;
            Sleep(1000);
        }
    }
    
}

Properties Properties::searchByCity(string city){
    // Linear Search
    Property *p = head;
    Properties temp;
    do{
        if(p->city == city){
            temp.append(p->propertyID, p->locationID, p->pageUrl, p->propertyType, p->price, p->priceType, p->location, p->city, p->province, p->locality, p->latitude, p->longitude, p->baths, p->area, p->areaMarla, p->areaSqft, p->purpose, p->bedrooms, p->dateAdded, p->year, p->month, p->day);
        }
        p = p->next;
    }while(p != head);
    return temp;
}

Properties Properties::searchByProvince(string province){
    // Linear Search
    Property *p = head;
    Properties temp;
    do{
        if(p->province == province){
            temp.append(p->propertyID, p->locationID, p->pageUrl, p->propertyType, p->price, p->priceType, p->location, p->city, p->province, p->locality, p->latitude, p->longitude, p->baths, p->area, p->areaMarla, p->areaSqft, p->purpose, p->bedrooms, p->dateAdded, p->year, p->month, p->day);
        }
        p = p->next;
    }while(p != head);
    return temp;
}

Properties Properties::searchByPropertyID(int ID){
    // Linear Search
    Property *p = head;
    Properties temp;
    do{
        if(p->propertyID == ID){
            temp.append(p->propertyID, p->locationID, p->pageUrl, p->propertyType, p->price, p->priceType, p->location, p->city, p->province, p->locality, p->latitude, p->longitude, p->baths, p->area, p->areaMarla, p->areaSqft, p->purpose, p->bedrooms, p->dateAdded, p->year, p->month, p->day);
            break;
        }
        p = p->next;
    }while(p != head);
    return temp;
}

bool Properties::propertyExists(int ID){
    Property *p = head;
    do{
        if(p->propertyID == ID){
            return true;
        }
        p = p->next;
    }while(p != head);
    return false;
}


void Properties::sellProperty(int propID, string name){
     // Open File pointers
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
    while(getline(first, word, ',')){
        row.push_back(word);
    }
    int first_size = row.size();
    for(int i=0;i<first_size - 1;i++){
        fout << row[i] << ",";
    }
    fout << row[first_size-1] << "\n";
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
            for(int i=0;i<row_size;i++){
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

void Properties::deleteNode(int propID){
    if(isEmpty()){
        return;
    }else{
        if(head->propertyID == propID){
            deleteFirstNode();
        }else{
            Property *temp = head;
            do{
                temp = temp->next;
            }while(temp != head && temp->propertyID != propID);
            if(temp->propertyID == propID){
                if(temp == tail){
                    deleteLastNode();
                }else{
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    delete temp;
                }
            }
        }
    }
}

void Properties::deleteFirstNode(){
    if(isEmpty()){
        return;
    }else{
        if(head == tail){
            delete head;
            head = tail = NULL;
        }else{
            Property *temp = head;
            head = head->next;
            tail->next = head;
            head->prev = tail;
            delete temp;
        }
    }
}

void Properties::deleteLastNode(){
    if(isEmpty()){
        return;
    }else{
        if(head == tail){
            delete head;
            head = tail = NULL;
        }else{
            Property *temp = tail;
            tail = tail->prev;
            tail->next = head;
            head->prev = tail;
            delete temp;
        }
    }
}

Properties Properties::sort(string type){
    Properties sorted;
    int n = count();
    Property *arr = new Property[n];
    Property *temp = head;
    for(int i=0;i<n;i++){
        arr[i] = *temp;
        temp = temp->next;
    }
    quickSort(arr, 0, n-1);
    for(int i=0;i<n;i++){
        if(type == "descending"){
            sorted.append(arr[i].propertyID, arr[i].locationID, arr[i].pageUrl, arr[i].propertyType, arr[i].price, arr[i].priceType, arr[i].location, arr[i].city, arr[i].province, arr[i].locality, arr[i].latitude, arr[i].longitude, arr[i].baths, arr[i].area, arr[i].areaMarla, arr[i].areaSqft, arr[i].purpose, arr[i].bedrooms, arr[i].dateAdded, arr[i].year, arr[i].month, arr[i].day);
        }else{
            sorted.prepend(arr[i].propertyID, arr[i].locationID, arr[i].pageUrl, arr[i].propertyType, arr[i].price, arr[i].priceType, arr[i].location, arr[i].city, arr[i].province, arr[i].locality, arr[i].latitude, arr[i].longitude, arr[i].baths, arr[i].area, arr[i].areaMarla, arr[i].areaSqft, arr[i].purpose, arr[i].bedrooms, arr[i].dateAdded, arr[i].year, arr[i].month, arr[i].day);
        }
    }
    delete[] arr;
    return sorted;
}

void Properties::quickSort(Property *arr, int low, int high)
{
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

int Properties::partition(Property *arr, int low, int high)
{
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
    temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

Properties Properties::filterByPrice(long long int from, long long int to){
    Property *temp = head;
    Properties filter;
    do{
        if(temp->price >= from && temp->price <= to){
            filter.append(temp->propertyID, temp->locationID, temp->pageUrl, temp->propertyType, temp->price, temp->priceType, temp->location, temp->city, temp->province, temp->locality, temp->latitude, temp->longitude, temp->baths, temp->area, temp->areaMarla, temp->areaSqft, temp->purpose, temp->bedrooms, temp->dateAdded, temp->year, temp->month, temp->day);
        }
        temp = temp->next;
    }while(temp != head);
    return filter;
}

Properties Properties::filterByArea(long double from, long double to){
    Property *temp = head;
    Properties filter;
    do{
        if(temp->areaSqft >= from && temp->areaSqft <= to){
            filter.append(temp->propertyID, temp->locationID, temp->pageUrl, temp->propertyType, temp->price, temp->priceType, temp->location, temp->city, temp->province, temp->locality, temp->latitude, temp->longitude, temp->baths, temp->area, temp->areaMarla, temp->areaSqft, temp->purpose, temp->bedrooms, temp->dateAdded, temp->year, temp->month, temp->day);
        }
        temp = temp->next;
    }while(temp != head);
    return filter;
}

Properties Properties::filterByBeds(int beds){
    Property *temp = head;
    Properties filter;
    do{
        if(temp->bedrooms == beds){
            filter.append(temp->propertyID, temp->locationID, temp->pageUrl, temp->propertyType, temp->price, temp->priceType, temp->location, temp->city, temp->province, temp->locality, temp->latitude, temp->longitude, temp->baths, temp->area, temp->areaMarla, temp->areaSqft, temp->purpose, temp->bedrooms, temp->dateAdded, temp->year, temp->month, temp->day);
        }
        temp = temp->next;
    }while(temp != head);
    return filter;
}

Properties Properties::filterByType(string type){
    Property *temp = head;
    Properties filter;
    do{
        if(temp->propertyType == type){
            filter.append(temp->propertyID, temp->locationID, temp->pageUrl, temp->propertyType, temp->price, temp->priceType, temp->location, temp->city, temp->province, temp->locality, temp->latitude, temp->longitude, temp->baths, temp->area, temp->areaMarla, temp->areaSqft, temp->purpose, temp->bedrooms, temp->dateAdded, temp->year, temp->month, temp->day);
        }
        temp = temp->next;
    }while(temp != head);
    return filter;
}

Properties Properties::filterByCity(string city){
    Property *temp = head;
    Properties filter;
    do{
        if(temp->city == city){
            filter.append(temp->propertyID, temp->locationID, temp->pageUrl, temp->propertyType, temp->price, temp->priceType, temp->location, temp->city, temp->province, temp->locality, temp->latitude, temp->longitude, temp->baths, temp->area, temp->areaMarla, temp->areaSqft, temp->purpose, temp->bedrooms, temp->dateAdded, temp->year, temp->month, temp->day);
        }
        temp = temp->next;
    }while(temp != head);
    return filter;
}

long long int Properties::predictPrice(string propertyType, string city, int baths, long double area, int bedrooms, int year){
    Properties searched = searchByCity(city);
    int propType, c;

    // storing data in csv file
    fstream fout;
    fout.open("./python-predict/data.csv", ios::out);
    fout << "property_type,price,city,bath,area_sqft,bedrooms,year" << endl;
    Property *temp = searched.head;
    do{
        propType = 1;   // house
        if(temp->propertyType == "Flat"){
            propType = 2;
        }
        if(temp->city == "Karachi"){
            c = 1;
        }else if(temp->city == "Lahore"){
            c = 2;
        }
        fout << propType << "," << temp->price << "," << c << "," << temp->baths << "," << temp->areaSqft << "," << temp->bedrooms << "," << temp->year << endl;
        temp = temp->next;
    }while(temp != searched.head);
    fout.close();

    // calling python program to do prediction
    propType = 1;   // house
    if(propertyType == "Flat"){
        propType = 2;
    }
    if(city == "Karachi"){
        c = 1;
    }else if(city == "Lahore"){
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

void Properties::generateGraphs(int year){
    fstream fout;
    fout.open("./python-graphs/data.csv", ios::out);
    fout << "property_type,price,city,bath,area_sqft,bedrooms,year,month,price_type" << endl;
    Property *temp = head;
    do{
        if(temp->year == year){
            fout << temp->propertyType << "," << temp->price << "," <<  temp->city << "," << temp->baths << "," << temp->areaSqft << "," << temp->bedrooms << "," << temp->year << "," << temp->month << "," << temp->priceType << endl;
        }
        temp = temp->next;
    }while(temp != head);
    fout.close();

    system("python ./python-graphs/app.py");
}

// USER

void User::setName()
{
    char ch;
    int i, backspaceCount;
    backspaceCount = i = 0;
    cout << "Enter your full name: ";
    while (1)
    {
        ch = getch();
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch == 32))
        {
            this->name[i] = ch;
            cout << ch;
            i++;
            backspaceCount++;
        }
        else if (ch == 8 && backspaceCount > 0)
        {
            cout << "\b \b";
            i--;
            backspaceCount--;
        }
        else if (ch == 13)
        {
            break;
        }
    }
    this->name[i] = '\0';
}

void User::setAge()
{
    char ch, a[3];
    int i, backspaceCount;
    backspaceCount = i = 0;
    cout << "Enter your age : ";
    while (1)
    {
        ch = getch();
        if (ch >= '0' && ch <= '9')
        {
            a[i] = ch;
            cout << ch;
            i++;
            backspaceCount++;
        }
        else if (ch == 8 && backspaceCount > 0)
        {
            cout << "\b \b";
            i--;
            backspaceCount--;
        }
        else if (ch == 13 && i == 2)
        {
            break;
        }
    }
    a[3] = '\0';
    this->age = ((a[0] - 48) * 10) + (a[1] - 48);
    if (this->age < 18)
    {
        TextColor(4);
        cout << "\n\t\t\t\t\tAge must be greater than or equal to 18" << endl;
        TextColor(7);
        setAge();
    }
}

void User::setGender()
{
    char ch;
    cout << "Enter your gender (m:male, f:female): ";
    while (1)
    {
        ch = getch();
        if (ch == 'm' || ch == 'f')
        {
            this->gender = ch;
            cout << ch;
            break;
        }
    }
}

void User::setEmail()
{
    char ch;
    int i, backspaceCount;
    backspaceCount = i = 0;
    cout << "Enter your email: ";
    while (1)
    {
        ch = getch();
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch == 32) || (ch == '@') || (ch == '.') || (ch >= '0' && ch <= '9'))
        {
            this->email[i] = ch;
            cout << ch;
            i++;
            backspaceCount++;
        }
        else if (ch == 8 && backspaceCount > 0)
        {
            cout << "\b \b";
            i--;
            backspaceCount--;
        }
        else if (ch == 13)
        {
            break;
        }
    }
    this->email[i] = '\0';
}

void User::setPassword()
{
    char ch;
    int i, backspaceCount;
    backspaceCount = i = 0;
    cout << "Enter your password: ";
    TextColor(4);
    while (1)
    {
        ch = getch();
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch == 32) || (ch == '@') || (ch == '.') || (ch >= '0' && ch <= '9'))
        {
            this->password[i] = ch;
            cout << '*';
            i++;
            backspaceCount++;
        }
        else if (ch == 8 && backspaceCount > 0)
        {
            cout << "\b \b";
            i--;
            backspaceCount--;
        }
        else if (ch == 13)
        {
            break;
        }
    }
    this->password[i] = '\0';
    TextColor(15);
}

void User::readData()
{
    ifstream fin;
    system("cls");
    fin.open("./data/customer.bank", ios::in | ios::binary);
    fin.read((char *)this, sizeof(*this));
    while (fin.eof() == 0)
    {
        cout << "Acc No: " << this->accountNumber << endl;
        cout << "Name: " << this->name << endl;
        cout << "Email: " << this->email << endl;
        cout << endl;
        fin.read((char *)this, sizeof(*this));
    }
    fin.close();
}

void User::inputPassword(char pass[20])
{
    char ch;
    int i, backspaceCount;
    backspaceCount = i = 0;
    TextColor(4);
    while (1)
    {
        ch = getch();
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch == 32) || (ch == '@') || (ch == '.') || (ch >= '0' && ch <= '9'))
        {
            pass[i] = ch;
            cout << '*';
            i++;
            backspaceCount++;
        }
        else if (ch == 8 && backspaceCount > 0)
        {
            cout << "\b \b";
            i--;
            backspaceCount--;
        }
        else if (ch == 13)
        {
            break;
        }
    }
    TextColor(15);
    pass[i] = '\0';
}

int User::getAccountNumber()
{
    return accountNumber;
}

char *User::getName()
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

char *User::getEmail()
{
    return email;
}

// CUSTOMER

void Customer::createNewAccount(char n[20], int age, char gender, char e[30], char p[20])
{
    Customer c;
    c.accountNumber = c.generateAccountNumber();
    strcpy(c.name, n);
    c.age = age;
    c.gender = gender;
    strcpy(c.email, e);
    strcpy(c.password, p);
    c.storeData();
}

int Customer::generateAccountNumber()
{
    ifstream fin;
    int num;
    bool isFound = false;
    srand(time(0));
    fin.open("./data/customer.bank", ios::in | ios::binary);
    if (!fin)
    {
        perror("Error");
        Sleep(2000);
        exit(1);
    }
    else
    {
        while (1)
        {
            num = (rand() % 10000) + 100000;
            fin.read((char *)this, sizeof(*this));
            while (fin.eof() == 0)
            {
                if (this->accountNumber == num)
                {
                    isFound = true;
                    break;
                }
                fin.read((char *)this, sizeof(*this));
            }
            if (isFound == false)
            {
                break;
            }
        }
    }
    fin.close();
    return num;
}

void Customer::storeData()
{
    ofstream fout;
    fout.open("./data/customer.bank", ios::app | ios::binary);
    if (!fout)
    {
        perror("Error");
        Sleep(2000);
    }
    fout.write((char *)this, sizeof(*this));
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
        fin.read((char *)this, sizeof(*this));
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
            fin.read((char *)this, sizeof(*this));
        }
        fin.close();
        return false;
    }
}

void Customer::viewMyInfo()
{
    system("color 0B");
    system("cls");
    system("title MY INFO");
    TextColor(7);
    cout << "Name: ";
    TextColor(2);
    cout << this->name << endl;
    TextColor(7);
    cout << "Account No: ";
    TextColor(2);
    cout << this->accountNumber << endl;
    TextColor(7);
    cout << "Age: ";
    TextColor(2);
    cout << this->age << endl;
    TextColor(7);
    cout << "Gender: ";
    TextColor(2);
    cout << (this->gender == 'm' ? "Male" : "Female") << endl;
    TextColor(7);
    cout << "Email: ";
    TextColor(2);
    cout << this->email << endl;
    TextColor(1);

    cout << "\n\t\t\t\t\tPress any key to go to your portal\n";
    getch();
    system("color 0F");
}

void Customer::portal()
{
    system("cls");
    int customerPortalChoice, accNo;
    accNo = accountNumber;
    ifstream fin;

    while (1)
    {
        fin.open("./data/customer.bank", ios::in | ios::binary);
        if (!fin)
        {
            system("cls");
            perror("Error");
            cout << "\nProgram will exit\n";
            Sleep(2000);
            exit(1);
        }
        fin.read((char *)this, sizeof(*this));
        while (fin.eof() == 0)
        {
            if (accNo == accountNumber)
            {
                break;
            }
            fin.read((char *)this, sizeof(*this));
        }
        fin.close();
        customerPortalChoice = Customer::portalMenu();
        switch (customerPortalChoice)
        {
        case 1:
            Customer::viewMyInfo();
            // customerPortal();
            break;
        case 2:
            system("cls");
            system("title SEARCH");
            properties.search();
            break;
        case 3:
            system("cls");
            system("title VIEW ALL PROPERTIES");
            properties.print();
            getch();
            break;
        case 4:
            system("cls");
            system("title BUY");
            // Customer::buy();
            break;
        case 5:
            system("cls");
            system("title RENT");
            // t.viewTransactionHistoryCustomer(accNo);
            break;
        case 6:
            system("cls");
            system("title DELETE ACCOUNT");
            Customer::accountSetting();
            break;
        case 7:
            goto customerPortalEnd;
            break;
        default:
            system("cls");
            system("title ERROR");
            CursorPosition(0, 0);
            system("color 4F");
            cout << "\aWrong choice entered, try again! \a";
            Sleep(1500);
            system("color 0F");
            break;
        }
    }
customerPortalEnd:
    system("cls");
}

int Customer::portalMenu()
{
    int choice, i;
    char ch;
    system("color 0F");
    system("cls");
    system("title MY PORTAL");
    CursorPosition(0, 0);
    TextColor(10);
    currentDateAndTime();
    CursorPosition(0, 2);
    TextColor(9);
    cout << "Welcome, " << this->name << endl;
    CursorPosition(32, 5);
    TextColor(11);
    cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 FAST PROPERTIES \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
    for (i = 1; i <= 14; i++)
    {
        CursorPosition(31, 5 + i);
        cout << "|";
    }
    for (i = 1; i <= 14; i++)
    {
        CursorPosition(91, 5 + i);
        cout << "|";
    }
    for (i = 1; i <= 60; i++)
    {
        CursorPosition(31 + i, 20);
        cout << "-";
    }
    TextColor(15);
    CursorPosition(33, 7);
    cout << "1. View my information";
    CursorPosition(33, 9);
    cout << "2. Search";
    CursorPosition(33, 11);
    cout << "3. View all properties";
    CursorPosition(33, 13);
    cout << "4. Buy";
    CursorPosition(33, 15);
    cout << "5. Rent";
    CursorPosition(33, 17);
    cout << "6. Predict Price";
    CursorPosition(33, 19);
    cout << "7. Account Settings";
    CursorPosition(33, 21);
    cout << "8. Logout";
    CursorPosition(32, 24);
    TextColor(5);
    cout << "Enter your choice: ";
    fflush(stdin);
    while (1)
    {
        ch = getch();
        if (ch >= '1' && ch <= '7')
        {
            cout << ch;
            choice = ch - '0';
        }
        else if (ch == 13)
        {
            break;
        }
        else if (ch == 8)
        {
            cout << "\b \b";
        }
    }
    system("color 0F");
    return choice;
}

void Customer::deleteAccount()
{
    int accNo = this->accountNumber;
    char ch, choice;
    system("cls");
    TextColor(4);
    cout << "Are you sure you want to delete your account? [y/n]: ";
    while (1)
    {
        ch = getch();
        if (ch == 'y' || ch == 'Y' || ch == 'n' || ch == 'N')
        {
            choice = ch;
            cout << ch << endl;
            break;
        }
    }
    system("color 0F");
    if (choice == 'y' || choice == 'Y')
    {
        ifstream fin;
        ofstream fout;
        fout.open("./data/temp.bank", ios::out | ios::binary);
        fin.open("./data/customer.bank", ios::in | ios::binary);
        if (!fin)
        {
            perror("Error");
            Sleep(2000);
            exit(1);
        }
        else
        {
            fin.read((char *)this, sizeof(*this));
            while (fin.eof() == 0)
            {
                if (this->accountNumber != accNo)
                {
                    fout.write((char *)this, sizeof(*this));
                }
                fin.read((char *)this, sizeof(*this));
            }
        }
        fin.close();
        fout.close();
        remove("./data/customer.bank");
        rename("./data/temp.bank", "./data/customer.bank");
        TextColor(2);
        cout << "\n\t\t\t\t\tAccount deleted successfully" << endl;
        Sleep(2500);
        main();
    }
}

void Customer::accountSetting()
{
    int choice;
    while (1)
    {
        system("cls");
        cout << "1. Update my email" << endl;
        cout << "2. Update my contact number" << endl;
        cout << "3. Change my password" << endl;
        cout << "4. Delete my account" << endl;
        cout << "5. Go back" << endl;
        TextColor(1);
        cout << endl
             << "Enter your choice: ";
        TextColor(7);
        fflush(stdin);
        cin >> choice;
        switch (choice)
        {
        case 1:
            Customer::updateEmail(this->accountNumber);
            break;
        case 2:
            Customer::updateContactNumber(this->accountNumber);
            break;
        case 3:
            Customer::changePassword(this->accountNumber);
            break;
        case 4:
            Customer::deleteAccount();
            break;
        case 5:
            goto customerAccountSettingEnd;
            break;
        default:
            TextColor(4);
            cout << "Enter a valid choice" << endl;
            Sleep(1000);
            TextColor(7);
            break;
        }
    }
customerAccountSettingEnd:
    system("cls");
}

void Customer::updateInfo(int accNo)
{
    fstream file;
    Customer c;
    file.open("./data/customer.bank", ios::in | ios::out | ios::ate | ios::binary);
    file.seekg(0);
    file.read((char *)&c, sizeof(c));
    while (file.eof() == 0)
    {
        if (c.accountNumber == accNo)
        {
            file.seekp(file.tellp() - sizeof(c));
            file.write((char *)this, sizeof(*this));
            break;
        }
        file.read((char *)&c, sizeof(c));
    }
    file.close();
}

void Customer::updateEmail(int accNo)
{
    setEmail();
    system("cls");
    cout << "Enter your password to confirm: ";
    char passToConfirm[20];
    inputPassword(passToConfirm);
    if (strcmp(password, passToConfirm) == 0)
    {
        Customer::updateInfo(accNo);
    }
}

void Customer::updateContactNumber(int accNo)
{
    system("cls");
    cout << "Enter your password to confirm: ";
    char passToConfirm[20];
    inputPassword(passToConfirm);
    if (strcmp(password, passToConfirm) == 0)
    {
        Customer::updateInfo(accNo);
    }
}

void Customer::changePassword(int accNo)
{
    char passToConfirm[20];
    cout << "Enter your password to confirm: ";
    inputPassword(passToConfirm);
    if (strcmp(password, passToConfirm) == 0)
    {
        system("cls");
        system("title ENTER NEW PASSWORD");
        setPassword();
        Customer::updateInfo(accNo);
    }
}

void Customer::buy(int propID){
    int propID;
    while(1){
        if(properties.propertyExists(propID)){
            properties.sellProperty(propID, name);
            cout << "Property bought successfully" << endl;
            properties.deleteNode(propID);
            Sleep(1000);
            return;
        }
    }
    cout << "This property does not exists" << endl;
    Sleep(1000);
}

void Customer::sendEmailToAll(string subject, string content){
    EmailQueue emailQueue;
    ifstream fin;
    Customer customer;
    system("cls");
    fin.open("./data/customer.bank", ios::in | ios::binary);
    fin.read((char *)&customer, sizeof(customer));
    while (fin.eof() == 0)
    {
        emailQueue.enqueue(customer.accountNumber, customer.name, customer.email);
        fin.read((char *)&customer, sizeof(customer));
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


    while(!emailQueue.isEmpty()){
        fout.open("./python-email/receiver.txt", ios::out);
        fout << emailQueue.getFrontEmail() << "\n";
        emailQueue.dequeue();
        fout.close();
        system("python send_email.py");
    }


}

void Customer::sendEmail(string email, string subject, string content){
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

// STACK

Stack::Stack(){
    top = NULL;
}

bool Stack::isEmpty(){
    if(top == NULL){
        return true;
    }else{
        return false;
    }
}

void Stack::push(Property *p){
    p->next = top;
    top = p;
}

void Stack::pop(){
    if(isEmpty()){
        return;
    }
    Property *temp = top;
    top = top->next;
    delete temp;
}

Property *Stack::peek(){
    if(isEmpty()){
        return NULL;
    }
    return top;
}

// EMAILNODE

EmailNode::EmailNode(int accountNumber, string name, string email){
    this->accountNumber = accountNumber;
    this->name = name;
    this->email = email;
    next = NULL;
}

// EMAILQUEUE

EmailQueue::EmailQueue(){
    front = rear = NULL;
}

bool EmailQueue::isEmpty(){
    if(front == NULL && rear == NULL){
        return true;
    }else{
        return false;
    }
}

void EmailQueue::enqueue(int accountNumber, string name, string email){
    EmailNode *e = new EmailNode(accountNumber, name, email);
    if(isEmpty()){
        front = rear = e;
    }else{
        rear->next = e;
        rear = e;
    }
}

void EmailQueue::dequeue(){
    if(isEmpty()){
        return;
    }
    if(front == rear){
        delete front;
        front = rear = NULL;
    }else{
        EmailNode *temp = front;
        front = front->next;
        delete temp;
    }
}

void EmailQueue::printQueue(){
    if(!isEmpty()){
        EmailNode *temp = front;
        while(temp != NULL){
            cout << temp->accountNumber << "  " << temp->name << "  " << temp->email << endl;
            temp = temp->next;
        }
    }
    cout << endl;
}

string EmailQueue::getFrontEmail(){
    if(!isEmpty()){
        return (front->email);
    }
}

void generateReport(string arg){
    string command = "python ./python-generate-report/app.py " + arg;
    const char* str = command.c_str();
    system(str);
}