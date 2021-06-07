#include<iostream>
#include<string>
#include<conio.h>
#include<iomanip>
#include<fstream>
#include<ctype.h>
#include<stdio.h>
#include<thread>
#include<chrono>
using namespace std;

class Account
{
	int accountNumber = 1934;
	char ID[15], phone[11];
	int type, type_1 = 0, gender, number;
	double deposit, deposit_1;
	char password[50], a, password1[50], password2[50];
	int i = 0, amount;
	int age; string prof, check_pass3, check_pass1, check_pass2, ReCaptcha, name, check_ID, check_phone;
public:
	Account() {
		accountNumber = 20391; ID[14] = { '0' }; phone[11] = { '0' }; deposit = 0; age = 0;
	}
	void Create();
	void Show();
	void Modify();
	void Withdrow();
	void Deposit();
	int Re_accountNumber();
	int Re_balance();
	void Re_type();
	void Menue();
	void del_account();
};

void Account::Create()
{
START:
	system("cls");
	cout << "\n\t\t   </> Creating New Account </>\n";
	cout << "\t\t----------------------------------\n\n";
	cout << "\n Account  [ " << accountNumber << " ]" << endl << endl;
	cout << "\n Enter The Name    :  ";
	cin.ignore();
	getline(cin, name);
	cout << "\n Enter Your Age    :  ";
	std::cin >> age;
	if (age >= 16) {
		cout << "\n The Mobile Phone  :  ";
		for (i = 0;; ) {
			a = _getch();
			if (a >= '0' && a <= '9') {
				if (i < 11) {
					phone[i] = a;
					++i;
					cout << a;
				}
			}
			if (a == '\b' && i >= 1) {
				cout << "\b \b";
				--i;
			}
			if (a == '\r' && i == 11) {
				phone[i] = '\0';
				break;
			}
		}
		check_phone = phone;
		cout << "\n\n Your Profession   :  ";


		cin.ignore();
		getline(cin, prof);
		cout << "\n\n Select The Gender : \t 1) Male    2) Femal\n\n -->  ";
		std::cin >> gender;
		cout << "\n Your National ID  :  ";
		for (i = 0; ; ) {
			a = _getch();
			if (a >= '0' && a <= '9') {
				if (i < 14) {
					ID[i] = a;
					++i;
					cout << a;
				}
			}
			if (a == '\b' && i >= 1) {
				cout << "\b \b";
				--i;
			}
			if (a == '\r' && i == 14) {
				ID[i] = '\0';
				break;
			}
		}
		check_ID = ID;
	point:
		cout << "\n\n Account Type      : \t 1) Saving Account \t\t 2) Current Account \n\n -->  ";
		std::cin >> type;
		if (type == 1) {
			cout << "\n\n Enter The Deposit From  1000 EGP   :  ";
			std::cin >> deposit;
			while (deposit < 1000) {
				cout << "\n\n Sorry ...   Minimum Deposit  1000 EGP :  ";
				std::cin >> deposit;
			}


			cout << "\n\n Note ))  You Balance Increase By  6% per Month \n";
			++type_1;
		}
		else if (type == 2) {
			cout << "\n Enter The Deposit From  50 EGP  \n\n -->>  ";
			std::cin >> deposit;
			while (deposit < 50) {
				cout << "\n\n Sorry ...   Minimum Deposit  50 EGP :  ";
				std::cin >> deposit;
			}
			--type_1;
		}

		else {
			cout << "\n error .. ))  Choice atleste One Of Account Types \n";
			goto point;
		}
		cout << "\n\n The  Password     :  ";
		for (i = 0; ;) {
			a = _getch();
			if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '1' && a <= '9')
				|| a == '#' || a == '@' || a == '%' || a == '$' || a == '&') {
				password[i] = a;
				++i;
				cout << "*";
			}
			if (a == '\b' && i >= 1) {
				cout << "\b \b";
				--i;
			}
			if (a == '\r') {
				password[i] = '\0';
				break;
			}
		}


		check_pass1 = password;
		cout << "\n\n Confirm Password  :  ";
		for (i = 0; ;) {
			a = _getch();
			if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '1' && a <= '9')
				|| a == '#' || a == '@' || a == '%' || a == '$' || a == '&') {
				password1[i] = a;
				++i;
				cout << "*";
			}
			if (a == '\b' && i >= 1) {
				cout << "\b \b";
				--i;
			}
			if (a == '\r') {
				password1[i] = '\0';
				break;
			}
		}
		check_pass2 = password1;

		cout << "\n\n\n\t Rewrite This Code  [ HRBSLU ] \n\n -->>  ";
		std::cin >> ReCaptcha;
		while (ReCaptcha != "HRBSLU") {
			cout << "\n Wrong .. !\n";
			cout << "\n\n Rewrite This Code  [ HRBSLU ] \n\n -->>  ";
			std::cin >> ReCaptcha;
		}
		cout << "\n\n\t\t I Agree with Ruls (())  ";
		cin.get();
		_getch();
		system("cls");
		cout << "\n\n\twait ...";
		std::this_thread::sleep_for(chrono::seconds(5));

		while (check_pass1 != check_pass2) {
			cout << "\n\n -->  Error ___ ";
			cout << "\n\n The Password is Not Equal ... !";
			_getch();
			system("cls");
			cout << "\n\t\t   </> Creating New Account </>\n";
			cout << "\t\t----------------------------------\n\n";
			cout << "\n Account  [ " << accountNumber << " ]" << endl << endl;
			cout << "\n Enter The Name    :  " << name << endl;
			cout << "\n Enter Your Age    :  " << age << endl;
			cout << "\n The Mobile Phone  :  " << check_phone << endl;
			cout << "\n\n Your Profession   :  " << prof << endl;
			cout << "\n\n Select The Gender : \t 1) Male    2) Femal\n\n -->  " << gender << endl;
			cout << "\n Your National ID  :  " << check_ID << endl;
			cout << "\n\n Account Type      : \t 1) Saving Account \t\t 2) Current Account \n\n -->  " << type << endl;
			cout << "\n\n The  Password     :  ";
			for (i = 0; ;) {
				a = _getch();
				if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '1' && a <= '9')
					|| a == '#' || a == '@' || a == '%' || a == '$' || a == '&') {
					password[i] = a;
					++i;
					cout << "*";
				}
				if (a == '\b' && i >= 1) {
					cout << "\b \b";
					--i;
				}
				if (a == '\r') {
					password[i] = '\0';
					break;
				}
			}
			check_pass1 = password;
			cout << "\n\n Confirm Password  :  ";
			for (i = 0; ;) {
				a = _getch();
				if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '1' && a <= '9')
					|| a == '#' || a == '@' || a == '%' || a == '$' || a == '&') {
					password1[i] = a;
					++i;
					cout << "*";
				}
				if (a == '\b' && i >= 1) {
					cout << "\b \b";
					--i;
				}
				if (a == '\r') {
					password1[i] = '\0';
					break;
				}
			}
			check_pass2 = password1;

			cout << "\n\n\n\t Rewrite This Code  [ HRBSLU ] \n\n -->>  ";
			std::cin >> ReCaptcha;
			while (ReCaptcha != "HRBSLU") {
				cout << "\n Wrong .. !\n";
				cout << "\n\n Rewrite This Code  [ HRBSLU ] \n\n -->>  ";
				std::cin >> ReCaptcha;
			}
			cout << "\n\n\t\t I Agree with Ruls (())  ";
			cin.get();
			_getch();
			system("cls");
			cout << "\n\n\twait ...";
			std::this_thread::sleep_for(chrono::seconds(5));

		}

		cout << "\n\n\a";
		cout << "\t -----------------------------------------------\n";
		cout << "\t *\t       Congratulation  \t\t       *\n\t *\tYour Account Created Successfully      *\n";
		cout << "\t -----------------------------------------------\n";
		cout << "\n\n OK. Thank You >>> ";
	}
	else
		cout << "\n\n\t Sorry ) Your Age Does not allow You to Create an Account ... !\n\n";
	_getch();
	Menue();
}
void Account::Modify()
{
START:
	system("cls");
	cout << "\n Enter The Account Number :  ";
	cin >> number;
	cout << "\n Enter The Password       :  ";
	for (i = 0; ;) {
		a = _getch();
		if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '1' && a <= '9')
			|| a == '#' || a == '@' || a == '%' || a == '$' || a == '&') {
			password2[i] = a;
			++i;
			cout << "*";
		}
		if (a == '\b' && i >= 1) {
			cout << "\b \b";
			--i;
		}
		if (a == '\r') {
			password2[i] = '\0';
			break;
		}
	}
	check_pass3 = password2;
	if (Re_accountNumber() != number) {
		cout << "\n\n wrong ))  this account number is not Exist \n";
		_getch();
		goto START;
	}
	if (check_pass3 != check_pass1) {
		cout << "\n\n Error ))  This Password Is not Correct ...     please try again \n";
		_getch();
		goto START;
	}
	else
	{
		system("cls");
		cout << "\n\t\t   </> Modifying  Account </>\n";
		cout << "\t\t----------------------------------\n\n";
		cout << "\n Account  [ " << accountNumber << " ]" << endl << endl;
		cout << "\n Enter The Name    :  ";
		cin.ignore();
		getline(cin, name);
		cout << "\n\n Select The Gender : \t 1) Male    2) Femal\n\n -->  ";
		std::cin >> gender;
		cout << "\n The Mobile Phone  :  ";
		for (; ; ) {
			a = _getch();
			if (a >= '0' && a <= '9') {
				phone[i] = a;
				++i;
				cout << a;
			}
			if (a == '\b' && i >= 1) {
				cout << "\b \b";
				--i;
			}
			if (a == '\r') {
				phone[i] = '\0';
				break;
			}
		}
		cout << "\n\n Your  Profession  :  ";
		cin.ignore();
		getline(cin, prof);

	point:
		cout << "\n Account Type      : \t 1) Saving Account \t\t 2) Current Account \n\n -->  ";
		std::cin >> type;
		if (type == 1) {
			if (type_1 > 0) {
				cout << "\n\n You Already Use this type \n";
			}
			else {
				if (deposit < 1000) {
					cout << "\n\n To Convert to (( S.Account ))  Minimum Deposit  1000 EGP :  ";
					cout << "\n\n Your Main Balance  :  " << deposit << " EGP" << endl;
					cout << "\n\n You Need To Deposit  >  " << 1000 - deposit << " EGP\n\n --->>  ";
					std::cin >> deposit_1;
					while (deposit_1 + deposit < 1000) {
						cout << "\n\n\t-----------------------------\n";
						cout << "\n\n You Need To Deposit  >  " << 1000 - deposit << " EGP\n\n --->>  ";
						std::cin >> deposit_1;
					}
					cout << "\n\n []  Your Account Type Converted Successfully \n";
					deposit += deposit_1;
				}
				else
					cout << "\n\n []  Your Account Type Converted Successfully \n";
				type_1 = 0;
				++type_1;
			}
		}
		else if (type == 2) {
			if (type_1 < 0) {
				cout << "\n\n You Already Use this type \n";
			}
			else {
				if (deposit < 50) {
					cout << "\n\n To Convert to (( C.Account ))  Minimum Deposit  50 EGP :  ";
					cout << "\n\n Your Main Balance  :  " << deposit << " EGP" << endl;
					cout << "\n\n You Need To Deposit  >  " << 50 - deposit << " EGP\n\n --->>  ";
					std::cin >> deposit_1;
					while (deposit_1 + deposit < 50) {
						cout << "\n\n\t-----------------------------\n";
						cout << "\n\n You Need To Deposit  >  " << 50 - deposit << "\n\n --->>  ";
						std::cin >> deposit_1;
					}
					cout << "\n\n []  Your Account Type Converted Successfully \n";
					deposit += deposit_1;
				}
				else
					cout << "\n\n []  Your Account Type Converted Successfully \n";
				type_1 = 0;
				--type_1;
			}
		}
		else {
			cout << "\n error .. ))  Choice atlest One Of Account Types \n";
			goto point;
		}
		cout << "\n\n\t\t----------------------------\n";
		cout << "\n Enter Old Passsword     :  ";
		for (i = 0; ;) {
			a = _getch();
			if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '1' && a <= '9')
				|| a == '#' || a == '@' || a == '%' || a == '$' || a == '&') {
				password[i] = a;
				++i;
				cout << "*";
			}
			if (a == '\b' && i >= 1) {
				cout << "\b \b";
				--i;
			}
			if (a == '\r') {
				password[i] = '\0';
				break;
			}
		}
		check_pass3 = password;
		while (check_pass1 != check_pass3) {
			cout << "\n\n Error ..)) this password is not Correct \n";
			cout << "\n Enter Old Passsword     :  ";
			for (i = 0; ;) {
				a = _getch();
				if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '1' && a <= '9')
					|| a == '#' || a == '@' || a == '%' || a == '$' || a == '&') {
					password[i] = a;
					++i;
					cout << "*";
				}
				if (a == '\b' && i >= 1) {
					cout << "\b \b";
					--i;
				}
				if (a == '\r') {
					password[i] = '\0';
					break;
				}
			}
			check_pass3 = password;
		}
	A:
		cout << "\n\n\n Enter New Password      :  ";
		for (i = 0; ;) {
			a = _getch();
			if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '1' && a <= '9')
				|| a == '#' || a == '@' || a == '%' || a == '$' || a == '&') {
				password[i] = a;
				++i;
				cout << "*";
			}
			if (a == '\b' && i >= 1) {
				cout << "\b \b";
				--i;
			}
			if (a == '\r') {
				password[i] = '\0';
				break;
			}
		}
		check_pass1 = password;
		cout << "\n\n Confirm New Password    :  ";
		for (i = 0; ;) {
			a = _getch();
			if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '1' && a <= '9')
				|| a == '#' || a == '@' || a == '%' || a == '$' || a == '&') {
				password1[i] = a;
				++i;
				cout << "*";
			}
			if (a == '\b' && i >= 1) {
				cout << "\b \b";
				--i;
			}
			if (a == '\r') {
				password1[i] = '\0';
				break;
			}
		}
		check_pass2 = password1;

		if (check_pass1 != check_pass2) {
			cout << "\n\n -->  Error ___ ";
			cout << "\n\n The Password is Not Equal ... !";
			_getch();
			goto A;
		}
		cout << "\n\n\n\t Rewrite This Code  [ HRBSLU ] \n\n -->>  ";
		std::cin >> ReCaptcha;
		while (ReCaptcha != "HRBSLU") {
			cout << "\n Wrong .. !\n";
			cout << "\n\n Rewrite This Code  [ HRBSLU ] \n\n -->>  ";
			std::cin >> ReCaptcha;
		}
		cout << "\n\n\t\t I Agree with Ruls (())  ";
		_getch();
		system("cls");
		cout << "\n\n\twait ...";
		std::this_thread::sleep_for(chrono::seconds(5));
		cout << "\n\n\a";
		cout << "\t -----------------------------------------------\n";
		cout << "\t *\t       Congratulation  \t\t       *\n\t *\tYour Account Modified Successfully     *\n";
		cout << "\t -----------------------------------------------\n";
		cout << "\n\n OK. Thank You >>> ";
		_getch();
	}
	Menue();
}
void Account::Show()
{
START:
	system("cls");
	cout << "\n Enter The Account Number :  ";
	cin >> number;
	cout << "\n Enter The Password       :  ";
	for (i = 0; ;) {
		a = _getch();
		if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '1' && a <= '9')
			|| a == '#' || a == '@' || a == '%' || a == '$' || a == '&') {
			password2[i] = a;
			++i;
			cout << "*";
		}
		if (a == '\b' && i >= 1) {
			cout << "\b \b";
			--i;
		}
		if (a == '\r') {
			password2[i] = '\0';
			break;
		}
	}
	check_pass3 = password2;
	if (Re_accountNumber() != number) {
		cout << "\n\n wrong ))  this account number is not Exist \n";
		_getch();
		goto START;
	}
	if (check_pass3 != check_pass1) {
		cout << "\n\n Error ))  This Password Is not Correct ...     please try again \n";
		_getch();
		goto START;
	}
	else {
		system("cls");
		cout << "\n\t\t\t (( User Information )) \n";
		cout << "\t\t    ---------------------------------\n\n";
		cout << "\n   Name            :  " << name << endl;
		cout << "\n   Age             :  " << age << endl;
		cout << "\n   National ID     :  " << check_ID << endl;
		if (gender == 1)
			cout << "\n   Gender          :  Male " << endl;
		else if (gender == 2)
			cout << "\n   Gender         :  Femal " << endl;
		else
			cout << "\n   Gender          :  ----- " << endl;
		cout << "\n   Phone Number    :  " << check_phone << endl;
		cout << "\n   Account Number  :  " << accountNumber << endl;
		cout << "\n   The Password    :  " << check_pass1 << endl;
		if (type == 1)
			cout << "\n   Account Type    :  Saving Account" << endl;
		else if (type == 2)
			cout << "\n   Account Type    :  Current Account" << endl;
		cout << "\n   The Profession  :  " << prof << endl;
		cout << "\n   Account Balace  :  " << Re_balance() << " EGP " << endl;
		cout << "\n\n\t\t\t\t\t    Ay.Bank\n";
		cout << "\t\t\t\t\t  ----------\n\n";
		cout << "\n\n --->> ";
	}
	_getch();
	Menue();
}
void Account::Withdrow()
{
START:
	system("cls");
	cout << "\n Enter The Account Number :  ";
	cin >> number;
	cout << "\n Enter The Password       :  ";
	for (i = 0; ;) {
		a = _getch();
		if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '1' && a <= '9')
			|| a == '#' || a == '@' || a == '%' || a == '$' || a == '&') {
			password2[i] = a;
			++i;
			cout << "*";
		}
		if (a == '\b' && i >= 1) {
			cout << "\b \b";
			--i;
		}
		if (a == '\r') {
			password2[i] = '\0';
			break;
		}
	}
	check_pass3 = password2;
	if (Re_accountNumber() != number) {
		cout << "\n\n wrong ))  this account number is not Exist \n";
		_getch();
		goto START;
	}
	if (check_pass3 != check_pass1) {
		cout << "\n\n Error ))  This Password Is not Correct ...     please try again \n";
		_getch();
		goto START;
	}
	else {
		system("cls");
		cout << "\n\n\t welcome back Mr ( " << name << " )" << endl;
		cout << "\n How much money you want Recieve  EGP \n\n -->  ";
		cin >> amount;
		while (amount < 20) {
			cout << "\n\n Error ))  Minimum of Withdrow :  20 EGP \n\n -->  ";
			cin >> amount;
		}
		deposit -= amount;
		cout << "\n  wait ... \n";
		this_thread::sleep_for(chrono::seconds(3));
		cout << "\n\n\a";
		cout << "  Main Balance Now  =   " << deposit << "  EGP " << "\n\n\n";
	}
	cout << "\n\n OK. Thank You >>> ";
	_getch();
	Menue();
}
void Account::Deposit()
{
START:
	system("cls");
	cout << "\n Enter The Account Number :  ";
	cin >> number;
	cout << "\n Enter The Password       :  ";
	for (i = 0; ;) {
		a = _getch();
		if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '1' && a <= '9')
			|| a == '#' || a == '@' || a == '%' || a == '$' || a == '&') {
			password2[i] = a;
			++i;
			cout << "*";
		}
		if (a == '\b' && i >= 1) {
			cout << "\b \b";
			--i;
		}
		if (a == '\r') {
			password2[i] = '\0';
			break;
		}
	}
	check_pass3 = password2;
	if (Re_accountNumber() != number) {
		cout << "\n\n wrong ))  this account number is not Exist \n";
		_getch();
		goto START;
	}
	if (check_pass3 != check_pass1) {
		cout << "\n\n Error ))  This Password Is not Correct ...     please try again \n";
		_getch();
		goto START;
	}
	else
	{
		system("cls");
		cout << "\n\n\t welcome back Mr ( " << name << " )" << endl;
		cout << "\n Enter Your Deposit EGP :  ";
		cin >> amount;
		while (amount < 20) {
			cout << "\n\n Error ))  Minimum Deposit :  20 EGP \n\n -->  ";
			cin >> amount;
		}
		deposit += amount;
		cout << "\n  wait ... \n";
		this_thread::sleep_for(chrono::seconds(3));
		cout << "\n\n\a";
		cout << "  Main Balance Now  =   " << deposit << "  EGP " << "\n\n\n";
	}
	cout << "\n\n OK. Thank You >>> ";
	_getch();
	Menue();
}
int Account::Re_accountNumber() {
	return accountNumber;
}
int Account::Re_balance()
{
	return deposit;
}
void Account::Re_type()
{
START:
	system("cls");
	cout << "\n Enter The Account Number :  ";
	cin >> number;
	cout << "\n Enter The Password       :  ";
	for (i = 0; ;) {
		a = _getch();
		if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '1' && a <= '9')
			|| a == '#' || a == '@' || a == '%' || a == '$' || a == '&') {
			password2[i] = a;
			++i;
			cout << "*";
		}
		if (a == '\b' && i >= 1) {
			cout << "\b \b";
			--i;
		}
		if (a == '\r') {
			password2[i] = '\0';
			break;
		}
	}
	check_pass3 = password2;
	if (Re_accountNumber() != number) {
		cout << "\n\n wrong ))  this account number is not Exist \n";
		_getch();
		goto START;
	}
	if (check_pass3 != check_pass1) {
		cout << "\n\n Error ))  This Password Is not Correct ...     please try again \n";
		_getch();
		goto START;
	}
	else {
		system("cls");
		cout << "\n\n\t welcome back Mr ( " << name << " )" << endl;
		if (type == 1) {
			cout << "\n Account Status ... ? \n\n - Saving Account \n\n - increase by 6% per Month \n";
		}
		else if (type == 2) {
			cout << "\n Account Status ... ? \n\n - Current Account";
		}
	}
	cout << "\n\n ok. Thank You >>> ";
	_getch();
	Menue();
}
void Account::del_account()
{
START:
	system("cls");
	cout << "\n Enter The Account Number :  ";
	cin >> number;
	cout << "\n Enter The Password       :  ";
	for (i = 0; ;) {
		a = _getch();
		if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '1' && a <= '9')
			|| a == '#' || a == '@' || a == '%' || a == '$' || a == '&') {
			password2[i] = a;
			++i;
			cout << "*";
		}
		if (a == '\b' && i >= 1) {
			cout << "\b \b";
			--i;
		}
		if (a == '\r') {
			password2[i] = '\0';
			break;
		}
	}
	check_pass3 = password2;
	if (Re_accountNumber() != number) {
		cout << "\n\n wrong ))  this account number is not Exist \n";
		_getch();
		goto START;
	}
	if (check_pass3 != check_pass1) {
		cout << "\n\n Error ))  This Password Is not Correct ...     please try again \n";
		_getch();
		goto START;
	}
	else
	{
		name = ""; age = 0; password[50] = { '1' }; phone[11] = { '0' }; ID[14] = { '0' }; gender = 0; type = 0; deposit = 0;
	}
	cout << "\n\n wait ... \n";
	this_thread::sleep_for(chrono::seconds(5));
	cout << "\n\n\a";
	cout << "\t -----------------------------------------------\n";
	cout << "\t *\tYour Account Deleted Successfully      *\n";
	cout << "\t -----------------------------------------------\n";
	cout << "\n\n OK. Thank You >>> ";
	_getch();
	Menue();
}
void Account::Menue()
{
	int option, d;
	system("cls");
	cout << "\n\t\t\t\t\t(( Ay.Bank ))\n";
	cout << "\n Choice any Option From [ Meue ] below :\n";
	cout << " ================================================\n\n";
	cout << " 1) Create an Account\n\n";
	cout << " 2) Modify The Account\n\n";
	cout << " 3) Show The Iformation\n\n";
	cout << " 4) Close an Account\n\n";
	cout << " 5) Make a Deposit\n\n";
	cout << " 6) Withdrow Money\n\n";
	cout << " 7) Know Account Type \n\n";
	cout << " 8) Exit\n\n --->>>  ";
	cin >> option;

	switch (option)
	{
	case 1:
		Create();
		break;
	case 2:
		Modify();
		break;
	case 3:
		Show();
		break;
	case 4:
		del_account();
		break;
	case 5:
		Deposit();
		break;
	case 6:
		Withdrow();
		break;
	case 7:
		Re_type();
		break;
	case 8:
		system("cls");
		cout << "\n /* \n\n  Thank you for dealing with [ Ay.Bank ]\n\n */ ";
		_getch();
		break;
	default:
		cout << "\n\n Not Founded Option .. !\n\n";
		_getch();
		Menue();
	}
}

int main()
{
	Account Member;

	Member.Menue();

	cout << "\n\n\n\a";
	return 0;
}