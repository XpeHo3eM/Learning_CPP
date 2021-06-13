#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <iomanip>


#define BEGIN  "begin"
#define END    "end"
#define STATUS "status"
#define EXIT   "exit"


bool isCorrectCommand (const std::string*, std::string&);
void endTask (std::string&, const std::string&, std::time_t);
std::string spentTime (std::time_t);


int main ()
{
  std::string actions[] {BEGIN, END, STATUS, EXIT};
  std::string taskName {""};
  std::string action;
  bool activeTask = false;
  std::time_t startTime = std::time (nullptr);
  std::string fileName {"allTasks.txt"};
  std::ofstream file (fileName);

  do
  {
    std::cout << "~ Enter one of command below: ~" << std::endl;
    std::cout << "\t 1. \"" << BEGIN  << "\" (for start new task);" << std::endl;
    std::cout << "\t 2. \"" << END    << "\" (for finish task);" << std::endl;
    std::cout << "\t 3. \"" << STATUS << "\" (show all finished task);" << std::endl;
    std::cout << "\t 4. \"" << EXIT   << "\" (exit from program)." << std::endl;
    do
      std::cin >> action;
    while (!isCorrectCommand(actions, action));
    
    if (action == BEGIN)
    {
      system ("cls");
      if (activeTask)
      {
        endTask (fileName, taskName, startTime);
        activeTask = false;
      }
      
      std::cout << "Enter task's name: ";
      std::cin >> taskName;
      startTime = time (nullptr);
      activeTask = true;
      system ("cls");
      std::cout << "~ Task \"" << taskName << "\" was started ~" << std::endl << std::endl;
    }
    else
      if (action == END)
      {
        endTask (fileName, taskName, startTime);
        activeTask = false;
      }
      else
        if (action == STATUS)
        {
          system ("cls");
          if (activeTask)
          {
            std::cout << "~ Active task ~" << std::endl;
            std::cout.width (20);
            std::cout << taskName << std::endl;
          }
          std::cout << "~ All finished tasks ~" << std::endl;
          std::ifstream file (fileName);
          std::time_t st;
          while (file >> taskName >> st)
          {
            std::cout.width (20);
            std::cout << taskName << ' ' << spentTime(st) << std::endl;
          }
          std::cout << std::endl << std::endl;
        }
  }
  while (action != actions[3]);
}



std::string spentTime (std::time_t time)
{
  int hour {0};
  int min  {0}; 
  int sec  {0};

  min = time / 60;
  if (min >= 60)
  {
    hour = min / 60;
    min %= 60;
  }
  sec = time % 60;

  std::string spTime = std::to_string(hour) + "h:" +
                       std::to_string(min)  + "m:" +
                       std::to_string(sec)  + "s.";

  return spTime;
}



void endTask (std::string &fileName, const std::string &taskName, std::time_t startTime)
{
  system ("cls");
  std::time_t spentTime = std::time (nullptr) - startTime;
  std::ofstream file (fileName, std::ios::app);
  file.width (20);
  file << taskName << ' ' << spentTime << std::endl;
  file.close ();
  std::cout << "~ Task \"" << taskName << "\" was closed ~" << std::endl << std::endl;
}



bool isCorrectCommand(const std::string *actions, std::string &str) 
{
  for (int i = 0; i < str.size (); ++i)
    str[i] = std::tolower (str[i]);

  for (int i = 0; i < actions->size(); ++i)
    if (str == actions[i]) 
      return true;
  return false;
}

