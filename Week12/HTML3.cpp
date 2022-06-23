#include <iostream>
#include <list>
#include <map>

// using namespace std;

class HTMLElement
{
private:
    std::string tagName;
    std::string content;

public:
    HTMLElement(std::string str)
    {
        int length = str.length();
        bool choice = true;

        for (int i = 1; i < length; i++)
        {
            if (choice)
            {
                tagName.push_back(str[i]);

                if (str[i + 1] == '>')
                {
                    i++;
                    choice = false;
                }
            }
            else
            {
                content.push_back(str[i]);

                if (str[i + 1] == '<')
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

class HTMLElementWithAttributes : private HTMLElement
{
private:
    std::map<std::string, std::string> type;

public:
    HTMLElementWithAttributes(std::string str) : HTMLElement(str)
    {
        int lenght = str.length();
        int start = 0;
        int end = lenght - 2;

        //std::cout << lenght << std::endl;

        /************ In the first part I try to trim the input into this kind of form*******************/
        /*
            <a href="https://www.w3schools.com">Visit W3Schools</a> ---------> href="https://www.w3schools.com"
            <a href="https://www.w3schools.com" href1="https://school">Visit W3Schools</a> ---------> href="https://www.w3schools.com" href1="https://school"
        */
        while (str[start] != ' ')
        {
            start++;
        }

        start++;

        while (1)
        {
            if (str[end] == '>')
            {
                break;
            }

            end--;
        }

        end = end - start;

        // std::cout << start << std::endl;
        // std::cout << end << std::endl;

        std::string data = str.substr(start, end);

        //std::cout << data << std::endl;

        std::string newData = removeSpaces(data);

        /* This just to trim the data we by removing the space not included the string in " "
            href="https://www.w3schools.com" href1="https://school" ------> href="https://www.w3schools.com"href1="https://school"
             href="https://www. w3schools.com" href1="h ttps://school" ------> href="https://www. w3schools.com"href1="h ttps://school"
        */

        //std::cout << newData << std::endl;

        lenght = newData.length();
        bool switching = true;
        std::string key;
        std::string attribute;

        //This map is for if there is two key that has the same name
        std::map<std::string, int> numbers;

        /*
            This loop down there is to seperate key and attribute 
        */

        for (int i = 0; i < lenght; i++)
        {
            if (switching)
            {
                if (newData[i] == '=')
                {
                    i++;
                    switching = false;
                }
                else
                {
                    key.push_back(newData[i]);
                }
            }
            else
            {
                if (newData[i] == '"')
                {
                    switching = true;
                    bool same = false;

                    //This if else is to check if the key was previosly declare in the map or not
                    if (numbers.find(key) == numbers.end())
                    {
                        //If this key haven't store in the map before the number is zero to indicate that there's still one number
                        numbers[key] = 0;
                    }
                    else
                    {
                        //In case if there is another key with the same name
                        for (std::map<std::string, int>::iterator itr = numbers.begin(); itr != numbers.end(); itr++)
                        {
                            if (itr->first == key)
                            {
                                //Add number to indicate that there's more than one key and use it to modified the name
                                // we have href , href ---------> href , href1
                                numbers[key]++;
                                key.push_back(numbers[key]);
                            }
                        }
                    }

                    //add both of them in the map
                    type[key] = attribute;

                    // std::cout << key << std::endl;
                    // std::cout << attribute << std::endl;

                    //Reset in case there more than one attribute 
                    key = "";
                    attribute = "";
                }
                else
                {
                    attribute.push_back(newData[i]);
                }
            }
        }

       
    }

    std::string removeSpaces(std::string str)
    {
        // To keep track of non-space character count
        int count = 0;
        int length = str.length();
        std::string newStr(length , ' ');
        // Traverse the given string. If current character
        // is not space, then place it at index 'count++'
        for (int i = 0; i < length; i++)
        {
            if (str[i] != ' ' && str[i] != '"')
            {
                newStr[count++] = str[i]; // here count is                   
                                      // incremented
            }
            else if (str[i] == '"')
            {
                while (1)
                {
                    newStr[count++] = str[i];
                    i++;

                    if (str[i] == '"')
                    {
                        newStr[count++] = str[i];
                        break;
                    }
                }
            }
        }

        newStr[count] = '\0';

        std::cout << newStr << std::endl;

        return newStr;
    }

    std::list<std::string> getAttributes()
    {
        std::list<std::string> List;

        for (std::map<std::string, std::string>::iterator itr = type.begin(); itr != type.end(); itr++)
        {
            List.push_back(itr->first);
        }

        return List;
    }

    std::string operator[](std::string key)
    {
        return type[key];
    }

    std::string getTagName()
    {
        std::string tagName = HTMLElement::getTagName();
        int lenght = tagName.length();
        std::string returnTagName;

        for (int i = 0; i < lenght; i++)
        {
            if (tagName[i] == ' ')
            {
                break;
            }
            else
            {
                returnTagName.push_back(tagName[i]);
            }
        }

        return returnTagName;
    }

    std::string getContent()
    {
        return HTMLElement::getContent();
    }
};
int main()
{
    std::string str;
    getline(std::cin, str);
    HTMLElementWithAttributes html(str);
    std::cout << html.getTagName() << std::endl;
    std::cout << html.getContent() << std::endl;
    std::list<std::string> key = html.getAttributes();
    for (std::string k : key)
        std::cout << html[k] << std::endl;
    return 0;
}