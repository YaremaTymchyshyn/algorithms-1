#include<iostream>
#include<vector>
#include <algorithm>
#include<exception>
using namespace std;

template<typename T>

class Set
{
private:
	vector<T> set;
public:

	void add(T element)
	{
		auto result = find(set.begin(), set.end(), element);

		if (result != set.end())
		{
			throw exception("Error! Set can't have elements that are the same!");
		}

		else
		{
			set.push_back(element);
		}
	}

	void remove(T element)
	{
		auto result = find(set.begin(), set.end(), element);

		if (result != set.end())
		{
			set.erase(result);
		}

		else
		{
			throw exception("Error! Can't remove element that doesn't exist");
		}
	}

	bool exist(T element)
	{
		auto result = find(set.begin(), set.end(), element);

		if (result != set.end())
		{
			return true;
		}

		else
		{
			return false;
		}
	}

	size_t size()
	{
		return set.size();
	}

	T max()
	{
		return *max_element(set.begin(), set.end());
	}

	T min()
	{
		return *min_element(set.begin(), set.end());
	}

	Set merge(Set other)
	{
		Set result = *this;

		for (int i = 0; i < other.size(); i++)
		{
			auto temp = find(result.set.begin(), result.set.end(), other.set[i]);

			if (temp == result.set.end())
			{
				result.set.push_back(other.set[i]);
			}
		}

		return result;
	}

	Set intersection(Set other)
	{
		Set result;

		for (int i = 0; i < other.size(); i++)
		{
			auto temp = find(set.begin(), set.end(), other.set[i]);

			if (temp != set.end())
			{
				result.set.push_back(other.set[i]);
			}
		}

		return result;
	}

	Set difference(Set other)
	{
		Set result = *this;

		for (int i = 0; i < other.size(); i++)
		{
			auto temp = find(result.set.begin(), result.set.end(), other.set[i]);

			if (temp != result.set.end())
			{
				result.set.erase(temp);
			}
		}

		return result;
	}

	void show()
	{
		for (int i = 0; i < set.size(); i++)
		{
			cout << set[i] << ' ';
		}

		cout << endl;
	}
};

int main()
{
	Set<int> first;
	first.add(91);
	first.add(12);
	first.add(-54);
	first.add(8);

	Set<int> second;
	second.add(100);
	second.add(2);
	second.add(91);
	second.add(46);
	second.add(-54);

	cout << "First set: ";
	first.show();
	cout << "Second set: ";
	second.show();
	cout << endl;
	cout << endl;

	Set<int> result;

	cout << "Merge: ";
	result = first.merge(second);
	result.show();
	cout << endl;

	cout << "Intersection: ";
	result = first.intersection(second);
	result.show();
	cout << endl;

	cout << "Difference (first without second): ";
	result = first.difference(second);
	result.show();
	cout << endl;
}