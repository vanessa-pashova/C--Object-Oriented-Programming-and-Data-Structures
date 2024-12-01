#include <iostream>
#include <string>

struct Node {
    char data;
    Node *next;

    Node(char data) : data(data), next(nullptr) {}
};

class TextEditor {
private:
    Node *head, *cursor;
    int size;

    std::string getLeftChars(int k) {
        Node *temp = head;
        std::string result = "";
        int steps = size;

        while (temp && steps-- > 0) {
            if (steps < 10)
                result = temp->data + result;

            temp = temp->next;
        }

        return result;
    }

public:
    TextEditor() : head(nullptr), cursor(nullptr), size(0) {}

    void addText(const std::string &text) {
        for (char ch : text) {
            Node *newNode = new Node(ch);
            if (!cursor) {
                if (!head)
                    head = cursor = newNode;

                else {
                    cursor->next = newNode;
                    cursor = newNode;
                }
            }

            else {
                newNode->next = cursor->next;
                cursor->next = newNode;
                cursor = newNode;
            }

            size++;
        }
    }

    int deleteText(int k) {
        int deletedCount = 0;

        while (k > 0 && cursor) {
            Node *temp = head;
            while (temp && temp->next != cursor)
                temp = temp->next;

            if (temp) {
                Node *toDelete = cursor;
                cursor = temp;
                cursor->next = nullptr;
                delete toDelete;
                deletedCount++;
                k--;
            }

            else {
                delete cursor;
                cursor = head = nullptr;
                size = 0;
                return deletedCount;
            }
        }

        size -= deletedCount;
        return deletedCount;
    }

    std::string cursorLeft(int k) {
        while (k > 0 && cursor != head) {
            Node *temp = head;
            while (temp && temp->next != cursor)
                temp = temp->next;

            if (temp)
                cursor = temp;

            k--;
        }
        return getLeftChars(10);
    }

    std::string cursorRight(int k) {
        while (k > 0 && cursor && cursor->next) {
            cursor = cursor->next;
            k--;
        }

        return getLeftChars(10);
    }

    ~TextEditor() {
        while (head) {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    TextEditor editor;
    editor.addText("leet");
    std::cout << "Added 'leet'.\n";
    editor.addText("code");
    std::cout << "Added 'code'.\n";
    std::cout << "Deleted characters: " << editor.deleteText(4) << "\n";
    editor.addText("practice");
    std::cout << "Added 'practice'.\n";
    std::cout << "Cursor left: " << editor.cursorLeft(8) << "\n";
    std::cout << "Cursor right: " << editor.cursorRight(6) << "\n";
}
