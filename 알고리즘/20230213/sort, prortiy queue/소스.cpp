#include <iostream>
#include <algorithm>
#include <queue> // priority queue ����
using namespace std;
struct Student {
    string name; // �̸�
    int age; // ���� 
    int grade; // ����
    bool operator < (Student right) const {
        if (grade > right.grade)
            return false; // �ùٸ� / ���ϴ� ��Ȳ�ϋ� true
        if (grade < right.grade)
            return true;
        if (age > right.age)
            return false;
        if (age < right.age)
            return true;
        if (name < right.name)
            return false;
        if (name > right.name)
            return true;
        return false;
    }
};
struct ssafycmp {
    bool operator()(Student left, Student right) {
        if (left.grade > right.grade)
            return false; // �ùٸ� / ���ϴ� ��Ȳ�ϋ� true
        if (left.grade < right.grade)
            return true;
        if (left.age > right.age)
            return false;
        if (left.age < right.age)
            return true;
        if (left.name < right.name)
            return false;
        if (left.name > right.name)
            return true;
        return false;
    }
};
// sort
// sort(first, last, cmp) default cmp : < 
// --> �����ź��� ������ ���� �������� ���� 
// left < right --> ������ �켱���� ����
// pq
// priority_queue<ty, container, cmp> default cmp : < 
// --> ū�ź��� ������ MAX HEAP
// left < right --> ū�ź��� �켱���� ����
struct cmp {
    // PQ -> < ���� : MAX HEAP 
    // sort���� ������ �������� ������ ��´�? 
    // �ùٸ� ��Ȳ (��, ���� ���ϴ� ��Ȳ�϶�) -> return false; 
    bool operator()(int left, int right) {
        // return left > right; 
        if (left > right)// �츮�� ���ϴ� ����?
            return true;
        if (left < right)
            return false;
        return false;
    }
};
bool qcmp(int left, int right) {
    // ¦�� �켱 
    if (left % 2 == 0 && right % 2 == 1)
        return true;
    if (left % 2 == 1 && right % 2 == 0)
        return false;
    // ¦����� ��������
    if (left % 2 == 0 && right % 2 == 0 && left > right)
        return true;
    if (left % 2 == 0 && right % 2 == 0 && left < right)
        return false;
    // Ȧ����� ��������
    if (left % 2 == 1 && right % 2 == 1 && left < right)
        return true;
    if (left % 2 == 1 && right % 2 == 1 && left > right)
        return false;
    return false;
}
int main() {
    int arr[] = { 1, 4, 5, 3, 2 };
    // #1 defaut : MAX heap : (int����) ���� ū ���� �켱������ ���´�. 
    // priority_queue<int>pq; 
     //���� : push()
     //���� : pop()
     //�� �� (�켱������ ���� ���� ��) return : q.top()
     //����ִ°�? : empty() 
    //for (int i = 0; i < 5; i++)
    //    pq.push(arr[i]); // heapify
    // ���
    //while (!pq.empty()) {
    //    cout << pq.top() << " ";
    //    pq.pop(); // heapify 
    //}
    // #2. MIN Heap
    // priority_queue<typename, container, less> 
    // typename : �ڷ��� 
    // container : vector
    // _Pr : less --> < 
    // less : Compare cmp X --> �Լ� ����ü
    // �Լ��� �־��ָ� �ȵǰ�, ����ü �Լ��� ���� �־�� �Ѵ�. 
    //priority_queue<int, vector<int>, cmp>pq;
    //for (int i = 0; i < 5; i++)
    //    pq.push(arr[i]); // heapify
    //
    //while (!pq.empty()) {
    //    cout << pq.top() << " ";
    //    pq.pop(); // heapify 
    //}
    // #3. ����� ���� heap
    priority_queue<Student>pq;
    // #1. ���� ���� ��
    // #2. ���� ���� ��
    // #3. �̸� ������
    pq.push({ "������", 3, 100 });
    pq.push({ "������", 4, 100 });
    pq.push({ "���ÿ�", 2, 100 });
    pq.push({ "����", 4, 100 });
    pq.push({ "�̵�ȭ", 7, 25 });
    while (!pq.empty()) {
        Student now = pq.top();
        cout << now.name << " " << now.age << " " << now.grade << '\n';
        pq.pop();
    }
    // sort�� priority queue ���� ���°�? 
    // sort : O(NlogN)
    // PQ : ���԰� ���� O(logN)
    // ���� - N���� ������ �Է� �ް� ���� ū ���� ����϶�
    // sort : �Է¹ް� -> ���� -> arr[N-1] == O(NlogN)
    // PQ : �Է¹����鼭 PQ ����(logN) -> heapify -> pq.top() // peek
    // ���� 2 - N���� Query 
    // 1 -> ���� (logN)
    // 2 -> ���� ���� ū �� ���� (logN)
    // 0 -> ���� ���� ū ���� ��� (1) 
    // sort : Q * O(NlogN)
    // PQ : Q * (logN)
    // sort : �� �ѹ��� ���ķ� �ذ��� �����Ҷ�
    // --> binary search, greedy
    // PQ : ����ؼ� ���ο� ���� ���� / ���� �ɋ� (��ȭ�� ������)
    cout << '\n';
    // QUIZ
    // ���� : ¦�� �켱, Ȧ�� ����, ¦���� ��������, Ȧ���� ��������
    int brr[] = { 1, 3, 4, 5, 2 };
    // 4 2 1 3 5 
    sort(brr, brr + 5, qcmp);
    for (int i = 0; i < 5; i++)
        cout << brr[i] << " ";
}