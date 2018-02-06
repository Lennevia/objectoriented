// Implement a value-semantic string class. Your class should support the following syntaxes:
# include <iostream>
# include <cstring>

// We only really care about strlen, strncpy, and
class String
{
public:
    
  
        Box(int width, int length, int height)
        : m_width(width), m_length(length), m_height(height) // member init list
        
        
    // Default construct: string s;
    String()
    {
        len = 1; // make room for a null pointer
        str = new char[len];
        str[len - 1] = '\0'; // assign null char
    }
    
    
    // Construct and assign from a literal value: string s1 = "hello";
    //                                            s1 = "foo";
    
        // Implicit constructor call to initialize new object with C string
    String(const char *input)
    {
        nlength = strlen(input)+1 ;
        nstring = new char[nlength];
        for(int i = 0; i < (nlength - 1); i++)
        {
            nstring[i] = input[i];
        }
        nstring[(nlength-1)] = NULL;
    }
    
    // Copy construct and assign
    // string s2 = s1;
    // s2 = s1; // s2 == s1
    
    // Compare
    // s1 == s1;
    
    // Order: lexicographical comparison
   // s1 < s1;
    template <class InputIterator1, class InputIterator2>
    bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
                                  InputIterator2 first2, InputIterator2 last2)
    {
        while (first1!=last1)
        {
            if (first2==last2 || *first2<*first1) return false;
            else if (*first1<*first2) return true;
            ++first1; ++first2;
        }
        return (first2!=last2);
    }
    
    // Object independence
    //s2 = "bar"; // Does not change the value of s1

    
    string(const char* s)
    : len(std::strlen(s)), str(new char[len]) // this will not compile
    {
        std:: strcpy(str, s, len);
    }
    
    string(const string& s)
    : str(s.str), len(s.len)
    {}
    
private:
    int len;
    char* str;
    
}




// There's a things called Sharing that is very bad for the string
// If you delete a string of objects, must use delete[] in order to get rid of
// every piece of memory allocated along with returning the pointer to memory
