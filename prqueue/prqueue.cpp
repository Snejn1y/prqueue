#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <chrono>

using namespace std;

struct elem
{
    int data;
    unsigned int priority;
    elem* next;
};

struct queue
{
    elem* back, * front;
    queue(void) : back(NULL), front(NULL) {}
};

void push(queue& q, int value)
{
    elem* new_elem = new elem;
    new_elem->data = value;
    new_elem->next = NULL;

    if (q.back == NULL)
    {
        q.back = new_elem;
        q.front = new_elem;
    }
    else
    {
        q.back->next = new_elem;
        q.back = new_elem;
    }
}

bool pop(queue& q, int& value)
{
    if (q.front == NULL)
    {
        return false;
    }

    value = q.front->data;
    elem* temp = q.front;
    q.front = q.front->next;

    if (q.front == NULL)
    {
        q.back = NULL;
    }

    delete temp;
    return true;
}

void clear(queue& q)
{
    elem* del;
    while (q.front)
    {
        del = q.front;
        q.front = q.front->next;
        delete del;
    }
    q.back = NULL;
}

void print(queue*& q, int n)
{
    for (int i = 0; i < n; i++)
    {
        elem* cursor = q[i].front;
        while (cursor)
        {
            cout << cursor->data << " ";
            cursor = cursor->next;
        }
        cout << endl;
    }
}

int size(const queue& q) {
    int count = 0;
    elem* curr = q.back;
    while (curr) {
        count++;
        curr = curr->next;
    }
    return count;
}

queue copy(const queue& q) {
    queue copyQueue;
    if (!q.front) return copyQueue;

    copyQueue.front = new elem;
    copyQueue.front->data = q.front->data;
    copyQueue.front->next = nullptr;
    copyQueue.back = copyQueue.front;

    for (elem* current = q.front->next; current != nullptr; current = current->next) {
        elem* newElem = new elem;
        newElem->data = current->data;
        newElem->next = nullptr;

        copyQueue.back->next = newElem;
        copyQueue.back = newElem;
    }

    return copyQueue;
}

int sum(queue& q, int& n)
{
    int sum = 0;
    queue temp = copy(q);
    int value = 0;
    while (pop(temp, value))
    {
        sum += value;
        n++;
    }
    clear(temp);
    return sum;
}

double avgN(queue*& q, int n)
{
    int summ = 0, k = 0;
    for (int i = 0; i < n; i++)
    {
        summ += sum(q[i], k);
    }
    return (double)summ / k;
}


void inputQueues(queue*& queues, int numQueues, int numElements)
{
    for (int i = 0; i < numQueues; i++)
    {
        for (int j = 0; j < numElements; j++)
        {
            int value;
            cout << "Enter value " << j + 1 << " for queue " << i + 1 << ": ";
            cin >> value;
            push(queues[i], value);
        }
    }
}

void randinput(queue*& queues, int numQueues, int numElements)
{
    srand(time(NULL));
    for (int i = 0; i < numQueues; i++)
        for (int j = 0; j < numElements; j++)
            push(queues[i], rand() % 10);
}

void deleteQueues(queue*& queues, int numQueues)
{
    for (int i = 0; i < numQueues; i++)
    {
        int value;
        while (pop(queues[i], value)) {}
    }
    delete[] queues;
    queues = NULL;
}


struct priority_queue
{
    elem* back;
    priority_queue(void) : back(NULL) {}
};

bool compare(elem* prev, elem* next)
{
    return prev->priority > next->priority;
}

void push(priority_queue& q, const int& value, const unsigned int& priority_value)
{
    elem* temp = new elem;
    temp->data = value;
    temp->priority = priority_value;
    temp->next = NULL;

    if (!q.back)
    {
        q.back = temp;
        return;
    }

    elem* p = q.back, * prev = NULL;
    for (; p && compare(temp, p); prev = p, p = p->next);

    if (p == q.back)
    {
        temp->next = q.back;
        q.back = temp;
        return;
    }

    prev->next = temp;
    if (!p) return;

    temp->next = p;
}

bool pop(priority_queue& q, int& out)
{
    if (!q.back) return false;
    if (!q.back->next)
    {
        out = q.back->data;
        delete q.back;
        q.back = NULL;
        return true;
    }
    elem* prev, * end;
    prev = end = q.back;
    while (end->next)
    {
        prev = end;
        end = end->next;
    }
    out = end->data;
    delete end;
    prev->next = NULL;
    return true;
}

priority_queue copy(const priority_queue& pq) {
    priority_queue copyPQ;
    if (!pq.back) return copyPQ; 
    elem* dummy = new elem;
    dummy->next = nullptr;
    elem* tail = dummy;

    for (elem* current = pq.back; current != nullptr; current = current->next) {
        elem* newElem = new elem;
        newElem->data = current->data;
        newElem->priority = current->priority; 
        newElem->next = nullptr;

        tail->next = newElem;
        tail = newElem;
    }
    copyPQ.back = dummy->next;
    delete dummy;
    return copyPQ;
}

void clear(priority_queue& q)
{
    elem* del;
    while (q.back)
    {
        del = q.back;
        q.back = q.back->next;
        delete del;
    }
}

