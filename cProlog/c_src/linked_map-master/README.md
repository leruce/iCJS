linked_map
==========

An STL-compatible, efficient map aggregate container preserving the insertion order of associated key/value pairs.  Functionally equivalent to Java's LinkedHashMap or Python's OrderedDict.

Warning!
--------
This software has not yet been thoroughly tested. Please refer to the GNU General Public License, version 3, section 16 titled _Limitation of Liability_.  The license can be found in the file _README.md_ distributed with this code.

Requirements
------------
Requires a C++11 compliant compilation environment.  GCC 4.9+ or Clang 3.3+ with libc++ recommended.

Usage
-----
Include the header file.

    #include <cxxext/linked_map.hpp>
    
Usage is equivalent to <code>std::map</code>.  There are two variants available.  <code>cxxext::linked\_map</code> uses <code>std::map</code>, <code>cxxext::linked\_hash</code> uses <code>std::unordered\_map</code>.

Example
-----
    #include <cxxext/linked_map.hpp>
    #include <string>
    #include <iostream>
    
	using namespace std;
	using namespace cxxext;
    
    int main (int argc, char** argv)
    {
       linked_map<string, string> map;
       string name, value;
       
		while (cin >> name >> value) {
			map[name] = value;
		}
		
		for (auto pair : map) {
			cout << pair.first << " = " << pair.second << endl;
		}
		
       return 0;
    }
    
#### Input

    a 1
    b 2
    c 3
    d 4
    a 9
    z 12
    b 9
    
#### Output

    a = 9
    b = 9
    c = 3
    d = 4
    z = 12
    
