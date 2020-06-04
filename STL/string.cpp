#include <iostream>
#include <algorithm>
#include <string> // std::basic_string<>


int main()
{
    std::string str = "Something else";
    std::string sstr;

    /* Assign */
    sstr.assign(4,'='); // second argument only char type ('')
    std::cout << sstr << '\n';
    sstr.assign({'C','-','s','t','y','l','e'});
    std::cout << sstr << '\n';
    sstr.assign(str);
    std::cout << sstr << '\n';

    /* at() */
    std::cout << "result at(): " << sstr.at(0) << '\n';

    /* operator[ ] */
    std::cout << "result sstr[3]: " << sstr[3] << '\n';
    
    /* front() - return first character in std::string */
    std::cout << "result front(): " << sstr.front() << '\n';

    /* back() - return last character in std::string */
    std::cout << "result back(): "<< sstr.back() << '\n';

    /* data() - return pointer in first element std::string type object  */
    const char* ch = sstr.data();
    std::cout << ch << '\n';

    sstr.assign("New something");
    /* c_str() - return pointer in const char* */
    const char* ch1 = sstr.c_str();
    std::cout << ch1 << '\n';

    std::boolalpha(std::cout);
    /* check, if std::string type value empty return true, otherwise - return false */
    std::cout << sstr.empty() << '\n';

    sstr.erase(); // similary clear()
    sstr.clear(); // clear variable std::string type
    std::cout << sstr.empty() << '\n';

    sstr = "New something else";
    std::cout << "length sstr: " << sstr.length() << '\n';
    std::cout << "size sstr: " << sstr.size() << '\n';

    /* work with iterators std::string, similary size(), length() */
    std::cout << "std::distance sstr: " << std::distance(sstr.begin(),sstr.end()) << '\n';

    str.erase();
    /* reserve() - allocate memory for variable */
    str.reserve(10);
    /* capacity() - return numbers of byte allocated memory for variable */
    std::cout << "str capacity before reserve(): "<< str.capacity() << '\n';
    str = "Something else";

    /* shrink_to_fit remove unused capacity */
    std::cout << "sstr capacity after shrink_to_fir(): " << sstr.capacity() << " and size: " << sstr.size() << '\n';
    sstr.shrink_to_fit();
    std::cout << "sstr capacity before shrink_to_fir(): " << sstr.capacity() << " and size: " << sstr.size() << " "+sstr <<'\n';
    
    /* insert character std::string type in position */
    sstr.insert(2,"v"); // insert "v" in 2 position
    std::cout << sstr << '\n';

    /* replace character on this in position */
    sstr.replace(2, 1, "w"); // replace character on position 2, 1 - size replacement substring
    std::cout << sstr << '\n';

    std::cout << "str: " << str << " sstr: " << sstr << '\n';
    /* compare() - return result difference of size  */
    int result = str.compare(sstr);
    std::cout << "result compare(): " << result << '\n';

    /* append() insert to end of string this characters */
    std::cout <<"result append(): "<< str.append(sstr) << '\n';
    std::cout <<"result append(): "<< str.append(3,'*') << '\n';

    /* remove last character from string */
    str.pop_back();
    std::cout <<"result pop_back(): "<< str << '\n';

    /* insert in end of string character */
    str.push_back('*');
    std::cout <<"result push_back('*'): "<< str << '\n';

    // return string in pos to end str.size() == 36, pos(33->36) == "***"
    std::string substr = str.substr(33);
    std::cout << substr << '\n';

    substr = str.substr(14,4); // return 4 string characters starting in position 14
    std::cout << substr << '\n';

    int pos = str.find("Neww"); // return substring position on this string
    std::cout << "Pos 'Neww': " << pos << '\n';

    pos = str.rfind("Neww");
    std::cout << "Pos 'Neww' of end: " << pos << '\n'; // return character position of end

    std::string inum = "45";
    std::string fnum = "3.14";

    int ival = std::stoi(inum);
    float fval = std::stof(fnum);
    std::cout << ival << " " << fval << '\n';
    
    std::string flval;
    flval = std::to_string(3.6f);
    std::cout << flval << '\n';

    return 0;
}
