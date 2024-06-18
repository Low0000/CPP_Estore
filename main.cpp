#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <random>
#include <algorithm>
#include<chrono>
#include <variant>
#include <cassert>
#include <string>
#include <fstream>
#include<thread>


using namespace std;
using namespace std::chrono;

int idex, idex2;
string name, password, find_user_chat;
vector<string> username_list;
vector<string> password_list;
vector<string> address_list;
vector<float> estimateKM_list;
vector<string> userInfo_list;
vector<string> phone_list;
vector<int> voucherList;
vector<int>tokenGuess_list;
vector<string> rate_name_list;
vector<string>buyItemType_list;
vector<vector<string>> buyItem_list;

vector<vector<string>> buy_record_list;

vector<vector<string>> chatHistory;

vector<vector<string>> chatCAList;
vector<string> joke;
vector<int> randomNum_list;
vector<string> ai_reply = {"AI: Hi there. How can I help?", "AI: My name is BEOX assistant. My mission: To assist you. My favourite colour is brown but changes sometimes","AI: I'm splenedid! Thank you for asking","AI: Please wait for a moment.Will reply in 24hours"};
vector<vector<string>> checkFoodRecord_list;

vector<string> checkStatusPurchase_list;

vector<string> drink_list;
vector<float> drinkPrice_list;
vector<string> mainFood_list;
vector<string>addFood_list;
vector<string> brainTeaserList;
vector<string> quoteslist;
vector<vector<string>> phoneCarrierList;
vector<int> registerDateList;


void mainPage();
void login();
void reg();
void goodbye();
bool is_valid(string email);
void getIndex(vector<string> v3, string name);
void userPage();
void purchaseItem();
void luck();
void rating();
void admin();
void adminProductControl();
void shopManage();
void deleteShopItem();
void buyFood();
void addFood();
void editShopItem();
void userRecord();
void accountSetting();
void serviceChat();
void checkInvoice();
void foodRecord();
void checkFood();
void userDetails();
void readNameFile();
void readPassFile();
void readVoucher();
void readAddress();
void readKMFile();
void readToken();
void readPhoneFile();
void readProduct();
void readProductType();
void readRateNameFile();
void readUserInfoFile();
void readPurchaseRecord();
void readPurchaseStatus();
void readMainFood();
void readAddonFood();
void readDrink();
void readDrinkPrice();
void readfoodRecord();
void readBrainTeaser();
void readQuotesList();
void readRegisterDate();
void writeName(vector<string> v2);
void writePass(vector<string> v2);
void writeAddress(vector<string> v2);
void writeKM(vector<string> v2);
void writePhone(vector<string> v2);
void writeVoucher(vector<string> v2);
void writeToken(vector<string> v2);
void writeProductType(vector<string> v2);
void writeProduct(vector<vector<string>> v2);
void writeUserInfo(vector<string> v2);
void writePurchaseRecord(vector<vector<string>> v2);
void writeStatusPurchase(vector<string> v2);
void writeMainFood(vector<string> v2);
void writeAddOnFood(vector<string> v2);
void writeDrink(vector<string> v2);
void writeDrinkPrice(vector<string> v2);
void writeFoodRecord(vector<vector<string>> v2);
void extractIntegerWords(string str);
void readJoke();
string getDate();
string getTime();
void memoryGame();
void adminChat();
void chatWithAdmin();
void calculateAgeAlive();
void betaFeature();
void foodManage();
void showAllFood();
void deleteFood();
void searchUserChat();
void readChatAI();
void readChatAdmin();
void writeChatAI(vector<vector<string>> v2);
void writeChatAdmin(vector<vector<string>> v2);
void writePhoneCarrier(vector<vector<string>> v2);
void readphoneCarrier();
void mobileTopup();

void extractIntegerWords(string str)
{
    stringstream ss;   

	randomNum_list.clear(); 

    ss << str;

    string temp;
    int found;
    while (!ss.eof()) {

        ss >> temp;

        if (stringstream(temp) >> found)
		{
            cout << found << " ";
            randomNum_list.push_back(found);
		}

        temp = "";
    }
}


void readJoke()
{
	int number_line = 0;
	string line;
	joke.clear();
	ifstream file("./data/joke.txt");
	while (getline(file,line))
	{
		number_line++;
		if(line.size() > 0)
		{
			joke.push_back(line);
		}
	}
	file.close();
}

void readQuotesList()
{
    int number_line = 0;
	string line;
	quoteslist.clear();
	ifstream file("./data/quotes.txt");
	while (getline(file,line))
	{
		number_line++;
		if(line.size() > 0)
		{
			quoteslist.push_back(line);
		}
	}
	file.close();
}

void readBrainTeaser()
{
	int number_line = 0;
	string line;
	joke.clear();
	ifstream file("./data/brainTeaser.txt");
	while (getline(file,line))
	{
		number_line++;
		if(line.size() > 0)
		{
			brainTeaserList.push_back(line);
		}
	}
	file.close();
}


string getDate()
{
	time_t t = time(NULL);
	tm* tptr = localtime(&t);
	string day = to_string(tptr->tm_mday);
	string month =  to_string(tptr->tm_mon+1);
	string year = to_string(tptr->tm_year+1900);
	return day + "-" + month + "-" + year;
}

string getTime()
{
	time_t t = time(NULL);
	tm* tptr = localtime(&t);
	string hour = to_string(tptr->tm_hour);
	string minute =  to_string(tptr->tm_min);
	string sec = to_string(tptr->tm_sec);
	return hour + ":" + minute + ":" + sec;
}



void readNameFile()
{
    int number_line = 0;
    string line;

    username_list.clear();
    ifstream file("./data/username.txt");

    while (getline(file,line))
    {
        number_line++;
        if(line.size()>0)
        {
            username_list.push_back(line);
        }
    }
    file.close();
}




void readPassFile()
{
    int number_line = 0;
    string line;

    password_list.clear();
    ifstream file("./data/password.txt");

    while (getline(file,line))
    {
        number_line++;
        if(line.size()>0)
        {
            password_list.push_back(line);
        }
    }
    file.close();
}

void readAddress()
{
    int number_line = 0;
    string line;

    address_list.clear();
    ifstream file("./data/address.txt");

    while (getline(file,line))
    {
        
        number_line++;
        if(line.size()>0)
        {
            address_list.push_back(line);
        }
        
    }
    file.close();
}

void readKMFile()
{
    int number_line = 0;
    string line;

    estimateKM_list.clear();
    ifstream file("./data/km.txt");

    while (getline(file,line))
    {
        
        number_line++;
        if(line.size()>0)
        {
            float new_line = stof(line);
            estimateKM_list.push_back(new_line);
        }
        
    }
    file.close();
}

void readUserInfoFile()
{
    int number_line = 0;
    string line;

    userInfo_list.clear();
    ifstream file("./data/userInfo.txt");

    while (getline(file,line))
    {
        number_line++;
        if(line.size()>0)
        {
            userInfo_list.push_back(line);
        }
    }
    file.close();
}

void readRegisterDate()
{
    int number_line = 0;
    string line;

    registerDateList.clear();
    ifstream file("./data/registerDate.txt");

    while (getline(file,line))
    {
        
        number_line++;
        if(line.size()>0)
        {
            int new_line = stoi(line);
            registerDateList.push_back(new_line);
        }
        
    }
    file.close();
}




void readVoucher()
{
    int number_line = 0;
    string line;

    voucherList.clear();
    ifstream file("./data/voucherList.txt");

    while (getline(file,line))
    {
        
        number_line++;
        if(line.size()>0)
        {
            int new_line = stoi(line);
            voucherList.push_back(new_line);
        }
        
    }
    file.close();
}

void readToken()
{
    int number_line = 0;
    string line;

    tokenGuess_list.clear();
    ifstream file("./data/tokenList.txt");

    while (getline(file,line))
    {
        
        number_line++;
        if(line.size()>0)
        {
            int new_line = stoi(line);
            tokenGuess_list.push_back(new_line);
        }
        
    }
    file.close();
}

void readPhoneFile()
{
    int number_line = 0;
    string line;

    phone_list.clear();
    ifstream file("./data/phone.txt");

    while (getline(file,line))
    {
        number_line++;
        if(line.size()>0)
        {
            phone_list.push_back(line);
        }
    }
    file.close();
}



void readProductType()
{
    int number_line = 0;
    string line;

    buyItemType_list.clear();
    ifstream file("./data/productType.txt");

    while (getline(file,line))
    {
        number_line++;
        if(line.size()>0)
        {
            buyItemType_list.push_back(line);
        }
    }
    file.close();
}

void readProduct()
{
    vector<string> tempDataList;
    int number_line = 0;
    string line;

    buyItem_list.clear();
    ifstream file("./data/product.txt");

    while (getline(file,line))
    {
        
        number_line++;
        if(line.size()>0)
        {
            tempDataList.push_back(line);
        }
        if(line.size()== 1 && line == "@")
        {
            tempDataList.pop_back();
            buyItem_list.push_back(tempDataList);
            tempDataList.clear();
        }
        
    }
    file.close();
}


void readPurchaseRecord()
{
    vector<string> tempDataList;
    int number_line = 0;
    string line;

    buy_record_list.clear();
    ifstream file("./data/buyRecord.txt");

    while (getline(file,line))
    {
        number_line++;
        if(line.size()>0)
        {
            tempDataList.push_back(line);
        }
        if(line.size()== 1 && line == "@")
        {
            tempDataList.pop_back();
            buy_record_list.push_back(tempDataList);
            tempDataList.clear();
        }
        
    }
    file.close();
}

void readPurchaseStatus()
{
    int number_line = 0;
    string line;

    checkStatusPurchase_list.clear();
    ifstream file("./data/statusItem.txt");

    while (getline(file,line))
    {
        number_line++;
        if(line.size()>0)
        {
            checkStatusPurchase_list.push_back(line);
        }
    }
    file.close();
}

void readfoodRecord()
{
    vector<string> tempDataList;
    int number_line = 0;
    string line;

    checkFoodRecord_list.clear();
    ifstream file("./data/foodRecordList.txt");

    while (getline(file,line))
    {
        number_line++;
        if(line.size()>0)
        {
            tempDataList.push_back(line);
        }
        if(line.size()== 1 && line == "@")
        {
            tempDataList.pop_back();
            checkFoodRecord_list.push_back(tempDataList);
            tempDataList.clear();
        }
        
    }
    file.close();
}

void readRateNameFile()
{
    int number_line = 0;
    string line;

    rate_name_list.clear();
    ifstream file("./data/rateName.txt");

    while (getline(file,line))
    {
        number_line++;
        if(line.size()>0)
        {
            rate_name_list.push_back(line);
        }
    }
    file.close();
}


void readMainFood()
{
    int number_line = 0;
    string line;

    mainFood_list.clear();
    ifstream file("./data/mainFoodList.txt");

    while (getline(file,line))
    {
        
        number_line++;
        if(line.size()>0)
        {
            mainFood_list.push_back(line);
        }
        
    }
    file.close();
}

void readAddonFood()
{
    int number_line = 0;
    string line;

    addFood_list.clear();
    ifstream file("./data/addOnFoodList.txt");

    while (getline(file,line))
    {
        
        number_line++;
        if(line.size()>0)
        {
            addFood_list.push_back(line);
        }
        
    }
    file.close();
}


void readDrink()
{
    int number_line = 0;
    string line;

    drink_list.clear();
    ifstream file("./data/drinkList.txt");

    while (getline(file,line))
    {
        
        number_line++;
        if(line.size()>0)
        {
            drink_list.push_back(line);
        }
        
    }
    file.close();
}


void readDrinkPrice()
{
    int number_line = 0;
    string line;

    drinkPrice_list.clear();
    ifstream file("./data/drinkPriceList.txt");

    while (getline(file,line))
    {
        
        number_line++;
        if(line.size()>0)
        {
            drinkPrice_list.push_back(stof(line));
        }
        
    }
    file.close();
}

void readphoneCarrier()
{
    vector<string> tempDataList;
    int number_line = 0;
    string line;

    phoneCarrierList.clear();
    ifstream file("./data/phoneCarrierList.txt");

    while (getline(file,line))
    {
        
        number_line++;
        if(line.size()>0)
        {
            tempDataList.push_back(line);
        }
        if(line.size()== 1 && line == "@")
        {
            tempDataList.pop_back();
            phoneCarrierList.push_back(tempDataList);
            tempDataList.clear();
        }
        
    }
    file.close();
}



void readChatAdmin()
{
    vector<string> tempDataList;
    int number_line = 0;
    string line;

    chatCAList.clear();
    ifstream file("./data/adminChatList.txt");

    while (getline(file,line))
    {
        
        number_line++;
        if(line.size()>0)
        {
            tempDataList.push_back(line);
        }
        if(line.size()== 1 && line == "@")
        {
            tempDataList.pop_back();
            chatCAList.push_back(tempDataList);
            tempDataList.clear();
        }
        
    }
    file.close();
}

void readChatAI()
{
    vector<string> tempDataList;
    int number_line = 0;
    string line;

    chatHistory.clear();
    ifstream file("./data/aiChatList.txt");

    while (getline(file,line))
    {
        
        number_line++;
        if(line.size()>0)
        {
            tempDataList.push_back(line);
        }
        if(line.size()== 1 && line == "@")
        {
            tempDataList.pop_back();
            chatHistory.push_back(tempDataList);
            tempDataList.clear();
        }
        
    }
    file.close();
}


void writeName(vector<string> v2)
{
    ofstream file2;
    file2.open("./data/temp.txt");
    for(int i=0; i< v2.size(); i++ )
    {
        file2 << v2[i] << endl;
    }
    file2.close();
    remove("./data/username.txt");
    rename("./data/temp.txt","./data/username.txt");
}

void writePass(vector<string> v2)
{
    ofstream file2;
    file2.open("./data/temp.txt");
    for(int i=0; i< v2.size(); i++ )
    {
        file2 << v2[i] << endl;
    }
    file2.close();
    remove("./data/password.txt");
    rename("./data/temp.txt","./data/password.txt");
}

void writeRegisterDate(vector<int> v2)
{
    ofstream file2;
    file2.open("./data/temp.txt");
    for(int i=0; i< v2.size(); i++ )
    {
        file2 << v2[i] << endl;
    }
    file2.close();
    remove("./data/registerDate.txt");
    rename("./data/temp.txt","./data/registerDate.txt");
}


void writeAddress(vector<string> v2)
{
    ofstream file2;
    file2.open("./data/temp.txt");
    for(int i=0; i< v2.size(); i++ )
    {
        file2 << v2[i] << endl;
    }
    file2.close();
    remove("./data/address.txt");
    rename("./data/temp.txt","./data/address.txt");
}


void writeUserInfo(vector<string> v2)
{
    ofstream file2;
    file2.open("./data/temp.txt");
    for(int i=0; i< v2.size(); i++ )
    {
        file2 << v2[i] << endl;
    }
    file2.close();
    remove("./data/userInfo.txt");
    rename("./data/temp.txt","./data/userInfo.txt");
}


void writeKM(vector<float> v2)
{
    ofstream file2;
    file2.open("./data/temp.txt");
    for(int i=0; i< v2.size(); i++ )
    {
        file2 << v2[i] << endl;
    }
    file2.close();
    remove("./data/km.txt");
    rename("./data/temp.txt","./data/km.txt");
}

void writePhone(vector<string> v2)
{
    ofstream file2;
    file2.open("./data/temp.txt");
    for(int i=0; i< v2.size(); i++ )
    {
        file2 << v2[i] << endl;
    }
    file2.close();
    remove("./data/phone.txt");
    rename("./data/temp.txt","./data/phone.txt");
}

void writeVoucher(vector<int> v2)
{
    ofstream file2;
    file2.open("./data/temp.txt");
    for(int i=0; i< v2.size(); i++ )
    {
        file2 << v2[i] << endl;
    }
    file2.close();
    remove("./data/voucherList.txt");
    rename("./data/temp.txt","./data/voucherList.txt");
}

void writeToken(vector<int> v2)
{
    ofstream file2;
    file2.open("./data/temp.txt");
    for(int i=0; i< v2.size(); i++ )
    {
        file2 << v2[i] << endl;
    }
    file2.close();
    remove("./data/tokenList.txt");
    rename("./data/temp.txt","./data/tokenList.txt");
}


void writeProductType(vector<string> v2)
{
    ofstream file2;
    file2.open("./data/temp.txt");
    for(int i=0; i< v2.size(); i++ )
    {
        file2 << v2[i] << endl;
    }
    file2.close();
    remove("./data/productType.txt");
    rename("./data/temp.txt","./data/productType.txt");
}

void writeProduct(vector<vector<string>> v2)
{
    ofstream file2;
    file2.open("./data/temp.txt");
    for(int i=0; i< v2.size(); i++ )
    {
        for(int j = 0; j < v2[i].size(); j++)
        {
            file2 << v2[i][j] << endl;
        }
        file2 << "@" << endl;
    }
    file2.close();
    remove("./data/product.txt");
    rename("./data/temp.txt","./data/product.txt");
}

void writePhoneCarrier(vector<vector<string>> v2)
{
    ofstream file2;
    file2.open("./data/temp.txt");
    for(int i=0; i< v2.size(); i++ )
    {
        for(int j = 0; j < v2[i].size(); j++)
        {
            file2 << v2[i][j] << endl;
        }
        file2 << "@" << endl;
    }
    file2.close();
    remove("./data/phoneCarrierList.txt");
    rename("./data/temp.txt","./data/phoneCarrierList.txt");
}

void writePurchaseRecord(vector<vector<string>> v2)
{
    ofstream file2;
    file2.open("./data/temp.txt");
    for(int i=0; i< v2.size(); i++ )
    {
        for(int j = 0; j < v2[i].size(); j++)
        {
            file2 << v2[i][j] << endl;
        }
        file2 << "@" << endl;
    }
    file2.close();
    remove("./data/buyRecord.txt");
    rename("./data/temp.txt","./data/buyRecord.txt");
}




void writeStatusPurchase(vector<string> v2)
{
    ofstream file2;
    file2.open("./data/temp.txt");
    for(int i=0; i< v2.size(); i++ )
    {
        file2 << v2[i] << endl;
    }
    file2.close();
    remove("./data/statusItem.txt");
    rename("./data/temp.txt","./data/statusItem.txt");
}


void writeFoodRecord(vector<vector<string>> v2)
{
    ofstream file2;
    file2.open("./data/temp.txt");
    for(int i=0; i< v2.size(); i++ )
    {
        for(int j = 0; j < v2[i].size(); j++)
        {
            file2 << v2[i][j] << endl;
        }
        file2 << "@" << endl;
    }
    file2.close();
    remove("./data/foodRecordList.txt");
    rename("./data/temp.txt","./data/foodRecordList.txt");
}

void writeRateName(vector<string> v2)
{
    ofstream file2;
    file2.open("./data/temp.txt");
    for(int i=0; i< v2.size(); i++ )
    {
        file2 << v2[i] << endl;
    }
    file2.close();
    remove("./data/rateName.txt");
    rename("./data/temp.txt","./data/rateName.txt");
}


void writeMainFood(vector<string> v2)
{
    ofstream file2;
    file2.open("./data/temp.txt");
    for(int i=0; i< v2.size(); i++ )
    {
        file2 << v2[i] << endl;
    }
    file2.close();
    remove("./data/mainFoodList.txt");
    rename("./data/temp.txt","./data/mainFoodList.txt");
}


void writeAddOnFood(vector<string> v2)
{
    ofstream file2;
    file2.open("./data/temp.txt");
    for(int i=0; i< v2.size(); i++ )
    {
        file2 << v2[i] << endl;
    }
    file2.close();
    remove("./data/addOnFoodList.txt");
    rename("./data/temp.txt","./data/addOnFoodList.txt");
}

void writeDrink(vector<string> v2)
{
    ofstream file2;
    file2.open("./data/temp.txt");
    for(int i=0; i< v2.size(); i++ )
    {
        file2 << v2[i] << endl;
    }
    file2.close();
    remove("./data/drinkList.txt");
    rename("./data/temp.txt","./data/drinkList.txt");
}

void writeDrinkPrice(vector<float> v2)
{
    ofstream file2;
    file2.open("./data/temp.txt");
    for(int i=0; i< v2.size(); i++ )
    {
        file2 << to_string(v2[i]) << endl;
    }
    file2.close();
    remove("./data/drinkPriceList.txt");
    rename("./data/temp.txt","./data/drinkPriceList.txt");
}

void writeChatAI(vector<vector<string>> v2)
{
    ofstream file2;
    file2.open("./data/temp.txt");
    for(int i=0; i< v2.size(); i++ )
    {
        for(int j = 0; j < v2[i].size(); j++)
        {
            file2 << v2[i][j] << endl;
        }
        file2 << "@" << endl;
    }
    file2.close();
    remove("./data/aiChatList.txt");
    rename("./data/temp.txt","./data/aiChatList.txt");
}

void writeChatAdmin(vector<vector<string>> v2)
{
    ofstream file2;
    file2.open("./data/temp.txt");
    for(int i=0; i< v2.size(); i++ )
    {
        for(int j = 0; j < v2[i].size(); j++)
        {
            file2 << v2[i][j] << endl;
        }
        file2 << "@" << endl;
    }
    file2.close();
    remove("./data/adminChatList.txt");
    rename("./data/temp.txt","./data/adminChatList.txt");
}




void getIndex(vector<string> v3, string name)
{
    auto it = find(v3.begin(), v3.end(), name);
    if (it != v3.end())
    {
        idex = it - v3.begin();
    }
}



bool isChar(char c)
{
    return ((c >= 'a' && c <= 'z')
        || (c >= 'A' && c <= 'Z'));
}

bool isDigit(const char c)
{
    return (c >= '0' && c <= '9');
}


bool is_valid(string email)
{
    if (!isChar(email[0]))
    {
        return 0;
    }

    int At = -1, Dot = -1;


    for (int i = 0; i < email.length(); i++)
    {

        if (email[i] == '@')
        {
            At = i;
        }

        else if (email[i] == '.')
        {
            Dot = i;
        }
    }

    if (At == -1 || Dot == -1)
        return 0;

    if (At > Dot)
        return 0;

    return !(Dot >= (email.length() - 1));
}




void checkFood()
{
    system("CLS");
    int choice;
    readfoodRecord();
    cout << "\t\t\t====================================" << endl;
    cout << "\t\t\t|          FOOD ORDERING           |" << endl;
    cout << "\t\t\t====================================" << endl;
    cout << "\t\t\t|         1. LIST ALL              |" << endl;
    cout << "\t\t\t------------------------------------" << endl;
    cout << "\t\t\t|         2. Mark as delivering    |" << endl;
    cout << "\t\t\t------------------------------------" << endl;
    cout << "\t\t\t|         3. Mark as delivered     |" << endl;
    cout << "\t\t\t------------------------------------" << endl;
    cout << "\t\t\t|         4. BACK                  |" << endl;
    cout << "\t\t\t------------------------------------" << endl;
    cout << ".........................................................................................." << endl;
    cout << "\t\tEnter your choice(1/2/3/4) ---> ";
    cin >> choice;
    while (choice != 1 && choice != 2 && choice != 3 && choice != 4)
    {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "|ATTEINTION: Invalid Choice|" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Enter Again: ";
        cin >> choice;
    }
    if(choice == 1)
    {
        system("CLS");
        cout << "Food Purchase LIST" << endl;
        cout << "------------------------------------------" << endl;
        for(int i = 0;i < checkFoodRecord_list.size(); i+=3)
        {
            cout << "Food No.: " << checkFoodRecord_list[i][1] << endl;
            cout << "Username: " << checkFoodRecord_list[i][2] << endl;
            cout << "Purchase Time: " << checkFoodRecord_list[i][3] << endl;
            cout << "Estimate Arrived: " << checkFoodRecord_list[i][4] << endl;
            cout << "Hp Num: " << checkFoodRecord_list[i][5] << endl;
            cout << "Deliver Address: " << checkFoodRecord_list[i][6] << endl;
            cout << "Deliver Status: " << checkFoodRecord_list[i][7] << endl;
            cout << "===============================================================================" << endl;
            cout << "Food Purchase|" << endl;
            cout << "--------------" << endl;
            for (int j = 0 ; j < checkFoodRecord_list[i+1].size(); j++)
            {
                cout << j+1 << ". " << checkFoodRecord_list[i+1][j] << endl;
            }
            cout << "------------------------------------------------------------------------------------" << endl;
            cout << "Drink Purchase|" << endl;
            cout << "---------------" << endl;
            for (int k = 0 ; k < checkFoodRecord_list[i+2].size(); k++)
            {
                cout << k+1 << ". " << checkFoodRecord_list[i+2][k] << endl;
            }
            cout << "------------------------------------------------------------------------------------" << endl;
            cout << "Total Purchased: RM " << checkFoodRecord_list[i][0] << endl;
            cout << endl << "================================================================================" << endl;
        }
        cout << "==========================================[END OF DATA]==========================================" << endl;
        system("PAUSE");
        
        checkFood();
    }
    else if(choice == 2)
    {
        system("CLS");
        string foodNum;
        vector<string> foodInvoiceList;
        for(int i = 0; i < checkFoodRecord_list.size(); i+=3)
        {
            if(find(checkFoodRecord_list[i].begin(),checkFoodRecord_list[i].end(),"Preparing") != checkFoodRecord_list[i].end())
            {
                break;
            }
            else
            {
                if(i == checkFoodRecord_list.size()-3)
                {
                    if(checkFoodRecord_list[i][7] != "Preparing")
                    {
                        cout << "Nothing need preparing!" << endl;
                        system("PAUSE");
                        checkFood();
                    }
                    
                }
            }
        }

        cout << "Food Purchase LIST" << endl;
        cout << "------------------------------------------" << endl;
        for(int i = 0;i < checkFoodRecord_list.size(); i+=3)
        {
            if(checkFoodRecord_list[i][7] == "Preparing")
            {
                cout << "Food No.: " << checkFoodRecord_list[i][1] << endl;
                foodInvoiceList.push_back(checkFoodRecord_list[i][1]);
                cout << "Username: " << checkFoodRecord_list[i][2] << endl;
                cout << "Purchase Time: " << checkFoodRecord_list[i][3] << endl;
                cout << "Estimate Arrived: " << checkFoodRecord_list[i][4] << endl;
                cout << "Hp Num: " << checkFoodRecord_list[i][5] << endl;
                cout << "Deliver Address: " << checkFoodRecord_list[i][6] << endl;
                cout << "Deliver Status: " << checkFoodRecord_list[i][7] << endl;
                cout << "===============================================================================" << endl;
                cout << "Food Purchase|" << endl;
                cout << "--------------" << endl;
                for (int j = 0 ; j < checkFoodRecord_list[i+1].size(); j++)
                {
                    cout << j+1 << ". " << checkFoodRecord_list[i+1][j] << endl;
                }
                cout << "------------------------------------------------------------------------------------" << endl;
                cout << "Drink Purchase|" << endl;
                cout << "---------------" << endl;
                for (int k = 0 ; k < checkFoodRecord_list[i+2].size(); k++)
                {
                    cout << k+1 << ". " << checkFoodRecord_list[i+2][k] << endl;
                }
                cout << "------------------------------------------------------------------------------------" << endl;
                cout << "Total Purchased: RM " << checkFoodRecord_list[i][0] << endl;
                cout << endl << "================================================================================" << endl;
            }
        }
        cout << "==========================================[END OF DATA]==========================================" << endl;
        
        do
        {
            cout << "Enter Food Ordering Number For Delivering [0-EXIT]: ";
            getline(cin >> ws, foodNum);
            if(find(foodInvoiceList.begin(),foodInvoiceList.end(),foodNum)!= foodInvoiceList.end())
            {  
                checkFoodRecord_list[(stoi(foodNum)-1001)*3][7] = "Delivering";
                cout << "UPDATED" << endl;
            }
            else
            {
                cout << "Ordering number not available.." << endl;
            }
            cout << "=======================================================================" << endl;
        } while (foodNum != "0");
        writeFoodRecord(checkFoodRecord_list);
        checkFood();
    }
    else if(choice == 3)
    {
        system("CLS");

        string foodNum;
        vector<string> foodInvoiceList;
        for(int i = 0; i < checkFoodRecord_list.size(); i+=3)
        {
            if(find(checkFoodRecord_list[i].begin(),checkFoodRecord_list[i].end(),"Delivering") != checkFoodRecord_list[i].end())
            {
                break;
            }
            else
            {
                
                if(i == checkFoodRecord_list.size()-3)
                {
                    if(checkFoodRecord_list[i][7] != "Delivering")
                    {
                        cout << "Nothing in delivering!" << endl;
                        system("PAUSE");
                        checkFood();
                    }
                }
                
            }
        }

        cout << "Food Purchase LIST" << endl;
        cout << "------------------------------------------" << endl;
        for(int i = 0;i < checkFoodRecord_list.size(); i+=3)
        {
            if(checkFoodRecord_list[i][7] == "Delivering")
            {
                cout << "Food No.: " << checkFoodRecord_list[i][1] << endl;
                foodInvoiceList.push_back(checkFoodRecord_list[i][1]);
                cout << "Username: " << checkFoodRecord_list[i][2] << endl;
                cout << "Purchase Time: " << checkFoodRecord_list[i][3] << endl;
                cout << "Estimate Arrived: " << checkFoodRecord_list[i][4] << endl;
                cout << "Hp Num: " << checkFoodRecord_list[i][5] << endl;
                cout << "Deliver Address: " << checkFoodRecord_list[i][6] << endl;
                cout << "Deliver Status: " << checkFoodRecord_list[i][7] << endl;
                cout << "===============================================================================" << endl;
                cout << "Food Purchase|" << endl;
                cout << "--------------" << endl;
                for (int j = 0 ; j < checkFoodRecord_list[i+1].size(); j++)
                {
                    cout << j+1 << ". " << checkFoodRecord_list[i+1][j] << endl;
                }
                cout << "------------------------------------------------------------------------------------" << endl;
                cout << "Drink Purchase|" << endl;
                cout << "---------------" << endl;
                for (int k = 0 ; k < checkFoodRecord_list[i+2].size(); k++)
                {
                    cout << k+1 << ". " << checkFoodRecord_list[i+2][k] << endl;
                }
                cout << "------------------------------------------------------------------------------------" << endl;
                cout << "Total Purchased: RM " << checkFoodRecord_list[i][0] << endl;
                cout << endl << "================================================================================" << endl;
            }
        }
        cout << "==========================================[END OF DATA]==========================================" << endl;

        do
        {
            cout << "Enter Food Ordering Number For Delivered [0-EXIT]: ";
            getline(cin >> ws, foodNum);
            if(find(foodInvoiceList.begin(),foodInvoiceList.end(),foodNum)!= foodInvoiceList.end())
            {
                checkFoodRecord_list[(stoi(foodNum)-1001)*3][7] = "Delivered";
                cout << "UPDATED" << endl;
            }
            else
            {
                cout << "Ordering number not available.." << endl;
            }
            cout << "=======================================================================" << endl;
        } while (foodNum != "0");
        writeFoodRecord(checkFoodRecord_list);
        checkFood();
    }
    else
    {
        adminProductControl();
    }

}



