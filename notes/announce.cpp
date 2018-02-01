// This is an assignment: Implement a value-semantic string class, should
// support the following stuff
// Turn on address sanitizer
// Test these things, see if you leave memory

// There are three variations:
// 1. Copy on writing (C.O.W.):
// 2. Immutable string: remove ability to modify string
//  1) Sharing method
//  2) Interning
// 3. Small string optimization (S.S.O.) **This one is very difficult**







//Construct from a literal value
int x1 =0;
string s1 = "hello";

//Copy construct and assign
int x2 = x1;
string s2 = s1;
x2 = x1;
s2 = s1;

// Move construction and assignment (optional)
string s3 =


//Compare
x1 == x1;
s1 == s1;

//Order
x1 < x1;
s1 < s1; // Lexicographical comparison

//Object independence
x2 = "5"; //


