// Implement a value-semantic string class. Your class should support the following syntaxes:

// Move construction and assignment (optional)
string s3 = std::move(s2);
s3 = std::move(s1);

// Default construct
string s0;

// Construct and assign from a literal value
string s1 = "hello";
s1 = "foo";

// Copy construct and assign
string s2 = s1;
s2 = s1; // s2 == s1

// Compare
s1 == s1;

// Order
s1 < s1; // lexicographical comparison

// Object independence
s2 = "bar"; // Does not change the value of s1


// We only really care about strlen, strncpy, and
//
// There's a things called Sharing that is very bad for the string
// If you delete a string of objects, must use delete[] in order to get rid of
// every piece of memory allocated along with returning the pointer to memory
class string
{
public:
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
