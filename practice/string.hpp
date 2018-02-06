// Implement a value-semantic string class. Your class should support the following syntaxes:


// We only really care about strlen, strncpy, and
class String
{
public:
    // Default construct: string s;
    String(const char* s)
    
    
    // Construct and assign from a literal value: string s1 = "hello";
    //                                            s1 = "foo";
    
    // Copy construct and assign
    // string s2 = s1;
    // s2 = s1; // s2 == s1
    
    // Compare
    // s1 == s1;
    
    // Order: lexicographical comparison
   // s1 < s1;
    
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
