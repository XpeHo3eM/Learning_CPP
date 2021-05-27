/*
* Напишите программу «Регистратура».
* На вход программе приходят строки с фамилиями или строка Next. 
* Пришедшие люди становятся в очередь.
* По запросу Next необходимо вызвать в регистратуру человека с фамилией, 
* идущей первой в лексикографическом порядке (по алфавиту), 
* и вывести его фамилию на экран. Фамилии пациентов могут повторяться.
* Каждый запрос (на добавление и вывод) должен работать за O(logn).
*/

#include <iostream>
#include <map>
#include <string>



bool isOnlyLetter(std::string &str)
{
  for (int i = 0; i < str.size (); ++i)
    if ((str[i] < 'a' || str[i] > 'z') &&
        (str[i] < 'A' || str[i] > 'Z'))
      return false;
  return true;
}



int main()
{
  std::map <std::string, int> queue;
  while (true)
  {
    std::cout << "Enter last name or command \"Next\": ";
    std::string answer;
    do
      std::getline (std::cin, answer);
    while (!isOnlyLetter (answer));

    system("cls");

    if (answer == "Next")
    {
      std::map <std::string, int>::iterator itq = queue.begin();
      if (itq != queue.end())
      {
        std::cout << "Calling: " << itq->first << std::endl;
        if (itq->second > 1)
          --itq->second;
        else
          queue.erase(itq);
      }
      else
        std::cout << "Queue is empty" << std::endl;
    }
    else
    {
      std::map <std::string, int>::iterator itf = queue.find(answer);
      if (itf == queue.end())
        queue.insert (std::pair <std::string, int> (answer, 1));
      else
        ++itf->second;
      std::cout << "Added " << answer << " on queue" << std::endl;
    }
  }
}