void adminChat()
{
    system("CLS");
    readChatAdmin();
    readChatAI();
    int choice;
    string text_admin, search_user;
    cout << "--------------------------------------------" << endl;
    cout << "|Chat Room                                 |" << endl;
    cout << "--------------------------------------------" << endl;
    cout << "|Key in [-1] To Exit Chat Room             |" << endl;
    cout << "--------------------------------------------" << endl << endl;

    for(int i = 0; i < chatCAList.size(); i++)
    {
        if(chatCAList[i][0] == "unread")
        { 
            cout << i + 1 << ". " << chatCAList[i][1] << " (UNREAD MESSAGE)" << endl << endl;
        }
        else
        {
            cout << i+1 << ". " << chatCAList[i][1] << endl << endl;
        }
    }
    cout << ".................................................................................." << endl;
    cout << "Enter number for your chat [0 - SEARCH USER]: ";
    cin >> choice;

    while (cin.fail() || choice > chatCAList.size() && choice < -1)
    {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "|ATTEINTION: Invalid Choice|" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Enter Again: ";
        cin >> choice;
    }

    if (choice == 0)
    {
        system("CLS");
        string search_email;
        vector<string> temp_email;
        cout << "Enter email you want to search: ";
        getline(cin >> ws, search_email);
        cout << "\n--------------------------------------------------------------\n";
        cout << "RELATDED EMAIL" << endl;
        cout << "--------------------" << endl;
        for(int i = 0; i < username_list.size(); i++)
        {
            if(username_list[i].find(search_email) != string::npos)
            {
                temp_email.push_back(username_list[i]);
            }
        }
        if(temp_email.size() == 0)
        {
            cout << "---------------------------------" << endl;
            cout << "|    Username didn't found!!    |" << endl;
            cout << "---------------------------------" << endl;
            system("PAUSE");
            adminChat();
        }

        for(int i = 0;i < temp_email.size(); i++)
        {
            cout << i+1 << ". " << temp_email[i] << endl << endl;
        }

        int select_user;
        cout << "Enter number for customer you want to chat [0-EXIT]: ";
        cin >> select_user;
        while(cin.fail() || select_user > temp_email.size() || select_user < 0)
        {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "|ATTEINTION: Invalid Input!|" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Enter Again: ";
            cin >> select_user;
        }
        if(select_user == 0)
        {
            adminProductControl();
        }
        search_user = temp_email[select_user-1];
    }
    else if(choice == -1)
    {
        adminProductControl();
    }
    else
    {
        search_user = chatCAList[choice-1][1];
    }

    getIndex(username_list,search_user);


    chatHistory[idex][0] = "read";
    chatCAList[idex][0] = "read";
    writeChatAI(chatHistory);
    writeChatAdmin(chatCAList);
    do
	{
		system("CLS");
        readChatAdmin();
        time_t t = time(NULL);
        string str_min;
		tm* tptr = localtime(&t);
		int hour = tptr->tm_hour;
        int min = tptr->tm_min;
        int mon = tptr->tm_mon+1;
        int day = tptr->tm_mday;
        if (min < 10)
        {
            str_min = "0" + to_string(min);
        }
        else
        {
            str_min = to_string(min);
        }
		cout << "Username: " << chatCAList[idex][1] << endl;
        cout << "--------------------------------------------------" << endl << endl;
        string find_bar = "Me: ";
        
		if(chatCAList[idex].size() >= 2)
		{
            cout << "AI: Type [quit] to close chat..." << endl << endl;
			for(int i = 2;i < chatCAList[idex].size(); i++)
			{
                size_t len = find_bar.length();
                if(chatCAList[idex][i].find(find_bar) != string::npos)
                {
                    size_t pos = chatCAList[idex][i].find(find_bar);
                    chatCAList[idex][i].replace(pos,len,"Customer: ");
                }
                
				cout  << chatCAList[idex][i] << endl << endl;
			}
		}
		cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
		cout << "Enter your message below: " << endl;
		getline(cin >> ws, text_admin);
        chatCAList[idex].push_back("[" + to_string(day) + "/" + to_string(mon) + " | " + to_string(hour) +":" + str_min + "]\t" + "Admin: " + text_admin);
		writeChatAdmin(chatCAList);
	} while (text_admin != "quit");

    chatCAList[idex].pop_back();
    string find_barC = "Customer: ";
    for(int i = 2;i < chatCAList[idex].size(); i++)
	{
        size_t len = find_barC.length();
        if(chatCAList[idex][i].find(find_barC) != string::npos)
        {
            size_t pos = chatCAList[idex][i].find(find_barC);
            chatCAList[idex][i].replace(pos,len,"Me: ");
        }
	}
    writeChatAdmin(chatCAList);

    adminProductControl();
}

void foodManage()
{
    system("CLS");
    int choice;
    cout << "\t\t==================================" << endl;
    cout << "\t\t|         Food Management        |" << endl;
    cout << "\t\t==================================" << endl;
    cout << "\t\t|          1. Add Food           |" << endl;
    cout << "\t\t----------------------------------" << endl;
    cout << "\t\t|          2. Delete Food        |" << endl;
    cout << "\t\t----------------------------------" << endl;
    cout << "\t\t|          3. Show All Food      |" << endl;
    cout << "\t\t----------------------------------" << endl;
    cout << "\t\t|          4. Back               |" << endl;
    cout << "\t\t==================================" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    while (choice != 1 && choice != 2 && choice != 3 && choice != 4)
    {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "|ATTEINTION: Invalid Choice|" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Enter Again: ";
        cin >> choice;
    }

    if (choice == 1)
    {
        addFood();
    }
    else if(choice == 2)
    {
        deleteFood();
    }
    else if(choice == 3)
    {
        showAllFood();
    }
    else if(choice == 4)
    {
        adminProductControl();
    }
}

void showAllFood()
{
    system("CLS");
    readMainFood();
    readAddonFood();
    readDrink();
    readDrinkPrice();

    cout << "\t\t\t+--------------------------------------------------------+" << endl;
    cout << "\t\t\t|                   Food Order Menu List                 |" << endl;
    cout << "\t\t\t+--------------------------------------------------------+" << endl;
    cout << "\t\t\t\t\t[ MAIN FOOD ]" << endl << endl;
    for(int i = 0;i < mainFood_list.size(); i+= 2)
    {
        cout << "\t\t\t" << mainFood_list[i] << "\t\t\t\tRM " << mainFood_list[i+1] << endl << endl;
    }
    cout << "-----------------------------------------------------------------------------------------------------------------" << endl << endl;
    cout << "\t\t\t\t\t[ ADD ON FOOD ]" << endl << endl;
    for(int i = 0;i < addFood_list.size(); i+= 2)
    {
        cout << "\t\t\t" << addFood_list[i] << "\t\t\t\tRM " << addFood_list[i+1] << endl << endl;
    }
    cout << "-----------------------------------------------------------------------------------------------------------------" << endl << endl;
    cout << "\t\t\t\t\t[ DRINK ]" << endl << endl;
    for(int i = 0;i < drink_list.size(); i++)
    {
        cout << "\t\t\t" << drink_list[i] << "\t\t\t\tRM " << fixed << setprecision(2) << drinkPrice_list[i] << endl << endl;
    }

    cout << "-----------------------------------------------------------------------------------------------------------------" << endl << endl;
    system("PAUSE");
    foodManage();
}


void addFood()
{
    system("CLS");
    readMainFood();
    readAddonFood();
    readDrink();
    readDrinkPrice();
    int choice;
    cout << "\t\t==================================" << endl;
    cout << "\t\t| What category you want to add: |" << endl;
    cout << "\t\t==================================" << endl;
    cout << "\t\t|          1. Main Food          |" << endl;
    cout << "\t\t----------------------------------" << endl;
    cout << "\t\t|          2. Add-on             |" << endl;
    cout << "\t\t----------------------------------" << endl;
    cout << "\t\t|          3. Drink              |" << endl;
    cout << "\t\t----------------------------------" << endl;
    cout << "\t\t|          4. Back               |" << endl;
    cout << "\t\t==================================" << endl;
    cout << ".........................................................................................." << endl;
    cout << "\t\tEnter your choice(1/2/3/4) ---> ";
    cin >> choice;
    while (choice != 1 && choice != 2 && choice != 3 && choice != 4)
    {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "|ATTEINTION: Invalid Choice|" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Enter Again: ";
        cin >> choice;
    }
    if (choice == 1)
    {
        system("CLS");
        string newnameFood, newFoodPrice;
        cout << "\t\t-----------" << endl;
        cout << "\t\t|Adding...|" << endl;
        cout << "\t\t-----------" << endl;
        cout << "===========================================================================" << endl << endl;
        cout << "Name of main food : ";
        getline(cin >> ws, newnameFood);
        cout << endl;
        cout << "Price of main food: RM ";
        getline(cin >> ws, newFoodPrice);
        mainFood_list.push_back(newnameFood);
        mainFood_list.push_back(newFoodPrice);
        writeMainFood(mainFood_list);
        cout << endl << endl;
        cout << "++++++++++++" << endl;
        cout << "|  Saved!  |" << endl;
        cout << "++++++++++++" << endl << endl;
        system("PAUSE");
        foodManage();


    }
    else if (choice == 2)
    {
        system("CLS");
        string newnameFood2, newFoodPrice2;
        cout << "\t\t-----------" << endl;
        cout << "\t\t|Adding...|" << endl;
        cout << "\t\t-----------" << endl;
        cout << "===========================================================================" << endl << endl;
        cout << "Name of add-on food : ";
        getline(cin >> ws, newnameFood2);
        cout << endl;
        cout << "Price of add-on food: RM ";
        getline(cin >> ws, newFoodPrice2);
        addFood_list.push_back(newnameFood2);
        addFood_list.push_back(newFoodPrice2);
        writeAddOnFood(addFood_list);
        cout << endl << endl;
        cout << "++++++++++++" << endl;
        cout << "|  Saved!  |" << endl;
        cout << "++++++++++++" << endl << endl;
        system("PAUSE");
        foodManage();
    }
    else if (choice == 3)
    {
        system("CLS");
        string newnameDrink;
        float newDrinkPrice;
        cout << "\t\t-----------" << endl;
        cout << "\t\t|Adding...|" << endl;
        cout << "\t\t-----------" << endl;
        cout << "===========================================================================" << endl << endl;
        cout << "Name of Drink : ";
        getline(cin >> ws, newnameDrink);
        cout << endl;
        cout << "Price of Drink: RM ";
        cin >> newDrinkPrice;
        while(cin.fail())
        {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "|ATTEINTION: Invalid Input!|" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Enter Again: ";
            cin >> newDrinkPrice;
        }
        drink_list.push_back(newnameDrink);
        drinkPrice_list.push_back(newDrinkPrice);
        writeDrink(drink_list);
        writeDrinkPrice(drinkPrice_list);
        cout << endl << endl;
        cout << "++++++++++++" << endl;
        cout << "|  Saved!  |" << endl;
        cout << "++++++++++++" << endl << endl;
        system("PAUSE");
        foodManage();
    }
    else if(choice == 4)
    {
        foodManage(); 
    }
}

void deleteFood()
{
    system("CLS");
    readMainFood();
    readAddonFood();
    readDrink();
    readDrinkPrice();
    int choice;
    cout << "\t\t===================================" << endl;
    cout << "\t\t| What category you want to delete|" << endl;
    cout << "\t\t===================================" << endl;
    cout << "\t\t|          1. Main Food           |" << endl;
    cout << "\t\t-----------------------------------" << endl;
    cout << "\t\t|          2. Add-on              |" << endl;
    cout << "\t\t-----------------------------------" << endl;
    cout << "\t\t|          3. Drink               |" << endl;
    cout << "\t\t-----------------------------------" << endl;
    cout << "\t\t|          4. Back                |" << endl;
    cout << "\t\t===================================" << endl;
    cout << ".........................................................................................." << endl;
    cout << "\t\tEnter your choice(1/2/3/4) ---> ";
    cin >> choice;
    while (choice != 1 && choice != 2 && choice != 3 && choice != 4)
    {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "|ATTEINTION: Invalid Choice|" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Enter Again: ";
        cin >> choice;
    }

    if(choice == 1)
    {
        int delete_item;
        cout << "\n\t\t-----------------------------------------" << endl;
        for(int i = 0;i < mainFood_list.size(); i+=2)
        {
            cout << "\t\t| " << (i/2)+1 << ". " << mainFood_list[i] << endl;
            cout << "\t\t-----------------------------------------" << endl;
        }
        cout << "\t\t| 0. Exit" << endl;
        cout << "\t\t-----------------------------------------" << endl;

        cout << "Which main food you want delete(number): ";
        cin >> delete_item;
        while(cin.fail() || delete_item > (mainFood_list.size()/2) || delete_item < 0)
        {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "|ATTEINTION: Invalid Input!|" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "Enter Again: ";
            cin.clear();
            cin.ignore(256, '\n');
            cin >> delete_item;
        }
        if (delete_item == 0)
        {
            foodManage();
        }

        getIndex(mainFood_list,mainFood_list[(delete_item-1)*2]);

        for(int p = 0; p < 2; p++)
        {
            mainFood_list.erase(mainFood_list.begin()+ idex);
        }
        writeMainFood(mainFood_list);
        cout << endl;
        cout << "----------------" << endl;
        cout << "| FOOD DELETED |" << endl;
        cout << "----------------" << endl;

        system("PAUSE");
        foodManage();
    }
    else if(choice == 2)
    {
        int delete_item;
        cout << "\n\t\t-----------------------------------------" << endl;
        for(int i = 0;i < addFood_list.size(); i+=2)
        {
            cout << "\t\t| " << (i/2)+1 << ". " << addFood_list[i] << endl;
            cout << "\t\t-----------------------------------------" << endl;
        }
        cout << "\t\t| 0. Exit" << endl;
        cout << "\t\t-----------------------------------------" << endl;
        
        cout << "Which add on food you want delete(number): ";
        cin >> delete_item;
        while(cin.fail() || delete_item > (addFood_list.size()/2) || delete_item < 0)
        {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "|ATTEINTION: Invalid Input!|" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "Enter Again: ";
            cin.clear();
            cin.ignore(256, '\n');
            cin >> delete_item;
        }
        if (delete_item == 0)
        {
            foodManage();
        }

        getIndex(addFood_list,addFood_list[(delete_item-1)*2]);
        for(int p = 0; p < 2; p++)
        {
            addFood_list.erase(addFood_list.begin()+ idex);
        }
        writeAddOnFood(addFood_list);
        cout << endl;
        cout << "-----------------------" << endl;
        cout << "| ADD ON FOOD DELETED |" << endl;
        cout << "-----------------------" << endl;
        system("PAUSE");
        foodManage();
    }
    else if(choice == 3)
    {
        int delete_item;
        cout << "\n\t\t-----------------------------------------" << endl;
        for(int i = 0;i < drink_list.size(); i++)
        {
            cout << "\t\t| " << i+1 << ". " << drink_list[i] << endl;
            cout << "\t\t-----------------------------------------" << endl;
        }
        cout << "\t\t| 0. Exit" << endl;
        cout << "\t\t-----------------------------------------" << endl;
        cout << "Which drink you want delete(number): ";
        cin >> delete_item;
        while(cin.fail() || delete_item > (addFood_list.size()/2) || delete_item < 0)
        {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "|ATTEINTION: Invalid Input!|" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "Enter Again: ";
            cin.clear();
            cin.ignore(256, '\n');
            cin >> delete_item;
        }
        if (delete_item == 0)
        {
            foodManage();
        }

        drink_list.erase(drink_list.begin()+ (delete_item-1));
        drinkPrice_list.erase(drinkPrice_list.begin() + (delete_item-1));

        writeDrink(drink_list);
        writeDrinkPrice(drinkPrice_list);
        cout << endl;
        cout << "-----------------" << endl;
        cout << "| DRINK DELETED |" << endl;
        cout << "-----------------" << endl;

        system("PAUSE");
        foodManage();
    }
    else if(choice == 4)
    {
        foodManage();
    }
}

