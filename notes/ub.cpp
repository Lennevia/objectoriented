// UNDEFINED BEHAVIOR: we're not sure which value will print
// at the point of creation of x, the variable is undeterministic
int x;
if(x < 0)
    cout << 1 << '\n';
else
    cout << 2 << '\n';