void print(priority_queue*& q, int n)
{
    for (int i = 0; i < n; i++)
    {
        elem* cursor = q[i].back;
        while (cursor)
        {
            cout << cursor->data << " ";
            cursor = cursor->next;
        }
        cout << endl;
    }
}

int size(priority_queue& q)
{
    int count = 0;
    elem* cursor = q.back;
    while (cursor)
    {
        count++;
        cursor = cursor->next;
    }
    return count;
}

int sum(priority_queue& q, int& n)
{
    int sum = 0;
    priority_queue temp = copy(q);
    int value = 0;
    while (pop(temp, value))
    {
        sum += value;
        n++;
    }
    clear(temp);
    return sum;
}

double avgN(priority_queue*& q, int n)
{
    int summ = 0, k = 0;
    for (int i = 0; i < n; i++)
    {
        summ += sum(q[i], k);
    }
    return (double)summ / k;
}


void randinput(priority_queue*& queues, int numQueues, int numElements)
{
    srand(time(NULL));
    for (int i = 0; i < numQueues; i++)
        for (int j = 0; j < numElements; j++)
            push(queues[i], rand() % 10, rand() % 10);
}

void inputQueues(priority_queue*& queues, int numQueues, int numElements)
{
    for (int i = 0; i < numQueues; i++)
    {
        for (int j = 0; j < numElements; j++)
        {
            int value, p;
            cout << "Enter value and priotity of element " << j + 1 << ": ";
            cin >> value >> p;
            push(queues[i], value, p);
        }
    }
}

void Ftest()
{
    cout << "Queue test \"queue.txt\":\n";
    ofstream out("queue.txt");
    int n = 0;
    double time = 0;
    for (int i = 0; i < 10; i++)
    {
        n += 500;
        for (int k = 0; k < 5; k++)
        {
            queue* q = new queue[n];
            randinput(q, n, n);
            chrono::time_point<chrono::steady_clock> start = chrono::steady_clock::now();
            avgN(q, n);
            chrono::time_point<chrono::steady_clock> done = chrono::steady_clock::now();
            time += chrono::duration_cast<chrono::milliseconds>(done - start).count();
            delete[] q;
        }
        time /= 5000;
        cout << "Queue test. n = " << n << " Time = " << time << "\n";
        out << n << "\t" << time << "\n";
    }
    
    out.close();
}

void Stest()
{
    cout << "Priority queue test \"priority_queue.txt\":\n";
    ofstream out("priority_queue.txt");
    int n = 0;
    double time = 0;
    for (int i = 0; i < 10; i++)
    {
        n += 200;
        for (int k = 0; k < 5; k++)
        {
           	priority_queue* q = new priority_queue[n];
            randinput(q, n, n);
            chrono::time_point<chrono::steady_clock> start = chrono::steady_clock::now();
            avgN(q, n);
            chrono::time_point<chrono::steady_clock> done = chrono::steady_clock::now();
            time += chrono::duration_cast<chrono::milliseconds>(done - start).count();
            delete[] q;
        }
        time /= 5000;
        cout << "Priority queue test. n = " << n << " Time = " << time << "\n";
        out << n << "\t" << time << "\n";
    }
    out.close();
}

int main()
{
    while (1)
    {
        int c = 4;
        cout << "1. If u want to work with queue;\n"
            "2. If u want to work with priority queue;\n"
            "3. If u want analize all algorithms;\n"
            "4. If u want exit;\n"
            "Choose: ";
        cin >> c;
        switch (c)
        {
        case 1:
        {
            int n = 0, m = 0;
            cout << "Enter a number of queues: ";
            cin >> n;
            queue* q = new queue[n];
            cout << "Enter a number of elements: ";
            cin >> m;
            int f = 0;
            cout << "1. Enter from keyboard;\n"
                "2. Random;\n"
                "Choose: ";
            cin >> f;
            if (f == 1)
                inputQueues(q, n, m);
            else if (f == 2)
            {
                randinput(q, n, m);
                cout << "You queues: \n";
                print(q, n);
            }
            else
            {
                cout << "U enter a wront number!";
                return 0;
            }
            cout << "Average arithmetic n queues: " << avgN(q, n) << endl;
            for (int i = 0; i < n; i++)
                clear(q[i]);
            delete[] q;
            break;
        }
        case 2:
        {
            int n = 0, m = 0;
            cout << "Enter a number of priority queues: ";
            cin >> n;
            priority_queue* q = new priority_queue[n];
            cout << "Enter a number of elements: ";
            cin >> m;
            int f = 0;
            cout << "1. Enter from keyboard;\n"
                "2. Random;\n"
                "Choose: ";
            cin >> f;
            if (f == 1)
                inputQueues(q, n, m);
            else if (f == 2)
            {
                randinput(q, n, m);
                cout << "You priority queues: \n";
                print(q, n);
            }
            else
            {
                cout << "U enter a wront number!";
                return 0;
            }
            cout << "Average arithmetic n priority queues: " << avgN(q, n) << endl;
            for (int i = 0; i < n; i++)
                clear(q[i]);
            delete[] q;
            break;
        }
        case 3:
        {
            //F test
            Ftest();
            //S test
            Stest();
            break;
        }
        default:
            return 0;
        }
    }
}
