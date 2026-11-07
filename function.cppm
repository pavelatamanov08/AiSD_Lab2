export module function;
import std;
import classes;

export template<typename T>
void print_reverse(const LinkedList<T>& other)
{
	if (other.getSize() == 0)
	{
		std::cout << "[]";
		return;
	}
	std::string result = "...";
	for (int i = other.getSize() - 1; i >= 0 ; --i)
	{
		result += "<--[*|";
		result += std::format("{}", other[i]);
		result += "]";
	}
	result += "<--...";
	std::cout << result;
}