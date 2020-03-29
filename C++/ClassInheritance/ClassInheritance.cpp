#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Person
{
	std::string name;
	int age = 0;
	std::string Sex;
public:
	Person(const char Name[], int Age, const char sex[]);
	void DisplayPersonInfo();
};

class Man : public Person
{
	std::string Job;

public:
	Man(const char Name[], int Age, const char sex[], const char job[]);
	void Displayinfo();
};



int main(void)
{
	Man Man1("KyuHyoung", 27, "Male", "Programmer");

	Man1.Displayinfo();

	return 0;
}



Person::Person(const char Name[], int Age, const char sex[])
{
	name = Name;
	if (!(strcmp(sex, "Male") && strcmp(sex, "Female")))
		Sex = sex;
	else
		Sex = "None";
	age = Age;
}

Man ::Man(const char Name[], int Age, const char sex[], const char job[]): Person(Name, Age, sex)
{
	Job = job;
}

void Person::DisplayPersonInfo()
{
	std::cout << "Name : " << name << std::endl << "Age : " << age << std::endl << "Sex : " << Sex << std::endl;
}

void Man :: Displayinfo()
{
	DisplayPersonInfo();
	std::cout << "Job : " << Job << std::endl;
}