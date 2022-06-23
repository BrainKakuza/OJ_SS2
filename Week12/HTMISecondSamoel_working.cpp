/*
Description

All HTML elements can have attributes

Attributes provide additional information about elements

Attributes are always specified in the start tag

Attributes usually come in name/value pairs like: name="value"

The <a> tag defines a hyperlink. The href attribute specifies the URL of the page the link goes to:

<a href="https://www.w3schools.com">Visit W3Schools</a>

Please design a class named HTMLElementWithAttributes, who inheritance the class HTMLElement

There will be one data member inside HTMLElementWithAttributes, attributes in map<string, string> type.

The key of map represent attributes name and value represent attributes value.

The class HTMLElementWithAttributes should content only one constructor as definition below

HTMLElementWithAttributes(string );

It will using the given string to construct the object, separate the tagName, 
content and attributes and set the member appropriately.

Please design a function getAttritubes to get all the keys in attributes

list<string>getAttritubes();

Please override operator[] and return the correspond value

string operator[](string key);



All HTML can have attributes

Attributes provide additional information to an element

Attributes are placed in the start tag

Attributes usually come in name/value pairs, such as name="value"

The <a> tag is used to define the hyperlink. In the <a> tag, we can use the href attribute to define the purpose of the hyperlink, as follows

<a href="https://www.w3schools.com">Visit W3Schools</a>

Please design a class HTMLElementWithAttributes that inherits the HTMLElement class

Add a data member attributes to HTMLElementWithAttributes, the type of this member is map<string, string>

The key of map represents the name of the property, and vlaue represents the value of the property

There must be only one constructor in the HTMLElementAttributes category, as defined below

HTMLElementAttributes(string );

The constructor will use the incoming string to construct an HTMLElement object, it will split tagName, content and attributes, and set the data member of the object

Please design a function getAttributes, this function will return all the key values ​​in attributes

Please use the overload operator [] to return the value corresponding to the key, which is defined as follows

string operator[](string key);

NOTE: a string may have several attributes


Input
a string

Output
first line is tagname

the others are attributes' value.

Sample Input 1 
<a href="https://www.w3schools.com">Visit W3Schools</a>

Sample Output 1
a
https://www.w3schools.com
*/

#include<iostream>
#include<list>
#include<map>

using namespace std;

class HTMLElementWithAttributes : public HTMLElement
{
public:
    HTMLElementWithAttributes(string str): HTMLElement(str)
    {
        string key;
        string value;
        bool valueEnd = false;
        bool quotation = false;

        for(int i = 1 + tagName.size(); str[i] != '>'; i++)
        {
            if(str[i] != '=' && !quotation)
            {
                key += str[i];
            }

            if(str[i] == '"' && !quotation)
            {
                quotation = true;
                continue;
            }

            if(str[i] != '"' && quotation && !valueEnd)
            {
                value += str[i];
            }

            if(str[i] == '"' && quotation)
            {
                valueEnd = true;
            }

            if(quotation && valueEnd)
            {
                attributes.insert({key , value});
                key = "";
                value = "";
                valueEnd = false;
                quotation = false;
            }  
        }
    }

    list<string> getAttributes() const
    {
        list<string> l = {};

        for(auto x: attributes)
        {
            l.push_back(x.first);
        }

        return l;
    }

    string operator [] (string key)
    {
        return attributes[key];
    }
private:
	map<string, string> attributes;
};
int main() {
  std::string str;
  getline(std::cin,str);
  HTMLElementWithAttributes html(str);
  std::cout << html.getTagName() << endl ;
  std::list<std::string> key = html.getAttributes();
  for(std::string k : key)
    std::cout<<html[k]<<std::endl;
  return 0;
}
