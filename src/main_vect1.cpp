#include "Vector.hpp"
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <map>
#include "Container.hpp"
#include "Map.hpp"

class B {
public:
	char *l;
	int i;
	B():l(nullptr), i(1) {};
	B(const int &ex) {
		this->i = ex;
		this->l = new char('a');
	};
	virtual ~B() {
		delete this->l;
		this->l = nullptr;
	};
};

class A : public B {
public:
	A():B(){};
	A(const B* ex){
		this->l = new char(*(ex->l));
		this->i = ex->i;
		if (ex->i == -1) throw "n";
	}
	~A() {
		delete this->l;
		this->l = nullptr;
	};
};

template<class T>
void      ft_assert(const T& lhs, const T& rhs)
{ 
    if(lhs == rhs)
        std::cout << "[OK] ";
    else
    {
        std::cout << "[KO] ";
        std::cout << lhs << " vs " << rhs << std::endl;
    }

}

int main() 
{
	/* ERASE RANGE */
    //////////////////
	{
		// std::vector<int> v;
		// ft::Vector<int> vector;
    	// for (int i = 0; i < 99000000; ++i)
    	//     vector.push_back(i);
    	// v.push_back(*(vector.erase(vector.begin() + 80000, vector.end() - 15000000)));

    	// v.push_back(*(vector.begin() + 82000));
    	// v.push_back(vector.size());
    	// v.push_back(vector.capacity());
		// for (size_t i = 0; i < v.size(); i++)
		// {
		//     std::cout << v[i] << " ";
		// }
	}

    /* Constructyor */
    //////////////////
    // {
		// std::vector<int> v;
		// ft::Vector<int> vector;
		// ft::Vector<int> tmp0(vector);
    	// ft::Vector<int> tmp(10000000, 4), tmp2(10000000, 5);
    	// tmp = tmp2;
    	// ft::Vector<int> tmp3(tmp);
    	// ft::Vector<int> tmp4(tmp.begin(), tmp.end());
    	// v.push_back(tmp4.size());
    	// v.push_back(tmp4.capacity());
    	// v.push_back(tmp[2]);
    	// v.push_back(tmp3[2]);
    	// v.push_back(tmp4[2]);
    	// try { ft::Vector<int> tmp5(-1, -1); }
    	// catch (std::exception &e) { v.push_back(1); }
    	// for (size_t i = 0; i < v.size(); i++)
    	// {
    	//     std::cout << v[i] << " ";
    	// }
    // }


	/* ITERATORS */
	///////////////
	// {
		// std::vector<int> v;
		// ft::Vector<int> vector;
		// ft::Vector<int>::iterator it;
		// for (int i = 0; i < 10; ++i)
		// 	vector.push_back(i);
		// it = vector.begin();
		// v.push_back(*(++it));
		// v.push_back(*(--it));
		// v.push_back(*(it + 1));
		// it += 1;
		// v.push_back(*(it - 1));
		// it -= 1;
		// v.push_back(*it);
	// }

	/* RBEGIN */
	/////////////
	// {
		// std::vector<int> v;
		// ft::Vector<int> vector;
		// vector.assign(1000, 1);
		// v.push_back(*vector.rbegin());
		// v.push_back(*(vector.rbegin() + 1));
	// }
	/* EMPTY */
	/////////////
	// {
	// 	std::vector<int> v;
	// 	ft::Vector<int> vector;
	// 	vector.assign(1000, 1);
	// 	v.push_back(vector.empty());
	// }

	/* POPBACK */
	/////////////
	// {
		// std::vector<int> v;
		// ft::Vector<int> vector;
		// vector.assign(99000000, 1);
		// vector.pop_back();
		// v.push_back(vector[vector.size() - 1]);
		// v.push_back(vector.size());
		// v.push_back(vector.capacity());
		// for (size_t i = 0; i < v.size(); i++)
		// {
		// 	std::cout << v[i] << " ";
		// }
	// }

	/* PUSHBACK */
	/////////////
	{
		// std::vector<int> v;
		// std::vector<int> vector;
		// for (int i = 0; i < 550000; ++i) 
		// {
        // 	vector.push_back(i);
    	// }
    	// v.push_back(vector.size());
    	// v.push_back(vector.capacity());
		// for (size_t i = 0; i < v.size(); i++)
		// {
		// 	std::cout << v[i] << " ";
		// }
	}

	/* INSERT VALUE */
	///////////////////
	{
		// std::vector<int> v;
		// ft::Vector<int> vector;
		// vector.assign(26000000, 1);
    	// v.push_back(*(vector.insert(vector.end() - 8000000, 44)));
    	// v.push_back(vector.size());
    	// v.push_back(vector.capacity());
    	// std::unique_ptr<B> k2(new B(3));
    	// std::unique_ptr<B> k3(new B(4));
    	// std::unique_ptr<B> k4(new B(-1));
    	// std::vector<A> vv;
    	// std::vector<B*> v1;

    	// v1.push_back(&(*k2));
    	// v1.push_back(&(*k3));
    	// v1.push_back(&(*k4));
    	// try { vv.insert(vv.begin(), v1.begin(), v1.end()); }
    	// catch (...) 
		// {
		// 	v.push_back(vv.size());
		// 	v.push_back(vv.capacity());
		// }
		// for (size_t i = 0; i < v.size(); i++)
		// {
		// 	std::cout << v[i] << " ";
		// }
	}

	/* INSERT RANGE */
	///////////////////
	// {
		// std::vector<int> v;
		// ft::Vector<int> vector;
		// for (int i = 0; i < 99000000; ++i)
		//     vector.push_back(i);
		// v.push_back(*(vector.erase(vector.begin() + 80000, vector.end() - 15000000)));
		// v.push_back(*(vector.begin() + 82000));
		// v.push_back(vector.size());
		// v.push_back(vector.capacity());
	// }

	/* SWAP */
	///////////////////
	// {
		// std::vector<int> v;
		// ft::Vector<int> vector;
		// vector.assign(11000000, 11);
		// ft::Vector<int> tmp(5000000, 5), tmp2(10000000, 10), tmp3(15000000, 15), tmp4(30000000, 30);
		// v.push_back(vector[2]);
		// v.push_back(vector.size());
		// v.push_back(vector.capacity());
		// long *adr1 = reinterpret_cast<long *>(&vector);
		// long *adr2 = reinterpret_cast<long *>(&tmp);
		// vector.swap(tmp);
		// if (reinterpret_cast<long *>(&vector) == adr1 && reinterpret_cast<long *>(&tmp) == adr2)
		// 	v.push_back(1);
		// v.push_back(vector[2]);
		// v.push_back(vector.size());
		// v.push_back(vector.capacity());
		// vector.swap(tmp3);
		// v.push_back(vector[2]);
		// v.push_back(vector.size());
		// v.push_back(vector.capacity());
		// std::swap(vector, tmp2);
		// v.push_back(vector[2]);
		// v.push_back(vector.size());
		// v.push_back(vector.capacity());
		// std::swap(vector, tmp4);
		// v.push_back(vector[2]);
		// v.push_back(vector.size());
		// v.push_back(vector.capacity());
		// for (size_t i = 0; i < v.size(); i++)
		// {
		// 	std::cout << v[i] << " ";
		// }
	// }

	/* OPERATOR == */
	///////////////////
	// {
		// ft::Vector<int> result, result_2;
		// ft::Vector<int> v_int1, v_int2, v_int3;
		// ft::Vector<std::string> v_str1, v_str2;		
		// ft::Vector<int> V_int1, V_int2, V_int3;
		// ft::Vector<std::string> V_str1, V_str2;
		// V_int1.push_back(1);
		// V_int3.push_back(1);
		// V_str1.push_back("aa");
		// V_str2.push_back("ab");
		// result_2.push_back(V_int1 < V_int2);
		// V_int2.push_back(2);
		// result_2.push_back(V_int1 < V_int2);
		// result_2.push_back(V_int1 < V_int3);
		// result_2.push_back(V_str1 < V_str2);
	// }

	/* ERASE VALUE(IT) */
	///////////////////
	{
		// std::vector<int> v;
		// ft::Vector<int> vector;
    	// for (int i = 0; i < 99000000; ++i)
    	//     vector.push_back(i);
    	// v.push_back(*(vector.erase(vector.begin() + 80000)));
    	// v.push_back(*(vector.begin() + 82000));
    	// v.push_back(vector.size());
    	// v.push_back(vector.capacity());
		// for (size_t i = 0; i < v.size(); i++)
		// {
		// 	std::cout << v[i] << " ";
		// }
	}

	/* EMPTY */
	///////////////////
	// {
		// std::vector<int> vec_std;
  		// ft::Vector<int> vec_ft;
  		// ft_assert(vec_std.empty(), vec_ft.empty());
  		// vec_std.insert(vec_std.begin(), 4);
  		// vec_ft.insert(vec_ft.begin(), 4);
  		// ft_assert(vec_std.empty(), vec_ft.empty());
	// }

	/* AT */
	///////////////////
	// {
		// ft::Vector<int> vec_ft(4,100);
  		// try
  		// {
  		//   vec_ft.at(3);
  		//   vec_ft.at(4);
  		//   std::cout << "[KO] ";
  		// }
  		// catch(const std::exception& e)
  		// {
  		//   std::cout << "[OK] ";
  		// }
	// }/

	/* ITERATORS */
	///////////////////
	{
		ft::Vector<int> u(4, 500);
  		u[1] = 400;
  		u[2] = 300;
  		u[3] = 200;
  		std::vector<int> u1(4, 500);
  		u1[1] = 400;
  		u1[2] = 300;
  		u1[3] = 200;   
  		ft::Vector<int>::iterator it_ft = u.begin();
  		ft::Vector<int>::iterator it_fte = u.end();
  		ft::Vector<int>::const_iterator it_constft = u.begin();
  		ft::Vector<int>::const_iterator it_constfte = u.end();
  		ft::Vector<int>::const_reverse_iterator it_constreverseft = u.rbegin();
  		ft::Vector<int>::const_reverse_iterator it_constreversefte = u.rend(); 
  		std::vector<int>::iterator it_std = u1.begin();
  		std::vector<int>::iterator it_stde = u1.end();
  		std::vector<int>::const_iterator it_conststd = u1.begin();
  		std::vector<int>::const_iterator it_conststde = u1.end();
  		std::vector<int>::const_reverse_iterator it_constreversestd = u1.rbegin();
  		std::vector<int>::const_reverse_iterator it_constreversestde = u1.rend();
  		ft_assert(*(it_std++), *(it_ft++));
  		ft_assert(*(++it_std), *(++it_ft));
  		ft_assert(*(--it_std), *(--it_ft));
  		ft_assert(*(it_std--), *(it_ft--));
  		ft_assert(*(2 + it_std),  *(2 + it_ft));
  		ft_assert(*(it_std + 2), *(it_ft + 2));
  		ft_assert((it_stde - it_std), (it_fte - it_ft));
  		ft_assert((it_stde < it_std), (it_fte < it_ft));
  		ft_assert((it_std < it_stde), (it_ft < it_fte));
  		ft_assert((it_stde > it_std), (it_fte > it_ft));
  		ft_assert((it_std > it_stde), (it_ft > it_fte));
  		ft_assert((it_stde >= it_std), (it_fte >= it_ft));
  		ft_assert((it_std >= it_stde), (it_ft >= it_fte));
  		ft_assert((it_stde <= it_std), (it_fte <= it_ft));
  		ft_assert((it_std <= it_stde), (it_ft <= it_fte));
  		std::cout << std::endl;
  		ft_assert(*(it_stde -= 1), *(it_fte -= 1));                        /* end() + 1 !!!!!! */
  		ft_assert(*(it_std += 1), *(it_ft += 1));
  		ft_assert(*(it_std -= 1), *(it_ft -= 1));
  		ft_assert(*(it_std += 1), *(it_ft += 1));                         /* begin() - 1 !!!!!! */
  		ft_assert(*(it_conststd++), *(it_constft++));
  		ft_assert(*(++it_conststd), *(++it_constft));
  		ft_assert(*(--it_conststd), *(--it_constft));
  		ft_assert(*(it_conststd--), *(it_constft--));
  		ft_assert(*(2 + it_conststd),  *(2 + it_constft));
  		ft_assert(*(it_conststd + 2), *(it_constft + 2));
  		ft_assert((it_conststde - it_conststd), (it_constfte - it_constft));
  		ft_assert((it_conststde < it_conststd), (it_constfte < it_constft));
  		ft_assert((it_conststd < it_conststde), (it_constft < it_constfte));
  		ft_assert((it_conststde > it_conststd), (it_constfte > it_constft));
  		ft_assert((it_conststd > it_conststde), (it_constft > it_constfte));
  		std::cout << std::endl;
  		ft_assert((it_conststde >= it_conststd), (it_constfte >= it_constft));
  		ft_assert((it_conststd >= it_conststde), (it_constft >= it_constfte));
  		ft_assert((it_conststde <= it_conststd), (it_constfte <= it_constft));
  		ft_assert((it_conststd <= it_conststde), (it_constft <= it_constfte));
  		ft_assert(*(it_conststde -= 1), *(it_constfte -= 1));             /* исправил на - 1 !!!!!! */
  		ft_assert(*(it_conststd += 1), *(it_constft += 1));
  		ft_assert(*(it_conststd -= 1), *(it_constft -= 1));
  		ft_assert(*(it_conststd += 1), *(it_constft += 1));
  		ft_assert(*(it_constreversestd++), *(it_constreverseft++));
		// std::cout << "\n" << *(it_constreversestd) << " " << *(it_constreverseft) << "\n";
		ft_assert(*(++it_constreversestd), *(++it_constreverseft));
		// std::cout << "\n" << *(it_constreversestd) << " " << *(it_constreverseft) << "\n";
		ft_assert(*(--it_constreversestd), *(--it_constreverseft));
		// std::cout << "\n" << *(it_constreversestd) << " " << *(it_constreverseft) << "\n";
  		ft_assert(*(it_constreversestd--), *(it_constreverseft--));
		// std::cout << "\n" << *(it_constreversestd) << " " << *(it_constreverseft) << "\n";
  		ft_assert(*(2 + it_constreversestd), *(2 + it_constreverseft));
		// std::cout << "\n" << *(it_constreversestd) << " " << *(it_constreverseft) << "\n";
  		ft_assert(*(it_constreversestd + 2), *(it_constreverseft + 2));
		// std::cout << "\n" << *(it_constreversestd) << " " << *(it_constreverseft) << "\n";
  		ft_assert((it_constreversestde - it_constreversestd), (it_constreversefte - it_constreverseft));
  		std::cout << std::endl;
  		ft_assert((it_constreversestde - 3 < it_constreversestd + 1), (it_constreversefte - 3 < it_constreverseft + 1));
  		ft_assert((it_constreversestd + 1< it_constreversestde - 3), (it_constreverseft +1 < it_constreversefte - 3));
  		ft_assert((it_constreversestde - 3> it_constreversestd + 1), (it_constreversefte - 3 > it_constreverseft + 1));
  		ft_assert((it_constreversestd +1> it_constreversestde-3), (it_constreverseft+1 > it_constreversefte-3));
  		ft_assert((it_constreversestde-3 >= it_constreversestd +1), (it_constreversefte-3 >= it_constreverseft+1));
  		ft_assert((it_constreversestd+1 >= it_constreversestde-3), (it_constreverseft+1 >= it_constreversefte-3));
  		ft_assert((it_constreversestde-3 <= it_constreversestd+1), (it_constreversefte-3 <= it_constreverseft+1));
  		ft_assert((it_constreversestd+1 <= it_constreversestde-3), (it_constreverseft+1 <= it_constreversefte-3));
  		ft_assert(*(it_constreversestde -= 1), *(it_constreversefte -= 1));                                              /* исправил на - 1 !!!!!! */
  		ft_assert(*(it_constreversestd += 1),  *(it_constreverseft += 1));
  		ft_assert(*(it_constreversestd -= 1), *(it_constreverseft -= 1));
  		ft_assert(*(it_constreversestde -= 1), *(it_constreversefte -= 1));
  		ft::Vector<int>::const_iterator cit_1 = u.begin();
  		ft::Vector<int>::const_iterator cit_2 = u.begin() + 2;
  		std::vector<int>::const_iterator cit_std1 = u1.begin();
  		std::vector<int>::const_iterator cit_std2 = u1.begin() + 2;
  		ft_assert((cit_std2 - cit_std1), (cit_2 - cit_1));
  		ft::Vector<int>::iterator it_1 = u.begin();
  		ft::Vector<int>::iterator it_2 = u.begin() + 2;
  		std::vector<int>::iterator it_std1 = u1.begin();
  		std::vector<int>::iterator it_std2 = u1.begin() + 2;
  		ft_assert((it_std2 - it_std1), (it_2 - it_1));
  		ft::Vector<int>::const_reverse_iterator rit_1 = u.rbegin();
  		ft::Vector<int>::const_reverse_iterator rit_2 = u.rbegin() + 2;
  		std::vector<int>::const_reverse_iterator rit_std1 = u1.rbegin();
  		std::vector<int>::const_reverse_iterator rit_std2 = u1.rbegin() + 2;
  		ft_assert((rit_std2 - rit_std1), (rit_2 - rit_1));
	}

	// {
	// 	std::vector<std::string> res;
	// 	std::vector<std::string> res2;


	// 	res.push_back(typeid(std::vector<int>::iterator::iterator_category).name());
	// 	res.push_back(typeid(std::vector<int>::iterator::value_type).name());
	// 	res.push_back(typeid(std::vector<int>::iterator::difference_type).name());
	// 	res.push_back(typeid(std::vector<int>::iterator::iterator_type).name());
	// 	res.push_back(typeid(std::vector<int>::iterator::pointer).name());
	// 	res.push_back(typeid(std::vector<int>::iterator::reference).name());
	// 	res.push_back(typeid(std::vector<int>::reverse_iterator::iterator_category).name());
	// 	res.push_back(typeid(std::vector<int>::reverse_iterator::value_type).name());
	// 	res.push_back(typeid(std::vector<int>::reverse_iterator::difference_type).name());
	// 	res.push_back(typeid(std::vector<int>::reverse_iterator::pointer).name());
	// 	res.push_back(typeid(std::vector<int>::reverse_iterator::reference).name());

	// 	res2.push_back(typeid(ft::Vector<int>::iterator::iterator_category).name());
	// 	res2.push_back(typeid(ft::Vector<int>::iterator::value_type).name());
	// 	res2.push_back(typeid(ft::Vector<int>::iterator::difference_type).name());
	// 	res2.push_back(typeid(ft::Vector<int>::iterator::iterator_type).name());
	// 	res2.push_back(typeid(ft::Vector<int>::iterator::pointer).name());
	// 	res2.push_back(typeid(ft::Vector<int>::iterator::reference).name());
	// 	res2.push_back(typeid(ft::Vector<int>::reverse_iterator::iterator_category).name());
	// 	res2.push_back(typeid(ft::Vector<int>::reverse_iterator::value_type).name());
	// 	res2.push_back(typeid(ft::Vector<int>::reverse_iterator::difference_type).name());
	// 	res2.push_back(typeid(ft::Vector<int>::reverse_iterator::pointer).name());
	// 	res2.push_back(typeid(ft::Vector<int>::reverse_iterator::reference).name());

	// 	for (size_t i = 0; i < res.size(); i++)
	// 	{
	// 		std::cout << res[i] << ' ';
	// 	}
	// 	std::cout << '\n';
	// 	std::cout << '\n';

	// 	for (size_t i = 0; i < res2.size(); i++)
	// 	{
	// 		std::cout << res2[i] << ' ';
	// 	}
	// }

	return (0);
}