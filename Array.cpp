#include <iostream>
using namespace std;


template<class Value>
class Array {
private:
  
  int m_size;
  int m_capacity;
  Value* m_data;

public:
  Array(): m_size(0), m_capacity(0), m_data(NULL){}
  
  Array(int size) {
    m_size = size;
    m_capacity = size*2;
    m_data = new Value[m_capacity];

  }
  Array(const Array& other) {
    m_size = other.m_size;
    m_data = new Value[other.m_size];

    for (int i = 0; i < m_size; ++i) {
      m_data[i] = other.m_data[i];
    }
  
  }
  ~Array() {
    delete[] m_data;
  }

  Array<Value>& operator=(const Array& other) {
    delete m_data;
    m_size = other.m_size;
    m_data = new Value[other.m_size];
    for( int i = 0; i < size()+1; ++i) {
      m_data[i] = other.m_data[i];
    }
    return *this;
  }

  /**
     Reserves creates a temporary array and copies the m_data into this temporary array.
     Next it deletes the original m_data and creates a new array called m_date which is of size n
     It then copies the values from temp into the new m_data which has the additional capacity

  **/
  void reserve(int n) {
    Value* temp = new Value[m_size];
    for (int i = 0; i < m_size; ++i) {
      temp[i] = m_data[i];
    }
    
    delete[] m_data;
    m_data = new Value[n];    
    for (int i = 0 ; i < m_size; ++i) {
      m_data[i] = temp[i];
    }
    m_capacity = n;
    delete[] temp;

  }

  void push_back(const Value& value){
    if (m_capacity > m_size) {
      m_data[m_size] = value;
      m_size++;
    }
    else {
      if (m_capacity == 0) 
	reserve(1);
      
      else 
	reserve(2*m_size);
      
      m_data[m_size] = value;
      m_size++;
    }
}

  const Value& operator[](size_t i) const {
    return m_data[i];
  }
  
  Value& operator[](size_t i) {
    return m_data[i];
  }

  size_t size() const {
    return m_size;
  }
  size_t capacity() const {
    return m_capacity;
  }

  void insert(size_t position, const Value& value) {
    if (m_capacity == 0) 
      reserve(1);
    
    if ((m_capacity == m_size) && (m_capacity != 0)) 
      reserve(m_size*2);
        
    if (m_capacity > m_size ) {
      for(int i = position + 1; i < m_size + 1; ++i) {
	m_data[i] = m_data[i-1];
      }
      m_data[position] = value;
      ++m_size;
    }      
  }
};


int main() {

  Array< int > x;
 
  Array< int > y(10);

  for (int i = 0; i < 10; ++i) {
    x.push_back(i);
  }
  cout << "x[3] = " << x[3] << '\n';
  cout << "x.size() = " << x.size() << '\n';
  cout << "x.capacity() = " << x.capacity() << '\n';
  cout << "x[x.size() -1] = " << x[x.size() -1] << '\n';

  cout << "y size: " << y.size() <<'\n';
  cout << "y capacity: "<< y.capacity() << '\n';
  
  cout << "y[1] before insert = " << y[1] << '\n';
  y.insert(1, 1);
  cout << "y[0] = " << y[0] << '\n';
  cout << "y[1] after inserting 1 at positon 1 = " << y[1] << '\n';

  Array< int > z(y);
    

  cout << "x.size() = " << x.size() << '\n';
  cout << "y.size() = " << y.size() << '\n';
  
  //Test push back on z
  //cout << "z.size() = " << z.size() << '\n';
  z.push_back(1000);
  //cout << "z.size() = " << z.size() << '\n';
  // cout << "z[m_size-1] = " << z[z.size() - 1] << '\n';
  

  return 0;

}
