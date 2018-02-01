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