void buyFood()
{
    vector<string> new_mainFood_list;
    vector<string> new_mainFoodPrice_list;
    vector<string> new_addonFood_list;
    vector<string> new_addonFoodPrice_list;
    vector<string> buyMainFood_list;
    vector<string>buyAddOnFood_List;
    vector<string>buyAddOnFoodPrice_List;
    vector<float> buyMainFoodPrice_list;
    vector<string> storeFood;
    vector<vector<string>> storeFinal;
    float price, addOnPrice, sum3 = 0, sum4 = 0;
    int choice, choice2, times, addOn, addOnMain, stillAddOn, choice5, drinkChoice, drinkChoice2, timesDrink, drinkChoice3,pay_comfirm,delete_package;
    bool loop = true;
    string connect_food;
    vector<string> connectFood_list;
    vector<string> foodbuyer_list;
    vector<float> temp_storePriceList;

    system("CLS");
    time_t tF = time(NULL);
    tm* tptr2 = localtime(&tF);

    int hourClose = tptr2->tm_hour;

    if(hourClose >= 22 || hourClose < 10)
    {
        cout << "------------------------------------------------------------" << endl;
        cout << "| CLOSED..Too Late For Purchasing Food..Buy it tommorow... |" << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << "|   BuyBuyBuy Supermarket open from [ 10 a.m to 10 p.m. ]  |" << endl;
        cout << "------------------------------------------------------------" << endl;
        system("PAUSE");
        userPage();
    }
    getIndex(username_list, name);
    if (estimateKM_list[idex] > 30)
    {
        cout << "\t\t******************************JomEatEatEat*****************************************" << endl;
        cout << "\t\t|Sorry,distance too far...MORE BUYBUYBUY supermarket coming soon in more district.|" << endl;
        cout << "\t\t|                       ********Stay Tune!!********                               |" << endl;
        cout << "\t\t***********************************************************************************" << endl;
        system("PAUSE");
        userPage();

    }
    cout << "\t\t****************JomEatEatEat*****************" << endl;
    cout << "\t\t^^^^^^^^^^^^^^^^^[Food MENU]^^^^^^^^^^^^^^^^^" << endl;
    cout << "\n\t\t\tMAIN FOOD" << endl;

    while (loop)
    {
        system("CLS");
        cout << "\t\t^^^^^^^^^^^^^^^^^[Food MENU]^^^^^^^^^^^^^^^^^" << endl;
        cout << "==========================================================================================" << endl;
        cout << "\n\t\t\t\t -----------" << endl;
        cout << "\t\t\t\t |MAIN FOOD|" << endl;
        cout << "\t\t\t\t -----------" << endl;
        cout << "==========================================================================================" << endl;
        new_mainFood_list.clear();
        new_mainFoodPrice_list.clear();
        for (int i = 0; i < mainFood_list.size(); i += 2)
        {
            new_mainFood_list.push_back(mainFood_list[i]);
            new_mainFoodPrice_list.push_back(mainFood_list[i + 1]);
        }
        for (int i = 0; i < new_mainFood_list.size(); i++)
        {
            cout << setw(25) << i + 1 << ". " << new_mainFood_list[i] << " { RM " << new_mainFoodPrice_list[i] << " }" << endl << endl;
        }

        cout << "\n\nEnter your choice[number / 0 -EXIT]: ";
        cin >> choice;
        while(cin.fail() || (choice > new_mainFood_list.size() || choice < 0))
        {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "|ATTEINTION: Invalid Input!|" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Enter Again: ";
            cin >> choice;
        }
        if(choice == 0)
        {
            userPage();
        }
        cout << "\nQuantity Purchase: ";
        cin >> times;
        while(cin.fail() || times <= 0)
        {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "|ATTEINTION: Invalid Input!|" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Enter Again: ";
            cin >> times;
        }
        for (int j = 0; j < times; j++)
        {
            buyMainFood_list.push_back(new_mainFood_list[choice - 1]);
            price = stof(new_mainFoodPrice_list[choice - 1]);
            buyMainFoodPrice_list.push_back(price);
        }

        system("CLS");
        float sum2 = 0;
        cout << "\t[ YOUR CART] \n-----------------------------------\n";
        sort(buyMainFood_list.begin(), buyMainFood_list.end());
        for (int i = 0; i < buyMainFood_list.size(); i++)
        {
            cout << i + 1 << ". " << buyMainFood_list[i] << endl;
        }
        for (int i = 0; i < buyMainFoodPrice_list.size(); i++)
        {
            sum2 += buyMainFoodPrice_list[i];
        }
        cout << "\n\tTotal Purchase(RM): " << fixed << setprecision(2) << sum2 << endl;
        cout << "-----------------------------------" << endl;
        cout << "1. Delete Item\n2. Continue Purchase Main Food\n3. Next\nEnter your choice(1/2/3) --->";
        cin >> choice2;
        while (choice2 != 1 && choice2 != 2 && choice2 != 3)
        {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "|ATTEINTION: Invalid Choice|" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Enter Again: ";
            cin >> choice2;
        }
        if (choice2 == 1)
        {
            int choice3, choice4;
            do
            {
                system("CLS");
                int delete_item;
                float sum = 0;
                cout << "\t\t[ CART ]" << endl;
                cout << "------------------------------------------" << endl;
                for (int i = 0; i < buyMainFood_list.size(); i++)
                {
                    cout << i + 1 << ". " << buyMainFood_list[i] << endl;
                }
                for (int i = 0; i < buyMainFoodPrice_list.size(); i++)
                {
                    sum += buyMainFoodPrice_list[i];
                }
                cout << "\n\t\tTotal Purchase(RM): " << fixed << setprecision(2) << sum << endl;
                if(sum == 0)
                {
                    cout << endl;
                    cout << "\t------------------------" << endl;
                    cout << "\t|  Your cart is empty. |" << endl;
                    cout << "\t------------------------" << endl;
                    cout << "\t| Back To Main Menu... |" << endl;
                    cout << "\t------------------------" << endl;
                    system("PAUSE");
                    userPage();
                }
                cout << "------------------------------------------" << endl;
                cout << "What item you want to delete(index num): ";
                cin >> delete_item;
                while (cin.fail() || (delete_item > buyMainFood_list.size() || delete_item <= 0))
                {
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    cout << "|ATTEINTION: Invalid Choice|" << endl;
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    cin.clear();
                    cin.ignore(256, '\n');
                    cout << "Enter Again: ";
                    cin >> delete_item;
                }
                buyMainFood_list.erase(buyMainFood_list.begin() + (delete_item - 1));
                buyMainFoodPrice_list.erase(buyMainFoodPrice_list.begin() + (delete_item - 1));
                cout << "\n\nDo you want to continue delete: \n1. YES\n2. NO\nEnter your choice(1/2) ---->";
                cin >> choice3;
                while (choice3 != 1 && choice3 != 2)
                {
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    cout << "|ATTEINTION: Invalid Choice|" << endl;
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    cin.clear();
                    cin.ignore(256, '\n');
                    cout << "Enter Again: ";
                    cin >> choice3;
                }
            } while (choice3 != 2);
            cout << "1. Continue Purchasing" << endl;
            cout << "2. Next" << endl;
            cout << "Enter your choice(1/2) ---> ";
            cin >> choice4;
            while (choice4 != 1 && choice4 != 2)
            {
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                cout << "|ATTEINTION: Invalid Choice|" << endl;
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                cin.clear();
                cin.ignore(256, '\n');
                cout << "Enter Again: ";
                cin >> choice4;
            }
            if (choice4 == 1)
            {
                loop = true;
            }
            else
            {
                loop = false;
            }

        }
        else if (choice2 == 2)
        {
            loop = true;
        }
        else if (choice2 == 3)
        {
            loop = false;
        }
    }

    do
    {
        system("CLS");

        cout << "\t\t[ CART ]" << endl << "------------------------------------------" << endl;
        if(buyMainFood_list.size() == 0)
        {
            cout << endl;
            cout << "+====================+" << endl;
            cout << "| Nothing in cart... |" << endl;
            cout << "+====================+" << endl;
        }
        for (int i = 0; i < buyMainFood_list.size(); i++)
        {
            cout << i + 1 << ". " << buyMainFood_list[i] << endl;
        }
        cout << "------------------------------------------" << endl;
        cout << "Choose which main food that want to add-on in number(Click [0] if no add on): ";
        cin >> addOnMain;
        while (cin.fail() || (addOnMain > buyMainFood_list.size() || addOnMain < 0))
        {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "|ATTEINTION: Invalid Choice|" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Enter Again: ";
            cin >> addOnMain;
        }
        if (addOnMain == 0)
        {
            choice5 = 2;
            break;
        }
        else
        {
            storeFood.push_back(buyMainFood_list[addOnMain - 1]);
            buyMainFood_list.erase(buyMainFood_list.begin() + (addOnMain - 1));
            do
            {
                system("CLS");
                delete_package = 2;
                new_addonFood_list.clear();
                new_addonFoodPrice_list.clear();
                cout << "----------------------------------------\n";
                cout << "\tADD-ON For " << buyMainFood_list[addOnMain-1] << endl;
                cout << "-----------------------------------------" << endl;
                for (int i = 0; i < addFood_list.size(); i += 2)
                {
                    new_addonFood_list.push_back(addFood_list[i]);
                    new_addonFoodPrice_list.push_back(addFood_list[i + 1]);
                }
                for (int j = 0; j < new_addonFood_list.size(); j++)
                {
                    cout << setw(5) << j + 1 << ". " << setw(5) << new_addonFood_list[j] << setw(15) << " { RM " << new_addonFoodPrice_list[j] << " }" << endl << endl;
                }
                cout << "==========================================================" << endl;

                cout << "Enter index number for add-on: ";
                cin >> addOn;
                while (cin.fail() || (addOn > new_addonFood_list.size() || addOn <= 0))
                {
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    cout << "|ATTEINTION: Invalid Choice|" << endl;
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    cin.clear();
                    cin.ignore(256, '\n');
                    cout << "Enter Again: ";
                    cin >> addOn;
                }

                storeFood.push_back(new_addonFood_list[addOn - 1]);
                addOnPrice = stof(new_addonFoodPrice_list[addOn - 1]);
                temp_storePriceList.push_back(addOnPrice);
                cout << "'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''" << endl;
                cout << "PACKAGE: ";
                for(int i = 0; i < storeFood.size(); i++)
                {
                    cout << storeFood[i] << " || ";
                }
                cout << endl << "''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''" << endl;
                cout << endl;
                cout << "\nDo you still want add on on this main food?\n";
                cout << "1. YES\n2. NO\n3. Delete This Package" << endl;
                cout << "Enter your choice(1/2/3) ---> ";
                cin >> stillAddOn;
                while (stillAddOn != 1 && stillAddOn != 2 && stillAddOn != 3)
                {
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    cout << "|ATTEINTION: Invalid Choice|" << endl;
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    cin.clear();
                    cin.ignore(256, '\n');
                    cout << "Enter Again: ";
                    cin >> stillAddOn;
                }
                if(stillAddOn == 3)
                {
                    stillAddOn = 2;
                    delete_package = 1;
                }
                
            } while (stillAddOn != 2);
        }
        cout << "----------------------------------------------------------------------" << endl << endl;
        if(delete_package == 1)
        {
            int select_delete;
            getIndex(mainFood_list,storeFood[0]);
            
            
            cout << "1. Delete Whole Package" << endl;
            cout << "2. Keep main food(ONLY DELETE ADD-ON FOOD)" << endl;
            cout << "Enter number (1/2): ";
            cin >> select_delete;
            while (select_delete != 1 && select_delete != 2)
            {
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                cout << "|ATTEINTION: Invalid Choice|" << endl;
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                cin.clear();
                cin.ignore(256, '\n');
                cout << "Enter Again: ";
                cin >> select_delete;
            }
            if(select_delete == 1)
            {
                temp_storePriceList.clear();
                buyMainFoodPrice_list.push_back(stof(mainFood_list[idex+1])*(-1));
                storeFood.clear();
                cout << endl;
                cout << "+----------------------+" << endl;
                cout << "|  Package DELETED...  |" << endl;
                cout << "+----------------------+" << endl;
            }
            else
            {
                temp_storePriceList.clear();
                buyMainFood_list.push_back(storeFood[0]);
                storeFood.clear();
                cout << endl;
                cout << "+--------------------------+" << endl;
                cout << "|  ADD ON Food DELETED...  |" << endl;
                cout << "+--------------------------+" << endl;
            }
            
            
        }
        else
        {
            for(int i= 0; i < temp_storePriceList.size(); i++)
            {
                buyMainFoodPrice_list.push_back(temp_storePriceList[i]);
            }
            cout << "Food packed...cancel from cart..." << endl;
            cout << "-----------------------------------------------------" << endl;
            storeFinal.push_back(storeFood);
            storeFood.clear();
            temp_storePriceList.clear();
        }
        cout << "\nDo You Still Want Add On Other Main Food(1/2): " << endl;
        cout << "1. YES\n2. NO" << endl;
        cout << "Enter your choice ---> ";
        cin >> choice5;
        while (choice5 != 1 && choice5 != 2)
        {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "|ATTEINTION: Invalid Choice|" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Enter Again: ";
            cin >> choice5;
        }
        
        

    } while (choice5 != 2);

    for (int i = 0; i < buyMainFood_list.size(); i++)
    {
        storeFood.clear();
        storeFood.push_back(buyMainFood_list[i]);
        storeFinal.push_back(storeFood);
    }

    system("CLS");
    vector<float> calculatePackage_list;
    vector<float> finialPackagePrice_list;
    vector<string> drinkChoice_list;
    vector<float> drinkChoicePrice_list;
    float package_price;


    for (int i = 0; i < storeFinal.size(); i++)
    {
        float total = 0;
        calculatePackage_list.clear();
        getIndex(mainFood_list, storeFinal[i][0]);
        package_price = stof(mainFood_list[idex + 1]);
        calculatePackage_list.push_back(package_price);
        if (storeFinal[i].size() > 0)
        {
            for (int j = 1; j < storeFinal[i].size(); j++)
            {
                getIndex(addFood_list, storeFinal[i][j]);
                package_price = stof(addFood_list[idex + 1]);
                calculatePackage_list.push_back(package_price);
            }
        }
        else
        {
            calculatePackage_list.push_back(0);
        }
        for (float k : calculatePackage_list)
        {
            total += k;
        }
        finialPackagePrice_list.push_back(total);
    }

    cout << "Do you want add some drink: " << endl;
    cout << "1. YES\n2. NO\n";
    cout << "Enter your choice(1/2) ---> ";
    cin >> drinkChoice;
    while (drinkChoice != 1 && drinkChoice != 2)
    {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "|ATTEINTION: Invalid Choice|" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Enter Again: ";
        cin >> drinkChoice;
    }
    if (drinkChoice == 1)
    {
        system("CLS");
        cout << "-------------------------------------------" << endl;
        cout << "\tDRINK LIST" << endl;
        cout << "-------------------------------------------" << endl;
        do
        {
            for (int i = 0; i < drink_list.size(); i++)
            {
                cout << setw(2) << i + 1 << ". " << setw(10) << drink_list[i] << setw(10) << "RM " << drinkPrice_list[i] << endl << endl;
            }
            cout << "-------------------------------------------" << endl;
            cout << "Enter your choice(index num): ";
            cin >> drinkChoice2;

            while (cin.fail() || (drinkChoice2 > drink_list.size() || drinkChoice2 <= 0))
            {
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                cout << "|ATTEINTION: Invalid Choice|" << endl;
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                cin.clear();
                cin.ignore(256, '\n');
                cout << "Enter Again: ";
                cin >> drinkChoice2;
            }

            cout << "\nQuantity Drink Purchase: ";
            cin >> timesDrink;
            while (cin.fail() || timesDrink < 0)
            {
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                cout << "|ATTEINTION: Invalid Input|" << endl;
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                cin.clear();
                cin.ignore(256, '\n');
                cout << "Enter Again: ";
                cin >> timesDrink;
            }
            for (int i = 0; i < timesDrink; i++)
            {
                drinkChoice_list.push_back(drink_list[drinkChoice2 - 1]);
                drinkChoicePrice_list.push_back(drinkPrice_list[drinkChoice2 - 1]);
            }
            cout << "\n-------------------------------------------" << endl;
            cout << "Do you want add more drink?" << endl;
            cout << "1. YES\n2. NO" << endl << "Enter your choice in number(1/2) ---> ";
            cin >> drinkChoice3;
            while (drinkChoice3 != 1 && drinkChoice3 != 2)
            {
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                cout << "|ATTEINTION: Invalid Choice|" << endl;
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                cin.clear();
                cin.ignore(256, '\n');
                cout << "Enter Again: ";
                cin >> drinkChoice3;
            }
        } while (drinkChoice3 != 2);

    }

    system("CLS");
    int foodNum = checkFoodRecord_list.size()/3 + 1001;
    string str_foodnum = to_string(foodNum);
    cout << "=================================== FOOD RECEIPT ==================================" << endl;
    cout << "\t\t\t\t\t\t\tFood No.: " << str_foodnum << endl;
    cout << "FOOD PACKAGES" << endl << "---------------------" << endl;
    for (int i = 0; i < storeFinal.size(); i++)
    {
        string spacebar = " || ";
        connect_food = " ";
        cout << i + 1 << ". ";
        for (int j = 0; j < storeFinal[i].size(); j++)
        {
            cout << setw(5) << "[" << storeFinal[i][j] << "] ";
            connect_food.append(storeFinal[i][j] + spacebar);
        }
        connectFood_list.push_back(connect_food);
        cout << "{ RM " << fixed << setprecision(2) << finialPackagePrice_list[i] << " }\n";
    }

    for (int i = 0; i < buyMainFoodPrice_list.size(); i++)
    {
        sum3 += buyMainFoodPrice_list[i];
    }
    cout << "\n\n\t\t\t\t\t\tTotal Purchase For Food(RM): " << fixed << setprecision(2) << sum3 << endl;

    cout << "Drink\n--------------------------\n";
    for (int i = 0; i < drinkChoice_list.size(); i++)
    {
        cout << i + 1 << ". " << drinkChoice_list[i] << "\t\t\tRM " << drinkChoicePrice_list[i] << endl;
    }

    if(drinkChoice_list.size() == 0)
    {
        drinkChoice_list.push_back("NULL");
    }

    for (float i : drinkChoicePrice_list)
    {
        sum4 += i;
    }

    time_t t = time(NULL);
    tm* tptr = localtime(&t);

    int hour = tptr->tm_hour;
    int min = tptr->tm_min;
    int final_time;
    float time;
    string apm;
    string buyTime;
    if (hour >= 0 && hour < 12)
    {
        apm = " AM";
    }
    else
    {
        apm = " PM";
    }
    buyTime = to_string(hour) + " : " +to_string(min) + apm;
    getIndex(username_list, name);
    final_time = min + (estimateKM_list[idex] * 3) + 5;
    if (final_time >= 60)
    {
        min = final_time % 60;
        hour++;
    }
    else
    {
        min = final_time;
    }

    if (hour >= 0 && hour < 12)
    {
        apm = " AM";
    }
    else
    {
        apm = " PM";
    }

    string arrived_time;
    if(min < 10)
    {
        arrived_time = to_string(hour) + " : " + "0" + to_string(min) + apm;
    }
    else
    {
        arrived_time = to_string(hour) + " : " +to_string(min) + apm;
    }

    cout << "\n\n\t\t\t\t\t\tTotal Purchase For Drink(RM): " << fixed << setprecision(2) << sum4 << endl;
    cout << "==================================================================================================" << endl;
    cout << "\nTotal Purchase: RM " << fixed << setprecision(2) << sum3 + sum4 << endl;
    cout << "Estimate arrived Time: " << arrived_time << endl;
    getIndex(username_list, name);
    cout << "Address delivered: " << address_list[idex] << endl;

    cout << "-------------------------------------------------------------------------------------------------------------" << endl;
    cout << "PAYMENT CONFIRM" << endl;
    cout << "----------------------" << endl;
    cout << "1. CONFIRM" << endl;
    cout << "2. CANCEL.BUY AGAIN NEXT TIME!" << endl;
    cout << "Enter your choice(1/2): ";
    cin >> pay_comfirm;
    while(pay_comfirm != 1 && pay_comfirm != 2)
    {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "|ATTEINTION: Invalid Choice|" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Enter Again: ";
        cin >> pay_comfirm;
    }

    if(pay_comfirm == 1)
    {
        getIndex(username_list,name);
        foodbuyer_list.push_back(to_string(sum3 + sum4).substr(0,to_string(sum3+sum4).find(".") + 0 + 2));
        foodbuyer_list.push_back(str_foodnum);
        foodbuyer_list.push_back(username_list[idex]);
        foodbuyer_list.push_back(buyTime);
        foodbuyer_list.push_back(arrived_time);
        foodbuyer_list.push_back(phone_list[idex]);
        foodbuyer_list.push_back(address_list[idex]);
        foodbuyer_list.push_back("Preparing");
        checkFoodRecord_list.push_back(foodbuyer_list);
        checkFoodRecord_list.push_back(connectFood_list);
        checkFoodRecord_list.push_back(drinkChoice_list);
        writeFoodRecord(checkFoodRecord_list);
        cout << "----------------------------------------------------------" << endl;
        cout << "| Payement Success Using TNG Wallet! Back To userpage... |" << endl;
        cout << "----------------------------------------------------------" << endl;
        system("PAUSE");
        userPage();
    }
    else
    {
        cout << "------------------------------------------" << endl;
        cout << "| Payment Cancelled..Back To userpage... |" << endl;
        cout << "------------------------------------------" << endl;
        userPage();
    }
    


    system("PAUSE");

    userPage();

}


void shopManage()
{
    system("CLS");
    readProduct();
    readProductType();
    int choice;
    cout << "\t\t---------------------------------------" << endl;
    cout << "\t\t|          Product Management         |" << endl;
    cout << "\t\t---------------------------------------" << endl;
    cout << "\t\t|          1. LIST ALL PRODUCTS       |" << endl;
    cout << "\t\t---------------------------------------" << endl;
    cout << "\t\t|          2. Add Product             |" << endl;
    cout << "\t\t---------------------------------------" << endl;
    cout << "\t\t|          3. Add Category            |" << endl;
    cout << "\t\t---------------------------------------" << endl;
    cout << "\t\t|          4. EDIT Product            |" << endl;
    cout << "\t\t---------------------------------------" << endl;
    cout << "\t\t|          5. Delete Product          |" << endl;
    cout << "\t\t---------------------------------------" << endl;
    cout << "\t\t|          6. BACK                    |" << endl;
    cout << "\t\t---------------------------------------" << endl;
    cout << "......................................................................................................." << endl;
    cout << "\t\tEnter your choice(num): ";
    cin >> choice;
    while (choice != 1 && choice != 2  && choice != 3  && choice != 4 && choice != 5 && choice != 6)
    {
        cout << "\n..................................................................." << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "|ATTEINTION: Invalid Choice|" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Enter Again: ";
        cin >> choice;
    }
    if (choice == 1)
    {
        system("CLS");
        readProduct();
        readProductType();
        cout << "\t\t ^^^^^^SLOGAN BuyBuyBuy Supermarket^^^^^^" << endl;
        cout << "-----------------------------------------------------------------------" << endl;
        cout << "\t\t\t<<  BUY MORE OFFER MORE  >>" << endl;
        cout << "\t\t\t<< BUY RM100 For 1 Token >>" << endl;
        cout << "============================Promtion Price=============================" << endl;
        cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
        for (int k = 0; k < buyItemType_list.size(); k++)
        {
            cout << buyItemType_list[k] << endl;
            cout << "-------------------------------------------------------------------------------------------" << endl;
            for (int j = 0; j < buyItem_list[k].size(); j += 5)
            {
                cout << "\t| 1. Product Name                      : " << buyItem_list[k][j] << endl;
                cout << "\t| 2. Product Price                     : RM " << buyItem_list[k][j + 1] << endl;
                cout << "\t| 3. Amount Buy For Promotion          : " << buyItem_list[k][j + 2] << endl;
                cout << "\t| 4. Promotion (Per Unit)              : " << buyItem_list[k][j + 3] << " %" << endl;
                cout << "\t| 5. Total Sale                        : " << buyItem_list[k][j + 4] << endl;
                cout << "=======================================================================================" << endl;
            }
        }
    }
    else if (choice == 2)
    {
        int select;
        string new_item, new_price, new_amount, new_discount;
        cout << "........................................................................" << endl << endl;
        cout << "\t---------------------------------------" << endl;
        cout << "\t| What category chosen to add in item |" << endl;
        cout << "\t---------------------------------------" << endl;
        for (int i = 0; i < buyItemType_list.size(); i++)
        {
            cout << "-------------------------------------------------------------" << endl;
            cout << "|\t\t" << i + 1 << ". " << buyItemType_list[i] << endl;
            cout << "|------------------------------------------------------------" << endl;
        }
        cout << "|------------------------------------------------------------" << endl;
        cout << "Enter your choice[num | 0 - EXIT]:  ";
        cin >> select;
        while (cin.fail() || (select > buyItemType_list.size() || select < 0))
        {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "|ATTEINTION: Invalid Input!|" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "Enter Again: ";
            cin.clear();
            cin.ignore(256, '\n');
            cin >> choice;
        }
        if(select == 0)
        {
            shopManage();
        }
        cout << endl;
        cout << "1. What item do you want to add    ---> ";
        getline(cin >> ws, new_item);
        cout << "\n------------------------------------------------------" << endl;
        

        cout << "2. What is the price               ---> RM ";
        getline(cin >> ws, new_price);
        cout << "\n------------------------------------------------------" << endl;
        
        cout << "3. Amount Item To Buy For Discount ---> ";
        getline(cin >> ws, new_amount);
        cout << "\n------------------------------------------------------" << endl;

        cout << "4. How much discount(%)            ---> ";
        getline(cin >> ws, new_discount);
        cout << "\n------------------------------------------------------" << endl;
        
        buyItem_list[select - 1].push_back(new_item);
        buyItem_list[select - 1].push_back(new_price);
        buyItem_list[select - 1].push_back(new_amount);
        buyItem_list[select - 1].push_back(new_discount);
        buyItem_list[select - 1].push_back("0");
        writeProduct(buyItem_list);
    }
    else if (choice == 3)
    {
        string new_category;
        string new_item2, new_price2, new_amount2, new_discount2;
        vector<string> addItemList;
        cout << endl;
        cout << "What category you want to add [0 -EXIT]: ";
        getline(cin >> ws, new_category);
        if(new_category == "0")
        {
            shopManage();
        }
        buyItemType_list.push_back(new_category);
        buyItem_list.push_back(addItemList);
        getIndex(buyItemType_list, new_category);

        cout << "--------------------------------------------------------" << endl;

        cout << "1. What item do you want to add ---> ";
        getline(cin >> ws, new_item2);
        cout << "--------------------------------------------------------" << endl;
        

        cout << "2. What is the price ----> RM ";
        getline(cin >> ws, new_price2);
        cout << "--------------------------------------------------------" << endl;
        

        cout << "3. Amount Item To Buy For Discount ---> ";
        getline(cin >> ws, new_amount2);
        cout << "--------------------------------------------------------" << endl;
        

        cout << "4. How much discount(%) ----> ";
        getline(cin >> ws, new_discount2);
        cout << "--------------------------------------------------------" << endl;
        

        buyItem_list[idex].push_back(new_item2);
        buyItem_list[idex].push_back(new_price2);
        buyItem_list[idex].push_back(new_amount2);
        buyItem_list[idex].push_back(new_discount2);
        buyItem_list[idex].push_back("0");

        writeProductType(buyItemType_list);
        writeProduct(buyItem_list);

    }
    else if(choice == 4)
    {
        editShopItem();
    }
    else if(choice == 5)
    {
        deleteShopItem();
    }
    else if(choice == 6)
    {
        adminProductControl();
    }
    system("PAUSE");
    shopManage();
}


void editShopItem()
{
    system("CLS");

    int choice;
    vector<string> store_item;

    cout << "What category item you want to edit: " << endl;

    for(int k = 0; k< buyItemType_list.size();k++)

    {
        cout << "-------------------------------------------------------------------------" << endl;
        cout << "| " << k+1 << ". " << buyItemType_list[k] << endl;
        cout << "-------------------------------------------------------------------------" << endl;
    }
    cout << "-------------------------------------------------------------------------" << endl;
    cout << "| 0 - EXIT" << endl;
    cout << "-------------------------------------------------------------------------" << endl;
    cout << "Enter number of your choice: ";
    cin >> choice;

    if(choice == 0)
    {
        shopManage();
    }
    
    for(int i = 0;i <buyItem_list[choice-1].size(); i+=5)
    {
        store_item.push_back(buyItem_list[choice-1][i]);
    }
    system("CLS");
    cout << "\t--------------------------------------------------------" << endl;
    cout << "\t|                      PRODUCT                         |" << endl;
    cout << "\t--------------------------------------------------------" << endl;
    for(int j = 0; j < store_item.size(); j++)
    {
        cout << "\t|\t" << j+1 << ". " << store_item[j] << endl;
        cout << "\t--------------------------------------------------------" << endl;
    }
    cout << "========================================================================================================" << endl;
    cout << "What Item You Want To Edit(NUMBER): " ;
    string edit_price,edit_number,edit_promo;
    int choice2;
    cin >> choice2;
    getIndex(buyItem_list[choice-1],store_item[choice2-1]);

    cout << "1. Product Name: " << store_item[choice2-1] << endl;

    cout << "2. Product Price: RM ";
 
    getline(cin >> ws,edit_price);
 
    buyItem_list[choice-1][idex+1] = edit_price;
 
 
    cout << "3. Total Item Buy For Discount: ";
 
    getline(cin >> ws,edit_number);
 
    buyItem_list[choice-1][idex+2] = edit_number;
 
 
    cout << "4. Discount(%): ";
 
    getline(cin >> ws, edit_promo);
 
    buyItem_list[choice-1][idex+3] = edit_promo; 

    writeProduct(buyItem_list);
    cout << "----------" << endl;
    cout << "| EDITED |" << endl;
    cout << "----------" << endl;
}

void deleteShopItem()
{
    system("CLS");
    string item;
    vector<string> store_item;
    int delete_item, choice;
    
    cout << "\t\t-----------------------------------------" << endl;
    cout << "\t\t|What category item you want to delete: |" << endl;
    cout << "\t\t-----------------------------------------" << endl;
    for (int k = 0; k < buyItemType_list.size(); k++)
    {
        cout << "\t\t| " << k + 1 << ". " << buyItemType_list[k] << endl;
        cout << "\t\t-----------------------------------------" << endl;
    }
    cout << "\t\t| 0. Exit" << endl;
    cout << "\t\t-----------------------------------------" << endl;
    cout << "\t\tEnter your choice(num): ";
    cin >> choice;
    while(cin.fail() || choice > buyItem_list.size() || choice < 0)
    {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "|ATTEINTION: Invalid Input!|" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "Enter Again: ";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> choice;
    }
    if (choice == 0)
    {
        shopManage();
    }
    for (int i = 0; i < buyItem_list[choice - 1].size(); i += 5)
    {
        store_item.push_back(buyItem_list[choice - 1][i]);
    }
    cout << "\n==========================================================================" << endl;
    for (int j = 0; j < store_item.size(); j++)
    {
        cout << "\t\t| " << j + 1 << ". " << store_item[j] << endl;
        cout << "\t\t-----------------------------------------" << endl;
    }
    cout << "\t\t| 0. Exit" << endl;
    cout << "\t\t-----------------------------------------" << endl;

    cout << "Which product you want to delete(number): ";
    cin >> delete_item;
    while(cin.fail() || delete_item > store_item.size() || delete_item < 0)
    {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "|ATTEINTION: Invalid Input!|" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "Enter Again: ";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> delete_item;
    }

    if(delete_item == 0)
    {
        shopManage();
    }
    getIndex(buyItem_list[choice - 1], store_item[delete_item - 1]);


    if (buyItem_list[choice-1].size() == 5)
    {
        buyItemType_list.erase(buyItemType_list.begin() + (choice-1));
        cout << "+-------------------------------------------------------------------------+" << endl;
        cout << "|ATTENTION: LAST PRODUCT IN THIS CATEGORY. CATEGORY ALSO WILL DELETED TOO!|" << endl;
        cout << "+-------------------------------------------------------------------------+" << endl;
        system("PAUSE");
    }
    writeProductType(buyItemType_list);


    for (int p = 0; p < 5; p++)
    {
        buyItem_list[choice - 1].erase(buyItem_list[choice - 1].begin() + (idex));
    }
    writeProduct(buyItem_list);
    cout << endl;
    cout << "----------------" << endl;
    cout << "| ITEM DELETED |" << endl;
    cout << "----------------" << endl;
}


