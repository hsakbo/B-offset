#include <iostream>
#include <vector>


void add1(std::vector<int> &num)
{
  using namespace std;
  int carry = 1;

  for (int i = num.size() -1; i >= 0; i--)
    {
      int ind = num[i];
      ind += carry;
      carry = ind / 10;
      num[i] = ind % 10;
    }

  if (carry)
    {
      num.emplace(num.begin(), -1);
      num[0] += carry;
    }
  
}

int pow(int base, int exp)
{
  if(!exp)
    return 1;
  return base * pow(base, exp-1);
}

int p_decode(std::vector<int> &num)
{
  if (num.size() == 1)  
    return num[0] + 1;
    

  int retVal;
  int d_val = num.size();
  for (int i = 0; i < d_val - 1; i++)
    {
      int ind = 11;
      if (!i)
	{
	  ind = ind * pow(10, d_val - 2 - i) * (num[i]+1);
	  retVal = ind;
	}
      
      else
	{
	  ind = ind * pow(10, d_val - 2 - i) * (num[i]);
	  retVal += ind;
	}
    }
  retVal += num[d_val-1];
  return retVal;

}

int main()
{
  
  std::vector<int> num;
  num.emplace(num.begin(), -1);
  std::cout << "\n\n";
  std::cout << "base is 10, offset is -1\n\n";
  std::cout << "Index(b10)\toffset value\tmy_decode_formula" << std::endl;

  for (int i = 0; i < 1000; i++)
    {
      std::cout << i << "\t\t";
      
      for (int j = 0; j < num.size(); j++)
	{
	  std::cout << num[j];
	}
      std::cout << "\t\t";
      std::cout << p_decode(num) << std::endl;
      add1(num);
    }
  
  return 0;
}
