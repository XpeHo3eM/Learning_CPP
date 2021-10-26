#include <iostream>

#include <cpr/cpr.h>



int main ()
{
    cpr::Response r = cpr::Get (cpr::Url ("http://httpbin.org/html"));
       
    size_t h1 = r.text.find ("<h1>") + 4;
    size_t h1end = r.text.find ("</h1>");
    std::cout << r.text.substr (h1, h1end - h1) << std::endl;
}