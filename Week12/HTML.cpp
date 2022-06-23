/*
Description

HTML stands for Hyper Text Markup Language

HTML is the standard markup language for creating Web pages

HTML describes the structure of a Web page

HTML consists of a series of elements

HTML elements tell the browser how to display the content

The HTML element is everything from the start tag to the end tag:

<tagname>Content goes here...</tagname>

Please design  a class HTMLElement to represent an element of HTML

There will be two data member inside HTMLElement, tagName and content, both of them are string type.

The class HTMLElement should content only one constructor as definition below

HTMLElement(string );

It will using the given string to construct the object, separate the tagName and content and set the member appropriately.

HTML is a so-called hypertext markup language

HTML is a standard markup language for building web pages

HTML is the main structure used to describe a web page

HTML is made up of a series of elements

HTML browsers construct and render web pages to users based on the elements provided by HTML

An HTML element is from the opening tag to the closing tag, like this:

<tagname>Content goes here...</tagname>

Please design a class HTMLElement to represent an element in HTML

There should be two data members in HTMLElement, tagName and content, both of them are of string type

There must be only one constructor in the HTMLElement class, as defined below

HTMLElement(string );

The constructor will use the incoming string to construct an HTMLElement object, it will split the tagName and content, and set the object's data member

Input
NONE

Output
NONE

Sample Input 1 
NONE

Sample Output 1
NONE
*/

#include <iostream>

using namespace std;

class HTMLElement
{
private:
  string tagName , content;
public:
  HTMLElement(string str)
  {
    bool change = true;

    for(int i = 1; i < str.length(); i++)
    {
      if(change)
      {
        tagName.push_back(str[i]);

        if(str[i + 1] == '>')
        {
          i++;
          change = false;
        }
      }else
      {
        content.push_back(str[i]);

        if(str[i + 1] == '<')
        {
          break;
        }
      }
    }
  }

  std::string getTagName()
  {
    return tagName;
  }
  std::string getContent()
  {
    return content;
  }
};
int main() {
  std::string str;
  getline(std::cin,str);
  HTMLElement html(str);
  std::cout<<html.getTagName()<<std::endl;
  std::cout<<html.getContent()<<std::endl;
  return 0;
}