void checkInvoice()
{
    system("CLS");
    readPurchaseRecord();
    readPurchaseStatus();
    int choice;
    cout << "\t\t\t===============================================" << endl;
    cout << "\t\t\t|             Admin Invoice Recorder          |" << endl;
    cout << "\t\t\t===============================================" << endl;
    cout << "\t\t\t|              1. List All                    |" << endl;
    cout << "\t\t\t-----------------------------------------------" << endl;
    cout << "\t\t\t|              2. Search Invoice No.          |" << endl;
    cout << "\t\t\t-----------------------------------------------" << endl;
    cout << "\t\t\t|              3. Search Using Username       |" << endl;
    cout << "\t\t\t-----------------------------------------------" << endl;
    cout << "\t\t\t|              4. Mark For Delivering         |" << endl;
    cout << "\t\t\t-----------------------------------------------" << endl;
    cout << "\t\t\t|              5. Mark For Delivered          |" << endl;
    cout << "\t\t\t-----------------------------------------------" << endl;
    cout << "\t\t\t|              6. Back                        |" << endl;
    cout << "\t\t\t-----------------------------------------------" << endl;
    cout << "Enter your choice in number(1/2/3/4/5/6): ";
    cin >> choice;
    while(choice != 1 && choice != 2  && choice != 3  && choice != 4 && choice != 5 && choice != 6)
    {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "|ATTEINTION: Invalid Input!|" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "Enter Again: ";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> choice;
    }

    if (choice == 1)
    {
        system("CLS");
        cout << "\t*****************LATEST BUYER PURCHASE RECORD*****************" << endl;
        for(int i = 0; i < buy_record_list.size(); i++)
        {
            cout << "================================================================================\n";
            cout << "\t\t\t\t\tUsername: " << buy_record_list[i][1] << endl;
            cout << "\t\t\t\t\tStatus: " << checkStatusPurchase_list[i] << endl;
            cout << "\t\t\t\t\tInvoice No.: " << buy_record_list[i][0] << endl;
            cout << "\t\t\t\t\tDate Purchase: " << buy_record_list[i][2] << endl << endl;
            cout << "------------------------------------------------------------------------" << endl;
            cout << setw(30) << "Item Name" << setw(30) << "Quantity" << endl;
            cout << "------------------------------------------------------------------------" << endl;
            for (int k = 3; k < buy_record_list[i].size() - 4; k += 2)
            {
                cout << setw(30) << buy_record_list[i][k] << setw(30) << buy_record_list[i][k + 1] << endl;
            }
            float paid = stof(buy_record_list[i][buy_record_list[i].size() - 4]);
            cout << "\n\nTotal Paid = RM " << fixed << setprecision(2) << paid << endl;
            cout << "Estimate arrived date: " << buy_record_list[i][buy_record_list[i].size()-3] << endl;
            cout << "Hp Num: " << buy_record_list[i][buy_record_list[i].size()-2] << endl;
            cout << "Deliver Address: " << buy_record_list[i].back() << endl;
            cout << "================================================================================\n";

        }
        cout << "\n\t\t\t\t[[[[END OF DATA]]]]" << endl;
        system("PAUSE");
        checkInvoice();
    }
    else if(choice == 2)
    {
        system("CLS");
        int search_invoice,final_search;
        cout << "Enter Invoice No.: ";
        cin >> search_invoice;
        while(cin.fail() || search_invoice > buy_record_list.size()+1001 || search_invoice < 1001)
        {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "|ATTEINTION: Invoice No. Not Found! [0-EXIT]|" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "Enter Again: ";
            cin.clear();
            cin.ignore(256, '\n');
            cin >> search_invoice;
            if (search_invoice == 0)
            {
                checkInvoice();
            }
        }
        final_search = search_invoice - 1001;
        system("CLS");
        cout << "\t*****************LASTEST PURCHASE RECORD*****************" << endl;
        cout << "================================================================================\n";
        cout << "\t\t\t\t\tUsername: " << buy_record_list[final_search][1] << endl;
        cout << "\t\t\t\t\tInvoice No.: " << buy_record_list[final_search][0] << endl;
        cout << "\t\t\t\t\tStatus: " << checkStatusPurchase_list[final_search] << endl;
        cout << "\t\t\t\t\tDate Purchase: " << buy_record_list[final_search][2] << endl << endl;
        cout << "------------------------------------------------------------------------" << endl;
        cout << setw(30) << "Item Name" << setw(30) << "Quantity" << endl;
        cout << "------------------------------------------------------------------------" << endl;
        for (int i = 3; i < buy_record_list[final_search].size() - 4; i += 2)
        {
            cout << setw(30) << buy_record_list[final_search][i] << setw(30) << buy_record_list[final_search][i + 1] << endl;
        }
        float paid = stof(buy_record_list[final_search][buy_record_list[final_search].size() - 4]);
        cout << "\n\nTotal Paid = RM " << fixed << setprecision(2) << paid << endl;
        cout << "Estimate arrived date: " << buy_record_list[final_search][buy_record_list[final_search].size()-3] << endl;
        cout << "Hp Num: " << buy_record_list[final_search][buy_record_list[final_search].size()-2] << endl;
        cout << "Deliver Address: " << buy_record_list[final_search].back() << endl;
        system("PAUSE");
        checkInvoice();
    }
    else if(choice == 3)
    {
        system("CLS");
        string buyer_name;
        cout << "Search buyer email [0 - EXIT ]: ";
        getline(cin >> ws,buyer_name);
        if(buyer_name == "0")
        {
            checkInvoice();
        }
        
        for(int i = 0; i < buy_record_list.size(); i++)
        {
            if(buy_record_list[i][1] == buyer_name)
            {
                cout << "\t*****************LASTEST BUYER PURCHASE RECORD*****************" << endl;
                cout << "================================================================================\n";
                cout << "\t\t\t\t\tUsername: " << buy_record_list[i][1] << endl;
                cout << "\t\t\t\t\tInvoice No.: " << buy_record_list[i][0] << endl;
                cout << "\t\t\t\t\tStatus: " << checkStatusPurchase_list[i] << endl;
                cout << "\t\t\t\t\tDate Purchase: " << buy_record_list[i][2] << endl << endl;
                cout << "------------------------------------------------------------------------" << endl;
                cout << setw(30) << "Item Name" << setw(30) << "Quantity" << endl;
                cout << "------------------------------------------------------------------------" << endl;
                for (int k = 3; k < buy_record_list[i].size() - 4; k += 2)
                {
                    cout << setw(30) << buy_record_list[i][k] << setw(30) << buy_record_list[i][k + 1] << endl;
                }
                float paid = stof(buy_record_list[i][buy_record_list[i].size() - 4]);
                cout << "\n\nTotal Paid = RM " << fixed << setprecision(2) << paid << endl;
                cout << "Estimate arrived date: " << buy_record_list[i][buy_record_list[i].size()-3] << endl;
                cout << "Hp Num: " << buy_record_list[i][buy_record_list[i].size()-2] << endl;
                cout << "Deliver Address: " << buy_record_list[i].back() << endl;
                cout << "================================================================================\n";

            }
        }
        cout << "----------------------" << endl;
        cout << "|     Nothing Else    |"<< endl;
        cout << "----------------------"<< endl;
        system("PAUSE");
        checkInvoice();

    }
    else if(choice == 4)
    {
        string invoice;
        vector<string> invoice_list;

        if(find(checkStatusPurchase_list.begin(),checkStatusPurchase_list.end(),"Pending") != checkStatusPurchase_list.end())
        {
            cout << "+-----------------+" << endl;
            cout << "| Displaying..... |" << endl;
            cout << "+-----------------+" << endl;
        }
        else
        {
            cout << "-----------------------" << endl;
            cout << "| Nothing in pending! |" << endl;
            cout << "-----------------------" << endl;
            system("PAUSE");
            checkInvoice();
        }
        for(int i = 0; i < buy_record_list.size() ; i++)
        {
            if (checkStatusPurchase_list[i] == "Pending")
            {
                cout << "================================================================================\n";
                cout << "\t\t\t\t\tUsername: " << buy_record_list[i][1] << endl;
                cout << "\t\t\t\t\tInvoice No.: " << buy_record_list[i][0] << endl;
                invoice_list.push_back(buy_record_list[i][0]);
                cout << "\t\t\t\t\tStatus: " << checkStatusPurchase_list[i] << endl;
                cout << "\t\t\t\t\tDate Purchase: " << buy_record_list[i][2] << endl << endl;
                cout << "------------------------------------------------------------------------" << endl;
                cout << setw(30) << "Item Name" << setw(30) << "Quantity" << endl;
                cout << "------------------------------------------------------------------------" << endl;
                for (int k = 3; k < buy_record_list[i].size() - 4; k += 2)
                {
                    cout << setw(30) << buy_record_list[i][k] << setw(30) << buy_record_list[i][k + 1] << endl;
                }
                float paid = stof(buy_record_list[i][buy_record_list[i].size() - 2]);
                cout << "\n\nTotal Paid = RM " << fixed << setprecision(2) << paid << endl;
                cout << "Estimate arrived date: " << buy_record_list[i][buy_record_list[i].size()-3] << endl;
                cout << "Hp Num: " << buy_record_list[i][buy_record_list[i].size()-2] << endl;
                cout << "Deliver Address: " << buy_record_list[i].back() << endl;
                cout << "================================================================================\n";
            }
        }

        do
        {
            cout << "Enter Invoice number for delivering [0 -EXIT]: ";
            getline(cin >> ws,invoice);
            
            if(find(invoice_list.begin(),invoice_list.end(),invoice)!= invoice_list.end())
            {
                checkStatusPurchase_list[stoi(invoice)-1001] = "Delivering";
                cout << "UPDATED" << endl;
            }
            else
            {
                cout << "Invoice number not available.." << endl;
            }
            cout << "=======================================================================" << endl;
        } while (invoice != "0");
        writeStatusPurchase(checkStatusPurchase_list);
        checkInvoice();
    }
    else if(choice == 5)
    {
        string invoice;
        vector<string> invoice_list;

        if(find(checkStatusPurchase_list.begin(),checkStatusPurchase_list.end(),"Delivering") != checkStatusPurchase_list.end())
        {
            cout << "+-----------------+" << endl;
            cout << "| Displaying..... |" << endl;
            cout << "+-----------------+" << endl;
        }
        else
        {
            cout << "Nothing in delivering!" << endl;
            system("PAUSE");
            checkInvoice();
        }
        for(int i = 0; i < buy_record_list.size() ; i++)
        {
            if (checkStatusPurchase_list[i] == "Delivering")
            {
                cout << "================================================================================\n";
                cout << "\t\t\t\t\tUsername: " << buy_record_list[i][1] << endl;
                cout << "\t\t\t\t\tInvoice No.: " << buy_record_list[i][0] << endl;
                invoice_list.push_back(buy_record_list[i][0]);
                cout << "\t\t\t\t\tStatus: " << checkStatusPurchase_list[i] << endl;
                cout << "\t\t\t\t\tDate Purchase: " << buy_record_list[i][2] << endl << endl;
                cout << "------------------------------------------------------------------------" << endl;
                cout << setw(30) << "Item Name" << setw(30) << "Quantity" << endl;
                cout << "------------------------------------------------------------------------" << endl;
                for (int k = 3; k < buy_record_list[i].size() - 4; k += 2)
                {
                    cout << setw(30) << buy_record_list[i][k] << setw(30) << buy_record_list[i][k + 1] << endl;
                }
                float paid = stof(buy_record_list[i][buy_record_list[i].size() - 4]);
                cout << "\n\nTotal Paid = RM " << fixed << setprecision(2) << paid << endl;
                cout << "Estimate arrived date: " << buy_record_list[i][buy_record_list[i].size() - 3] << endl;
                cout << "Hp Num: " << buy_record_list[i][buy_record_list[i].size()-2] << endl;
                cout << "Deliver Address: " << buy_record_list[i].back() << endl;
                cout << "================================================================================\n";
            }
        }

        do
        {
            cout << "Enter Invoice number for delivered [0 -EXIT]: ";
            getline(cin >> ws,invoice);
            

            if(find(invoice_list.begin(),invoice_list.end(),invoice) != invoice_list.end())
            {
                checkStatusPurchase_list[stoi(invoice)-1001] = "Delivered";
                cout << "UPDATED" << endl;
            }
            else
            {
                cout << "Invoice number not available.." << endl;
            }
            cout << "=======================================================================" << endl;
        } while (invoice != "0");
        writeStatusPurchase(checkStatusPurchase_list);
        checkInvoice();

    }
    else if (choice == 6)
    {
        adminProductControl();
    }

}

void userDetails()
{
    system("CLS");
    int choice;
    readNameFile();
    readRegisterDate();
    readChatAdmin();
    readChatAI();
    cout << "\t\t---------------------------------" << endl;
    cout << "\t\t|         USER DETAILS          |" << endl;
    cout << "\t\t---------------------------------" << endl;
    cout << "\t\t| 1. LIST ALL USERS             |" << endl;
    cout << "\t\t---------------------------------" << endl;
    cout << "\t\t| 2. Search Using Email Address |" << endl;
    cout << "\t\t---------------------------------" << endl;
    cout << "\t\t| 3. Ban User Account           |" << endl;
    cout << "\t\t---------------------------------" << endl;
    cout << "\t\t| 4. Unban User Account         |" << endl;
    cout << "\t\t---------------------------------" << endl;
    cout << "\t\t| 5. Back                       |" << endl;
    cout << "\t\t---------------------------------" << endl;
    cout << "Enter your choice(1/2/3/4/5): ";
    cin >> choice;
    while(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5)
    {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "|ATTEINTION: Invalid Input!|" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "Enter Again: ";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> choice;
    }
    
    if(choice == 1)
    {
        system("CLS");
        cout << "USERS DETAILS" << endl;
        cout << "-------------------" << endl;
        for(int i = 0; i< username_list.size(); i++)
        {
            cout << "-------------------------------------------------------------------------------------------------" << endl;
            cout << "| User No.      | " << i + 1 << endl;
            cout << "| Name          | " << userInfo_list[i*4] << endl;
            cout << "| IC            | " << userInfo_list[(i*4)+1] << endl;
            cout << "| Age           | " << userInfo_list[(i*4)+2] << endl;
            cout << "| Gender        | " << userInfo_list[(i*4)+3] << endl;
            cout << "| Email         | " << username_list[i] << endl;
            cout << "| Password      | " << password_list[i] << endl;
            cout << "| Hp Num        | " << phone_list[i] << endl;
            cout << "| Address       | " << address_list[i] << endl;
            cout << "| Voucher       | RM " << voucherList[i] << endl;
            cout << "| Token         | " << tokenGuess_list[i] << endl; 
            cout << "| Register Date | " << registerDateList[i*4] << " / " << registerDateList[(i*4)+1] << " / " << registerDateList[(i*4)+2] << endl;
            cout << "| Purchase Times| " << registerDateList[(i*4)+3] << endl;
            cout << "-------------------------------------------------------------------------------------------------" << endl;
        }
        system("PAUSE");
        userDetails();
    }
    else if(choice == 2)
    {
        system("CLS");
        string email;
        vector<string> temp_email_list;
        cout << "Enter searching email address[0-EXIT]: ";
        getline(cin >> ws, email);
        if (email == "0")
        {
            userDetails();
        }
        cout << "-------------------------------------------" << endl;
        cout << "RELATED EMAIL: " << endl;
        cout << "-----------------------------" << endl;
        for(int i = 0;i < username_list.size(); i++)
        {
            if(username_list[i].find(email) != string::npos)
            {
                temp_email_list.push_back(username_list[i]);
            }
        }
        if(temp_email_list.size() == 0)
        {
            cout << "---------------------------------" << endl;
            cout << "|      EMAIL didn't found!!     |" << endl;
            cout << "---------------------------------" << endl;
            system("PAUSE");
            userDetails();
        }
        for(int i = 0;i < temp_email_list.size(); i++)
        {
            cout << i+1 << ". " << temp_email_list[i] << endl << endl;
        }

        int select_user;
        cout << "Enter index number of your choice [0 -EXIT]: ";
        cin >> select_user;
        while(cin.fail() || select_user > temp_email_list.size() || select_user < 0)
        {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "|ATTEINTION: Invalid Input!|" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Enter Again: ";
            cin >> select_user; 
        }

        if(select_user == 0)
        {
            userDetails();
        }
        getIndex(username_list, temp_email_list[select_user-1]);

        cout << "-------------------------------------------------------------------------------------------------" << endl;
        cout << "| User No.    | " << idex + 1 << endl;
        cout << "| Name        | " << userInfo_list[idex*4] << endl;
        cout << "| IC          | " << userInfo_list[(idex*4)+1] << endl;
        cout << "| Age         | " << userInfo_list[(idex*4)+2] << endl;
        cout << "| Gender      | " << userInfo_list[(idex*4)+3] << endl;
        cout << "| Email       | " << username_list[idex] << endl;
        cout << "| Password    | " << password_list[idex] << endl;
        cout << "| Hp Num      | " << phone_list[idex] << endl;
        cout << "| Address     | " << address_list[idex] << endl;
        cout << "| Voucher     | RM " << voucherList[idex] << endl;
        cout << "| Token       | " << tokenGuess_list[idex] << endl; 
        cout << "-------------------------------------------------------------------------------------------------" << endl;

        system("PAUSE");
        userDetails();

    }
    else if(choice == 3)
    {
        system("CLS");
        string email;
        cout << "Enter ban email address[0 - EXIT]: ";
        getline(cin >> ws, email);
        if(email == "0")
        {
            userDetails();
        }
        if(find(username_list.begin(),username_list.end(),email) != username_list.end())
        {
            getIndex(username_list,email);
            srand(unsigned(time(NULL)));
            int ran_num = rand() % 10000 + 1;
            username_list[idex] = username_list[idex] + " " + to_string(ran_num) + "(BANNED)";
            chatCAList[idex][1] = username_list[idex] + " " + to_string(ran_num) + "(BANNED)";
            writeChatAdmin(chatCAList);
            writeName(username_list);
            cout << "+--------+" << endl;
            cout << "| BANNED |" << endl;
            cout << "+--------+" << endl;
        }
        else
        {
            cout << "-------------------" << endl;
            cout << "| Email Not Found |" << endl;
            cout << "-------------------" << endl;
        }
        system("PAUSE");
        userDetails();

    }
    else if(choice == 4)
    {
        system("CLS");
        int choice2;
        vector<string> temp_banned_list;
        for(int i = 0; i < username_list.size(); i++)
        {
            if((username_list[i])[username_list[i].size()-1] == ')')
            {
                temp_banned_list.push_back(username_list[i]);
            }
        }
        if(temp_banned_list.size() == 0)
        {
            cout << "-----------------------" << endl;
            cout << "| None User Be Banned |" << endl;
            cout << "-----------------------" << endl;
            system("PAUSE");
            userDetails();
        }
        sort(temp_banned_list.begin(),temp_banned_list.end());
        cout << "BANNED LIST" << endl;
        cout << "----------------------------" << endl;
        for(int i = 0;i < temp_banned_list.size(); i++)
        {
            cout << i+1 << ". " << temp_banned_list[i] << endl;
        }
        cout << "------------------------------------------------------------------------------" << endl;
        cout << "Unban Using\n[1] - Index Number of banned list\n[2] - Email Address\n[3] - BACK" << endl;
        cout << "Enter your choice(1/2): ";
        cin >> choice2;
        while(choice2 != 1 && choice2 != 2 && choice2 != 3)
        {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "|ATTEINTION: Invalid Input!|" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "Enter Again: ";
            cin.clear();
            cin.ignore(256, '\n');
            cin >> choice2;
        }
        cout << "-----------------------------------------------------------------" << endl;
        if (choice2 == 1)
        {
            int bannedIndex;
            cout << "Enter unban index: ";
            cin >> bannedIndex;
            while(cin.fail() || bannedIndex > temp_banned_list.size() || bannedIndex <= 0)
            {
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                cout << "|ATTEINTION: Invalid Input!|" << endl;
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                cin.clear();
                cin.ignore(256, '\n');
                cout << "Enter Again: ";
                cin >> bannedIndex;
            }
            string lastScan = temp_banned_list[bannedIndex-1].substr(0, temp_banned_list[bannedIndex-1].find(" "));
            getIndex(username_list,temp_banned_list[bannedIndex-1]);
            username_list[idex] = lastScan;
            chatCAList[idex][1] = lastScan;
            cout << "+----------+" << endl;
            cout << "| UNBANNED |" << endl;
            cout << "+----------+" << endl;
            writeName(username_list);
            writeChatAdmin(chatCAList);
            system("PAUSE");
            userDetails();
        }
        else if(choice2 == 2)
        {
            vector<string> banned_email_list;
            string search_email;
            for (int i = 0;i < temp_banned_list.size(); i++)
            {
                string scanEmail = temp_banned_list[i].substr(0, temp_banned_list[i].find(" "));
                banned_email_list.push_back(scanEmail);
            }
            sort(banned_email_list.begin(),banned_email_list.end());
            cout << "Enter email for unbanned [0 -EXIT]: ";
            getline(cin >> ws, search_email);
            if(search_email == "0")
            {
                userDetails();
            }
            if(find(banned_email_list.begin(),banned_email_list.end(),search_email) != banned_email_list.end())
            {
                getIndex(banned_email_list,search_email);
                getIndex(username_list,temp_banned_list[idex]);
                username_list[idex] = search_email;
                chatCAList[idex][1] = search_email;
                writeName(username_list);
                writeChatAdmin(chatCAList);
                cout << "+----------+" << endl;
                cout << "| UNBANNED |" << endl;
                cout << "+----------+" << endl;
            }
            else
            {
                cout << "--------------------------" << endl;
                cout << "| Email Not Found/Banned |" << endl;
                cout << "--------------------------" << endl;
            }
            system("PAUSE");
            userDetails();
        }
        else if(choice2 == 3)
        {
            userDetails();
        }
    }
    else if(choice == 5)
    {
        adminProductControl();
    }
}



void adminProductControl()
{
    system("CLS");
    system("Color F0");
    int choice;
    cout << "\t\t\t===================================================" << endl;
    cout << "\t\t\t|$$$$$$$$$$$ [ Product Control System ] $$$$$$$$$$|" << endl;
    cout << "\t\t\t===================================================" << endl;
    cout << "\t\t\t|              1. Product Management              |" << endl;
    cout << "\t\t\t|                                                 |" << endl;
    cout << "\t\t\t|              2. Food Managemet                  |" << endl;
    cout << "\t\t\t|                                                 |" << endl;
    cout << "\t\t\t|              3. Check Invoice No.               |" << endl;
    cout << "\t\t\t|                                                 |" << endl;
    cout << "\t\t\t|              4. Check Food Order                |" << endl;
    cout << "\t\t\t|                                                 |" << endl;
    cout << "\t\t\t|              5. Check User Details              |" << endl;
    cout << "\t\t\t|                                                 |" << endl;
    cout << "\t\t\t|              6. Customer ChatRoom               |" << endl;
    cout << "\t\t\t|                                                 |" << endl;
    cout << "\t\t\t|              7. Logout admin                    |" << endl;
    cout << "\t\t\t===================================================" << endl;
    cout << "\t\t\tEnter your choice(num): ";
    cin >> choice;
    while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 7)
    {
        system("Color 74");
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "|ATTEINTION: Invalid Choice|"<< endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Enter Again: ";
        cin >> choice;
    }
    if (choice == 1)
    {
        system("Color F0");
        shopManage();
    }
    
    else if (choice == 2)
    {
        system("Color F0");
        foodManage();
    }
    else if (choice == 3)
    {
        system("Color F0");
        checkInvoice();
    }
    else if (choice == 4)
    {
        system("Color F0");
        checkFood();
    }
    else if (choice == 5)
    {
        system("Color F0");
        userDetails();
    }
    else if (choice == 6)
    {
        system("Color F0");
        adminChat();
    }
    else if (choice == 7)
    {
        system("Color F0");
        mainPage();
    }
    
}


void admin()
{
    system("CLS");
    string adminName, adminPass;
    cout << "\n\n\n\n\n\n\n\n\n\n\n";
    cout << "\t\t\t-------------------------------------------------------------------------" << endl;
    cout << "\t\t\t|============================[ Admin Page ]=============================|" << endl;
    cout << "\t\t\t-------------------------------------------------------------------------" << endl;
    cout << "\n\t\t\t\t\tAdmin Name     : ";
    getline(cin >> ws, adminName);
    cout << "\n\t\t\t\t\tAdmin Password : ";
    getline(cin >> ws, adminPass);
    if (adminName == "admin" && adminPass == "admin")
    {
        system("Color 0A");
        cout << "\n\n\t\t\t\t\t\t****LOGIN SUCCESS****" << endl;
        system("PAUSE");
        adminProductControl();
    }
    else
    {
        system("Color 74");
        cout << "\n\n\t\t\t\t\t\txxxxx Login Fail xxxxxx" << endl;
        system("PAUSE");
        mainPage();
    }


}


