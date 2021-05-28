#include <iostream>
#include <map>
#include <string>


std::string enterWord ();
std::map<char, int> decomposeWordToMap(std::string&);


int main()
{
  std::cout << "Enter first word: ";
  std::string word1 = enterWord ();
  std::cout << "Enter second word: ";
  std::string word2 = enterWord ();

  if (word1.size() == word2.size())
  {
    std::map <char, int> firstWordCharacters  = decomposeWordToMap (word1);
    std::map <char, int> secondWordCharacters = decomposeWordToMap (word2);

    if (firstWordCharacters == secondWordCharacters)
      std::cout << "~ This word are anagramm ~" << std::endl;
    else
      std::cout << "~ This word are not anagramm ~" << std::endl;
  }
  else
    std::cout << "~ This words are not anagramm ~" << std::endl;
}



std::map <char, int> decomposeWordToMap(std::string &str)
{
  std::map <char, int> mapTmp;
  for (const char ch : str)
    mapTmp[ch] += 1;

  return mapTmp;
}



std::string enterWord ()
{
  std::string str;
  std::cin >> str;
  return str;
}