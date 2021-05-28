#include <iostream>
#include <map>
#include <string>


std::string enterWord ();
void decomposeWordToCharacters(std::string&, std::map<char, int>&);


int main()
{
  std::cout << "Enter first word: ";
  std::string word1 = enterWord ();
  std::cout << "Enter second word: ";
  std::string word2 = enterWord ();

  if (word1.size() == word2.size())
  {
    std::map <char, int> firstWordCharacters;
    std::map <char, int> secondWordCharacters;
    decomposeWordToCharacters (word1, firstWordCharacters );
    decomposeWordToCharacters (word2, secondWordCharacters);

    std::map <char, int>::iterator itw1 =  firstWordCharacters.begin();
    std::map <char, int>::iterator itw2 = secondWordCharacters.begin();

    bool mistmatch = false;
    while (!mistmatch && itw1 != firstWordCharacters.end())
    {
      if (itw1->first == itw2->first &&
          itw1->second == itw2->second)
      {
        ++itw1;
        ++itw2;
      }
      else
        mistmatch = true;
    }

    if (!mistmatch)
      std::cout << "~ This word are anagramm ~" << std::endl;
    else
      std::cout << "~ This word are not anagramm ~" << std::endl;
  }
  else
    std::cout << "~ This words are not anagramm ~" << std::endl;
}



void decomposeWordToCharacters(std::string &str, std::map<char, int> &wMap)
{
  std::map <char, int>::iterator itf;
  for (int i = 0; i < str.size(); ++i)
  {
    itf = wMap.find(str[i]);
    if (itf == wMap.end())
      wMap.insert(std::pair<char, int> (str[i], 1));
    else
      ++itf->second;
  }
}



std::string enterWord ()
{
  std::string str;
  std::cin >> str;
  return str;
}