void mainPage()
{
    system("CLS");
    system("Color F0");
    int choice;
    readNameFile();
    readPassFile();
    readVoucher();
    readAddress();
    readKMFile();
    readToken();
    readPhoneFile();
    readProduct();
    readProductType();
    readRateNameFile();
    readUserInfoFile();
    cout << R"(
                                                                                                   
                                                                                                   
        ,---,.                            ,---,.                            ,---,.                         
      ,'  .'  \                         ,'  .'  \                         ,'  .'  \                        
    ,---.' .' |         ,--,          ,---.' .' |         ,--,          ,---.' .' |         ,--,           
    |   |  |: |       ,'_ /|          |   |  |: |       ,'_ /|          |   |  |: |       ,'_ /|           
    :   :  :  /  .--. |  | :     .--, :   :  :  /  .--. |  | :     .--, :   :  :  /  .--. |  | :     .--,  
    :   |    ; ,'_ /| :  . |   /_ ./| :   |    ; ,'_ /| :  . |   /_ ./| :   |    ; ,'_ /| :  . |   /_ ./|  
    |   :     \|  ' | |  . ., ' , ' : |   :     \|  ' | |  . ., ' , ' : |   :     \|  ' | |  . ., ' , ' :  
    |   |   . ||  | ' |  | /___/ \: | |   |   . ||  | ' |  | /___/ \: | |   |   . ||  | ' |  | /___/ \: |  
    '   :  '; |:  | : ;  ; |.  \  ' | '   :  '; |:  | : ;  ; |.  \  ' | '   :  '; |:  | : ;  ; |.  \  ' |  
    |   |  | ; '  :  `--'   \\  ;   : |   |  | ; '  :  `--'   \\  ;   : |   |  | ; '  :  `--'   \\  ;   :  
    |   :   /  :  ,      .-./ \  \  ; |   :   /  :  ,      .-./ \  \  ; |   :   /  :  ,      .-./ \  \  ;  
    |   | ,'    `--`----'      :  \  \|   | ,'    `--`----'      :  \  \|   | ,'    `--`----'      :  \  \ 
    `----'                      \  ' ;`----'                      \  ' ;`----'                      \  ' ; 
                                 `--`                              `--`                              `--`  
    )";
    cout << "\n\n";
    cout << "\t\t\t************************************************************" << endl;
    cout << "\t\t\t|          %   WELCOME To BuyBuyBuy Supermarket   %        |" << endl;
    cout << "\t\t\t|                                                          |" << endl;
    cout << "\t\t\t|              [ BUY EVERYTHING ONLINE SYSTEM ]            |" << endl;
    cout << "\t\t\t|----------------------------------------------------------|" << endl;
    cout << "\t\t\t|                       MAIN MENU                          |" << endl;
    cout << "\t\t\t************************************************************" << endl;
    cout << "\t\t\t|\t\t       1. Register                         |" << endl;
    cout << "\t\t\t|\t\t                                           |" << endl;
    cout << "\t\t\t|\t\t       2. Login                            |" << endl;
    cout << "\t\t\t|\t\t                                           |" << endl;
    cout << "\t\t\t|\t\t       3. Admin                            |" << endl;
    cout << "\t\t\t|\t\t                                           |" << endl;
    cout << "\t\t\t|\t\t       4. Exit                             |" << endl;
    cout << "\t\t\t************************************************************" << endl << endl;
    cout << "\t\t\tChoice(1/2/3/4) ---> "; cin >> choice;
    while (choice != 1 && choice != 2 && choice != 3 && choice != 4)
    {
        system("Color 74");
        cout << "\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "\t\t\t|ATTEINTION: Invalid Choice|" << endl;
        cout << "\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cout << "\t\t\tEnter Again: ";
        cin >> choice;
    }

    if (choice == 1)
    {
        system("Color F0");
        reg();
    }
    else if (choice == 2)
    {
        system("Color F0");
        login();
    }
    else if (choice == 3)
    {
        system("Color F0");
        admin();
    }
    else if (choice == 4)
    {
        system("Color F0");
        goodbye();
    }
}


void goodbye()
{
    system("CLS");
    system("Color 0A");
    cout << R"(
              ___     ___     ___     ___     ___   __   __   ___            
      / __|   / _ \   / _ \   |   \   | _ )  \ \ / /  | __|     o O O 
     | (_ |  | (_) | | (_) |  | |) |  | _ \   \ V /   | _|     o      
      \___|   \___/   \___/   |___/   |___/   _|_|_   |___|   TS__[O] 
_|"""""|_|"""""|_|"""""|_|"""""|_|"""""|_| """ |_|"""""| {======| 
"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'./o--000' 
    )" << '\n';



    cout << "See you soon!!!" << endl;
    cout << "==============================================================" << endl;

    auto now = chrono::system_clock::now();
    time_t time_now = chrono::system_clock::to_time_t(now);
    string str_time = ctime(&time_now);
    cout << "Last Seen: " << str_time;

    system("PAUSE");
    exit(0);
}

void reg()
{
    system("CLS");
    readChatAdmin();
    readChatAI();
    readRegisterDate();
    readphoneCarrier();
    bool loop = true;
    float km;
    char strengthen_pass;
    string weekdays[7] = { "Sunday","Monday","Tuesday", "Wednesday","Thursday","Friday","Saturday" };

    string new_name, new_pass, new_pass2, new_phone, new_email, new_occu, new_ic, new_age, new_gender, new_address, remainder, call;
    int year, age,security_sum;
    time_t t = time(NULL);
    tm* tptr = localtime(&t);

    cout << "\t\t\t\t**Welcome New User**" << endl;
    cout << "================================================================================================" << endl;
    cout << "\t1. Enter your name: ";
    getline(cin >> ws, new_name);
    string firstWord = new_name.substr(0, new_name.find(" "));


    cout << "\n\t2. Enter your IC number(xxxxxx-xx-xxxx): ";
    getline(cin >> ws, new_ic);
    while (new_ic[6] != '-' || new_ic[9] != '-' || new_ic.length() != 14)
    {
        cout << "\t------------------------" << endl;
        cout << "\t| Invalid IC number... |" << endl;
        cout << "\t------------------------" << endl;
        cout << "\tReenter your IC number(xxxxxx-xx-xxxx): ";
        getline(cin >> ws, new_ic);
        cout << endl;
    }

    string firstTwo = new_ic.substr(0, 2);
    int c_firstTwo, dobyy;
    char last = new_ic[new_ic.length() - 1];
    int lastC;
    stringstream obj;
    obj << last;
    obj >> lastC;

    if (lastC % 2 == 0)
    {
        new_gender = "Female";
    }
    else
    {
        new_gender = "Male";
    }

    if (new_gender == "Male")
    {
        call = "Mr.";
    }
    else
    {
        call = "Mrs.";
    }


    stringstream obj2;
    obj2 << firstTwo;
    obj2 >> c_firstTwo;

    year = (tptr->tm_year) + 1900;
    if (c_firstTwo > year % 2000)
    {
        dobyy = 1900 + c_firstTwo;
    }
    else
    {
        dobyy = 2000 + c_firstTwo;
    }

    age = (year - dobyy);
    string sAge;
    stringstream obj3;
    obj3 << age;
    obj3 >> sAge;


    cout << "\n\t3. Enter your email address: ";
    getline(cin >> ws, new_email);
    bool ans = is_valid(new_email);

    

    for (int i = 0; i < 3; i++)
    {
        //New Updated Feature
        while(find(username_list.begin(),username_list.end(),new_email)!= username_list.end())
        {
            cout << "\t-----------------------------------------------------------------" << endl;
            cout << "\t| This email had been registered.Try Using Other Email Address. |" << endl;
            cout << "\t-----------------------------------------------------------------" << endl;
            cout << "\tReenter your email address: ";
            getline(cin >> ws,new_email);
            ans = is_valid(new_email);
        }
        if (ans) break;
        else
        {
            cout << "\t-----------------------------------------------" << endl;
            cout << "\t|  Key In Invalid Email Not More Than 3 Times!| " << endl;
            cout << "\t-----------------------------------------------" << endl;
            cout << "\t|          Invalid Email For [" << i + 1 << "] times!       |" << endl;
            cout << "\t-----------------------------------------------" << endl;
            cout << "\tReenter again your email address: ";
            getline(cin >> ws, new_email);
            cout << endl;
            ans = is_valid(new_email);
            if(i == 2)
            {
                while(find(username_list.begin(),username_list.end(),new_email)!= username_list.end())
                {
                    cout << "\t-----------------------------------------------------------------" << endl;
                    cout << "\t| This email had been registered.Try Using Other Email Address. |" << endl;
                    cout << "\t-----------------------------------------------------------------" << endl;
                    cout << "\tReenter your email address: ";
                    getline(cin >> ws,new_email);
                    ans = is_valid(new_email);
                }
                if(ans == 1)
                {
                    break;
                }
                else
                {
                    cout << "\t------------------------" << endl;
                    cout << "\t| Back To Main Menu... |" << endl;
                    cout << "\t------------------------" << endl;
                    system("PAUSE");
                    mainPage();
                }
                
            }
        }
    }

    do
    {
        security_sum = 0;
        cout << "\n\t4. Enter your password: ";
        getline(cin >> ws, new_pass);
        while(new_pass.length() < 9)
        {
            cout << "\t------------------------------------------" << endl;
            cout << "\t| Please use stronger security password. |" << endl;
            cout << "\t|          AT LEAST 9 CHARACTERS         |" << endl;
            cout << "\t------------------------------------------" << endl;
            cout << "\tEnter A Stronger Password: ";
            getline(cin >> ws,new_pass); 
            cout << endl;
        }
        for(int i = 0;i < new_pass.length(); i++)
        {
            if(islower(new_pass[i])) security_sum++;
            if(isupper(new_pass[i])) security_sum += 2;
            if(isDigit(new_pass[i])) security_sum++;
            if(!isalpha(new_pass[i]) && !isdigit(new_pass[i])) security_sum += 3;
        }
        if(security_sum > 18)
        {
            cout << "\n\t------------------------------------";
            cout << "\n\t|      Strong Security Password    |";
            cout << "\n\t------------------------------------" << endl;
        }
        else if(security_sum > 14)
        {
            cout << "\n\t------------------------------------";
            cout << "\n\t|    Moderate Security Password    |";
            cout << "\n\t------------------------------------" << endl;
        }
        else
        {
            cout << "\n\t------------------------------------";
            cout << "\n\t|       Low Security Password      |";
            cout << "\n\t------------------------------------" << endl;
        }
        cout << "\tDo you want to strengthen your password( [Y] - YES [N] - NO): ";
        cin >> strengthen_pass;
        while(strengthen_pass != 'Y' && strengthen_pass != 'N')
        {
            cout << "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "\t|ATTEINTION: Invalid Input!|" << endl;
            cout << "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cin.clear();
            cin.ignore(256, '\n');
            cout << "\tEnter again: ";
            cin >> strengthen_pass;
        }
    }while(strengthen_pass != 'N');
    


    cout << "\n\t5. Reenter your password: ";
    getline(cin >> ws, new_pass2);
    while (new_pass2 != new_pass)
    {
        cout << "\t---------------------------------------" << endl;
        cout << "\t| Password not same...Reenter again!! |" << endl;
        cout << "\t---------------------------------------" << endl;
        cout << "\tReenter your password: ";
        getline(cin >> ws, new_pass2);
        cout << endl;
    }


    string c_phone, final_phone;
    do
    {
        cout << "\n\t6. Enter your phone number(Eg: +60 XXXXXXXXXX): ";
        getline(cin >> ws, new_phone);
        while (new_phone.length() < 12 || (new_phone[0] != '+' || new_phone[1] != '6' || new_phone[2] != '0'))
        {
            cout << "\t---------------------------------------" << endl;
            cout << "\t| Invalid phone number! Key In Again! |" << endl;
            cout << "\t---------------------------------------" << endl;
            cout << "\tReenter your phone number(Eg: +60 XXXXXXXXXX): ";
            getline(cin >> ws, new_phone);
        }

        ofstream phoneout;
        phoneout.open("phoneNum.txt");
        phoneout << new_phone << endl;
        phoneout.close();
        system("python -u \"./checkPhone.py\"");
        
        ifstream readCphone("phoneNum.txt");

        while(getline(readCphone,c_phone))
        {
            final_phone = c_phone;
        }
        readCphone.close();
        remove("phoneNum.txt");

        if(final_phone == "")
        {
            final_phone = "[ Non-Recognize ]. Please reenter again...";
        }

        cout << "\tPhone Carrier: " << final_phone << endl << endl;
    } while (final_phone == "[ Non-Recognize ]. Please reenter again...");
    

    cout << "\n\t7. Enter your home address: ";
    getline(cin >> ws, new_address);
    while(new_address.length() < 20)
    {
        cout << "\t+----------------------------------+" << endl;
        cout << "\t| Please Key In FULL HOME Address. |" << endl;
        cout << "\t+----------------------------------+" << endl;
        cout << "\t Reenter your full home address: ";
        getline(cin >> ws, new_address);
    }

    cout << "\n\t8. Enter estimate distance(km) with Nearest BuyBuyBuy Supermarket: ";
    cin >> km;
    while (cin.fail())
	{
		cin.clear();
        cin.ignore(256, '\n');
        cout << "\t-----------------" << endl;
		cout << "\t| Invalid Input |" << endl;
        cout << "\t-----------------" << endl;
        cout << "\tReenter estimate distance(km) with Nearest BuyBuyBuy Supermarket: ";
		cin >> km;
	}
    


    cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    auto t2 = time(nullptr);
    auto tm = *localtime(&t2);

    std::ostringstream oss;
    oss << put_time(&tm, "%d-%m-%Y    %H:%M:%S");
    auto str_time = oss.str();

    int hourNow = tptr->tm_hour;
    int dayNow = tptr->tm_wday;
    if (hourNow > 12 && hourNow < 18)
    {
        remainder = "Good Afternoon! " + call + firstWord + " ! Have your lunch? Hope you have a happy " + weekdays[dayNow] + "! ^-^\n|ThankYou For Chosen BuyBuyBuy System!";
    }
    else if (hourNow == 18)
    {
        remainder = "Good Evening! " + call + firstWord + " ! Have your dinner? Hope you have a happy " + weekdays[dayNow] + "! ^-^\n|ThankYou For Chosen BuyBuyBuy System!";
    }
    else if (hourNow > 18 && hourNow <= 23)
    {
        remainder = "Good Night! " + call + firstWord + " ! Rest Earlier! Hope you have a happy " + weekdays[dayNow] + "! ^-^\n|ThankYou For Chosen BuyBuyBuy System!";
    }
    else if (hourNow >= 0 && hourNow <= 5)
    {
        remainder = "Good Night! " + call + firstWord + " ! Rest Earlier! Hope you have a happy " + weekdays[dayNow] + "! ^-^\n|ThankYou For Chosen BuyBuyBuy System!";
    }
    else if (hourNow > 5 && hourNow < 12)
    {
        remainder = "Good Moring! " + call + firstWord + " ! Have your breakfast? Hope you have a happy " + weekdays[dayNow] + "! ^-^\n|ThankYou For Chosen BuyBuyBuy System!";
    }

    system("PAUSE");


    system("CLS");
    cout << "\t\t******************************************************************************************************************************" << endl;
    cout << "\t\t|                                                    Personal INFO                                                           |" << endl;
    cout << "\t\t******************************************************************************************************************************" << endl;
    cout << "\t\t|\t\t1. Name           : " << new_name << endl;
    cout << "\t\t|\t\t2. IC             : " << new_ic << endl;
    cout << "\t\t|\t\t3. Gender         : " << new_gender << endl;
    cout << "\t\t|\t\t4. Age            : " << sAge << endl;
    cout << "\t\t|\t\t5. Email-Address  : " << new_email << endl;
    cout << "\t\t|\t\t6. Password       : " << new_pass << endl;
    cout << "\t\t|\t\t7. HpNum          : " << new_phone << endl;
    cout << "\t\t|\t\t8. Home Address   : " << new_address << endl;
    cout << "=============================================================================================================================================" << endl;
    cout << "|" << remainder << endl;
    cout << "|Can Try Using New Feature Of BuyBuyBuy App For Food Ordering!!! ENJOY!! (*ONLY FOR USER 30KM NEAR TO ANY FRANCHISE OF BUYBUYBUY supermarket)" << endl;
    cout << "=============================================================================================================================================" << endl << endl;
    char ins;
    cout << "\t->->->->IS DATA CORRECT?( [Y] - YES/ [N] - NO ): ";
    cin >> ins;
    while (ins != 'Y' && ins != 'N')
    {
        cout << "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "\t|ATTEINTION: Invalid Input!|" << endl;
        cout << "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cout << "\t->->->->IS DATA CORRECT?( [Y] - YES/ [N] - NO ): ";
        cin >> ins;
    }
    if (ins == 'Y')
    {
        stringstream ss(sAge);
        int age_num = 0;
        ss >> age_num;
        if (age_num < 18)
        {
            cout << "\t|---------------------------------------------------------|" << endl;
            cout << "\t|OOPS! Sorry! You are too small for doing online purchase!|" << endl;
            cout << "\t|                   Back To Main Menu...                  |" << endl;
            cout << "\t|---------------------------------------------------------|" << endl;
            system("PAUSE");
            mainPage();
        }
        else if (age_num > 99)
        {
            cout << "\t|------------------------------------------------------|" << endl;
            cout << "\t|Please enter a valid IC number.Thanks for cooperation!|" << endl;
            cout << "\t|                   Back To Main Menu...               |" << endl;
            cout << "\t|------------------------------------------------------|" << endl;
            system("PAUSE");
            mainPage();
        }
        else
        {
            if (km > 30)
            {
                cout << "\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
                cout << "\t[Sorry. You cannot use the new EatEatEat feature for food ordering cause your house is further than 30km. ]" << endl;
                cout << "\t[                        STAY TUNE For MORE BuyBuyBuy supermarket open in more district!!                 ]" << endl;
                cout << "\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
                
            }

            vector<string> newChatAIList;
            vector<string> newChatAdminList;
            vector<string> newPhoneList;
            // cout << "Register Success!!!!" << endl << endl;
            username_list.push_back(new_email);
            password_list.push_back(new_pass2);
            address_list.push_back(new_address);
            phone_list.push_back(new_phone);
            estimateKM_list.push_back(km);
            voucherList.push_back(0);
            tokenGuess_list.push_back(0);
            userInfo_list.push_back(new_name);
            userInfo_list.push_back(new_ic);
            userInfo_list.push_back(sAge);
            userInfo_list.push_back(new_gender);
            newChatAIList.push_back("never");
            newChatAIList.push_back(new_email);
            newChatAIList.push_back(to_string(tptr->tm_mday));
            chatHistory.push_back(newChatAIList);
            newChatAdminList.push_back("never");
            newChatAdminList.push_back(new_email);
            chatCAList.push_back(newChatAdminList);
            newPhoneList.push_back(final_phone);
            newPhoneList.push_back(new_phone);
            phoneCarrierList.push_back(newPhoneList);

            writeName(username_list);
            writePass(password_list);
            writeAddress(address_list);
            writePhone(phone_list);
            writeKM(estimateKM_list);
            writeVoucher(voucherList);
            writeToken(tokenGuess_list);
            writeUserInfo(userInfo_list);
            registerDateList.push_back(tptr->tm_year + 1900);
            registerDateList.push_back(tptr->tm_mon+1);
            registerDateList.push_back(tptr->tm_mday);
            registerDateList.push_back(0);
            writeRegisterDate(registerDateList);

            writeChatAdmin(chatCAList);
            writeChatAI(chatHistory);
            writePhoneCarrier(phoneCarrierList);
            cout << "=============================================================================================================================================" << endl;
            cout << "|                                   <-<-<-<      Welcome For Using BuyBuyBuy Application!!        ->->->->                                  |" << endl;
            cout << "|<><><><><>           We will provide user a most safety environment and fastest responses for ANY online purchase!               <><><><><>|" << endl;
            cout << "=============================================================================================================================================" << endl << endl;
            system("PAUSE");
            system("CLS");
            system("Color 0A");
            cout << R"(
            ______           _     _              _____                             
            | ___ \         (_)   | |            /  ___|                            
            | |_/ /___  __ _ _ ___| |_ ___ _ __  \ `--. _   _  ___ ___ ___  ___ ___ 
            |    // _ \/ _` | / __| __/ _ \ '__|  `--. \ | | |/ __/ __/ _ \/ __/ __|
            | |\ \  __/ (_| | \__ \ ||  __/ |    /\__/ / |_| | (_| (_|  __/\__ \__ \
            \_| \_\___|\__, |_|___/\__\___|_|    \____/ \__,_|\___\___\___||___/___/
                        __/ |                                                       
                       |___/                                                        
                )" << '\n';

            cout << "\n----------------------------------------------------------------------------------------------------------------------\nBack To Main Menu..." << endl;
            system("PAUSE");
            mainPage();

        }
    }
    else if (ins == 'N')
    {
        cout << "\t-----------------------------------------------------------------------------------------------" << endl;
        cout << "\t|Your personal record had been deleted! Faster create a account to let life happy and easier!!|" << endl;
        cout << "\t|                              Back To Main Page Now.....                                     |" << endl;
        cout << "\t-----------------------------------------------------------------------------------------------" << endl;
        system("PAUSE");
        mainPage();
    }
}

void userRecord()
{
    system("CLS");
    vector<int> store_int_list;
    vector<int> user_check_list;
    int find_i = -1,check_same,choice,choice2;
    for(int i = 0; i < buy_record_list.size();i++)
    {
        check_same = 0;
        for(int j = 0; j < buy_record_list[i].size();j++)
        {
            if(buy_record_list[i][1] == name)
            {
                find_i = i;
                if(check_same == 0)
                {
                    store_int_list.push_back(find_i);
                    check_same++;
                }
                
            }
        }
    }



    getIndex(username_list, name);
    if (find_i == -1)
    {
        cout << "\t---------------------------------------" << endl;
        cout << "\t| User didnt purchase any item online |" << endl;
        cout << "\t---------------------------------------" << endl;
        cout << "\t|          Back To Main Menu...       |" << endl;
        cout << "\t---------------------------------------" << endl;
        system("PAUSE");
        userPage();
    }
    for(int i = 0; i< store_int_list.size(); i++)
    {
        cout << "\t*****************LATEST PURCHASE RECORD*****************" << endl;
        cout << "================================================================================\n";
        cout << "\t\t\t\t\tUsername: " << buy_record_list[store_int_list[i]][1] << endl;
        cout << "\t\t\t\t\tInvoice No.: " << buy_record_list[store_int_list[i]][0] << endl;
        user_check_list.push_back(stoi(buy_record_list[store_int_list[i]][0])-1001);
        cout << "\t\t\t\t\tStatus: " << checkStatusPurchase_list[(stoi(buy_record_list[store_int_list[i]][0]) - 1001)] << endl;
        cout << "\t\t\t\t\tDate Purchase: " << buy_record_list[store_int_list[i]][2] << endl << endl;
        cout << "------------------------------------------------------------------------" << endl;
        cout << setw(30) << "Item Name" << setw(30) << "Quantity" << endl;
        cout << "------------------------------------------------------------------------" << endl;
        for (int j = 3; j < buy_record_list[store_int_list[i]].size() - 4; j += 2)
        {
            cout << setw(30) << buy_record_list[store_int_list[i]][j] << setw(30) << buy_record_list[store_int_list[i]][j + 1] << endl;
        }
        float paid = stof(buy_record_list[store_int_list[i]][buy_record_list[store_int_list[i]].size() - 4]);
        cout << "\n\nTotal Paid = RM " << fixed << setprecision(2) << paid << endl;
        cout << "Estimate arrived date: " << buy_record_list[store_int_list[i]][buy_record_list[store_int_list[i]].size() - 3] << endl;
        cout << "Hp Num: " << buy_record_list[store_int_list[i]][buy_record_list[store_int_list[i]].size() - 2] << endl;
        cout << "Deliver Address: " << buy_record_list[store_int_list[i]][buy_record_list[store_int_list[i]].size() - 1] << endl;
        cout << "=======================================================================================================================" << endl;
    }

    cout << "Click [1] -> Confirm received purchase Item" << endl;
    cout << "Click [2] -> Back To Main Menu" << endl;
    cout << "Enter your choice(1/2): ";
    cin >> choice;
    while (choice != 1 && choice != 2)
    {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "|ATTEINTION: Invalid Choice|" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Enter Again: ";
        cin >> choice;
    }

    if(choice == 1)
    {
        for (int i = 0; i < user_check_list.size(); i++)
        {
            if(checkStatusPurchase_list[user_check_list[i]] == "Delivered")
            {
                cout << "============================================================================================" << endl;
                cout << "Enter[1] to confirm item received [2] for Skip for Invoice No. " << user_check_list[i]+1001 << endl;
                cout << "Enter your choice(1/2): ";
                cin >> choice2;
                while (choice2 != 1 && choice2 != 2)
                {
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    cout << "|ATTEINTION: Invalid Choice|" << endl;
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    cin.clear();
                    cin.ignore(256, '\n');
                    cout << "Enter Again: ";
                    cin >> choice2;
                }
                if (choice2 == 1)
                {
                    checkStatusPurchase_list[user_check_list[i]] = "Received";
                    writeStatusPurchase(checkStatusPurchase_list);
                    cout << "-------------------------------------------------------------" << endl;
                    cout << "+-----------+" << endl;
                    cout << "|  UPDATED  |" << endl;
                    cout << "+-----------+" << endl;
                }
                else
                {
                    cout << "+-----------+" << endl;
                    cout << "|  SKIPPED  |" << endl;
                    cout << "+-----------+" << endl;
                }

            }
        }
    }
    else if(choice == 2)
    {
        userPage();
    }


    cout << "-----------------------------------------------------------------------------" << endl;
    cout << "+------------------------------------------+" << endl;
    cout << "| Nothing else...Thanks for visit our shop |" << endl;
    cout << "+------------------------------------------+" << endl;

    system("PAUSE");
    userPage();
}


