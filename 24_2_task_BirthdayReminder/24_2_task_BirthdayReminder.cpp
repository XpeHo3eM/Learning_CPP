#include <iostream>
#include <ctime>
#include <string>
#include <iomanip>
#include <vector>


struct PersonBirthday
{
  std::string name;
  std::tm date;
};


void enterBirthday  (std::string &);
void printBirthdays (std::vector<PersonBirthday> &);
int  convertToDays  (std::tm &);

std::vector <PersonBirthday> birthdaysCalendar;



int main()
{
  std::string name;
  do
  {
    system ("cls");
    std::cout << "Enter name: ";
    std::cin >> name;
    if (name != "end") 
      enterBirthday (name);
  }
  while (name != "end");
  
  system ("cls");
  std::time_t time = std::time (nullptr);
  std::tm local = *std::localtime (&time);
  std::vector <PersonBirthday> nearestBirthdays;
  std::vector <PersonBirthday> todayBirthdays;
  int minCountDays = 366;
  int currentDays = convertToDays (local);
  for (auto i : birthdaysCalendar)
  {
    if (i.date.tm_year >= local.tm_year)
    {
      int difDays = convertToDays(i.date) - currentDays;
      if (difDays == 0)
        todayBirthdays.push_back (i);
      else
        if (difDays > 0 && difDays <= minCountDays)
        {
          if (difDays < minCountDays)
          {
            nearestBirthdays.clear ();
            minCountDays = difDays;
          }
          nearestBirthdays.push_back (i);
        }       
    }
  }

  if (!todayBirthdays.empty ())
  {
    std::cout << "~ Today birthdays ~" << std::endl;
    printBirthdays (todayBirthdays);
    std::cout << std::endl;
  }

  if (!nearestBirthdays.empty ())
  {
    std::cout << "~ Nearest birthdays ~" << std::endl;
    printBirthdays (nearestBirthdays);
  }
}



int convertToDays (std::tm &tm)
{
  int totalDays {0};
  int day = tm.tm_mday;
  int mon = tm.tm_mon;
  int year = tm.tm_year;

  for (int i = 0; i < mon; ++i)
    if (i == 3 || i == 5 || i == 8 || i == 10)
      totalDays += 30;
    else
      if (i == 2)
        if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
          totalDays += 29;
        else
          totalDays += 28;
      else
        totalDays += 31;
  totalDays += day;

  return totalDays;
}



void printBirthdays (std::vector<PersonBirthday> &vec)
{
  for (auto i : vec)
    std::cout << i.name << " " << std::put_time (&i.date, "%m/%d") << std::endl;
}



void enterBirthday (std::string &name)
{
  PersonBirthday person;
  std::time_t time = std::time (nullptr);
  std::tm local = *std::localtime (&time);
  person.date = local;

  person.name = name;
  std::cout << "Enter birthday on format YYYY/MM/DD: ";
  std::cin >> std::get_time (&person.date, "%Y/%m/%d");

  birthdaysCalendar.push_back (person);
}