C++11 introduces uniform initialization (Braced initialization)

Ex: 1
std::vector<int> v{ 1, 3, 5 }; // v's initial content is 1, 3, 5

Ex: 2
class w{
    int i{ 0 };   // fine
    int j =10;    // fine
    int k(20);    // error!
};

Ex: 3
On the other hand, uncopyable objects (e.g., std::atomic s—see Item 40 ) may be initialized using braces or parentheses, 
but not using “ = ”: 
std::atomic<int> ai1{ 0 };     // fine 
std::atomic<int> ai2(0);       // fine 
std::atomic<int> ai3 = 0;      // error! 

Ex: 4
double x, y, z;
… 
int sum1{ x + y + z };       // error! sum of doubles may not be expressible as int 
Initialization using parentheses and “ = ” doesn’t check for narrowing conversions, 
because that could break too much legacy code: 
int sum2(x + y + z);         // okay (value of expression truncated to an int) 
int sum3 = x + y + z;        // ditto
