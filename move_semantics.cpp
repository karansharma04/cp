#include <bits/stdc++.h>
using namespace std;

class Entity {
	int* m_numbers;
	int m_sz;
	public:
	Entity(): m_sz(0), m_numbers(nullptr) {
		cout<<"Inside default constructor"<<endl;
	}
	Entity(int* nums, int sz) {
		cout<<"Inside param. constructor"<<endl;
		m_sz = sz;
		m_numbers = new int[m_sz];
		for(int i=0;i<m_sz;i++) {
			m_numbers[i] = nums[i];
		}
	}
	Entity(const Entity& e) {
		cout<<"Inside copy constructor"<<endl;
		m_sz = e.m_sz;
		m_numbers = new int[m_sz];
		for(int i=0;i<m_sz;i++) {
			m_numbers[i] = e.m_numbers[i];
		}
	}
	Entity(Entity&& e) {
		cout<<"Inside move constructor"<<endl;
		m_sz = e.m_sz;
		m_numbers = e.m_numbers;
		
		e.m_numbers = NULL;
		e.m_sz = 0;
	}
	void operator=(const Entity& e) {
		cout<<"Inside copy ass. op"<<endl;
		m_sz = e.m_sz;
		m_numbers = new int[m_sz];
		for(int i=0;i<m_sz;i++) {
			m_numbers[i] = e.m_numbers[i];
		}
	}
	void operator=(Entity&& e) {
		cout<<"Inside move ass. op"<<endl;
		m_sz = e.m_sz;
		m_numbers = e.m_numbers;
		e.m_numbers = nullptr;
		e.m_sz = 0;
	}
	~Entity() {
		cout<<"Inside Destructor"<<endl;
		if(m_numbers) delete m_numbers;
	}
};

int main() {
	int arr[] = {1, 2, 3};
	Entity e(arr, 3);
	Entity d;
	d = move(e);
	return 0;
}