void purchaseItem()
{
    system("CLS");
    int choice, num;
    bool loop = true;
    string item_name, final_sold;
    float price, amount_buy, offer, final_offer, discount_money;
    float total_price = 0;
    int times, item_delete, result, total_sold;
    char select, select_add_remove;
    vector<string> storeItem;
    vector<string> storeItemPrice;
    vector<string> buy_item;
    vector<int> total_item;
    readProduct();

    cout << "\t\t ^^^^^^SLOGAN BuyBuyBuy Supermarket^^^^^^" << endl;
    cout << "-----------------------------------------------------------------------" << endl;
    cout << "\t\t\t<<    0 DELIVERY FEE     >>" << endl;
    cout << "\t\t\t<<  BUY MORE OFFER MORE  >>" << endl;
    cout << "\t\t\t<< BUY RM100 For 1 Token >>" << endl;
    cout << "============================Promtion Price=============================" << endl;
    cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
    for (int k = 0; k < buyItemType_list.size(); k++)
    {
        cout << buyItemType_list[k] << endl;
        cout << "-------------------------------------------------------------------------------------------" << endl;
        for (int j = 0; j < buyItem_list[k].size(); j += 5)
        {
            cout << "\t| 1. Product Name                      : " << buyItem_list[k][j] << endl;
            cout << "\t| 2. Product Price                     : RM " << buyItem_list[k][j + 1] << endl;
            cout << "\t| 3. Amount Buy For Promotion          : " << buyItem_list[k][j + 2] << endl;
            cout << "\t| 4. Promotion (Per Unit)              : " << buyItem_list[k][j + 3] << " %" << endl;
            cout << "\t| 5. Total Sale                        : " << buyItem_list[k][j + 4] << endl;
            cout << "=======================================================================================" << endl;
        }
    }
    cout << "\n\n" << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;


    while (loop)
    {
        cout << "\t\t+-----------------------------------------------+" << endl; 
        cout << "\t\t|                  [ CATEGORY ]                 |" << endl;
        cout << "\t\t+-----------------------------------------------+" << endl; 
        for (int i = 0; i < buyItemType_list.size(); i++)
        {
            cout << "\t\t\t\t" << i + 1 << ". " << buyItemType_list[i] << endl;
        }
        cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Enter your choice(num | [0-EXIT]): ";
        cin >> choice;
        while (cin.fail() || (choice > buyItem_list.size() || choice < 0))
        {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "|ATTEINTION: Invalid Input!|" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "Enter Again: ";
            cin.clear();
            cin.ignore(256, '\n');
            cin >> choice;
        }
        if(choice == 0)
        {
            userPage();
        }
        
        cout << "\n####################################################################" << endl;
        getIndex(buyItemType_list, buyItemType_list[choice - 1]);
        idex2 = idex;
        storeItem.clear();
        storeItemPrice.clear();
        for (int i = 0; i < buyItem_list[idex].size(); i += 5)
        {
            storeItem.push_back(buyItem_list[idex][i]);
        }

        for (int i = 0; i < buyItem_list[idex].size(); i += 5)
        {
            storeItemPrice.push_back(buyItem_list[idex][i + 1]);
        }

        cout << setw(5) << "Index" << setw(30) << "Item Name" << setw(30) << "Price Per Item(RM)" << endl;
        cout << "###################################################################" << endl;
        for (int i = 0; i < storeItem.size(); i++)
        {
            cout << setw(5) << i + 1 << ". " << setw(30) << storeItem[i] << setw(30) << storeItemPrice[i] << setw(30) << endl;
        }

        cout << "\nWhat item you want to buy(index num): ";
        cin >> num;
        while (cin.fail() || (num > storeItem.size() || num <= 0))
        {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "|ATTEINTION: Invalid Input!|" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "Enter Again: ";
            cin.clear();
            cin.ignore(256, '\n');
            cin >> num;
        }
        getIndex(buyItem_list[idex2], storeItem[num - 1]);


        price = stof(buyItem_list[idex2][idex + 1]);
        amount_buy = stof(buyItem_list[idex2][idex + 2]);
        offer = stof(buyItem_list[idex2][idex + 3]) / 100;
        total_sold = stof(buyItem_list[idex2][idex + 4]);


        if (find(buy_item.begin(), buy_item.end(), buyItem_list[idex2][idex]) != buy_item.end())
        {
            int calItem = count(buy_item.begin(), buy_item.end(), buyItem_list[idex2][idex]);
            cout << "+---------------------------------+" << endl;
            cout << "| You had selected this product!! |" << endl;
            cout << "+---------------------------------+" << endl;
            cout << "Amount Purchase For [ " << buyItem_list[idex2][idex] << " ]: " << calItem << " UNIT(S)" << endl;
            cout << "---------------------------------------------------------------------------------------------------" << endl;
            cout << "Do you want to add or remove this item([A]: ADD/ [R]: REMOVE): ";
            cin >> select_add_remove;
            while(select_add_remove != 'A' && select_add_remove != 'R')
            {
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                cout << "|ATTEINTION: Invalid Input!|" << endl;
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                cin.clear();
                cin.ignore(256, '\n');
                cout << "Enter your choice again: ";
                cin >> select_add_remove;
            }
            if (select_add_remove == 'A')
            {
                cout << "How much you want to buy: ";
                cin >> times;
                while (cin.fail() || times < 0)
                {
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    cout << "|ATTEINTION: Invalid Input!|" << endl;
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    cout << "Enter Again: ";
                    cin.clear();
                    cin.ignore(256, '\n');
                    cin >> times;
                }
                for (int i = 0; i < times; i++)
                {
                    buy_item.push_back(buyItem_list[idex2][idex]);
                }
                result = total_sold + times;
                final_sold = to_string(result);
                buyItem_list[idex2][idex + 4] = final_sold;
            }
            else if (select_add_remove == 'R')
            {
                int cal = count(buy_item.begin(), buy_item.end(), buyItem_list[idex2][idex]);
                cout << "How many item you want to delete: ";
                cin >> item_delete;
                while (cin.fail() || item_delete <= 0)
                {
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    cout << "|ATTEINTION: Invalid Input!|" << endl;
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    cout << "Enter Again: ";
                    cin.clear();
                    cin.ignore(256, '\n');
                    cin >> item_delete;
                }
                while (item_delete > cal)
                {
                    cout << "------------------------------------------------------------------------------" << endl;
                    cout << "| OPERATION FAIL..The number you want to remove is more than selected item.. |" << endl;
                    cout << "------------------------------------------------------------------------------" << endl;
                    cout << "How many item you want to delete: ";
                    cin >> item_delete;
                    while (cin.fail() || item_delete <= 0)
                    {
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        cout << "|ATTEINTION: Invalid Input!|" << endl;
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                        cout << "Enter Again: ";
                        cin.clear();
                        cin.ignore(256, '\n');
                        cin >> item_delete;
                    }
                }
                if (item_delete <= cal)
                {
                    auto iter = find(buy_item.begin(), buy_item.end(), buyItem_list[idex2][idex]);
                    if (iter != buy_item.end())
                    {
                        for (int i = 0; i < item_delete; i++)
                        {
                            buy_item.erase(iter);
                        }
                        result = total_sold - item_delete;
                        final_sold = to_string(result);
                        buyItem_list[idex2][idex + 4] = final_sold;
                    }
                }


            }
        }
        else
        {
            cout << "How much you want to buy: ";
            cin >> times;
            while (cin.fail() || times < 0)
            {
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                cout << "|ATTEINTION: Invalid Input!|" << endl;
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                cout << "Enter Again: ";
                cin.clear();
                cin.ignore(256, '\n');
                cin >> times;
            }
            final_sold = to_string(total_sold + times);

            buyItem_list[idex2][idex + 4] = final_sold;

            for (int i = 0; i < times; i++)
            {
                buy_item.push_back(buyItem_list[idex2][idex]);
            }
        }


        cout << "Do You Want To Continue Purchase( [Y] - YES/ [N] - NO ): ";
        cin >> select;
        while (select != 'Y' && select != 'N')
        {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Invalid Choice..TRY AGAIN!" << endl;
            cout << "Enter Again: ";
            cin >> select;

        }
        if (select == 'Y')
        {
            loop = true;
        }
        else if (select == 'N')
        {
            loop = false;
        }

    }
    double fprice, discountPrice;
    double sum = 0;
    int findI, token, year, month, day, year2, month2, day2, hour ,minute,temp_voucher;
    string nameI, arrived_date;
    vector<string> new_buy_item;
    vector<int> final_item_list;
    vector<float> new_price_list;
    vector<string> newItem_list;
    vector<float> offer_list;
    vector<float> fprice_list;
    vector<float> discount_list;
    new_buy_item = buy_item;
    sort(new_buy_item.begin(), new_buy_item.end());
    new_buy_item.erase(unique(new_buy_item.begin(), new_buy_item.end()), new_buy_item.end());


    if (new_buy_item.size() == 0)
    {
        system("CLS");
        cout << "----------------------------" << endl;
        cout << "|   Your cart is empty...  |" << endl;
        cout << "----------------------------" << endl;
        cout << "|   Back To User Page....  |" << endl;
        cout << "----------------------------" << endl;
        system("PAUSE");
        userPage();
    }
    else
    {
        for (int j = 0; j < buyItem_list.size(); j++)
        {
            for (int k = 0; k < buyItem_list[j].size(); k++)
            {
                for (int i = 0; i < new_buy_item.size(); i++)
                {
                    if (buyItem_list[j][k] == new_buy_item[i])
                    {
                        getIndex(buyItem_list[j], new_buy_item[i]);

                        nameI = buyItem_list[j][idex];
                        newItem_list.push_back(nameI);

                        price = stof(buyItem_list[j][idex + 1]);
                        new_price_list.push_back(price);

                        amount_buy = stof(buyItem_list[j][idex + 2]);

                        offer = stof(buyItem_list[j][idex + 3]);
                        final_offer = (100 - offer) / 100;
                        offer_list.push_back(final_offer);
                        discount_money = offer / 100;

                        int ca = count(buy_item.begin(), buy_item.end(), new_buy_item[i]);

                        final_item_list.push_back(ca);

                        if (ca >= amount_buy)
                        {
                            fprice = price * ca * final_offer;
                            fprice_list.push_back(fprice);
                            discountPrice = price * ca * discount_money;
                            discount_list.push_back(discountPrice);
                        }
                        else
                        {
                            fprice = price * ca;
                            fprice_list.push_back(fprice);
                            discount_list.push_back(0);
                        }
                    }
                }
            }

        }
    }



    system("PAUSE");
    system("CLS");
    string makeSure;
    cout << setw(80) << "RECEIPT" << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << setw(10) << "NO." << setw(30) << "Item Name" << setw(30) << "Price Per Unit(RM)" << setw(30) << "Total unit" << setw(30) << "Total discount(RM)" << setw(30) << "Final Price(RM)" << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    for (int j = 0; j < new_buy_item.size(); j++)
    {
        cout << setw(10) << j + 1 << setw(30) << newItem_list[j] << setw(30) << fixed << setprecision(2) << new_price_list[j] << setw(30) << final_item_list[j] << setw(30) << fixed << setprecision(2) << discount_list[j] << setw(30) << fixed << setprecision(2) << fprice_list[j] << endl;
    }


    for (double i : fprice_list)
    {
        sum += i;
    }

    cout << endl << "Total Price Before Using Voucher: RM ";
    cout << fixed << setprecision(2) << sum << endl;

    getIndex(username_list, name);
    if (voucherList[idex] == 0)
    {
        cout << "Sorry,you had no voucher for discount!" << endl;
    }
    else
    {
        int sel;
        cout << "\n\n==========================================================================================================" << endl;
        cout << "You have a RM " << voucherList[idex] << " voucher! Do you want to use it?" << endl;
        cout << "ATTENTION: Any balance of the voucher will not refund!" << endl;
        cout << "1. YES" << endl;
        cout << "2. NO" << endl;
        cout << "==========================================================================================================" << endl;
        cout << "Enter number of your choice: ";
        cin >> sel;
        while (sel != 1 && sel != 2)
        {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "|ATTEINTION: Invalid Choice|" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Enter Again: ";
            cin >> sel;
        }
        
        temp_voucher = voucherList[idex];
        if (sel == 1)
        {
            sum -= voucherList[idex];
            voucherList[idex] = 0;
            while (sum < 0)
            {
                sum = 0;
            }
        }
    }
    cout << endl << "Total Price             : RM ";
    cout << fixed << setprecision(2) << sum << endl;



    cout << "Your contact number     : " << phone_list[idex] << endl;
    cout << "Deliver Address         : " << address_list[idex] << endl;
    if (estimateKM_list[idex] < 40)
    {
        arrived_date = "within 24 hours";
    }
    else
    {
        int m2[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
        time_t t = time(NULL);
        tm* tptr = localtime(&t);
        year = tptr->tm_year + 1900;
        month = tptr->tm_mon + 1;
        day = tptr->tm_mday + 3;
        if ((day > m2[month]) && (year % 4 != 0))
        {
            month++;
            day = day - m2[month - 1];
            arrived_date = to_string(year) + '/' + to_string(month) + '/' + to_string(day);
        }
        else if ((year % 4 == 0) && (month == 2) && (day > 29))
        {
            month++;
            day = day - 29;
            arrived_date = to_string(year) + '/' + to_string(month) + '/' + to_string(day);
        }


    }
    cout << "Estimate arrived date   : " << arrived_date << endl;
    token = sum / 100;


    cout << "\n\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
    cout << "KEY IN [YES] TO PAY OR [NO] FOR CANCEL" << endl;
    cout << "Your choice[YES/NO]: ";
    getline(cin >> ws, makeSure);
    while (makeSure != "YES" && makeSure != "NO")
    {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "|ATTEINTION: Invalid Choice|" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "Enter Again: ";
        getline(cin >> ws, makeSure);
    }
    if (makeSure == "YES")
    {
        vector<string> empty_record;
        empty_record.clear();
        cout << "**********************************************************************************" << endl;
        cout << "------------------------------------------------------------------------------" << endl;
        cout << "| PAID using TNG eWallet.Thanks For using Buy Everthing Online System(BEO)!! |" << endl;
        cout << "------------------------------------------------------------------------------" << endl;
        cout << "           You had earn [ " << token << " ] token for LuckLuckLuck Voucher!!        " << endl;
        cout << "-----------------------------------------------------------------------------------------------------" << endl;
        tokenGuess_list[idex] = tokenGuess_list[idex] + token;
        getIndex(username_list, name);
        int t = buy_record_list.size() + 1001;
        string s_t = to_string(t);
        empty_record.push_back(s_t);
        empty_record.push_back(username_list[idex]);
        
        time_t t2 = time(NULL);
        tm* tptr = localtime(&t2);
        year2 = tptr->tm_year + 1900;
        month2 = tptr->tm_mon + 1;
        day2 = tptr->tm_mday;
        hour = tptr->tm_hour;
        minute = tptr->tm_min;

        string last_date,print_receipt;
        if(minute < 10)
        {
            last_date = to_string(year2) + '/' + to_string(month2) + '/' + to_string(day2) + ' ' + to_string(hour) + ':' + "0" + to_string(minute);
        }
        else
        {
            last_date = to_string(year2) + '/' + to_string(month2) + '/' + to_string(day2) + ' ' + to_string(hour) + ':' + to_string(minute);
        }
        empty_record.push_back(last_date);
        for (int i = 0; i < new_buy_item.size(); i++)
        {
            empty_record.push_back(newItem_list[i]);
            empty_record.push_back(to_string(final_item_list[i]));
        }
        empty_record.push_back(to_string(sum));
        empty_record.push_back(arrived_date);
        getIndex(username_list,name);
        empty_record.push_back(phone_list[idex]);
        empty_record.push_back(address_list[idex]);
        buy_record_list.push_back(empty_record);
        writePurchaseRecord(buy_record_list);
        checkStatusPurchase_list.push_back("Pending");
        writeStatusPurchase(checkStatusPurchase_list);
        cout << "Do you want to print receipt(YES/NO): ";
        getline(cin >> ws, print_receipt);
        while (print_receipt != "YES" && print_receipt != "NO")
        {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "|ATTEINTION: Invalid Choice|" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "Enter Again: ";
            getline(cin >> ws, print_receipt);
        }
        
        if(print_receipt == "YES")
        {
            ofstream receiptR;
            receiptR.open("receipt" + s_t + ".txt");
            receiptR << setw(80) << "RECEIPT" << endl;
            receiptR << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
            receiptR << "Invoice Num       : " << s_t << endl;
            receiptR << "Username Purchased: " << username_list[idex] << endl;
            receiptR << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
            receiptR << setw(10) << "NO." << setw(30) << "Item Name" << setw(30) << "Price Per Unit(RM)" << setw(30) << "Total unit" << setw(30) << "Total discount(RM)" << setw(30) << "Final Price(RM)" << endl;
            receiptR << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
            for (int j = 0; j < new_buy_item.size(); j++)
            {
                receiptR << setw(10) << j + 1 << setw(30) << newItem_list[j] << setw(30) << fixed << setprecision(2) << new_price_list[j] << setw(30) << final_item_list[j] << setw(30) << fixed << setprecision(2) << discount_list[j] << setw(30) << fixed << setprecision(2) << fprice_list[j] << endl;
            }
            receiptR << "\nTotal Purchase: RM  " << sum << endl;
            receiptR << "Phone Number  : " << phone_list[idex] << endl;
            receiptR << "Address       : " << address_list[idex] << endl;
            receiptR.close();
        }

        writeProduct(buyItem_list);
        if(sum >= 30)
        {
            registerDateList[(idex*4)+3]++;
        }
        writeRegisterDate(registerDateList);
        system("PAUSE");
        userPage();
    }
    else if (makeSure == "NO")
    {
        cout << "**********************************************************************************" << endl;
        voucherList[idex] = temp_voucher;
        cout << "------------------------------------------------" << endl;
        cout << "| CANCELED.Thanks For using BuyBuyBuy System!! |" << endl;
        cout << "------------------------------------------------" << endl;
        system("PAUSE");
        userPage();
    }


}

void luck()
{
    system("CLS");
    int choiceUser;
    getIndex(username_list, name);
    cout << "\t\t  --------------------------------------" << endl;
    cout << "\t\t  |      Welcome To LuckLuckLuck!!     |" << endl;
    cout << "=======================================================================" << endl;
    cout << "\t\t\t{ You left [ " << tokenGuess_list[idex] << " ] token! }" << endl;
    cout << "-----------------------------------------------------------------------" << endl;
    cout << "| 1. Continue Playing...                                              |" << endl;
    cout << "-----------------------------------------------------------------------" << endl;
    cout << "| 2. BACK                                                             |" << endl;
    cout << "-----------------------------------------------------------------------" << endl;
    cout << "Enter your choice [number]: ";
    cin >> choiceUser;
    while(choiceUser != 1 && choiceUser != 2)
    {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "|ATTEINTION: Invalid Choice|" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "Enter Again: ";
        cin >> choiceUser;
    }
    if(choiceUser == 2)
    {
        userPage();
    }
    system("PAUSE");
    if (tokenGuess_list[idex] > 0)
    {
        system("CLS");
        int choice, ans, guess;
        srand(unsigned(time(NULL)));
        choice = rand() % 3 + 1;
        if (choice == 1)
        {
            int start = 0;
            int end = 100;
            int times = 1;
            int voucher;
            cout << "***************************Guess the number between 0 to 100*******************************" << endl;
            cout << "****************************Win Special Voucher Up To RM66*************************************" << endl;
            cout << "================================================================================================" << endl;
            ans = rand() % 100 + 1;
            do
            {
                cout << "Guess number " << times << " times: ";
                cin >> guess;
                while(cin.fail())
                {
                    cout << "***ONLY KEY IN NUMBER***" << endl;
                    cout << "Guess number " << times << " times: ";
                    cin.clear();
                    cin.ignore(256, '\n');
                    cin >> guess;
                }
                if (guess > ans)
                {
                    cout << "You guess too high!" << endl;
                    end = guess;
                    cout << "Guess from " << start << " - " << end << endl;
                }
                else if (guess < ans)
                {
                    cout << "You guess too low!" << endl;
                    start = guess;
                    cout << "Guess from " << start << " - " << end << endl;
                }
                else
                {
                    cout << "\n\nCongratulation!You guess the correct answer!!" << endl;
                    cout << "Attempt times: " << times << endl;
                }
                cout << "\n--------------------------------------------------\n";
                times++;
            } while (guess != ans);

            if (times-1 <= 2)
            {
                voucher = 66;
            }
            else if (times-1 >= 3 && times-1 <= 4)
            {
                voucher = 33;
            }
            else if (times-1 > 4 && times-1 <= 6)
            {
                voucher = 6;
            }
            else
            {
                voucher = 0;
                cout << "Sorry.Try again next time!" << endl;
            }
            cout << "You have won RM" << voucher << " voucher !!!" << endl;
            getIndex(username_list, name);
            tokenGuess_list[idex] = tokenGuess_list[idex] - 1;
            voucherList[idex] += voucher;



            system("PAUSE");
            userPage();
        }

        else if (choice == 2)
        {
            system("CLS");
            int voucher;
            int result = 0;
            cout << "****************GUESS WORD FOR VOUCHER****************" << endl;
            cout << "All words come from catalogue of BuyBuyBuy Supermarket" << endl;
            cout << "======================================================" << endl;
            cout << "Are You Ready!!!!!" << endl;
            system("PAUSE");
            auto start = high_resolution_clock::now();
            cout << "Go! Go! Go!" << endl;
            cout << "-------------------------------------------------------" << endl << endl;
            vector<string> storeItem;
            for (int i = 0; i < buyItem_list.size(); i++)
            {
                for (int j = 0; j < buyItem_list[i].size(); j += 5)
                {
                    string store = buyItem_list[i][j];

                    for_each(store.begin(), store.end(), [](char& c)
                        {
                            c = ::tolower(c);
                        });
                    storeItem.push_back(store);
                }
            }
            srand(unsigned(time(NULL)));
            random_shuffle(storeItem.begin(), storeItem.end());

            for (int i = 0; i < 10; i++)
            {
                srand(unsigned(time(NULL)));
                string one = storeItem[i];

                random_shuffle(one.begin(), one.end());
                cout << i + 1 << ". ";
                for (const char& alp : one)
                {
                    cout << alp << " ";
                }
                cout << "\n";
                string ans;
                cout << "Enter your guess: ";
                getline(cin >> ws, ans);
                if (ans == storeItem[i])
                {
                    cout << "\nSuccess" << endl;
                    result++;
                }
                else
                {
                    cout << "\nSorry..Failed..Correct Answer Is " << storeItem[i] << endl;
                }
                cout << "===================================================" << endl;
            }
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<seconds>(stop - start);
            cout << "Time Taken For This Guess is ------> " << duration.count() << " sec" << endl;
            cout << "You had answer correct " << result << " question!!";
            if (result > 8 && duration.count() < 20)
            {
                voucher = 66;
            }
            else if (result > 8 && duration.count() < 30)
            {
                voucher = 16;
            }
            else if (result > 8 && duration.count() < 50)
            {
                voucher = 6;
            }
            else
            {
                voucher = 0;
            }
            cout << "You have won RM" << voucher << " voucher !!!" << endl;
            voucherList[idex] += voucher;
            tokenGuess_list[idex] = tokenGuess_list[idex] - 1;
            system("PAUSE");
            userPage();
        }
        else if(choice == 3)
        {
            system("CLS");
            char a,end;
            int voucher, time = 0,score = 0;
        
            cout << "\t\t-------------------------------------------" << endl;
            cout << "\t\t| Hands-on Speed (WIN VOUCHER UP TO RM66) |" << endl;
            cout << "\t\t-------------------------------------------" << endl;
            cout << "[ Instruction: Press [a] then enter in 5 seconds *The faster you click,the bigger the prizes* ]" << endl;
            cout << "\n=======================================================================================================================" << endl;
            cout << "Press Enter To Start The Game!!" << endl;
            system("PAUSE");
            auto start = high_resolution_clock::now();
        
            do
            {
                cout << "Enter a + enter" << endl;
                cin >> a;
                while(a != 'a')
                {
                    cout << "Only Accept [a]" << endl;
                    cin >> a;
                }
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<seconds>(stop - start);
                time = duration.count();
                score++;
            } while (time <= 5);
            cout << "\n\n-----------------------------------------------------------------------" << endl;
            cout << "Game Finished!!!" << endl;
            cout << "Enter [x] to close the game!" << endl;
            cin >> end;
            while (end != 'x')
            {
                cout << "Game Finished!!!" << endl;
                cout << "Enter [x] to close the game!" << endl;
                cin >> end;
            }
        
            cout << "Score: " << score << endl;
            if (score >= 40)
            {
                voucher = 66;
            }
            else if (score > 35 && score < 40)
            {
                voucher = 16;
            }
            else if (score >= 30 && score <= 35)
            {
                voucher = 6;
            }
            else
            {
                voucher = 0;
            }
            cout << "You have won RM" << voucher << " voucher !!!" << endl;
            voucherList[idex] += voucher;
            tokenGuess_list[idex] = tokenGuess_list[idex] - 1;
            system("PAUSE");
            userPage();
        }
    }
    else
    {
        cout << "\n-------------------------------------------------------------------------" << endl;
        cout << "|Sorry!You had not enough token! Purchase Up To RM100 To Get The Token!!|" << endl;
        cout << "-------------------------------------------------------------------------" << endl;
        system("PAUSE");
        userPage();
    }


}



void rating()
{
    system("CLS");
    float sum = 0;
    int choice;
    float cal_star;
    float star;
    readRateNameFile();
    for(int i = 2;i < rate_name_list.size(); i+=3)
    {
        sum += stof(rate_name_list[i]);
    }

    star = sum / (rate_name_list.size()/3);

    cout << "\t\t-----------------------------------------------------------------------------------" << endl;
    cout << "\t\t|                               ~ ~ Information ~ ~                               |" << endl;
    cout << "\t\t-----------------------------------------------------------------------------------" << endl;
    cout << "\t\t|*Face ANY BUG?*                                                                  |" << endl;
    cout << "\t\t|Contact Developer Gmail: chickenbye35@gmail.com / juihongss@gmail.com            |" << endl;
    cout << "\t\t|Thanks For Your Help!                                                            |" << endl;
    cout << "\t\t-----------------------------------------------------------------------------------" << endl << endl;

    cout << "[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]" << endl << endl;

    cout << "===================================================== [ Comment Area ] =================================================================" << endl;
    cout << "\t\tAverage Rating For App: " << fixed << setprecision(1) << star << endl << endl;
    cout << "\t\t" << rate_name_list.size()/3 << " users had rating this app!" << endl << endl;
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;


    for (int i = 0; i < rate_name_list.size(); i+=3)
    {
        cout << "\tUsername: " << rate_name_list[i] << endl;
        cout << "\tRating: " << setprecision(1) << stof(rate_name_list[i+2]) << endl;
        cout << "\tComment: " << rate_name_list[i+1] << endl;
        cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
    }
    system("PAUSE");
    cout << "Do you Want to leave a comment(1/2)?" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No.Maybe Next Time" << endl;
    cout << "Enter your choice(num): ";
    cin >> choice;
    while (choice != 1 && choice != 2)
    {
        system("Color 74");
        cout << "\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "\t\t\t|ATTEINTION: Invalid Choice|" << endl;
        cout << "\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cout << "\t\t\tEnter Again: ";
        cin >> choice;
    }
    if (choice == 1)
    {
        float rate;
        string comment;
        system("Color F0");
        
        cout << "=============================================================================" << endl;
        cout << "Enter your rating(?.?/can be decimal/FULL rate: 5): ";
        cin >> rate;
        while (cin.fail() || rate > 5 || rate < 0)
        {
            cout << "----------------------" << endl;
            cout << "|ERROR: Full rate = 5|" << endl;
            cout << "----------------------" << endl;
            cout << "Enter your rating again: ";
            cin.clear();
            cin.ignore(256, '\n');
            cin >> rate;
        }
        cout << "\n=============================================================================" << endl;
        cout << "Enter comment for this app: " << endl;
        getline(cin >> ws, comment);
        rate_name_list.push_back(name);
        rate_name_list.push_back(comment);
        rate_name_list.push_back(to_string(rate));
        writeRateName(rate_name_list);
        system("PAUSE");
        userPage();

    }
    else if (choice == 2)
    {
        system("Color F0");
        userPage();
    }
}



void accountSetting()
{
    int choice,choice2;
    system("CLS");
    getIndex(username_list, name);
    readphoneCarrier();
    cout << "\t\t\t===============================================================================================================" << endl;
    cout << "\t\t\t|                                               Personal Account Info                                         |" << endl;
    cout << "\t\t\t===============================================================================================================" << endl;
    cout << "\t\t\t  1. Username         : " << username_list[idex] << endl;
    cout << "\t\t\t  2. Password         : " << password_list[idex] << endl;
    cout << "\t\t\t  3. Hp Number        : " << phone_list[idex] << endl;
    cout << "\t\t\t  4. Delivered Address: " << address_list[idex] << endl;
    cout << "\t\t\t===============================================================================================================" << endl << endl;
    cout << "\t\t\t1. EDIT INFO" << endl;
    cout << "\t\t\t2. BACK" << endl;
    cout << "\t\t\tEnter your chocie(NUMBER): ";
    cin >> choice;
    while (choice != 1 && choice != 2)
    {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "|ATTEINTION: Invalid Choice|" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Enter Again: ";
        cin >> choice;
    }
    if (choice == 1)
    {
        system("CLS");
        cout << "\t\t\t+-----------------------------------+" << endl;
        cout << "\t\t\t|            [ EDIT ]               |" << endl;
        cout << "\t\t\t+-----------------------------------+" << endl;
        cout << "\t\t\t|      1. Change Password           |" << endl;
        cout << "\t\t\t-------------------------------------" << endl;
        cout << "\t\t\t|      2. Change Hp Number          |" << endl;
        cout << "\t\t\t-------------------------------------" << endl;
        cout << "\t\t\t|      3. Change delivered address  |" << endl;
        cout << "\t\t\t+-----------------------------------+" << endl;
        cout << "\t\t\t|      4. BACK                      |" << endl;
        cout << "\t\t\t+-----------------------------------+" << endl;
        cout << "Enter your choice(ENTER NUMBER): ";
        cin >> choice2;
        while (choice2 != 1 && choice2 != 2 && choice2 != 3 && choice2 != 4)
        {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "|ATTEINTION: Invalid Choice|" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Enter Again: ";
            cin >> choice2;
        }

        if (choice2 == 1)
        {
            string update_password;
            getIndex(username_list, name);
            cout << ".................................................................." << endl;
            cout << "Enter your new password: ";
            getline(cin >> ws, update_password);
            password_list[idex] = update_password;
            writePass(password_list);
            cout << endl << endl;
            cout << "---------------" << endl;
            cout << "| UPDATED.... |" << endl;
            cout << "---------------" << endl;
            system("PAUSE");
            userPage();
            
        }
        else if (choice2 == 2)
        {
            string update_hp;
            string c_phone, final_phone;
            getIndex(username_list, name);
            cout << ".................................................................." << endl;
            do
            {
                cout << "Enter your new phone number(Eg: +60 XXXXXXXXXX): ";
                getline(cin >> ws, update_hp);
                while (update_hp.length() < 12 || (update_hp[0] != '+' || update_hp[1] != '6' || update_hp[2] != '0'))
                {
                    cout << "\t---------------------------------------" << endl;
                    cout << "\t| Invalid phone number! Key In Again! |" << endl;
                    cout << "\t---------------------------------------" << endl;
                    cout << "Reenter your phone number(Eg: +60 XXXXXXXXXX): ";
                    getline(cin >> ws, update_hp);
                }
                ofstream phoneout;
                phoneout.open("phoneNum.txt");
                phoneout << update_hp << endl;
                phoneout.close();
                system("python -u \"./checkPhone.py\"");
                
                ifstream readCphone("phoneNum.txt");

                while(getline(readCphone,c_phone))
                {
                    final_phone = c_phone;
                }
                readCphone.close();
                remove("phoneNum.txt");

                if(final_phone == "")
                {
                    final_phone = "[ Non-Recognize ]. Please reenter again...";
                }
                cout << "Phone Carrier: " << final_phone << endl << endl;
            } while(final_phone == "[ Non-Recognize ]. Please reenter again...");
            
            phone_list[idex] = update_hp;
            writePhone(phone_list);
            phoneCarrierList[idex][0] = final_phone;
            phoneCarrierList[idex][1] = update_hp;
            writePhoneCarrier(phoneCarrierList);
            cout << endl << endl;
            cout << "---------------" << endl;
            cout << "| UPDATED.... |" << endl;
            cout << "---------------" << endl;
            system("PAUSE");
            userPage();
        }
        else if (choice2 == 3)
        {
            string update_address;
            getIndex(username_list, name);
            cout << ".................................................................." << endl;
            cout << "Enter your new delivered address: ";
            getline(cin >> ws, update_address);
            address_list[idex] = update_address;
            writeAddress(address_list);
            cout << endl << endl;
            cout << "---------------" << endl;
            cout << "| UPDATED.... |" << endl;
            cout << "---------------" << endl;
            system("PAUSE");
            userPage();
        }
        else if(choice2 == 4)
        {
            accountSetting();
        }

    }
    else if (choice == 2)
    {
        system("PAUSE");
        userPage();
    }
    
}

void foodRecord()
{
    system("CLS");
    getIndex(username_list, name);
    if (estimateKM_list[idex] > 30)
    {
        cout << "\t\t******************************JomEatEatEat*****************************************" << endl;
        cout << "\t\t|Sorry,distance too far...MORE BUYBUYBUY supermarket coming soon in more district.|" << endl;
        cout << "\t\t|                       ********Stay Tune!!********                               |" << endl;
        cout << "\t\t***********************************************************************************" << endl;
        system("PAUSE");
        userPage();
    }

    for(int i = 0;i < checkFoodRecord_list.size(); i+=3)
    {
        if(checkFoodRecord_list[i][2] == name)
        {
            break;
        }
        else
        {
            if(i == checkFoodRecord_list.size()-3)
            {
                if(checkFoodRecord_list[i][2] != name)
                {
                    cout << "\t--------------------------------------------" << endl;
                    cout << "\t| Didn't find any purchase food record.... |" << endl;
                    cout << "\t--------------------------------------------" << endl;
                    cout << "\t|          Back To Main Menu....           |" << endl;
                    cout << "\t--------------------------------------------" << endl;
                    system("PAUSE");
                    userPage();
                }
                
            }
        }
    }


    cout << "Food Purchase History" << endl;
    cout << "------------------------------------------------------------------" << endl;
    for(int i = 0;i < checkFoodRecord_list.size(); i+=3)
    {
        if(checkFoodRecord_list[i][2] == name)
        {
            cout << "Food No.: " << checkFoodRecord_list[i][1] << endl;
            cout << "Username: " << checkFoodRecord_list[i][2] << endl;
            cout << "Purchase Time: " << checkFoodRecord_list[i][3] << endl;
            cout << "Estimate Arrived: " << checkFoodRecord_list[i][4] << endl;
            cout << "Hp Num: " << checkFoodRecord_list[i][5] << endl;
            cout << "Deliver Address: " << checkFoodRecord_list[i][6] << endl;
            cout << "Deliver Status: " << checkFoodRecord_list[i][7] << endl;
            cout << "===============================================================================" << endl;
            cout << "Food Purchase|" << endl;
            cout << "--------------" << endl;
            for (int j = 0 ; j < checkFoodRecord_list[i+1].size(); j++)
            {
                cout << j+1 << ". " << checkFoodRecord_list[i+1][j] << endl;
            }
            cout << "------------------------------------------------------------------------------------" << endl;
            cout << "Drink Purchase|" << endl;
            cout << "---------------" << endl;
            for (int k = 0 ; k < checkFoodRecord_list[i+2].size(); k++)
            {
                cout << k+1 << ". " << checkFoodRecord_list[i+2][k] << endl;
            }
            cout << "------------------------------------------------------------------------------------" << endl;
            cout << "Total Purchased: RM " << checkFoodRecord_list[i][0] << "0" << endl;
            cout << endl << "================================================================================" << endl;
        }
        
    }
    cout << "==========================================[END OF DATA]==========================================" << endl;
    system("PAUSE");
    userPage();
}

void serviceChat()
{
    int day,choice;
	time_t t = time(NULL);
	tm* tptr = localtime(&t);
	readJoke();
	getIndex(username_list,name);
    srand(unsigned(time(NULL)));
	string text;
    vector<string> temp_store;
    for(int i = 0;i < buyItem_list.size(); i++)
    {
        for(int j = 0; j < buyItem_list[i].size(); j++)
        {
            temp_store.push_back(buyItem_list[i][j]);
        }
    }
	do
	{
		system("CLS");
        readChatAI();
		text = "";
		day = stoi(chatHistory[idex][2]);
        cout << "\t\t===================" << endl;
        cout << "\t\t| [ A.I CHATBOX ] |" << endl;
        cout << "\t\t===================" << endl;
		cout << "Username: " << name << endl;
		cout << getDate() << endl;
        cout << "---------------------------------------------------------------" << endl << endl;
		cout << "AI: Type [Chat To Customer Service] to chat with customer service." << endl << endl;
        cout << "AI: Type [Bye] to exit" << endl << endl;
		if(chatHistory[idex].size() > 2)
		{
			for(int i = 3;i < chatHistory[idex].size(); i++)
			{
				cout << chatHistory[idex][i] << endl << endl;
			}
		}
		if(day != tptr->tm_mday)
		{
			string autoReply = "AI: What can I help you? Type [Help] for help";
			cout << autoReply << endl;
			chatHistory[idex][2] = to_string(tptr->tm_mday);
			chatHistory[idex].push_back(autoReply);
		}
		cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
		
		cout << "Enter your message below: " << endl;
		getline(cin >> ws, text);
		
		for_each(text.begin(), text.end(), [](char& c)
        {
            c = ::tolower(c);
        });
        if(text != "bye")
		{
			text = "Me: " + text;
			chatHistory[idex].push_back(text);
		}
		if(text.find("hi") != string::npos || text.find("hello") != string::npos)
		{
			chatHistory[idex].push_back(ai_reply[0]);
		}
		else if(text.find("your name") != string::npos)
		{
			chatHistory[idex].push_back(ai_reply[1]);
		}
		else if(text.find("how are you") != string::npos)
		{
			chatHistory[idex].push_back(ai_reply[2]);
		}
		else if(text.find("chat to customer service") != string:: npos)
		{
			chatHistory[idex].push_back(ai_reply[3]);
            chatHistory[idex][0] = "unread";
            chatCAList[idex][0] = "unread";
            system("PAUSE");
            chatWithAdmin();
		}
		else if(text.find("sum") != string:: npos)
		{
			int times;
			int num, sum = 0;
			string ans;
			vector<int>temp_cal;
			temp_cal.clear();
			cout << "How many number you want to add: ";
			cin >> times;
			
			for(int i = 0; i < times; i++)
			{
				cout << "Enter number " << i+1 << ": ";
				cin >> num;
				temp_cal.push_back(num);
				sum += num;
			}
			for(int j = 0;j <temp_cal.size(); j++)
			{
				if(j == temp_cal.size()-1)
				{
					ans += to_string(temp_cal[j]);
				}
				else
				{
					ans += to_string(temp_cal[j]) + " + ";
				}
				
			}
			
			chatHistory[idex].push_back("AI: " + ans + " = " + to_string(sum));
		}
		else if(text.find("multiple") != string:: npos)
		{
			int times;
			int num, sum = 0;
			string ans;
			vector<int>temp_cal;
			temp_cal.clear();
			cout << "How many number you want to multiple: ";
			cin >> times;
			
			for(int i = 0; i < times; i++)
			{
				cout << "Enter number " << i+1 << ": ";
				cin >> num;
				temp_cal.push_back(num);
				sum *= num;
			}
			for(int j = 0;j <temp_cal.size(); j++)
			{
				if(j == temp_cal.size()-1)
				{
					ans += to_string(temp_cal[j]);
				}
				else
				{
					ans += to_string(temp_cal[j]) + " * ";
				}
				
			}
			
			chatHistory[idex].push_back("AI: " + ans + " = " + to_string(sum));
		}
		else if(text.find("minus") != string:: npos || text.find("substraction") != string:: npos || text.find("substract") != string:: npos)
		{
			int times;
			int num, sum = 0;
			string ans;
			vector<int>temp_cal;
			temp_cal.clear();
			cout << "How many number you want to minus: ";
			cin >> times;
			
			for(int i = 0; i < times; i++)
			{
				cout << "Enter number " << i+1 << ": ";
				cin >> num;
				temp_cal.push_back(num);
				sum -= num;
			}
			for(int j = 0;j <temp_cal.size(); j++)
			{
				if(j == temp_cal.size()-1)
				{
					ans += to_string(temp_cal[j]);
				}
				else
				{
					ans += to_string(temp_cal[j]) + " - ";
				}
				
			}
			
			chatHistory[idex].push_back("AI: " + ans + " = " + to_string(sum));
		}
		else if(text.find("divide") != string:: npos)
		{
			int times;
			int num, sum = 0;
			string ans;
			vector<int>temp_cal;
			temp_cal.clear();
			cout << "How many number you want to divide: ";
			cin >> times;
			
			for(int i = 0; i < times; i++)
			{
				cout << "Enter number " << i+1 << ": ";
				cin >> num;
				temp_cal.push_back(num);
				sum /= num;
			}
			for(int j = 0;j <temp_cal.size(); j++)
			{
				if(j == temp_cal.size()-1)
				{
					ans += to_string(temp_cal[j]);
				}
				else
				{
					ans += to_string(temp_cal[j]) + " / ";
				}
				
			}
			
			chatHistory[idex].push_back("AI: " + ans + " = " + to_string(sum));
		}
		else if(text.find("date") != string:: npos && (text.find("today") != string:: npos || text.find("now") != string:: npos))
		{
			string date = "AI: Today is " + getDate();
			chatHistory[idex].push_back(date);
		}
		else if(text.find("time") != string:: npos && (text.find("today") != string:: npos || text.find("now") != string:: npos))
		{
			string date = "AI: Time now is " + getTime();
			chatHistory[idex].push_back(date);
		}
		else if(text.find("joke") != string:: npos)
		{
			srand(unsigned(time(NULL)));
    		choice = rand() % 50 + 1;
			chatHistory[idex].push_back("AI: " + joke[choice]);
		}
		else if(text.find("sad") != string:: npos)
		{
			srand(unsigned(time(NULL)));
    		choice = rand() % 25 + 1;
			chatHistory[idex].push_back("AI: Don't Be Sad. Be happy!! Let's me told you a joke!");
			chatHistory[idex].push_back("AI: " + joke[choice]);
		}
		else if(text == "Me: help")
		{
			chatHistory[idex].push_back("AI: 1. Type [Chat To Customer Service] to chat with customer service.");
			chatHistory[idex].push_back("AI: 2. Type [Bye] to exit");
		}
		else if(text.find("morning") != string:: npos)
		{
			time_t t = time(NULL);
			tm* tptr = localtime(&t);
			int hour = tptr->tm_hour;
			if(hour >= 6 && hour < 12)
			{
				chatHistory[idex].push_back("AI: A good morning to you, too.Let me know if there's anything I can help you ^_^");
			}
			else
			{
				if(hour >= 12 && hour < 18)
				{
					chatHistory[idex].push_back("AI: Already afternoon ^_^ !! Hope you have a nice day !");
				}
				else if(hour == 18)
				{
					chatHistory[idex].push_back("AI: Already evening ^_^ !! Hope you have a nice day !");
				}
				else
				{
					chatHistory[idex].push_back("AI: Already night ^_^ !! Hope you have a nice day !");
				}
			}
		}
		else if(text.find("afternoon") != string:: npos)
		{
			time_t t = time(NULL);
			tm* tptr = localtime(&t);
			int hour = tptr->tm_hour;
			if(hour >= 12 && hour < 18)
			{
				chatHistory[idex].push_back("AI: A good afternoon to you, too.Let me know if there's anything I can help you ^_^");
			}
			else
			{
				if(hour >= 6 && hour < 12)
				{
					chatHistory[idex].push_back("AI: Already morning ^_^ !! Hope you have a nice day !");
				}
				else if(hour == 18)
				{
					chatHistory[idex].push_back("AI: Already evening ^_^ !! Hope you have a nice day !");
				}
				else
				{
					chatHistory[idex].push_back("AI: Already night ^_^ !! Hope you have a nice day !");
				}
			}
		}
		else if(text.find("night") != string:: npos)
		{
			time_t t = time(NULL);
			tm* tptr = localtime(&t);
			int hour = tptr->tm_hour;
			if(hour >= 18 || hour < 6)
			{
				chatHistory[idex].push_back("AI: A good night to you, too.Let me know if there's anything I can help you ^_^");
			}
			else
			{
				if(hour >= 6 && hour < 12)
				{
					chatHistory[idex].push_back("AI: Already morning ^_^ !! Hope you have a nice day !");
				}
				else if(hour == 18)
				{
					chatHistory[idex].push_back("AI: Already evening ^_^ !! Hope you have a nice day !");
				}
				else
				{
					chatHistory[idex].push_back("AI: Already afternoon ^_^ !! Hope you have a nice day !");
				}
			}
		}
		else if(text.find("lucky number") != string:: npos)
		{
			vector<int> luckyList;
			for(int i = 1000; i < 10000; i++)
    		{
    		    luckyList.push_back(i);
   			}
   			srand(unsigned(time(NULL)));
   			random_shuffle(luckyList.begin(), luckyList.end());
			for(int i = 0; i < 30; i++)
   			{
   			    std::this_thread::sleep_for(std::chrono::milliseconds(100));
   			    std::cout << luckyList[i] << std::flush << endl;
   			}
   			system("CLS");
			chatHistory[idex].push_back("AI: Your lucky number is: " + to_string(luckyList[rand()%30+1]));
		}
		else if(text.find("random number") != string:: npos)
		{
			vector<int> temp_store_num;
			extractIntegerWords(text);
			if(randomNum_list.size() > 2 || randomNum_list.size() <= 0 || randomNum_list[1] <= randomNum_list[0])
			{
				chatHistory[idex].push_back("AI: ERROR..Eg: random number from 1 to 90");
			}
			else
			{
				for(int i = randomNum_list[0]; i<= randomNum_list[1]; i++)
				{
					temp_store_num.push_back(i);
				}
				srand(unsigned(time(NULL)));
   				random_shuffle(temp_store_num.begin(), temp_store_num.end());
				chatHistory[idex].push_back("AI: Random number is: " + to_string(temp_store_num[0])); 
			}
		}

        else if(text.find("play game")!= string:: npos || text.find("boring")!= string:: npos || text.find("play a game")!= string:: npos)
        {
            chatHistory[idex].push_back("AI: Game Start...");
            memoryGame();
        }

        else if(text.find("food") != string:: npos || text.find("recommend") != string:: npos || text.find("eat today")!= string:: npos || text.find("recommended food") != string:: npos || text.find("hungry") != string:: npos)
        {
            vector<int>store_num1;
            
            vector<int>store_num2;
            float price = 0;
            
            for(int i = 0; i < mainFood_list.size(); i+=2)
            {
                store_num1.push_back(i);
                
            }

            
            for(int i = 0; i < addFood_list.size(); i+=2)
            {
                store_num2.push_back(i);
            }

            random_shuffle(store_num1.begin(),store_num1.end());
            random_shuffle(store_num2.begin(),store_num2.end());
            price += stof(mainFood_list[store_num1[0] + 1]);
            price += stof(addFood_list[store_num2[0] + 1]);
            string str_price = to_string(price).substr(0, to_string(price).find(".") + 3);

            chatHistory[idex].push_back("AI: Can try our " + mainFood_list[store_num1[0]] + " + " + addFood_list[store_num2[0]] + " that sold at our BuyBuyBuy Supemarket! It taste superb delicious!!");
            chatHistory[idex].push_back("AI: It only cost RM " + str_price);
            
        }

        else if(text.find("brain teaser") != string:: npos)
        {
            int x;
            do
            {
                srand(unsigned(time(NULL)));
                x = rand() % 101 + 1;
            }while(x % 2 != 0);

            chatHistory[idex].push_back("AI: " + brainTeaserList[x]);
            chatHistory[idex].push_back("AI: " + brainTeaserList[x+1]);
        }
        else if(text.find("calculate") != string:: npos || text.find("calculation") != string:: npos)
        {
            string equation;
            cout << "Enter equation here: ";
            getline(cin >> ws, equation);
            string finalEQ = "SET /a " + equation;
            const char *strEQ = finalEQ.c_str();
            int ans = system(strEQ);
            string finalAns = to_string(ans);
            finalAns.pop_back();
            string fE = "AI: Answer is " + finalAns;
            chatHistory[idex].push_back(fE);
        }
        else if(text.find("what") != string::npos && (text.find("category") != string::npos || text.find("type") != string::npos) && (text.find("item") != string::npos || text.find("product") != string::npos) && (text.find("sold") != string::npos || text.find("sell") != string::npos || text.find("find") != string::npos || text.find("buy") != string::npos)|| text.find("bought") != string::npos)
        {
            string ans = "";
            for(int i = 0; i < buyItemType_list.size(); i++)
            {
                ans += buyItemType_list[i] + ", ";   
            }
            chatHistory[idex].push_back("AI: Types of products sold in BuyBuyBuy Supermarket are " + ans + "and more category will release in the futrue! With Cheapest price ! *^~^*");
        }
        else if(text.find("what") != string::npos && (text.find("item") != string::npos || text.find("product") != string::npos) && (text.find("sold") != string::npos || text.find("sell") != string::npos || text.find("find") != string::npos || text.find("buy") != string::npos)|| text.find("bought") != string::npos)
        {
            string ans = "";
            for(int i = 0; i < buyItem_list.size(); i++)
            {
                for(int j = 0; j < buyItem_list[i].size(); j+=5)
                {
                    ans += buyItem_list[i][j] + ", ";
                }
            }
            chatHistory[idex].push_back("AI: Products sold in BuyBuyBuy Supermarket are " + ans + "and more products will release in the futrue! With Affordable price ! *^~^*");
        }
        else if(text.find("delivery") != string::npos && text.find("fee") != string::npos)
        {
            chatHistory[idex].push_back("AI: Our delivery fee is totally FREE !!");
        }
        else if((text.find("change") != string::npos || text.find("edit") != string::npos) && (text.find("phone")) != string::npos)
        {
            chatHistory[idex].push_back("AI: STEP 1. Customers need to enter [9] Account Setting at user menu page.");
            chatHistory[idex].push_back("AI: STEP 2. Customers need to enter [1] EDIT INFO at Account Setting.");
            chatHistory[idex].push_back("AI: You can know edit your personal info !!");
        }           
        else
        {
            chatHistory[idex].push_back("AI: SORRY, Cant'understand BUT I will continue learning!");
        }
        writeChatAI(chatHistory);

	} while (text != "bye");
    chatHistory[idex].pop_back();
    writeChatAI(chatHistory);
    
	userPage();

    
}

void chatWithAdmin()
{
    system("CLS");
    string text;
    getIndex(username_list,name);
    do
    {
        system("CLS");
        text = "";
        cout << "Username: " << name << endl;
        cout << "------------------------------------------------" << endl << endl;
        cout << "AI: Chat With Customer Service Now...." << endl << endl;
        cout << "AI: Type [Bye] to exit Chatbox Feature" << endl << endl;

        if(chatCAList[idex].size() >= 2)
        {
            for(int i = 2;i < chatCAList[idex].size(); i++)
            {
                cout << chatCAList[idex][i] << endl << endl;
            }
        }

        cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
        cout << "Enter your message below: " << endl;
        getline(cin >> ws, text);
        time_t t = time(NULL);
        string str_min;
		tm* tptr = localtime(&t);
		int hour = tptr->tm_hour;
        int min = tptr->tm_min;
        int mon = tptr->tm_mon+1;
        int day = tptr->tm_mday;
        if (min < 10)
        {
            str_min = "0" + to_string(min);
        }
        else
        {
            str_min = to_string(min);
        }

        chatCAList[idex].push_back("[" + to_string(day) + "/" + to_string(mon) + " | " + to_string(hour) +":" + str_min + "]\t" + "Me: " + text);
        writeChatAdmin(chatCAList);
    } while (text != "bye");
    chatCAList[idex].pop_back();
    writeChatAdmin(chatCAList);
    userPage();
}

void calculateAgeAlive()
{
    time_t t = time(NULL);
    tm* tptr = localtime(&t);
    int dobby,aliveMon,aliveDay,aliveYear;
    vector<int> month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    getIndex(username_list,name);
    string ic = userInfo_list[(idex*4) + 1];
    string yearI = ic.substr(0,2);
    string monI = ic.substr(2,2);
    string dayI = ic.substr(4,2);

    int birthYear = stoi(yearI);
    int birthMon = stoi(monI);
    int birthDay = stoi(dayI);

    int currentYear = (tptr->tm_year) + 1900;
    int currentMonth = (tptr->tm_mon + 1);
    int currentDay = (tptr-> tm_mday);

    if(currentYear % 4 == 0)
    {
        month[1] = 29;
    }

    if (birthYear > (currentYear % 2000))
    {
        dobby = 1900 + birthYear;
    }
    else
    {
        dobby = 2000 + birthYear;
    }

    aliveYear = currentYear - dobby;
    if(currentMonth >= birthMon)
    {
        aliveMon = currentMonth-birthMon;
    }
    else
    {
        aliveYear--;
        aliveMon = 12 + currentMonth - birthMon;
    }

    if(currentDay >= birthDay)
    {
        aliveDay = currentDay - birthDay;
    }
    else
    {
        aliveMon--;
        int days = month[currentMonth-2];
        aliveDay = days + currentDay - birthDay;

        if(birthMon < 0)
        {
            aliveMon = 11;
            aliveYear--;
        }
    }

    int total = 0;
    float percentageYear;


    for(int i =0; i < currentMonth - 1; i++)
    {
        total += month[i];
    }

    total += currentDay;
    percentageYear = (total/365.0) * 100;

    int liveday = (aliveYear*365) + (aliveMon*30) + aliveDay;
    int livehour = liveday * 24;
    int livemin = livehour * 60;
    int livesec = livemin * 60;

    cout << "+--------------------------------------------------------+" << endl;
    cout << "|\tYear\t\tMonth\t\tDay              |" << endl;
    cout << "+--------------------------------------------------------+" << endl;
    cout << "\t " + to_string(aliveYear) + "\t\t  " + to_string(aliveMon) + "\t\t " + to_string(aliveDay) << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << "This Year Had Already Pass " << fixed << setprecision(1) << percentageYear << " %" << endl;
    cout << "You had stay in this world for about " + to_string(liveday) + " days !!" << endl;
    cout << "You had stay in this world for about " + to_string(livehour) + " hours !!" << endl;
    cout << "You had stay in this world for about " + to_string(livemin) + " minutes !!" << endl;
    cout << "You had stay in this world for about " + to_string(livesec) + " seconds !!" << endl << endl << endl;
    cout << "\t\t+-------------------------------------------------------------------+" << endl;
    cout << "\t\t| STAY POSITIVE. BETTER DAYS ARE ON THEIR WAYS. LIFE IS FANTASTICS! |" << endl;
    cout << "\t\t+-------------------------------------------------------------------+" << endl;
    cout << "\t\t| Purchase Using Our B.E.O System, Make Life Easier [FREE DELIVERY] |" << endl;
    cout << "\t\t+-------------------------------------------------------------------+" << endl;

}

void betaFeature()
{
    system("CLS");
    readRegisterDate();
    vector<string> store_get;
    getIndex(username_list,name);
    cout << "\t\tToday Quotes" << endl;
    cout << "---------------------------------------------------------" << endl;
    srand(unsigned(time(NULL)));
    int randomNUM = rand() % (quoteslist.size()+1);
    cout << quoteslist[randomNUM] << endl;

    calculateAgeAlive();


    getIndex(username_list,name);
    int totalPurchase = registerDateList[(idex*4)+3];
    // cout << totalPurchase << endl;
    for(int i = 1; i <= 10; i++)
    {
        if(i <= totalPurchase)
        {
            store_get.push_back("GET");
        }
        else
        {
            store_get.push_back(" X ");
        }
    }
    cout << "_______________________________________________________________________________________________________________" << endl << endl;
    cout << "\t\t\tCOLLECT { 10 } STAMPS FOR [ RM5.00 ] Voucher" << endl;
    cout << "\t\t\tTerms and Conditions: You will get a stamps once you purchase UP TO RM 30.00" << endl;
    cout << "\t\t\t+---------+   +---------+   +---------+   +---------+   +---------+" << endl;    
    cout << "\t\t\t|         |   |         |   |         |   |         |   |         |" << endl;
    cout << "\t\t\t|   "<<store_get[0]<<"   |"<<   "   |   "<<store_get[1]<<"   |"<<"   |   "<<store_get[2]<<"   |"<<"   |   "<<store_get[3]<<"   |" <<"   |   "<<store_get[4]<<"   |"<< endl;
    cout << "\t\t\t|         |   |         |   |         |   |         |   |         |" << endl;
    cout << "\t\t\t+---------+   +---------+   +---------+   +---------+   +---------+" << endl; 

    cout << "\t\t\t+---------+   +---------+   +---------+   +---------+   +---------+" << endl;    
    cout << "\t\t\t|         |   |         |   |         |   |         |   |         |" << endl;
    cout << "\t\t\t|   "<<store_get[5]<<"   |"<<   "   |   "<<store_get[6]<<"   |"<<"   |   "<<store_get[7]<<"   |"<<"   |   "<<store_get[8]<<"   |" <<"   |   "<<store_get[9]<<"   |"<< endl;
    cout << "\t\t\t|         |   |         |   |         |   |         |   |         |" << endl;
    cout << "\t\t\t+---------+   +---------+   +---------+   +---------+   +---------+" << endl; 

    if(registerDateList[(idex*4) + 3] == 10)
    {
        cout << "You had collect FULL 10 Stamps..Press any key to receive voucher." << endl;
        system("PAUSE");
        voucherList[idex] += 5;
        registerDateList[(idex*4) + 3] = 0;
        writeVoucher(voucherList);
        writeRegisterDate(registerDateList);
        cout << "+----------------+" << endl;
        cout << "+-- COLLECTED ---+" << endl;
        cout << "+----------------+" << endl;
    }
    system("PAUSE");
    userPage();


}




void userPage()
{
    system("Color F0");
    system("CLS");
    int choice;
    readNameFile();
    readPassFile();
    readVoucher();
    readAddress();
    readKMFile();
    readToken();
    readPhoneFile();
    readProduct();
    readProductType();
    readUserInfoFile();
    readPurchaseStatus();
    readPurchaseRecord();
    readDrink();
    readAddonFood();
    readDrinkPrice();
    readMainFood();
    readfoodRecord();
    readBrainTeaser();
    readQuotesList();
    readRegisterDate();
    readChatAdmin();
    cout << R"(
==============================================================================
|>            _   _ ___ ___ ___     __  __ ___ _  _ _   _                   <|
|>           | | | / __| __| _ \   |  \/  | __| \| | | | |                  <|
|>           | |_| \__ \ _||   /   | |\/| | _|| .` | |_| |                  <|
|>            \___/|___/___|_|_\   |_|  |_|___|_|\_|\___/                   <|
|>--------------------------------------------------------------------------<|
|>                 *PAYMENT ONLY ACCEPT TNG E-WALLET*                       <|
==============================================================================
|>    )";
    cout << "\t\t\t\t\t\tUsername: " << name << endl << "|>" << endl;
    cout << "|>\t1.  Purchase Item" << endl << "|>" << endl;
    cout << "|>\t2.  Food Delivery" << endl << "|>" << endl;
    cout << "|>\t3.  Win For Special Voucher(Luck! Luck! Luck!)" << endl << "|>" << endl;
    cout << "|>\t4.  Latest Online Purchase Record" << endl << "|>" << endl;
    cout << "|>\t5.  Food Purchase Tracker" << endl << "|>" << endl;
    cout << "|>\t6.  Chat With A.I/Customer Service" << endl << "|>" << endl;
    cout << "|>\t7.  Beta Version Feature" << endl << "|>" << endl;
    cout << "|>\t8.  Mobile TopUp" << endl << "|>" << endl;
    cout << "|>\t9.  Account Setting" << endl << "|>" << endl;
    cout << "|>\t10. Rating For Our App" << endl << "|>" << endl;
    cout << "|>\t11. Logout" << endl << "|>" << endl;
    cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "\tEnter your choice(1/2/3/4/5/6/7/8/9/10/11): ";
    cin >> choice;
    while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 7 && choice != 8 && choice != 9 && choice != 10 && choice != 11)
    {
        cout << "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "\t|ATTEINTION: Invalid Choice|" << endl;
        cout << "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cout << "\tEnter Again: ";
        cin >> choice;
    }

    if (choice == 1)
    {
        system("Color F0");
        purchaseItem();
    }
    else if (choice == 2)
    {
        system("Color F0");
        buyFood();
    }
    else if (choice == 3)
    {
        system("Color F0");
        luck();
    }
    else if (choice == 4)
    {
        system("Color F0");
        userRecord();
    }
    else if (choice == 5)
    {
        system("Color F0");
        foodRecord();
    }
    else if (choice == 6)
    {
        system("Color F0");
        serviceChat();
    }
    else if (choice == 7)
    {
        system("Color F0");
        betaFeature();
    }
    else if (choice == 8)
    {
        system("Color F0");
        mobileTopup();
    }
    else if (choice == 9)
    {
        system("Color F0");
        accountSetting();
    }
    else if (choice == 10)
    {
        system("Color F0");
        rating();
    }
    else if (choice == 11)
    {
        system("Color F0");
        mainPage();
    }

}


void mobileTopup()
{
    system("CLS");


    int choice,counter = 0;
    string sureContinue;
    vector<string> pricePaid = {"4.93","8.00","13.00","18.00","28.00","48.00","98.00"};
    readphoneCarrier();
    getIndex(username_list,name);
    cout << R"(
                                                             
 _____     _   _ _        _____            _____     
|     |___| |_|_| |___   |_   _|___ ___   |  |  |___ 
| | | | . | . | | | -_|    | | | . | . |  |  |  | . |
|_|_|_|___|___|_|_|___|    |_| |___|  _|  |_____|  _|
                                   |_|          |_|  
    )";
    cout << "\n";
    if(phoneCarrierList[idex][0] == "Non-Recognize")
    {
        string new_carrier;
        cout << "Enter phone carrier of your phone: ";
        getline(cin >> ws, new_carrier);
        phoneCarrierList[idex][0] = new_carrier;
        writePhoneCarrier(phoneCarrierList);
        readphoneCarrier();
    }
    cout << "\n\n";
    cout << "------------------------------------------------------------------------" << endl;
    cout << "Username     : " << username_list[idex] << endl << endl;
    cout << "Phone Number : " << phoneCarrierList[idex][0] << endl << endl;
    cout << "Phone Carrier: " <<phoneCarrierList[idex][1] << endl;
    cout << "------------------------------------------------------------------------" << endl;
    cout << "                         [ Purchase History ]                " << endl;
    cout << "------------------------------------------------------------------------" << endl;
    if(phoneCarrierList[idex].size() == 2)
    {
        cout << "No Any Purchase Record...." << endl;
        cout << "------------------------------------------------------------------------" << endl;
        system("PAUSE");
    }
    else
    {
        cout << "\tPurchase History" << "\t\t" << "Purchase Time" << endl;
        cout << "\t----------------" << "\t\t" << "-------------" << endl;
        for(int i = phoneCarrierList[idex].size()-1; i >= 2; i-=2) 
        {
            if(counter < 5)
            {
                cout << "\t- RM " << phoneCarrierList[idex][i-1] << "\t\t\t" << phoneCarrierList[idex][i] << endl;
                counter++;
            }
            else
            {
                break;
            }
            
        }
        cout << "\n\t\t+-----------+" << endl;
        cout << "\t\t| MORE..... |" << endl;
        cout << "\t\t+-----------+" << endl;
        cout << "Press Any Key And Enter To Continue OR Key IN [1] to show all the top up purchase history" << endl;
        cout << ">>>";
        getline(cin >> ws, sureContinue);
    }

    


    
    if(sureContinue == "1")
    {
        if(phoneCarrierList[idex].size() > 12)
        {
            system("CLS");
            cout << "\tPurchase History" << "\t\t" << "Purchase Time" << endl;
            cout << "\t----------------" << "\t\t" << "-------------" << endl;
            for(int i = phoneCarrierList[idex].size()-1; i >= 2; i-=2) 
            {
                cout << "\t- RM " << phoneCarrierList[idex][i-1] << "\t\t\t" << phoneCarrierList[idex][i] << endl;
            }
            system("PAUSE");
            system("CLS");
        }
        else
        {
            cout << "----------------------------------" << endl;
            cout << "| No More Purchase History Found |" << endl;
            cout << "----------------------------------" << endl;
        }
    }
    cout << "-------------------------------------------------------------------------------------------------------" << endl;
    cout << phoneCarrierList[idex][0] << " Prepaid Top Up (RM)" << endl;
    cout << R"(
        +====================================================+
        |                 |                  |                |
        | [1]  {1% OFF}   | [2]  {20% OFF}   | [3]  {13% OFF} |
        |      5.00       |      10.00       |      15.00     |
        |  Pay: RM 4.93   |   Pay: RM 8.00   |  Pay: RM 13.00 |
        |                 |                  |                |
        +=====================================================+
        |                 |                  |                |
        | [4]  {10% OFF}  | [5]  {7% OFF}    | [6]   {4% OFF} |
        |      20.00      |      30.00       |      50.00     |
        |  Pay: RM 18.00  |  Pay: RM 28.00   |  Pay: RM 48.00 |
        |                 |                  |                |
        +=====================================================+
        |                 |                                   |
        | [7]   {2% OFF}  |            MOBILE                 |
        |     100.00      |            TOP UP                 |
        |  Pay: RM 98.00  |        { [0] -- EXIT }            |
        |                 |                                   |
        +=====================================================+
    )";
    cout << "......................................................................." << endl;
    cout << "Enter your choice(1/2/3/4/5/6/7) [0-EXIT]: ";
    cin >> choice;
    while (cin.fail() || (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 7 && choice != 0))
    {
        cout << "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "\t|ATTEINTION: Invalid Choice|" << endl;
        cout << "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cout << "\tEnter Again: ";
        cin >> choice;
    }
    
    if(choice == 0)
    {
        userPage();
    }

    cout << "......................................................................." << endl << endl;
    string dateNow = getDate();
    string timeNow = getTime();
    string combineDT = dateNow + "  " + timeNow;
    cout << "\n\n";
    cout << "\t\t+=========================+" << endl;
    cout << "\t\t| Purchase Successfull !! |" << endl;
    cout << "\t\t+=========================+" << endl;
    cout << "......................................................................." << endl;
    cout << "- RM " << pricePaid[choice-1] << " had been detucted from your TNG E-WALLET" << endl;
    cout << "Purchase Time: " << combineDT << endl;

    phoneCarrierList[idex].push_back(pricePaid[choice-1]);
    phoneCarrierList[idex].push_back(combineDT);
    writePhoneCarrier(phoneCarrierList);
    
    system("PAUSE");
    userPage();
}




void memoryGame()
{
    system("CLS");
    int choice1,choice2;
    int score = 0;
    int attempt_times = 0;
    vector<int> number_list = {1,2,3,1,2,3,4,5,6,4,5,6};
    vector<vector<int>> store_num ={ {}, {}, {}, {} };
    vector<vector<int>> show_num ={ {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} };
    int times;
    vector<int> memory;
    vector<int> click;
    srand(unsigned(time(NULL)));


    random_shuffle(number_list.begin(), number_list.end());
    int iTotal = 0;
    memory.clear();
    for(int j = 0; j < number_list.size(); j+=3)
    {
        if(j == 3 || j == 6 || j == 9)
        {
            iTotal++;
        }
        store_num[iTotal].push_back(number_list[j]);
        store_num[iTotal].push_back(number_list[j+1]);
        store_num[iTotal].push_back(number_list[j+2]);
        
    }
    cout << "\tAI: Feel Boring? Play A Game Now!!" << endl;
    cout << R"(
                    +-----------------------------------------------------------------------------+                                                                 
                    |      /\/\   ___ _ __ ___   ___  _ __ _   _    __ _  __ _ _ __ ___   ___     |
                    |    /    \ / _ \ '_ ` _ \ / _ \| '__| | | |  / _` |/ _` | '_ ` _ \ / _ \     |
                    |   / /\/\ \  __/ | | | | | (_) | |  | |_| | | (_| | (_| | | | | | |  __/     |
                    |   \/    \/\___|_| |_| |_|\___/|_|   \__, |  \__, |\__,_|_| |_| |_|\___|     |
                    |                                     |___/   |___/                           |
                    +-----------------------------------------------------------------------------+   
    )";
    

    cout << R"(
                           [1]                            [2]                            [3]
           +---------------------------------------------------------------------------------------------------+
           |          +---------+                     +---------+                    +---------+               |
           |          |         |                     |         |                    |         |               |
           |          |         |                     |         |                    |         |               |                                                                            
      [1]  |          |   (a)   |                     |   (b)   |                    |   (c)   |               |                                                                                 
           |          |         |                     |         |                    |         |               |                                                                                 
           |          |         |                     |         |                    |         |               |                                                                                
           |          +---------+                     +---------+                    +---------+               |                                                 
           |                                                                                                   |                                                    
           |                                                                                                   |                                                  
           |                                                                                                   |                                                     
           |                                                                                                   |                                                       
           |          +---------+                     +---------+                    +---------+               |
           |          |         |                     |         |                    |         |               |
           |          |         |                     |         |                    |         |               |                                                                            
      [2]  |          |   (d)   |                     |   (e)   |                    |   (f)   |               |                                                                                 
           |          |         |                     |         |                    |         |               |                                                                                 
           |          |         |                     |         |                    |         |               |                                                                                  
           |          +---------+                     +---------+                    +---------+               |                                                   
           |                                                                                                   |                                                  
           |                                                                                                   |                                                  
           |                                                                                                   |                                                
           |                                                                                                   |                     
           |          +---------+                     +---------+                    +---------+               |
           |          |         |                     |         |                    |         |               |
           |          |         |                     |         |                    |         |               |                                                                            
      [3]  |          |   (g)   |                     |   (h)   |                    |   (i)   |               |                                                                                 
           |          |         |                     |         |                    |         |               |                                                                                 
           |          |         |                     |         |                    |         |               |                                                                                  
           |          +---------+                     +---------+                    +---------+               | 
           |                                                                                                   |
           |                                                                                                   |
           |                                                                                                   |
           |                                                                                                   |
           |          +---------+                     +---------+                    +---------+               |
           |          |         |                     |         |                    |         |               |
           |          |         |                     |         |                    |         |               |                                                                            
      [4]  |          |   (j)   |                     |   (k)   |                    |   (l)   |               |                                                                                 
           |          |         |                     |         |                    |         |               |                                                                                 
           |          |         |                     |         |                    |         |               |                                                                                  
           |          +---------+                     +---------+                    +---------+               |    
           |                                                                                                   |
           |                                                                                                   |
           +---------------------------------------------------------------------------------------------------+
    )";
    system("PAUSE");

    do
    {
        times = 0;
        do
        {
            system("CLS");
            cout << "SCORE: " << score <<endl;
            cout << "Attempt Times: " << attempt_times;
            cout << R"(
             ROW           [1]                            [2]                             [3]
            +---------------------------------------------------------------------------------------------------+
            |          +---------+                     +---------+                    +---------+               |
            |          |         |                     |         |                    |         |               |
            |          |         |                     |         |                    |         |               |                                                                            
        )";
        cout <<
         "[1] |          |    "    << show_num[0][0]  <<"    |                     |    " << show_num[0][1] << "    |                    |    " << show_num[0][2] << "    |               |";
        cout << R"(
            |          |         |                     |         |                    |         |               |                                                                                 
            |          |         |                     |         |                    |         |               |                                                                                
            |          +---------+                     +---------+                    +---------+               |                                                 
            |                                                                                                   |                                                    
            |                                                                                                   |                                                  
            |                                                                                                   |                                                     
            |                                                                                                   |                                                       
            |          +---------+                     +---------+                    +---------+               |
            |          |         |                     |         |                    |         |               |
            |          |         |                     |         |                    |         |               |                                                                            
        )";
        cout <<
         "[2] |          |    "    << show_num[1][0]  <<"    |                     |    " << show_num[1][1] << "    |                    |    " << show_num[1][2] << "    |               |";
        cout << R"(                                                                                
            |          |         |                     |         |                    |         |               |                                                                                 
            |          |         |                     |         |                    |         |               |                                                                                  
          C |          +---------+                     +---------+                    +---------+               |                                                   
          O |                                                                                                   |                                                  
          L |                                                                                                   |                                                  
          U |                                                                                                   |                                                
          M |                                                                                                   |                     
          N |          +---------+                     +---------+                    +---------+               |
            |          |         |                     |         |                    |         |               |
            |          |         |                     |         |                    |         |               |                                                                            
        )";
        cout <<
         "[3] |          |    "    << show_num[2][0]  <<"    |                     |    " << show_num[2][1] << "    |                    |    " << show_num[2][2] << "    |               |";  
        cout << R"(                                                                                
            |          |         |                     |         |                    |         |               |                                                                                 
            |          |         |                     |         |                    |         |               |                                                                                  
            |          +---------+                     +---------+                    +---------+               |                                                   
            |                                                                                                   |                                                  
            |                                                                                                   |                                                  
            |                                                                                                   |                                                
            |                                                                                                   |                     
            |          +---------+                     +---------+                    +---------+               |
            |          |         |                     |         |                    |         |               |
            |          |         |                     |         |                    |         |               |
        )";
        cout <<
         "[4] |          |    "    << show_num[3][0]  <<"    |                     |    " << show_num[3][1] << "    |                    |    " << show_num[3][2] << "    |               |";  
        cout << R"(                                                                                
            |          |         |                     |         |                    |         |               |                                                                                 
            |          |         |                     |         |                    |         |               |                                                                                  
            |          +---------+                     +---------+                    +---------+               |                                                   
            |                                                                                                   |
            +---------------------------------------------------------------------------------------------------+
        )";
            int z;
            cout << "Key In [-1] to exit the game" << endl;
            cout << "\nWhat column of number of card you want to choose: ";
            cin >> choice1;
            if(choice1 == -1)
            {
                userPage();
            }
        
            while (choice1 > 4 || choice1 < -1)
            {
                cout << "Invalid Input.Enter again: ";
                cin >> choice1;
            }
            
            cout << "What row of number of card you want to choose: ";
            cin >> choice2;
            if(choice2 == -1)
            {
                userPage();
            }
            while (choice2 > 3 || choice2 < -1)
            {
                cout << "Invalid Input.Enter again: ";
                cin >> choice2;
            }
            while(show_num[choice1-1][choice2-1] != 0)
            {
                cout << "Card selected! Enter another number" << endl;
                system("PAUSE");
                cout << "\nWhat column of number of card you want to choose: ";
                cin >> choice1;
                while (choice1 > 4 || choice1 < -1)
                {
                    cout << "Invalid Input.Enter again: ";
                    cin >> choice1;
                    if(choice1 == -1)
                    {
                        userPage();
                    }
                }

                cout << "What row of number of card you want to choose: ";
                cin >> choice2;
                while (choice2 > 3 || choice2 < -1)
                {
                    cout << "Invalid Input.Enter again: ";
                    cin >> choice2;
                    if(choice2 == -1)
                    {
                        userPage();
                    }
                }
            }
            
            click.push_back(choice1-1);
            click.push_back(choice2-1);


            for(int i = 1; i <= 3; i++)
            {
                for(int j = 1; j <= 3; j++)
                {
                    if(choice1 == i && choice2 == j)
                    {
                        show_num[choice1-1][choice2-1] = store_num[choice1-1][choice2-1];
                    }
                }
            }

            times++;

            memory.push_back(show_num[choice1-1][choice2-1]);
        }while(times != 2);
        system("CLS");
        attempt_times++;
        cout << R"(
             ROW           [1]                            [2]                             [3]
            +---------------------------------------------------------------------------------------------------+
            |          +---------+                     +---------+                    +---------+               |
            |          |         |                     |         |                    |         |               |
            |          |         |                     |         |                    |         |               |                                                                            
        )";
        cout <<
         "[1] |          |    "    << show_num[0][0]  <<"    |                     |    " << show_num[0][1] << "    |                    |    " << show_num[0][2] << "    |               |";
        cout << R"(
            |          |         |                     |         |                    |         |               |                                                                                 
            |          |         |                     |         |                    |         |               |                                                                                
            |          +---------+                     +---------+                    +---------+               |                                                 
            |                                                                                                   |                                                    
            |                                                                                                   |                                                  
            |                                                                                                   |                                                     
            |                                                                                                   |                                                       
            |          +---------+                     +---------+                    +---------+               |
            |          |         |                     |         |                    |         |               |
            |          |         |                     |         |                    |         |               |                                                                            
        )";
        cout <<
         "[2] |          |    "    << show_num[1][0]  <<"    |                     |    " << show_num[1][1] << "    |                    |    " << show_num[1][2] << "    |               |";
        cout << R"(                                                                                
            |          |         |                     |         |                    |         |               |                                                                                 
            |          |         |                     |         |                    |         |               |                                                                                  
          C |          +---------+                     +---------+                    +---------+               |                                                   
          O |                                                                                                   |                                                  
          L |                                                                                                   |                                                  
          U |                                                                                                   |                                                
          M |                                                                                                   |                     
          N |          +---------+                     +---------+                    +---------+               |
            |          |         |                     |         |                    |         |               |
            |          |         |                     |         |                    |         |               |                                                                            
        )";
        cout <<
         "[3] |          |    "    << show_num[2][0]  <<"    |                     |    " << show_num[2][1] << "    |                    |    " << show_num[2][2] << "    |               |";  
        cout << R"(                                                                                
            |          |         |                     |         |                    |         |               |                                                                                 
            |          |         |                     |         |                    |         |               |                                                                                  
            |          +---------+                     +---------+                    +---------+               |                                                   
            |                                                                                                   |                                                  
            |                                                                                                   |                                                  
            |                                                                                                   |                                                
            |                                                                                                   |                     
            |          +---------+                     +---------+                    +---------+               |
            |          |         |                     |         |                    |         |               |
            |          |         |                     |         |                    |         |               |
        )";
        cout <<
         "[4] |          |    "    << show_num[3][0]  <<"    |                     |    " << show_num[3][1] << "    |                    |    " << show_num[3][2] << "    |               |";  
        cout << R"(                                                                                
            |          |         |                     |         |                    |         |               |                                                                                 
            |          |         |                     |         |                    |         |               |                                                                                  
            |          +---------+                     +---------+                    +---------+               |                                                   
            |                                                                                                   |
            +---------------------------------------------------------------------------------------------------+
        )";
        system("PAUSE");
        if(memory[0] == memory[1])
        {
            memory.clear();
            cout << endl;
            cout << "\t\t-----------------" << endl;
            cout << "\t\t| Guess correct |" << endl;
            cout << "\t\t-----------------" << endl;
            score++;
            cout << score;
            system("PAUSE");
            system("CLS");
        }
        else
        {
            memory.clear();
            cout << endl;
            cout << "\t\t-----------------" << endl;
            cout << "\t\t| Guess Wrongly |" << endl;
            cout << "\t\t-----------------" << endl;

            show_num[click[click.size()-4]][click[click.size()-3]] = 0; 
            show_num[click[click.size()-2]][click[click.size()-1]] = 0; 
            click.clear();

            system("PAUSE");
            system("CLS");
        }
        
    }while(score != 6);

}


void login()
{
    system("CLS");
    vector<string> temp_nameList;
    for(int i = 0; i < username_list.size(); i++) {
        string firstEmail = username_list[i].substr(0, username_list[i].find(" "));
        temp_nameList.push_back(firstEmail);
    }
    cout << "\n\n\n\n\n\n\n\n\n\n\n";
    cout << "\t\t\t*************************************************************" << endl;
    cout << "\t\t\t|--------------------- [LOGIN PAGE] ------------------------|" << endl;
    cout << "\t\t\t|___________________________________________________________|" << endl;
    cout << "\t\t\t*************************************************************" << endl;
    readNameFile();
    readPassFile();
    cout << "\t\t\t\t\tEmail Address: ";
    getline(cin >> ws, name);
    cout << "\t\t\t" << endl;
    cout << "\t\t\t\t\tPassword     : ";
    getline(cin >> ws, password);

    getIndex(temp_nameList, name);



    for (int j = 2; j >= 0; j--)
    {
        if(username_list[idex][username_list[idex].length()-1] == ')')
        {
            cout << "------------------------------------------------------------------------------------------" << endl;
            cout << "|          This username account had been banned since viloate some rules.               |" << endl;
            cout << "------------------------------------------------------------------------------------------" << endl;
            system("PAUSE");
            mainPage();
        }
        if (username_list[idex] == name && password_list[idex] == password)
        {
            cout << "Login Success !!" << endl;
            userPage();
        }
        else
        {
            system("Color 74");
            cout << ".................................................................................................................." << endl;
            cout << "\t\t\t\t\t---------------------------------" << endl;
            cout << "\t\t\t\t\t|     Login Fail!! Try again!   |" << endl;
            cout << "\t\t\t\t\t---------------------------------" << endl;
            cout << "\t\t\t\t\t|Left:       " << j+1 << "         chances!!|" << endl;
            cout << "\t\t\t\t\t---------------------------------" << endl;
            cout << "\t\t\t\tEmail Address: ";
            getline(cin >> ws, name);
            cout << "\t\t\t\tPassword     : ";
            getline(cin >> ws, password);
            getIndex(username_list, name);
            if(j == 0)
            {
                if (username_list[idex] == name && password_list[idex] == password)
                {
                    cout << "Login Success !!" << endl;
                    userPage();
                }
                else
                {
                    system("CLS");
                    cout << "\t\t\t-----------------------" << endl;
                    cout << "\t\t\t|     Fail Login!!    |" << endl;
                    cout << "\t\t\t-----------------------" << endl;
                    cout << "\t\t\t|  Back To Main Menu  |" << endl;
                    cout << "\t\t\t-----------------------" << endl;
                    system("PAUSE");
                    mainPage();
                }
                
            }
        }
    }

    
    

}


int main()
{
    mainPage();
}