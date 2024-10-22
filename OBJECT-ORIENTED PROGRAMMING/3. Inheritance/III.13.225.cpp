//Опашка е редица от 0 или повече елемнти, в която включването на елемент се осъществява в единия край на редицата (край на опашката), а изключването на елемент - 
//от другия край на редицата (начало на опашката). Да се дефинира клас Опашка, наследник на класа Стак, реализиращ опашка от символи. Реализацяита на кю да е такава, че обектите ѝ
//да нямат пряк достъп до компонентите на класа стак
#include <iostream>

const int MaxStack = 100;
const int FullStack = 100;
const int EmptyStack = -1;
const char EmptyFlag = '\0';

class Stack 
{   
    private:
        char items[MaxStack];
        int top;

        void copyFrom(const Stack &other)
        {
            this->top = other.top;
            strcpy(this->items, other.items);
        }

        void erase() {
            for (std::size_t i = 0; i < MaxStack; i++)
                this->items[i] = ' ';
        }
    public:
        Stack();
        Stack(const Stack &);
        
        void push(char);
        char pop();
        bool empty() const;
        bool full() const;
        void print();
};

Stack::Stack() : top(0) {
    items[0] = '\0';
}

Stack::Stack(const Stack &other)
{
    this->erase();
    this->copyFrom(other);
}

bool Stack::empty() const {
    if (top == EmptyFlag) 
        return true;
    
    return false;
}

bool Stack::full() const {
    if (top == FullStack)
        return true;

    return false;
}

void Stack::print() {
    for (std::size_t i = 0; i < this->top; i++)
        std::cout << this->items[i] << "  ";

    std::cout << '\n';
}

void Stack::push(char c)
{
    this->top += 1;
    if (!full())
        this->items[top - 1] = c;

    else 
        std::cout << "[ error: stack's already full, cannot add an element ]\n";

}

char Stack::pop()
{
    if (empty())  
    {
        std::cout << "[ error: stack's already empty ]\n";
        return EmptyFlag;
    }

    return this->items[this->top--];
}

class Queue : Stack
{
    public:
        Queue();

        void add(const char&);
        void remove();
        char front();
        bool empty() const;
        bool full() const;
        int lenght();
        void print();
};

Queue::Queue() {}

void Queue::add(const char &c)
{
    Stack s;
    while (!empty())
        s.push(pop());

    push(c);

    while (!s.empty())
        push(s.pop());
}

void Queue::remove() {
    pop();
}

char Queue::front()
{
    char h = pop();
    push(h);

    return h;
}

bool Queue::empty() const {
    return Stack::empty();
}

bool Queue::full() const {
    return Stack::full();
}

int Queue::lenght()
{
    Stack s = *this;
    int n = 0; 
    while (s.pop())
        n++;

    return n;
}

void Queue::print() {
    Stack::print();
}

int main()
{
    std::cout << '\n';
    std::cout << "---------------------------" << '\n';

    Stack f, g;
    f.push('m');
    f.push('a');
    f.push('r');
    f.push('t');
    f.push('i');

    f.print();

    f.pop();
    f.print();

    g.pop();
}
//✅