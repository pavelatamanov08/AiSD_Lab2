import function;
import classes;
import std;

int main()
{
	LinkedList<int> obj1(8);
	LinkedList<int> obj11(3);
	LinkedList<double> obj2(4);
	LinkedList<double> obj22(2);
	LinkedList<long> obj3(6);
	LinkedList<float> obj4(5);
	LinkedList<short> obj5(3);
	std::cout << "obj1:\n" << obj1 << "obj11:\n" << obj11 << "obj2:\n" << obj2 << "obj22:\n" << obj22 
		<< "obj3:\n" << obj3 << "obj4:\n" << obj4 << "obj5:\n" << obj5 << "\n";

	LinkedList<int> obj6 = LinkedList<int>();
	std::cout << "Constructor Default:\n" << obj6;
	LinkedList<double> obj7(obj2);
	std::cout << "Constructor Copy:\n" << obj7;
	LinkedList<int> obj8 = obj1;
	std::cout << "Operator \'=\'" << obj8 << "\n";

	obj1.push_tail(5);
	std::cout << "obj1.push_tail(5):\n" << obj1;
	obj2.push_head(8);
	std::cout << "obj2.push_head(8):\n" << obj2;
	obj1.push_tail(obj11);
	std::cout << "obj1.push_tail(obj11):\n" << obj1;
	obj2.push_head(obj22);
	std::cout << "obj2.push_head(obj22):\n" << obj2;

	obj1.pop_tail();
	std::cout << "obj1.pop_tail():\n" << obj1;
	obj2.pop_head();
	std::cout << "obj2.pop_head():\n" << obj2;
	obj1[3] = 5;
	obj1[5] = 5;
	std::cout << "Default obj1:\n" << obj1;
	obj1.delete_node(5);
	std::cout << "obj1.delete_node(5):\n" << obj1;

	std::cout << "print_reverse(obj1):\n";
	print_reverse(obj1);
}