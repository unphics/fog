#ifndef fog_saa_linked_list
#define fog_saa_linked_list

namespace fog::saa::linked_list {

template<typename T>
struct singly_node {
    T data;
    singly_node<T>* next = nullptr;
};

template<typename T>
struct singly_linked_list {
    singly_linked_list() {
        this->head = new singly_node<T>;
        this->head->next = nullptr;
    }
    singly_linked_list(T* arr, int len) { // 整体创建单链表
        this->head = new singly_node<T>;
        this->head->next = nullptr;
        this->head->data = arr[0];
        singly_node<T>* end = head;
        for (int i = 1; i < len; i++) {
            singly_node<T>* node = new singly_node<T>;
            node->data = arr[i];
            end->next = node;
            end = node;
        }
        end = nullptr;
    }
    ~singly_linked_list() {
        singly_node<T>* cur = this->head->next;
        while (cur != nullptr) {
            this->head = cur->next;
            delete cur;
            cur = this->head->next;
        }
    }
    int len() {
        auto p = this->head->next;
        int i = 1; // head含有实际数据,占1
        while (p != nullptr) {
            p = p->next;
            i++;
        }
        return i;
    }
    bool get_elem(int i, T& e) {
        int j = 0;
        auto p = this->head;
        while(j < i && p != nullptr) {
            j++;
            p = p->next;
        }
        if (p == nullptr) return false;
        e = p->data;
        return true;
    }
    int local_elem(T e) {
        auto p = this->head;
        int i = 0;
        while(p != nullptr && p->data != e) {
            p = p->next;
            i++;
        }
        if (p->next == nullptr) return 0;
        return i;
    }
    bool insert(int i, T e) {
        int j = 0;
        auto p = this->head;
        while(p != nullptr && j < i) {
            j++;
            p = p->next;
        }
        if (p == nullptr) return false;
        auto s = new singly_node<T>;
        s->data = p->data;
        s->next = p->next;
        p->next = s;
        p->data = e;
        return true;
    }
    bool remove(int i, T& e) {
        int j = 0;
        auto p = this->head;
        while (j < i && p != nullptr) {
            j++;
            p = p->next;
        }
        if (p == nullptr) return false;
        auto q = p->next;
        if (q == nullptr) return false;
        e = q->data;
        if (j == 0) {
            delete this->head;
            this->head = q;
        } else {
            delete p;
            p = q;
        }
        return true;
    }
    void reverse() {
        auto p = this->head;
        this->head = nullptr;
        while (p != nullptr) {
            auto q = p->next; // 保持首节点的后继节点
            p->next = this->head;
            this->head = p;
            p = q;
        }
    }
    void sort() {
        singly_node<T>* p, *pre, *q;
        p = this->head; // p指向list的第2个数据节点
        this->head->next = nullptr; // 构造只含一个数据节点的有序表
        while (p != nullptr) {
            q = p->next; // q保存p节点后继节点的指针
            pre = this->head; // 从有序表开头进行比较, pre指向插入p的前驱节点
            while (pre->next != nullptr && pre->next->data < p->data) pre = pre->next; // 在有序表中找插入p的前驱节点pre
            p->next = pre->next;
            pre->next = p;
            p = q; // 扫描原单向链表余下的节点
        }
    }
    void display() {
        std::string str = "";
        singly_node<T>* cur = this->head;
        while (cur != nullptr) {
            str.append(std::to_string(cur->data)).append(", ");
            cur = cur->next;
        }
        print("display fwd link list: ", str);
    }
    singly_node<T>* head;
};

void test_singly_linked_list() {
    print("===== test singly linked list ====");
    int arr[] = {5, 4, 8, 0, 1, 3, 7};
    singly_linked_list<int>* list = new singly_linked_list<int>(arr, sizeof(arr) / sizeof(int));
    list->display();
    print("list len:", list->len());
    int data_1;
    list->get_elem(3, data_1);
    print("find 3th data =", data_1);
    print("find val 0 idx =", list->local_elem(0));
    list->insert(4, 9);
    list->display();
    int out_1;
    list->remove(0, out_1);
    list->display();
    list->reverse();
    list->display();
    // list->sort();
    // list->display();
}

}

#endif
