#include <iostream>
#include <queue>
using namespace std;

class MedianFinder {
private:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;

public:
    void insert(int num) {
        if (left.empty() || num <= left.top())
            left.push(num);
        else
            right.push(num);

        if (left.size() > right.size() + 1) {
            right.push(left.top());
            left.pop();
        }
        else if (right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        }
    }

    float getMedian() {
        if (left.size() == right.size())
            return (left.top() + right.top()) / 2.0f;

        return left.top();
    }
};

int main() {
    MedianFinder mf;

    mf.insert(5);
    cout << mf.getMedian() << endl;

    mf.insert(15);
    cout << mf.getMedian() << endl;

    mf.insert(1);
    cout << mf.getMedian() << endl;

    mf.insert(3);
    cout << mf.getMedian() << endl;

    return 0;
}