import std;
template<typename T>
struct Node {
	T _value = T();
	Node* _next = nullptr;
	Node(T val, Node* next): _value(val), _next(next) {}
};

template<typename T>
class LinkedList {
private:
	Node<T>* _end = nullptr;
	int _size = 0;

	static void FillRandom(Node<int>*& end, int size)
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<int> dist(-100, 100);
		end = new Node<int>(dist(gen));
		Node<int>* cur = end;
		for (int i = 1; i < size; ++i)
		{
			Node<int>* el = new Node<int>(dist(gen));
			cur->_next = el;
			cur = cur->_next;
		}
		cur->_next = end;
	}
	static void FillRandom(Node<short>*& end, int size)
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<short> dist(-100, 100);
		end = new Node<short>(dist(gen));
		Node<short>* cur = end;
		for (int i = 1; i < size; ++i)
		{
			Node<short>* el = new Node<short>(dist(gen));
			cur->_next = el;
			cur = cur->_next;
		}
		cur->_next = end;
	}
	static void FillRandom(Node<long>*& end, int size)
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<long> dist(-100, 100);
		end = new Node<long>(dist(gen));
		Node<long>* cur = end;
		for (int i = 1; i < size; ++i)
		{
			Node<long>* el = new Node<long>(dist(gen));
			cur->_next = el;
			cur = cur->_next;
		}
		cur->_next = end;
	}
	static void FillRandom(Node<double>*& end, int size)
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_real_distribution<double> dist(-100.0, 100.0);
		end = new Node<double>(dist(gen));
		Node<double>* cur = end;
		for (int i = 1; i < size; ++i)
		{
			Node<double>* el = new Node<double>(dist(gen));
			cur->_next = el;
			cur = cur->_next;
		}
		cur->_next = end;
	}
	static void FillRandom(Node<float>*& end, int size)
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_real_distribution<float> dist(-100.0, 100.0);
		end = new Node<float>(dist(gen));
		Node<float>* cur = end;
		for (int i = 1; i < size; ++i)
		{
			Node<float>* el = new Node<float>(dist(gen));
			cur->_next = el;
			cur = cur->_next;
		}
		cur->_next = end;
	}
public:
	LinkedList(){}

	LinkedList(const LinkedList& other)
	{
		if (other._end == nullptr) return;
		if (other._size == 0) return;
		_size = other._size;
		_end = new Node<T>(other._end->_value);
		Node<T>* cur = _end;
		Node<T>* otherNext = other._end->_next;
		while (otherNext != other._end) {
			cur->_next = new Node<T>(otherNext->_value);
			cur = cur->_next;
			otherNext = otherNext->_next;
		}
		cur->_next = _end;
	}

	LinkedList(int size)
	{
		if (size < 0) throw std::invalid_argument("Error! Degenerate size!");
		if (size == 0) return;
		_size = size;
		FillRandom(_end, size);
	}

	~LinkedList() 
	{
		if (_end == nullptr) return;
		Node<T>* cur = _end->_next;
		while (cur != _end)
		{
			Node<T>* next = cur->_next;
			delete cur;
			cur = next;
		}
		delete _end;
		_end = nullptr;
		_size = 0;
	}

	int getSize() const { return _size; }
	const Node<T>* getEnd() const { return _end; }


	LinkedList& operator=(const LinkedList& other)
	{
		if (this == &other) return *this;
		if (_end != nullptr)
		{
			Node<T>* cur = _end->_next;
			while (cur != _end)
			{
				Node<T>* next = cur->_next;
				delete cur;
				cur = next;
			}
			delete _end;
			_end = nullptr;
			_size = 0;
		}
		if (other._end == nullptr) return *this;
		_end = new Node<T>(other._end->_value);
		_size = other._size;
		Node<T>* cur = _end;
		Node<T>* otherNext = other._end->_next;
		while (otherNext != other._end)
		{
			cur->_next = new Node<T>(otherNext->_value);
			cur = cur->_next;
			otherNext = otherNext->_next;
		}
		cur->_next = _end;
		return *this;
	}

	void push_tail(T value)
	{
		if (_end == nullptr)
		{
			_end = new Node<T>(value);
			_end->_next = _end;
			++_size;
		}
		else 
		{
			Node<T>* newVal = new Node<T>(value);
			newVal->_next = _end->_next;
			_end->_next = newVal;
			_end = newVal;
			++_size;
		}
	}

	void push_tail(const LinkedList& other)
	{
		if (other._end == nullptr) return;

		Node<T>* otherCur = other._end->_next;
		while (otherCur != other._end)
		{
			push_tail(otherCur->_value);
			otherCur = otherCur->_next;
		}
		push_tail(otherCur->_value);
	}

	void push_head(T value)
	{
		if (_end == nullptr)
		{
			_end = new Node<T>(value);
			_end->_next = _end;
			++_size;
		}
		else
		{
			Node<T>* newVal = new Node<T>(value);
			newVal->_next = _end->_next;
			_end->_next = newVal;
			++_size;
		}
	}

	void push_head(const LinkedList& other)
	{
		if (other._end == nullptr) return;
		Node<T>* otherCur = other._end;
		do
		{
			push_head(otherCur->_value);

			for (int i = 0; i < other._size - 1; ++i)
			{
				otherCur = otherCur->_next;
			}
		} while (otherCur != other._end);
	}

	void pop_head()
	{
		if (_end == nullptr) return;
		if (_size == 1)
		{
			delete _end;
			_end = nullptr;
			--_size;
			return;
		}
		Node<T>* tmp = _end->_next;
		_end->_next = tmp->_next;
		delete tmp;
		--_size;
	}

	void pop_tail()
	{
		if (_end == nullptr) return;
		if (_size == 1)
		{
			delete _end;
			_end = nullptr;
			--_size;
			return;
		}
		for (int i = 0; i < _size - 1; ++i)
		{
			_end = _end->_next;
		}
		Node<T>* tmp = _end->_next;
		_end->_next = tmp->_next;
		delete tmp;
		--_size;
	}

	void delete_node(T value)
	{
		if (_end == nullptr) return;

		while(_end->_next->_value == value)
		{
			pop_head();
			if (_end == nullptr) return;
		}

		Node<T>* cur = _end->_next;
		while (cur->_next != _end)
		{
			if (cur->_next->_value == value)
			{
				Node<T>* tmp = cur->_next;
				cur->_next = tmp->_next;
				delete tmp;
				--_size;
			}
			else
			{
				cur = cur->_next;
			}
		} 

		if (_end->_value == value)
		{
			pop_tail();
		}
	}

	const T operator[](int index) const
	{
		if (_size == 0) throw std::out_of_range("Empty list");
		index %= _size;
		if (index < 0) index += _size;
		Node<T>* cur = _end;
		for (int i = 0; i <= index; ++i)
		{
			cur = cur->_next;
		}
		return cur->_value;
	}

	T& operator[](int index)
	{
		if (_size == 0) throw std::out_of_range("Empty list");
		index %= _size;
		if (index < 0) index += _size;
		Node<T>* cur = _end;
		for (int i = 0; i <= index; ++i)
		{
			cur = cur->_next;
		}
		return cur->_value;
	}
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const LinkedList<T>& obj)
{
	if (obj.getSize() == 0)
	{
		os << "[]";
		return os;
	}
	const Node<T>* cur = obj.getEnd()->_next;
	os << "...-->";
	for (int i = 0; i < obj.getSize(); ++i)
	{
		os << "[" << cur->_value << "|*]-->";
		cur = cur->_next;
	}
	os << "-->...\n";
	return os;
}