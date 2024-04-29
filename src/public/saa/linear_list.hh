#ifndef fog_saa_linear_list
#define fog_saa_linear_list

#include "essential.hh"
#include <cstdint>
#include <utility> // std::swap

namespace fog::saa::linear_list {

template<typename T>
struct linear {
    linear(T* arr, int len) {
        int i = 0;
        this->_data = new int[len];
        while(i < len) {
            this->_data[i] = arr[i];
            i++;
        }
        this->_len = i;
    }
    linear(int len) {
        this->_data = new T[len];
        this->_len = 0;
    }
    ~linear() {
        delete[] this->_data;
    }
    bool empty() {
        return this->_len == 0;
    }
    int len() {
        return this->_len;
    }
    void display() {
        std::string str;
        for (int i = 0; i < this->_len; i++) {
            str.append(std::to_string(this->_data[i])).append(", ");
        }
        // print("linear: ", str);
    }
    bool get_elem(int i, T& e) {
        if (i < 0 || i > this->_len) return false;
        e = this->_data[i];
        return true;
    }
    int locate_elem(T e) {
        for (int i = 0; i < this->_len; i++) {
            if (this->_data[i] == e) {
                return i;
            }
        }
        return -1;
    }
    bool insert(int i, T e) {
        if (i < 0 || i > this->_len + 1) return false;
        for (int j = this->_len; j > i; j--) this->_data[j] = this->_data[j - 1];
        this->_data[i] = e;
        this->_len++;
        return true;
    }
    bool del(int i, T& e) {
        if (i < 1 || i > this->_len) return false;
        e = this->_data[i];
        for (int j = i; j < this->_len - 1; j++) this->_data[j] = this->_data[j - 1];
        this->_len--;
        return true;
    }
    /* 题目1,删除所有x元素 */
    // 删除所有x, 重建法
    void del_all_re(T x) {
        int k = 0;
        for (int i = 0; i < this->_len; i++) {
            if (this->_data[i] != x) {
                this->_data[k] = this->_data[i];
                k++;
            }
        }
        this->_len = k;
    }
    // 删除所有x, 前移法
    void del_all_fwd(T x) {
        int k = 0, i = 0;
        while(i < this->_len) {
            if (this->_data[i] == x) k++;
            else this->_data[i - k] = this->_data[i];
        }
        this->_len -= k;
    }
    // 删除所有x, 区间划分法
    void del_all_area(T x) {
        int i = -1, j = 0;
        while(j < this->_len) {
            if (this->_data[j] != x) {
                i++;
                if (i != j) ::std::swap(this->_data[i], this,_data[j]);
            }
            j++;
        }
        this->_len = i + 1;
    }
    /* 题目2,将最大值元素与最小值元素交换 */
    void swap_max_min() {
        int max = 0, min = 0;
        for (int i = 1; i < this->_len; i++) {
            if (this->_data[i] > this->_data[max]) max = i;
            else if (this->_data[i] < this->_data[max]) min = i;
        }
        std::swap(this->_data[max], this->_data[min]);
    }
    /* 题目3,删除自第i个元素开始的k个元素*/
    bool del_belong(int i, int k) {
        if (i < 0 || k < 1 || i + k > this->_len) return false;
        for(int j = i + k; j < this->_len; j++) {
            this->_data[j - k] = this->_data[j];
        }
        this->_len -= k;
        return true;
    }
    /* 题目4,以第一个元素为基准, 将所有小于等于他的元素移到该元素的前面, 将所有大于他的元素移到该元素的后面*/
    void sort_divide_since_first() {
        int i = 0, j = this->len - 1;
        T pivot = this->_data[0]; // 以0为基准
        while (i < j) {
            while (i < j && this->_data[j] > pivot) j--; // 从后往前找到第一个小于的数
            while (i < j && this->_data[i] <= pivot) i++; // 从前往后找到第一个大于的数
            if (i < j) std::swap(this->_data[i], this->_data[j]);
        }
        std::swap(this->_data[0], this->_data[i]);
    }
    // 第二种写法
    void sort_divide_since_first_2() {
        int i = 0, j = this->_len - 1;
        T pivot = this->_data[0];
        while(i < j) {
            while (i < j && this->_data[j] > pivot) j--; // 从后往前找带第一个小于的数
            this->_data[i] = this->_data[j];
            while (i < j && this->_data[i] <= pivot) i++; // 从前往后找到第一个大于的数
            this->_data[j] = this->_data[i];
        }
        this->_data[i] = pivot;
    }
    /* 题目5, 表的每个元素都是互不相等的整数, 将所有奇数移动到所有偶数前面*/
    void move_odd_font_even() {
        int i = 0, j = this->_len - 1;
        while (i < j) {
            while(i < j && this->_data[j] % 2 == 0) j--;
            while(i < j && this->_data[i] % 2 == 1) i++;
            if (i < j) std::swap(this->_data[i], this->_data[j]);
        }
    }
    // 第二种解法, 区间划分法
    void move_odd_font_even_2() {
        int i = -1;
        for (int j = 0; j < this->_len -1; j++) {
            if (this->_data[j] % 2 == 1) {
                i++;
                if (i != j) std::swap(this->_data[i], this->_data[j]);
            }
        }
    }
private:
    T* _data;
    int _len;
};

void linear_list() {
    // print("===== linear_list =====");
    int a = 3;
    int b = 2;
    a = a + b;
    b = a - b;
    a = a - b;

    int a_1[] = {1, 3, 5, 7, 9};
    linear l_1(a_1, 5);
    l_1.display();

    int a_2[] = {1, 3, 5, 1, 6, 1};
    linear l_2(a_2, 10);
    l_2.del_all_re(1);
    l_2.display();
}

}

#endif