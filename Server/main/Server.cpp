#include <iostream>

#include "ManageUser.h"
#include "User.h"

using namespace std;

int main() {

	User* user = new User();
	(*user).setName("Reza");
	//user->setAge(33);
	//
	//string name = (*user).getName();

	//int age = user->getAge();
	//
	//cout << name << age << endl;
		
	delete user;
	
	//ManageUser newUser;
	//newUser.insert(user);

	//ManageUser::users;

	//for (auto &user : ManageUser::users) {
	//	cout << user.getAddress() << endl;
	//}


	cout << "TESwwwwT" << endl;

	return 0;
}
