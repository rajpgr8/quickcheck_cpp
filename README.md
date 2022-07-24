### quickcheck_cpp14
examples mentioned in thise repo are not mine and they are taken from mutiples sources for refrence purpose.

Q: How to search an element in the list/vector and in the map.    
std::find(arr.begin(), arr.end(), 3)  vs   
m.find(3)  
```
Serach/ Find element in a vector/list   (use std 'find' method)
    if (std::find(arr.begin(), arr.end(), 3) != arr.end()) {  
        std::cout << "foud element in the vector";  
    }  else {
        arr.push_back(3);  //insert if not found
    }
```
```
Serach/ Find element in a map/unordered_map  (use class 'find' method)
    if (m.find(3) != arr.end()) {  
        std::cout << "foud element in the map";  
    }  {
        m[3] = "value";  //insert if npt found
    }
```
