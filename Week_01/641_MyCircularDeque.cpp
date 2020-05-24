/*
641. 设计循环双端队列

设计实现双端队列。
你的实现需要支持以下操作：

MyCircularDeque(k)：构造函数,双端队列的大小为k。
insertFront()：将一个元素添加到双端队列头部。 如果操作成功返回 true。
insertLast()：将一个元素添加到双端队列尾部。如果操作成功返回 true。
deleteFront()：从双端队列头部删除一个元素。 如果操作成功返回 true。
deleteLast()：从双端队列尾部删除一个元素。如果操作成功返回 true。
getFront()：从双端队列头部获得一个元素。如果双端队列为空，返回 -1。
getRear()：获得双端队列的最后一个元素。 如果双端队列为空，返回 -1。
isEmpty()：检查双端队列是否为空。
isFull()：检查双端队列是否满了。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/design-circular-deque
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class MyCircularDeque {
private:
    vector<int> deque;
    int max_size;
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        max_size=k;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(deque.size()<max_size)
        {
            deque.insert ( deque.begin() , value );
            return true;
        }
         
         return false;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(deque.size()<max_size)
        {
            deque.push_back(value);
             return true;
        }
        return false;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        vector<int>::iterator it=deque.begin();
        if(it!=deque.end())
        {
            deque.erase(it);
            return true;
        }
        return false;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        vector<int>::iterator it=deque.end();
        if(it!=deque.begin())
        {
            deque.pop_back();
            return true;
        }
        return false;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if(deque.empty())
        {
            return -1;
        }
        return deque.front();

    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if(deque.empty())
        {
            return -1;
        }
         return deque.back();
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return  deque.empty();

    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return deque.size() == max_size;

    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
