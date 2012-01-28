**basic_stringizer** - functor that turns an object into a basic_string  
**stringize** - function that turn an object into a string

Creating a string from an int:

	std::string s = "The answer is " + stringize(42);
	
Transforming a vector of doubles to a vector of strings:

	std::vector<double> vf;
	std::vector<std::string> vs;
	vf.push_back(3.14159); vf.push_back(2.71828); vf.push_back(1.57079);
	std::transform(
	    vf.begin(), vf.end(),   // from
	    std::back_inserter(vs), // to
	    stringizer() );         // transformation

Note: The object you stringize must have the output operator defined (`operator<<` with an `ostream` argument).
