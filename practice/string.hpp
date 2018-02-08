// Implement a value-semantic string class.

#pragma once // lets declare this header file just once

// We only really care about strlen, strncpy, and
class String
{
public:
    // Default construct: string s;
    String();
   
    // Construct and assign from a literal value: string s1 = "hello";
    //                                            s1 = "foo";
    String(const char *input);

    // Copy construct and assign
    // string s2 = s1;
    // s2 = s1; // s2 == s1
    String(const String& s);
    
    
    // If you write:
    //    c1 = c2;
    // "this" is a pointer to c1.
//    String& operator=(const String& s);

    
    // Compare
    // s1 == s1;
    String operator==(String a, String b);
    

    
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



inline bool
operator==(String a, String b) {
    
    
    return a.get_rank() == b.get_rank() &&
    a.get_suit() == b.get_suit();
}






// There's a things called Sharing that is very bad for the string
// If you delete a string of objects, must use delete[] in order to get rid of
// every piece of memory allocated along with returning the pointer to memory
