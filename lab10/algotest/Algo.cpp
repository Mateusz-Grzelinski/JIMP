//
// Created by mat on 11.05.17.
//

#include "Algo.h"

namespace algo {
    std::set<std::string> Keys(const std::map<std::string, int> &m) {
        std::set<std::string> tmp;
//        std::for_each(m.begin(), m.end(), [tmp](const std::pair<std::string, int> &it){tmp.insert(it.first); });
//        return tmp;
//        std::transform(m.begin(), m.end(), tmp.begin(), )
    }
    std::vector<int> Values(const std::map<std::string, int> &m) {
        std::vector<int> tmp(m.size());
//        std::for_each(m.begin(), m.end(), [tmp](const std::pair<std::string, int> it){tmp.push_back(it.second); });
        return tmp;
    }

    std::map<std::string, int> DivisableBy(const std::map<std::string, int> &m, int divisor) {
        return std::map<std::string, int>();
    }

    void SortInPlace(std::vector<int> *v) {
        std::sort(v->begin(), v->end());
    }

    std::vector<int> Sort(const std::vector<int> &v) {
        return std::vector<int>();
    }

    void SortByFirstInPlace(std::vector<std::pair<int, int>> *v) {

    }

    void SortBySecondInPlace(std::vector<std::pair<int, int>> *v) {

    }

    void SortByThirdInPlace(std::vector<std::tuple<int, int, int>> *v) {

    }

    std::vector<std::string> MapToString(const std::vector<double> &v) {
        std::vector<std::string> vectmp;
//        std::for_each(v.begin(), v.end(), [&vectmp](const double v_it){ vectmp.push_back(std::to_string(v_it)); });
        std::transform(v.begin(), v.end(), std::back_inserter(vectmp),  [](const double &v_it){ return std::to_string(v_it); });
        return vectmp;
    }

    std::string Join(const std::string &joiner, const std::vector<double> &v) {
        return std::__cxx11::string();
    }

    int Sum(const std::vector<int> &v) {
        return 0;
    }

    int Product(const std::vector<int> &v) {
        return 0;
    }

    bool Contains(const std::vector<int> &v, int element) {
        return std::any_of(v.begin(), v.end(), [element](const int &v_it){ return v_it==element; } );
        //[ element zewnętrzny ](iterator)
    }

    bool ContainsKey(const std::map<std::string, int> &v, const std::string &key) {
        return std::any_of(v.begin(), v.end(), [key](const std::pair<std::string, int> p){ return (key==p.first); });
    }

    bool ContainsValue(const std::map<std::string, int> &v, int value) {
        return std::any_of(v.begin(), v.end(), [value](const std::pair<std::string, int> p){ return (value==p.second); });
    }

    std::vector<std::string> RemoveDuplicates(const std::vector<std::string> &v) {
        return std::vector<std::string>();
    }

    void RemoveDuplicatesInPlace(std::vector<std::string> *v) {

    }

    void InitializeWith(int initial_value, std::vector<int> *v) {
        std::fill(v->begin(), v->end(), initial_value);
    }

    std::vector<int> InitializedVectorOfLength(int length, int initial_value) {
        return std::vector<int> (length,initial_value);
    }

    void CopyInto(const std::vector<int> &v, int n_elements, std::vector<int> *out) {
        std::copy(v.begin(), v.begin()+n_elements, std::back_inserter(*out));
    }

    int HowManyShortStrings(const std::vector<std::string> &v, int inclusive_short_length) {
        return 0;
    }
}